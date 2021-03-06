/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2014- The GROMACS Authors
 * and the project initiators Erik Lindahl, Berk Hess and David van der Spoel.
 * Consult the AUTHORS/COPYING files and https://www.gromacs.org for details.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * https://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at https://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out https://www.gromacs.org.
 */

#ifndef GMX_SIMD_IMPL_X86_AVX_512_DEFINITIONS_H
#define GMX_SIMD_IMPL_X86_AVX_512_DEFINITIONS_H

// A couple of implementation notes:
//
// - We avoid using the reduce calls provided by the intel compiler, since they
//   are not instructions but software routines, and not implemented on gcc.
// - gcc-4.9 through 5.2 do not provide int2mask and mask2int. However, since both
//   compilers are fine when we just use hexadecimal literals, we use our
//   own routines avx512Mask2Int() & avx512Int2Mask() that simply return
//   the argument. If some compiler needs a different solution in the future,
//   just write some conditional code for these routines.
// - gcc does not provide _mm512_trunc_ps(), and all alternative ops where we
//   can specify a rounding mode also appear to be buggy. We conditionally work
//   around this by using conversions to/from integer instead.

#define GMX_SIMD 1
#define GMX_SIMD_HAVE_FLOAT 1
#define GMX_SIMD_HAVE_DOUBLE 1
#define GMX_SIMD_HAVE_LOADU 1
#define GMX_SIMD_HAVE_STOREU 1
#define GMX_SIMD_HAVE_LOGICAL 1
#define GMX_SIMD_HAVE_FMA 1
#define GMX_SIMD_HAVE_FINT32_EXTRACT 0
#define GMX_SIMD_HAVE_FINT32_LOGICAL 1
#define GMX_SIMD_HAVE_FINT32_ARITHMETICS 1
// Technically it is straightforward to emulate extract on AVX-512 through
// memory operations, but when applied to 16 elements as part of a table lookup
// it will be faster to just store the entire vector once, so we avoid setting it.
#define GMX_SIMD_HAVE_DINT32_EXTRACT 0
#define GMX_SIMD_HAVE_DINT32_LOGICAL 1
#define GMX_SIMD_HAVE_DINT32_ARITHMETICS 1
#define GMX_SIMD_HAVE_NATIVE_COPYSIGN_FLOAT 1
#define GMX_SIMD_HAVE_NATIVE_RSQRT_ITER_FLOAT 0
#define GMX_SIMD_HAVE_NATIVE_RCP_ITER_FLOAT 0
#define GMX_SIMD_HAVE_NATIVE_LOG_FLOAT 0
#define GMX_SIMD_HAVE_NATIVE_EXP2_FLOAT 0
#define GMX_SIMD_HAVE_NATIVE_EXP_FLOAT 0
#define GMX_SIMD_HAVE_NATIVE_COPYSIGN_DOUBLE 1
#define GMX_SIMD_HAVE_NATIVE_RSQRT_ITER_DOUBLE 0
#define GMX_SIMD_HAVE_NATIVE_RCP_ITER_DOUBLE 0
#define GMX_SIMD_HAVE_NATIVE_LOG_DOUBLE 0
#define GMX_SIMD_HAVE_NATIVE_EXP2_DOUBLE 0
#define GMX_SIMD_HAVE_NATIVE_EXP_DOUBLE 0
#define GMX_SIMD_HAVE_GATHER_LOADU_BYSIMDINT_TRANSPOSE_FLOAT 1
#define GMX_SIMD_HAVE_GATHER_LOADU_BYSIMDINT_TRANSPOSE_DOUBLE 1
#define GMX_SIMD_HAVE_HSIMD_UTIL_FLOAT 1
#define GMX_SIMD_HAVE_HSIMD_UTIL_DOUBLE 1
#define GMX_SIMD_HAVE_4NSIMD_UTIL_FLOAT 1
#define GMX_SIMD_HAVE_4NSIMD_UTIL_DOUBLE 1

#define GMX_SIMD4_HAVE_FLOAT 1
#define GMX_SIMD4_HAVE_DOUBLE 1

// Implementation details
#define GMX_SIMD_FLOAT_WIDTH 16
#define GMX_SIMD_DOUBLE_WIDTH 8
#define GMX_SIMD_FINT32_WIDTH 16
#define GMX_SIMD_DINT32_WIDTH 8
#define GMX_SIMD4_WIDTH 4
#define GMX_SIMD_ALIGNMENT 64 // Bytes (16*single or 8*double)
#define GMX_SIMD_RSQRT_BITS 14
#define GMX_SIMD_RCP_BITS 14

#endif // GMX_SIMD_IMPL_X86_AVX_512_DEFINITIONS_H
