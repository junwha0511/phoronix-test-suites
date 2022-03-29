/*
 * This file is part of John the Ripper password cracker,
 * Copyright (c) 1996-2002,2005,2006,2008,2010,2011,2013,2019 by Solar Designer
 *
 * ...with changes in the jumbo patch for mingw and MSC, by JimF.
 * ...and NT_SSE2 by Alain Espinosa.
 * ...and various little things by magnum
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 *
 * There's ABSOLUTELY NO WARRANTY, express or implied.
 */

/*
 * Architecture specific parameters for x86 with SSE2 asm or intrinsics.
 */

#ifndef _JOHN_ARCH_H
#define _JOHN_ARCH_H

#if AC_BUILT
#include "autoconfig.h"
#else
#if defined (_MSC_VER) && !defined (_OPENMP)
#define __SSE2__ 1
#endif
#define ARCH_WORD			long
#define ARCH_SIZE			4
#define ARCH_BITS			32
#define ARCH_BITS_LOG			5
#define ARCH_BITS_STR			"32"
#define ARCH_LITTLE_ENDIAN		1
#define ARCH_INT_GT_32			0
#endif

#if !defined(ARCH_ALLOWS_UNALIGNED)
#define ARCH_ALLOWS_UNALIGNED		1
#endif
#define ARCH_INDEX(x)			((unsigned int)(unsigned char)(x))

#define DES_ASM				1
#define DES_128K			0
#define DES_X2				1
#define DES_MASK			1
#define DES_SCALE			0
#define DES_EXTB			0
#define DES_COPY			1
#define DES_STD_ALGORITHM_NAME		"DES 48/64 4K MMX"
#define DES_BS_ASM			0
#define DES_BS				1
#define DES_BS_EXPAND			1

#define CPU_DETECT			1
#define CPU_REQ				1

#if !defined(JOHN_NO_SIMD)

#ifdef __AVX512BW__
#define JOHN_AVX512BW			1
#define JOHN_AVX512F			1
#elif defined(__AVX512F__)
#define JOHN_AVX512F			1
#elif defined(__AVX2__)
#define JOHN_AVX2			1
#elif defined(__XOP__)
#define JOHN_XOP			1
#elif defined(__AVX__)
#define JOHN_AVX			1
#elif defined(__SSE4_2__)
#define JOHN_SSE4_2			1
#elif defined(__SSE4_1__)
#define JOHN_SSE4_1			1
#elif defined(__SSSE3__)
#define JOHN_SSSE3			1
#endif

#if defined(JOHN_AVX512F) || defined(JOHN_AVX2) || defined(JOHN_XOP)
#define JOHN_AVX			1
#endif

#ifdef JOHN_AVX512BW
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_AVX512BW		1
#define CPU_NAME			"AVX512BW"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-avx512bw"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_AVX512F)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_AVX512F			1
#define CPU_NAME			"AVX512F"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-avx512"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_AVX2)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_AVX2			1
#define CPU_NAME			"AVX2"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-avx2"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_XOP)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_XOP			1
#define CPU_NAME			"XOP"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-xop"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_AVX)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_AVX			1
#define CPU_NAME			"AVX"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-avx"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_SSE4_2)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_SSE4_2			1
#define CPU_NAME			"SSE4.2"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-sse4.2"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_SSE4_1)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_SSE4_1			1
#define CPU_NAME			"SSE4.1"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-sse4.1"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(JOHN_SSSE3)
#define CPU_DETECT			1
#define CPU_REQ				1
#define CPU_REQ_SSSE3			1
#define CPU_NAME			"SSSE3"
#if CPU_FALLBACK && !defined(CPU_FALLBACK_BINARY)
#define CPU_FALLBACK_BINARY		"john-non-ssse3"
#define CPU_FALLBACK_BINARY_DEFAULT
#endif
#elif defined(__SSE2__)
#define CPU_NAME			"SSE2"
#endif

#endif /* !defined(JOHN_NO_SIMD) */

#if defined(JOHN_AVX) && (defined(__GNUC__) || defined(_OPENMP))
/*
 * Require gcc for non-OpenMP AVX+ builds, because DES_bs_all is aligned in a
 * gcc-specific way in those.  (In non-OpenMP SSE2 builds, it's aligned in the
 * assembly file.  In OpenMP builds, it's aligned by our runtime code.)
 */
#ifdef JOHN_AVX512F
#define DES_BS_VECTOR			16
#undef DES_BS
#define DES_BS				4
#define DES_BS_ALGORITHM_NAME		"DES 512/512 AVX512F"
#elif defined(JOHN_AVX2)
#define DES_BS_VECTOR			8
#define DES_BS_ALGORITHM_NAME		"DES 256/256 AVX2"
#else
#define DES_BS_VECTOR			4
#ifdef JOHN_XOP
#undef DES_BS
#define DES_BS				3
#define DES_BS_ALGORITHM_NAME		"DES 128/128 XOP"
#else
#define DES_BS_ALGORITHM_NAME		"DES 128/128 AVX"
#endif
#endif
#else
/* Not AVX+ or non-gcc non-OpenMP */
#ifndef _OPENMP
#undef DES_BS_ASM
#define DES_BS_ASM			1
#endif
#define DES_BS_VECTOR			4
#define DES_BS_ALGORITHM_NAME		"DES 128/128 SSE2"
#endif

#ifndef CPU_NAME
#define CPU_NAME			"SSE2"
#endif
#ifndef CPU_FALLBACK_BINARY_DEFAULT
#define CPU_FALLBACK_BINARY_DEFAULT	"john-non-sse"
#endif

#ifndef CPU_FALLBACK
#define CPU_FALLBACK			0
#endif
#if !defined(CPU_FALLBACK_BINARY) && defined(CPU_FALLBACK_BINARY_DEFAULT)
#define CPU_FALLBACK_BINARY		CPU_FALLBACK_BINARY_DEFAULT
#endif

#ifdef _OPENMP
#define MD5_ASM				0
#else
#define MD5_ASM				1
#endif
#define MD5_X2				0
#define MD5_IMM				1

#if defined(_OPENMP) || defined(_MSC_VER) || \
    (defined(__GNUC__) && \
    (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)))
#define BF_ASM				0
#ifndef BF_X2
#define BF_X2				1
#endif
#else
#define BF_ASM				1
#define BF_X2				0
#endif
#define BF_SCALE			1

#ifndef JOHN_DISABLE_INTRINSICS
#ifdef __GNUC__
#define GCC_VERSION			(__GNUC__ * 10000 \
			 + __GNUC_MINOR__ * 100 \
			 + __GNUC_PATCHLEVEL__)
#endif

#if __AVX512F__
#define SIMD_COEF_32 16
#define SIMD_COEF_64 8
#elif __AVX2__
#define SIMD_COEF_32 8
#define SIMD_COEF_64 4
#elif __SSE2__
#define SIMD_COEF_32 4
#define SIMD_COEF_64 2
#elif __MMX__
#define SIMD_COEF_32 2
#define SIMD_COEF_64 1
#endif

#ifndef SIMD_PARA_MD4
#if defined(__INTEL_COMPILER)
#define SIMD_PARA_MD4			3
#elif defined(__clang__)
#define SIMD_PARA_MD4			3
#elif defined (_MSC_VER)
#define SIMD_PARA_MD4			1
#elif defined(__GNUC__) && GCC_VERSION < 40405	// 4.4.5
#define SIMD_PARA_MD4			1
#elif defined(__GNUC__) && GCC_VERSION < 40500	// 4.5
#define SIMD_PARA_MD4			2
#elif defined(__GNUC__)
#define SIMD_PARA_MD4			3
#else
#define SIMD_PARA_MD4			2
#endif
#endif /* SIMD_PARA_MD4 */

#ifndef SIMD_PARA_MD5
#if defined(__INTEL_COMPILER)
#define SIMD_PARA_MD5			3
#elif defined(__clang__)
#define SIMD_PARA_MD5			4
#elif defined (_MSC_VER)
#define SIMD_PARA_MD5			1
#elif defined(__GNUC__) && GCC_VERSION < 40405	// 4.4.5
#define SIMD_PARA_MD5			1
#elif defined(__GNUC__)
#define SIMD_PARA_MD5			3
#else
#define SIMD_PARA_MD5			2
#endif
#endif /* SIMD_PARA_MD5 */

#ifndef SIMD_PARA_SHA1
#if defined(__INTEL_COMPILER)
#define SIMD_PARA_SHA1			1
#elif defined(__clang__)
#define SIMD_PARA_SHA1			3
#elif defined (_MSC_VER)
#define SIMD_PARA_SHA1			1
#elif defined(__GNUC__) && GCC_VERSION > 40600 // 4.6
#define SIMD_PARA_SHA1			2
#elif defined(__GNUC__)
#define SIMD_PARA_SHA1			1
#else
#define SIMD_PARA_SHA1			1
#endif
#endif /* SIMD_PARA_SHA1 */

#ifndef SIMD_PARA_SHA256
#define SIMD_PARA_SHA256 1
#endif
#ifndef SIMD_PARA_SHA512
#define SIMD_PARA_SHA512 1
#endif

#define STR_VALUE(arg)			#arg
#define PARA_TO_N(n)			STR_VALUE(n) "x"
#define PARA_TO_MxN(m, n)		STR_VALUE(m) "x" STR_VALUE(n)

#if SIMD_PARA_MD4 > 1
#define MD4_N_STR			PARA_TO_MxN(SIMD_COEF_32, SIMD_PARA_MD4)
#else
#define MD4_N_STR			PARA_TO_N(SIMD_COEF_32)
#endif
#if SIMD_PARA_MD5 > 1
#define MD5_N_STR			PARA_TO_MxN(SIMD_COEF_32, SIMD_PARA_MD5)
#else
#define MD5_N_STR			PARA_TO_N(SIMD_COEF_32)
#endif
#if SIMD_PARA_SHA1 > 1
#define SHA1_N_STR			PARA_TO_MxN(SIMD_COEF_32, SIMD_PARA_SHA1)
#else
#define SHA1_N_STR			PARA_TO_N(SIMD_COEF_32)
#endif
#if SIMD_PARA_SHA256 > 1
#define SHA256_N_STR		PARA_TO_MxN(SIMD_COEF_32, SIMD_PARA_SHA256)
#else
#define SHA256_N_STR		PARA_TO_N(SIMD_COEF_32)
#endif
#if SIMD_PARA_SHA512 > 1
#define SHA512_N_STR		PARA_TO_MxN(SIMD_COEF_64, SIMD_PARA_SHA512)
#else
#define SHA512_N_STR		PARA_TO_N(SIMD_COEF_64)
#endif

#endif /* JOHN_DISABLE_INTRINSICS */

#define SHA_BUF_SIZ			16

#ifndef JOHN_NO_SIMD
#define NT_SSE2
#endif

#endif
