/*
 * Copyright(c) 2019 Netflix, Inc.
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at https://www.aomedia.org/license/software-license. If the
 * Alliance for Open Media Patent License 1.0 was not distributed with this
 * source code in the PATENTS file, you can obtain it at
 * https://www.aomedia.org/license/patent-license.
 */

/******************************************************************************
 * @file PackUnPackTest.cc
 *
 * @brief Unit test for Pack UnPack functions:
 * - svt_c_pack_avx2_intrin
 * - svt_enc_msb_pack2d_avx2_intrin_al
 * - svt_enc_msb_pack2d_sse2_intrin
 * - svt_compressed_packmsb_avx2_intrin
 * - svt_enc_un_pack8_bit_data_avx2_intrin
 * - svt_enc_msb_un_pack2d_sse2_intrin
 * - svt_unpack_avg_avx2_intrin
 * - svt_unpack_avg_sse2_intrin
 * - svt_unpack_avg_safe_sub_avx2_intrin
 *
 * @author Cidana-Ivy, Cidana-Wenyao
 *
 ******************************************************************************/
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <new>
// workaround to eliminate the compiling warning on linux
// The macro will conflict with definition in gtest.h
#ifdef __USE_GNU
#undef __USE_GNU  // defined in EbThreads.h
#endif
#ifdef _GNU_SOURCE
#undef _GNU_SOURCE  // defined in EbThreads.h
#endif

#include "EbDefinitions.h"
#include "EbPackUnPack_C.h"
#include "EbEncIntraPrediction.h"
#include "EbUnitTestUtility.h"
#include "EbUtility.h"
#include "random.h"
#include "util.h"
#include "common_dsp_rtcd.h"
#include "aom_dsp_rtcd.h"
using svt_av1_test_tool::SVTRandom;  // to generate the random

namespace {
const int RANDOM_TIME = 8;
typedef std::tuple<uint32_t, uint32_t> AreaSize;
/*
 * TEST_PACK_SIZES: containing width of 32, 64.
 */
AreaSize TEST_PACK_SIZES[] = {AreaSize(32, 32),
                              AreaSize(32, 8),
                              AreaSize(32, 16),
                              AreaSize(64, 16),
                              AreaSize(64, 64),
                              AreaSize(64, 32),
                              AreaSize(32, 64)};

#define MAX_TEST_SIZE 2048
AreaSize TEST_PACK_SIZES_EXTEND[] = {AreaSize(128, 128),
                                     AreaSize(128, 8),
                                     AreaSize(128, 16),
                                     AreaSize(128, 62),
                                     AreaSize(128, 80),
                                     AreaSize(4, 4),
                                     AreaSize(4, 8),
                                     AreaSize(8, 4),
                                     AreaSize(8, 8),
                                     AreaSize(16, 16),
                                     AreaSize(4, 16),
                                     AreaSize(16, 4),
                                     AreaSize(16, 8),
                                     AreaSize(8, 16),
                                     AreaSize(1920, 1080),
                                     AreaSize(1280, 720),
                                     AreaSize(176, 144),
                                     AreaSize(800, 600),
                                     AreaSize(640, 480)};

// test svt_c_pack_avx2_intrin, which only support width of 32 and 64;
class PackTest : public ::testing::TestWithParam<AreaSize> {
  public:
    PackTest()
        : area_width_(std::get<0>(GetParam())),
          area_height_(std::get<1>(GetParam())) {
        in_stride_ = MAX_SB_SIZE;
        out_stride_ = MAX_SB_SIZE >> 2;
        test_size_ = MAX_SB_SQUARE;
        in_compn_bit_buffer1_ = nullptr;
        in_compn_bit_buffer2_ = nullptr;
        in_bit_buffer_ = nullptr;
        local_cache1_ = nullptr;
        local_cache2_ = nullptr;
    }

    void SetUp() override {
        in_compn_bit_buffer1_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        in_compn_bit_buffer2_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        in_bit_buffer_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        local_cache1_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        local_cache2_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        memset(in_compn_bit_buffer1_, 0, test_size_);
        memset(in_compn_bit_buffer2_, 0, test_size_);
        memset(local_cache1_, 0, test_size_);
        memset(local_cache2_, 0, test_size_);
    }

    void TearDown() override {
        if (in_bit_buffer_)
            svt_aom_free(in_bit_buffer_);
        if (in_compn_bit_buffer1_)
            svt_aom_free(in_compn_bit_buffer1_);
        if (in_compn_bit_buffer2_)
            svt_aom_free(in_compn_bit_buffer2_);
        if (local_cache1_)
            svt_aom_free(local_cache1_);
        if (local_cache2_)
            svt_aom_free(local_cache2_);
        aom_clear_system_state();
    }

  protected:
    void check_output(uint32_t width, uint32_t height, uint8_t *out_1,
                      uint8_t *out_2) {
        int fail_count = 0;
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t k = 0; k < width / 4; k++) {
                if (out_1[k + j * out_stride_] != out_2[k + j * out_stride_])
                    fail_count++;
            }
        }
        EXPECT_EQ(0, fail_count)
            << "compare result error"
            << "in test area for " << fail_count << "times";
    }

    void run_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            svt_buf_random_u8(in_bit_buffer_, test_size_);
            svt_c_pack_avx2_intrin(in_bit_buffer_,
                                   in_stride_,
                                   in_compn_bit_buffer1_,
                                   out_stride_,
                                   local_cache1_,
                                   area_width_,
                                   area_height_);
            svt_c_pack_c(in_bit_buffer_,
                         in_stride_,
                         in_compn_bit_buffer2_,
                         out_stride_,
                         local_cache2_,
                         area_width_,
                         area_height_);

            check_output(area_width_,
                         area_height_,
                         in_compn_bit_buffer1_,
                         in_compn_bit_buffer2_);

            EXPECT_FALSE(HasFailure())
                << "svt_c_pack_avx2_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    uint8_t *local_cache1_, *local_cache2_;
    uint8_t *in_bit_buffer_;
    uint32_t in_stride_, out_stride_;
    uint8_t *in_compn_bit_buffer1_, *in_compn_bit_buffer2_;
    uint32_t area_width_, area_height_;
    uint32_t test_size_;
};

TEST_P(PackTest, PackTest) {
    run_test();
};

INSTANTIATE_TEST_CASE_P(PACK, PackTest, ::testing::ValuesIn(TEST_PACK_SIZES));

// test svt_compressed_packmsb_sse4_1_intrin
// test svt_compressed_packmsb_avx2_intrin
typedef void (*svt_compressed_packmsb_fn)(
    uint8_t *in8_bit_buffer, uint32_t in8_stride, uint8_t *inn_bit_buffer,
    uint32_t inn_stride, uint16_t *out16_bit_buffer, uint32_t out_stride,
    uint32_t width, uint32_t height);

typedef std::tuple<AreaSize, svt_compressed_packmsb_fn>
    svt_compressed_packmsb_param;
class PackMsbTest
    : public ::testing::TestWithParam<svt_compressed_packmsb_param> {
  public:
    PackMsbTest()
        : area_width_(std::get<0>(TEST_GET_PARAM(0))),
          area_height_(std::get<1>(TEST_GET_PARAM(0))) {
        tst_fn = TEST_GET_PARAM(1);
        in8_stride_ = out_stride_ = MAX_TEST_SIZE;
        inn_stride_ = in8_stride_ >> 2;
        test_size_ = MAX_TEST_SIZE * MAX_TEST_SIZE;
        inn_bit_buffer_ = nullptr;
        in_8bit_buffer_ = nullptr;
        out_16bit_buffer1_ = nullptr;
        out_16bit_buffer2_ = nullptr;
    }

    void SetUp() override {
        inn_bit_buffer_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_ >> 2));
        in_8bit_buffer_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_16bit_buffer1_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        out_16bit_buffer2_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        memset(out_16bit_buffer1_, 0, sizeof(uint16_t) * test_size_);
        memset(out_16bit_buffer2_, 0, sizeof(uint16_t) * test_size_);
    }

    void TearDown() override {
        if (inn_bit_buffer_)
            svt_aom_free(inn_bit_buffer_);
        if (in_8bit_buffer_)
            svt_aom_free(in_8bit_buffer_);
        if (out_16bit_buffer1_)
            svt_aom_free(out_16bit_buffer1_);
        if (out_16bit_buffer2_)
            svt_aom_free(out_16bit_buffer2_);
        aom_clear_system_state();
    }

  protected:
    void check_output(uint32_t width, uint32_t height, uint16_t *out_1,
                      uint16_t *out_2) {
        int fail_count = 0;
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t k = 0; k < width; k++) {
                if (out_1[k + j * out_stride_] != out_2[k + j * out_stride_])
                    fail_count++;
            }
        }
        EXPECT_EQ(0, fail_count)
            << "compare result error"
            << "in test area for " << fail_count << "times";
    }

    void run_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            svt_buf_random_u8(inn_bit_buffer_, test_size_ >> 2);
            svt_buf_random_u8(in_8bit_buffer_, test_size_);
            tst_fn(in_8bit_buffer_,
                   in8_stride_,
                   inn_bit_buffer_,
                   inn_stride_,
                   out_16bit_buffer1_,
                   out_stride_,
                   area_width_,
                   area_height_);

            svt_compressed_packmsb_c(in_8bit_buffer_,
                                     in8_stride_,
                                     inn_bit_buffer_,
                                     inn_stride_,
                                     out_16bit_buffer2_,
                                     out_stride_,
                                     area_width_,
                                     area_height_);

            check_output(area_width_,
                         area_height_,
                         out_16bit_buffer1_,
                         out_16bit_buffer2_);

            EXPECT_FALSE(HasFailure())
                << "svt_compressed_packmsb_avx2_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    uint8_t *inn_bit_buffer_, *in_8bit_buffer_;
    uint32_t in8_stride_, inn_stride_, out_stride_;
    uint16_t *out_16bit_buffer1_, *out_16bit_buffer2_;
    uint32_t area_width_, area_height_;
    uint32_t test_size_;
    svt_compressed_packmsb_fn tst_fn;
};

TEST_P(PackMsbTest, PackMsbTest) {
    run_test();
};

INSTANTIATE_TEST_CASE_P(
    PACKMSB, PackMsbTest,
    ::testing::Combine(::testing::ValuesIn(TEST_PACK_SIZES),
                       ::testing::Values(svt_compressed_packmsb_sse4_1_intrin,
                                         svt_compressed_packmsb_avx2_intrin)));

INSTANTIATE_TEST_CASE_P(
    PACKMSB_EXTEND, PackMsbTest,
    ::testing::Combine(::testing::ValuesIn(TEST_PACK_SIZES_EXTEND),
                       ::testing::Values(svt_compressed_packmsb_sse4_1_intrin,
                                         svt_compressed_packmsb_avx2_intrin)));

// test svt_unpack_and_2bcompress_sse4_1
// test svt_unpack_and_2bcompress_avx2
typedef void (*svt_unpack_and_2bcompress_fn)(
    uint16_t *in16b_buffer, uint32_t in16b_stride, uint8_t *out8b_buffer,
    uint32_t out8b_stride, uint8_t *out2b_buffer, uint32_t out2b_stride,
    uint32_t width, uint32_t height);

typedef std::tuple<AreaSize, svt_unpack_and_2bcompress_fn>
    Unpack2bCompressParam;

class Unpack2bCompress
    : public ::testing::TestWithParam<Unpack2bCompressParam> {
  public:
    Unpack2bCompress()
        : area_width_(std::get<0>(TEST_GET_PARAM(0))),
          area_height_(std::get<1>(TEST_GET_PARAM(0))) {
        tst_fn = TEST_GET_PARAM(1);
        out8_stride_ = in_stride_ = MAX_TEST_SIZE;
        out2_stride_ = out8_stride_ >> 2;
        test_size_ = MAX_TEST_SIZE * MAX_TEST_SIZE;
        in_16bit_ = nullptr;
        out_2bit_buffer_ref_ = nullptr;
        out_2bit_buffer_mod_ = nullptr;
        out_8bit_buffer_ref_ = nullptr;
        out_8bit_buffer_mod_ = nullptr;
    }

    void SetUp() override {
        out_2bit_buffer_ref_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_ >> 2));
        out_2bit_buffer_mod_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_ >> 2));
        out_8bit_buffer_ref_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_8bit_buffer_mod_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        in_16bit_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));

        memset(out_2bit_buffer_ref_, 0, test_size_ >> 2);
        memset(out_2bit_buffer_mod_, 0, test_size_ >> 2);
        memset(out_8bit_buffer_ref_, 0, test_size_);
        memset(out_8bit_buffer_mod_, 0, test_size_);
    }

    void TearDown() override {
        if (out_2bit_buffer_ref_)
            svt_aom_free(out_2bit_buffer_ref_);
        if (out_2bit_buffer_mod_)
            svt_aom_free(out_2bit_buffer_mod_);
        if (out_8bit_buffer_ref_)
            svt_aom_free(out_8bit_buffer_ref_);
        if (out_8bit_buffer_mod_)
            svt_aom_free(out_8bit_buffer_mod_);
        if (in_16bit_)
            svt_aom_free(in_16bit_);
        aom_clear_system_state();
    }

  protected:
    void check_output(uint32_t width, uint32_t height, uint8_t *out_1,
                      uint8_t *out_2, uint32_t out_stride) {
        int fail_count = 0;
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t k = 0; k < width; k++) {
                if (out_1[k + j * out_stride] != out_2[k + j * out_stride])
                    fail_count++;
            }
        }
        EXPECT_EQ(0, fail_count)
            << "compare result error"
            << "in test area for " << fail_count << "times";
    }

    void run_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            svt_buf_random_u16_with_bd(in_16bit_, test_size_, 10);

            tst_fn(in_16bit_,
                   in_stride_,
                   out_8bit_buffer_mod_,
                   out8_stride_,
                   out_2bit_buffer_mod_,
                   out2_stride_,
                   area_width_,
                   area_height_);

            svt_unpack_and_2bcompress_c(in_16bit_,
                                        in_stride_,
                                        out_8bit_buffer_ref_,
                                        out8_stride_,
                                        out_2bit_buffer_ref_,
                                        out2_stride_,
                                        area_width_,
                                        area_height_);

            // 2bit output
            check_output(area_width_ >> 2,
                         area_height_,
                         out_2bit_buffer_mod_,
                         out_2bit_buffer_ref_,
                         out2_stride_);

            // 8bit output
            check_output(area_width_,
                         area_height_,
                         out_8bit_buffer_mod_,
                         out_8bit_buffer_ref_,
                         out8_stride_);

            EXPECT_FALSE(HasFailure())
                << "svt_unpack_and_2bcompress_avx2 failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    uint8_t *out_2bit_buffer_ref_, *out_2bit_buffer_mod_, *out_8bit_buffer_ref_,
        *out_8bit_buffer_mod_;
    uint32_t out8_stride_, out2_stride_, in_stride_;
    uint16_t *in_16bit_;
    uint32_t area_width_, area_height_;
    uint32_t test_size_;
    svt_unpack_and_2bcompress_fn tst_fn;
};

TEST_P(Unpack2bCompress, Unpack2bCompress) {
    run_test();
};

INSTANTIATE_TEST_CASE_P(
    UNPACK2BCOMPRESS, Unpack2bCompress,
    ::testing::Combine(::testing::ValuesIn(TEST_PACK_SIZES),
                       ::testing::Values(svt_unpack_and_2bcompress_sse4_1,
                                         svt_unpack_and_2bcompress_avx2)));

INSTANTIATE_TEST_CASE_P(
    UNPACK2BCOMPRESS_EXTEND, Unpack2bCompress,
    ::testing::Combine(::testing::ValuesIn(TEST_PACK_SIZES_EXTEND),
                       ::testing::Values(svt_unpack_and_2bcompress_sse4_1,
                                         svt_unpack_and_2bcompress_avx2)));

INSTANTIATE_TEST_CASE_P(
    UNPACK2BCOMPRESS_EXTEND2, Unpack2bCompress,
    ::testing::Combine(::testing::Values(AreaSize(32, 1), AreaSize(32, 2),
                                         AreaSize(32, 3), AreaSize(32, 5),
                                         AreaSize(64, 1), AreaSize(64, 2),
                                         AreaSize(64, 3), AreaSize(64, 5),
                                         AreaSize(65, 3), AreaSize(66, 5),
                                         AreaSize(129, 3), AreaSize(129, 5)),
                       ::testing::Values(svt_unpack_and_2bcompress_sse4_1,
                                         svt_unpack_and_2bcompress_avx2)));

// test svt_enc_msb_pack2d_avx2_intrin_al and svt_enc_msb_pack2d_sse2_intrin.
// There is an implicit assumption that the width should be multiple of 4.
// Also there are special snippet to handle width of {4, 8, 16, 32, 64}, so use
// TEST_COMMON_SIZES to cover all the width;
AreaSize TEST_COMMON_SIZES[] = {
    AreaSize(4, 4),    AreaSize(4, 8),   AreaSize(8, 4),   AreaSize(8, 8),
    AreaSize(16, 16),  AreaSize(4, 16),  AreaSize(16, 4),  AreaSize(16, 8),
    AreaSize(8, 16),   AreaSize(32, 32), AreaSize(32, 8),  AreaSize(16, 32),
    AreaSize(8, 32),   AreaSize(32, 16), AreaSize(16, 64), AreaSize(64, 16),
    AreaSize(64, 64),  AreaSize(64, 32), AreaSize(32, 64), AreaSize(128, 128),
    AreaSize(68, 64),  AreaSize(72, 64), AreaSize(80, 64), AreaSize(96, 64),
    AreaSize(64, 128), AreaSize(128, 64), AreaSize(48, 64), AreaSize(24, 64)};

class Pack2dTest : public ::testing::TestWithParam<AreaSize> {
  public:
    Pack2dTest()
        : area_width_(std::get<0>(GetParam())),
          area_height_(std::get<1>(GetParam())) {
        in_stride_ = out_stride_ = MAX_SB_SIZE;
        test_size_ = MAX_SB_SQUARE;
        in_8bit_buffer_ = nullptr;
        inn_bit_buffer_ = nullptr;
        out_16bit_buffer_avx2_ = nullptr;
        out_16bit_buffer_c_ = nullptr;
        out_16bit_buffer_sse2_ = nullptr;
    }

    void SetUp() override {
        in_8bit_buffer_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        inn_bit_buffer_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_16bit_buffer_avx2_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        out_16bit_buffer_c_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        out_16bit_buffer_sse2_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        memset(out_16bit_buffer_avx2_, 0, sizeof(uint16_t) * test_size_);
        memset(out_16bit_buffer_c_, 0, sizeof(uint16_t) * test_size_);
        memset(out_16bit_buffer_sse2_, 0, sizeof(uint16_t) * test_size_);
    }

    void TearDown() override {
        if (in_8bit_buffer_)
            svt_aom_free(in_8bit_buffer_);
        if (inn_bit_buffer_)
            svt_aom_free(inn_bit_buffer_);
        if (out_16bit_buffer_avx2_)
            svt_aom_free(out_16bit_buffer_avx2_);
        if (out_16bit_buffer_c_)
            svt_aom_free(out_16bit_buffer_c_);
        if (out_16bit_buffer_sse2_)
            svt_aom_free(out_16bit_buffer_sse2_);
        aom_clear_system_state();
    }

  protected:
    void check_output(uint32_t width, uint32_t height, uint16_t *out_1,
                      uint16_t *out_2) {
        int fail_count = 0;
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t k = 0; k < width; k++) {
                if (out_1[k + j * out_stride_] != out_2[k + j * out_stride_])
                    fail_count++;
            }
        }
        EXPECT_EQ(0, fail_count)
            << "compare result error"
            << "in test area for " << fail_count << "times";
    }

    void run_2d_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            svt_buf_random_u8(in_8bit_buffer_, test_size_);
            svt_buf_random_u8(inn_bit_buffer_, test_size_);

            svt_enc_msb_pack2d_avx2_intrin_al(in_8bit_buffer_,
                                              in_stride_,
                                              inn_bit_buffer_,
                                              out_16bit_buffer_avx2_,
                                              out_stride_,
                                              out_stride_,
                                              area_width_,
                                              area_height_);
            svt_enc_msb_pack2_d(in_8bit_buffer_,
                                in_stride_,
                                inn_bit_buffer_,
                                out_16bit_buffer_c_,
                                out_stride_,
                                out_stride_,
                                area_width_,
                                area_height_);
            svt_enc_msb_pack2d_sse2_intrin(in_8bit_buffer_,
                                           in_stride_,
                                           inn_bit_buffer_,
                                           out_16bit_buffer_sse2_,
                                           out_stride_,
                                           out_stride_,
                                           area_width_,
                                           area_height_);

            check_output(area_width_,
                         area_height_,
                         out_16bit_buffer_avx2_,
                         out_16bit_buffer_c_);
            check_output(area_width_,
                         area_height_,
                         out_16bit_buffer_sse2_,
                         out_16bit_buffer_c_);

            EXPECT_FALSE(HasFailure())
                << "svt_enc_msb_pack2d_{sse2,avx2}_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    uint8_t *in_8bit_buffer_, *inn_bit_buffer_;
    uint32_t in_stride_, out_stride_;
    uint16_t *out_16bit_buffer_avx2_, *out_16bit_buffer_c_,
        *out_16bit_buffer_sse2_;
    uint32_t area_width_, area_height_;
    uint32_t test_size_;
};

TEST_P(Pack2dTest, Pack2dTest) {
    run_2d_test();
};

INSTANTIATE_TEST_CASE_P(PACK2D, Pack2dTest,
                        ::testing::ValuesIn(TEST_COMMON_SIZES));

// test svt_enc_un_pack8_bit_data_avx2_intrin
// Similar assumption that the width is multiple of 4, using
// TEST_COMMON_SIZES to cover all the special width.
class UnPackTest : public ::testing::TestWithParam<AreaSize> {
  public:
    UnPackTest()
        : area_width_(std::get<0>(GetParam())),
          area_height_(std::get<1>(GetParam())) {
        in_stride_ = out_stride_ = MAX_SB_SIZE;
        test_size_ = MAX_SB_SQUARE;
        out_8bit_buffer1_ = nullptr;
        out_8bit_buffer2_ = nullptr;
        out_8bit_buffer3_ = nullptr;
        out_nbit_buffer1_ = nullptr;
        out_nbit_buffer2_ = nullptr;
        out_nbit_buffer3_ = nullptr;
        in_16bit_buffer_ = nullptr;
    }

    void SetUp() override {
        out_8bit_buffer1_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_8bit_buffer2_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_8bit_buffer3_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_nbit_buffer1_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_nbit_buffer2_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_nbit_buffer3_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        in_16bit_buffer_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        memset(out_8bit_buffer1_, 0, test_size_);
        memset(out_8bit_buffer2_, 0, test_size_);
        memset(out_8bit_buffer3_, 0, test_size_);
        memset(out_nbit_buffer1_, 0, test_size_);
        memset(out_nbit_buffer2_, 0, test_size_);
        memset(out_nbit_buffer3_, 0, test_size_);
    }

    void TearDown() override {
        if (in_16bit_buffer_)
            svt_aom_free(in_16bit_buffer_);
        if (out_8bit_buffer1_)
            svt_aom_free(out_8bit_buffer1_);
        if (out_8bit_buffer2_)
            svt_aom_free(out_8bit_buffer2_);
        if (out_8bit_buffer3_)
            svt_aom_free(out_8bit_buffer3_);
        if (out_nbit_buffer1_)
            svt_aom_free(out_nbit_buffer1_);
        if (out_nbit_buffer2_)
            svt_aom_free(out_nbit_buffer2_);
        if (out_nbit_buffer3_)
            svt_aom_free(out_nbit_buffer3_);
        aom_clear_system_state();
    }

  protected:
    void check_output(uint32_t width, uint32_t height, uint8_t *out_1,
                      uint8_t *out_2) {
        int fail_count = 0;
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t k = 0; k < width; k++) {
                if (out_1[k + j * out_stride_] != out_2[k + j * out_stride_])
                    fail_count++;
            }
        }
        EXPECT_EQ(0, fail_count)
            << "compare result error"
            << "in test area for " << fail_count << "times";
    }

    void run_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            svt_buf_random_u16(in_16bit_buffer_, test_size_);
            svt_enc_un_pack8_bit_data_avx2_intrin(in_16bit_buffer_,
                                                  in_stride_,
                                                  out_8bit_buffer1_,
                                                  out_stride_,
                                                  area_width_,
                                                  area_height_);
            svt_un_pack8_bit_data_c(in_16bit_buffer_,
                                    in_stride_,
                                    out_8bit_buffer2_,
                                    out_stride_,
                                    area_width_,
                                    area_height_);

            check_output(area_width_,
                         area_height_,
                         out_8bit_buffer1_,
                         out_8bit_buffer2_);

            EXPECT_FALSE(HasFailure())
                << "svt_enc_un_pack8_bit_data_avx2_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    void run_2d_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            svt_buf_random_u16(in_16bit_buffer_, test_size_);
            svt_enc_msb_un_pack2d_sse2_intrin(in_16bit_buffer_,
                                              in_stride_,
                                              out_8bit_buffer1_,
                                              out_nbit_buffer1_,
                                              out_stride_,
                                              out_stride_,
                                              area_width_,
                                              area_height_);
            svt_enc_msb_un_pack2_d(in_16bit_buffer_,
                                   in_stride_,
                                   out_8bit_buffer2_,
                                   out_nbit_buffer2_,
                                   out_stride_,
                                   out_stride_,
                                   area_width_,
                                   area_height_);
            svt_enc_msb_un_pack2d_avx2_intrin(in_16bit_buffer_,
                                              in_stride_,
                                              out_8bit_buffer3_,
                                              out_nbit_buffer3_,
                                              out_stride_,
                                              out_stride_,
                                              area_width_,
                                              area_height_);

            check_output(area_width_,
                         area_height_,
                         out_8bit_buffer1_,
                         out_8bit_buffer2_);
            check_output(area_width_,
                         area_height_,
                         out_nbit_buffer1_,
                         out_nbit_buffer2_);

            EXPECT_FALSE(HasFailure())
                << "svt_enc_msb_un_pack2d_sse2_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";

            check_output(area_width_,
                         area_height_,
                         out_8bit_buffer2_,
                         out_8bit_buffer3_);
            check_output(area_width_,
                         area_height_,
                         out_nbit_buffer2_,
                         out_nbit_buffer3_);

            EXPECT_FALSE(HasFailure())
                << "svt_enc_msb_un_pack2d_avx2_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    uint16_t *in_16bit_buffer_;
    uint32_t in_stride_, out_stride_;
    uint8_t *out_8bit_buffer1_, *out_8bit_buffer2_, *out_8bit_buffer3_,
        *out_nbit_buffer1_, *out_nbit_buffer2_, *out_nbit_buffer3_;
    uint32_t area_width_, area_height_;
    uint32_t test_size_;
};

TEST_P(UnPackTest, UnPackTest) {
    run_test();
};

TEST_P(UnPackTest, UnPack2dTest) {
    run_2d_test();
};

INSTANTIATE_TEST_CASE_P(UNPACK, UnPackTest,
                        ::testing::ValuesIn(TEST_COMMON_SIZES));

// test svt_unpack_avg_avx2_intrin
// only width of {4, 8, 16, 32, 64} are implemented in
// svt_unpack_avg_avx2_intrin. only width of {8, 16, 32, 64} are implemented in
// svt_unpack_avg_safe_sub_avx2_intrin. use TEST_AVG_SIZES to cover all the
// cases.
AreaSize TEST_AVG_SIZES[] = {AreaSize(4, 4),
                             AreaSize(4, 8),
                             AreaSize(8, 4),
                             AreaSize(8, 8),
                             AreaSize(16, 16),
                             AreaSize(4, 16),
                             AreaSize(16, 4),
                             AreaSize(16, 8),
                             AreaSize(8, 16),
                             AreaSize(32, 32),
                             AreaSize(32, 8),
                             AreaSize(16, 32),
                             AreaSize(8, 32),
                             AreaSize(32, 16),
                             AreaSize(16, 64),
                             AreaSize(64, 16),
                             AreaSize(64, 64),
                             AreaSize(64, 32),
                             AreaSize(32, 64)};

class UnPackAvgTest : public ::testing::TestWithParam<AreaSize> {
  public:
    UnPackAvgTest()
        : area_width_(std::get<0>(GetParam())),
          area_height_(std::get<1>(GetParam())) {
        in_stride_ = out_stride_ = MAX_SB_SIZE;
        test_size_ = MAX_SB_SQUARE;
        out_8bit_buffer_avx2_ = nullptr;
        out_8bit_buffer_c_ = nullptr;
        out_8bit_buffer_sse2_ = nullptr;
        in_16bit_buffer1_ = nullptr;
        in_16bit_buffer2_ = nullptr;
    }

    void SetUp() override {
        out_8bit_buffer_avx2_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_8bit_buffer_c_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        out_8bit_buffer_sse2_ =
            reinterpret_cast<uint8_t *>(svt_aom_memalign(32, test_size_));
        in_16bit_buffer1_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        in_16bit_buffer2_ = reinterpret_cast<uint16_t *>(
            svt_aom_memalign(32, sizeof(uint16_t) * test_size_));
        memset(in_16bit_buffer1_, 0, sizeof(uint16_t) * test_size_);
        memset(in_16bit_buffer2_, 0, sizeof(uint16_t) * test_size_);
        memset(out_8bit_buffer_avx2_, 0, test_size_);
        memset(out_8bit_buffer_c_, 0, test_size_);
        memset(out_8bit_buffer_sse2_, 0, test_size_);
    }

    void TearDown() override {
        if (in_16bit_buffer1_)
            svt_aom_free(in_16bit_buffer1_);
        if (in_16bit_buffer2_)
            svt_aom_free(in_16bit_buffer2_);
        if (out_8bit_buffer_avx2_)
            svt_aom_free(out_8bit_buffer_avx2_);
        if (out_8bit_buffer_c_)
            svt_aom_free(out_8bit_buffer_c_);
        if (out_8bit_buffer_sse2_)
            svt_aom_free(out_8bit_buffer_sse2_);
        aom_clear_system_state();
    }

  protected:
    void prepare_data() {
        // Limit the range to 10bit
        const int16_t mask = (1 << 10) - 1;
        SVTRandom rnd(0, mask);
        for (uint32_t i = 0; i < test_size_; i++) {
            in_16bit_buffer1_[i] = rnd.random();
            in_16bit_buffer2_[i] = rnd.random();
        }
    }

    void check_output(uint32_t width, uint32_t height, uint8_t *out_1,
                      uint8_t *out_2) {
        int fail_count = 0;
        for (uint32_t j = 0; j < height; j++) {
            for (uint32_t k = 0; k < width; k++) {
                if (out_1[k + j * out_stride_] != out_2[k + j * out_stride_])
                    fail_count++;
            }
        }
        EXPECT_EQ(0, fail_count)
            << "compare result error"
            << "in test area for " << fail_count << "times";
    }

    void run_avg_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            prepare_data();
            svt_unpack_avg_avx2_intrin(in_16bit_buffer1_,
                                       in_stride_,
                                       in_16bit_buffer2_,
                                       in_stride_,
                                       out_8bit_buffer_avx2_,
                                       out_stride_,
                                       area_width_,
                                       area_height_);
            svt_unpack_avg_c(in_16bit_buffer1_,
                             in_stride_,
                             in_16bit_buffer2_,
                             in_stride_,
                             out_8bit_buffer_c_,
                             out_stride_,
                             area_width_,
                             area_height_);
            svt_unpack_avg_sse2_intrin(in_16bit_buffer1_,
                                       in_stride_,
                                       in_16bit_buffer2_,
                                       in_stride_,
                                       out_8bit_buffer_sse2_,
                                       out_stride_,
                                       area_width_,
                                       area_height_);
            check_output(area_width_,
                         area_height_,
                         out_8bit_buffer_avx2_,
                         out_8bit_buffer_c_);
            check_output(area_width_,
                         area_height_,
                         out_8bit_buffer_sse2_,
                         out_8bit_buffer_c_);

            EXPECT_FALSE(HasFailure())
                << "svt_unpack_avg_{sse2,avx2}_intrin failed at " << i
                << "th test with size (" << area_width_ << "," << area_height_
                << ")";
        }
    }

    void run_sub_avg_test() {
        for (int i = 0; i < RANDOM_TIME; i++) {
            if (area_width_ > 4) {
                prepare_data();
                svt_unpack_avg_safe_sub_avx2_intrin(in_16bit_buffer1_,
                                                    in_stride_,
                                                    in_16bit_buffer2_,
                                                    in_stride_,
                                                    out_8bit_buffer_avx2_,
                                                    out_stride_,
                                                    false,
                                                    area_width_,
                                                    area_height_);
                svt_unpack_avg_safe_sub_c(in_16bit_buffer1_,
                                          in_stride_,
                                          in_16bit_buffer2_,
                                          in_stride_,
                                          out_8bit_buffer_c_,
                                          out_stride_,
                                          false,
                                          area_width_,
                                          area_height_);

                check_output(area_width_,
                             area_height_,
                             out_8bit_buffer_avx2_,
                             out_8bit_buffer_c_);

                EXPECT_FALSE(HasFailure())
                    << "svt_unpack_avg_safe_sub_avx2_intrin failed at " << i
                    << "th test with size (" << area_width_ << ","
                    << area_height_ << ")";
            }
        }
    }

    uint16_t *in_16bit_buffer1_, *in_16bit_buffer2_;
    uint32_t in_stride_, out_stride_;
    uint8_t *out_8bit_buffer_avx2_, *out_8bit_buffer_c_, *out_8bit_buffer_sse2_;
    uint32_t area_width_, area_height_;
    uint32_t test_size_;
};

TEST_P(UnPackAvgTest, UnPackAvgTest) {
    run_avg_test();
};

TEST_P(UnPackAvgTest, UnPackSubAvgTest) {
    run_sub_avg_test();
};

INSTANTIATE_TEST_CASE_P(UNPACKAVG, UnPackAvgTest,
                        ::testing::ValuesIn(TEST_AVG_SIZES));

}  // namespace