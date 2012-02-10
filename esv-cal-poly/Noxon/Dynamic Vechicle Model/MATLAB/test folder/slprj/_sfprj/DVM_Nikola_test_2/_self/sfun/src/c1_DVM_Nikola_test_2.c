/* Include files */

#include "blascompat32.h"
#include "DVM_Nikola_test_2_sfun.h"
#include "c1_DVM_Nikola_test_2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DVM_Nikola_test_2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[160] = { "g", "v_x", "v_y", "phi",
  "phi_d", "psi", "psi_d", "l_fs", "l_rs", "t_f", "t_r", "h_f", "h_r", "h_cgs",
  "h_cguf", "h_cgur", "M", "M_uf", "M_ur", "I_xxs", "I_xys", "I_xzs", "I_yys",
  "I_yzs", "I_zzs", "I_zzuf", "I_zzur", "I_tlf", "I_trf", "I_tlr", "I_trr",
  "K_spf", "K_spr", "B_f", "B_r", "K_rf", "K_rr", "K_phif", "K_phir", "K_phi",
  "B_phif", "B_phir", "B_phi", "K_sr", "L", "M_s", "l_cgs", "l_f", "l_r", "M_f",
  "M_r", "h_o", "h_s", "h_uf", "h_ur", "h_cg", "varx", "vary", "varM", "t_wid",
  "t_rad", "t_pressure", "d_steer", "delta", "ROT", "I_b", "I_c", "I_zzus",
  "I_zzo", "Fzlf", "Fzrf", "Fzlr", "Fzrr", "vx_lf", "vy_lf", "vx_rf", "vy_rf",
  "vx_lr", "vy_lr", "vx_rr", "vy_rr", "vc_lf", "vc_rf", "vc_lr", "vc_rr",
  "vl_lf", "vl_rf", "vl_lr", "vl_rr", "a_lf", "a_rf", "a_lr", "a_rr", "C_alf",
  "C_arf", "C_alr", "C_arr", "Fxtlf", "Fxtrf", "Fxtlr", "Fxtrr", "Fytlf",
  "Fytrf", "Fytlr", "Fytrr", "Fxlf", "Fxrf", "Fxlr", "Fxrr", "Fylf", "Fyrf",
  "Fylr", "Fyrr", "Mzlf", "Mzrf", "Mzlr", "Mzrr", "T_phif", "T_phir", "sigFx",
  "sigFy", "sigTxs", "sigTz", "Am", "Bm", "Cm1", "Cm2", "Dm1", "Dm2",
  "Mass_Matrix", "A1", "A2", "A3", "B1", "B2", "B3", "B4", "C1", "C2", "C3",
  "C4", "C5", "D1", "D2", "D3", "F_c", "F_u", "a_x_new", "a_y_new", "phi_dd_new",
  "psi_dd_new", "nargin", "nargout", "p", "steer", "torque", "acc_in", "pdot",
  "slp_ang", "Fout" };

/* Function Declarations */
static void initialize_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void initialize_params_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void enable_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void disable_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void set_sim_state_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void sf_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void c1_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_mpower(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_a);
static real_T c1_power(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_a, real_T c1_b);
static void c1_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void c1_eml_error(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void c1_eml_xgemm(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_A[9], real_T c1_B[9], real_T c1_C[9], real_T c1_b_C[9]);
static void c1_b_mpower(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_a[16], real_T c1_c[16]);
static void c1_matrix_to_integer_power(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, real_T c1_a[16], real_T c1_b, real_T c1_c[16]);
static void c1_c_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void c1_d_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static void c1_invNxN(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
                      real_T c1_x[16], real_T c1_y[16]);
static void c1_eps(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void c1_eml_matlab_zgetrf(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_b_A[16], int32_T c1_ipiv[4],
  int32_T *c1_info);
static int32_T c1_eml_ixamax(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[16], int32_T c1_ix0);
static int32_T c1_ceval_ixamax(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[16], int32_T c1_ix0, int32_T c1_incx);
static void c1_ceval_xswap(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[16], int32_T c1_ix0, int32_T c1_incx, int32_T c1_iy0,
  int32_T c1_incy, real_T c1_b_x[16]);
static void c1_ceval_xger(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0, int32_T c1_incx,
  int32_T c1_iy0, int32_T c1_incy, real_T c1_A[16], int32_T c1_ia0, int32_T
  c1_lda, real_T c1_b_A[16]);
static void c1_eml_blas_xtrsm(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[16],
  int32_T c1_ia0, int32_T c1_lda, real_T c1_B[16], int32_T c1_ib0, int32_T
  c1_ldb, real_T c1_b_B[16]);
static real_T c1_norm(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
                      real_T c1_x[16]);
static void c1_eml_warning(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance);
static void c1_b_eml_warning(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_varargin_3);
static void c1_e_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_h_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_i_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[94]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[94]);
static const mxArray *c1_j_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_k_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, const mxArray *c1_Fout, const char_T *c1_name, real_T c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, const mxArray *c1_pdot, const char_T *c1_name, real_T c1_y[6]);
static uint8_T c1_c_emlrt_marshallIn(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_DVM_Nikola_test_2, const
  char_T *c1_name);
static void init_dsm_address_info(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_DVM_Nikola_test_2 = 0U;
}

static void initialize_params_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
}

static void enable_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_hoistedGlobal[4];
  int32_T c1_i1;
  real_T c1_u[4];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i2;
  real_T c1_b_hoistedGlobal[6];
  int32_T c1_i3;
  real_T c1_b_u[6];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i4;
  real_T c1_c_hoistedGlobal[4];
  int32_T c1_i5;
  real_T c1_c_u[4];
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T (*c1_slp_ang)[4];
  real_T (*c1_pdot)[6];
  real_T (*c1_Fout)[4];
  c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_pdot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4));
  for (c1_i0 = 0; c1_i0 < 4; c1_i0 = c1_i0 + 1) {
    c1_hoistedGlobal[c1_i0] = (*c1_Fout)[c1_i0];
  }

  for (c1_i1 = 0; c1_i1 < 4; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i2 = 0; c1_i2 < 6; c1_i2 = c1_i2 + 1) {
    c1_b_hoistedGlobal[c1_i2] = (*c1_pdot)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 6; c1_i3 = c1_i3 + 1) {
    c1_b_u[c1_i3] = c1_b_hoistedGlobal[c1_i3];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i4 = 0; c1_i4 < 4; c1_i4 = c1_i4 + 1) {
    c1_c_hoistedGlobal[c1_i4] = (*c1_slp_ang)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 4; c1_i5 = c1_i5 + 1) {
    c1_c_u[c1_i5] = c1_c_hoistedGlobal[c1_i5];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_DVM_Nikola_test_2;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i6;
  real_T c1_dv1[6];
  int32_T c1_i7;
  real_T c1_dv2[4];
  int32_T c1_i8;
  real_T (*c1_pdot)[6];
  real_T (*c1_slp_ang)[4];
  real_T (*c1_Fout)[4];
  c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_pdot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Fout",
                      c1_dv0);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6 = c1_i6 + 1) {
    (*c1_Fout)[c1_i6] = c1_dv0[c1_i6];
  }

  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "pdot", c1_dv1);
  for (c1_i7 = 0; c1_i7 < 6; c1_i7 = c1_i7 + 1) {
    (*c1_pdot)[c1_i7] = c1_dv1[c1_i7];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                      "slp_ang", c1_dv2);
  for (c1_i8 = 0; c1_i8 < 4; c1_i8 = c1_i8 + 1) {
    (*c1_slp_ang)[c1_i8] = c1_dv2[c1_i8];
  }

  chartInstance->c1_is_active_c1_DVM_Nikola_test_2 = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
     "is_active_c1_DVM_Nikola_test_2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_DVM_Nikola_test_2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
}

static void sf_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_previousEvent;
  real_T *c1_steer;
  real_T *c1_torque;
  real_T (*c1_Fout)[4];
  real_T (*c1_slp_ang)[4];
  real_T (*c1_acc_in)[5];
  real_T (*c1_pdot)[6];
  real_T (*c1_p)[6];
  c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_acc_in = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c1_torque = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_pdot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_p = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  for (c1_i9 = 0; c1_i9 < 6; c1_i9 = c1_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_p)[c1_i9], 0U);
  }

  for (c1_i10 = 0; c1_i10 < 6; c1_i10 = c1_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_pdot)[c1_i10], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_steer, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_torque, 3U);
  for (c1_i11 = 0; c1_i11 < 5; c1_i11 = c1_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_acc_in)[c1_i11], 4U);
  }

  for (c1_i12 = 0; c1_i12 < 4; c1_i12 = c1_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_slp_ang)[c1_i12], 5U);
  }

  for (c1_i13 = 0; c1_i13 < 4; c1_i13 = c1_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_Fout)[c1_i13], 6U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_DVM_Nikola_test_2(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_DVM_Nikola_test_2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_DVM_Nikola_test_2(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
  int32_T c1_i14;
  real_T c1_hoistedGlobal[6];
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  int32_T c1_i15;
  real_T c1_d_hoistedGlobal[5];
  int32_T c1_i16;
  real_T c1_p[6];
  real_T c1_steer;
  real_T c1_torque;
  int32_T c1_i17;
  real_T c1_acc_in[5];
  uint32_T c1_debug_family_var_map[160];
  static const char *c1_sv0[160] = { "g", "v_x", "v_y", "phi", "phi_d", "psi",
    "psi_d", "l_fs", "l_rs", "t_f", "t_r", "h_f", "h_r",
    "h_cgs", "h_cguf", "h_cgur", "M", "M_uf", "M_ur", "I_xxs", "I_xys", "I_xzs",
    "I_yys", "I_yzs",
    "I_zzs", "I_zzuf", "I_zzur", "I_tlf", "I_trf", "I_tlr", "I_trr", "K_spf",
    "K_spr", "B_f", "B_r",
    "K_rf", "K_rr", "K_phif", "K_phir", "K_phi", "B_phif", "B_phir", "B_phi",
    "K_sr", "L", "M_s",
    "l_cgs", "l_f", "l_r", "M_f", "M_r", "h_o", "h_s", "h_uf", "h_ur", "h_cg",
    "varx", "vary", "varM"
    , "t_wid", "t_rad", "t_pressure", "d_steer", "delta", "ROT", "I_b", "I_c",
    "I_zzus", "I_zzo",
    "Fzlf", "Fzrf", "Fzlr", "Fzrr", "vx_lf", "vy_lf", "vx_rf", "vy_rf", "vx_lr",
    "vy_lr", "vx_rr",
    "vy_rr", "vc_lf", "vc_rf", "vc_lr", "vc_rr", "vl_lf", "vl_rf", "vl_lr",
    "vl_rr", "a_lf", "a_rf",
    "a_lr", "a_rr", "C_alf", "C_arf", "C_alr", "C_arr", "Fxtlf", "Fxtrf",
    "Fxtlr", "Fxtrr", "Fytlf",
    "Fytrf", "Fytlr", "Fytrr", "Fxlf", "Fxrf", "Fxlr", "Fxrr", "Fylf", "Fyrf",
    "Fylr", "Fyrr", "Mzlf"
    , "Mzrf", "Mzlr", "Mzrr", "T_phif", "T_phir", "sigFx", "sigFy", "sigTxs",
    "sigTz", "Am", "Bm",
    "Cm1", "Cm2", "Dm1", "Dm2", "Mass_Matrix", "A1", "A2", "A3", "B1", "B2",
    "B3", "B4", "C1", "C2",
    "C3", "C4", "C5", "D1", "D2", "D3", "F_c", "F_u", "a_x_new", "a_y_new",
    "phi_dd_new",
    "psi_dd_new", "nargin", "nargout", "p", "steer", "torque", "acc_in", "pdot",
    "slp_ang", "Fout" };

  real_T c1_g;
  real_T c1_v_x;
  real_T c1_v_y;
  real_T c1_phi;
  real_T c1_phi_d;
  real_T c1_psi;
  real_T c1_psi_d;
  real_T c1_l_fs;
  real_T c1_l_rs;
  real_T c1_t_f;
  real_T c1_t_r;
  real_T c1_h_f;
  real_T c1_h_r;
  real_T c1_h_cgs;
  real_T c1_h_cguf;
  real_T c1_h_cgur;
  real_T c1_M;
  real_T c1_M_uf;
  real_T c1_M_ur;
  real_T c1_I_xxs;
  real_T c1_I_xys;
  real_T c1_I_xzs;
  real_T c1_I_yys;
  real_T c1_I_yzs;
  real_T c1_I_zzs;
  real_T c1_I_zzuf;
  real_T c1_I_zzur;
  real_T c1_I_tlf;
  real_T c1_I_trf;
  real_T c1_I_tlr;
  real_T c1_I_trr;
  real_T c1_K_spf;
  real_T c1_K_spr;
  real_T c1_B_f;
  real_T c1_B_r;
  real_T c1_K_rf;
  real_T c1_K_rr;
  real_T c1_K_phif;
  real_T c1_K_phir;
  real_T c1_K_phi;
  real_T c1_B_phif;
  real_T c1_B_phir;
  real_T c1_B_phi;
  real_T c1_K_sr;
  real_T c1_L;
  real_T c1_M_s;
  real_T c1_l_cgs;
  real_T c1_l_f;
  real_T c1_l_r;
  real_T c1_M_f;
  real_T c1_M_r;
  real_T c1_h_o;
  real_T c1_h_s;
  real_T c1_h_uf;
  real_T c1_h_ur;
  real_T c1_h_cg;
  real_T c1_varx[8];
  real_T c1_vary[10];
  real_T c1_varM[8];
  real_T c1_t_wid;
  real_T c1_t_rad;
  real_T c1_t_pressure;
  real_T c1_d_steer;
  real_T c1_delta;
  real_T c1_ROT[9];
  real_T c1_I_b[9];
  real_T c1_I_c[9];
  real_T c1_I_zzus;
  real_T c1_I_zzo;
  real_T c1_Fzlf;
  real_T c1_Fzrf;
  real_T c1_Fzlr;
  real_T c1_Fzrr;
  real_T c1_vx_lf;
  real_T c1_vy_lf;
  real_T c1_vx_rf;
  real_T c1_vy_rf;
  real_T c1_vx_lr;
  real_T c1_vy_lr;
  real_T c1_vx_rr;
  real_T c1_vy_rr;
  real_T c1_vc_lf;
  real_T c1_vc_rf;
  real_T c1_vc_lr;
  real_T c1_vc_rr;
  real_T c1_vl_lf;
  real_T c1_vl_rf;
  real_T c1_vl_lr;
  real_T c1_vl_rr;
  real_T c1_a_lf;
  real_T c1_a_rf;
  real_T c1_a_lr;
  real_T c1_a_rr;
  real_T c1_C_alf;
  real_T c1_C_arf;
  real_T c1_C_alr;
  real_T c1_C_arr;
  real_T c1_Fxtlf;
  real_T c1_Fxtrf;
  real_T c1_Fxtlr;
  real_T c1_Fxtrr;
  real_T c1_Fytlf;
  real_T c1_Fytrf;
  real_T c1_Fytlr;
  real_T c1_Fytrr;
  real_T c1_Fxlf;
  real_T c1_Fxrf;
  real_T c1_Fxlr;
  real_T c1_Fxrr;
  real_T c1_Fylf;
  real_T c1_Fyrf;
  real_T c1_Fylr;
  real_T c1_Fyrr;
  real_T c1_Mzlf;
  real_T c1_Mzrf;
  real_T c1_Mzlr;
  real_T c1_Mzrr;
  real_T c1_T_phif;
  real_T c1_T_phir;
  real_T c1_sigFx;
  real_T c1_sigFy;
  real_T c1_sigTxs;
  real_T c1_sigTz;
  real_T c1_Am;
  real_T c1_Bm;
  real_T c1_Cm1;
  real_T c1_Cm2;
  real_T c1_Dm1;
  real_T c1_Dm2;
  real_T c1_Mass_Matrix[16];
  real_T c1_A1;
  real_T c1_A2;
  real_T c1_A3;
  real_T c1_B1;
  real_T c1_B2;
  real_T c1_B3;
  real_T c1_B4;
  real_T c1_C1;
  real_T c1_C2;
  real_T c1_C3;
  real_T c1_C4;
  real_T c1_C5;
  real_T c1_D1;
  real_T c1_D2;
  real_T c1_D3;
  real_T c1_F_c[4];
  real_T c1_F_u[4];
  real_T c1_a_x_new;
  real_T c1_a_y_new;
  real_T c1_phi_dd_new;
  real_T c1_psi_dd_new;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 3.0;
  real_T c1_pdot[6];
  real_T c1_slp_ang[4];
  real_T c1_Fout[4];
  int32_T c1_i18;
  static real_T c1_dv3[8] = { 0.0, 0.1, 0.15, 1.0, 0.0, 0.6, 0.85, 0.4 };

  int32_T c1_i19;
  static real_T c1_dv4[10] = { 0.0, 0.08, 0.15, 0.3, 1.0, 0.0, 0.4, 0.6, 0.8,
    0.4 };

  int32_T c1_i20;
  static real_T c1_dv5[8] = { 0.0, 0.1, 0.3, 1.0, 0.0, 0.0005, 0.00025, 0.0 };

  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_a;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  int32_T c1_i21;
  int32_T c1_i22;
  static real_T c1_dv6[3] = { 1.0, 0.0, 0.0 };

  int32_T c1_i23;
  static real_T c1_dv7[9] = { 744.014865523518, 0.0, 21.096972567806741, 0.0,
    2802.6101435242981, 0.0, 21.096972567806741, 0.0,
    2619.8862780007803 };

  int32_T c1_i24;
  real_T c1_b_a[9];
  int32_T c1_i25;
  real_T c1_c_a[9];
  int32_T c1_i26;
  real_T c1_dv8[9];
  int32_T c1_i27;
  real_T c1_dv9[9];
  real_T c1_b_y[9];
  int32_T c1_i28;
  real_T c1_d_a[9];
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b[9];
  int32_T c1_i33;
  real_T c1_e_a[9];
  int32_T c1_i34;
  real_T c1_b_b[9];
  int32_T c1_i35;
  real_T c1_dv10[9];
  real_T c1_dv11[9];
  int32_T c1_i36;
  real_T c1_f_a;
  real_T c1_c_y;
  real_T c1_b_A;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_d_y;
  real_T c1_g_a;
  real_T c1_e_y;
  real_T c1_h_a;
  real_T c1_f_y;
  real_T c1_c_A;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_g_y;
  real_T c1_i_a;
  real_T c1_h_y;
  real_T c1_j_a;
  real_T c1_i_y;
  real_T c1_d_A;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  real_T c1_j_y;
  real_T c1_k_a;
  real_T c1_k_y;
  real_T c1_l_a;
  real_T c1_l_y;
  real_T c1_e_A;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_m_y;
  real_T c1_m_a;
  real_T c1_n_y;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_fb_x;
  real_T c1_n_a;
  real_T c1_c_b;
  real_T c1_o_y;
  real_T c1_gb_x;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_o_a;
  real_T c1_d_b;
  real_T c1_p_y;
  real_T c1_jb_x;
  real_T c1_kb_x;
  real_T c1_lb_x;
  real_T c1_p_a;
  real_T c1_e_b;
  real_T c1_q_y;
  real_T c1_mb_x;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_q_a;
  real_T c1_f_b;
  real_T c1_r_y;
  real_T c1_pb_x;
  real_T c1_qb_x;
  real_T c1_rb_x;
  real_T c1_r_a;
  real_T c1_g_b;
  real_T c1_s_y;
  real_T c1_sb_x;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_s_a;
  real_T c1_h_b;
  real_T c1_t_y;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_xb_x;
  real_T c1_t_a;
  real_T c1_i_b;
  real_T c1_u_y;
  real_T c1_yb_x;
  real_T c1_ac_x;
  real_T c1_bc_x;
  real_T c1_u_a;
  real_T c1_j_b;
  real_T c1_w_y;
  real_T c1_f_A;
  real_T c1_B;
  real_T c1_cc_x;
  real_T c1_x_y;
  real_T c1_dc_x;
  real_T c1_y_y;
  real_T c1_ec_x;
  real_T c1_ab_y;
  real_T c1_bb_y;
  real_T c1_fc_x;
  real_T c1_gc_x;
  real_T c1_g_A;
  real_T c1_b_B;
  real_T c1_hc_x;
  real_T c1_cb_y;
  real_T c1_ic_x;
  real_T c1_db_y;
  real_T c1_jc_x;
  real_T c1_eb_y;
  real_T c1_fb_y;
  real_T c1_kc_x;
  real_T c1_lc_x;
  real_T c1_h_A;
  real_T c1_c_B;
  real_T c1_mc_x;
  real_T c1_gb_y;
  real_T c1_nc_x;
  real_T c1_hb_y;
  real_T c1_oc_x;
  real_T c1_ib_y;
  real_T c1_jb_y;
  real_T c1_pc_x;
  real_T c1_qc_x;
  real_T c1_i_A;
  real_T c1_d_B;
  real_T c1_rc_x;
  real_T c1_kb_y;
  real_T c1_sc_x;
  real_T c1_lb_y;
  real_T c1_tc_x;
  real_T c1_mb_y;
  real_T c1_nb_y;
  real_T c1_uc_x;
  real_T c1_vc_x;
  real_T c1_v_a;
  real_T c1_w_a;
  real_T c1_x_a;
  real_T c1_y_a;
  real_T c1_wc_x;
  real_T c1_xc_x;
  real_T c1_yc_x;
  real_T c1_k_b;
  real_T c1_ob_y;
  real_T c1_ad_x;
  real_T c1_bd_x;
  real_T c1_cd_x;
  real_T c1_ab_a;
  real_T c1_l_b;
  real_T c1_pb_y;
  real_T c1_dd_x;
  real_T c1_ed_x;
  real_T c1_fd_x;
  real_T c1_m_b;
  real_T c1_qb_y;
  real_T c1_gd_x;
  real_T c1_hd_x;
  real_T c1_id_x;
  real_T c1_bb_a;
  real_T c1_n_b;
  real_T c1_rb_y;
  real_T c1_jd_x;
  real_T c1_kd_x;
  real_T c1_ld_x;
  real_T c1_cb_a;
  real_T c1_o_b;
  real_T c1_sb_y;
  real_T c1_md_x;
  real_T c1_nd_x;
  real_T c1_od_x;
  real_T c1_p_b;
  real_T c1_tb_y;
  real_T c1_pd_x;
  real_T c1_qd_x;
  real_T c1_rd_x;
  real_T c1_db_a;
  real_T c1_q_b;
  real_T c1_ub_y;
  real_T c1_sd_x;
  real_T c1_td_x;
  real_T c1_ud_x;
  real_T c1_r_b;
  real_T c1_vb_y;
  real_T c1_s_b;
  real_T c1_wb_y;
  real_T c1_t_b;
  real_T c1_xb_y;
  real_T c1_u_b;
  real_T c1_yb_y;
  real_T c1_v_b;
  real_T c1_ac_y;
  real_T c1_vd_x;
  real_T c1_wd_x;
  real_T c1_xd_x;
  real_T c1_w_b;
  real_T c1_bc_y;
  real_T c1_eb_a;
  real_T c1_cc_y;
  real_T c1_fb_a;
  real_T c1_dc_y;
  real_T c1_x_b;
  real_T c1_ec_y;
  real_T c1_yd_x;
  real_T c1_ae_x;
  real_T c1_be_x;
  real_T c1_y_b;
  real_T c1_fc_y;
  real_T c1_j_A;
  real_T c1_ce_x;
  real_T c1_de_x;
  real_T c1_ee_x;
  real_T c1_gc_y;
  real_T c1_fe_x;
  real_T c1_ge_x;
  real_T c1_he_x;
  real_T c1_ab_b;
  real_T c1_hc_y;
  real_T c1_k_A;
  real_T c1_ie_x;
  real_T c1_je_x;
  real_T c1_ke_x;
  real_T c1_e_B;
  real_T c1_ic_y;
  real_T c1_jc_y;
  real_T c1_kc_y;
  real_T c1_f_B;
  real_T c1_lc_y;
  real_T c1_mc_y;
  real_T c1_nc_y;
  real_T c1_le_x;
  real_T c1_me_x;
  real_T c1_ne_x;
  real_T c1_bb_b;
  real_T c1_oc_y;
  real_T c1_oe_x;
  real_T c1_pe_x;
  real_T c1_qe_x;
  real_T c1_cb_b;
  real_T c1_pc_y;
  real_T c1_re_x;
  real_T c1_se_x;
  real_T c1_te_x;
  real_T c1_gb_a;
  real_T c1_db_b;
  real_T c1_qc_y;
  real_T c1_ue_x;
  real_T c1_ve_x;
  real_T c1_we_x;
  real_T c1_hb_a;
  real_T c1_eb_b;
  real_T c1_rc_y;
  real_T c1_g_B;
  real_T c1_sc_y;
  real_T c1_tc_y;
  real_T c1_uc_y;
  real_T c1_h_B;
  real_T c1_vc_y;
  real_T c1_wc_y;
  real_T c1_xc_y;
  real_T c1_i_B;
  real_T c1_yc_y;
  real_T c1_ad_y;
  real_T c1_bd_y;
  int32_T c1_i37;
  real_T c1_fb_b;
  real_T c1_cd_y;
  real_T c1_ib_a;
  real_T c1_gb_b;
  real_T c1_dd_y;
  real_T c1_hb_b;
  real_T c1_ed_y;
  real_T c1_ib_b;
  real_T c1_fd_y;
  real_T c1_jb_a;
  real_T c1_jb_b;
  real_T c1_gd_y;
  real_T c1_xe_x;
  real_T c1_ye_x;
  real_T c1_af_x;
  real_T c1_kb_a;
  real_T c1_kb_b;
  real_T c1_hd_y;
  real_T c1_lb_b;
  real_T c1_id_y;
  real_T c1_lb_a;
  real_T c1_mb_b;
  real_T c1_jd_y;
  real_T c1_nb_b;
  real_T c1_kd_y;
  real_T c1_ob_b;
  real_T c1_ld_y;
  real_T c1_bf_x;
  real_T c1_cf_x;
  real_T c1_df_x;
  real_T c1_mb_a;
  real_T c1_pb_b;
  real_T c1_md_y;
  real_T c1_qb_b;
  real_T c1_nd_y;
  real_T c1_ef_x;
  real_T c1_ff_x;
  real_T c1_gf_x;
  real_T c1_nb_a;
  real_T c1_rb_b;
  real_T c1_od_y;
  real_T c1_sb_b;
  real_T c1_pd_y;
  real_T c1_hf_x;
  real_T c1_if_x;
  real_T c1_jf_x;
  real_T c1_tb_b;
  real_T c1_qd_y;
  real_T c1_ob_a;
  real_T c1_ub_b;
  real_T c1_rd_y;
  real_T c1_pb_a;
  real_T c1_vb_b;
  real_T c1_sd_y;
  real_T c1_kf_x;
  real_T c1_lf_x;
  real_T c1_mf_x;
  real_T c1_wb_b;
  real_T c1_td_y;
  real_T c1_nf_x;
  real_T c1_of_x;
  real_T c1_pf_x;
  real_T c1_qb_a;
  real_T c1_xb_b;
  real_T c1_ud_y;
  real_T c1_rb_a;
  real_T c1_yb_b;
  real_T c1_vd_y;
  real_T c1_qf_x;
  real_T c1_rf_x;
  real_T c1_sf_x;
  real_T c1_ac_b;
  real_T c1_wd_y;
  real_T c1_sb_a;
  real_T c1_bc_b;
  real_T c1_xd_y;
  real_T c1_tb_a;
  real_T c1_cc_b;
  real_T c1_yd_y;
  real_T c1_tf_x;
  real_T c1_uf_x;
  real_T c1_vf_x;
  real_T c1_dc_b;
  real_T c1_ae_y;
  real_T c1_wf_x;
  real_T c1_xf_x;
  real_T c1_yf_x;
  real_T c1_ub_a;
  real_T c1_ec_b;
  real_T c1_be_y;
  real_T c1_vb_a;
  real_T c1_fc_b;
  real_T c1_ce_y;
  real_T c1_wb_a;
  real_T c1_gc_b;
  real_T c1_de_y;
  real_T c1_ag_x;
  real_T c1_bg_x;
  real_T c1_cg_x;
  real_T c1_xb_a;
  real_T c1_hc_b;
  real_T c1_ee_y;
  real_T c1_yb_a;
  real_T c1_ic_b;
  real_T c1_fe_y;
  real_T c1_dg_x;
  real_T c1_eg_x;
  real_T c1_fg_x;
  real_T c1_ac_a;
  real_T c1_jc_b;
  real_T c1_ge_y;
  real_T c1_gg_x;
  real_T c1_hg_x;
  real_T c1_ig_x;
  real_T c1_bc_a;
  real_T c1_kc_b;
  real_T c1_he_y;
  real_T c1_cc_a;
  real_T c1_lc_b;
  real_T c1_ie_y;
  real_T c1_dc_a;
  real_T c1_mc_b;
  real_T c1_je_y;
  int32_T c1_i38;
  real_T c1_b_Mass_Matrix[16];
  real_T c1_ec_a[16];
  int32_T c1_i39;
  real_T c1_nc_b[4];
  int32_T c1_i40;
  real_T c1_l_A[16];
  int32_T c1_i41;
  real_T c1_j_B[4];
  int32_T c1_i42;
  int32_T c1_i43;
  real_T c1_m_A[16];
  int32_T c1_i44;
  real_T c1_k_B[4];
  int32_T c1_i45;
  real_T c1_n_A[16];
  int32_T c1_i46;
  real_T c1_l_B[4];
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  real_T *c1_b_steer;
  real_T *c1_b_torque;
  real_T (*c1_b_pdot)[6];
  real_T (*c1_b_Fout)[4];
  real_T (*c1_b_slp_ang)[4];
  real_T (*c1_b_acc_in)[5];
  real_T (*c1_b_p)[6];
  c1_b_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_acc_in = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_torque = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_pdot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_p = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  for (c1_i14 = 0; c1_i14 < 6; c1_i14 = c1_i14 + 1) {
    c1_hoistedGlobal[c1_i14] = (*c1_b_p)[c1_i14];
  }

  c1_b_hoistedGlobal = *c1_b_steer;
  c1_c_hoistedGlobal = *c1_b_torque;
  for (c1_i15 = 0; c1_i15 < 5; c1_i15 = c1_i15 + 1) {
    c1_d_hoistedGlobal[c1_i15] = (*c1_b_acc_in)[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 6; c1_i16 = c1_i16 + 1) {
    c1_p[c1_i16] = c1_hoistedGlobal[c1_i16];
  }

  c1_steer = c1_b_hoistedGlobal;
  c1_torque = c1_c_hoistedGlobal;
  for (c1_i17 = 0; c1_i17 < 5; c1_i17 = c1_i17 + 1) {
    c1_acc_in[c1_i17] = c1_d_hoistedGlobal[c1_i17];
  }

  sf_debug_symbol_scope_push_eml(0U, 160U, 160U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_g, c1_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_v_x, c1_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_v_y, c1_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_phi, c1_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_phi_d, c1_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_psi, c1_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_psi_d, c1_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_l_fs, c1_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_l_rs, c1_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_t_f, c1_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_t_r, c1_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_h_f, c1_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_h_r, c1_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_h_cgs, c1_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_h_cguf, c1_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_h_cgur, c1_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_M, c1_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_M_uf, c1_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_M_ur, c1_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_I_xxs, c1_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c1_I_xys, c1_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c1_I_xzs, c1_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c1_I_yys, c1_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c1_I_yzs, c1_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzs, c1_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzuf, c1_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzur, c1_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c1_I_tlf, c1_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c1_I_trf, c1_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c1_I_tlr, c1_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c1_I_trr, c1_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c1_K_spf, c1_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c1_K_spr, c1_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c1_B_f, c1_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c1_B_r, c1_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c1_K_rf, c1_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c1_K_rr, c1_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c1_K_phif, c1_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c1_K_phir, c1_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c1_K_phi, c1_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c1_B_phif, c1_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c1_B_phir, c1_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c1_B_phi, c1_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c1_K_sr, c1_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c1_L, c1_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c1_M_s, c1_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c1_l_cgs, c1_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c1_l_f, c1_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c1_l_r, c1_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c1_M_f, c1_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c1_M_r, c1_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c1_h_o, c1_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c1_h_s, c1_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c1_h_uf, c1_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c1_h_ur, c1_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c1_h_cg, c1_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(c1_varx, c1_h_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(c1_vary, c1_i_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(c1_varM, c1_h_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c1_t_wid, c1_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c1_t_rad, c1_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c1_t_pressure, c1_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c1_d_steer, c1_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c1_delta, c1_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(c1_ROT, c1_g_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c1_I_b, c1_g_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(c1_I_c, c1_g_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzus, c1_d_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzo, c1_d_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c1_Fzlf, c1_d_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c1_Fzrf, c1_d_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c1_Fzlr, c1_d_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c1_Fzrr, c1_d_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(&c1_vx_lf, c1_d_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(&c1_vy_lf, c1_d_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(&c1_vx_rf, c1_d_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c1_vy_rf, c1_d_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c1_vx_lr, c1_d_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c1_vy_lr, c1_d_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c1_vx_rr, c1_d_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c1_vy_rr, c1_d_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c1_vc_lf, c1_d_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c1_vc_rf, c1_d_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c1_vc_lr, c1_d_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c1_vc_rr, c1_d_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c1_vl_lf, c1_d_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c1_vl_rf, c1_d_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c1_vl_lr, c1_d_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c1_vl_rr, c1_d_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c1_a_lf, c1_d_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c1_a_rf, c1_d_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c1_a_lr, c1_d_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c1_a_rr, c1_d_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c1_C_alf, c1_d_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c1_C_arf, c1_d_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c1_C_alr, c1_d_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c1_C_arr, c1_d_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtlf, c1_d_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtrf, c1_d_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtlr, c1_d_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtrr, c1_d_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c1_Fytlf, c1_d_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c1_Fytrf, c1_d_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(&c1_Fytlr, c1_d_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(&c1_Fytrr, c1_d_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(&c1_Fxlf, c1_d_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(&c1_Fxrf, c1_d_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(&c1_Fxlr, c1_d_sf_marshall, 107U);
  sf_debug_symbol_scope_add_eml(&c1_Fxrr, c1_d_sf_marshall, 108U);
  sf_debug_symbol_scope_add_eml(&c1_Fylf, c1_d_sf_marshall, 109U);
  sf_debug_symbol_scope_add_eml(&c1_Fyrf, c1_d_sf_marshall, 110U);
  sf_debug_symbol_scope_add_eml(&c1_Fylr, c1_d_sf_marshall, 111U);
  sf_debug_symbol_scope_add_eml(&c1_Fyrr, c1_d_sf_marshall, 112U);
  sf_debug_symbol_scope_add_eml(&c1_Mzlf, c1_d_sf_marshall, 113U);
  sf_debug_symbol_scope_add_eml(&c1_Mzrf, c1_d_sf_marshall, 114U);
  sf_debug_symbol_scope_add_eml(&c1_Mzlr, c1_d_sf_marshall, 115U);
  sf_debug_symbol_scope_add_eml(&c1_Mzrr, c1_d_sf_marshall, 116U);
  sf_debug_symbol_scope_add_eml(&c1_T_phif, c1_d_sf_marshall, 117U);
  sf_debug_symbol_scope_add_eml(&c1_T_phir, c1_d_sf_marshall, 118U);
  sf_debug_symbol_scope_add_eml(&c1_sigFx, c1_d_sf_marshall, 119U);
  sf_debug_symbol_scope_add_eml(&c1_sigFy, c1_d_sf_marshall, 120U);
  sf_debug_symbol_scope_add_eml(&c1_sigTxs, c1_d_sf_marshall, 121U);
  sf_debug_symbol_scope_add_eml(&c1_sigTz, c1_d_sf_marshall, 122U);
  sf_debug_symbol_scope_add_eml(&c1_Am, c1_d_sf_marshall, 123U);
  sf_debug_symbol_scope_add_eml(&c1_Bm, c1_d_sf_marshall, 124U);
  sf_debug_symbol_scope_add_eml(&c1_Cm1, c1_d_sf_marshall, 125U);
  sf_debug_symbol_scope_add_eml(&c1_Cm2, c1_d_sf_marshall, 126U);
  sf_debug_symbol_scope_add_eml(&c1_Dm1, c1_d_sf_marshall, 127U);
  sf_debug_symbol_scope_add_eml(&c1_Dm2, c1_d_sf_marshall, 128U);
  sf_debug_symbol_scope_add_eml(c1_Mass_Matrix, c1_f_sf_marshall, 129U);
  sf_debug_symbol_scope_add_eml(&c1_A1, c1_d_sf_marshall, 130U);
  sf_debug_symbol_scope_add_eml(&c1_A2, c1_d_sf_marshall, 131U);
  sf_debug_symbol_scope_add_eml(&c1_A3, c1_d_sf_marshall, 132U);
  sf_debug_symbol_scope_add_eml(&c1_B1, c1_d_sf_marshall, 133U);
  sf_debug_symbol_scope_add_eml(&c1_B2, c1_d_sf_marshall, 134U);
  sf_debug_symbol_scope_add_eml(&c1_B3, c1_d_sf_marshall, 135U);
  sf_debug_symbol_scope_add_eml(&c1_B4, c1_d_sf_marshall, 136U);
  sf_debug_symbol_scope_add_eml(&c1_C1, c1_d_sf_marshall, 137U);
  sf_debug_symbol_scope_add_eml(&c1_C2, c1_d_sf_marshall, 138U);
  sf_debug_symbol_scope_add_eml(&c1_C3, c1_d_sf_marshall, 139U);
  sf_debug_symbol_scope_add_eml(&c1_C4, c1_d_sf_marshall, 140U);
  sf_debug_symbol_scope_add_eml(&c1_C5, c1_d_sf_marshall, 141U);
  sf_debug_symbol_scope_add_eml(&c1_D1, c1_d_sf_marshall, 142U);
  sf_debug_symbol_scope_add_eml(&c1_D2, c1_d_sf_marshall, 143U);
  sf_debug_symbol_scope_add_eml(&c1_D3, c1_d_sf_marshall, 144U);
  sf_debug_symbol_scope_add_eml(c1_F_c, c1_e_sf_marshall, 145U);
  sf_debug_symbol_scope_add_eml(c1_F_u, c1_e_sf_marshall, 146U);
  sf_debug_symbol_scope_add_eml(&c1_a_x_new, c1_d_sf_marshall, 147U);
  sf_debug_symbol_scope_add_eml(&c1_a_y_new, c1_d_sf_marshall, 148U);
  sf_debug_symbol_scope_add_eml(&c1_phi_dd_new, c1_d_sf_marshall, 149U);
  sf_debug_symbol_scope_add_eml(&c1_psi_dd_new, c1_d_sf_marshall, 150U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_d_sf_marshall, 151U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_d_sf_marshall, 152U);
  sf_debug_symbol_scope_add_eml(c1_p, c1_b_sf_marshall, 153U);
  sf_debug_symbol_scope_add_eml(&c1_steer, c1_d_sf_marshall, 154U);
  sf_debug_symbol_scope_add_eml(&c1_torque, c1_d_sf_marshall, 155U);
  sf_debug_symbol_scope_add_eml(c1_acc_in, c1_c_sf_marshall, 156U);
  sf_debug_symbol_scope_add_eml(c1_pdot, c1_b_sf_marshall, 157U);
  sf_debug_symbol_scope_add_eml(c1_slp_ang, c1_sf_marshall, 158U);
  sf_debug_symbol_scope_add_eml(c1_Fout, c1_sf_marshall, 159U);
  CV_EML_FCN(0, 0);

  /* ==constants==% */
  _SFD_EML_CALL(0, 4);
  c1_g = 9.81;

  /* -------------% */
  /* ==current states==% */
  _SFD_EML_CALL(0, 8);
  c1_v_x = c1_p[0];
  _SFD_EML_CALL(0, 9);
  c1_v_y = c1_p[1];
  _SFD_EML_CALL(0, 10);
  c1_phi = c1_p[2];
  _SFD_EML_CALL(0, 11);
  c1_phi_d = c1_p[3];
  _SFD_EML_CALL(0, 12);
  c1_psi = c1_p[4];
  _SFD_EML_CALL(0, 13);
  c1_psi_d = c1_p[5];

  /*  a_x = acc_in(1); */
  /*  a_y = acc_in(2); */
  /*  phi_dd = acc_in(4); */
  /*  psi_dd = acc_in(5); */
  /* ------------------% */
  /* Car physical variables */
  _SFD_EML_CALL(0, 22);
  c1_l_fs = 1.01476;

  /* length from sprung mass CG to front suspension */
  _SFD_EML_CALL(0, 23);
  c1_l_rs = 1.67524;

  /* length from sprung mass CG to rear suspension */
  _SFD_EML_CALL(0, 24);
  c1_t_f = 1.54;

  /* front vehicle width */
  _SFD_EML_CALL(0, 25);
  c1_t_r = 1.53;

  /* rear vehicle width */
  _SFD_EML_CALL(0, 26);
  c1_h_f = 0.13;

  /* height from ground to front suspension */
  _SFD_EML_CALL(0, 27);
  c1_h_r = 0.11;

  /* height from ground to rear suspension */
  _SFD_EML_CALL(0, 28);
  c1_h_cgs = 0.567851;

  /* height from ground to sprung CG */
  _SFD_EML_CALL(0, 29);
  c1_h_cguf = 0.32;

  /* height from ground to front unsprung CG */
  _SFD_EML_CALL(0, 30);
  c1_h_cgur = 0.32;

  /* height from ground to rear unsprung CG */
  _SFD_EML_CALL(0, 31);
  c1_M = 1704.7;

  /* total vehicle mass */
  _SFD_EML_CALL(0, 32);
  c1_M_uf = 98.1;

  /* unsprung front mass */
  _SFD_EML_CALL(0, 33);
  c1_M_ur = 79.7;

  /* unsprung rear mass */
  _SFD_EML_CALL(0, 34);
  c1_I_xxs = 440.911;

  /* sprung XX inertia */
  _SFD_EML_CALL(0, 35);
  c1_I_xys = 0.0;

  /* sprung XY inertia */
  _SFD_EML_CALL(0, 36);
  c1_I_xzs = 7.54097;

  /* sprung XZ inertia */
  _SFD_EML_CALL(0, 37);
  c1_I_yys = 2498.9;

  /* sprung YY inertia */
  _SFD_EML_CALL(0, 38);
  c1_I_yzs = 0.0;

  /* sprung yz inertia */
  _SFD_EML_CALL(0, 39);
  c1_I_zzs = 2619.28;

  /* sprung ZZ inertia */
  _SFD_EML_CALL(0, 40);
  c1_I_zzuf = 58.163489999999996;

  /* front unsprung ZZ inertia */
  _SFD_EML_CALL(0, 41);
  c1_I_zzur = 46.6424325;

  /* rear unsprung ZZ inertia */
  _SFD_EML_CALL(0, 42);
  c1_I_tlf = 0.99;

  /* front left tire inertia */
  _SFD_EML_CALL(0, 43);
  c1_I_trf = 0.99;

  /* front right tire inertia */
  _SFD_EML_CALL(0, 44);
  c1_I_tlr = 0.99;

  /* rear left tire inertia */
  _SFD_EML_CALL(0, 45);
  c1_I_trr = 0.99;

  /* rear right tire inertia */
  /* spring/dampers */
  _SFD_EML_CALL(0, 48);
  c1_K_spf = 27.85;

  /* N/mm */
  _SFD_EML_CALL(0, 49);
  c1_K_spr = 18.16;

  /* N/mm */
  _SFD_EML_CALL(0, 51);
  c1_B_f = 2.9915;

  /* N-s/mm */
  _SFD_EML_CALL(0, 52);
  c1_B_r = 2.9915;

  /* N-s/mm */
  /* anti_roll bars */
  _SFD_EML_CALL(0, 55);
  c1_K_rf = 22001.579333023612;

  /* Nm/rad */
  _SFD_EML_CALL(0, 56);
  c1_K_rr = 19732.666464305548;

  /* roll stiffness */
  _SFD_EML_CALL(0, 59);
  c1_K_phif = 47298.369313023613;

  /*  */
  _SFD_EML_CALL(0, 60);
  c1_K_phir = 37310.859108305551;

  /*  */
  _SFD_EML_CALL(0, 61);
  c1_K_phi = c1_K_phif + c1_K_phir;

  /* roll damping */
  _SFD_EML_CALL(0, 64);
  c1_B_phif = 2717.2476562;

  /* Nm-s/rad */
  _SFD_EML_CALL(0, 65);
  c1_B_phir = 2895.6587717249995;
  _SFD_EML_CALL(0, 66);
  c1_B_phi = c1_B_phif + c1_B_phir;
  _SFD_EML_CALL(0, 68);
  c1_K_sr = 15.97;

  /* steering-to-wheel angle ratio */
  /* ==calculated parameters==% */
  _SFD_EML_CALL(0, 71);
  c1_L = 2.6900000000000004;

  /* distance from front to rear suspension */
  _SFD_EML_CALL(0, 72);
  c1_M_s = 1526.9;

  /* sprung mass */
  _SFD_EML_CALL(0, 73);
  c1_l_cgs = 0.019926480905731212;

  /* distance from vehicle CG to sprung CG */
  _SFD_EML_CALL(0, 74);
  c1_l_f = 1.0346864809057312;

  /* distance from vehicle CG to front suspension */
  _SFD_EML_CALL(0, 75);
  c1_l_r = 1.6553135190942689;

  /* distance from vehicle CG to rear suspension */
  _SFD_EML_CALL(0, 76);
  c1_M_f = 1049.0010988847582;

  /* front vehicle mass */
  _SFD_EML_CALL(0, 77);
  c1_M_r = 655.6989011152416;

  /* rear vehicle mass */
  _SFD_EML_CALL(0, 78);
  c1_h_o = 0.12230716371073806;

  /* height from ground to roll axis */
  _SFD_EML_CALL(0, 79);
  c1_h_s = 0.44554383628926192;

  /* height from roll axis to sprung CG */
  _SFD_EML_CALL(0, 80);
  c1_h_uf = c1_h_cguf - c1_h_o;

  /* height from roll axis to front suspension */
  _SFD_EML_CALL(0, 81);
  c1_h_ur = c1_h_cgur - c1_h_o;

  /* height from roll axis to rear suspension */
  _SFD_EML_CALL(0, 82);
  c1_h_cg = 0.542000171232475;

  /* height from gound to vehicle CG */
  /* ----------------------------% */
  /* ==tire properties==% */
  _SFD_EML_CALL(0, 86);
  for (c1_i18 = 0; c1_i18 < 8; c1_i18 = c1_i18 + 1) {
    c1_varx[c1_i18] = c1_dv3[c1_i18];
  }

  /* slip curve coordinates (slip-%, mu) */
  _SFD_EML_CALL(0, 91);
  for (c1_i19 = 0; c1_i19 < 10; c1_i19 = c1_i19 + 1) {
    c1_vary[c1_i19] = c1_dv4[c1_i19];
  }

  /* slip curve coordinates (slip-%, mu)  */
  _SFD_EML_CALL(0, 97);
  for (c1_i20 = 0; c1_i20 < 8; c1_i20 = c1_i20 + 1) {
    c1_varM[c1_i20] = c1_dv5[c1_i20];
  }

  /* slip angle (slip-angle, Moment-arm) */
  /* tire properties */
  _SFD_EML_CALL(0, 105);
  c1_t_wid = 0.175;
  _SFD_EML_CALL(0, 106);
  c1_t_rad = 0.292;
  _SFD_EML_CALL(0, 107);
  c1_t_pressure = 275000.0;

  /* ---------------------% */
  /* ==steering inputs==% */
  _SFD_EML_CALL(0, 112);
  c1_d_steer = c1_steer;
  _SFD_EML_CALL(0, 113);
  c1_A = c1_d_steer;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = c1_c_x / 2874.6;
  c1_a = c1_y;
  c1_delta = c1_a * 3.1415926535897931;

  /* radians */
  /* -------------------% */
  /* ==calculate internal accelerations==% */
  /*  a_sx = a_x ... */
  /*       - psi_d*v_y ... */
  /*       - 2*h_s*phi_d*psi_d*cos(phi) ... */
  /*       - l_cgs*psi_d^2; */
  /*  a_sy = psi_d*v_x ... */
  /*       + l_cgs*psi_dd ... */
  /*       + h_s*cos(phi)*phi_dd ... */
  /*       - h_s*phi_d^2*sin(phi) ... */
  /*       - h_s*psi_d^2*sin(phi); */
  /*  a_ufx = a_x - l_f*psi_d^2; */
  /*  a_ufy = a_y + l_f*psi_dd; */
  /*  a_urx = a_x + l_r*psi_d^2; */
  /*  a_ury = a_y - l_r*psi_dd; */
  /* -------------------------------------% */
  /* ==rotation Matrix==% */
  _SFD_EML_CALL(0, 133);
  c1_d_x = c1_phi;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_e_x = c1_f_x;
  c1_e_x = muDoubleScalarCos(c1_e_x);
  c1_g_x = c1_phi;
  c1_h_x = c1_g_x;
  c1_i_x = c1_h_x;
  c1_h_x = c1_i_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_j_x = c1_phi;
  c1_k_x = c1_j_x;
  c1_l_x = c1_k_x;
  c1_k_x = c1_l_x;
  c1_k_x = muDoubleScalarSin(c1_k_x);
  c1_m_x = c1_phi;
  c1_n_x = c1_m_x;
  c1_o_x = c1_n_x;
  c1_n_x = c1_o_x;
  c1_n_x = muDoubleScalarCos(c1_n_x);
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 3; c1_i22 = c1_i22 + 1) {
    c1_ROT[c1_i21] = c1_dv6[c1_i22];
    c1_i21 = c1_i21 + 3;
  }

  c1_ROT[1] = 0.0;
  c1_ROT[4] = c1_e_x;
  c1_ROT[7] = c1_h_x;
  c1_ROT[2] = 0.0;
  c1_ROT[5] = -c1_k_x;
  c1_ROT[8] = c1_n_x;
  _SFD_EML_CALL(0, 137);
  for (c1_i23 = 0; c1_i23 < 9; c1_i23 = c1_i23 + 1) {
    c1_I_b[c1_i23] = c1_dv7[c1_i23];
  }

  _SFD_EML_CALL(0, 141);
  for (c1_i24 = 0; c1_i24 < 9; c1_i24 = c1_i24 + 1) {
    c1_b_a[c1_i24] = c1_ROT[c1_i24];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i25 = 0; c1_i25 < 9; c1_i25 = c1_i25 + 1) {
    c1_c_a[c1_i25] = c1_b_a[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 9; c1_i26 = c1_i26 + 1) {
    c1_dv8[c1_i26] = c1_dv7[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 9; c1_i27 = c1_i27 + 1) {
    c1_dv9[c1_i27] = 0.0;
  }

  c1_eml_xgemm(chartInstance, c1_c_a, c1_dv8, c1_dv9, c1_b_y);
  for (c1_i28 = 0; c1_i28 < 9; c1_i28 = c1_i28 + 1) {
    c1_d_a[c1_i28] = c1_b_y[c1_i28];
  }

  c1_i29 = 0;
  for (c1_i30 = 0; c1_i30 < 3; c1_i30 = c1_i30 + 1) {
    c1_i31 = 0;
    for (c1_i32 = 0; c1_i32 < 3; c1_i32 = c1_i32 + 1) {
      c1_b[c1_i32 + c1_i29] = c1_ROT[c1_i31 + c1_i30];
      c1_i31 = c1_i31 + 3;
    }

    c1_i29 = c1_i29 + 3;
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i33 = 0; c1_i33 < 9; c1_i33 = c1_i33 + 1) {
    c1_e_a[c1_i33] = c1_d_a[c1_i33];
  }

  for (c1_i34 = 0; c1_i34 < 9; c1_i34 = c1_i34 + 1) {
    c1_b_b[c1_i34] = c1_b[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 9; c1_i35 = c1_i35 + 1) {
    c1_dv10[c1_i35] = 0.0;
  }

  c1_eml_xgemm(chartInstance, c1_e_a, c1_b_b, c1_dv10, c1_dv11);
  for (c1_i36 = 0; c1_i36 < 9; c1_i36 = c1_i36 + 1) {
    c1_I_c[c1_i36] = c1_dv11[c1_i36];
  }

  /* chassis M.o.I. tensor */
  _SFD_EML_CALL(0, 143);
  c1_I_zzus = (323.40652562649871 + c1_I_zzuf) + c1_I_zzur;
  _SFD_EML_CALL(0, 147);
  c1_I_zzo = c1_I_c[8] + c1_I_zzus;

  /* effective I_zz */
  /* ---------------------------------------------% */
  /*  %==Dynamic Weight Transfer Forces==% */
  /*  Fzax = (M_s*h_s*a_sx + M_uf*h_uf*a_ufx + M_ur*h_ur*a_urx)/(2*L); */
  /*   */
  /*  Fzayf = 1/t_f*(M_s*l_r*h_f/L*a_sy + M_uf*h_uf*a_ufy); */
  /*  Fzayr = 1/t_r*(M_s*l_f*h_r/L*a_sy + M_ur*h_ur*a_ury); */
  /*   */
  /*  Fzphif = -1/t_f*(K_phif*phi + B_phif*phi_d); */
  /*  Fzphir = -1/t_r*(K_phir*phi + B_phir*phi_d); */
  /*  %----------------------------------% */
  /* ==Tire Normal Forces==%  */
  /*  Fzlf = M*g*l_r/(2*L) - Fzax - Fzayf + Fzphif; */
  /*  Fzrf = M*g*l_r/(2*L) - Fzax + Fzayf - Fzphif; */
  /*  Fzlr = M*g*l_f/(2*L) + Fzax - Fzayr + Fzphir; */
  /*  Fzrr = M*g*l_f/(2*L) + Fzax + Fzayr - Fzphir; */
  _SFD_EML_CALL(0, 166);
  c1_Fzlf = 5145.3503900297392;
  _SFD_EML_CALL(0, 167);
  c1_Fzrf = 5145.3503900297392;
  _SFD_EML_CALL(0, 168);
  c1_Fzlr = 3216.2031099702594;
  _SFD_EML_CALL(0, 169);
  c1_Fzrr = 3216.2031099702594;

  /* ----------------------% */
  /* ==Tire Longitudinal/Lateral Forces==% */
  /* left front wheel velocity */
  _SFD_EML_CALL(0, 174);
  c1_f_a = c1_psi_d;
  c1_c_y = c1_f_a * 1.54;
  c1_b_A = c1_c_y;
  c1_p_x = c1_b_A;
  c1_q_x = c1_p_x;
  c1_r_x = c1_q_x;
  c1_d_y = c1_r_x / 2.0;
  c1_vx_lf = c1_v_x + c1_d_y;
  _SFD_EML_CALL(0, 175);
  c1_g_a = c1_psi_d;
  c1_e_y = c1_g_a * 1.0346864809057312;
  c1_vy_lf = c1_v_y + c1_e_y;

  /* right front wheel velocity */
  _SFD_EML_CALL(0, 178);
  c1_h_a = c1_psi_d;
  c1_f_y = c1_h_a * 1.54;
  c1_c_A = c1_f_y;
  c1_s_x = c1_c_A;
  c1_t_x = c1_s_x;
  c1_u_x = c1_t_x;
  c1_g_y = c1_u_x / 2.0;
  c1_vx_rf = c1_v_x - c1_g_y;
  _SFD_EML_CALL(0, 179);
  c1_i_a = c1_psi_d;
  c1_h_y = c1_i_a * 1.0346864809057312;
  c1_vy_rf = c1_v_y + c1_h_y;

  /* left rear wheel velocity */
  _SFD_EML_CALL(0, 182);
  c1_j_a = c1_psi_d;
  c1_i_y = c1_j_a * 1.53;
  c1_d_A = c1_i_y;
  c1_w_x = c1_d_A;
  c1_x_x = c1_w_x;
  c1_y_x = c1_x_x;
  c1_j_y = c1_y_x / 2.0;
  c1_vx_lr = c1_v_x + c1_j_y;
  _SFD_EML_CALL(0, 183);
  c1_k_a = c1_psi_d;
  c1_k_y = c1_k_a * 1.6553135190942689;
  c1_vy_lr = c1_v_y - c1_k_y;

  /* right rear wheel velocity */
  _SFD_EML_CALL(0, 186);
  c1_l_a = c1_psi_d;
  c1_l_y = c1_l_a * 1.53;
  c1_e_A = c1_l_y;
  c1_ab_x = c1_e_A;
  c1_bb_x = c1_ab_x;
  c1_cb_x = c1_bb_x;
  c1_m_y = c1_cb_x / 2.0;
  c1_vx_rr = c1_v_x - c1_m_y;
  _SFD_EML_CALL(0, 187);
  c1_m_a = c1_psi_d;
  c1_n_y = c1_m_a * 1.6553135190942689;
  c1_vy_rr = c1_v_y - c1_n_y;

  /*  %---------------------------------------% */
  /*  %SLIP ANGLES HIRTLE */
  /*  %---------------------------------------% */
  /*  beta_lf = atan(vy_lf/vx_lf); */
  /*  beta_rf = atan(vy_rf/vx_rf); */
  /*  beta_lr = atan(vy_lr/vx_lr); */
  /*  beta_rr = atan(vy_rr/vx_rr); */
  /*    */
  /*  a_lf = beta_lf - delta; */
  /*  a_rf = beta_rf - delta; */
  /*  a_lr = beta_lr; */
  /*  a_rr = beta_rr; */
  /*    */
  /*  slp_ang = [a_lf,a_rf,a_lr,a_rr]; */
  /*  %---------------------------------------% */
  /*  %END SLIP ANGLES HIRTLE */
  /*  %---------------------------------------% */
  /* ---------------------------------------% */
  /* SLIP ANGLES NIKOLA */
  /* ---------------------------------------% */
  /*  Tire longitudinal and cornering velocities */
  _SFD_EML_CALL(0, 211);
  c1_db_x = c1_delta;
  c1_eb_x = c1_db_x;
  c1_fb_x = c1_eb_x;
  c1_eb_x = c1_fb_x;
  c1_eb_x = muDoubleScalarCos(c1_eb_x);
  c1_n_a = c1_vy_lf;
  c1_c_b = c1_eb_x;
  c1_o_y = c1_n_a * c1_c_b;
  c1_gb_x = c1_delta;
  c1_hb_x = c1_gb_x;
  c1_ib_x = c1_hb_x;
  c1_hb_x = c1_ib_x;
  c1_hb_x = muDoubleScalarSin(c1_hb_x);
  c1_o_a = c1_vx_lf;
  c1_d_b = c1_hb_x;
  c1_p_y = c1_o_a * c1_d_b;
  c1_vc_lf = c1_o_y - c1_p_y;
  _SFD_EML_CALL(0, 212);
  c1_jb_x = c1_delta;
  c1_kb_x = c1_jb_x;
  c1_lb_x = c1_kb_x;
  c1_kb_x = c1_lb_x;
  c1_kb_x = muDoubleScalarCos(c1_kb_x);
  c1_p_a = c1_vy_rf;
  c1_e_b = c1_kb_x;
  c1_q_y = c1_p_a * c1_e_b;
  c1_mb_x = c1_delta;
  c1_nb_x = c1_mb_x;
  c1_ob_x = c1_nb_x;
  c1_nb_x = c1_ob_x;
  c1_nb_x = muDoubleScalarSin(c1_nb_x);
  c1_q_a = c1_vx_rf;
  c1_f_b = c1_nb_x;
  c1_r_y = c1_q_a * c1_f_b;
  c1_vc_rf = c1_q_y - c1_r_y;
  _SFD_EML_CALL(0, 213);
  c1_vc_lr = c1_vy_lr;
  _SFD_EML_CALL(0, 214);
  c1_vc_rr = c1_vy_rr;
  _SFD_EML_CALL(0, 216);
  c1_pb_x = c1_delta;
  c1_qb_x = c1_pb_x;
  c1_rb_x = c1_qb_x;
  c1_qb_x = c1_rb_x;
  c1_qb_x = muDoubleScalarSin(c1_qb_x);
  c1_r_a = c1_vy_lf;
  c1_g_b = c1_qb_x;
  c1_s_y = c1_r_a * c1_g_b;
  c1_sb_x = c1_delta;
  c1_tb_x = c1_sb_x;
  c1_ub_x = c1_tb_x;
  c1_tb_x = c1_ub_x;
  c1_tb_x = muDoubleScalarCos(c1_tb_x);
  c1_s_a = c1_vx_lf;
  c1_h_b = c1_tb_x;
  c1_t_y = c1_s_a * c1_h_b;
  c1_vl_lf = c1_s_y + c1_t_y;
  _SFD_EML_CALL(0, 217);
  c1_vb_x = c1_delta;
  c1_wb_x = c1_vb_x;
  c1_xb_x = c1_wb_x;
  c1_wb_x = c1_xb_x;
  c1_wb_x = muDoubleScalarSin(c1_wb_x);
  c1_t_a = c1_vy_rf;
  c1_i_b = c1_wb_x;
  c1_u_y = c1_t_a * c1_i_b;
  c1_yb_x = c1_delta;
  c1_ac_x = c1_yb_x;
  c1_bc_x = c1_ac_x;
  c1_ac_x = c1_bc_x;
  c1_ac_x = muDoubleScalarCos(c1_ac_x);
  c1_u_a = c1_vx_rf;
  c1_j_b = c1_ac_x;
  c1_w_y = c1_u_a * c1_j_b;
  c1_vl_rf = c1_u_y + c1_w_y;
  _SFD_EML_CALL(0, 218);
  c1_vl_lr = c1_vx_lr;
  _SFD_EML_CALL(0, 219);
  c1_vl_rr = c1_vx_rr;

  /*  Slip angles */
  _SFD_EML_CALL(0, 222);
  c1_f_A = c1_vc_lf;
  c1_B = c1_vl_lf;
  c1_cc_x = c1_f_A;
  c1_x_y = c1_B;
  c1_dc_x = c1_cc_x;
  c1_y_y = c1_x_y;
  c1_ec_x = c1_dc_x;
  c1_ab_y = c1_y_y;
  c1_bb_y = c1_ec_x / c1_ab_y;
  c1_fc_x = c1_bb_y;
  c1_a_lf = c1_fc_x;
  c1_gc_x = c1_a_lf;
  c1_a_lf = c1_gc_x;
  c1_a_lf = muDoubleScalarAtan(c1_a_lf);
  _SFD_EML_CALL(0, 223);
  c1_g_A = c1_vc_rf;
  c1_b_B = c1_vl_rf;
  c1_hc_x = c1_g_A;
  c1_cb_y = c1_b_B;
  c1_ic_x = c1_hc_x;
  c1_db_y = c1_cb_y;
  c1_jc_x = c1_ic_x;
  c1_eb_y = c1_db_y;
  c1_fb_y = c1_jc_x / c1_eb_y;
  c1_kc_x = c1_fb_y;
  c1_a_rf = c1_kc_x;
  c1_lc_x = c1_a_rf;
  c1_a_rf = c1_lc_x;
  c1_a_rf = muDoubleScalarAtan(c1_a_rf);
  _SFD_EML_CALL(0, 224);
  c1_h_A = c1_vc_lr;
  c1_c_B = c1_vl_lr;
  c1_mc_x = c1_h_A;
  c1_gb_y = c1_c_B;
  c1_nc_x = c1_mc_x;
  c1_hb_y = c1_gb_y;
  c1_oc_x = c1_nc_x;
  c1_ib_y = c1_hb_y;
  c1_jb_y = c1_oc_x / c1_ib_y;
  c1_pc_x = c1_jb_y;
  c1_a_lr = c1_pc_x;
  c1_qc_x = c1_a_lr;
  c1_a_lr = c1_qc_x;
  c1_a_lr = muDoubleScalarAtan(c1_a_lr);
  _SFD_EML_CALL(0, 225);
  c1_i_A = c1_vc_rr;
  c1_d_B = c1_vl_rr;
  c1_rc_x = c1_i_A;
  c1_kb_y = c1_d_B;
  c1_sc_x = c1_rc_x;
  c1_lb_y = c1_kb_y;
  c1_tc_x = c1_sc_x;
  c1_mb_y = c1_lb_y;
  c1_nb_y = c1_tc_x / c1_mb_y;
  c1_uc_x = c1_nb_y;
  c1_a_rr = c1_uc_x;
  c1_vc_x = c1_a_rr;
  c1_a_rr = c1_vc_x;
  c1_a_rr = muDoubleScalarAtan(c1_a_rr);
  _SFD_EML_CALL(0, 227);
  c1_slp_ang[0] = c1_a_lf;
  c1_slp_ang[1] = c1_a_rf;
  c1_slp_ang[2] = c1_a_lr;
  c1_slp_ang[3] = c1_a_rr;

  /* ---------------------------------------% */
  /* END SLIP ANGLES NIKOLA */
  /* ---------------------------------------% */
  /* Linearized Force Coefficients (C_alpha) */
  _SFD_EML_CALL(0, 233);
  c1_C_alf = 25726.751950148697;
  _SFD_EML_CALL(0, 234);
  c1_C_arf = 25726.751950148697;
  _SFD_EML_CALL(0, 235);
  c1_C_alr = 16081.015549851298;
  _SFD_EML_CALL(0, 236);
  c1_C_arr = 16081.015549851298;
  _SFD_EML_CALL(0, 238);
  c1_Fxtlf = 0.0;
  _SFD_EML_CALL(0, 239);
  c1_Fxtrf = 0.0;
  _SFD_EML_CALL(0, 240);
  c1_Fxtlr = 0.0;
  _SFD_EML_CALL(0, 241);
  c1_Fxtrr = 0.0;
  _SFD_EML_CALL(0, 243);
  c1_v_a = -c1_a_lf;
  c1_Fytlf = c1_v_a * 25726.751950148697;
  _SFD_EML_CALL(0, 244);
  c1_w_a = -c1_a_rf;
  c1_Fytrf = c1_w_a * 25726.751950148697;
  _SFD_EML_CALL(0, 245);
  c1_x_a = -c1_a_lr;
  c1_Fytlr = c1_x_a * 16081.015549851298;
  _SFD_EML_CALL(0, 246);
  c1_y_a = -c1_a_rr;
  c1_Fytrr = c1_y_a * 16081.015549851298;
  _SFD_EML_CALL(0, 248);
  c1_wc_x = c1_delta;
  c1_xc_x = c1_wc_x;
  c1_yc_x = c1_xc_x;
  c1_xc_x = c1_yc_x;
  c1_xc_x = muDoubleScalarCos(c1_xc_x);
  c1_k_b = c1_xc_x;
  c1_ob_y = 0.0 * c1_k_b;
  c1_ad_x = c1_delta;
  c1_bd_x = c1_ad_x;
  c1_cd_x = c1_bd_x;
  c1_bd_x = c1_cd_x;
  c1_bd_x = muDoubleScalarSin(c1_bd_x);
  c1_ab_a = c1_Fytlf;
  c1_l_b = c1_bd_x;
  c1_pb_y = c1_ab_a * c1_l_b;
  c1_Fxlf = c1_ob_y - c1_pb_y;
  _SFD_EML_CALL(0, 249);
  c1_dd_x = c1_delta;
  c1_ed_x = c1_dd_x;
  c1_fd_x = c1_ed_x;
  c1_ed_x = c1_fd_x;
  c1_ed_x = muDoubleScalarCos(c1_ed_x);
  c1_m_b = c1_ed_x;
  c1_qb_y = 0.0 * c1_m_b;
  c1_gd_x = c1_delta;
  c1_hd_x = c1_gd_x;
  c1_id_x = c1_hd_x;
  c1_hd_x = c1_id_x;
  c1_hd_x = muDoubleScalarSin(c1_hd_x);
  c1_bb_a = c1_Fytrf;
  c1_n_b = c1_hd_x;
  c1_rb_y = c1_bb_a * c1_n_b;
  c1_Fxrf = c1_qb_y - c1_rb_y;
  _SFD_EML_CALL(0, 250);
  c1_Fxlr = 0.0;
  _SFD_EML_CALL(0, 251);
  c1_Fxrr = 0.0;
  _SFD_EML_CALL(0, 253);
  c1_jd_x = c1_delta;
  c1_kd_x = c1_jd_x;
  c1_ld_x = c1_kd_x;
  c1_kd_x = c1_ld_x;
  c1_kd_x = muDoubleScalarCos(c1_kd_x);
  c1_cb_a = c1_Fytlf;
  c1_o_b = c1_kd_x;
  c1_sb_y = c1_cb_a * c1_o_b;
  c1_md_x = c1_delta;
  c1_nd_x = c1_md_x;
  c1_od_x = c1_nd_x;
  c1_nd_x = c1_od_x;
  c1_nd_x = muDoubleScalarSin(c1_nd_x);
  c1_p_b = c1_nd_x;
  c1_tb_y = 0.0 * c1_p_b;
  c1_Fylf = c1_sb_y + c1_tb_y;
  _SFD_EML_CALL(0, 254);
  c1_pd_x = c1_delta;
  c1_qd_x = c1_pd_x;
  c1_rd_x = c1_qd_x;
  c1_qd_x = c1_rd_x;
  c1_qd_x = muDoubleScalarCos(c1_qd_x);
  c1_db_a = c1_Fytrf;
  c1_q_b = c1_qd_x;
  c1_ub_y = c1_db_a * c1_q_b;
  c1_sd_x = c1_delta;
  c1_td_x = c1_sd_x;
  c1_ud_x = c1_td_x;
  c1_td_x = c1_ud_x;
  c1_td_x = muDoubleScalarSin(c1_td_x);
  c1_r_b = c1_td_x;
  c1_vb_y = 0.0 * c1_r_b;
  c1_Fyrf = c1_ub_y + c1_vb_y;
  _SFD_EML_CALL(0, 255);
  c1_Fylr = c1_Fytlr;
  _SFD_EML_CALL(0, 256);
  c1_Fyrr = c1_Fytrr;
  _SFD_EML_CALL(0, 258);
  c1_Fout[0] = c1_Fylf;
  c1_Fout[1] = c1_Fyrf;
  c1_Fout[2] = c1_Fylr;
  c1_Fout[3] = c1_Fyrr;

  /* ---------------------------------------% */
  /* ==Tire Moments==% */
  _SFD_EML_CALL(0, 262);
  c1_Mzlf = 0.0;
  _SFD_EML_CALL(0, 263);
  c1_Mzrf = 0.0;
  _SFD_EML_CALL(0, 264);
  c1_Mzlr = 0.0;
  _SFD_EML_CALL(0, 265);
  c1_Mzrr = 0.0;

  /* ==Torques==% */
  _SFD_EML_CALL(0, 268);
  c1_s_b = c1_phi;
  c1_wb_y = -47298.369313023613 * c1_s_b;
  c1_t_b = c1_phi_d;
  c1_xb_y = 2717.2476562 * c1_t_b;
  c1_T_phif = c1_wb_y - c1_xb_y;
  _SFD_EML_CALL(0, 269);
  c1_u_b = c1_phi;
  c1_yb_y = -37310.859108305551 * c1_u_b;
  c1_v_b = c1_phi_d;
  c1_ac_y = 2895.6587717249995 * c1_v_b;
  c1_T_phir = c1_yb_y - c1_ac_y;

  /* -----------% */
  /* ==Sum forces and torques==% */
  _SFD_EML_CALL(0, 273);
  c1_sigFx = ((c1_Fxlf + c1_Fxrf) + c1_Fxlr) + c1_Fxrr;
  _SFD_EML_CALL(0, 274);
  c1_sigFy = ((c1_Fylf + c1_Fyrf) + c1_Fylr) + c1_Fyrr;

  /*  sigTxs  = T_phif + T_phir - ... */
  /*            M_s*g*h_s*sin(phi) + M_s*h_s*a_sy*cos(phi); */
  _SFD_EML_CALL(0, 277);
  c1_vd_x = c1_phi;
  c1_wd_x = c1_vd_x;
  c1_xd_x = c1_wd_x;
  c1_wd_x = c1_xd_x;
  c1_wd_x = muDoubleScalarSin(c1_wd_x);
  c1_w_b = c1_wd_x;
  c1_bc_y = 6673.7516684110269 * c1_w_b;
  c1_sigTxs = (c1_T_phif + c1_T_phir) - c1_bc_y;
  _SFD_EML_CALL(0, 278);
  c1_eb_a = c1_Fylf + c1_Fyrf;
  c1_cc_y = c1_eb_a * 1.0346864809057312;
  c1_fb_a = c1_Fylr + c1_Fyrr;
  c1_dc_y = c1_fb_a * 1.6553135190942689;
  c1_x_b = c1_Fxlf - c1_Fxrf;
  c1_ec_y = 0.77 * c1_x_b;
  c1_sigTz = (((((c1_cc_y - c1_dc_y) + c1_ec_y) + c1_Mzlf) + c1_Mzrf) + c1_Mzlr)
    + c1_Mzrr;

  /* --------------------------% */
  /*  %---------------------------------------% */
  /*  %EoM HIRTLE */
  /*  %---------------------------------------% */
  /*  a_x_new =  psi_d*v_y + (sigFx + ... */
  /*             M_s.*(-2*h_s.*phi_d.*psi_d.*cos(phi) - ... */
  /*             h_s.*psi_dd.*sin(phi)))./M; */
  /*  a_y_new = -psi_d*v_x + (sigFy - ... */
  /*             M_s*(-h_s*phi_dd*cos(phi) + ... */
  /*             h_s*phi_d^2*sin(phi) + ... */
  /*             h_s*psi_d^2*sin(phi)))./M; */
  /*  phi_dd_new = (sigTxs - ... */
  /*             (I_xzs+M_s*h_s*l_cgs)*cos(phi)*psi_dd + ... */
  /*             (I_xzs+M_s*h_s*l_cgs)*sin(phi)*phi_d*psi_d + ... */
  /*             (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi)*psi_d^2)./ ... */
  /*             (I_xxs+M_s*h_s^2); */
  /*  psi_dd_new = (sigTz - ... */
  /*             (I_xzs+M_s*h_s*l_cgs)*cos(phi)*phi_dd - ... */
  /*             (I_xzs+M_s*h_s*l_cgs)*sin(phi)*phi_d^2 - ... */
  /*              M_s*h_s*a_x*sin(phi) - ... */
  /*             (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi)*psi_d*phi_d)./ ... */
  /*              I_zzo; */
  /*  %---------------------------------------% */
  /*  %EoM HIRTLE END */
  /*  %---------------------------------------% */
  /* ---------------------------------------% */
  /* EoM NOXON */
  /* ---------------------------------------% */
  /* ==Equations of Motion==% */
  /*  mass matrix for coupled equations of motion */
  _SFD_EML_CALL(0, 313);
  c1_Am = 0.39907366905031622;
  _SFD_EML_CALL(0, 314);
  c1_Bm = -0.39907366905031622;
  _SFD_EML_CALL(0, 316);
  c1_yd_x = c1_phi;
  c1_ae_x = c1_yd_x;
  c1_be_x = c1_ae_x;
  c1_ae_x = c1_be_x;
  c1_ae_x = muDoubleScalarCos(c1_ae_x);
  c1_y_b = c1_mpower(chartInstance, c1_ae_x);
  c1_fc_y = 303.103865523518 * c1_y_b;
  c1_j_A = c1_fc_y;
  c1_ce_x = c1_j_A;
  c1_de_x = c1_ce_x;
  c1_ee_x = c1_de_x;
  c1_gc_y = c1_ee_x / 744.014865523518;
  c1_Cm1 = 1.0 - c1_gc_y;
  _SFD_EML_CALL(0, 318);
  c1_fe_x = c1_phi;
  c1_ge_x = c1_fe_x;
  c1_he_x = c1_ge_x;
  c1_ge_x = c1_he_x;
  c1_ge_x = muDoubleScalarCos(c1_ge_x);
  c1_ab_b = c1_ge_x;
  c1_hc_y = 7.54097 * c1_ab_b;
  c1_k_A = c1_hc_y;
  c1_ie_x = c1_k_A;
  c1_je_x = c1_ie_x;
  c1_ke_x = c1_je_x;
  c1_Cm2 = c1_ke_x / 744.014865523518;

  /*  Cm  = (I_xzs+M_s*h_s*l_cgs)/(I_xxs+M_s*h_s^2); */
  _SFD_EML_CALL(0, 322);
  c1_e_B = c1_I_zzo;
  c1_ic_y = c1_e_B;
  c1_jc_y = c1_ic_y;
  c1_kc_y = c1_jc_y;
  c1_Dm1 = 680.300883630074 / c1_kc_y;
  _SFD_EML_CALL(0, 323);
  c1_f_B = c1_I_zzo;
  c1_lc_y = c1_f_B;
  c1_mc_y = c1_lc_y;
  c1_nc_y = c1_mc_y;
  c1_Dm2 = 21.096972567806741 / c1_nc_y;
  _SFD_EML_CALL(0, 325);
  c1_le_x = c1_phi;
  c1_me_x = c1_le_x;
  c1_ne_x = c1_me_x;
  c1_me_x = c1_ne_x;
  c1_me_x = muDoubleScalarSin(c1_me_x);
  c1_bb_b = c1_me_x;
  c1_oc_y = 0.39907366905031622 * c1_bb_b;
  c1_oe_x = c1_phi;
  c1_pe_x = c1_oe_x;
  c1_qe_x = c1_pe_x;
  c1_pe_x = c1_qe_x;
  c1_pe_x = muDoubleScalarCos(c1_pe_x);
  c1_cb_b = c1_pe_x;
  c1_pc_y = -0.39907366905031622 * c1_cb_b;
  c1_re_x = c1_phi;
  c1_se_x = c1_re_x;
  c1_te_x = c1_se_x;
  c1_se_x = c1_te_x;
  c1_se_x = muDoubleScalarSin(c1_se_x);
  c1_gb_a = c1_Dm1;
  c1_db_b = c1_se_x;
  c1_qc_y = c1_gb_a * c1_db_b;
  c1_ue_x = c1_phi;
  c1_ve_x = c1_ue_x;
  c1_we_x = c1_ve_x;
  c1_ve_x = c1_we_x;
  c1_ve_x = muDoubleScalarCos(c1_ve_x);
  c1_hb_a = c1_Dm2;
  c1_eb_b = c1_ve_x;
  c1_rc_y = c1_hb_a * c1_eb_b;
  c1_Mass_Matrix[0] = 1.0;
  c1_Mass_Matrix[4] = 0.0;
  c1_Mass_Matrix[8] = 0.0;
  c1_Mass_Matrix[12] = c1_oc_y;
  c1_Mass_Matrix[1] = 0.0;
  c1_Mass_Matrix[5] = 1.0;
  c1_Mass_Matrix[9] = c1_pc_y;
  c1_Mass_Matrix[13] = 0.0;
  c1_Mass_Matrix[2] = 0.0;
  c1_Mass_Matrix[6] = 0.0;
  c1_Mass_Matrix[10] = c1_Cm1;
  c1_Mass_Matrix[14] = c1_Cm2;
  c1_Mass_Matrix[3] = c1_qc_y;
  c1_Mass_Matrix[7] = 0.0;
  c1_Mass_Matrix[11] = c1_rc_y;
  c1_Mass_Matrix[15] = 1.0;

  /*  coupled equations of motion */
  _SFD_EML_CALL(0, 331);
  c1_A1 = 1.0;
  _SFD_EML_CALL(0, 332);
  c1_A2 = 0.000586613480377779;
  _SFD_EML_CALL(0, 333);
  c1_A3 = -0.79814733810063243;
  _SFD_EML_CALL(0, 334);
  c1_B1 = -1.0;
  _SFD_EML_CALL(0, 335);
  c1_B2 = 0.000586613480377779;
  _SFD_EML_CALL(0, 336);
  c1_B3 = -0.39907366905031622;
  _SFD_EML_CALL(0, 337);
  c1_B4 = 0.39907366905031622;
  _SFD_EML_CALL(0, 338);
  c1_C1 = 0.0013440591664742624;
  _SFD_EML_CALL(0, 339);
  c1_C2 = 0.028355579364616707;
  _SFD_EML_CALL(0, 340);
  c1_C3 = -0.24559168639049464;
  _SFD_EML_CALL(0, 341);
  c1_C4 = 0.91436463860354156;
  _SFD_EML_CALL(0, 342);
  c1_C5 = -0.91436463860354156;
  _SFD_EML_CALL(0, 343);
  c1_g_B = c1_I_zzo;
  c1_sc_y = c1_g_B;
  c1_tc_y = c1_sc_y;
  c1_uc_y = c1_tc_y;
  c1_D1 = 1.0 / c1_uc_y;
  _SFD_EML_CALL(0, 344);
  c1_h_B = c1_I_zzo;
  c1_vc_y = c1_h_B;
  c1_wc_y = c1_vc_y;
  c1_xc_y = c1_wc_y;
  c1_D2 = -21.096972567806741 / c1_xc_y;
  _SFD_EML_CALL(0, 345);
  c1_i_B = c1_I_zzo;
  c1_yc_y = c1_i_B;
  c1_ad_y = c1_yc_y;
  c1_bd_y = c1_ad_y;
  c1_D3 = -182.72386552351787 / c1_bd_y;
  _SFD_EML_CALL(0, 347);
  for (c1_i37 = 0; c1_i37 < 4; c1_i37 = c1_i37 + 1) {
    c1_F_c[c1_i37] = 0.0;
  }

  _SFD_EML_CALL(0, 349);
  c1_fb_b = c1_psi_d;
  c1_cd_y = c1_fb_b;
  c1_ib_a = c1_cd_y;
  c1_gb_b = c1_v_y;
  c1_dd_y = c1_ib_a * c1_gb_b;
  c1_hb_b = c1_sigFx;
  c1_ed_y = 0.000586613480377779 * c1_hb_b;
  c1_ib_b = c1_phi_d;
  c1_fd_y = -0.79814733810063243 * c1_ib_b;
  c1_jb_a = c1_fd_y;
  c1_jb_b = c1_psi_d;
  c1_gd_y = c1_jb_a * c1_jb_b;
  c1_xe_x = c1_phi;
  c1_ye_x = c1_xe_x;
  c1_af_x = c1_ye_x;
  c1_ye_x = c1_af_x;
  c1_ye_x = muDoubleScalarCos(c1_ye_x);
  c1_kb_a = c1_gd_y;
  c1_kb_b = c1_ye_x;
  c1_hd_y = c1_kb_a * c1_kb_b;
  c1_F_c[0] = (c1_dd_y + c1_ed_y) + c1_hd_y;
  _SFD_EML_CALL(0, 350);
  c1_lb_b = c1_psi_d;
  c1_id_y = -1.0 * c1_lb_b;
  c1_lb_a = c1_id_y;
  c1_mb_b = c1_v_x;
  c1_jd_y = c1_lb_a * c1_mb_b;
  c1_nb_b = c1_sigFy;
  c1_kd_y = 0.000586613480377779 * c1_nb_b;
  c1_ob_b = c1_mpower(chartInstance, c1_phi_d);
  c1_ld_y = -0.39907366905031622 * c1_ob_b;
  c1_bf_x = c1_phi;
  c1_cf_x = c1_bf_x;
  c1_df_x = c1_cf_x;
  c1_cf_x = c1_df_x;
  c1_cf_x = muDoubleScalarSin(c1_cf_x);
  c1_mb_a = c1_ld_y;
  c1_pb_b = c1_cf_x;
  c1_md_y = c1_mb_a * c1_pb_b;
  c1_qb_b = c1_mpower(chartInstance, c1_psi_d);
  c1_nd_y = 0.39907366905031622 * c1_qb_b;
  c1_ef_x = c1_phi;
  c1_ff_x = c1_ef_x;
  c1_gf_x = c1_ff_x;
  c1_ff_x = c1_gf_x;
  c1_ff_x = muDoubleScalarSin(c1_ff_x);
  c1_nb_a = c1_nd_y;
  c1_rb_b = c1_ff_x;
  c1_od_y = c1_nb_a * c1_rb_b;
  c1_F_c[1] = ((c1_jd_y + c1_kd_y) + c1_md_y) + c1_od_y;
  _SFD_EML_CALL(0, 351);
  c1_sb_b = c1_sigTxs;
  c1_pd_y = 0.0013440591664742624 * c1_sb_b;
  c1_hf_x = c1_phi;
  c1_if_x = c1_hf_x;
  c1_jf_x = c1_if_x;
  c1_if_x = c1_jf_x;
  c1_if_x = muDoubleScalarSin(c1_if_x);
  c1_tb_b = c1_if_x;
  c1_qd_y = 0.028355579364616707 * c1_tb_b;
  c1_ob_a = c1_qd_y;
  c1_ub_b = c1_phi_d;
  c1_rd_y = c1_ob_a * c1_ub_b;
  c1_pb_a = c1_rd_y;
  c1_vb_b = c1_psi_d;
  c1_sd_y = c1_pb_a * c1_vb_b;
  c1_kf_x = c1_phi;
  c1_lf_x = c1_kf_x;
  c1_mf_x = c1_lf_x;
  c1_lf_x = c1_mf_x;
  c1_lf_x = muDoubleScalarSin(c1_lf_x);
  c1_wb_b = c1_lf_x;
  c1_td_y = -0.24559168639049464 * c1_wb_b;
  c1_nf_x = c1_phi;
  c1_of_x = c1_nf_x;
  c1_pf_x = c1_of_x;
  c1_of_x = c1_pf_x;
  c1_of_x = muDoubleScalarCos(c1_of_x);
  c1_qb_a = c1_td_y;
  c1_xb_b = c1_of_x;
  c1_ud_y = c1_qb_a * c1_xb_b;
  c1_rb_a = c1_ud_y;
  c1_yb_b = c1_mpower(chartInstance, c1_psi_d);
  c1_vd_y = c1_rb_a * c1_yb_b;
  c1_qf_x = c1_phi;
  c1_rf_x = c1_qf_x;
  c1_sf_x = c1_rf_x;
  c1_rf_x = c1_sf_x;
  c1_rf_x = muDoubleScalarCos(c1_rf_x);
  c1_ac_b = c1_rf_x;
  c1_wd_y = 0.91436463860354156 * c1_ac_b;
  c1_sb_a = c1_wd_y;
  c1_bc_b = c1_psi_d;
  c1_xd_y = c1_sb_a * c1_bc_b;
  c1_tb_a = c1_xd_y;
  c1_cc_b = c1_v_x;
  c1_yd_y = c1_tb_a * c1_cc_b;
  c1_tf_x = c1_phi;
  c1_uf_x = c1_tf_x;
  c1_vf_x = c1_uf_x;
  c1_uf_x = c1_vf_x;
  c1_uf_x = muDoubleScalarSin(c1_uf_x);
  c1_dc_b = c1_uf_x;
  c1_ae_y = -0.91436463860354156 * c1_dc_b;
  c1_wf_x = c1_phi;
  c1_xf_x = c1_wf_x;
  c1_yf_x = c1_xf_x;
  c1_xf_x = c1_yf_x;
  c1_xf_x = muDoubleScalarCos(c1_xf_x);
  c1_ub_a = c1_ae_y;
  c1_ec_b = c1_xf_x;
  c1_be_y = c1_ub_a * c1_ec_b;
  c1_vb_a = c1_be_y;
  c1_fc_b = c1_mpower(chartInstance, c1_phi_d) + c1_mpower(chartInstance,
    c1_psi_d);
  c1_ce_y = c1_vb_a * c1_fc_b;
  c1_F_c[2] = (((c1_pd_y + c1_sd_y) + c1_vd_y) + c1_yd_y) + c1_ce_y;
  _SFD_EML_CALL(0, 352);
  c1_wb_a = c1_D1;
  c1_gc_b = c1_sigTz;
  c1_de_y = c1_wb_a * c1_gc_b;
  c1_ag_x = c1_phi;
  c1_bg_x = c1_ag_x;
  c1_cg_x = c1_bg_x;
  c1_bg_x = c1_cg_x;
  c1_bg_x = muDoubleScalarSin(c1_bg_x);
  c1_xb_a = c1_D2;
  c1_hc_b = c1_bg_x;
  c1_ee_y = c1_xb_a * c1_hc_b;
  c1_yb_a = c1_ee_y;
  c1_ic_b = c1_mpower(chartInstance, c1_phi_d);
  c1_fe_y = c1_yb_a * c1_ic_b;
  c1_dg_x = c1_phi;
  c1_eg_x = c1_dg_x;
  c1_fg_x = c1_eg_x;
  c1_eg_x = c1_fg_x;
  c1_eg_x = muDoubleScalarSin(c1_eg_x);
  c1_ac_a = c1_D3;
  c1_jc_b = c1_eg_x;
  c1_ge_y = c1_ac_a * c1_jc_b;
  c1_gg_x = c1_phi;
  c1_hg_x = c1_gg_x;
  c1_ig_x = c1_hg_x;
  c1_hg_x = c1_ig_x;
  c1_hg_x = muDoubleScalarCos(c1_hg_x);
  c1_bc_a = c1_ge_y;
  c1_kc_b = c1_hg_x;
  c1_he_y = c1_bc_a * c1_kc_b;
  c1_cc_a = c1_he_y;
  c1_lc_b = c1_psi_d;
  c1_ie_y = c1_cc_a * c1_lc_b;
  c1_dc_a = c1_ie_y;
  c1_mc_b = c1_phi_d;
  c1_je_y = c1_dc_a * c1_mc_b;
  c1_F_c[3] = (c1_de_y + c1_fe_y) + c1_je_y;

  /*  decouple the EoM */
  _SFD_EML_CALL(0, 355);
  for (c1_i38 = 0; c1_i38 < 16; c1_i38 = c1_i38 + 1) {
    c1_b_Mass_Matrix[c1_i38] = c1_Mass_Matrix[c1_i38];
  }

  c1_b_mpower(chartInstance, c1_b_Mass_Matrix, c1_ec_a);
  for (c1_i39 = 0; c1_i39 < 4; c1_i39 = c1_i39 + 1) {
    c1_nc_b[c1_i39] = c1_F_c[c1_i39];
  }

  c1_e_eml_scalar_eg(chartInstance);
  c1_e_eml_scalar_eg(chartInstance);
  for (c1_i40 = 0; c1_i40 < 16; c1_i40 = c1_i40 + 1) {
    c1_l_A[c1_i40] = c1_ec_a[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 4; c1_i41 = c1_i41 + 1) {
    c1_j_B[c1_i41] = c1_nc_b[c1_i41];
  }

  for (c1_i42 = 0; c1_i42 < 4; c1_i42 = c1_i42 + 1) {
    c1_F_u[c1_i42] = 0.0;
  }

  for (c1_i43 = 0; c1_i43 < 16; c1_i43 = c1_i43 + 1) {
    c1_m_A[c1_i43] = c1_l_A[c1_i43];
  }

  for (c1_i44 = 0; c1_i44 < 4; c1_i44 = c1_i44 + 1) {
    c1_k_B[c1_i44] = c1_j_B[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 16; c1_i45 = c1_i45 + 1) {
    c1_n_A[c1_i45] = c1_m_A[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 4; c1_i46 = c1_i46 + 1) {
    c1_l_B[c1_i46] = c1_k_B[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 4; c1_i47 = c1_i47 + 1) {
    c1_F_u[c1_i47] = 0.0;
    c1_i48 = 0;
    for (c1_i49 = 0; c1_i49 < 4; c1_i49 = c1_i49 + 1) {
      c1_F_u[c1_i47] = c1_F_u[c1_i47] + c1_n_A[c1_i48 + c1_i47] * c1_l_B[c1_i49];
      c1_i48 = c1_i48 + 4;
    }
  }

  /*  extract the left hand side of the EoM */
  _SFD_EML_CALL(0, 358);
  c1_a_x_new = c1_F_u[0];
  _SFD_EML_CALL(0, 359);
  c1_a_y_new = c1_F_u[1];
  _SFD_EML_CALL(0, 360);
  c1_phi_dd_new = c1_F_u[2];
  _SFD_EML_CALL(0, 361);
  c1_psi_dd_new = c1_F_u[3];

  /* ---------------------------------------% */
  /* EoM NOXON END */
  /* ---------------------------------------% */
  /* ==Update independent variables==% */
  /* acceleration outputs */
  /*  acc_out = [a_x_new;a_y_new;a_sy;phi_dd_new;psi_dd_new];         */
  _SFD_EML_CALL(0, 370);
  c1_pdot[0] = c1_a_x_new;
  c1_pdot[1] = c1_a_y_new;
  c1_pdot[2] = c1_phi_d;
  c1_pdot[3] = c1_phi_dd_new;
  c1_pdot[4] = c1_psi_d;
  c1_pdot[5] = c1_psi_dd_new;

  /* ----------------------------------% */
  /* end */
  /* nd */
  /* d */
  /*  */
  _SFD_EML_CALL(0, -370);
  sf_debug_symbol_scope_pop();
  for (c1_i50 = 0; c1_i50 < 6; c1_i50 = c1_i50 + 1) {
    (*c1_b_pdot)[c1_i50] = c1_pdot[c1_i50];
  }

  for (c1_i51 = 0; c1_i51 < 4; c1_i51 = c1_i51 + 1) {
    (*c1_b_slp_ang)[c1_i51] = c1_slp_ang[c1_i51];
  }

  for (c1_i52 = 0; c1_i52 < 4; c1_i52 = c1_i52 + 1) {
    (*c1_b_Fout)[c1_i52] = c1_Fout[c1_i52];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
}

static void compInitSubchartSimstructsFcn_c1_DVM_Nikola_test_2
  (SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_mpower(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_a)
{
  return c1_power(chartInstance, c1_a, 2.0);
}

static real_T c1_power(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_a, real_T c1_b)
{
  real_T c1_ak;
  real_T c1_bk;
  real_T c1_x;
  real_T c1_b_x;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_a;
  c1_bk = c1_b;
  if (c1_ak < 0.0) {
    c1_x = c1_bk;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarFloor(c1_b_x);
    if (c1_b_x != c1_bk) {
      c1_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c1_ak, c1_bk);
}

static void c1_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
}

static void c1_eml_error(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
  int32_T c1_i53;
  static char_T c1_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  int32_T c1_i54;
  static char_T c1_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c1_b_u[102];
  const mxArray *c1_b_y = NULL;
  for (c1_i53 = 0; c1_i53 < 32; c1_i53 = c1_i53 + 1) {
    c1_u[c1_i53] = c1_cv0[c1_i53];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c1_i54 = 0; c1_i54 < 102; c1_i54 = c1_i54 + 1) {
    c1_b_u[c1_i54] = c1_cv1[c1_i54];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_b_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
}

static void c1_eml_xgemm(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_A[9], real_T c1_B[9], real_T c1_C[9], real_T
  c1_b_C[9])
{
  int32_T c1_i55;
  real_T c1_b_A[9];
  int32_T c1_i56;
  real_T c1_b_B[9];
  int32_T c1_i57;
  real_T c1_c_A[9];
  int32_T c1_i58;
  real_T c1_c_B[9];
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  for (c1_i55 = 0; c1_i55 < 9; c1_i55 = c1_i55 + 1) {
    c1_b_A[c1_i55] = c1_A[c1_i55];
  }

  for (c1_i56 = 0; c1_i56 < 9; c1_i56 = c1_i56 + 1) {
    c1_b_B[c1_i56] = c1_B[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 9; c1_i57 = c1_i57 + 1) {
    c1_c_A[c1_i57] = c1_b_A[c1_i57];
  }

  for (c1_i58 = 0; c1_i58 < 9; c1_i58 = c1_i58 + 1) {
    c1_c_B[c1_i58] = c1_b_B[c1_i58];
  }

  for (c1_i59 = 0; c1_i59 < 3; c1_i59 = c1_i59 + 1) {
    c1_i60 = 0;
    for (c1_i61 = 0; c1_i61 < 3; c1_i61 = c1_i61 + 1) {
      c1_b_C[c1_i60 + c1_i59] = 0.0;
      c1_i62 = 0;
      for (c1_i63 = 0; c1_i63 < 3; c1_i63 = c1_i63 + 1) {
        c1_b_C[c1_i60 + c1_i59] = c1_b_C[c1_i60 + c1_i59] + c1_c_A[c1_i62 +
          c1_i59] * c1_c_B[c1_i63 + c1_i60];
        c1_i62 = c1_i62 + 3;
      }

      c1_i60 = c1_i60 + 3;
    }
  }
}

static void c1_b_mpower(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_a[16], real_T c1_c[16])
{
  int32_T c1_i64;
  real_T c1_b_a[16];
  for (c1_i64 = 0; c1_i64 < 16; c1_i64 = c1_i64 + 1) {
    c1_b_a[c1_i64] = c1_a[c1_i64];
  }

  c1_matrix_to_integer_power(chartInstance, c1_b_a, -1.0, c1_c);
}

static void c1_matrix_to_integer_power(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, real_T c1_a[16], real_T c1_b, real_T
  c1_c[16])
{
  real_T c1_x;
  real_T c1_e;
  boolean_T c1_firstmult;
  real_T c1_b_x;
  real_T c1_ed2;
  real_T c1_b_b;
  real_T c1_y;
  int32_T c1_i65;
  int32_T c1_i66;
  real_T c1_b_a[16];
  int32_T c1_i67;
  real_T c1_c_b[16];
  int32_T c1_i68;
  real_T c1_A[16];
  int32_T c1_i69;
  real_T c1_B[16];
  int32_T c1_i70;
  real_T c1_b_A[16];
  int32_T c1_i71;
  real_T c1_b_B[16];
  int32_T c1_i72;
  real_T c1_c_A[16];
  int32_T c1_i73;
  real_T c1_c_B[16];
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  real_T c1_c_x[16];
  int32_T c1_i80;
  real_T c1_d_x[16];
  int32_T c1_i81;
  real_T c1_e_x[16];
  int32_T c1_i82;
  real_T c1_xinv[16];
  int32_T c1_i83;
  real_T c1_f_x[16];
  real_T c1_n1x;
  int32_T c1_i84;
  real_T c1_b_xinv[16];
  real_T c1_n1xinv;
  real_T c1_c_a;
  real_T c1_d_b;
  real_T c1_b_y;
  real_T c1_rc;
  real_T c1_g_x;
  boolean_T c1_e_b;
  int32_T c1_i85;
  real_T c1_d_a[16];
  int32_T c1_i86;
  real_T c1_f_b[16];
  int32_T c1_i87;
  real_T c1_d_A[16];
  int32_T c1_i88;
  real_T c1_d_B[16];
  int32_T c1_i89;
  real_T c1_e_A[16];
  int32_T c1_i90;
  real_T c1_e_B[16];
  int32_T c1_i91;
  real_T c1_f_A[16];
  int32_T c1_i92;
  real_T c1_f_B[16];
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_k;
  int32_T c1_b_k;
  c1_c_eml_scalar_eg(chartInstance);
  c1_x = c1_b;
  c1_e = muDoubleScalarAbs(c1_x);
  if (c1_e > 0.0) {
    c1_firstmult = TRUE;
   label_1:
    ;
    c1_b_x = c1_e / 2.0;
    c1_ed2 = c1_b_x;
    c1_ed2 = muDoubleScalarFloor(c1_ed2);
    c1_b_b = c1_ed2;
    c1_y = 2.0 * c1_b_b;
    if (c1_y != c1_e) {
      if (c1_firstmult) {
        for (c1_i65 = 0; c1_i65 < 16; c1_i65 = c1_i65 + 1) {
          c1_c[c1_i65] = c1_a[c1_i65];
        }

        c1_firstmult = FALSE;
      } else {
        for (c1_i66 = 0; c1_i66 < 16; c1_i66 = c1_i66 + 1) {
          c1_b_a[c1_i66] = c1_c[c1_i66];
        }

        for (c1_i67 = 0; c1_i67 < 16; c1_i67 = c1_i67 + 1) {
          c1_c_b[c1_i67] = c1_a[c1_i67];
        }

        c1_d_eml_scalar_eg(chartInstance);
        c1_d_eml_scalar_eg(chartInstance);
        for (c1_i68 = 0; c1_i68 < 16; c1_i68 = c1_i68 + 1) {
          c1_A[c1_i68] = c1_b_a[c1_i68];
        }

        for (c1_i69 = 0; c1_i69 < 16; c1_i69 = c1_i69 + 1) {
          c1_B[c1_i69] = c1_c_b[c1_i69];
        }

        for (c1_i70 = 0; c1_i70 < 16; c1_i70 = c1_i70 + 1) {
          c1_b_A[c1_i70] = c1_A[c1_i70];
        }

        for (c1_i71 = 0; c1_i71 < 16; c1_i71 = c1_i71 + 1) {
          c1_b_B[c1_i71] = c1_B[c1_i71];
        }

        for (c1_i72 = 0; c1_i72 < 16; c1_i72 = c1_i72 + 1) {
          c1_c_A[c1_i72] = c1_b_A[c1_i72];
        }

        for (c1_i73 = 0; c1_i73 < 16; c1_i73 = c1_i73 + 1) {
          c1_c_B[c1_i73] = c1_b_B[c1_i73];
        }

        for (c1_i74 = 0; c1_i74 < 4; c1_i74 = c1_i74 + 1) {
          c1_i75 = 0;
          for (c1_i76 = 0; c1_i76 < 4; c1_i76 = c1_i76 + 1) {
            c1_c[c1_i75 + c1_i74] = 0.0;
            c1_i77 = 0;
            for (c1_i78 = 0; c1_i78 < 4; c1_i78 = c1_i78 + 1) {
              c1_c[c1_i75 + c1_i74] = c1_c[c1_i75 + c1_i74] + c1_c_A[c1_i77 +
                c1_i74] * c1_c_B[c1_i78 + c1_i75];
              c1_i77 = c1_i77 + 4;
            }

            c1_i75 = c1_i75 + 4;
          }
        }
      }
    }

    if (c1_ed2 == 0.0) {
    } else {
      c1_e = c1_ed2;
      for (c1_i85 = 0; c1_i85 < 16; c1_i85 = c1_i85 + 1) {
        c1_d_a[c1_i85] = c1_a[c1_i85];
      }

      for (c1_i86 = 0; c1_i86 < 16; c1_i86 = c1_i86 + 1) {
        c1_f_b[c1_i86] = c1_a[c1_i86];
      }

      c1_d_eml_scalar_eg(chartInstance);
      c1_d_eml_scalar_eg(chartInstance);
      for (c1_i87 = 0; c1_i87 < 16; c1_i87 = c1_i87 + 1) {
        c1_d_A[c1_i87] = c1_d_a[c1_i87];
      }

      for (c1_i88 = 0; c1_i88 < 16; c1_i88 = c1_i88 + 1) {
        c1_d_B[c1_i88] = c1_f_b[c1_i88];
      }

      for (c1_i89 = 0; c1_i89 < 16; c1_i89 = c1_i89 + 1) {
        c1_e_A[c1_i89] = c1_d_A[c1_i89];
      }

      for (c1_i90 = 0; c1_i90 < 16; c1_i90 = c1_i90 + 1) {
        c1_e_B[c1_i90] = c1_d_B[c1_i90];
      }

      for (c1_i91 = 0; c1_i91 < 16; c1_i91 = c1_i91 + 1) {
        c1_f_A[c1_i91] = c1_e_A[c1_i91];
      }

      for (c1_i92 = 0; c1_i92 < 16; c1_i92 = c1_i92 + 1) {
        c1_f_B[c1_i92] = c1_e_B[c1_i92];
      }

      for (c1_i93 = 0; c1_i93 < 4; c1_i93 = c1_i93 + 1) {
        c1_i94 = 0;
        for (c1_i95 = 0; c1_i95 < 4; c1_i95 = c1_i95 + 1) {
          c1_a[c1_i94 + c1_i93] = 0.0;
          c1_i96 = 0;
          for (c1_i97 = 0; c1_i97 < 4; c1_i97 = c1_i97 + 1) {
            c1_a[c1_i94 + c1_i93] = c1_a[c1_i94 + c1_i93] + c1_f_A[c1_i96 +
              c1_i93] * c1_f_B[c1_i97 + c1_i94];
            c1_i96 = c1_i96 + 4;
          }

          c1_i94 = c1_i94 + 4;
        }
      }

      goto label_1;
    }

    if (c1_b < 0.0) {
      for (c1_i79 = 0; c1_i79 < 16; c1_i79 = c1_i79 + 1) {
        c1_c_x[c1_i79] = c1_c[c1_i79];
      }

      for (c1_i80 = 0; c1_i80 < 16; c1_i80 = c1_i80 + 1) {
        c1_d_x[c1_i80] = c1_c_x[c1_i80];
      }

      c1_invNxN(chartInstance, c1_d_x, c1_c);
      for (c1_i81 = 0; c1_i81 < 16; c1_i81 = c1_i81 + 1) {
        c1_e_x[c1_i81] = c1_c_x[c1_i81];
      }

      for (c1_i82 = 0; c1_i82 < 16; c1_i82 = c1_i82 + 1) {
        c1_xinv[c1_i82] = c1_c[c1_i82];
      }

      for (c1_i83 = 0; c1_i83 < 16; c1_i83 = c1_i83 + 1) {
        c1_f_x[c1_i83] = c1_e_x[c1_i83];
      }

      c1_n1x = c1_norm(chartInstance, c1_f_x);
      for (c1_i84 = 0; c1_i84 < 16; c1_i84 = c1_i84 + 1) {
        c1_b_xinv[c1_i84] = c1_xinv[c1_i84];
      }

      c1_n1xinv = c1_norm(chartInstance, c1_b_xinv);
      c1_c_a = c1_n1x;
      c1_d_b = c1_n1xinv;
      c1_b_y = c1_c_a * c1_d_b;
      c1_rc = 1.0 / c1_b_y;
      if (c1_n1x == 0.0) {
      } else if (c1_n1xinv == 0.0) {
      } else if (c1_rc == 0.0) {
        goto label_2;
      } else {
        c1_g_x = c1_rc;
        c1_e_b = muDoubleScalarIsNaN(c1_g_x);
        if (c1_e_b) {
        } else if (c1_rc < 2.2204460492503131E-16) {
        } else {
          return;
        }

        c1_b_eml_warning(chartInstance, c1_rc);
        return;
      }

     label_2:
      ;
      c1_eml_warning(chartInstance);
    }
  } else {
    for (c1_i98 = 0; c1_i98 < 16; c1_i98 = c1_i98 + 1) {
      c1_c[c1_i98] = 0.0;
    }

    for (c1_k = 1; c1_k < 5; c1_k = c1_k + 1) {
      c1_b_k = c1_k;
      c1_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_b_k), 1, 4, 1, 0) - 1) + ((
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c1_b_k), 1, 4, 2, 0) - 1) << 2)] = 1.0;
    }
  }
}

static void c1_c_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
}

static void c1_d_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
}

static void c1_invNxN(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
                      real_T c1_x[16], real_T c1_y[16])
{
  int32_T c1_i99;
  int32_T c1_i100;
  real_T c1_A[16];
  int32_T c1_i101;
  real_T c1_b_x[16];
  int32_T c1_i102;
  real_T c1_b_A[16];
  int32_T c1_i103;
  real_T c1_c_A[16];
  int32_T c1_i104;
  real_T c1_d_A[16];
  int32_T c1_info;
  int32_T c1_ipiv[4];
  real_T c1_e_A[16];
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_b_ipiv[4];
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_c_ipiv[4];
  int32_T c1_i109;
  int32_T c1_i110;
  int32_T c1_d_ipiv[4];
  int32_T c1_i111;
  int32_T c1_e_ipiv[4];
  int32_T c1_i112;
  int32_T c1_p[4];
  real_T c1_k;
  real_T c1_b_k;
  int32_T c1_ipk;
  int32_T c1_pipk;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_c;
  int32_T c1_e_k;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_i113;
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_b_y;
  int32_T c1_i114;
  real_T c1_f_A[16];
  int32_T c1_i115;
  real_T c1_B[16];
  int32_T c1_i116;
  int32_T c1_i117;
  real_T c1_g_A[16];
  int32_T c1_i118;
  real_T c1_c_y[16];
  for (c1_i99 = 0; c1_i99 < 16; c1_i99 = c1_i99 + 1) {
    c1_y[c1_i99] = 0.0;
  }

  for (c1_i100 = 0; c1_i100 < 16; c1_i100 = c1_i100 + 1) {
    c1_A[c1_i100] = c1_x[c1_i100];
  }

  for (c1_i101 = 0; c1_i101 < 16; c1_i101 = c1_i101 + 1) {
    c1_b_x[c1_i101] = c1_A[c1_i101];
  }

  for (c1_i102 = 0; c1_i102 < 16; c1_i102 = c1_i102 + 1) {
    c1_b_A[c1_i102] = c1_b_x[c1_i102];
  }

  for (c1_i103 = 0; c1_i103 < 16; c1_i103 = c1_i103 + 1) {
    c1_c_A[c1_i103] = c1_b_A[c1_i103];
  }

  for (c1_i104 = 0; c1_i104 < 16; c1_i104 = c1_i104 + 1) {
    c1_d_A[c1_i104] = c1_c_A[c1_i104];
  }

  c1_eml_matlab_zgetrf(chartInstance, c1_d_A, c1_e_A, c1_ipiv, &c1_info);
  for (c1_i105 = 0; c1_i105 < 16; c1_i105 = c1_i105 + 1) {
    c1_c_A[c1_i105] = c1_e_A[c1_i105];
  }

  for (c1_i106 = 0; c1_i106 < 4; c1_i106 = c1_i106 + 1) {
    c1_b_ipiv[c1_i106] = c1_ipiv[c1_i106];
  }

  for (c1_i107 = 0; c1_i107 < 16; c1_i107 = c1_i107 + 1) {
    c1_b_x[c1_i107] = c1_c_A[c1_i107];
  }

  for (c1_i108 = 0; c1_i108 < 4; c1_i108 = c1_i108 + 1) {
    c1_c_ipiv[c1_i108] = c1_b_ipiv[c1_i108];
  }

  for (c1_i109 = 0; c1_i109 < 16; c1_i109 = c1_i109 + 1) {
    c1_x[c1_i109] = c1_b_x[c1_i109];
  }

  for (c1_i110 = 0; c1_i110 < 4; c1_i110 = c1_i110 + 1) {
    c1_d_ipiv[c1_i110] = c1_c_ipiv[c1_i110];
  }

  for (c1_i111 = 0; c1_i111 < 4; c1_i111 = c1_i111 + 1) {
    c1_e_ipiv[c1_i111] = c1_d_ipiv[c1_i111];
  }

  for (c1_i112 = 0; c1_i112 < 4; c1_i112 = c1_i112 + 1) {
    c1_p[c1_i112] = 1 + c1_i112;
  }

  for (c1_k = 1.0; c1_k <= 3.0; c1_k = c1_k + 1.0) {
    c1_b_k = c1_k;
    c1_ipk = c1_e_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 4, 1, 0) - 1];
    if ((real_T)c1_ipk > c1_b_k) {
      c1_pipk = c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c1_ipk), 1, 4, 1, 0) - 1];
      c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_ipk), 1, 4, 1, 0) - 1] = c1_p[
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
        1, 4, 1, 0) - 1];
      c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c1_b_k), 1, 4, 1, 0) - 1] = c1_pipk;
    }
  }

  for (c1_c_k = 1; c1_c_k < 5; c1_c_k = c1_c_k + 1) {
    c1_d_k = c1_c_k;
    c1_c = c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_d_k), 1, 4, 1, 0) - 1];
    c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_d_k), 1, 4, 1, 0) - 1) + ((
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_c), 1, 4, 2, 0) - 1) << 2)] = 1.0;
    c1_e_k = c1_d_k;
    for (c1_j = c1_e_k; c1_j < 5; c1_j = c1_j + 1) {
      c1_b_j = c1_j;
      if (c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c1_b_j), 1, 4, 1, 0) - 1) + ((
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)] != 0.0) {
        c1_a = c1_b_j;
        c1_i113 = c1_a + 1;
        for (c1_i = c1_i113; c1_i < 5; c1_i = c1_i + 1) {
          c1_b_i = c1_i;
          c1_b_a = c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) - 1) + ((
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)];
          c1_b = c1_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) - 1) + ((
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_j), 1, 4, 2, 0) - 1) << 2)];
          c1_b_y = c1_b_a * c1_b;
          c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c1_b_i), 1, 4, 1, 0) - 1) + ((
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)] = c1_y[(
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_i), 1, 4, 1, 0) - 1) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(""
            , (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_c), 1, 4, 2, 0) - 1) <<
            2)] - c1_b_y;
        }
      }
    }
  }

  for (c1_i114 = 0; c1_i114 < 16; c1_i114 = c1_i114 + 1) {
    c1_f_A[c1_i114] = c1_x[c1_i114];
  }

  for (c1_i115 = 0; c1_i115 < 16; c1_i115 = c1_i115 + 1) {
    c1_B[c1_i115] = c1_y[c1_i115];
  }

  for (c1_i116 = 0; c1_i116 < 16; c1_i116 = c1_i116 + 1) {
    c1_y[c1_i116] = c1_B[c1_i116];
  }

  for (c1_i117 = 0; c1_i117 < 16; c1_i117 = c1_i117 + 1) {
    c1_g_A[c1_i117] = c1_f_A[c1_i117];
  }

  for (c1_i118 = 0; c1_i118 < 16; c1_i118 = c1_i118 + 1) {
    c1_c_y[c1_i118] = c1_y[c1_i118];
  }

  c1_eml_blas_xtrsm(chartInstance, 4, 4, 1.0, c1_g_A, 1, 4, c1_c_y, 1, 4, c1_y);
}

static void c1_eps(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
}

static void c1_eml_matlab_zgetrf(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_b_A[16], int32_T
  c1_ipiv[4], int32_T *c1_info)
{
  int32_T c1_i119;
  int32_T c1_i120;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_jm1;
  int32_T c1_b;
  int32_T c1_mmj;
  int32_T c1_b_a;
  int32_T c1_c;
  int32_T c1_b_b;
  int32_T c1_jj;
  int32_T c1_c_a;
  int32_T c1_jp1j;
  int32_T c1_d_a;
  int32_T c1_b_c;
  int32_T c1_i121;
  real_T c1_c_A[16];
  int32_T c1_e_a;
  int32_T c1_jpiv_offset;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_jpiv;
  int32_T c1_g_a;
  int32_T c1_d_b;
  int32_T c1_c_c;
  int32_T c1_e_b;
  int32_T c1_jrow;
  int32_T c1_h_a;
  int32_T c1_f_b;
  int32_T c1_jprow;
  int32_T c1_i122;
  real_T c1_x[16];
  int32_T c1_ix0;
  int32_T c1_iy0;
  int32_T c1_i123;
  int32_T c1_i124;
  real_T c1_b_x[16];
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_i125;
  real_T c1_c_x[16];
  int32_T c1_i126;
  real_T c1_d_x[16];
  real_T c1_e_x[16];
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_b_jp1j;
  int32_T c1_i_a;
  int32_T c1_d_c;
  int32_T c1_j_a;
  int32_T c1_g_b;
  int32_T c1_loop_ub;
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_f_x;
  real_T c1_y;
  real_T c1_g_x;
  real_T c1_b_y;
  real_T c1_z;
  int32_T c1_h_b;
  int32_T c1_e_c;
  int32_T c1_k_a;
  int32_T c1_f_c;
  int32_T c1_l_a;
  int32_T c1_g_c;
  int32_T c1_m;
  int32_T c1_n;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_i129;
  real_T c1_d_A[16];
  int32_T c1_ia0;
  int32_T c1_i130;
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_d_ix0;
  int32_T c1_d_iy0;
  int32_T c1_i131;
  real_T c1_e_A[16];
  int32_T c1_b_ia0;
  int32_T c1_i132;
  int32_T c1_c_m;
  int32_T c1_c_n;
  int32_T c1_e_ix0;
  int32_T c1_e_iy0;
  int32_T c1_i133;
  real_T c1_f_A[16];
  int32_T c1_c_ia0;
  int32_T c1_i134;
  int32_T c1_i135;
  real_T c1_g_A[16];
  for (c1_i119 = 0; c1_i119 < 16; c1_i119 = c1_i119 + 1) {
    c1_b_A[c1_i119] = c1_A[c1_i119];
  }

  c1_eps(chartInstance);
  for (c1_i120 = 0; c1_i120 < 4; c1_i120 = c1_i120 + 1) {
    c1_ipiv[c1_i120] = 1 + c1_i120;
  }

  *c1_info = 0;
  for (c1_j = 1; c1_j < 4; c1_j = c1_j + 1) {
    c1_b_j = c1_j;
    c1_a = c1_b_j;
    c1_jm1 = c1_a - 1;
    c1_b = c1_b_j;
    c1_mmj = 4 - c1_b;
    c1_b_a = c1_jm1;
    c1_c = c1_b_a * 5;
    c1_b_b = c1_c;
    c1_jj = 1 + c1_b_b;
    c1_c_a = c1_jj;
    c1_jp1j = c1_c_a + 1;
    c1_d_a = c1_mmj;
    c1_b_c = c1_d_a + 1;
    for (c1_i121 = 0; c1_i121 < 16; c1_i121 = c1_i121 + 1) {
      c1_c_A[c1_i121] = c1_b_A[c1_i121];
    }

    c1_e_a = c1_eml_ixamax(chartInstance, c1_b_c, c1_c_A, c1_jj);
    c1_jpiv_offset = c1_e_a - 1;
    c1_f_a = c1_jj;
    c1_c_b = c1_jpiv_offset;
    c1_jpiv = c1_f_a + c1_c_b;
    if (c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if ((real_T)c1_jpiv_offset != 0.0) {
        c1_g_a = c1_b_j;
        c1_d_b = c1_jpiv_offset;
        c1_c_c = c1_g_a + c1_d_b;
        c1_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_c_c;
        c1_e_b = c1_jm1;
        c1_jrow = 1 + c1_e_b;
        c1_h_a = c1_jrow;
        c1_f_b = c1_jpiv_offset;
        c1_jprow = c1_h_a + c1_f_b;
        for (c1_i122 = 0; c1_i122 < 16; c1_i122 = c1_i122 + 1) {
          c1_x[c1_i122] = c1_b_A[c1_i122];
        }

        c1_ix0 = c1_jrow;
        c1_iy0 = c1_jprow;
        for (c1_i123 = 0; c1_i123 < 16; c1_i123 = c1_i123 + 1) {
          c1_b_A[c1_i123] = c1_x[c1_i123];
        }

        for (c1_i124 = 0; c1_i124 < 16; c1_i124 = c1_i124 + 1) {
          c1_b_x[c1_i124] = c1_b_A[c1_i124];
        }

        c1_b_ix0 = c1_ix0;
        c1_b_iy0 = c1_iy0;
        for (c1_i125 = 0; c1_i125 < 16; c1_i125 = c1_i125 + 1) {
          c1_c_x[c1_i125] = c1_b_x[c1_i125];
        }

        for (c1_i126 = 0; c1_i126 < 16; c1_i126 = c1_i126 + 1) {
          c1_d_x[c1_i126] = c1_c_x[c1_i126];
        }

        c1_ceval_xswap(chartInstance, 4, c1_d_x, c1_b_ix0, 4, c1_b_iy0, 4,
                       c1_e_x);
        for (c1_i127 = 0; c1_i127 < 16; c1_i127 = c1_i127 + 1) {
          c1_c_x[c1_i127] = c1_e_x[c1_i127];
        }

        for (c1_i128 = 0; c1_i128 < 16; c1_i128 = c1_i128 + 1) {
          c1_b_A[c1_i128] = c1_c_x[c1_i128];
        }
      }

      c1_b_jp1j = c1_jp1j;
      c1_i_a = c1_mmj;
      c1_d_c = c1_i_a - 1;
      c1_j_a = c1_jp1j;
      c1_g_b = c1_d_c;
      c1_loop_ub = c1_j_a + c1_g_b;
      for (c1_i = c1_b_jp1j; c1_i <= c1_loop_ub; c1_i = c1_i + 1) {
        c1_b_i = c1_i;
        c1_f_x = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 16, 1, 0) - 1];
        c1_y = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_jj), 1, 16, 1, 0) - 1];
        c1_g_x = c1_f_x;
        c1_b_y = c1_y;
        c1_z = c1_g_x / c1_b_y;
        c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_i), 1, 16, 1, 0) - 1] = c1_z;
      }
    } else {
      *c1_info = c1_b_j;
    }

    c1_h_b = c1_b_j;
    c1_e_c = 4 - c1_h_b;
    c1_k_a = c1_jj;
    c1_f_c = c1_k_a + 4;
    c1_l_a = c1_jj;
    c1_g_c = c1_l_a + 5;
    c1_m = c1_mmj;
    c1_n = c1_e_c;
    c1_c_ix0 = c1_jp1j;
    c1_c_iy0 = c1_f_c;
    for (c1_i129 = 0; c1_i129 < 16; c1_i129 = c1_i129 + 1) {
      c1_d_A[c1_i129] = c1_b_A[c1_i129];
    }

    c1_ia0 = c1_g_c;
    for (c1_i130 = 0; c1_i130 < 16; c1_i130 = c1_i130 + 1) {
      c1_b_A[c1_i130] = c1_d_A[c1_i130];
    }

    c1_b_m = c1_m;
    c1_b_n = c1_n;
    c1_d_ix0 = c1_c_ix0;
    c1_d_iy0 = c1_c_iy0;
    for (c1_i131 = 0; c1_i131 < 16; c1_i131 = c1_i131 + 1) {
      c1_e_A[c1_i131] = c1_b_A[c1_i131];
    }

    c1_b_ia0 = c1_ia0;
    for (c1_i132 = 0; c1_i132 < 16; c1_i132 = c1_i132 + 1) {
      c1_b_A[c1_i132] = c1_e_A[c1_i132];
    }

    c1_c_m = c1_b_m;
    c1_c_n = c1_b_n;
    c1_e_ix0 = c1_d_ix0;
    c1_e_iy0 = c1_d_iy0;
    for (c1_i133 = 0; c1_i133 < 16; c1_i133 = c1_i133 + 1) {
      c1_f_A[c1_i133] = c1_b_A[c1_i133];
    }

    c1_c_ia0 = c1_b_ia0;
    for (c1_i134 = 0; c1_i134 < 16; c1_i134 = c1_i134 + 1) {
      c1_b_A[c1_i134] = c1_f_A[c1_i134];
    }

    if ((real_T)c1_c_m < 1.0) {
    } else if ((real_T)c1_c_n < 1.0) {
    } else {
      for (c1_i135 = 0; c1_i135 < 16; c1_i135 = c1_i135 + 1) {
        c1_g_A[c1_i135] = c1_b_A[c1_i135];
      }

      c1_ceval_xger(chartInstance, c1_c_m, c1_c_n, -1.0, c1_e_ix0, 1, c1_e_iy0,
                    4, c1_g_A, c1_c_ia0, 4, c1_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c1_info == 0.0) {
    if (!(c1_b_A[15] != 0.0)) {
      *c1_info = 4;
      return;
    }
  }
}

static int32_T c1_eml_ixamax(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[16], int32_T c1_ix0)
{
  int32_T c1_b_n;
  int32_T c1_i136;
  real_T c1_b_x[16];
  int32_T c1_b_ix0;
  int32_T c1_i137;
  real_T c1_c_x[16];
  c1_b_n = c1_n;
  for (c1_i136 = 0; c1_i136 < 16; c1_i136 = c1_i136 + 1) {
    c1_b_x[c1_i136] = c1_x[c1_i136];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i137 = 0; c1_i137 < 16; c1_i137 = c1_i137 + 1) {
    c1_c_x[c1_i137] = c1_b_x[c1_i137];
  }

  return c1_ceval_ixamax(chartInstance, c1_b_n, c1_c_x, c1_b_ix0, 1);
}

static int32_T c1_ceval_ixamax(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[16], int32_T c1_ix0,
  int32_T c1_incx)
{
  return idamax32(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 16, 1, 0) - 1], &
                  c1_incx);
}

static void c1_ceval_xswap(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[16], int32_T c1_ix0,
  int32_T c1_incx, int32_T c1_iy0, int32_T c1_incy, real_T c1_b_x[16])
{
  int32_T c1_i138;

  /* Empty Loop. */
  for (c1_i138 = 0; c1_i138 < 16; c1_i138 = c1_i138 + 1) {
    c1_b_x[c1_i138] = c1_x[c1_i138];
  }

  dswap32(&c1_n, &c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 16, 1, 0) - 1], &c1_incx
          , &c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c1_iy0), 1, 16, 1, 0) - 1], &c1_incy);
}

static void c1_ceval_xger(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T
  c1_ix0, int32_T c1_incx, int32_T c1_iy0, int32_T c1_incy, real_T c1_A[16],
  int32_T c1_ia0, int32_T c1_lda, real_T c1_b_A[16])
{
  int32_T c1_i139;
  for (c1_i139 = 0; c1_i139 < 16; c1_i139 = c1_i139 + 1) {
    c1_b_A[c1_i139] = c1_A[c1_i139];
  }

  dger32(&c1_m, &c1_n, &c1_alpha1, &c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 16, 1,
          0) - 1], &c1_incx, &c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 16, 1, 0) - 1], &
         c1_incy, &c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ia0), 1, 16, 1, 0) - 1], &c1_lda);
}

static void c1_eml_blas_xtrsm(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1,
  real_T c1_A[16], int32_T c1_ia0, int32_T c1_lda, real_T c1_B[16], int32_T
  c1_ib0, int32_T c1_ldb, real_T c1_b_B[16])
{
  int32_T c1_i140;
  int32_T c1_b_m;
  int32_T c1_b_n;
  real_T c1_b_alpha1;
  int32_T c1_i141;
  real_T c1_b_A[16];
  int32_T c1_b_ia0;
  int32_T c1_b_lda;
  int32_T c1_i142;
  real_T c1_c_B[16];
  int32_T c1_b_ib0;
  int32_T c1_b_ldb;
  int32_T c1_i143;
  boolean_T c1_NON_UNIT_ALPHA;
  int32_T c1_a;
  int32_T c1_Aoffset;
  int32_T c1_b_a;
  int32_T c1_Boffset;
  int32_T c1_loop_ub;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_c_a;
  int32_T c1_c;
  int32_T c1_d_a;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_e_a;
  int32_T c1_b_b;
  int32_T c1_jBcol;
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_c_c;
  int32_T c1_c_loop_ub;
  int32_T c1_c_j;
  int32_T c1_g_a;
  int32_T c1_d_c;
  int32_T c1_h_a;
  int32_T c1_d_b;
  int32_T c1_e_c;
  int32_T c1_i_a;
  int32_T c1_e_b;
  int32_T c1_d_loop_ub;
  int32_T c1_c_i;
  int32_T c1_j_a;
  int32_T c1_f_b;
  int32_T c1_f_c;
  int32_T c1_k_a;
  int32_T c1_g_b;
  int32_T c1_g_c;
  int32_T c1_c_m;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_l_a;
  int32_T c1_h_c;
  int32_T c1_m_a;
  int32_T c1_h_b;
  int32_T c1_i_c;
  int32_T c1_n_a;
  int32_T c1_i_b;
  int32_T c1_kAcol;
  int32_T c1_o_a;
  int32_T c1_j_b;
  int32_T c1_j_c;
  int32_T c1_p_a;
  int32_T c1_k_b;
  int32_T c1_k_c;
  int32_T c1_q_a;
  int32_T c1_l_b;
  int32_T c1_l_c;
  int32_T c1_r_a;
  int32_T c1_m_b;
  int32_T c1_m_c;
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_z;
  int32_T c1_s_a;
  int32_T c1_e_loop_ub;
  int32_T c1_d_i;
  int32_T c1_t_a;
  int32_T c1_n_b;
  int32_T c1_n_c;
  int32_T c1_u_a;
  int32_T c1_o_b;
  int32_T c1_o_c;
  int32_T c1_v_a;
  int32_T c1_p_b;
  int32_T c1_p_c;
  int32_T c1_w_a;
  int32_T c1_q_b;
  int32_T c1_q_c;
  for (c1_i140 = 0; c1_i140 < 16; c1_i140 = c1_i140 + 1) {
    c1_b_B[c1_i140] = c1_B[c1_i140];
  }

  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_alpha1 = c1_alpha1;
  for (c1_i141 = 0; c1_i141 < 16; c1_i141 = c1_i141 + 1) {
    c1_b_A[c1_i141] = c1_A[c1_i141];
  }

  c1_b_ia0 = c1_ia0;
  c1_b_lda = c1_lda;
  for (c1_i142 = 0; c1_i142 < 16; c1_i142 = c1_i142 + 1) {
    c1_c_B[c1_i142] = c1_b_B[c1_i142];
  }

  c1_b_ib0 = c1_ib0;
  c1_b_ldb = c1_ldb;
  for (c1_i143 = 0; c1_i143 < 16; c1_i143 = c1_i143 + 1) {
    c1_b_B[c1_i143] = c1_c_B[c1_i143];
  }

  c1_NON_UNIT_ALPHA = (c1_b_alpha1 != 1.0);
  if ((real_T)c1_b_n == 0.0) {
  } else {
    c1_a = c1_b_ia0;
    c1_Aoffset = c1_a - 1;
    c1_b_a = c1_b_ib0;
    c1_Boffset = c1_b_a - 1;
    if (c1_b_alpha1 == 0.0) {
      c1_loop_ub = c1_b_n;
      for (c1_j = 1; c1_j <= c1_loop_ub; c1_j = c1_j + 1) {
        c1_b_j = c1_j;
        c1_c_a = c1_b_j;
        c1_c = c1_c_a - 1;
        c1_d_a = c1_b_ldb;
        c1_b = c1_c;
        c1_b_c = c1_d_a * c1_b;
        c1_e_a = c1_Boffset;
        c1_b_b = c1_b_c;
        c1_jBcol = c1_e_a + c1_b_b;
        c1_b_loop_ub = c1_b_m;
        for (c1_i = 1; c1_i <= c1_b_loop_ub; c1_i = c1_i + 1) {
          c1_b_i = c1_i;
          c1_f_a = c1_b_i;
          c1_c_b = c1_jBcol;
          c1_c_c = c1_f_a + c1_c_b;
          c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_c_c), 1, 16, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c1_c_loop_ub = c1_b_n;
      for (c1_c_j = 1; c1_c_j <= c1_c_loop_ub; c1_c_j = c1_c_j + 1) {
        c1_b_j = c1_c_j;
        c1_g_a = c1_b_j;
        c1_d_c = c1_g_a - 1;
        c1_h_a = c1_b_ldb;
        c1_d_b = c1_d_c;
        c1_e_c = c1_h_a * c1_d_b;
        c1_i_a = c1_Boffset;
        c1_e_b = c1_e_c;
        c1_jBcol = c1_i_a + c1_e_b;
        if (c1_NON_UNIT_ALPHA) {
          c1_d_loop_ub = c1_b_m;
          for (c1_c_i = 1; c1_c_i <= c1_d_loop_ub; c1_c_i = c1_c_i + 1) {
            c1_b_i = c1_c_i;
            c1_j_a = c1_b_i;
            c1_f_b = c1_jBcol;
            c1_f_c = c1_j_a + c1_f_b;
            c1_k_a = c1_b_i;
            c1_g_b = c1_jBcol;
            c1_g_c = c1_k_a + c1_g_b;
            c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_f_c), 1, 16, 1, 0) - 1] = c1_b_alpha1 * c1_b_B[
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_g_c), 1, 16, 1, 0) - 1];
          }
        }

        c1_c_m = c1_b_m;
        for (c1_k = c1_c_m; c1_k > 0; c1_k = c1_k + -1) {
          c1_b_k = c1_k;
          c1_l_a = c1_b_k;
          c1_h_c = c1_l_a - 1;
          c1_m_a = c1_b_lda;
          c1_h_b = c1_h_c;
          c1_i_c = c1_m_a * c1_h_b;
          c1_n_a = c1_Aoffset;
          c1_i_b = c1_i_c;
          c1_kAcol = c1_n_a + c1_i_b;
          c1_o_a = c1_b_k;
          c1_j_b = c1_jBcol;
          c1_j_c = c1_o_a + c1_j_b;
          if (c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
               ("", (real_T)c1_j_c), 1, 16, 1, 0) - 1] != 0.0) {
            c1_p_a = c1_b_k;
            c1_k_b = c1_jBcol;
            c1_k_c = c1_p_a + c1_k_b;
            c1_q_a = c1_b_k;
            c1_l_b = c1_jBcol;
            c1_l_c = c1_q_a + c1_l_b;
            c1_r_a = c1_b_k;
            c1_m_b = c1_kAcol;
            c1_m_c = c1_r_a + c1_m_b;
            c1_x = c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_l_c), 1, 16, 1, 0) - 1];
            c1_y = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_m_c), 1, 16, 1, 0) - 1];
            c1_b_x = c1_x;
            c1_b_y = c1_y;
            c1_z = c1_b_x / c1_b_y;
            c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_k_c), 1, 16, 1, 0) - 1] = c1_z;
            c1_s_a = c1_b_k;
            c1_e_loop_ub = c1_s_a - 1;
            for (c1_d_i = 1; c1_d_i <= c1_e_loop_ub; c1_d_i = c1_d_i + 1) {
              c1_b_i = c1_d_i;
              c1_t_a = c1_b_i;
              c1_n_b = c1_jBcol;
              c1_n_c = c1_t_a + c1_n_b;
              c1_u_a = c1_b_i;
              c1_o_b = c1_jBcol;
              c1_o_c = c1_u_a + c1_o_b;
              c1_v_a = c1_b_k;
              c1_p_b = c1_jBcol;
              c1_p_c = c1_v_a + c1_p_b;
              c1_w_a = c1_b_i;
              c1_q_b = c1_kAcol;
              c1_q_c = c1_w_a + c1_q_b;
              c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c1_n_c), 1, 16, 1, 0) - 1] = c1_b_B[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_o_c), 1, 16, 1, 0) - 1] - c1_b_B[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_p_c), 1, 16, 1, 0) - 1] * c1_b_A[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_q_c), 1, 16, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static real_T c1_norm(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
                      real_T c1_x[16])
{
  real_T c1_y;
  int32_T c1_i144;
  real_T c1_b_x[16];
  real_T c1_j;
  real_T c1_b_j;
  real_T c1_s;
  real_T c1_i;
  real_T c1_b_i;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  real_T c1_e_x;
  boolean_T c1_b;
  for (c1_i144 = 0; c1_i144 < 16; c1_i144 = c1_i144 + 1) {
    c1_b_x[c1_i144] = c1_x[c1_i144];
  }

  c1_y = 0.0;
  c1_j = 1.0;
 label_1:
  ;
  if (c1_j <= 4.0) {
    c1_b_j = c1_j;
    c1_s = 0.0;
    for (c1_i = 1.0; c1_i <= 4.0; c1_i = c1_i + 1.0) {
      c1_b_i = c1_i;
      c1_c_x = c1_b_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_b_i), 1, 4, 1, 0) - 1) + ((
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_j),
        1, 4, 2, 0) - 1) << 2)];
      c1_d_x = c1_c_x;
      c1_b_y = muDoubleScalarAbs(c1_d_x);
      c1_s = c1_s + c1_b_y;
    }

    c1_e_x = c1_s;
    c1_b = muDoubleScalarIsNaN(c1_e_x);
    if (c1_b) {
      return rtNaN;
    } else {
      if (c1_s > c1_y) {
        c1_y = c1_s;
      }

      c1_j = c1_j + 1.0;
      goto label_1;
    }
  }

  return c1_y;
}

static void c1_eml_warning(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance)
{
  int32_T c1_i145;
  static char_T c1_cv2[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c1_u[21];
  const mxArray *c1_y = NULL;
  int32_T c1_i146;
  static char_T c1_cv3[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c1_b_u[40];
  const mxArray *c1_b_y = NULL;
  for (c1_i145 = 0; c1_i145 < 21; c1_i145 = c1_i145 + 1) {
    c1_u[c1_i145] = c1_cv2[c1_i145];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c1_i146 = 0; c1_i146 < 40; c1_i146 = c1_i146 + 1) {
    c1_b_u[c1_i146] = c1_cv3[c1_i146];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_b_eml_warning(SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance,
  real_T c1_varargin_3)
{
  int32_T c1_i147;
  static char_T c1_cv4[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'l', 'l',
    'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e', 'd'
    , 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  int32_T c1_i148;
  static char_T c1_cv5[103] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ',', ' ',
    'c', 'l', 'o', 's', 'e', ' ', 't', 'o', ' ', 's', 'i', 'n', 'g', 'u', 'l',
    'a', 'r', ' ', 'o', 'r',
    ' ', 'b', 'a', 'd', 'l', 'y', ' ', 's', 'c', 'a', 'l', 'e', 'd', '.', '\\',
    'n', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'R', 'e', 's', 'u', 'l', 't', 's', ' ', 'm', 'a',
    'y', ' ', 'b', 'e', ' ',
    'i', 'n', 'a', 'c', 'c', 'u', 'r', 'a', 't', 'e', '.', ' ', 'R', 'C', 'O',
    'N', 'D', ' ', '=', ' ',
    '%', 'e', '.' };

  char_T c1_b_u[103];
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  for (c1_i147 = 0; c1_i147 < 27; c1_i147 = c1_i147 + 1) {
    c1_u[c1_i147] = c1_cv4[c1_i147];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 27));
  for (c1_i148 = 0; c1_i148 < 103; c1_i148 = c1_i148 + 1) {
    c1_b_u[c1_i148] = c1_cv5[c1_i148];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 103));
  c1_c_u = c1_varargin_3;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("warning", 0U, 3U, 14, c1_y, 14, c1_b_y, 14, c1_c_y);
}

static void c1_e_eml_scalar_eg(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i149;
  real_T c1_b_u[4];
  int32_T c1_i150;
  real_T c1_c_u[4];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i149 = 0; c1_i149 < 4; c1_i149 = c1_i149 + 1) {
    c1_b_u[c1_i149] = (*((real_T (*)[4])c1_u))[c1_i149];
  }

  for (c1_i150 = 0; c1_i150 < 4; c1_i150 = c1_i150 + 1) {
    c1_c_u[c1_i150] = c1_b_u[c1_i150];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i151;
  real_T c1_b_u[6];
  int32_T c1_i152;
  real_T c1_c_u[6];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i151 = 0; c1_i151 < 6; c1_i151 = c1_i151 + 1) {
    c1_b_u[c1_i151] = (*((real_T (*)[6])c1_u))[c1_i151];
  }

  for (c1_i152 = 0; c1_i152 < 6; c1_i152 = c1_i152 + 1) {
    c1_c_u[c1_i152] = c1_b_u[c1_i152];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i153;
  real_T c1_b_u[5];
  int32_T c1_i154;
  real_T c1_c_u[5];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i153 = 0; c1_i153 < 5; c1_i153 = c1_i153 + 1) {
    c1_b_u[c1_i153] = (*((real_T (*)[5])c1_u))[c1_i153];
  }

  for (c1_i154 = 0; c1_i154 < 5; c1_i154 = c1_i154 + 1) {
    c1_c_u[c1_i154] = c1_b_u[c1_i154];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i155;
  real_T c1_b_u[4];
  int32_T c1_i156;
  real_T c1_c_u[4];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i155 = 0; c1_i155 < 4; c1_i155 = c1_i155 + 1) {
    c1_b_u[c1_i155] = (*((real_T (*)[4])c1_u))[c1_i155];
  }

  for (c1_i156 = 0; c1_i156 < 4; c1_i156 = c1_i156 + 1) {
    c1_c_u[c1_i156] = c1_b_u[c1_i156];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i157;
  int32_T c1_i158;
  int32_T c1_i159;
  real_T c1_b_u[16];
  int32_T c1_i160;
  int32_T c1_i161;
  int32_T c1_i162;
  real_T c1_c_u[16];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i157 = 0;
  for (c1_i158 = 0; c1_i158 < 4; c1_i158 = c1_i158 + 1) {
    for (c1_i159 = 0; c1_i159 < 4; c1_i159 = c1_i159 + 1) {
      c1_b_u[c1_i159 + c1_i157] = (*((real_T (*)[16])c1_u))[c1_i159 + c1_i157];
    }

    c1_i157 = c1_i157 + 4;
  }

  c1_i160 = 0;
  for (c1_i161 = 0; c1_i161 < 4; c1_i161 = c1_i161 + 1) {
    for (c1_i162 = 0; c1_i162 < 4; c1_i162 = c1_i162 + 1) {
      c1_c_u[c1_i162 + c1_i160] = c1_b_u[c1_i162 + c1_i160];
    }

    c1_i160 = c1_i160 + 4;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i163;
  int32_T c1_i164;
  int32_T c1_i165;
  real_T c1_b_u[9];
  int32_T c1_i166;
  int32_T c1_i167;
  int32_T c1_i168;
  real_T c1_c_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i163 = 0;
  for (c1_i164 = 0; c1_i164 < 3; c1_i164 = c1_i164 + 1) {
    for (c1_i165 = 0; c1_i165 < 3; c1_i165 = c1_i165 + 1) {
      c1_b_u[c1_i165 + c1_i163] = (*((real_T (*)[9])c1_u))[c1_i165 + c1_i163];
    }

    c1_i163 = c1_i163 + 3;
  }

  c1_i166 = 0;
  for (c1_i167 = 0; c1_i167 < 3; c1_i167 = c1_i167 + 1) {
    for (c1_i168 = 0; c1_i168 < 3; c1_i168 = c1_i168 + 1) {
      c1_c_u[c1_i168 + c1_i166] = c1_b_u[c1_i168 + c1_i166];
    }

    c1_i166 = c1_i166 + 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_h_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i169;
  int32_T c1_i170;
  int32_T c1_i171;
  real_T c1_b_u[8];
  int32_T c1_i172;
  int32_T c1_i173;
  int32_T c1_i174;
  real_T c1_c_u[8];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i169 = 0;
  for (c1_i170 = 0; c1_i170 < 2; c1_i170 = c1_i170 + 1) {
    for (c1_i171 = 0; c1_i171 < 4; c1_i171 = c1_i171 + 1) {
      c1_b_u[c1_i171 + c1_i169] = (*((real_T (*)[8])c1_u))[c1_i171 + c1_i169];
    }

    c1_i169 = c1_i169 + 4;
  }

  c1_i172 = 0;
  for (c1_i173 = 0; c1_i173 < 2; c1_i173 = c1_i173 + 1) {
    for (c1_i174 = 0; c1_i174 < 4; c1_i174 = c1_i174 + 1) {
      c1_c_u[c1_i174 + c1_i172] = c1_b_u[c1_i174 + c1_i172];
    }

    c1_i172 = c1_i172 + 4;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 4, 2));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_i_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i175;
  int32_T c1_i176;
  int32_T c1_i177;
  real_T c1_b_u[10];
  int32_T c1_i178;
  int32_T c1_i179;
  int32_T c1_i180;
  real_T c1_c_u[10];
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i175 = 0;
  for (c1_i176 = 0; c1_i176 < 2; c1_i176 = c1_i176 + 1) {
    for (c1_i177 = 0; c1_i177 < 5; c1_i177 = c1_i177 + 1) {
      c1_b_u[c1_i177 + c1_i175] = (*((real_T (*)[10])c1_u))[c1_i177 + c1_i175];
    }

    c1_i175 = c1_i175 + 5;
  }

  c1_i178 = 0;
  for (c1_i179 = 0; c1_i179 < 2; c1_i179 = c1_i179 + 1) {
    for (c1_i180 = 0; c1_i180 < 5; c1_i180 = c1_i180 + 1) {
      c1_c_u[c1_i180 + c1_i178] = c1_b_u[c1_i180 + c1_i178];
    }

    c1_i178 = c1_i178 + 5;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 5, 2));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_DVM_Nikola_test_2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[94];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i181;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 94));
  for (c1_i181 = 0; c1_i181 < 94; c1_i181 = c1_i181 + 1) {
    c1_r0 = &c1_info[c1_i181];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i181);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i181);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i181);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i181);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i181);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c1_i181);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c1_i181);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[94])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileLength = 432U;
  c1_info[0].fileTime1 = 1277780622U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "nargin";
  c1_info[1].dominantType = "";
  c1_info[1].resolved = "[B]nargin";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[2].name = "ge";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[B]ge";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[3].name = "isscalar";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]isscalar";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[4].name = "rdivide";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[4].fileLength = 403U;
  c1_info[4].fileTime1 = 1245134820U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[5].name = "gt";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]gt";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].name = "isa";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]isa";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].name = "eml_div";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[7].fileLength = 4918U;
  c1_info[7].fileTime1 = 1267095810U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[8].name = "isinteger";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]isinteger";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c1_info[9].name = "isreal";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]isreal";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "";
  c1_info[10].name = "mpower";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[10].fileLength = 3710U;
  c1_info[10].fileTime1 = 1238466688U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[11].name = "ndims";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]ndims";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[12].name = "eq";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]eq";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[13].name = "size";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]size";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[14].name = "power";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[14].fileLength = 5380U;
  c1_info[14].fileTime1 = 1228126298U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[15].name = "eml_scalar_eg";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[15].fileLength = 3068U;
  c1_info[15].fileTime1 = 1240294410U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c1_info[16].name = "false";
  c1_info[16].dominantType = "";
  c1_info[16].resolved = "[B]false";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[17].name = "isstruct";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[B]isstruct";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c1_info[18].name = "class";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]class";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c1_info[19].name = "cast";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]cast";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c1_info[20].name = "plus";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]plus";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[21].name = "eml_scalexp_alloc";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[21].fileLength = 932U;
  c1_info[21].fileTime1 = 1261984270U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[22].name = "minus";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[B]minus";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[23].name = "not";
  c1_info[23].dominantType = "logical";
  c1_info[23].resolved = "[B]not";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[24].name = "lt";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[B]lt";
  c1_info[24].fileLength = 0U;
  c1_info[24].fileTime1 = 0U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[25].name = "eml_scalar_floor";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[25].fileLength = 260U;
  c1_info[25].fileTime1 = 1209363190U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[26].name = "ne";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]ne";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[27].name = "eml_error";
  c1_info[27].dominantType = "char";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[27].fileLength = 315U;
  c1_info[27].fileTime1 = 1213959144U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[28].name = "strcmp";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved = "[B]strcmp";
  c1_info[28].fileLength = 0U;
  c1_info[28].fileTime1 = 0U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context = "";
  c1_info[29].name = "mtimes";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[29].fileLength = 3425U;
  c1_info[29].fileTime1 = 1251064272U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "";
  c1_info[30].name = "pi";
  c1_info[30].dominantType = "";
  c1_info[30].resolved = "[B]pi";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "";
  c1_info[31].name = "cos";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[31].fileLength = 324U;
  c1_info[31].fileTime1 = 1203480350U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[32].name = "eml_scalar_cos";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[32].fileLength = 602U;
  c1_info[32].fileTime1 = 1209363186U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "";
  c1_info[33].name = "sin";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[33].fileLength = 324U;
  c1_info[33].fileTime1 = 1203480442U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[34].name = "eml_scalar_sin";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[34].fileLength = 601U;
  c1_info[34].fileTime1 = 1209363190U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "";
  c1_info[35].name = "uminus";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]uminus";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[36].name = "le";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]le";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[37].name = "eml_index_class";
  c1_info[37].dominantType = "";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[37].fileLength = 909U;
  c1_info[37].fileTime1 = 1192499182U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[38].name = "ones";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved = "[B]ones";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[39].name = "isempty";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved = "[B]isempty";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[40].name = "eml_xgemm";
  c1_info[40].dominantType = "int32";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[40].fileLength = 3184U;
  c1_info[40].fileTime1 = 1209363252U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[41].name = "length";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[41].fileLength = 326U;
  c1_info[41].fileTime1 = 1226609674U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[42].name = "min";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[42].fileLength = 362U;
  c1_info[42].fileTime1 = 1245134764U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[43].name = "nargout";
  c1_info[43].dominantType = "";
  c1_info[43].resolved = "[B]nargout";
  c1_info[43].fileLength = 0U;
  c1_info[43].fileTime1 = 0U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[44].name = "eml_min_or_max";
  c1_info[44].dominantType = "char";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[44].fileLength = 9967U;
  c1_info[44].fileTime1 = 1261984270U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[45].name = "ischar";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved = "[B]ischar";
  c1_info[45].fileLength = 0U;
  c1_info[45].fileTime1 = 0U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[46].name = "isnumeric";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved = "[B]isnumeric";
  c1_info[46].fileLength = 0U;
  c1_info[46].fileTime1 = 0U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[47].name = "islogical";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]islogical";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[48].name = "eml_refblas_xgemm";
  c1_info[48].dominantType = "int32";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[48].fileLength = 5748U;
  c1_info[48].fileTime1 = 1228126272U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[49].name = "eml_index_minus";
  c1_info[49].dominantType = "int32";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[49].fileLength = 277U;
  c1_info[49].fileTime1 = 1192499184U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[50].name = "eml_index_times";
  c1_info[50].dominantType = "int32";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[50].fileLength = 280U;
  c1_info[50].fileTime1 = 1192499186U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[51].name = "eml_index_plus";
  c1_info[51].dominantType = "int32";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[51].fileLength = 272U;
  c1_info[51].fileTime1 = 1192499184U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context = "";
  c1_info[52].name = "ctranspose";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved = "[B]ctranspose";
  c1_info[52].fileLength = 0U;
  c1_info[52].fileTime1 = 0U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context = "";
  c1_info[53].name = "atan";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c1_info[53].fileLength = 536U;
  c1_info[53].fileTime1 = 1203480346U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c1_info[54].name = "eml_scalar_atan";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c1_info[54].fileLength = 281U;
  c1_info[54].fileTime1 = 1203480376U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context = "";
  c1_info[55].name = "zeros";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved = "[B]zeros";
  c1_info[55].fileLength = 0U;
  c1_info[55].fileTime1 = 0U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c1_info[56].name = "eml_scalar_abs";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[56].fileLength = 461U;
  c1_info[56].fileTime1 = 1203480360U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c1_info[57].name = "true";
  c1_info[57].dominantType = "";
  c1_info[57].resolved = "[B]true";
  c1_info[57].fileLength = 0U;
  c1_info[57].fileTime1 = 0U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c1_info[58].name = "inv";
  c1_info[58].dominantType = "double";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c1_info[58].fileLength = 4757U;
  c1_info[58].fileTime1 = 1252541208U;
  c1_info[58].fileTime2 = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[59].name = "eml_xgetrf";
  c1_info[59].dominantType = "int32";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[59].fileLength = 204U;
  c1_info[59].fileTime1 = 1271437994U;
  c1_info[59].fileTime2 = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[60].name = "eml_lapack_xgetrf";
  c1_info[60].dominantType = "int32";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[60].fileLength = 211U;
  c1_info[60].fileTime1 = 1271437994U;
  c1_info[60].fileTime2 = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[61].name = "eml_matlab_zgetrf";
  c1_info[61].dominantType = "int32";
  c1_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[61].fileLength = 2193U;
  c1_info[61].fileTime1 = 1271437998U;
  c1_info[61].fileTime2 = 0U;
  c1_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[62].name = "realmin";
  c1_info[62].dominantType = "char";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[62].fileLength = 749U;
  c1_info[62].fileTime1 = 1226609678U;
  c1_info[62].fileTime2 = 0U;
  c1_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[63].name = "eps";
  c1_info[63].dominantType = "char";
  c1_info[63].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[63].fileLength = 1331U;
  c1_info[63].fileTime1 = 1246642112U;
  c1_info[63].fileTime2 = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[94])
{
  c1_info[64].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[64].name = "eml_is_float_class";
  c1_info[64].dominantType = "char";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[64].fileLength = 226U;
  c1_info[64].fileTime1 = 1197882840U;
  c1_info[64].fileTime2 = 0U;
  c1_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[65].name = "colon";
  c1_info[65].dominantType = "int32";
  c1_info[65].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[65].fileLength = 8633U;
  c1_info[65].fileTime1 = 1273876662U;
  c1_info[65].fileTime2 = 0U;
  c1_info[66].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[66].name = "floor";
  c1_info[66].dominantType = "double";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[66].fileLength = 332U;
  c1_info[66].fileTime1 = 1203480422U;
  c1_info[66].fileTime2 = 0U;
  c1_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[67].name = "intmin";
  c1_info[67].dominantType = "char";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[67].fileLength = 1505U;
  c1_info[67].fileTime1 = 1192499128U;
  c1_info[67].fileTime2 = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[68].name = "int32";
  c1_info[68].dominantType = "double";
  c1_info[68].resolved = "[B]int32";
  c1_info[68].fileLength = 0U;
  c1_info[68].fileTime1 = 0U;
  c1_info[68].fileTime2 = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[69].name = "intmax";
  c1_info[69].dominantType = "char";
  c1_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[69].fileLength = 1535U;
  c1_info[69].fileTime1 = 1192499128U;
  c1_info[69].fileTime2 = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c1_info[70].name = "double";
  c1_info[70].dominantType = "int32";
  c1_info[70].resolved = "[B]double";
  c1_info[70].fileLength = 0U;
  c1_info[70].fileTime1 = 0U;
  c1_info[70].fileTime2 = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c1_info[71].name = "transpose";
  c1_info[71].dominantType = "int32";
  c1_info[71].resolved = "[B]transpose";
  c1_info[71].fileLength = 0U;
  c1_info[71].fileTime1 = 0U;
  c1_info[71].fileTime2 = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[72].name = "eml_ixamax";
  c1_info[72].dominantType = "int32";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[72].fileLength = 731U;
  c1_info[72].fileTime1 = 1209363244U;
  c1_info[72].fileTime2 = 0U;
  c1_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[73].name = "eml_refblas_ixamax";
  c1_info[73].dominantType = "int32";
  c1_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[73].fileLength = 740U;
  c1_info[73].fileTime1 = 1192499266U;
  c1_info[73].fileTime2 = 0U;
  c1_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[74].name = "eml_xcabs1";
  c1_info[74].dominantType = "double";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[74].fileLength = 419U;
  c1_info[74].fileTime1 = 1209363246U;
  c1_info[74].fileTime2 = 0U;
  c1_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[75].name = "real";
  c1_info[75].dominantType = "double";
  c1_info[75].resolved = "[B]real";
  c1_info[75].fileLength = 0U;
  c1_info[75].fileTime1 = 0U;
  c1_info[75].fileTime2 = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[76].name = "abs";
  c1_info[76].dominantType = "double";
  c1_info[76].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[76].fileLength = 566U;
  c1_info[76].fileTime1 = 1221299532U;
  c1_info[76].fileTime2 = 0U;
  c1_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[77].name = "imag";
  c1_info[77].dominantType = "double";
  c1_info[77].resolved = "[B]imag";
  c1_info[77].fileLength = 0U;
  c1_info[77].fileTime1 = 0U;
  c1_info[77].fileTime2 = 0U;
  c1_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[78].name = "eml_xswap";
  c1_info[78].dominantType = "int32";
  c1_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[78].fileLength = 1330U;
  c1_info[78].fileTime1 = 1209363260U;
  c1_info[78].fileTime2 = 0U;
  c1_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[79].name = "eml_refblas_xswap";
  c1_info[79].dominantType = "int32";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[79].fileLength = 905U;
  c1_info[79].fileTime1 = 1238466670U;
  c1_info[79].fileTime2 = 0U;
  c1_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[80].name = "eml_xgeru";
  c1_info[80].dominantType = "int32";
  c1_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[80].fileLength = 2462U;
  c1_info[80].fileTime1 = 1209363256U;
  c1_info[80].fileTime2 = 0U;
  c1_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[81].name = "eml_xger";
  c1_info[81].dominantType = "int32";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[81].fileLength = 2168U;
  c1_info[81].fileTime1 = 1209363254U;
  c1_info[81].fileTime2 = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[82].name = "eml_refblas_xger";
  c1_info[82].dominantType = "int32";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[82].fileLength = 411U;
  c1_info[82].fileTime1 = 1211248448U;
  c1_info[82].fileTime2 = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[83].name = "eml_refblas_xgerx";
  c1_info[83].dominantType = "int32";
  c1_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[83].fileLength = 2231U;
  c1_info[83].fileTime1 = 1238466668U;
  c1_info[83].fileTime2 = 0U;
  c1_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[84].name = "times";
  c1_info[84].dominantType = "double";
  c1_info[84].resolved = "[B]times";
  c1_info[84].fileLength = 0U;
  c1_info[84].fileTime1 = 0U;
  c1_info[84].fileTime2 = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[85].name = "eml_ipiv2perm";
  c1_info[85].dominantType = "int32";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c1_info[85].fileLength = 673U;
  c1_info[85].fileTime1 = 1246642112U;
  c1_info[85].fileTime2 = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[86].name = "eml_xtrsm";
  c1_info[86].dominantType = "int32";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[86].fileLength = 2383U;
  c1_info[86].fileTime1 = 1209363262U;
  c1_info[86].fileTime2 = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[87].name = "eml_refblas_xtrsm";
  c1_info[87].dominantType = "int32";
  c1_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[87].fileLength = 13101U;
  c1_info[87].fileTime1 = 1252541206U;
  c1_info[87].fileTime2 = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[88].name = "norm";
  c1_info[88].dominantType = "double";
  c1_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[88].fileLength = 5453U;
  c1_info[88].fileTime1 = 1271438008U;
  c1_info[88].fileTime2 = 0U;
  c1_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[89].name = "isvector";
  c1_info[89].dominantType = "double";
  c1_info[89].resolved = "[B]isvector";
  c1_info[89].fileLength = 0U;
  c1_info[89].fileTime1 = 0U;
  c1_info[89].fileTime2 = 0U;
  c1_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[90].name = "isnan";
  c1_info[90].dominantType = "double";
  c1_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[90].fileLength = 541U;
  c1_info[90].fileTime1 = 1271437988U;
  c1_info[90].fileTime2 = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[91].name = "eml_guarded_nan";
  c1_info[91].dominantType = "char";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[91].fileLength = 485U;
  c1_info[91].fileTime1 = 1192499180U;
  c1_info[91].fileTime2 = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[92].name = "nan";
  c1_info[92].dominantType = "char";
  c1_info[92].resolved = "[B]nan";
  c1_info[92].fileLength = 0U;
  c1_info[92].fileTime1 = 0U;
  c1_info[92].fileTime2 = 0U;
  c1_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[93].name = "eml_warning";
  c1_info[93].dominantType = "char";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[93].fileLength = 262U;
  c1_info[93].fileTime1 = 1236289678U;
  c1_info[93].fileTime2 = 0U;
}

static const mxArray *c1_j_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_k_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, const mxArray *c1_Fout, const char_T *c1_name,
  real_T c1_y[4])
{
  real_T c1_dv12[4];
  int32_T c1_i182;
  sf_mex_import(c1_name, sf_mex_dup(c1_Fout), c1_dv12, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i182 = 0; c1_i182 < 4; c1_i182 = c1_i182 + 1) {
    c1_y[c1_i182] = c1_dv12[c1_i182];
  }

  sf_mex_destroy(&c1_Fout);
}

static void c1_b_emlrt_marshallIn(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, const mxArray *c1_pdot, const char_T *c1_name
  , real_T c1_y[6])
{
  real_T c1_dv13[6];
  int32_T c1_i183;
  sf_mex_import(c1_name, sf_mex_dup(c1_pdot), c1_dv13, 1, 0, 0U, 1, 0U, 1, 6);
  for (c1_i183 = 0; c1_i183 < 6; c1_i183 = c1_i183 + 1) {
    c1_y[c1_i183] = c1_dv13[c1_i183];
  }

  sf_mex_destroy(&c1_pdot);
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance, const mxArray *
  c1_b_is_active_c1_DVM_Nikola_test_2, const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_DVM_Nikola_test_2), &c1_u0,
                1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_DVM_Nikola_test_2);
  return c1_y;
}

static void init_dsm_address_info(SFc1_DVM_Nikola_test_2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_DVM_Nikola_test_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1779129838U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(599632090U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1768808281U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1550604704U);
}

mxArray *sf_c1_DVM_Nikola_test_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1889656123U);
    pr[1] = (double)(3736329906U);
    pr[2] = (double)(1676586326U);
    pr[3] = (double)(1278869370U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_DVM_Nikola_test_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[11],T\"Fout\",},{M[1],M[5],T\"pdot\",},{M[1],M[9],T\"slp_ang\",},{M[8],M[0],T\"is_active_c1_DVM_Nikola_test_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DVM_Nikola_test_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
    chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DVM_Nikola_test_2MachineNumber_,
           1,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_DVM_Nikola_test_2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_DVM_Nikola_test_2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DVM_Nikola_test_2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"p");
          _SFD_SET_DATA_PROPS(1,2,0,1,"pdot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"steer");
          _SFD_SET_DATA_PROPS(3,1,1,0,"torque");
          _SFD_SET_DATA_PROPS(4,1,1,0,"acc_in");
          _SFD_SET_DATA_PROPS(5,2,0,1,"slp_ang");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Fout");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,11001);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_k_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshall);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshall);
        }

        {
          real_T *c1_steer;
          real_T *c1_torque;
          real_T (*c1_p)[6];
          real_T (*c1_pdot)[6];
          real_T (*c1_acc_in)[5];
          real_T (*c1_slp_ang)[4];
          real_T (*c1_Fout)[4];
          c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_acc_in = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
          c1_torque = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_pdot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_p = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_p);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_pdot);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_steer);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_torque);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_acc_in);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_slp_ang);
          _SFD_SET_DATA_VALUE_PTR(6U, *c1_Fout);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_DVM_Nikola_test_2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_DVM_Nikola_test_2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInstanceVar);
  initialize_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_DVM_Nikola_test_2(void *chartInstanceVar)
{
  enable_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_DVM_Nikola_test_2(void *chartInstanceVar)
{
  disable_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_DVM_Nikola_test_2(void *chartInstanceVar)
{
  sf_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_DVM_Nikola_test_2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DVM_Nikola_test_2
    ((SFc1_DVM_Nikola_test_2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_DVM_Nikola_test_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c1_DVM_Nikola_test_2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DVM_Nikola_test_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_DVM_Nikola_test_2(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DVM_Nikola_test_2(S);
}

static void sf_opaque_set_sim_state_c1_DVM_Nikola_test_2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_DVM_Nikola_test_2(S, st);
}

static void sf_opaque_terminate_c1_DVM_Nikola_test_2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DVM_Nikola_test_2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c1_DVM_Nikola_test_2
    ((SFc1_DVM_Nikola_test_2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DVM_Nikola_test_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DVM_Nikola_test_2((SFc1_DVM_Nikola_test_2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DVM_Nikola_test_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"DVM_Nikola_test_2","DVM_Nikola_test_2",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DVM_Nikola_test_2","DVM_Nikola_test_2",
                1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DVM_Nikola_test_2",
      "DVM_Nikola_test_2",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DVM_Nikola_test_2",
        "DVM_Nikola_test_2",1,4);
      sf_mark_chart_reusable_outputs(S,"DVM_Nikola_test_2","DVM_Nikola_test_2",1,
        3);
    }

    sf_set_rtw_dwork_info(S,"DVM_Nikola_test_2","DVM_Nikola_test_2",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3777239144U));
  ssSetChecksum1(S,(2932992506U));
  ssSetChecksum2(S,(3327658505U));
  ssSetChecksum3(S,(70192055U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_DVM_Nikola_test_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DVM_Nikola_test_2", "DVM_Nikola_test_2",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DVM_Nikola_test_2(SimStruct *S)
{
  SFc1_DVM_Nikola_test_2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DVM_Nikola_test_2InstanceStruct *)malloc(sizeof
    (SFc1_DVM_Nikola_test_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DVM_Nikola_test_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_DVM_Nikola_test_2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_DVM_Nikola_test_2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DVM_Nikola_test_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DVM_Nikola_test_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DVM_Nikola_test_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DVM_Nikola_test_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
