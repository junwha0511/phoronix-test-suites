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

#include <Kokkos_Core.hpp>

#define KOKKOS_PRAGMA_UNROLL(a)

namespace {

template <class Scalar, class ExecutionSpace>
struct SumPlain {
  using execution_space = ExecutionSpace;
  using type            = typename Kokkos::View<Scalar*, execution_space>;

  type view;

  SumPlain(type view_) : view(view_) {}

  KOKKOS_INLINE_FUNCTION
  void operator()(int /*i*/, Scalar& val) { val += Scalar(); }
};

template <class Scalar, class ExecutionSpace>
struct SumInitJoinFinalValueType {
  using execution_space = ExecutionSpace;
  using type            = typename Kokkos::View<Scalar*, execution_space>;
  using value_type      = Scalar;

  type view;

  SumInitJoinFinalValueType(type view_) : view(view_) {}

  KOKKOS_INLINE_FUNCTION
  void init(value_type& val) const { val = value_type(); }

  KOKKOS_INLINE_FUNCTION
  void join(volatile value_type& val, volatile value_type& src) const {
    val += src;
  }

  KOKKOS_INLINE_FUNCTION
  void operator()(int /*i*/, value_type& val) const { val += value_type(); }
};

template <class Scalar, class ExecutionSpace>
struct SumInitJoinFinalValueType2 {
  using execution_space = ExecutionSpace;
  using type            = typename Kokkos::View<Scalar*, execution_space>;
  using value_type      = Scalar;

  type view;

  SumInitJoinFinalValueType2(type view_) : view(view_) {}

  KOKKOS_INLINE_FUNCTION
  void init(volatile value_type& val) const { val = value_type(); }

  KOKKOS_INLINE_FUNCTION
  void join(volatile value_type& val, const volatile value_type& src) const {
    val += src;
  }

  KOKKOS_INLINE_FUNCTION
  void operator()(int /*i*/, value_type& val) const { val += value_type(); }
};

template <class Scalar, class ExecutionSpace>
struct SumInitJoinFinalValueTypeArray {
  using execution_space = ExecutionSpace;
  using type            = typename Kokkos::View<Scalar*, execution_space>;
  using value_type      = Scalar[];

  type view;
  int n;

  SumInitJoinFinalValueTypeArray(type view_, int n_) : view(view_), n(n_) {}

  KOKKOS_INLINE_FUNCTION
  void init(value_type val) const {
    for (int k = 0; k < n; k++) {
      val[k] = 0;
    }
  }

  KOKKOS_INLINE_FUNCTION
  void join(volatile value_type val, const volatile value_type src) const {
    for (int k = 0; k < n; k++) {
      val[k] += src[k];
    }
  }

  KOKKOS_INLINE_FUNCTION
  void operator()(int i, value_type val) const {
    for (int k = 0; k < n; k++) {
      val[k] += k * i;
    }
  }
};

template <class Scalar, class ExecutionSpace>
void TestTemplateMetaFunctions() {
  static_assert(
      Kokkos::Impl::ReduceFunctorHasInit<SumPlain<Scalar, ExecutionSpace>,
                                         Scalar&>::value == false,
      "");
  static_assert(
      Kokkos::Impl::ReduceFunctorHasInit<
          SumInitJoinFinalValueType<Scalar, ExecutionSpace>>::value == true,
      "");
  static_assert(
      Kokkos::Impl::ReduceFunctorHasInit<
          SumInitJoinFinalValueType2<Scalar, ExecutionSpace>>::value == true,
      "");

  static_assert(
      Kokkos::Impl::ReduceFunctorHasInit<
          SumInitJoinFinalValueTypeArray<Scalar, ExecutionSpace>>::value ==
          true,
      "");

  static_assert(Kokkos::Impl::ReduceFunctorHasJoin<
                    SumPlain<Scalar, ExecutionSpace>>::value == false,
                "");
  static_assert(
      Kokkos::Impl::ReduceFunctorHasJoin<
          SumInitJoinFinalValueType<Scalar, ExecutionSpace>>::value == true,
      "");
  static_assert(
      Kokkos::Impl::ReduceFunctorHasJoin<
          SumInitJoinFinalValueType2<Scalar, ExecutionSpace>>::value == true,
      "");
}

}  // namespace

namespace Test {
TEST(TEST_CATEGORY, template_meta_functions) {
  TestTemplateMetaFunctions<int, TEST_EXECSPACE>();
}
}  // namespace Test
