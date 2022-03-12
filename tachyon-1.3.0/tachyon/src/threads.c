/*
 * threads.c - code for spawning threads on various platforms.
 *
 *  $Id: threads.c,v 1.106 2021/03/07 03:30:09 johns Exp $
 */ 

/*
   To use the WorkForce threading routines outside of Tachyon, 
   run the following sed commands to generate the WKF variants of the
   function names and macros.  This method supercedes the old hand-edited
   versions that I previously maintained, and retains the support for
   UI threads etc.  These are written in c-shell (/bin/csh) syntax:
     sed -e 's/rt_/wkf_/g' threads.c >! /tmp/tmp1
     sed -e 's/defined(THR)/defined(WKFTHREADS)/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/#ifdef THR/#ifdef WKFTHREADS/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/#ifndef THR/#ifndef WKFTHREADS/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/RTUSE/WKFUSE/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/RTFORCE/WKFFORCE/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/threads.h/WKFThreads.h/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/RT_/WKF_/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/STAWKF_ROUTINE/START_ROUTINE/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/RTTHREAD/WKFTHREAD/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/ THR / WKFTHREADS /g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/THRUSE/WKFUSE/g' /tmp/tmp1 >! /tmp/WKFThreads.C

     sed -e 's/rt_/wkf_/g' threads.h >! /tmp/tmp1
     sed -e 's/defined(THR)/defined(WKFTHREADS)/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/#ifdef THR/#ifdef WKFTHREADS/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/#ifndef THR/#ifndef WKFTHREADS/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/RTUSE/WKFUSE/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/RTFORCE/WKFFORCE/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/threads.h/WKFThreads.h/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/RT_/WKF_/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/STAWKF_ROUTINE/START_ROUTINE/g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/RTTHREAD/WKFTHREAD/g' /tmp/tmp1 >! /tmp/tmp2
     sed -e 's/ THR / WKFTHREADS /g' /tmp/tmp2 >! /tmp/tmp1
     sed -e 's/THRUSE/WKFUSE/g' /tmp/tmp1 >! /tmp/WKFThreads.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * If compiling on Linux, enable the GNU CPU affinity functions in both
 * libc and the libpthreads
 */
#if defined(__linux)
#define _GNU_SOURCE 1
#include <sched.h>
#endif

#include "threads.h"

/* needed for CPU info APIs and flag macros */
#if (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1300)) || (defined(_MSC_VER) && (_MSC_VER >= 1916))
#include <emmintrin.h>
#include <immintrin.h>
#endif


#ifdef _MSC_VER
#if 0
#define RTUSENEWWIN32APIS 1
#define _WIN32_WINNT 0x0400 /**< needed for TryEnterCriticalSection(), etc */
#define  WINVER      0x0400 /**< needed for TryEnterCriticalSection(), etc */
#endif
#include <windows.h>        /**< main Win32 APIs and types */
#include <winbase.h>        /**< system services headers */
#endif

#if defined(_AIX) || defined(_CRAY) || defined(__irix) || defined(__linux) || defined(__osf__) || defined(__sun)
#include <unistd.h>         /**< sysconf() headers, used by most systems */
#endif

#if defined(__APPLE__) && defined(THR)
#if 1
#include <sys/types.h>
#include <sys/sysctl.h>     /**< OSX >= 10.7 queries sysctl() for CPU count */
#else
#include <Carbon/Carbon.h>  /**< Deprecated Carbon APIs for Multiprocessing */
#endif
#endif

#if defined(__GNUC__) && defined(__linux) && (defined(__ARM_ARCH_ISA_A64) || defined(__ARM_NEON))
#include <sys/auxv.h>       /**< for getauxval() */
#endif

#if defined(__hpux)
#include <sys/mpctl.h>      /**< HP-UX Multiprocessing headers */
#endif


#ifdef __cplusplus
extern "C" {
#endif

int rt_thread_numphysprocessors(void) {
  int a=1;

#ifdef THR
#if defined(__APPLE__)
#if 1
  int rc;
  int mib[2];
  u_int miblen;
  size_t alen = sizeof(a);
  mib[0] = CTL_HW;
  mib[1] = HW_AVAILCPU;
  miblen = 2;
  rc = sysctl(mib, miblen, &a, &alen, NULL, 0); /**< Number of active CPUs */
  if (rc < 0) {
    perror("Error during sysctl() query for CPU count");
    a = 1;
  }
#else
  a = MPProcessorsScheduled();       /**< Number of active/running CPUs */
#endif
#endif

#ifdef _MSC_VER
  struct _SYSTEM_INFO sysinfo;
  GetSystemInfo(&sysinfo);
  a = sysinfo.dwNumberOfProcessors;  /**< total number of CPUs */
#endif /* _MSC_VER */

#if defined(__PARAGON__) 
  a=2; /**< Threads-capable Paragons have 2 CPUs for computation */
#endif /* __PARAGON__ */ 

#if defined(_CRAY)
  a = sysconf(_SC_CRAY_NCPU);        /**< total number of CPUs */
#endif

#if defined(ANDROID) || defined(USEPHYSCPUCOUNT)
  /* Android devices and the NVIDIA/SECO "CARMA" and "Kayla"    */
  /* boards toggles cores on/off according to system activity,  */
  /* thermal management, and battery state.  For now, we will   */
  /* use as many threads as the number of physical cores since  */
  /* the number that are online may vary even over a 2 second   */
  /* time window.  We will likely have this issue on many more  */
  /* platforms as power management becomes more important...    */

  /* use sysconf() for initial guess, although it produces incorrect    */
  /* results on the older android releases due to a bug in the platform */
  a = sysconf(_SC_NPROCESSORS_CONF); /**< Number of physical CPU cores  */

  /* check CPU count by parsing /sys/devices/system/cpu/present and use */
  /* whichever result gives the larger CPU count...                     */
  {
    int rc=0, b=1, i=-1, j=-1;
    FILE *ifp;

    ifp = fopen("/sys/devices/system/cpu/present", "r");
    if (ifp != NULL) {
      rc = fscanf(ifp, "%d-%d", &i, &j); /* read and interpret line */
      fclose(ifp);

      if (rc == 2 && i == 0) {
        b = j+1; /* 2 or more cores exist */
      }
    }

    /* return the greater CPU count result... */
    a = (a > b) ? a : b;
  }
#else
#if defined(__sun) || defined(__linux) || defined(__osf__) || defined(_AIX)
  a = sysconf(_SC_NPROCESSORS_ONLN); /**< Number of active/running CPUs */
#endif /* SunOS, and similar... */
#endif /* Android */

#if defined(__irix)
  a = sysconf(_SC_NPROC_ONLN);       /**< Number of active/running CPUs */
#endif /* IRIX */

#if defined(__hpux)
  a = mpctl(MPC_GETNUMSPUS, 0, 0);   /**< total number of CPUs */
#endif /* HPUX */
#endif /* THR */

  return a;
}


int rt_thread_numprocessors(void) {
  int a=1;

#ifdef THR
  /* Allow the user to override the number of CPUs for use */
  /* in scalability testing, debugging, etc.               */
  char *forcecount = getenv("RTFORCECPUCOUNT");
  if (forcecount != NULL) {
    if (sscanf(forcecount, "%d", &a) == 1) {
      return a; /* if we got a valid count, return it */
    } else {
      a=1;      /* otherwise use the real available hardware CPU count */
    }
  }

  /* otherwise return the number of physical processors currently available */
  a = rt_thread_numphysprocessors();

  /* XXX we should add checking for the current CPU affinity masks here, */
  /* and return the min of the physical processor count and CPU affinity */
  /* mask enabled CPU count.                                             */
#endif /* THR */

  return a;
}


/*
 * Functions supporting processor-specific runtime dispatch for hand-written
 * kernels using SIMD vector intrinsics or other highly specialized routines.
 */
#define RT_USEINTCPUID 1
#if defined(RT_USEINTCPUID) && (defined(__GNUC__) || defined(__INTEL_COMPILER) || (defined(_MSC_VER) && (_MSC_VER >= 1916))) && (defined(__i386__) || defined(__x86_64__) || defined(_M_IX86) || defined(_M_AMD64))
#if 1
//static void rt_cpuid(uint32_t eax, uint32_t ecx, uint32_t* abcd) {
static void rt_cpuid(unsigned int eax, unsigned int ecx, unsigned int* abcd) {
#if defined(_MSC_VER)
  __cpuidex((int*)abcd, eax, ecx);
#else
//  uint32_t ebx, edx;
  unsigned int ebx=0, edx=0;
#if defined(__i386__) && defined (__PIC__)
  /* in case of PIC under 32-bit EBX cannot be clobbered */
  __asm__("movl %%ebx, %%edi \n\t cpuid \n\t xchgl %%ebx, %%edi" : "=D" (ebx),
#else
  __asm__("cpuid" : "+b" (ebx),
#endif
          "+a" (eax), "+c" (ecx), "=d" (edx));
          abcd[0] = eax; abcd[1] = ebx; abcd[2] = ecx; abcd[3] = edx;
#endif
  }
#else
static void rt_cpuid(unsigned int eax, unsigned int ecx, unsigned int *info) {
  __asm__ __volatile__(
    "xchg %%ebx, %%edi;"
    "cpuid;"
    "xchg %%ebx, %%edi;"
    :"=a" (info[0]), "=D" (info[1]), "=c" (info[2]), "=d" (info[3])
    :"0" (eax)
  );
}
#endif

static unsigned long long rt_xgetbv(unsigned int index) {
#if defined(_MSC_VER)
  return _xgetbv(index);
#else
  unsigned int eax=0, edx=0;
  __asm__ __volatile__(
    "xgetbv;"
    : "=a" (eax), "=d"(edx)
    : "c" (index)
  );
  return ((unsigned long long) edx << 32) | eax;
#endif
}
#endif


int rt_cpu_capability_flags(rt_cpu_caps_t *cpucaps) {
  int flags=CPU_UNKNOWN;
  int smtdepth = CPU_SMTDEPTH_UNKNOWN;

#if defined(RT_USEINTCPUID) && (defined(__GNUC__) || defined(__INTEL_COMPILER) || (defined(_MSC_VER) && (_MSC_VER >= 1916))) && (defined(__i386__) || defined(__x86_64__) || defined(_M_IX86) || defined(_M_AMD64))
#define RT_INTERNAL_ENABLE_CPUCAP_BAILOUT 1
  // https://software.intel.com/content/www/us/en/develop/articles/how-to-detect-new-instruction-support-in-the-4th-generation-intel-core-processor-family.html
  // https://stackoverflow.com/questions/6121792/how-to-check-if-a-cpu-supports-the-sse3-instruction-set
  // https://gist.github.com/hi2p-perim/7855506
  // http://www.hugi.scene.org/online/coding/hugi%2016%20-%20corawhd4.htm
  // http://www.geoffchappell.com/studies/windows/km/cpu/precpuid.htm
  // http://www.geoffchappell.com/studies/windows/km/cpu/cpuid/index.htm
  // https://www.sandpile.org/x86/cpuid.htm
  // https://lemire.me/blog/2020/07/17/the-cost-of-runtime-dispatch/
  // https://github.com/google/cpu_features/
  // https://github.com/klauspost/cpuid
  // https://github.com/anrieff/libcpuid/tree/master/libcpuid
  // Considerations about clock rate capping and false dependencies
  //   when high AVX/AVX-512 registers are considered "in use" with 
  //   stale data, unless cleared, e.g., by _mm256_zeroupper():
  //   https://blog.cloudflare.com/on-the-dangers-of-intels-frequency-scaling/
  //   https://www.agner.org/optimize/blog/read.php?i=857
  unsigned int vendcpuinfo[4] = { 0 };
  unsigned int cpuinfo[4] = { 0 };
  unsigned long long xcrFeatureMask = 0;
  int havexmmymm = 0;
  int havezmmmask = 0;
  int haveosxsave = 0;

  rt_cpuid(0, 0, vendcpuinfo); /* get vendor string, highest function code */
  if (vendcpuinfo[0] == 0)
    goto nocpuinfo; /* bail on very primitive CPU type, max fctn code==0 */

  rt_cpuid(1, 0, cpuinfo);     /* get various SIMD extension flags */
  haveosxsave = (cpuinfo[2] & (1 << 27)) != 0; /* OS save/restore xmm regs */

  flags = 0;
  flags |= ((cpuinfo[2] & (1 << 19)) != 0)           * CPU_SSE4_1;
  flags |= ((cpuinfo[2] & (1 << 29)) != 0)           * CPU_F16C;
  flags |= ((cpuinfo[2] & (1 << 31)) != 0)           * CPU_HYPERVISOR;
  flags |= ((cpuinfo[3] & (1 << 26)) != 0)           * CPU_SSE2;
  flags |= ((cpuinfo[3] & (1 << 28)) != 0)           * CPU_HT;

  /* if we have AVX, we need to call xgetbv too */
  if ((cpuinfo[2] & (1 << 28)) != 0) {
    xcrFeatureMask = rt_xgetbv(0);
    havexmmymm  = (xcrFeatureMask & 0x06) == 0x06;
    havezmmmask = (xcrFeatureMask & 0xE6) == 0xE6;
  }

  flags |= (((cpuinfo[2] & (1 << 12)) != 0) &&
            havexmmymm && haveosxsave)               * CPU_FMA;

  flags |= (((cpuinfo[2] & (1 << 28)) != 0) &&
            havexmmymm && haveosxsave)               * CPU_AVX;

  /* check that we can call CPUID function 7 */
  if (cpuinfo[0] >= 0x7) {
    unsigned int extcpuinfo[4] = { 0 };
    rt_cpuid(7, 0, extcpuinfo);

    flags |= (((extcpuinfo[1] & (1 << 5)) != 0) &&
              havexmmymm && haveosxsave)               * CPU_AVX2;

    flags |= (((extcpuinfo[1] & (1 << 16)) != 0) &&
              havezmmmask && haveosxsave)              * CPU_AVX512F;
    flags |= (((extcpuinfo[1] & (1 << 26)) != 0) &&
              havezmmmask && haveosxsave)              * CPU_AVX512PF;
    flags |= (((extcpuinfo[1] & (1 << 27)) != 0) &&
              havezmmmask && haveosxsave)              * CPU_AVX512ER;
    flags |= (((extcpuinfo[1] & (1 << 28)) != 0) &&
              havezmmmask && haveosxsave)              * CPU_AVX512CD;
  }

  smtdepth = 1;
  if (flags & CPU_HT) {
#if 1
    /* XXX correct this for Phi, OS/BIOS settings */
    smtdepth = 2;

    /* XXX Hack to detect Xeon Phi CPUs since no other CPUs */
    /* support AVX-512ER or AVX-512PF (yet...)              */ 
    if ((flags & CPU_AVX512ER) && (flags & CPU_AVX512PF)) { 
      smtdepth = 4;
    }
#else
    int logicalcores = (cpuinfo[1] >> 16) && 0xFF;
    int physicalcores = logicalcores;
    char vendor[16] = { 0 };
    ((unsigned *)vendor)[0] = vendcpuinfo[1];
    ((unsigned *)vendor)[1] = vendcpuinfo[3];
    ((unsigned *)vendor)[2] = vendcpuinfo[2];

    /* hmm, not quite right yet */
    if (!strcmp(vendor, "GenuineIntel")) {
      unsigned int corecpuinfo[4] = { 0 };
      rt_cpuid(4, 0, corecpuinfo);
      physicalcores = ((corecpuinfo[0] >> 26) & 0x3f) + 1; 
    } else if (!strcmp(vendor, "AuthenticAMD")) {
      unsigned int corecpuinfo[4] = { 0 };
      rt_cpuid(0x80000008, 0, corecpuinfo);
      physicalcores = (corecpuinfo[2] & 0xFF) + 1; 
    }

printf("cpuinfo: %d / %d  vend: %s\n", logicalcores, physicalcores, vendor);

    smtdepth = logicalcores / physicalcores;
#endif
  }

#elif defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1300)

  // https://software.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/intrinsics/intrinsics-for-all-intel-architectures/may-i-use-cpu-feature.html
  flags = 0;
  flags |= _may_i_use_cpu_feature(_FEATURE_SSE2)     * CPU_SSE2;
  flags |= _may_i_use_cpu_feature(_FEATURE_SSE4_1)   * CPU_SSE4_1;
  flags |= _may_i_use_cpu_feature(_FEATURE_AVX)      * CPU_AVX;
  flags |= _may_i_use_cpu_feature(_FEATURE_AVX2)     * CPU_AVX2;
  flags |= _may_i_use_cpu_feature(_FEATURE_FMA)      * CPU_FMA;
  flags |= _may_i_use_cpu_feature(_FEATURE_AVX512F)  * CPU_AVX512F;
  flags |= _may_i_use_cpu_feature(_FEATURE_AVX512CD) * CPU_AVX512CD;
  flags |= _may_i_use_cpu_feature(_FEATURE_AVX512ER) * CPU_AVX512ER;
  flags |= _may_i_use_cpu_feature(_FEATURE_AVX512PF) * CPU_AVX512PF;

#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__)) 

  // https://gcc.gnu.org/onlinedocs/gcc/x86-Built-in-Functions.html
  flags = 0;
  __builtin_cpu_init();
  flags |= (__builtin_cpu_supports("sse2")!=0)       * CPU_SSE2;
  flags |= (__builtin_cpu_supports("sse4.1")!=0)     * CPU_SSE4_1;
  flags |= (__builtin_cpu_supports("avx")!=0)        * CPU_AVX;
  flags |= (__builtin_cpu_supports("avx2")!=0)       * CPU_AVX2;
  flags |= (__builtin_cpu_supports("fma")!=0)        * CPU_FMA;
  flags |= (__builtin_cpu_supports("avx512f")!=0)    * CPU_AVX512F;
  flags |= (__builtin_cpu_supports("avx512cd")!=0)   * CPU_AVX512CD;
  flags |= (__builtin_cpu_supports("avx512er")!=0)   * CPU_AVX512ER;
  flags |= (__builtin_cpu_supports("avx512pf")!=0)   * CPU_AVX512PF;

#elif defined(__GNUC__) && defined(__linux) && (defined(__ARM_ARCH_ISA_A64) || defined(__ARM_NEON))

  // https://golang.org/src/internal/cpu/cpu_arm64.go
  // https://code.woboq.org/qt5/qtbase/src/corelib/tools/qsimd.cpp.html
  // https://www.kernel.org/doc/html/latest/arm64/elf_hwcaps.html
  // https://man7.org/linux/man-pages/man3/getauxval.3.html
  // https://lists.cs.columbia.edu/pipermail/kvmarm/2017-August/026715.html
  unsigned long auxval1=0, auxval2=0;
  auxval1 = getauxval(AT_HWCAP);
  auxval2 = getauxval(AT_HWCAP2);
//  printf("WKFThreadsARM: %016lx %016lx\n", auxval1, auxval2);

  flags = 0;
  flags |= ((auxval1 & HWCAP_FP) != 0)               * CPU_ARM64_FP;

  flags |= ((auxval1 & HWCAP_ASIMD) != 0)            * CPU_ARM64_ASIMD;
  flags |= ((auxval1 & HWCAP_ASIMDHP) != 0)          * CPU_ARM64_ASIMDHP;
  flags |= ((auxval1 & HWCAP_ASIMDRDM) != 0)         * CPU_ARM64_ASIMDRDM;
  flags |= ((auxval1 & HWCAP_ASIMDDP) != 0)          * CPU_ARM64_ASIMDDP;
  flags |= ((auxval1 & HWCAP_ASIMDFHM) != 0)         * CPU_ARM64_ASIMDFHM;

  flags |= ((auxval1 & HWCAP_SVE) != 0)              * CPU_ARM64_SVE;

  flags |= ((auxval1 & HWCAP_AES) != 0)              * CPU_ARM64_AES;
  flags |= ((auxval1 & HWCAP_CRC32) != 0)            * CPU_ARM64_CRC32;
  flags |= ((auxval1 & HWCAP_SHA1) != 0)             * CPU_ARM64_SHA1;
  flags |= ((auxval1 & HWCAP_SHA2) != 0)             * CPU_ARM64_SHA2;
  flags |= ((auxval1 & HWCAP_SHA3) != 0)             * CPU_ARM64_SHA3;
  flags |= ((auxval1 & HWCAP_SHA512) != 0)           * CPU_ARM64_SHA512;

#endif

#if defined(RT_INTERNAL_ENABLE_CPUCAP_BAILOUT)
nocpuinfo:
#endif
  cpucaps->flags = flags;
  cpucaps->smtdepth = smtdepth;

  if (flags == CPU_UNKNOWN)
    return 1;

  return 0;
}


int rt_cpu_smt_depth(void) {
  int smtdepth = CPU_SMTDEPTH_UNKNOWN;

#if defined(RT_USEINTCPUID) && (defined(__GNUC__) || defined(__INTEL_COMPILER)) && (defined(__i386__) || defined(__x86_64__))
  // x86 examples:
  //  https://software.intel.com/en-us/articles/methods-to-utilize-intels-hyper-threading-technology-with-linux
  // https://stackoverflow.com/questions/2901694/how-to-detect-the-number-of-physical-processors-cores-on-windows-mac-and-linu
  rt_cpu_caps_t cpucaps;
  if (!rt_cpu_capability_flags(&cpucaps)) {
    smtdepth = cpucaps.smtdepth;
  }
#endif

  return smtdepth;
}


int * rt_cpu_affinitylist(int *cpuaffinitycount) {
  int *affinitylist = NULL;
  *cpuaffinitycount = -1; /* return count -1 if unimplemented or err occurs */

/* Win32 process affinity mask query */
#if 0 && defined(_MSC_VER)
  /* XXX untested, but based on the linux code, may work with a few tweaks */
  HANDLE myproc = GetCurrentProcess(); /* returns a psuedo-handle */
  DWORD affinitymask, sysaffinitymask;

  if (!GetProcessAffinityMask(myproc, &affinitymask, &sysaffinitymask)) {
    /* count length of affinity list */
    int affinitycount=0;
    int i;
    for (i=0; i<31; i++) {
      affinitycount += (affinitymask >> i) & 0x1;
    }

    /* build affinity list */
    if (affinitycount > 0) {
      affinitylist = (int *) malloc(affinitycount * sizeof(int));
      if (affinitylist == NULL)
        return NULL;

      int curcount = 0;
      for (i=0; i<CPU_SETSIZE; i++) {
        if (CPU_ISSET(i, &affinitymask)) {
          affinitylist[curcount] = i;
          curcount++;
        }
      }
    }

    *cpuaffinitycount = affinitycount; /* return final affinity list */
  }
#endif

/* Linux process affinity mask query */
#if defined(__linux)

/* protect ourselves from some older Linux distros */
#if defined(CPU_SETSIZE)
  int i;
  cpu_set_t affinitymask;
  int affinitycount=0;

  /* PID 0 refers to the current process */
  if (sched_getaffinity(0, sizeof(affinitymask), &affinitymask) < 0) {
    perror("rt_cpu_affinitylist: sched_getaffinity");
    return NULL;
  }

  /* count length of affinity list */
  for (i=0; i<CPU_SETSIZE; i++) {
    affinitycount += CPU_ISSET(i, &affinitymask);
  }

  /* build affinity list */
  if (affinitycount > 0) {
    affinitylist = (int *) malloc(affinitycount * sizeof(int));
    if (affinitylist == NULL)
      return NULL;

    int curcount = 0;
    for (i=0; i<CPU_SETSIZE; i++) {
      if (CPU_ISSET(i, &affinitymask)) {
        affinitylist[curcount] = i;
        curcount++;
      }
    }
  }

  *cpuaffinitycount = affinitycount; /* return final affinity list */
#endif
#endif

  /* MacOS X 10.5.x has a CPU affinity query/set capability finally      */
  /* http://developer.apple.com/releasenotes/Performance/RN-AffinityAPI/ */

  /* Solaris and HP-UX use pset_bind() and related functions, and they   */
  /* don't use the single-level mask-based scheduling mechanism that     */
  /* the others, use.  Instead, they use a hierarchical tree of          */
  /* processor sets and processes float within those, or are tied to one */
  /* processor that's a member of a particular set.                      */

  return affinitylist;
}


int rt_thread_set_self_cpuaffinity(int cpu) {
  int status=-1; /* unsupported by default */

#ifdef THR

#if defined(__linux) && defined(CPU_ZERO) && defined(CPU_SET)
#if defined(__MIC__)
  /* XXX this is available on Intel MIC */
  /* XXX this code is too new even for RHEL4, though it runs on Fedora 7 */
  /* and other newer revs.                                               */
  /* NPTL systems can assign per-thread affinities this way              */
  cpu_set_t affinitymask;
  CPU_ZERO(&affinitymask);
  CPU_SET(cpu, &affinitymask);
  status = pthread_setaffinity_np(pthread_self(), sizeof(affinitymask), &affinitymask);
#else
  /* non-NPTL systems based on the clone() API must use this method      */
  cpu_set_t affinitymask;
  CPU_ZERO(&affinitymask);
  CPU_SET(cpu, &affinitymask);

  /* PID 0 refers to the current process */
  if ((status=sched_setaffinity(0, sizeof(affinitymask), &affinitymask)) < 0) {
    perror("rt_thread_set_self_cpuaffinitylist: sched_setaffinity");
    return status;
  }
#endif

  /* call sched_yield() so new affinity mask takes effect immediately */
  sched_yield();
#endif /* linux */

  /* MacOS X 10.5.x has a CPU affinity query/set capability finally      */
  /* http://developer.apple.com/releasenotes/Performance/RN-AffinityAPI/ */

  /* Solaris and HP-UX use pset_bind() and related functions, and they   */
  /* don't use the single-level mask-based scheduling mechanism that     */
  /* the others, use.  Instead, they use a hierarchical tree of          */
  /* processor sets and processes float within those, or are tied to one */
  /* processor that's a member of a particular set.                      */
#endif

  return status;
}


int rt_thread_setconcurrency(int nthr) {
  int status=0;

#ifdef THR
#if defined(__sun)
#ifdef USEPOSIXTHREADS
  status = pthread_setconcurrency(nthr);
#else
  status = thr_setconcurrency(nthr);
#endif
#endif /* SunOS */

#if defined(__irix) || defined(_AIX)
  status = pthread_setconcurrency(nthr);
#endif
#endif /* THR */

  return status;
}


/*
 * Thread creation/management
 */
/** Typedef to eliminate compiler warning caused by C/C++ linkage conflict. */
typedef void * (*RTTHREAD_START_ROUTINE)(void *);

int rt_thread_create(rt_thread_t * thr, void * fctn(void *), void * arg) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
  DWORD tid; /* thread id, msvc only */
  *thr = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) fctn, arg, 0, &tid);
  if (*thr == NULL) {
    status = -1;
  }
  // If we want to spawn the thread "detached" without ever joining it in the
  // future, such that it's totally on its own, we need to call CloseHandle()
  // immediately on creation so the handle doesn't leak.  If we need to join
  // later, we call CloseHandle() at the end of the join sync-up.
  // CloseHandle(thr);
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS 
#if defined(_AIX)
  /* AIX schedule threads in system scope by default, have to ask explicitly */
  {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    status = pthread_create(thr, &attr, (RTTHREAD_START_ROUTINE)fctn, arg);
    pthread_attr_destroy(&attr);
  }
#elif defined(__PARAGON__)
  status = pthread_create(thr, pthread_attr_default, fctn, arg);
#else   
  status = pthread_create(thr, NULL, (RTTHREAD_START_ROUTINE)fctn, arg);
#endif 
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS 
  status = thr_create(NULL, 0, (RTTHREAD_START_ROUTINE)fctn, arg, 0, thr); 
#endif /* USEUITHREADS */
#endif /* THR */
 
  return status;
}


int rt_thread_join(rt_thread_t thr, void ** stat) {
  int status=0;  

#ifdef THR
#ifdef _MSC_VER
  DWORD wstatus = 0;
 
  wstatus = WAIT_TIMEOUT;
 
  while (wstatus != WAIT_OBJECT_0) {
    wstatus = WaitForSingleObject(thr, INFINITE);
  }
  // Windows won't free the thread handle until both the thread terminates
  // AND all existing handles to it are explicitly closed
  CloseHandle(thr);
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_join(thr, stat);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = thr_join(thr, NULL, stat);
#endif /* USEPOSIXTHREADS */
#endif /* THR */

  return status;
}  


/*
 * Mutexes
 */
int rt_mutex_init(rt_mutex_t * mp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
  InitializeCriticalSection(mp);
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_mutex_init(mp, 0);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS 
  status = mutex_init(mp, USYNC_THREAD, NULL);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


int rt_mutex_lock(rt_mutex_t * mp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
  EnterCriticalSection(mp);
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_mutex_lock(mp);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = mutex_lock(mp);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


int rt_mutex_trylock(rt_mutex_t * mp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
#if defined(THRUSENEWWIN32APIS)
  /* TryEnterCriticalSection() is only available on newer */
  /* versions of Win32: _WIN32_WINNT/WINVER >= 0x0400     */
  status = (!(TryEnterCriticalSection(mp)));
#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = (pthread_mutex_lock(mp) != 0);
#endif /* USEPOSIXTHREADS */
#endif /* THR */

  return status;
}


int rt_mutex_spin_lock(rt_mutex_t * mp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
#if defined(THRUSENEWWIN32APIS)
  /* TryEnterCriticalSection() is only available on newer */
  /* versions of Win32: _WIN32_WINNT/WINVER >= 0x0400     */
  while (!TryEnterCriticalSection(mp));
#else
  EnterCriticalSection(mp);
#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  while ((status = pthread_mutex_trylock(mp)) != 0);
#endif /* USEPOSIXTHREADS */
#endif /* THR */

  return status;
}


int rt_mutex_unlock(rt_mutex_t * mp) {
  int status=0;

#ifdef THR  
#ifdef _MSC_VER
  LeaveCriticalSection(mp);
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_mutex_unlock(mp);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = mutex_unlock(mp);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


int rt_mutex_destroy(rt_mutex_t * mp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
  DeleteCriticalSection(mp);
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_mutex_destroy(mp);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = mutex_destroy(mp);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


/*
 * Condition variables
 */
int rt_cond_init(rt_cond_t * cvp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
#if defined(RTUSEWIN2008CONDVARS)
  InitializeConditionVariable(cvp);
#else
  /* XXX not implemented */
  cvp->waiters = 0;

  /* Create an auto-reset event. */
  cvp->events[RT_COND_SIGNAL] = CreateEvent(NULL,  /* no security */
                                            FALSE, /* auto-reset event */
                                            FALSE, /* non-signaled initially */
                                            NULL); /* unnamed */

  /* Create a manual-reset event. */
  cvp->events[RT_COND_BROADCAST] = CreateEvent(NULL,  /* no security */
                                               TRUE,  /* manual-reset */
                                               FALSE, /* non-signaled initially */
                                               NULL); /* unnamed */
#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_cond_init(cvp, NULL);
#endif /* USEPOSIXTHREADS */
#ifdef USEUITHREADS
  status = cond_init(cvp, USYNC_THREAD, NULL);
#endif
#endif /* THR */

  return status;
}

int rt_cond_destroy(rt_cond_t * cvp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
#if defined(RTUSEWIN2008CONDVARS)
  /* XXX not implemented */
#else
  CloseHandle(cvp->events[RT_COND_SIGNAL]);
  CloseHandle(cvp->events[RT_COND_BROADCAST]);
#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_cond_destroy(cvp);
#endif /* USEPOSIXTHREADS */
#ifdef USEUITHREADS
  status = cond_destroy(cvp);
#endif
#endif /* THR */

  return status;
}

int rt_cond_wait(rt_cond_t * cvp, rt_mutex_t * mp) {
  int status=0;
#if defined(THR) && defined(_MSC_VER)
  int result=0;
  LONG last_waiter;
  LONG my_waiter;
#endif

#ifdef THR
#ifdef _MSC_VER
#if defined(RTUSEWIN2008CONDVARS)
  SleepConditionVariableCS(cvp, mp, INFINITE)
#else
#if !defined(RTUSEINTERLOCKEDATOMICOPS)
  EnterCriticalSection(&cvp->waiters_lock);
  cvp->waiters++;
  LeaveCriticalSection(&cvp->waiters_lock);
#else
  InterlockedIncrement(&cvp->waiters);
#endif

  LeaveCriticalSection(mp); /* SetEvent() keeps state, avoids lost wakeup */

  /* Wait either a single or broadcast even to become signalled */
  result = WaitForMultipleObjects(2, cvp->events, FALSE, INFINITE);

#if !defined(RTUSEINTERLOCKEDATOMICOPS)
  EnterCriticalSection (&cvp->waiters_lock);
  cvp->waiters--;
  last_waiter =
    ((result == (WAIT_OBJECT_0 + RT_COND_BROADCAST)) && cvp->waiters == 0);
  LeaveCriticalSection (&cvp->waiters_lock);
#else
  my_waiter = InterlockedDecrement(&cvp->waiters);
  last_waiter =
    ((result == (WAIT_OBJECT_0 + RT_COND_BROADCAST)) && my_waiter == 0);
#endif

  /* Some thread called cond_broadcast() */
  if (last_waiter)
    /* We're the last waiter to be notified or to stop waiting, so */
    /* reset the manual event.                                     */
    ResetEvent(cvp->events[RT_COND_BROADCAST]);

  EnterCriticalSection(mp);
#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_cond_wait(cvp, mp);
#endif /* USEPOSIXTHREADS */
#ifdef USEUITHREADS
  status = cond_wait(cvp, mp);
#endif
#endif /* THR */

  return status;
}

int rt_cond_signal(rt_cond_t * cvp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
#if defined(RTUSEWIN2008CONDVARS)
  WakeConditionVariable(cvp);
#else
#if !defined(RTUSEINTERLOCKEDATOMICOPS)
  EnterCriticalSection(&cvp->waiters_lock);
  int have_waiters = (cvp->waiters > 0);
  LeaveCriticalSection(&cvp->waiters_lock);
  if (have_waiters)
    SetEvent (cvp->events[RT_COND_SIGNAL]);
#else
  if (InterlockedExchangeAdd(&cvp->waiters, 0) > 0)
    SetEvent(cvp->events[RT_COND_SIGNAL]);
#endif
#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_cond_signal(cvp);
#endif /* USEPOSIXTHREADS */
#ifdef USEUITHREADS
  status = cond_signal(cvp);
#endif
#endif /* THR */

  return status;
}

int rt_cond_broadcast(rt_cond_t * cvp) {
  int status=0;

#ifdef THR
#ifdef _MSC_VER
#if defined(RTUSEWIN2008CONDVARS)
  WakeAllConditionVariable(cvp);
#else
#if !defined(RTUSEINTERLOCKEDATOMICOPS)
  EnterCriticalSection(&cvp->waiters_lock);
  int have_waiters = (cvp->waiters > 0);
  LeaveCriticalSection(&cvp->waiters_lock);
  if (have_waiters)
    SetEvent(cvp->events[RT_COND_BROADCAST]);
#else
  if (InterlockedExchangeAdd(&cvp->waiters, 0) > 0)
    SetEvent(cvp->events[RT_COND_BROADCAST]);
#endif

#endif
#endif /* _MSC_VER */

#ifdef USEPOSIXTHREADS
  status = pthread_cond_broadcast(cvp);
#endif /* USEPOSIXTHREADS */
#ifdef USEUITHREADS
  status = cond_broadcast(cvp);
#endif
#endif /* THR */

  return status;
}


/*
 * Atomic integer ops -- Ideally implemented by fast machine instruction 
 *                       fetch-and-add operations.  Worst-case implementation 
 *                       based on mutex locks and math ops if no other choice.
 */

int rt_atomic_int_init(rt_atomic_int_t * atomp, int val) {
  memset(atomp, 0, sizeof(rt_atomic_int_t));
#ifdef THR
#if defined(USEGCCATOMICS)
  /* nothing to do here */
#elif defined(USENETBSDATOMICS) 
  /* nothing to do here */
#elif defined(USESOLARISATOMICS) 
  /* nothing to do here */
#elif defined(USEWIN32ATOMICS) 
  /* nothing to do here */
#else  /* use mutexes */
  rt_mutex_init(&atomp->lock);
#endif
#else
  /* nothing to do for non-threaded builds */
#endif
  atomp->val = val;

  return 0;
}


int rt_atomic_int_destroy(rt_atomic_int_t * atomp) {
#ifdef THR
#if defined(USEGCCATOMICS)
  /* nothing to do here */
#elif defined(USENETBSDATOMICS) 
  /* nothing to do here */
#elif defined(USESOLARISATOMICS) 
  /* nothing to do here */
#elif defined(USEWIN32ATOMICS) 
  /* nothing to do here */
#else  /* use mutexes */
  rt_mutex_destroy(&atomp->lock);
#endif
#else
  /* nothing to do for non-threaded builds */
#endif

  return 0;
}


int rt_atomic_int_set(rt_atomic_int_t * atomp, int val) {
  int retval;

#ifdef THR
#if defined(USEGCCATOMICS)
  /* nothing special to do here? */
  atomp->val = val;  
  retval = val;
#elif defined(USENETBSDATOMICS) 
  /* nothing special to do here? */
  atomp->val = val;  
  retval = val;
#elif defined(USESOLARISATOMICS) 
  /* nothing special to do here? */
  atomp->val = val;  
  retval = val;
#elif defined(USEWIN32ATOMICS) 
  /* nothing special to do here? */
  atomp->val = val;  
  retval = val;
#else  /* use mutexes */
  rt_mutex_lock(&atomp->lock);
  atomp->val = val;  
  retval = atomp->val;
  rt_mutex_unlock(&atomp->lock);
#endif
#else
  /* nothing special to do here */
  atomp->val = val;  
  retval = atomp->val;
#endif
  
  return retval;
}


int rt_atomic_int_get(rt_atomic_int_t * atomp) {
  int retval;

#ifdef THR
#if defined(USEGCCATOMICS)
  /* nothing special to do here? */
  retval = atomp->val;
#elif defined(USENETBSDATOMICS) 
  /* nothing special to do here? */
  retval = atomp->val;
#elif defined(USESOLARISATOMICS) 
  /* nothing special to do here? */
  retval = atomp->val;
#elif defined(USEWIN32ATOMICS) 
  /* nothing special to do here? */
  retval = atomp->val;
#else  /* use mutexes */
  rt_mutex_lock(&atomp->lock);
  retval = atomp->val;
  rt_mutex_unlock(&atomp->lock);
#endif
#else
  /* nothing special to do here */
  retval = atomp->val;
#endif
  
  return retval;
}

int rt_atomic_int_fetch_and_add(rt_atomic_int_t * atomp, int inc) {
#ifdef THR
#if defined(USEGCCATOMICS)
  return __sync_fetch_and_add(&atomp->val, inc);
#elif defined(USENETBSDATOMICS) 
  /* value returned is the new value, so we have to subtract it off again */
  return atomic_add_int_nv(&atomp->val, inc) - inc;
#elif defined(USESOLARISATOMICS) 
  /* value returned is the new value, so we have to subtract it off again */
  return atomic_add_int_nv(&atomp->val, inc) - inc;
#elif defined(USEWIN32ATOMICS) 
  return InterlockedExchangeAdd(&atomp->val, inc);
#else  /* use mutexes */
  int retval;
  rt_mutex_lock(&atomp->lock);
  retval = atomp->val;
  atomp->val+=inc;
  rt_mutex_unlock(&atomp->lock);
  return retval;
#endif
#else
  int retval = atomp->val;
  atomp->val+=inc;
  return retval;
#endif
}


int rt_atomic_int_add_and_fetch(rt_atomic_int_t * atomp, int inc) {
#ifdef THR
#if defined(USEGCCATOMICS)
  return __sync_add_and_fetch(&atomp->val, inc);
#elif defined(USENETBSDATOMICS) 
  return atomic_add_int_nv(&atomp->val, inc);
#elif defined(USESOLARISATOMICS) 
  return atomic_add_int_nv(&atomp->val, inc);
#elif defined(USEWIN32ATOMICS) 
  /* value returned is the old value, so we have to add it on again */
  return InterlockedExchangeAdd(&atomp->val, inc) + inc;
#else  /* use mutexes */
  int retval; 
  rt_mutex_lock(&atomp->lock);
  atomp->val+=inc;
  retval = atomp->val;
  rt_mutex_unlock(&atomp->lock);
  return retval;
#endif
#else
  int retval;
  atomp->val+=inc;
  retval = atomp->val;
  return retval;
#endif
}



/*
 * Reader/Writer locks -- slower than mutexes but good for some purposes
 */
int rt_rwlock_init(rt_rwlock_t * rwp) {
  int status=0;

#ifdef THR  
#ifdef _MSC_VER
  rt_mutex_init(&rwp->lock);
  rt_cond_init(&rwp->rdrs_ok);
  rt_cond_init(&rwp->wrtr_ok);
  rwp->rwlock = 0;
  rwp->waiting_writers = 0;
#endif

#ifdef USEPOSIXTHREADS
  pthread_mutex_init(&rwp->lock, NULL);
  pthread_cond_init(&rwp->rdrs_ok, NULL);
  pthread_cond_init(&rwp->wrtr_ok, NULL);
  rwp->rwlock = 0;
  rwp->waiting_writers = 0;
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = rwlock_init(rwp, USYNC_THREAD, NULL);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


int rt_rwlock_readlock(rt_rwlock_t * rwp) {
  int status=0;

#ifdef THR  
#ifdef _MSC_VER
  rt_mutex_lock(&rwp->lock);
  while (rwp->rwlock < 0 || rwp->waiting_writers) 
    rt_cond_wait(&rwp->rdrs_ok, &rwp->lock);   
  rwp->rwlock++;   /* increment number of readers holding the lock */
  rt_mutex_unlock(&rwp->lock);
#endif

#ifdef USEPOSIXTHREADS
  pthread_mutex_lock(&rwp->lock);
  while (rwp->rwlock < 0 || rwp->waiting_writers) 
    pthread_cond_wait(&rwp->rdrs_ok, &rwp->lock);   
  rwp->rwlock++;   /* increment number of readers holding the lock */
  pthread_mutex_unlock(&rwp->lock);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = rw_rdlock(rwp);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


int rt_rwlock_writelock(rt_rwlock_t * rwp) {
  int status=0;

#ifdef THR  
#ifdef _MSC_VER
  rt_mutex_lock(&rwp->lock);
  while (rwp->rwlock != 0) {
    rwp->waiting_writers++;
    rt_cond_wait(&rwp->wrtr_ok, &rwp->lock);
    rwp->waiting_writers--;
  }
  rwp->rwlock=-1;
  rt_mutex_unlock(&rwp->lock);
#endif

#ifdef USEPOSIXTHREADS
  pthread_mutex_lock(&rwp->lock);
  while (rwp->rwlock != 0) {
    rwp->waiting_writers++;
    pthread_cond_wait(&rwp->wrtr_ok, &rwp->lock);
    rwp->waiting_writers--;
  }
  rwp->rwlock=-1;
  pthread_mutex_unlock(&rwp->lock);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = rw_wrlock(rwp);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


int rt_rwlock_unlock(rt_rwlock_t * rwp) {
  int status=0;

#ifdef THR  
#ifdef _MSC_VER
  int ww, wr;
  rt_mutex_lock(&rwp->lock);
  if (rwp->rwlock > 0) {
    rwp->rwlock--;
  } else {
    rwp->rwlock = 0;
  } 
  ww = (rwp->waiting_writers && rwp->rwlock == 0);
  wr = (rwp->waiting_writers == 0);
  rt_mutex_unlock(&rwp->lock);
  if (ww) 
    rt_cond_signal(&rwp->wrtr_ok);
  else if (wr)
    rt_cond_signal(&rwp->rdrs_ok);
#endif

#ifdef USEPOSIXTHREADS
  int ww, wr;
  pthread_mutex_lock(&rwp->lock);
  if (rwp->rwlock > 0) {
    rwp->rwlock--;
  } else {
    rwp->rwlock = 0;
  } 
  ww = (rwp->waiting_writers && rwp->rwlock == 0);
  wr = (rwp->waiting_writers == 0);
  pthread_mutex_unlock(&rwp->lock);
  if (ww) 
    pthread_cond_signal(&rwp->wrtr_ok);
  else if (wr)
    pthread_cond_signal(&rwp->rdrs_ok);
#endif /* USEPOSIXTHREADS */

#ifdef USEUITHREADS
  status = rw_unlock(rwp);
#endif /* USEUITHREADS */
#endif /* THR */

  return status;
}


/*
 * Simple counting barrier primitive
 */
rt_barrier_t * rt_thread_barrier_init(int n_clients) {
  rt_barrier_t *barrier = (rt_barrier_t *) malloc(sizeof(rt_barrier_t));

#ifdef THR
  if (barrier != NULL) {
    barrier->n_clients = n_clients;
    barrier->n_waiting = 0;
    barrier->phase = 0;
    barrier->sum = 0;
    rt_mutex_init(&barrier->lock);
    rt_cond_init(&barrier->wait_cv);
  }
#endif

  return barrier;
}


/* When rendering in the CAVE we use a special synchronization    */
/* mode so that shared memory mutexes and condition variables     */
/* will work correctly when accessed from multiple processes.     */
/* Inter-process synchronization involves the kernel to a greater */
/* degree, so these barriers are substantially more costly to use */
/* than the ones designed for use within a single-process.        */
int rt_thread_barrier_init_proc_shared(rt_barrier_t *barrier, int n_clients) {
#ifdef THR
#ifdef USEPOSIXTHREADS
  if (barrier != NULL) {
    barrier->n_clients = n_clients;
    barrier->n_waiting = 0;
    barrier->phase = 0;
    barrier->sum = 0;

    pthread_mutexattr_t mattr;
    pthread_condattr_t  cattr;

    printf("Setting barriers to have system scope...\n");

    pthread_mutexattr_init(&mattr);
    if (pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED) != 0) {
      printf("WARNING: could not set mutex to process shared scope\n");
    }

    pthread_condattr_init(&cattr);
    if (pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED) != 0) {
      printf("WARNING: could not set mutex to process shared scope\n");
    }

    pthread_mutex_init(&barrier->lock, &mattr);
    pthread_cond_init(&barrier->wait_cv, &cattr);

    pthread_condattr_destroy(&cattr);
    pthread_mutexattr_destroy(&mattr);
  }
#endif
#endif

  return 0;
}


void rt_thread_barrier_destroy(rt_barrier_t *barrier) {
#ifdef THR
  rt_mutex_destroy(&barrier->lock);
  rt_cond_destroy(&barrier->wait_cv);
#endif
  free(barrier);
}


int rt_thread_barrier(rt_barrier_t *barrier, int increment) {
#ifdef THR
  int my_phase;
  int my_result;

  rt_mutex_lock(&barrier->lock);
  my_phase = barrier->phase;
  barrier->sum += increment;
  barrier->n_waiting++;

  if (barrier->n_waiting == barrier->n_clients) {
    barrier->result = barrier->sum;
    barrier->sum = 0;
    barrier->n_waiting = 0;
    barrier->phase = 1 - my_phase;
    rt_cond_broadcast(&barrier->wait_cv);
  }

  while (barrier->phase == my_phase) {
    rt_cond_wait(&barrier->wait_cv, &barrier->lock);
  }

  my_result = barrier->result;

  rt_mutex_unlock(&barrier->lock);

  return my_result; 
#else 
  return 0;
#endif
}


/*
 * Barriers used for sleepable thread pools
 */
/* symmetric run barrier for use within a single process */
int rt_thread_run_barrier_init(rt_run_barrier_t *barrier, int n_clients) {
#ifdef THR
  if (barrier != NULL) {
    barrier->n_clients = n_clients;
    barrier->n_waiting = 0;
    barrier->phase = 0;
    barrier->fctn = NULL;

    rt_mutex_init(&barrier->lock);
    rt_cond_init(&barrier->wait_cv);
  }
#endif

  return 0;
}

void rt_thread_run_barrier_destroy(rt_run_barrier_t *barrier) {
#ifdef THR
  rt_mutex_destroy(&barrier->lock);
  rt_cond_destroy(&barrier->wait_cv);
#endif
}


/**
 * Wait until all threads reach barrier, and return the function
 * pointer passed in by the master thread.
 */
void * (*rt_thread_run_barrier(rt_run_barrier_t *barrier,
                               void * fctn(void*),
                               void * parms,
                               void **rsltparms))(void *) {
#if defined(THR)
  int my_phase;
  void * (*my_result)(void*);

  rt_mutex_lock(&barrier->lock);
  my_phase = barrier->phase;
  if (fctn != NULL)
    barrier->fctn = fctn;
  if (parms != NULL)
    barrier->parms = parms;
  barrier->n_waiting++;

  if (barrier->n_waiting == barrier->n_clients) {
    barrier->rslt = barrier->fctn;
    barrier->rsltparms = barrier->parms;
    barrier->fctn = NULL;
    barrier->parms = NULL;
    barrier->n_waiting = 0;
    barrier->phase = 1 - my_phase;
    rt_cond_broadcast(&barrier->wait_cv);
  }

  while (barrier->phase == my_phase) {
    rt_cond_wait(&barrier->wait_cv, &barrier->lock);
  }

  my_result = barrier->rslt;
  if (rsltparms != NULL)
    *rsltparms = barrier->rsltparms;

  rt_mutex_unlock(&barrier->lock);
#else
  void * (*my_result)(void*) = fctn;
  if (rsltparms != NULL)
    *rsltparms = parms;
#endif

  return my_result;
}


/** non-blocking poll to see if peers are already at the barrier */
int rt_thread_run_barrier_poll(rt_run_barrier_t *barrier) {
  int rc=0;
#if defined(THR)
  rt_mutex_lock(&barrier->lock);
  if (barrier->n_waiting == (barrier->n_clients-1)) {
    rc=1;
  }
  rt_mutex_unlock(&barrier->lock);
#endif
  return rc;
}


/*
 * task tile stack
 */
int rt_tilestack_init(rt_tilestack_t *s, int size) {
  if (s == NULL)
    return -1;

#if defined(THR)
  rt_mutex_init(&s->mtx);
#endif

  s->growthrate = 512;
  s->top = -1;

  if (size > 0) {
    s->size = size;
    s->s = (rt_tasktile_t *) malloc(s->size * sizeof(rt_tasktile_t));
  } else {
    s->size = 0;
    s->s = NULL;
  }

  return 0;
}


void rt_tilestack_destroy(rt_tilestack_t *s) {
#if defined(THR)
  rt_mutex_destroy(&s->mtx);
#endif
  free(s->s);
  s->s = NULL; /* prevent access after free */
}


int rt_tilestack_compact(rt_tilestack_t *s) {
#if defined(THR)
  rt_mutex_lock(&s->mtx);
#endif
  if (s->size > (s->top + 1)) {
    int newsize = s->top + 1;
    rt_tasktile_t *tmp = (rt_tasktile_t *) realloc(s->s, newsize * sizeof(rt_tasktile_t));
    if (tmp == NULL) {
#if defined(THR)
      rt_mutex_unlock(&s->mtx);
#endif
      return -1; /* out of space! */
    }
    s->s = tmp;
    s->size = newsize;
  }
#if defined(THR)
  rt_mutex_unlock(&s->mtx);
#endif

  return 0;
}


int rt_tilestack_push(rt_tilestack_t *s, const rt_tasktile_t *t) {
#if defined(THR)
  rt_mutex_lock(&s->mtx);
#endif
  s->top++;
  if (s->top >= s->size) {
    int newsize = s->size + s->growthrate;
    rt_tasktile_t *tmp = (rt_tasktile_t *) realloc(s->s, newsize * sizeof(rt_tasktile_t));
    if (tmp == NULL) {
      s->top--;
#if defined(THR)
      rt_mutex_unlock(&s->mtx);
#endif
      return -1; /* out of space! */
    }
    s->s = tmp;
    s->size = newsize;
  }

  s->s[s->top] = *t; /* push onto the stack */

#if defined(THR)
  rt_mutex_unlock(&s->mtx);
#endif

  return 0;
}


int rt_tilestack_pop(rt_tilestack_t *s, rt_tasktile_t *t) {
#if defined(THR)
  rt_mutex_lock(&s->mtx);
#endif

  if (s->top < 0) {
#if defined(THR)
    rt_mutex_unlock(&s->mtx);
#endif
    return RT_TILESTACK_EMPTY; /* empty stack */
  }

  *t = s->s[s->top];
  s->top--;

#if defined(THR)
  rt_mutex_unlock(&s->mtx);
#endif

  return 0;
}


int rt_tilestack_popall(rt_tilestack_t *s) {
#if defined(THR)
  rt_mutex_lock(&s->mtx);
#endif

  s->top = -1;

#if defined(THR)
  rt_mutex_unlock(&s->mtx);
#endif

  return 0;
}


int rt_tilestack_empty(rt_tilestack_t *s) {
#if defined(THR)
  rt_mutex_lock(&s->mtx);
#endif

  if (s->top < 0) {
#if defined(THR)
    rt_mutex_unlock(&s->mtx);
#endif
    return 1;
  }

#if defined(THR)
  rt_mutex_unlock(&s->mtx);
#endif

  return 0;
}


/*
 * shared iterators
 */

/** initialize a shared iterator */
int rt_shared_iterator_init(rt_shared_iterator_t *it) {
  memset(it, 0, sizeof(rt_shared_iterator_t));
#if defined(THR)
  rt_mutex_init(&it->mtx);
#endif
  return 0;
}


/** destroy a shared iterator */
int rt_shared_iterator_destroy(rt_shared_iterator_t *it) {
#if defined(THR)
  rt_mutex_destroy(&it->mtx);
#endif
  return 0;
}


/** set shared iterator parameters */
int rt_shared_iterator_set(rt_shared_iterator_t *it,
                           rt_tasktile_t *tile) {
#if defined(THR)
  rt_mutex_lock(&it->mtx);
#endif
  it->start = tile->start;
  it->current = tile->start;
  it->end = tile->end;
  it->fatalerror = 0;
#if defined(THR)
  rt_mutex_unlock(&it->mtx);
#endif
  return 0;
}


/** iterate the shared iterator, over a requested half-open interval */
int rt_shared_iterator_next_tile(rt_shared_iterator_t *it, int reqsize,
                                 rt_tasktile_t *tile) {
  int rc=RT_SCHED_CONTINUE;

#if defined(THR)
  rt_mutex_spin_lock(&it->mtx);
#endif
  if (!it->fatalerror) {
    tile->start=it->current; /* set start to the current work unit    */
    it->current+=reqsize;    /* increment by the requested tile size  */
    tile->end=it->current;   /* set the (exclusive) endpoint          */

    /* if start is beyond the last work unit, we're done */
    if (tile->start >= it->end) {
      tile->start=0;
      tile->end=0;
      rc = RT_SCHED_DONE;
    }

    /* if the endpoint (exclusive) for the requested tile size */
    /* is beyond the last work unit, roll it back as needed     */
    if (tile->end > it->end) {
      tile->end = it->end;
    }
  } else {
    rc = RT_SCHED_DONE;
  }
#if defined(THR)
  rt_mutex_unlock(&it->mtx);
#endif

  return rc;
}


/** worker thread calls this to indicate a fatal error */
int rt_shared_iterator_setfatalerror(rt_shared_iterator_t *it) {
#if defined(THR)
  rt_mutex_spin_lock(&it->mtx);
#endif
  it->fatalerror=1;
#if defined(THR)
  rt_mutex_unlock(&it->mtx);
#endif
  return 0;
}


/** master thread calls this to query for fatal errors */
int rt_shared_iterator_getfatalerror(rt_shared_iterator_t *it) {
  int rc=0;
#if defined(THR)
  rt_mutex_lock(&it->mtx);
#endif
  if (it->fatalerror)
    rc = -1;
#if defined(THR)
  rt_mutex_unlock(&it->mtx);
#endif
  return rc;
}


#if defined(THR)
/*
 * Thread pool.
 */
static void * rt_threadpool_workerproc(void *voidparms) {
  void *(*fctn)(void*);
  rt_threadpool_workerdata_t *workerdata = (rt_threadpool_workerdata_t *) voidparms;
  rt_threadpool_t *thrpool = (rt_threadpool_t *) workerdata->thrpool;

  while ((fctn = rt_thread_run_barrier(&thrpool->runbar, NULL, NULL, &workerdata->parms)) != NULL) {
    (*fctn)(workerdata);
  }

  return NULL;
}


static void * rt_threadpool_workersync(void *voidparms) {
  return NULL;
}
#endif


rt_threadpool_t * rt_threadpool_create(int workercount, int *devlist) {
  int i;
  rt_threadpool_t *thrpool = NULL;
  thrpool = (rt_threadpool_t *) malloc(sizeof(rt_threadpool_t));
  if (thrpool == NULL)
    return NULL;

  memset(thrpool, 0, sizeof(rt_threadpool_t));

#if !defined(THR)
  workercount=1;
#endif

  /* if caller provides a device list, use it, otherwise we assume */
  /* all workers are CPU cores */
  thrpool->devlist = (int *) malloc(sizeof(int) * workercount);
  if (devlist == NULL) {
    for (i=0; i<workercount; i++)
      thrpool->devlist[i] = -1; /* mark as a CPU core */
  } else {
    memcpy(thrpool->devlist, devlist, sizeof(int) * workercount);
  }

  /* initialize shared iterator */
  rt_shared_iterator_init(&thrpool->iter);

  /* initialize tile stack for error handling */
  rt_tilestack_init(&thrpool->errorstack, 64);

  /* create a run barrier with N+1 threads: N workers, 1 master */
  thrpool->workercount = workercount;
  rt_thread_run_barrier_init(&thrpool->runbar, workercount+1);

  /* allocate and initialize thread pool */
  thrpool->threads = (rt_thread_t *) malloc(sizeof(rt_thread_t) * workercount);
  thrpool->workerdata = (rt_threadpool_workerdata_t *) malloc(sizeof(rt_threadpool_workerdata_t) * workercount);
  memset(thrpool->workerdata, 0, sizeof(rt_threadpool_workerdata_t) * workercount);

  /* setup per-worker data */
  for (i=0; i<workercount; i++) {
    thrpool->workerdata[i].iter=&thrpool->iter;
    thrpool->workerdata[i].errorstack=&thrpool->errorstack;
    thrpool->workerdata[i].threadid=i;
    thrpool->workerdata[i].threadcount=workercount;
    thrpool->workerdata[i].devid=thrpool->devlist[i];
    thrpool->workerdata[i].devspeed=1.0f; /* must be reset by dev setup code */
    thrpool->workerdata[i].thrpool=thrpool;
  }

#if defined(THR)
  /* launch thread pool */
  for (i=0; i<workercount; i++) {
    rt_thread_create(&thrpool->threads[i], rt_threadpool_workerproc, &thrpool->workerdata[i]);
  }
#endif

  return thrpool;
}


int rt_threadpool_launch(rt_threadpool_t *thrpool,
                          void *fctn(void *), void *parms, int blocking) {
  if (thrpool == NULL)
    return -1;

#if defined(THR)
  /* wake sleeping threads to run fctn(parms) */
  rt_thread_run_barrier(&thrpool->runbar, fctn, parms, NULL);
  if (blocking)
    rt_thread_run_barrier(&thrpool->runbar, rt_threadpool_workersync, NULL, NULL);
#else
  thrpool->workerdata[0].parms = parms;
  (*fctn)(&thrpool->workerdata[0]);
#endif
  return 0;
}


int rt_threadpool_wait(rt_threadpool_t *thrpool) {
#if defined(THR)
  rt_thread_run_barrier(&thrpool->runbar, rt_threadpool_workersync, NULL, NULL);
#endif
  return 0;
}


int rt_threadpool_poll(rt_threadpool_t *thrpool) {
#if defined(THR)
  return rt_thread_run_barrier_poll(&thrpool->runbar);
#else
  return 1;
#endif
}


int rt_threadpool_destroy(rt_threadpool_t *thrpool) {
#if defined(THR)
  int i;
#endif

  /* wake threads and tell them to shutdown */
  rt_thread_run_barrier(&thrpool->runbar, NULL, NULL, NULL);

#if defined(THR)
  /* join the pool of worker threads */
  for (i=0; i<thrpool->workercount; i++) {
    rt_thread_join(thrpool->threads[i], NULL);
  }
#endif

  /* destroy the thread barrier */
  rt_thread_run_barrier_destroy(&thrpool->runbar);

  /* destroy the shared iterator */
  rt_shared_iterator_destroy(&thrpool->iter);

  /* destroy tile stack for error handling */
  rt_tilestack_destroy(&thrpool->errorstack);

  free(thrpool->devlist);
  free(thrpool->threads);
  free(thrpool->workerdata);
  free(thrpool);

  return 0;
}


/** return the number of worker threads currently in the pool */
int rt_threadpool_get_workercount(rt_threadpool_t *thrpool) {
  return thrpool->workercount;
}


/** worker thread can call this to get its ID and number of peers */
int rt_threadpool_worker_getid(void *voiddata, int *threadid, int *threadcount) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voiddata;
  if (threadid != NULL)
    *threadid = worker->threadid;

  if (threadcount != NULL)
    *threadcount = worker->threadcount;

  return 0;
}


/** worker thread can call this to get its CPU/GPU device ID */
int rt_threadpool_worker_getdevid(void *voiddata, int *devid) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voiddata;
  if (devid != NULL)
    *devid = worker->devid;

  return 0;
}


/**
 * worker thread calls this to set relative speed of this device
 * as determined by the SM/core count and clock rate
 * Note: this should only be called once, during the worker's
 * device initialization process
 */
int rt_threadpool_worker_setdevspeed(void *voiddata, float speed) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voiddata;
  worker->devspeed = speed;
  return 0;
}


/**
 * worker thread calls this to get relative speed of this device
 * as determined by the SM/core count and clock rate
 */
int rt_threadpool_worker_getdevspeed(void *voiddata, float *speed) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voiddata;
  if (speed != NULL)
    *speed = worker->devspeed;
  return 0;
}


/**
 * worker thread calls this to scale max tile size by worker speed
 * as determined by the SM/core count and clock rate
 */
int rt_threadpool_worker_devscaletile(void *voiddata, int *tilesize) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voiddata;
  if (tilesize != NULL) {
    int scaledtilesize;
    scaledtilesize = (int) (worker->devspeed * ((float) (*tilesize)));
    if (scaledtilesize < 1)
      scaledtilesize = 1;

    *tilesize = scaledtilesize;
  }

  return 0;
}


/** worker thread can call this to get its client data pointer */
int rt_threadpool_worker_getdata(void *voiddata, void **clientdata) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voiddata;
  if (clientdata != NULL)
    *clientdata = worker->parms;

  return 0;
}


/** Set shared iterator state to half-open interval defined by tile */
int rt_threadpool_sched_dynamic(rt_threadpool_t *thrpool, rt_tasktile_t *tile) {
  if (thrpool == NULL)
    return -1;
  return rt_shared_iterator_set(&thrpool->iter, tile);
}


/** iterate the shared iterator over the requested half-open interval */
int rt_threadpool_next_tile(void *voidparms, int reqsize,
                            rt_tasktile_t *tile) {
  int rc;
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voidparms;
  rc = rt_shared_iterator_next_tile(worker->iter, reqsize, tile);
  if (rc == RT_SCHED_DONE) {
    /* if the error stack is empty, then we're done, otherwise pop */
    /* a tile off of the error stack and retry it                  */
    if (rt_tilestack_pop(worker->errorstack, tile) != RT_TILESTACK_EMPTY)
      return RT_SCHED_CONTINUE;
  }

  return rc;
}


/**
 * worker thread calls this when a failure occurs on a tile it has
 * already taken from the scheduler
 */
int rt_threadpool_tile_failed(void *voidparms, rt_tasktile_t *tile) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voidparms;
  return rt_tilestack_push(worker->errorstack, tile);
}


/* worker thread calls this to indicate that an unrecoverable error occured */
int rt_threadpool_setfatalerror(void *voidparms) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voidparms;
  rt_shared_iterator_setfatalerror(worker->iter);
  return 0;
}


/* worker thread calls this to indicate that an unrecoverable error occured */
int rt_threadpool_getfatalerror(void *voidparms) {
  rt_threadpool_workerdata_t *worker = (rt_threadpool_workerdata_t *) voidparms;
  /* query error status for return to caller */
  return rt_shared_iterator_getfatalerror(worker->iter);
}


/* launch up to numprocs threads using shared iterator as a load balancer */
int rt_threadlaunch(int numprocs, void *clientdata, void * fctn(void *),
                    rt_tasktile_t *tile) {
  rt_shared_iterator_t iter;
  rt_threadlaunch_t *parms=NULL;
  rt_thread_t * threads=NULL;
  int i, rc;

  /* XXX have to ponder what the right thing to do is here */
#if !defined(THR)
  numprocs=1;
#endif

  /* initialize shared iterator and set the iteration and range */
  rt_shared_iterator_init(&iter);
  if (rt_shared_iterator_set(&iter, tile))
    return -1;

  /* allocate array of threads */
  threads = (rt_thread_t *) calloc(numprocs * sizeof(rt_thread_t), 1);
  if (threads == NULL)
    return -1;

  /* allocate and initialize array of thread parameters */
  parms = (rt_threadlaunch_t *) malloc(numprocs * sizeof(rt_threadlaunch_t));
  if (parms == NULL) {
    free(threads);
    return -1;
  }
  for (i=0; i<numprocs; i++) {
    parms[i].iter = &iter;
    parms[i].threadid = i;
    parms[i].threadcount = numprocs;
    parms[i].clientdata = clientdata;
  }

#if defined(THR)
  if (numprocs == 1) {
    /* XXX we special-case the single worker thread  */
    /*     scenario because this greatly reduces the */
    /*     GPU kernel launch overhead since a new    */
    /*     contexts doesn't have to be created, and  */
    /*     in the simplest case with a single-GPU we */
    /*     will just be using the same device anyway */
    /*     Ideally we shouldn't need to do this....  */
    /* single thread does all of the work */
    fctn((void *) &parms[0]);
  } else {
    /* spawn child threads to do the work */
    for (i=0; i<numprocs; i++) {
      rt_thread_create(&threads[i], fctn, &parms[i]);
    }

    /* join the threads after work is done */
    for (i=0; i<numprocs; i++) {
      rt_thread_join(threads[i], NULL);
    }
  }
#else
  /* single thread does all of the work */
  fctn((void *) &parms[0]);
#endif

  /* free threads/parms */
  free(parms);
  free(threads);

  /* query error status for return to caller */
  rc=rt_shared_iterator_getfatalerror(&iter);

  /* destroy the shared iterator */
  rt_shared_iterator_destroy(&iter);

  return rc;
}


/** worker thread can call this to get its ID and number of peers */
int rt_threadlaunch_getid(void *voidparms, int *threadid, int *threadcount) {
  rt_threadlaunch_t *worker = (rt_threadlaunch_t *) voidparms;
  if (threadid != NULL)
    *threadid = worker->threadid;

  if (threadcount != NULL)
    *threadcount = worker->threadcount;

  return 0;
}


/** worker thread can call this to get its client data pointer */
int rt_threadlaunch_getdata(void *voidparms, void **clientdata) {
  rt_threadlaunch_t *worker = (rt_threadlaunch_t *) voidparms;
  if (clientdata != NULL)
    *clientdata = worker->clientdata;

  return 0;
}


/** iterate the shared iterator over the requested half-open interval */
int rt_threadlaunch_next_tile(void *voidparms, int reqsize,
                              rt_tasktile_t *tile) {
  rt_threadlaunch_t *worker = (rt_threadlaunch_t *) voidparms;
  return rt_shared_iterator_next_tile(worker->iter, reqsize, tile);
}


/** worker thread calls this to indicate that an unrecoverable error occured */
int rt_threadlaunch_setfatalerror(void *voidparms) {
  rt_threadlaunch_t *worker = (rt_threadlaunch_t *) voidparms;
  return rt_shared_iterator_setfatalerror(worker->iter);
}


#ifdef __cplusplus
}
#endif


