/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef VPX_VP9_COMMON_VP9_BLOCKD_H_
#define VPX_VP9_COMMON_VP9_BLOCKD_H_

#define INLINE __inline

#include <stdint.h>
#include <string.h>
#include "vpx_dsp_common.h"
#include "mem.h"

#include "vp9_common_data.h"
#include "vp9_entropy.h"
#include "vp9_entropymode.h"
#include "vp9_mv.h"
#include "vp9_seg_common.h"
#include "vp9_tile_common.h"
#include "vp9_filter.h"
#include "vp9_scale.h"
#include "vp9_blockd.h"
#include "yv12config.h"

#include "EbDefinitions.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_MB_PLANE 3

typedef enum {
    KEY_FRAME = 0,
    INTER_FRAME = 1,
    FRAME_TYPES,
} FRAME_TYPE;

static INLINE int is_inter_mode(PREDICTION_MODE mode) {
    return mode >= NEARESTMV && mode <= NEWMV;
}

/* For keyframes, intra block modes are predicted by the (already decoded)
   modes for the Y blocks to the left and above us; for interframes, there
   is a single probability table. */

typedef struct {
    PREDICTION_MODE as_mode;
    int_mv as_mv[2];  // first, second inter predictor motion vectors
} b_mode_info;

// Note that the rate-distortion optimization loop, bit-stream writer, and
// decoder implementation modules critically rely on the defined entry values
// specified herein. They should be refactored concurrently.

#define NONE -1
#define INTRA_FRAME 0
#define LAST_FRAME 1
#define GOLDEN_FRAME 2
#define ALTREF_FRAME 3
#define MAX_REF_FRAMES 4

typedef int8_t MV_REFERENCE_FRAME;

// This structure now relates to 8x8 block regions.
typedef struct ModeInfo {
    // Common for both INTER and INTRA blocks
    BLOCK_SIZE sb_type;
    PREDICTION_MODE mode;
    TX_SIZE tx_size;
    int8_t skip;
#if 1 //SEG_SUPPORT // Hsan: segmentation not supported
    int8_t segment_id;
#endif
#if 0 // Hsan: temporal_update not supported
    int8_t seg_id_predicted;  // valid only when temporal_update is enabled
#endif
    // Only for INTRA blocks
    PREDICTION_MODE uv_mode;
#if 0 // Hsan: switchable interp_filter not supported
    // Only for INTER blocks
    INTERP_FILTER interp_filter;
#endif
    // if ref_frame[idx] is equal to ALTREF_FRAME then
    // MACROBLOCKD::block_ref[idx] is an altref
    MV_REFERENCE_FRAME ref_frame[2];

    // TODO(slavarnway): Delete and use bmi[3].as_mv[] instead.
    int_mv mv[2];
#if 1 // Hsan: 4x4 not supported
    b_mode_info bmi[4];
#endif
} ModeInfo;

static INLINE PREDICTION_MODE get_y_mode(const ModeInfo *mi, int block) {
    return mi->sb_type < BLOCK_8X8 ? mi->bmi[block].as_mode : mi->mode;
}

static INLINE int is_inter_block(const ModeInfo *mi) {
    return mi->ref_frame[0] > INTRA_FRAME;
}

static INLINE int has_second_ref(const ModeInfo *mi) {
    return mi->ref_frame[1] > INTRA_FRAME;
}

PREDICTION_MODE eb_vp9_left_block_mode(const ModeInfo *cur_mi,
    const ModeInfo *left_mi, int b);

PREDICTION_MODE eb_vp9_above_block_mode(const ModeInfo *cur_mi,
    const ModeInfo *above_mi, int b);

enum mv_precision { MV_PRECISION_Q3, MV_PRECISION_Q4 };

struct buf_2d {
    uint8_t *buf;
    int stride;
};

struct macroblockd_plane {
    tran_low_t *dqcoeff;
    int subsampling_x;
    int subsampling_y;
    struct buf_2d dst;
    struct buf_2d pre[2];
    ENTROPY_CONTEXT *above_context;
    ENTROPY_CONTEXT *left_context;
    int16_t seg_dequant[MAX_SEGMENTS][2];

    // number of 4x4s in current block
    uint16_t n4_w, n4_h;
    // log2 of n4_w, n4_h
    uint8_t n4_wl, n4_hl;

    // encoder
    const int16_t *dequant;
};

#define BLOCK_OFFSET(x, i) ((x) + (i)*16)

typedef struct ref_buffer {
    // TODO(dkovalev): idx is not really required and should be removed, now it
    // is used in vp9_onyxd_if.c
    int idx;

    YV12_BUFFER_CONFIG *buf;

    struct scale_factors sf;

} ref_buffer;

typedef struct macroblockd {
    struct macroblockd_plane plane[MAX_MB_PLANE];
    uint8_t bmode_blocks_wl;
    uint8_t bmode_blocks_hl;

    FRAME_COUNTS *counts;
    TileInfo tile;

    int mi_stride;

    // Grid of 8x8 cells is placed over the block.
    // If some of them belong to the same mbtree-block
    // they will just have same mi[i][j] value
    ModeInfo **mi;

    ModeInfo *left_mi;
    ModeInfo *above_mi;

    unsigned int max_blocks_wide;
    unsigned int max_blocks_high;

    const vpx_prob(*partition_probs)[PARTITION_TYPES - 1];

    /* Distance of MB away from frame edges */
    int mb_to_left_edge;
    int mb_to_right_edge;
    int mb_to_top_edge;
    int mb_to_bottom_edge;

    FRAME_CONTEXT *fc;

    /* pointers to reference frames */
    ref_buffer *block_refs[2];

    /* pointer to current frame */
    const YV12_BUFFER_CONFIG *cur_buf;

    ENTROPY_CONTEXT *above_context[MAX_MB_PLANE];
    ENTROPY_CONTEXT left_context[MAX_MB_PLANE][16];

    PARTITION_CONTEXT *above_seg_context;
    PARTITION_CONTEXT left_seg_context[8];

#if CONFIG_VP9_HIGHBITDEPTH
   /* Bit depth: 8, 10, 12 */
   int bd;
#endif

    int lossless;
    int corrupted;
#if 0
    struct vpx_internal_error_info *error_info;
#endif
} MACROBLOCKD;

static INLINE PLANE_TYPE get_plane_type(int plane) {
    return (PLANE_TYPE)(plane > 0);
}

static INLINE BLOCK_SIZE get_subsize(BLOCK_SIZE bsize,
    PARTITION_TYPE partition) {
    return eb_vp9_subsize_lookup[partition][bsize];
}

extern const TX_TYPE eb_vp9_intra_mode_to_tx_type_lookup[INTRA_MODES];

static INLINE TX_TYPE get_tx_type(PLANE_TYPE plane_type,
    const MACROBLOCKD *xd) {
    const ModeInfo *const mi = xd->mi[0];

    if (plane_type != PLANE_TYPE_Y || xd->lossless || is_inter_block(mi))
        return DCT_DCT;

    return eb_vp9_intra_mode_to_tx_type_lookup[mi->mode];
}

static INLINE TX_TYPE get_tx_type_4x4(PLANE_TYPE plane_type,
    const MACROBLOCKD *xd, int ib) {
    const ModeInfo *const mi = xd->mi[0];

    if (plane_type != PLANE_TYPE_Y || xd->lossless || is_inter_block(mi))
        return DCT_DCT;

    return eb_vp9_intra_mode_to_tx_type_lookup[get_y_mode(mi, ib)];
}

void eb_vp9_setup_block_planes(MACROBLOCKD *xd, int ss_x, int ss_y);

static INLINE TX_SIZE get_uv_tx_size(const ModeInfo *mi,
    const struct macroblockd_plane *pd) {
    assert(mi->sb_type < BLOCK_8X8 ||
        eb_vp9_ss_size_lookup[mi->sb_type][pd->subsampling_x][pd->subsampling_y] !=
        BLOCK_INVALID);
    return eb_vp9_uv_txsize_lookup[mi->sb_type][mi->tx_size][pd->subsampling_x]
        [pd->subsampling_y];
}

static INLINE BLOCK_SIZE
    get_plane_block_size(BLOCK_SIZE bsize, const struct macroblockd_plane *pd) {
    return eb_vp9_ss_size_lookup[bsize][pd->subsampling_x][pd->subsampling_y];
}

static INLINE void reset_skip_context(MACROBLOCKD *xd, BLOCK_SIZE bsize) {
    int i;
    for (i = 0; i < MAX_MB_PLANE; i++) {
        struct macroblockd_plane *const pd = &xd->plane[i];
        const BLOCK_SIZE plane_bsize = get_plane_block_size(bsize, pd);
        memset(pd->above_context, 0,
            sizeof(ENTROPY_CONTEXT) * eb_vp9_num_4x4_blocks_wide_lookup[plane_bsize]);
        memset(pd->left_context, 0,
            sizeof(ENTROPY_CONTEXT) * eb_vp9_num_4x4_blocks_high_lookup[plane_bsize]);
    }
}

static INLINE const vpx_prob *get_y_mode_probs(const ModeInfo *mi,
    const ModeInfo *above_mi,
    const ModeInfo *left_mi,
    int block) {
    const PREDICTION_MODE above = eb_vp9_above_block_mode(mi, above_mi, block);
    const PREDICTION_MODE left = eb_vp9_left_block_mode(mi, left_mi, block);
    return eb_vp9_kf_y_mode_prob[above][left];
}

typedef void(*foreach_transformed_block_visitor)(MACROBLOCKD *xd, int plane, int block, int row,
    int col,
    BLOCK_SIZE plane_bsize,
    TX_SIZE tx_size, void *arg);

void eb_vp9_foreach_transformed_block_in_plane(
    MACROBLOCKD *xd, BLOCK_SIZE bsize, int plane,
    foreach_transformed_block_visitor visit, void *arg);

void eb_vp9_foreach_transformed_block(MACROBLOCKD *xd,
    BLOCK_SIZE bsize,
    foreach_transformed_block_visitor visit,
    void *arg);

void eb_vp9_set_contexts(const MACROBLOCKD *xd, struct macroblockd_plane *pd,
    BLOCK_SIZE plane_bsize, TX_SIZE tx_size, int has_eob,
    int aoff, int loff);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // VPX_VP9_COMMON_VP9_BLOCKD_H_