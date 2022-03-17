# Compound Mode Prediction Appendix

## 1.  Description of the algorithm

The general idea behind compound prediction is to generate a weighted
average of two different predictions of the same block to develop a
final prediction. Let Prediction\_1 and Prediction\_2 denote two
different predictions of the same block. Sample p(i,j) in the compound
prediction is then generated using sample p1(i,j) from Prediction\_1,
sample p2(i,j) from Prediction\_2 and weight m(i,j) as follows:

p(i,j) = m(i,j)p1(i,j) + (1-m(i,j))p2(i,j)

Figure 1 illustrates the process of generating compound mode
predictions.

![comp_mode_pred_fig1](./img/comp_mode_pred_fig1.png)

##### Figure 1. Compound mode prediction generation.

Four different compound prediction types are supported:

  - Inter-Intra prediction: The mask (i.e. weights) are based on sample
    position relative to the block boundary.

  - Wedge prediction: The mask is based on a wedge codebook. Could be
    inter-inter or inter-intra prediction.

  - Distance-weighted compound prediction: The weights are based on the
    distance between the current frame and the reference frame.

  - Difference-weighted compound prediction: The weights are based on
    the difference between the two inter predictions.

**Compound Inter-Intra Prediction**

The compound inter-intra prediction mode is useful in blocks that
contain previously occluded areas. Inter prediction is usually preferred
for non-occluded content, whereas intra prediction is helpful in
uncovered areas. A combined inter/intra prediction helps generate
predictions for such cases that take advantage of the benefits of both
inter prediction and intra prediction. Only H\_PRED, V\_PRED, DC\_PRED,
and SMOOTH\_PRED intra modes are supported. The mask for the intra
prediction P1(i, j) applies a smoothly decaying weight in the direction
of intra prediction. The mask is inferred from a primitive 128-tap 1-D
decaying function​ ```ii_weights1d(.)```.

  - ![math](http://latex.codecogs.com/gif.latex?m_{DC}(i,j)) = 0.5,

  - ![math](http://latex.codecogs.com/gif.latex?m_{HORZ}(i,j)) = ​ii\_weights1d​(a\*j),

  - ![math](http://latex.codecogs.com/gif.latex?m_{VERT}(i,j)) = ii\_weights1d ​(a\*i),

  - ![math](http://latex.codecogs.com/gif.latex?m_{SMOOTH}(i,j))​ = ii\_weights1d​(a\*min(i, j)).

*where a = 128/size\_of\_long\_edge(block\_size) and where*
![math](http://latex.codecogs.com/gif.latex?m_{DC})*,* ![math](http://latex.codecogs.com/gif.latex?m_{HORZ})*, *![math](http://latex.codecogs.com/gif.latex?m_{VERT})* and*
![math](http://latex.codecogs.com/gif.latex?m_{SMOOTH}) *are the masks for the inter-intra smooth modes
involving the DC, horizontal, vertical and smooth intra prediction
modes, respectively. The array* ​ii\_weights1d is given below

   ii_weights1d(.):\
   60, 58, 56, 54, 52, 50, 48, 47, 45, 44, 42, 41, 39, 38,\
   37, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23,\
   22, 22, 21, 20, 19, 19, 18, 18, 17, 16, 16, 15, 15, 14,\
   14, 13, 13, 12, 12, 12, 11, 11, 10, 10, 10, 9, 9, 9, 8,\
   8, 8, 8, 7, 7, 7, 7, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4,\
   4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2,\
   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1,\
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

**Compound Wedge Prediction**

The general idea in compound wedge prediction is to generate a better
prediction of areas around edges by combining two different predictions
of the block. The feature makes use of a wedge codebook where wedge
orientations are either horizontal, vertical or oblique with slopes: 2,
-2, 0.5 and -0.5 for square and rectangular blocks, as shown in Figure 2.

![Wedge_Codebook_2020_01_11](./img/Wedge_Codebook_2020_01_11.png)

##### Figure 2. Wedge Codebook.

Using two predictions Prediction\_1 and Prediction\_2 for the block, a
final prediction p(i,j) for sample (i,j) in the block is generated by
weighting the two predictions:

p​(i, j) = m(i, j) p1​(i, j) + ( ​1 ​ - m(i, j)) p2​(i, j)

where m(i,j) is a function of the distance of the pixel to the wedge
line. The two predictors could be both inter or one inter and one intra
where intra modes are constrained to be either DC, V, H or Smooth.

**Difference-based Compound Prediction**

The difference-based compound prediction mode addresses cases where
wedge prediction is not good enough due to for example, non-straight
moving edge in a block. It considers two different predictions
Prediction\_1 and Prediction\_2 of the same block, computes the
pixel-wise differences between the two predictions, generates masks for
each of the two predictions based on the computed pixel-wise
differences, and applies the mask to the two predictions to generate the
final prediction for the block.

The mask for sample (i, j) is given by m(i,j) = b + a \* |p​1​(i, j) -
p​2​(i, j)|, where b controls the strength of the weight, a is used to
smooth the variation of the mask values around b.

The prediction is generated using p​(i, j) = m(i, j) \* p1​(i, j) + ( ​1
​ - m(i, j)) \* p​2​(i, j). Both the mask m(i,j) and (1-m(i,j)) are
evaluated and the one that provides the best RD cost is selected.

**Distance-based Compound Prediction**

In distance-based prediction mode, the weighting applied to the two
inter predictions is a function of the distance between the reference
frames and the current frame. Let d0 and d1 denote the
distances from the current frame to the forward and backward reference
pictures. The weights depend on the ratio d1/d0, and on a set of the
thresholds for the ratio. Let fwd\_offset and bck\_offset be the weights
used in the distance-based compound prediction. Then we have the
following:

  - Case where d0\>d1: The fwd\_offset and bck\_offset weights
    correspond to the largest Threshold value for which d1/d0\>Threshold
    is true.

  - Case where d0\<=d1: The fwd\_offset and bck\_offset weights
    correspond to the smallest Threshold value for which
    d1/d0\<Threshold is true.

  - When d0=0 or d1=0, if d0\<=d1 then fwd\_offset = 13 and bck\_offset
    = 3, else fwd\_offset = 3 and bck\_offset = 13

Table 1 below provides the weights as a function of d1/d0.

##### Table 1. fwd\_offset and back\_offset as a function of the ration d1/d0 for the case where d0\>0 and d1\>0.

![comp_mode_pred_table1](./img/comp_mode_pred_table1.png)

## 2.  Implementation of the algorithm

**Control tokens/flags**:

The control tokens and flags for the feature are listed in Tables 2 and 3.

##### Table 2. Control flags related to inter-intra compound mode prediction.

| **Flag** | **Level (Sequence/picture)** | **Description** |
| --- | --- | --- |
| inter_intra_compound | sequence | Config level settings for the whole sequence. 0/1: ON/OFF; -1 for Auto i.e. Default |
| enable_interintra_compound | sequence | Sequence level ON/OFF flag |
| md_inter_intra_level | sequence | Enable/disable the feature at the picture level. |
| md_inter_intra_level | block | Enable/disable the feature at the block level. |


##### Table 3. Control flags related to inter-inter compound mode prediction.

| **Flag** | **Level (Sequence/picture)** | **Description** |
| --- | --- | --- |
| compound_level | sequence | Config level settings for the whole sequence. 0/1: OFF/ON; -1 for Auto i.e. Default |
| compound_mode | sequence | Sequence level ON/OFF flag |
| inter_compound_mode | sequence | Enable/disable the feature at the picture level. |
| inter_compound_mode | block | Enable/disable the feature at the block level. |

### API

The main function calls associated with the compound mode are listed in Tables 4 and 5.

##### Table 4. API for inter-intra compound mode.

![comp_mode_pred_table4_new](./img/comp_mode_pred_table4_new.png)

##### Table 5. API for inter-inter compound mode.

![comp_mode_pred_table5_new](./img/comp_mode_pred_table5_new.png)

### Details of the implementation

The main function calls associated with compound mode prediction in mode decision are indicated in Figure 3.

![comp_mode_pred_fig5](./img/comp_mode_pred_fig5.png)

##### Figure 3. Function calls associated with compound mode prediction in mode decision.

The generation of coded blocks using the compound mode involves three main steps, namely the injection of the compound mode
candidates, the processing of those candidates in MD stages 0 to 3, and the final encoding of selected compound mode
candidates in the encode pass.

**Step 1: Injection of compound mode candidates.**

The three main functions associated with compound mode prediction at
the candidate injection stage are
```precompute_intra_pred_for_inter_intra```, ```inter_intra_search``` and
```determine_compound_mode```. The first two are related to the generation
of inter-intra compound candidates. The third is related to the
injection of inter-inter compound candidates.

1.  ```Precompute_intra_pred_for_inter_intra```

The function generates for a given block DC, Vertical, Horizontal and
Smooth intra predictions that would be used in subsequent stages in the
compound mode candidate injection process.

2.  ```Inter_intra_search```

For a given block, the generation of inter-intra wedge prediction and
the smooth inter-intra prediction is performed using the function
```inter_intra_search```. The function is invoked only for the case of
single reference inter predictions. The steps involved in the
inter-intra search are outlined below.

 - Perform inter prediction through the function call ```av1_inter_prediction```. Only luma prediction is computed.

 - Determine if wedge prediction could be used for the given block size
 using the function ```is_interintra_wedge_used```. Only 8x8, 8x16, 16x8,
 16x16, 16x32, 32x16, 32x32, 8x32 and 32x8 block sizes are allowed.

 - Enable the flag ```enable_smooth_interintra```.

 - Loop over the intra prediction modes: II\_DC\_PRED, II\_V\_PRED,
 II\_H\_PRED, II\_SMOOTH\_PRED

     - Perform smooth filtering of the inter prediction and the intra
 prediction through the function call combine\_interintra\_highbd or
 combine\_interintra based on the already computed inter predictions
 and intra predictions. The intra predictions are already generated in
 the function ```precompute_intra_pred_for_inter_intra```.

    - Compute the associated RD cost and keep track of the best RD cost
 and the corresponding intra prediction mode.

  - Perform inter-intra wedge prediction based on the best intra
 prediction mode from the smooth intra search step above using the
 function ```pick_interintra_wedge```. The details of the function are
 included below.

```pick_interintra_wedge```: Determines the best wedge option in the
inter-intra wedge prediction. Returns the wedge index and its associated
cost.

  - The search is allowed only for blocks sizes 8x8, 8x16, 16x8, 16x16,
 16x32, 32x16, 32x32, 8x32 and 32x8. (```is_interintra_wedge_used```)

  - Compute the residual for intra prediction and the difference between
 the inter prediction and the intra prediction.
 (```svt_aom_highbd_subtract_block / aom_subtract_block```)

  - Determine the best wedge option to use based on the above computed
 residuals and difference. (```pick_wedge_fixed_sign```). The details of
 the function are included below.

```pick_wedge_fixed_sign```: Determines the best wedge option for a fixed
wedge sign (0).

  - Check if ```inter_intra``` wedge is allowed, as described above.
(```is_interintra_wedge_used```)

  - Loop over the available edge prediction options

    - Determine the mask associated with the current wedge option.
(```av1_get_contiguous_soft_mask```)

    - Compute the corresponding prediction residuals based on the intra
prediction residual and the difference between the inter prediction
residuals and the intra prediction residuals.
(```av1_wedge_sse_from_residuals```)

    - Compute the R-D cost and keep track of the best option.
(```pick_wedge_fixed_sign``` and other computations.)

3.  ```Determine_compound_mode```

The main function calls starting at ```determine_compound_mode``` are outlined in Figure 4.

![comp_mode_pred_fig6](./img/comp_mode_pred_fig6.png)

##### Figure 4. Continuation of Figure 3 showing the main function calls starting with determine\_compound\_mode.

The generation of ```COMPOUND_WEDGE``` and ```COMPOUND_DIFFWTD``` predictions is performed using the function ```determine_compound_mode```,
which calls the function ```search_compound_diff_wedge```. The rest of the details are outlined in the following.

For a given block, the generation of the single reference inter
predictions is performed in the function ```av1_inter_prediction /
av1_inter_prediction_hbd```. Only luma predictions are generated.

Generate the residuals associated with the prediction from List1
reference picture, as well as the difference between the residuals
corresponding to the predictions from List0 and List1 reference
pictures, respectively.

In the function ```pick_interinter_mask```, in the case of
```COMPOUND_WEDGE```, the function ```pick_interinter_wedge``` is called. In
the case of ```COMPOUND_DIFFWTD```, the function ```pick_interinter_seg``` is
called.

```pick_interinter_wedge``` generates the prediction for the case of
inter-inter ```COMPOUND_WEDGE``` and updates the best ```COMPOUND_WEDGE```
prediction mode and corresponding cost. This is allowed only for block
sizes 8x8, 8x16, 16x8, 16x16, 16x32, 32x16, 32x32, 8x32 and 32x8. In
this function, both the nominal mask and its inverse are evaluated, and
the best mask is selected. The best mask also indicated the mask
sign.

```pick_interinter_seg``` generates the prediction for the case of
inter-inter ```COMPOUND_DIFFWTD``` and updates the best ```COMPOUND_DIFFWTD```
mask. Block size should be at least 8x8 for bipred to be allowed.

As an example, consider the flow below for the function
```inject_mvp_candidates_II```

1.  Check if compound reference mode is allowed, i.e. The candidate
    should not be a single-reference candidate and the block size
    should be at least 8x8 for bipred to be allowed.

2.  Determine the number of compound modes to try:

     - If compound is enabled for this inter type (`inter_comp_ctrls.do_nearest_nearest` is true) `tot_comp_types` equal to `inter_comp_ctrls.tot_comp_types`
       which is based on `inter_compound_mode` level
     - else `tot_comp_types` equal to `MD_COMP_DIST`

3.  Single reference case

    - Check if inter-intra is allowed: ```svt_is_interintra_allowed```

      - enable\_inter\_intra flag should be set.

      - Block size should at least 8x8 and at most
        32x32.(```is_interintra_allowed_bsize```)

      - Only NEARESTMV, NEARMV, GLOBALMV and NEWMV modes are allowed.
        (```is_interintra_allowed_mode```)

      - (rf\[0\] \> INTRA\_FRAME) && (rf\[1\] \<= INTRA\_FRAME).
        (```is_interintra_allowed_ref```);

      If inter\_intra is allowed, the total number of candidates to check is
3 (Single-reference inter mode, inter-intra wedge,
smooth\_inter-intra), else it set to 1 (only Single-reference inter
mode).

    - Loop over the NEARESTMV candidate and all the NEARMV candidates.

      - Update the candidate parameters.

      - Determine the intra prediction mode that yields the best smooth
    inter-intra prediction, and determine the best inter-intra wedge
    prediction option based on the best intra prediction mode from the
    smooth inter-intra prediction search. (```inter_intra_search```)

4.  Compound reference case

    For all ```NEARESTMV_NEARESTMV``` and ```NEAR_NEARMV``` candidates, loop over
all selected compound prediction modes

    - Update the candidate parameters

    - Determine the best wedge option for the case of ```COMPOUND_WEDGE``` or
    the best difference weighted prediction mask for the case of
    ```COMPOUND_DIFFWTD```. (```pick_interinter_mask```)

**Step 2: Generate compound mode candidates in MD stages 0, 1 and 2.**

The two main functions involved in generating compound mode candidates
in MD stages 0, 1 and 2 are warped\_motion\_prediction and
av1\_inter\_prediction.

![comp_mode_pred_fig7](./img/comp_mode_pred_fig7.png)

##### Figure 5. Continuation of Figure 3 showing the main function calls associated with compound modes in the case of warped motion prediction.

- Step 2.1: warped\_motion\_prediction
  - **plane\_warped\_motion\_prediction**: Generates the luma and chroma
    warped luma predictions. The chroma predictions are generated for
    blocks that are 16x16 or larger.
    - **av1\_dist\_wtd\_comp\_weight\_assign**: Returns forward offset
      and backward offset for the case of compound reference
      candidates and where the inter-inter compound prediction mde
      is COMPOUND\_DISTWTD. The forward offset and backward offset
      are used as weights in the generation of the final prediction.
    - **av1\_make\_masked\_warp\_inter\_predictor**: Called only in the case
      of compound reference candidate where the inter-inter compound type
      is COMPOUND\_WEDGE or COMPOUND\_DIFFWTD. Generates the predictions
      for both of those two compound types. The first step is to build the
      mask for the case of the COMPOUND\_DIFFWTD inter-inter compound type
      using the function av1\_build\_compound\_diffwtd\_mask\_d16. The
      next step is to generate the predictions using the function
      build\_masked\_compound\_no\_round as follows:
      - The function av1\_get\_compound\_type\_mask is called and
        returns the mask for either the case of COMPOUND\_DIFFWTD or
        for the case of COMPOUND\_WEDGE. The function
        av1\_get\_contiguous\_soft\_mask returns the mask for the case
        of COMPOUND\_WEDGE. For the case of COMPOUND\_DIFFWTD, the
        mask is computed in the step above.
      - The function aom\_highbd\_blend\_a64\_d16\_mask/
        aom\_lowbd\_blend\_a64\_d16\_mask is the called to perform the
        blending of the two inter predictions using the generated
        mask.
    - **svt\_av1\_warp\_plane** is invoked in the case of BIPRED where
      inter-inter compound type is COMPOUND\_DISTWTD. In this case the
      function highbd\_warp\_plane / warp\_plane is called and in turn
      calls the function eb\_av1\_highbd\_warp\_affine /
      eb\_av1\_warp\_affine. The latter applies the affine transform and
      generates the warped motion prediction using the forward offset and
      backward offset weights associated with the COMPOUND\_DISTWTD mode.
  - **chroma\_plane\_warped\_motion\_prediction\_sub8x8**: Generates chroma
    warped motion predictions for blocks that are smaller than 16x16.
    The function av1\_dist\_wtd\_comp\_weight\_assign is first called to
    generate the mask for the COMPOUND\_DISTWTD case. The appropriate
    function in the function array convolve\[\]\[\]\[\] /
    convolveHbd\[\]\[\]\[\] is then called to generate the prediction
    using the forward offset and the backward offset weights.

- Step 2.1:  **av1\_inter\_prediction**

![comp_mode_pred_fig8](./img/comp_mode_pred_fig8.png)

##### Figure 6. Continuation of Figure 3 showing the main function calls in av1_inter_prediction associated with the compound mode.

In the case where inter prediction motion mode is different from
```WARPED_CAUSAL```, then the function ```av1_inter_prediction``` is called to
generate the inter prediction. The main function calls associated with
compound mode prediction are ```av1_dist_wtd_comp_weight_assign```,
```av1_make_masked_inter_predictor``` and ```combine_interintra```, which are
described above.

**Step 3**: Generate the final compound mode predictions in the encode
pass. The two main relevant functions are ```warped_motion_prediction``` and
```av1_inter_prediction```. The two functions are described above.


## 3.  Optimization of the algorithm

**Inter-intra prediction**

The flag ```md_inter_intra_level``` is used to control when the inter-intra modes are allowed as a function of the PD pass and encoder preset.

### Optimization of inter-inter compound mode prediction

The flag ```inter_compound_mode``` is used to define different levels of complexity-quality tradeoffs for the inter-inter compound prediction mode.
The flag is set as a function of the encoder preset and controls a number of signals in the InterCompCtrls structure. The descriptions of those
signals are given in Table 6.


##### Table 6. Optimization signals related to inter-inter compound mode prediction.
| **Signal** | **Description** |
| --- | --- |
| tot_comp_types | Compound types to test; 0: OFF, 1: AVG, 2: AVG/DIST, 3: AVG/DIST/DIFF/WEDGE, 4: AVG/DIST/DIFF/WEDGE |
| do_me | if true, test all compound types for me |
| do_pme | if true, test all compound types for pme |
| do_nearest_nearest | if true, test all compound types for nearest_nearest |
| do_near_near | if true, test all compound types for near_near |
| do_nearest_near_new | if true, test all compound types for nearest_near_new |
| do_3x3_bi | if true, test all compound types for near_near |
| do_nearest_near_new | if true, test all compound types for nearest_near_new |
| do_3x3_bi | if true, test all compound types for 3x3_bipred |
| pred0_to_pred1_mult | Multiplier to the pred0_to_pred1_sad; 0: no pred0_to_pred1_sad-based pruning, >= 1: towards more inter-inter compound |
| use_rate | if true, use rate @ compound params derivation |

## Notes

The feature settings that are described in this document were compiled at v0.9.0 of the code and may not reflect the current status of the code. The description in this document represents an example showing  how features would interact with the SVT architecture. For the most up-to-date settings, it's recommended to review the section of the code implementing this feature.

## References

\[1\] Cheng Chen, Jingning Han, and Yaowu Xu, “A Hybrid Weighted Compound
Motion Compensated Prediction for Video Compression,” Picture Coding
Symposium, pp. 223-227, 2018.

\[2\] Yue Chen, Debargha Murherjee, Jingning Han, Adrian Grange, Yaowu Xu, Zoe
Liu, Sarah Parker, Cheng Chen, Hui Su, Urvang Joshi, Ching-Han Chiang,
Yunqing Wang, Paul Wilkins, Jim Bankoski, Luc Trudeau, Nathan Egge,
Jean-Marc Valin, Thomas Davies, Steinar Midtskogen, Andrey Norkin and
Peter de Rivaz, “An Overview of Core Coding Tools in the AV1 Video
Codec,” Picture Coding Symposium, pp. 41-45, 2018.

\[3\] Jingning Han, Bohan Li, Debargha Mukherjee, Ching-Han Chiang, Adrian Grange, Cheng Chen,
Hui Su, Sarah Parker, Sai Deng, Urvang Joshi, Yue Chen, Yunqing Wang, Paul Wilkins, Yaowu Xu, James  Bankoski,
“A Technical Overview of AV1,” Proceedings of the IEEE, vol. 109, no. 9, pp. 1435-1462, Sept. 2021.