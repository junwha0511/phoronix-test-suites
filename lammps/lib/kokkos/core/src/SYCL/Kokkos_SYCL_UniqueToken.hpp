/*
//@HEADER
// ************************************************************************
//
//                        Kokkos v. 3.0
//       Copyright (2020) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY NTESS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NTESS OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Christian R. Trott (crtrott@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOS_SYCL_UNIQUE_TOKEN_HPP
#define KOKKOS_SYCL_UNIQUE_TOKEN_HPP

#include <impl/Kokkos_ConcurrentBitset.hpp>
#include <Kokkos_SYCL_Space.hpp>
#include <Kokkos_UniqueToken.hpp>

namespace Kokkos {
namespace Experimental {

// both global and instance Unique Tokens are implemented in the same way
template <>
class UniqueToken<SYCL, UniqueTokenScope::Global> {
 protected:
  uint32_t volatile* m_buffer;
  uint32_t m_count;

 public:
  using execution_space = SYCL;
  using size_type       = int32_t;

  explicit UniqueToken(execution_space const& = execution_space())
      : m_buffer(Impl::SYCLInternal::singleton().m_scratchConcurrentBitset),
        m_count(SYCL::concurrency()) {}

  KOKKOS_DEFAULTED_FUNCTION
  UniqueToken(const UniqueToken&) = default;

  KOKKOS_DEFAULTED_FUNCTION
  UniqueToken(UniqueToken&&) = default;

  KOKKOS_DEFAULTED_FUNCTION
  UniqueToken& operator=(const UniqueToken&) = default;

  KOKKOS_DEFAULTED_FUNCTION
  UniqueToken& operator=(UniqueToken&&) = default;

  /// \brief upper bound for acquired values, i.e. 0 <= value < size()
  KOKKOS_INLINE_FUNCTION
  size_type size() const noexcept { return m_count; }

  /// \brief acquire value such that 0 <= value < size()
  KOKKOS_INLINE_FUNCTION
  size_type acquire() const {
    const Kokkos::pair<int, int> result =
        Kokkos::Impl::concurrent_bitset::acquire_bounded(
            m_buffer, m_count
#ifdef KOKKOS_ARCH_INTEL_GPU
            ,
            Kokkos::Impl::clock_tic() % m_count
#endif
        );

    if (result.first < 0) {
      Kokkos::abort(
          "UniqueToken<SYCL> failure to acquire tokens, no tokens available");
    }

    return result.first;
  }

  /// \brief release an acquired value
  KOKKOS_INLINE_FUNCTION
  void release(size_type i) const noexcept {
    Kokkos::Impl::concurrent_bitset::release(m_buffer, i);
  }
};

template <>
class UniqueToken<SYCL, UniqueTokenScope::Instance>
    : public UniqueToken<SYCL, UniqueTokenScope::Global> {
  View<uint32_t*, SYCLDeviceUSMSpace> m_buffer_view;

 public:
  explicit UniqueToken(execution_space const& arg = execution_space())
      : UniqueToken<SYCL, UniqueTokenScope::Global>(arg) {}

  UniqueToken(size_type max_size, execution_space const& = execution_space())
      : m_buffer_view(
            "UniqueToken::m_buffer_view",
            ::Kokkos::Impl::concurrent_bitset::buffer_bound(max_size)) {
    m_buffer = m_buffer_view.data();
    m_count  = max_size;
  }
};

}  // namespace Experimental
}  // namespace Kokkos

#endif
