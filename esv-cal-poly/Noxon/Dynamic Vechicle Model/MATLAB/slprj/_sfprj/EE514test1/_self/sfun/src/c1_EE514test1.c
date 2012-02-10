/* Include files */

#include "blascompat32.h"
#include "EE514test1_sfun.h"
#include "c1_EE514test1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EE514test1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[164] = { "g", "v_x", "v_y", "phi",
  "phi_d", "psi", "psi_d", "a_x", "a_y", "phi_dd", "psi_dd", "l_fs", "l_rs",
  "t_f", "t_r", "h_f", "h_r", "h_cgs", "h_cguf", "h_cgur", "M", "M_uf", "M_ur",
  "I_xxs", "I_xys", "I_xzs", "I_yys", "I_yzs", "I_zzs", "I_zzuf", "I_zzur",
  "I_tlf", "I_trf", "I_tlr", "I_trr", "K_spf", "K_spr", "B_f", "B_r", "K_rf",
  "K_rr", "K_phif", "K_phir", "K_phi", "B_phif", "B_phir", "B_phi", "K_sr", "L",
  "M_s", "l_cgs", "l_f", "l_r", "M_f", "M_r", "h_o", "h_s", "h_uf", "h_ur",
  "h_cg", "varx", "vary", "varM", "t_wid", "t_rad", "t_pressure", "d_steer",
  "a_sx", "a_sy", "a_ufx", "a_ufy", "a_urx", "a_ury", "ROT", "I_b", "I_c",
  "I_zzus", "I_xxo", "I_zzo", "Fzax", "Fzayf", "Fzayr", "Fzphif", "Fzphir",
  "Fzlf", "Fzrf", "Fzlr", "Fzrr", "v_xlf", "v_ylf", "v_xrf", "v_yrf", "v_xlr",
  "v_ylr", "v_xrr", "v_yrr", "omega_lf", "omega_rf", "omega_lr", "omega_rr",
  "Mtlr", "Mtrr", "delta", "beta", "beta_lf", "beta_rf", "beta_lr", "beta_rr",
  "C_alf", "C_arf", "C_alr", "C_arr", "a_lf", "a_rf", "a_lr", "a_rr", "Fxtlf",
  "Fxtrf", "Fxtlr", "Fxtrr", "Fytlf", "Fytrf", "Fytlr", "Fytrr", "Fxlf", "Fxrf",
  "Fxlr", "Fxrr", "Fylf", "Fyrf", "Fylr", "Fyrr", "Mzlf", "Mzrf", "Mzlr", "Mzrr",
  "alpha_lf_new", "alpha_rf_new", "alpha_lr_new", "alpha_rr_new", "T_phif",
  "T_phir", "sigFx", "sigFy", "sigTxs", "sigTz", "a_x_new", "a_y_new",
  "phi_dd_new", "psi_dd_new", "Mtlf", "Mtrf", "Fxtf", "nargin", "nargout", "p",
  "steer", "torque", "acc_in", "pdot", "slp_ang", "acc_out", "Fout", "sigFout" };

/* Function Declarations */
static void initialize_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance);
static void initialize_params_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance);
static void enable_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance);
static void disable_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_EE514test1(SFc1_EE514test1InstanceStruct *
  chartInstance);
static void set_sim_state_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance);
static void sf_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance);
static void c1_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c1_EE514test1
  (SFc1_EE514test1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_mpower(SFc1_EE514test1InstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_power(SFc1_EE514test1InstanceStruct *chartInstance, real_T c1_a,
  real_T c1_b);
static void c1_eml_scalar_eg(SFc1_EE514test1InstanceStruct *chartInstance);
static void c1_eml_error(SFc1_EE514test1InstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_EE514test1InstanceStruct *chartInstance);
static void c1_eml_xgemm(SFc1_EE514test1InstanceStruct *chartInstance, real_T
  c1_A[9], real_T c1_B[9], real_T c1_C[9], real_T c1_b_C[9]);
static real_T c1_b_mpower(SFc1_EE514test1InstanceStruct *chartInstance, real_T
  c1_a);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_h_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[57]);
static const mxArray *c1_i_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_EE514test1InstanceStruct *chartInstance,
  const mxArray *c1_Fout, const char_T *c1_name, real_T c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_EE514test1InstanceStruct *chartInstance,
  const mxArray *c1_acc_out, const char_T *c1_name, real_T c1_y[5]);
static void c1_c_emlrt_marshallIn(SFc1_EE514test1InstanceStruct *chartInstance,
  const mxArray *c1_pdot, const char_T *c1_name, real_T c1_y[10]);
static uint8_T c1_d_emlrt_marshallIn(SFc1_EE514test1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_EE514test1, const char_T
  *c1_name);
static void init_dsm_address_info(SFc1_EE514test1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_EE514test1 = 0U;
}

static void initialize_params_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance)
{
}

static void enable_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_EE514test1(SFc1_EE514test1InstanceStruct *
  chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_hoistedGlobal[4];
  int32_T c1_i1;
  real_T c1_u[4];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i2;
  real_T c1_b_hoistedGlobal[5];
  int32_T c1_i3;
  real_T c1_b_u[5];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i4;
  real_T c1_c_hoistedGlobal[10];
  int32_T c1_i5;
  real_T c1_c_u[10];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i6;
  real_T c1_d_hoistedGlobal[4];
  int32_T c1_i7;
  real_T c1_d_u[4];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i8;
  real_T c1_e_hoistedGlobal[4];
  int32_T c1_i9;
  real_T c1_e_u[4];
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T (*c1_slp_ang)[4];
  real_T (*c1_sigFout)[4];
  real_T (*c1_pdot)[10];
  real_T (*c1_acc_out)[5];
  real_T (*c1_Fout)[4];
  c1_sigFout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c1_acc_out = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_pdot = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6));
  for (c1_i0 = 0; c1_i0 < 4; c1_i0 = c1_i0 + 1) {
    c1_hoistedGlobal[c1_i0] = (*c1_Fout)[c1_i0];
  }

  for (c1_i1 = 0; c1_i1 < 4; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i2 = 0; c1_i2 < 5; c1_i2 = c1_i2 + 1) {
    c1_b_hoistedGlobal[c1_i2] = (*c1_acc_out)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 5; c1_i3 = c1_i3 + 1) {
    c1_b_u[c1_i3] = c1_b_hoistedGlobal[c1_i3];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i4 = 0; c1_i4 < 10; c1_i4 = c1_i4 + 1) {
    c1_c_hoistedGlobal[c1_i4] = (*c1_pdot)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 10; c1_i5 = c1_i5 + 1) {
    c1_c_u[c1_i5] = c1_c_hoistedGlobal[c1_i5];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 10));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6 = c1_i6 + 1) {
    c1_d_hoistedGlobal[c1_i6] = (*c1_sigFout)[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 4; c1_i7 = c1_i7 + 1) {
    c1_d_u[c1_i7] = c1_d_hoistedGlobal[c1_i7];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i8 = 0; c1_i8 < 4; c1_i8 = c1_i8 + 1) {
    c1_e_hoistedGlobal[c1_i8] = (*c1_slp_ang)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 4; c1_i9 = c1_i9 + 1) {
    c1_e_u[c1_i9] = c1_e_hoistedGlobal[c1_i9];
  }

  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_c1_EE514test1;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_EE514test1(SFc1_EE514test1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i10;
  real_T c1_dv1[5];
  int32_T c1_i11;
  real_T c1_dv2[10];
  int32_T c1_i12;
  real_T c1_dv3[4];
  int32_T c1_i13;
  real_T c1_dv4[4];
  int32_T c1_i14;
  real_T (*c1_pdot)[10];
  real_T (*c1_slp_ang)[4];
  real_T (*c1_sigFout)[4];
  real_T (*c1_acc_out)[5];
  real_T (*c1_Fout)[4];
  c1_sigFout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c1_acc_out = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_pdot = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Fout",
                      c1_dv0);
  for (c1_i10 = 0; c1_i10 < 4; c1_i10 = c1_i10 + 1) {
    (*c1_Fout)[c1_i10] = c1_dv0[c1_i10];
  }

  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "acc_out", c1_dv1);
  for (c1_i11 = 0; c1_i11 < 5; c1_i11 = c1_i11 + 1) {
    (*c1_acc_out)[c1_i11] = c1_dv1[c1_i11];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "pdot", c1_dv2);
  for (c1_i12 = 0; c1_i12 < 10; c1_i12 = c1_i12 + 1) {
    (*c1_pdot)[c1_i12] = c1_dv2[c1_i12];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                      "sigFout", c1_dv3);
  for (c1_i13 = 0; c1_i13 < 4; c1_i13 = c1_i13 + 1) {
    (*c1_sigFout)[c1_i13] = c1_dv3[c1_i13];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                      "slp_ang", c1_dv4);
  for (c1_i14 = 0; c1_i14 < 4; c1_i14 = c1_i14 + 1) {
    (*c1_slp_ang)[c1_i14] = c1_dv4[c1_i14];
  }

  chartInstance->c1_is_active_c1_EE514test1 = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
     "is_active_c1_EE514test1");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_EE514test1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance)
{
}

static void sf_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance)
{
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_previousEvent;
  real_T *c1_steer;
  real_T *c1_torque;
  real_T (*c1_sigFout)[4];
  real_T (*c1_Fout)[4];
  real_T (*c1_acc_out)[5];
  real_T (*c1_slp_ang)[4];
  real_T (*c1_acc_in)[5];
  real_T (*c1_pdot)[10];
  real_T (*c1_p)[10];
  c1_sigFout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c1_acc_out = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_acc_in = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c1_torque = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_pdot = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_p = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  for (c1_i15 = 0; c1_i15 < 10; c1_i15 = c1_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_p)[c1_i15], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_steer, 1U);
  for (c1_i16 = 0; c1_i16 < 10; c1_i16 = c1_i16 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_pdot)[c1_i16], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_torque, 3U);
  for (c1_i17 = 0; c1_i17 < 5; c1_i17 = c1_i17 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_acc_in)[c1_i17], 4U);
  }

  for (c1_i18 = 0; c1_i18 < 4; c1_i18 = c1_i18 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_slp_ang)[c1_i18], 5U);
  }

  for (c1_i19 = 0; c1_i19 < 5; c1_i19 = c1_i19 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_acc_out)[c1_i19], 6U);
  }

  for (c1_i20 = 0; c1_i20 < 4; c1_i20 = c1_i20 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_Fout)[c1_i20], 7U);
  }

  for (c1_i21 = 0; c1_i21 < 4; c1_i21 = c1_i21 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_sigFout)[c1_i21], 8U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_EE514test1(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_EE514test1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_EE514test1(SFc1_EE514test1InstanceStruct *chartInstance)
{
  int32_T c1_i22;
  real_T c1_hoistedGlobal[10];
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  int32_T c1_i23;
  real_T c1_d_hoistedGlobal[5];
  int32_T c1_i24;
  real_T c1_p[10];
  real_T c1_steer;
  real_T c1_torque;
  int32_T c1_i25;
  real_T c1_acc_in[5];
  uint32_T c1_debug_family_var_map[164];
  static const char *c1_sv0[164] = { "g", "v_x", "v_y", "phi", "phi_d", "psi",
    "psi_d", "a_x", "a_y", "phi_dd", "psi_dd", "l_fs",
    "l_rs", "t_f", "t_r", "h_f", "h_r", "h_cgs", "h_cguf", "h_cgur", "M", "M_uf",
    "M_ur", "I_xxs",
    "I_xys", "I_xzs", "I_yys", "I_yzs", "I_zzs", "I_zzuf", "I_zzur", "I_tlf",
    "I_trf", "I_tlr",
    "I_trr", "K_spf", "K_spr", "B_f", "B_r", "K_rf", "K_rr", "K_phif", "K_phir",
    "K_phi", "B_phif",
    "B_phir", "B_phi", "K_sr", "L", "M_s", "l_cgs", "l_f", "l_r", "M_f", "M_r",
    "h_o", "h_s", "h_uf"
    , "h_ur", "h_cg", "varx", "vary", "varM", "t_wid", "t_rad", "t_pressure",
    "d_steer", "a_sx",
    "a_sy", "a_ufx", "a_ufy", "a_urx", "a_ury", "ROT", "I_b", "I_c", "I_zzus",
    "I_xxo", "I_zzo",
    "Fzax", "Fzayf", "Fzayr", "Fzphif", "Fzphir", "Fzlf", "Fzrf", "Fzlr", "Fzrr",
    "v_xlf", "v_ylf",
    "v_xrf", "v_yrf", "v_xlr", "v_ylr", "v_xrr", "v_yrr", "omega_lf", "omega_rf",
    "omega_lr",
    "omega_rr", "Mtlr", "Mtrr", "delta", "beta", "beta_lf", "beta_rf", "beta_lr",
    "beta_rr", "C_alf"
    , "C_arf", "C_alr", "C_arr", "a_lf", "a_rf", "a_lr", "a_rr", "Fxtlf",
    "Fxtrf", "Fxtlr", "Fxtrr",
    "Fytlf", "Fytrf", "Fytlr", "Fytrr", "Fxlf", "Fxrf", "Fxlr", "Fxrr", "Fylf",
    "Fyrf", "Fylr",
    "Fyrr", "Mzlf", "Mzrf", "Mzlr", "Mzrr", "alpha_lf_new", "alpha_rf_new",
    "alpha_lr_new",
    "alpha_rr_new", "T_phif", "T_phir", "sigFx", "sigFy", "sigTxs", "sigTz",
    "a_x_new", "a_y_new",
    "phi_dd_new", "psi_dd_new", "Mtlf", "Mtrf", "Fxtf", "nargin", "nargout", "p",
    "steer", "torque",
    "acc_in", "pdot", "slp_ang", "acc_out", "Fout", "sigFout" };

  real_T c1_g;
  real_T c1_v_x;
  real_T c1_v_y;
  real_T c1_phi;
  real_T c1_phi_d;
  real_T c1_psi;
  real_T c1_psi_d;
  real_T c1_a_x;
  real_T c1_a_y;
  real_T c1_phi_dd;
  real_T c1_psi_dd;
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
  real_T c1_a_sx;
  real_T c1_a_sy;
  real_T c1_a_ufx;
  real_T c1_a_ufy;
  real_T c1_a_urx;
  real_T c1_a_ury;
  real_T c1_ROT[9];
  real_T c1_I_b[9];
  real_T c1_I_c[9];
  real_T c1_I_zzus;
  real_T c1_I_xxo;
  real_T c1_I_zzo;
  real_T c1_Fzax;
  real_T c1_Fzayf;
  real_T c1_Fzayr;
  real_T c1_Fzphif;
  real_T c1_Fzphir;
  real_T c1_Fzlf;
  real_T c1_Fzrf;
  real_T c1_Fzlr;
  real_T c1_Fzrr;
  real_T c1_v_xlf;
  real_T c1_v_ylf;
  real_T c1_v_xrf;
  real_T c1_v_yrf;
  real_T c1_v_xlr;
  real_T c1_v_ylr;
  real_T c1_v_xrr;
  real_T c1_v_yrr;
  real_T c1_omega_lf;
  real_T c1_omega_rf;
  real_T c1_omega_lr;
  real_T c1_omega_rr;
  real_T c1_Mtlr;
  real_T c1_Mtrr;
  real_T c1_delta;
  real_T c1_beta;
  real_T c1_beta_lf;
  real_T c1_beta_rf;
  real_T c1_beta_lr;
  real_T c1_beta_rr;
  real_T c1_C_alf;
  real_T c1_C_arf;
  real_T c1_C_alr;
  real_T c1_C_arr;
  real_T c1_a_lf;
  real_T c1_a_rf;
  real_T c1_a_lr;
  real_T c1_a_rr;
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
  real_T c1_alpha_lf_new;
  real_T c1_alpha_rf_new;
  real_T c1_alpha_lr_new;
  real_T c1_alpha_rr_new;
  real_T c1_T_phif;
  real_T c1_T_phir;
  real_T c1_sigFx;
  real_T c1_sigFy;
  real_T c1_sigTxs;
  real_T c1_sigTz;
  real_T c1_a_x_new;
  real_T c1_a_y_new;
  real_T c1_phi_dd_new;
  real_T c1_psi_dd_new;
  real_T c1_Mtlf;
  real_T c1_Mtrf;
  real_T c1_Fxtf;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 5.0;
  real_T c1_pdot[10];
  real_T c1_slp_ang[4];
  real_T c1_acc_out[5];
  real_T c1_Fout[4];
  real_T c1_sigFout[4];
  int32_T c1_i26;
  int32_T c1_i27;
  static real_T c1_dv5[8] = { 0.0, 0.1, 0.15, 1.0, 0.0, 0.6, 0.85, 0.4 };

  int32_T c1_i28;
  static real_T c1_dv6[10] = { 0.0, 0.08, 0.15, 0.3, 1.0, 0.0, 0.4, 0.6, 0.8,
    0.4 };

  int32_T c1_i29;
  static real_T c1_dv7[8] = { 0.0, 0.1, 0.3, 1.0, 0.0, 0.0005, 0.00025, 0.0 };

  real_T c1_a;
  real_T c1_b;
  real_T c1_y;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_c_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_d_a;
  real_T c1_f_y;
  real_T c1_f_b;
  real_T c1_g_y;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_b;
  real_T c1_h_y;
  real_T c1_e_a;
  real_T c1_h_b;
  real_T c1_i_y;
  real_T c1_i_b;
  real_T c1_j_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_f_a;
  real_T c1_j_b;
  real_T c1_k_y;
  real_T c1_k_b;
  real_T c1_l_y;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_g_a;
  real_T c1_l_b;
  real_T c1_m_y;
  real_T c1_m_b;
  real_T c1_n_y;
  real_T c1_n_b;
  real_T c1_o_y;
  real_T c1_o_b;
  real_T c1_p_y;
  real_T c1_p_b;
  real_T c1_q_y;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  int32_T c1_i30;
  int32_T c1_i31;
  static real_T c1_dv8[3] = { 1.0, 0.0, 0.0 };

  int32_T c1_i32;
  static real_T c1_dv9[9] = { 744.014865523518, 0.0, 21.096972567806741, 0.0,
    2802.6101435242981, 0.0, 21.096972567806741, 0.0,
    2619.8862780007803 };

  int32_T c1_i33;
  real_T c1_h_a[9];
  int32_T c1_i34;
  real_T c1_i_a[9];
  int32_T c1_i35;
  real_T c1_dv10[9];
  int32_T c1_i36;
  real_T c1_dv11[9];
  real_T c1_r_y[9];
  int32_T c1_i37;
  real_T c1_j_a[9];
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  real_T c1_q_b[9];
  int32_T c1_i42;
  real_T c1_k_a[9];
  int32_T c1_i43;
  real_T c1_r_b[9];
  int32_T c1_i44;
  real_T c1_dv12[9];
  real_T c1_dv13[9];
  int32_T c1_i45;
  real_T c1_s_b;
  real_T c1_s_y;
  real_T c1_t_b;
  real_T c1_t_y;
  real_T c1_u_b;
  real_T c1_u_y;
  real_T c1_A;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_v_b;
  real_T c1_w_y;
  real_T c1_w_b;
  real_T c1_x_y;
  real_T c1_x_b;
  real_T c1_y_b;
  real_T c1_y_y;
  real_T c1_ab_b;
  real_T c1_ab_y;
  real_T c1_bb_b;
  real_T c1_cb_b;
  real_T c1_bb_y;
  real_T c1_db_b;
  real_T c1_cb_y;
  real_T c1_eb_b;
  real_T c1_fb_b;
  real_T c1_db_y;
  real_T c1_gb_b;
  real_T c1_eb_y;
  real_T c1_hb_b;
  real_T c1_l_a;
  real_T c1_fb_y;
  real_T c1_b_A;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_fb_x;
  real_T c1_gb_y;
  real_T c1_m_a;
  real_T c1_hb_y;
  real_T c1_n_a;
  real_T c1_ib_y;
  real_T c1_c_A;
  real_T c1_gb_x;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_jb_y;
  real_T c1_o_a;
  real_T c1_kb_y;
  real_T c1_p_a;
  real_T c1_lb_y;
  real_T c1_d_A;
  real_T c1_jb_x;
  real_T c1_kb_x;
  real_T c1_lb_x;
  real_T c1_mb_y;
  real_T c1_q_a;
  real_T c1_nb_y;
  real_T c1_r_a;
  real_T c1_ob_y;
  real_T c1_e_A;
  real_T c1_mb_x;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_pb_y;
  real_T c1_s_a;
  real_T c1_qb_y;
  real_T c1_f_A;
  real_T c1_pb_x;
  real_T c1_qb_x;
  real_T c1_rb_x;
  real_T c1_rb_y;
  real_T c1_t_a;
  real_T c1_g_A;
  real_T c1_sb_x;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_sb_y;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_h_A;
  real_T c1_B;
  real_T c1_xb_x;
  real_T c1_tb_y;
  real_T c1_yb_x;
  real_T c1_ub_y;
  real_T c1_ac_x;
  real_T c1_vb_y;
  real_T c1_wb_y;
  real_T c1_bc_x;
  real_T c1_cc_x;
  real_T c1_i_A;
  real_T c1_b_B;
  real_T c1_dc_x;
  real_T c1_xb_y;
  real_T c1_ec_x;
  real_T c1_yb_y;
  real_T c1_fc_x;
  real_T c1_ac_y;
  real_T c1_bc_y;
  real_T c1_gc_x;
  real_T c1_hc_x;
  real_T c1_j_A;
  real_T c1_c_B;
  real_T c1_ic_x;
  real_T c1_cc_y;
  real_T c1_jc_x;
  real_T c1_dc_y;
  real_T c1_kc_x;
  real_T c1_ec_y;
  real_T c1_fc_y;
  real_T c1_lc_x;
  real_T c1_mc_x;
  real_T c1_k_A;
  real_T c1_d_B;
  real_T c1_nc_x;
  real_T c1_gc_y;
  real_T c1_oc_x;
  real_T c1_hc_y;
  real_T c1_pc_x;
  real_T c1_ic_y;
  real_T c1_jc_y;
  real_T c1_qc_x;
  real_T c1_rc_x;
  real_T c1_ib_b;
  real_T c1_jb_b;
  real_T c1_kb_b;
  real_T c1_lb_b;
  real_T c1_u_a;
  real_T c1_mb_b;
  real_T c1_v_a;
  real_T c1_nb_b;
  real_T c1_w_a;
  real_T c1_ob_b;
  real_T c1_x_a;
  real_T c1_pb_b;
  real_T c1_sc_x;
  real_T c1_tc_x;
  real_T c1_uc_x;
  real_T c1_qb_b;
  real_T c1_kc_y;
  real_T c1_vc_x;
  real_T c1_wc_x;
  real_T c1_xc_x;
  real_T c1_y_a;
  real_T c1_rb_b;
  real_T c1_lc_y;
  real_T c1_yc_x;
  real_T c1_ad_x;
  real_T c1_bd_x;
  real_T c1_sb_b;
  real_T c1_mc_y;
  real_T c1_cd_x;
  real_T c1_dd_x;
  real_T c1_ed_x;
  real_T c1_ab_a;
  real_T c1_tb_b;
  real_T c1_nc_y;
  real_T c1_fd_x;
  real_T c1_gd_x;
  real_T c1_hd_x;
  real_T c1_bb_a;
  real_T c1_ub_b;
  real_T c1_oc_y;
  real_T c1_id_x;
  real_T c1_jd_x;
  real_T c1_kd_x;
  real_T c1_vb_b;
  real_T c1_pc_y;
  real_T c1_ld_x;
  real_T c1_md_x;
  real_T c1_nd_x;
  real_T c1_cb_a;
  real_T c1_wb_b;
  real_T c1_qc_y;
  real_T c1_od_x;
  real_T c1_pd_x;
  real_T c1_qd_x;
  real_T c1_xb_b;
  real_T c1_rc_y;
  real_T c1_yb_b;
  real_T c1_sc_y;
  real_T c1_ac_b;
  real_T c1_tc_y;
  real_T c1_bc_b;
  real_T c1_uc_y;
  real_T c1_cc_b;
  real_T c1_vc_y;
  real_T c1_rd_x;
  real_T c1_sd_x;
  real_T c1_td_x;
  real_T c1_dc_b;
  real_T c1_wc_y;
  real_T c1_ec_b;
  real_T c1_xc_y;
  real_T c1_ud_x;
  real_T c1_vd_x;
  real_T c1_wd_x;
  real_T c1_db_a;
  real_T c1_fc_b;
  real_T c1_yc_y;
  real_T c1_eb_a;
  real_T c1_ad_y;
  real_T c1_fb_a;
  real_T c1_bd_y;
  real_T c1_gc_b;
  real_T c1_cd_y;
  real_T c1_xd_x;
  real_T c1_yd_x;
  real_T c1_ae_x;
  real_T c1_be_x;
  real_T c1_ce_x;
  real_T c1_de_x;
  real_T c1_ee_x;
  real_T c1_fe_x;
  real_T c1_ge_x;
  real_T c1_hc_b;
  real_T c1_dd_y;
  real_T c1_he_x;
  real_T c1_ie_x;
  real_T c1_je_x;
  real_T c1_gb_a;
  real_T c1_ic_b;
  real_T c1_ed_y;
  real_T c1_jc_b;
  real_T c1_fd_y;
  real_T c1_ke_x;
  real_T c1_le_x;
  real_T c1_me_x;
  real_T c1_hb_a;
  real_T c1_kc_b;
  real_T c1_gd_y;
  real_T c1_lc_b;
  real_T c1_hd_y;
  real_T c1_ne_x;
  real_T c1_oe_x;
  real_T c1_pe_x;
  real_T c1_ib_a;
  real_T c1_mc_b;
  real_T c1_id_y;
  real_T c1_nc_b;
  real_T c1_jd_y;
  real_T c1_qe_x;
  real_T c1_re_x;
  real_T c1_se_x;
  real_T c1_te_x;
  real_T c1_ue_x;
  real_T c1_ve_x;
  real_T c1_oc_b;
  real_T c1_kd_y;
  real_T c1_jb_a;
  real_T c1_pc_b;
  real_T c1_ld_y;
  real_T c1_we_x;
  real_T c1_xe_x;
  real_T c1_ye_x;
  real_T c1_qc_b;
  real_T c1_md_y;
  real_T c1_kb_a;
  real_T c1_rc_b;
  real_T c1_nd_y;
  real_T c1_lb_a;
  real_T c1_sc_b;
  real_T c1_od_y;
  real_T c1_af_x;
  real_T c1_bf_x;
  real_T c1_cf_x;
  real_T c1_tc_b;
  real_T c1_pd_y;
  real_T c1_df_x;
  real_T c1_ef_x;
  real_T c1_ff_x;
  real_T c1_mb_a;
  real_T c1_uc_b;
  real_T c1_qd_y;
  real_T c1_nb_a;
  real_T c1_vc_b;
  real_T c1_rd_y;
  real_T c1_gf_x;
  real_T c1_hf_x;
  real_T c1_if_x;
  real_T c1_jf_x;
  real_T c1_kf_x;
  real_T c1_lf_x;
  real_T c1_wc_b;
  real_T c1_sd_y;
  real_T c1_ob_a;
  real_T c1_xc_b;
  real_T c1_td_y;
  real_T c1_mf_x;
  real_T c1_nf_x;
  real_T c1_of_x;
  real_T c1_yc_b;
  real_T c1_ud_y;
  real_T c1_pb_a;
  real_T c1_ad_b;
  real_T c1_vd_y;
  real_T c1_bd_b;
  real_T c1_wd_y;
  real_T c1_pf_x;
  real_T c1_qf_x;
  real_T c1_rf_x;
  real_T c1_qb_a;
  real_T c1_cd_b;
  real_T c1_xd_y;
  real_T c1_sf_x;
  real_T c1_tf_x;
  real_T c1_uf_x;
  real_T c1_dd_b;
  real_T c1_yd_y;
  real_T c1_vf_x;
  real_T c1_wf_x;
  real_T c1_xf_x;
  real_T c1_rb_a;
  real_T c1_ed_b;
  real_T c1_ae_y;
  real_T c1_sb_a;
  real_T c1_fd_b;
  real_T c1_be_y;
  real_T c1_tb_a;
  real_T c1_gd_b;
  real_T c1_ce_y;
  real_T c1_yf_x;
  real_T c1_de_y;
  real_T c1_ag_x;
  real_T c1_ee_y;
  real_T c1_bg_x;
  real_T c1_fe_y;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  real_T *c1_b_torque;
  real_T *c1_b_steer;
  real_T (*c1_b_pdot)[10];
  real_T (*c1_b_sigFout)[4];
  real_T (*c1_b_Fout)[4];
  real_T (*c1_b_acc_out)[5];
  real_T (*c1_b_slp_ang)[4];
  real_T (*c1_b_acc_in)[5];
  real_T (*c1_b_p)[10];
  c1_b_sigFout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_acc_out = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_acc_in = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_torque = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_pdot = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_p = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  for (c1_i22 = 0; c1_i22 < 10; c1_i22 = c1_i22 + 1) {
    c1_hoistedGlobal[c1_i22] = (*c1_b_p)[c1_i22];
  }

  c1_b_hoistedGlobal = *c1_b_steer;
  c1_c_hoistedGlobal = *c1_b_torque;
  for (c1_i23 = 0; c1_i23 < 5; c1_i23 = c1_i23 + 1) {
    c1_d_hoistedGlobal[c1_i23] = (*c1_b_acc_in)[c1_i23];
  }

  for (c1_i24 = 0; c1_i24 < 10; c1_i24 = c1_i24 + 1) {
    c1_p[c1_i24] = c1_hoistedGlobal[c1_i24];
  }

  c1_steer = c1_b_hoistedGlobal;
  c1_torque = c1_c_hoistedGlobal;
  for (c1_i25 = 0; c1_i25 < 5; c1_i25 = c1_i25 + 1) {
    c1_acc_in[c1_i25] = c1_d_hoistedGlobal[c1_i25];
  }

  sf_debug_symbol_scope_push_eml(0U, 164U, 164U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_g, c1_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_v_x, c1_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_v_y, c1_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_phi, c1_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_phi_d, c1_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_psi, c1_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_psi_d, c1_e_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_a_x, c1_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_a_y, c1_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_phi_dd, c1_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_psi_dd, c1_e_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_l_fs, c1_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_l_rs, c1_e_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_t_f, c1_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_t_r, c1_e_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_h_f, c1_e_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_h_r, c1_e_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_h_cgs, c1_e_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_h_cguf, c1_e_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_h_cgur, c1_e_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c1_M, c1_e_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c1_M_uf, c1_e_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c1_M_ur, c1_e_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c1_I_xxs, c1_e_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c1_I_xys, c1_e_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c1_I_xzs, c1_e_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c1_I_yys, c1_e_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c1_I_yzs, c1_e_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzs, c1_e_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzuf, c1_e_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzur, c1_e_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c1_I_tlf, c1_e_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c1_I_trf, c1_e_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c1_I_tlr, c1_e_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c1_I_trr, c1_e_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c1_K_spf, c1_e_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c1_K_spr, c1_e_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c1_B_f, c1_e_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c1_B_r, c1_e_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c1_K_rf, c1_e_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c1_K_rr, c1_e_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c1_K_phif, c1_e_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c1_K_phir, c1_e_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c1_K_phi, c1_e_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c1_B_phif, c1_e_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c1_B_phir, c1_e_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c1_B_phi, c1_e_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c1_K_sr, c1_e_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c1_L, c1_e_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c1_M_s, c1_e_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c1_l_cgs, c1_e_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c1_l_f, c1_e_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c1_l_r, c1_e_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c1_M_f, c1_e_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c1_M_r, c1_e_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c1_h_o, c1_e_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c1_h_s, c1_e_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c1_h_uf, c1_e_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c1_h_ur, c1_e_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c1_h_cg, c1_e_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(c1_varx, c1_g_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(c1_vary, c1_h_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(c1_varM, c1_g_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c1_t_wid, c1_e_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c1_t_rad, c1_e_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(&c1_t_pressure, c1_e_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c1_d_steer, c1_e_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c1_a_sx, c1_e_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c1_a_sy, c1_e_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c1_a_ufx, c1_e_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c1_a_ufy, c1_e_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c1_a_urx, c1_e_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c1_a_ury, c1_e_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(c1_ROT, c1_f_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(c1_I_b, c1_f_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(c1_I_c, c1_f_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzus, c1_e_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c1_I_xxo, c1_e_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c1_I_zzo, c1_e_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c1_Fzax, c1_e_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c1_Fzayf, c1_e_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c1_Fzayr, c1_e_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c1_Fzphif, c1_e_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c1_Fzphir, c1_e_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c1_Fzlf, c1_e_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c1_Fzrf, c1_e_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c1_Fzlr, c1_e_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c1_Fzrr, c1_e_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c1_v_xlf, c1_e_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c1_v_ylf, c1_e_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c1_v_xrf, c1_e_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c1_v_yrf, c1_e_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c1_v_xlr, c1_e_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c1_v_ylr, c1_e_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c1_v_xrr, c1_e_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c1_v_yrr, c1_e_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c1_omega_lf, c1_e_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c1_omega_rf, c1_e_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c1_omega_lr, c1_e_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c1_omega_rr, c1_e_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c1_Mtlr, c1_e_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c1_Mtrr, c1_e_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c1_delta, c1_e_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(&c1_beta, c1_e_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(&c1_beta_lf, c1_e_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(&c1_beta_rf, c1_e_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(&c1_beta_lr, c1_e_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(&c1_beta_rr, c1_e_sf_marshall, 107U);
  sf_debug_symbol_scope_add_eml(&c1_C_alf, c1_e_sf_marshall, 108U);
  sf_debug_symbol_scope_add_eml(&c1_C_arf, c1_e_sf_marshall, 109U);
  sf_debug_symbol_scope_add_eml(&c1_C_alr, c1_e_sf_marshall, 110U);
  sf_debug_symbol_scope_add_eml(&c1_C_arr, c1_e_sf_marshall, 111U);
  sf_debug_symbol_scope_add_eml(&c1_a_lf, c1_e_sf_marshall, 112U);
  sf_debug_symbol_scope_add_eml(&c1_a_rf, c1_e_sf_marshall, 113U);
  sf_debug_symbol_scope_add_eml(&c1_a_lr, c1_e_sf_marshall, 114U);
  sf_debug_symbol_scope_add_eml(&c1_a_rr, c1_e_sf_marshall, 115U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtlf, c1_e_sf_marshall, 116U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtrf, c1_e_sf_marshall, 117U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtlr, c1_e_sf_marshall, 118U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtrr, c1_e_sf_marshall, 119U);
  sf_debug_symbol_scope_add_eml(&c1_Fytlf, c1_e_sf_marshall, 120U);
  sf_debug_symbol_scope_add_eml(&c1_Fytrf, c1_e_sf_marshall, 121U);
  sf_debug_symbol_scope_add_eml(&c1_Fytlr, c1_e_sf_marshall, 122U);
  sf_debug_symbol_scope_add_eml(&c1_Fytrr, c1_e_sf_marshall, 123U);
  sf_debug_symbol_scope_add_eml(&c1_Fxlf, c1_e_sf_marshall, 124U);
  sf_debug_symbol_scope_add_eml(&c1_Fxrf, c1_e_sf_marshall, 125U);
  sf_debug_symbol_scope_add_eml(&c1_Fxlr, c1_e_sf_marshall, 126U);
  sf_debug_symbol_scope_add_eml(&c1_Fxrr, c1_e_sf_marshall, 127U);
  sf_debug_symbol_scope_add_eml(&c1_Fylf, c1_e_sf_marshall, 128U);
  sf_debug_symbol_scope_add_eml(&c1_Fyrf, c1_e_sf_marshall, 129U);
  sf_debug_symbol_scope_add_eml(&c1_Fylr, c1_e_sf_marshall, 130U);
  sf_debug_symbol_scope_add_eml(&c1_Fyrr, c1_e_sf_marshall, 131U);
  sf_debug_symbol_scope_add_eml(&c1_Mzlf, c1_e_sf_marshall, 132U);
  sf_debug_symbol_scope_add_eml(&c1_Mzrf, c1_e_sf_marshall, 133U);
  sf_debug_symbol_scope_add_eml(&c1_Mzlr, c1_e_sf_marshall, 134U);
  sf_debug_symbol_scope_add_eml(&c1_Mzrr, c1_e_sf_marshall, 135U);
  sf_debug_symbol_scope_add_eml(&c1_alpha_lf_new, c1_e_sf_marshall, 136U);
  sf_debug_symbol_scope_add_eml(&c1_alpha_rf_new, c1_e_sf_marshall, 137U);
  sf_debug_symbol_scope_add_eml(&c1_alpha_lr_new, c1_e_sf_marshall, 138U);
  sf_debug_symbol_scope_add_eml(&c1_alpha_rr_new, c1_e_sf_marshall, 139U);
  sf_debug_symbol_scope_add_eml(&c1_T_phif, c1_e_sf_marshall, 140U);
  sf_debug_symbol_scope_add_eml(&c1_T_phir, c1_e_sf_marshall, 141U);
  sf_debug_symbol_scope_add_eml(&c1_sigFx, c1_e_sf_marshall, 142U);
  sf_debug_symbol_scope_add_eml(&c1_sigFy, c1_e_sf_marshall, 143U);
  sf_debug_symbol_scope_add_eml(&c1_sigTxs, c1_e_sf_marshall, 144U);
  sf_debug_symbol_scope_add_eml(&c1_sigTz, c1_e_sf_marshall, 145U);
  sf_debug_symbol_scope_add_eml(&c1_a_x_new, c1_e_sf_marshall, 146U);
  sf_debug_symbol_scope_add_eml(&c1_a_y_new, c1_e_sf_marshall, 147U);
  sf_debug_symbol_scope_add_eml(&c1_phi_dd_new, c1_e_sf_marshall, 148U);
  sf_debug_symbol_scope_add_eml(&c1_psi_dd_new, c1_e_sf_marshall, 149U);
  sf_debug_symbol_scope_add_eml(&c1_Mtlf, c1_e_sf_marshall, 150U);
  sf_debug_symbol_scope_add_eml(&c1_Mtrf, c1_e_sf_marshall, 151U);
  sf_debug_symbol_scope_add_eml(&c1_Fxtf, c1_e_sf_marshall, 152U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_e_sf_marshall, 153U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_e_sf_marshall, 154U);
  sf_debug_symbol_scope_add_eml(c1_p, c1_c_sf_marshall, 155U);
  sf_debug_symbol_scope_add_eml(&c1_steer, c1_e_sf_marshall, 156U);
  sf_debug_symbol_scope_add_eml(&c1_torque, c1_e_sf_marshall, 157U);
  sf_debug_symbol_scope_add_eml(c1_acc_in, c1_d_sf_marshall, 158U);
  sf_debug_symbol_scope_add_eml(c1_pdot, c1_c_sf_marshall, 159U);
  sf_debug_symbol_scope_add_eml(c1_slp_ang, c1_sf_marshall, 160U);
  sf_debug_symbol_scope_add_eml(c1_acc_out, c1_b_sf_marshall, 161U);
  sf_debug_symbol_scope_add_eml(c1_Fout, c1_sf_marshall, 162U);
  sf_debug_symbol_scope_add_eml(c1_sigFout, c1_sf_marshall, 163U);
  CV_EML_FCN(0, 0);

  /* ==output==% */
  _SFD_EML_CALL(0, 4);
  for (c1_i26 = 0; c1_i26 < 10; c1_i26 = c1_i26 + 1) {
    c1_pdot[c1_i26] = 0.0;
  }

  /* ==constants==% */
  _SFD_EML_CALL(0, 7);
  c1_g = 9.81;

  /* m/s^2 */
  /* -------------% */
  /* ==current states==% */
  _SFD_EML_CALL(0, 11);
  c1_v_x = 1.0;
  _SFD_EML_CALL(0, 12);
  c1_v_y = c1_p[1];
  _SFD_EML_CALL(0, 13);
  c1_phi = c1_p[2];
  _SFD_EML_CALL(0, 14);
  c1_phi_d = c1_p[3];
  _SFD_EML_CALL(0, 15);
  c1_psi = c1_p[4];
  _SFD_EML_CALL(0, 16);
  c1_psi_d = c1_p[5];
  _SFD_EML_CALL(0, 18);
  c1_a_x = c1_acc_in[0];
  _SFD_EML_CALL(0, 19);
  c1_a_y = c1_acc_in[1];
  _SFD_EML_CALL(0, 20);
  c1_phi_dd = c1_acc_in[3];
  _SFD_EML_CALL(0, 21);
  c1_psi_dd = c1_acc_in[4];

  /* ------------------% */
  /* Car physical variables */
  _SFD_EML_CALL(0, 25);
  c1_l_fs = 1.01476;

  /* length from sprung mass CG to front suspension */
  _SFD_EML_CALL(0, 26);
  c1_l_rs = 1.67524;

  /* length from sprung mass CG to rear suspension */
  _SFD_EML_CALL(0, 27);
  c1_t_f = 1.54;

  /* front vehicle width */
  _SFD_EML_CALL(0, 28);
  c1_t_r = 1.53;

  /* rear vehicle width */
  _SFD_EML_CALL(0, 29);
  c1_h_f = 0.13;

  /* height from ground to front suspension */
  _SFD_EML_CALL(0, 30);
  c1_h_r = 0.11;

  /* height from ground to rear suspension */
  _SFD_EML_CALL(0, 31);
  c1_h_cgs = 0.567851;

  /* height from ground to sprung CG */
  _SFD_EML_CALL(0, 32);
  c1_h_cguf = 0.32;

  /* height from ground to front unsprung CG */
  _SFD_EML_CALL(0, 33);
  c1_h_cgur = 0.32;

  /* height from ground to rear unsprung CG */
  _SFD_EML_CALL(0, 34);
  c1_M = 1704.7;

  /* total vehicle mass */
  _SFD_EML_CALL(0, 35);
  c1_M_uf = 98.1;

  /* unsprung front mass */
  _SFD_EML_CALL(0, 36);
  c1_M_ur = 79.7;

  /* unsprung rear mass */
  _SFD_EML_CALL(0, 37);
  c1_I_xxs = 440.911;

  /* sprung XX inertia */
  _SFD_EML_CALL(0, 38);
  c1_I_xys = 0.0;

  /* sprung XY inertia */
  _SFD_EML_CALL(0, 39);
  c1_I_xzs = 7.54097;

  /* sprung XZ inertia */
  _SFD_EML_CALL(0, 40);
  c1_I_yys = 2498.9;

  /* sprung YY inertia */
  _SFD_EML_CALL(0, 41);
  c1_I_yzs = 0.0;

  /* sprung yz inertia */
  _SFD_EML_CALL(0, 42);
  c1_I_zzs = 2619.28;

  /* sprung ZZ inertia */
  _SFD_EML_CALL(0, 43);
  c1_I_zzuf = 58.163489999999996;

  /* front unsprung ZZ inertia */
  _SFD_EML_CALL(0, 44);
  c1_I_zzur = 46.6424325;

  /* rear unsprung ZZ inertia */
  _SFD_EML_CALL(0, 45);
  c1_I_tlf = 0.99;

  /* front left tire inertia */
  _SFD_EML_CALL(0, 46);
  c1_I_trf = 0.99;

  /* front right tire inertia */
  _SFD_EML_CALL(0, 47);
  c1_I_tlr = 0.99;

  /* rear left tire inertia */
  _SFD_EML_CALL(0, 48);
  c1_I_trr = 0.99;

  /* rear right tire inertia */
  /* spring/dampers */
  _SFD_EML_CALL(0, 51);
  c1_K_spf = 27.85;

  /* N/mm */
  _SFD_EML_CALL(0, 52);
  c1_K_spr = 18.16;

  /* N/mm */
  _SFD_EML_CALL(0, 54);
  c1_B_f = 2.9915;

  /* N-s/mm */
  _SFD_EML_CALL(0, 55);
  c1_B_r = 2.9915;

  /* N-s/mm */
  /* anti_roll bars */
  _SFD_EML_CALL(0, 58);
  c1_K_rf = 22001.579333023612;

  /* Nm/rad */
  _SFD_EML_CALL(0, 59);
  c1_K_rr = 19732.666464305548;

  /* roll stiffness */
  _SFD_EML_CALL(0, 62);
  c1_K_phif = 47298.369313023613;

  /*  */
  _SFD_EML_CALL(0, 63);
  c1_K_phir = 37310.859108305551;

  /*  */
  _SFD_EML_CALL(0, 64);
  c1_K_phi = c1_K_phif + c1_K_phir;

  /* roll damping */
  _SFD_EML_CALL(0, 67);
  c1_B_phif = 2717.2476562;

  /* Nm-s/rad */
  _SFD_EML_CALL(0, 68);
  c1_B_phir = 2895.6587717249995;
  _SFD_EML_CALL(0, 69);
  c1_B_phi = c1_B_phif + c1_B_phir;
  _SFD_EML_CALL(0, 71);
  c1_K_sr = 15.97;

  /* steering-to-wheel angle ratio */
  /* ==calculated parameters==% */
  _SFD_EML_CALL(0, 74);
  c1_L = 2.6900000000000004;

  /* distance from front to rear suspension */
  _SFD_EML_CALL(0, 75);
  c1_M_s = 1526.9;

  /* sprung mass */
  _SFD_EML_CALL(0, 76);
  c1_l_cgs = 0.019926480905731212;

  /* distance from vehicle CG to sprung CG */
  _SFD_EML_CALL(0, 77);
  c1_l_f = 1.0346864809057312;

  /* distance from vehicle CG to front suspension */
  _SFD_EML_CALL(0, 78);
  c1_l_r = 1.6553135190942689;

  /* distance from vehicle CG to rear suspension */
  _SFD_EML_CALL(0, 79);
  c1_M_f = 1049.0010988847582;

  /* front vehicle mass */
  _SFD_EML_CALL(0, 80);
  c1_M_r = 655.6989011152416;

  /* rear vehicle mass */
  _SFD_EML_CALL(0, 81);
  c1_h_o = 0.12230716371073806;

  /* height from ground to roll axis */
  _SFD_EML_CALL(0, 82);
  c1_h_s = 0.44554383628926192;

  /* height from roll axis to sprung CG */
  _SFD_EML_CALL(0, 83);
  c1_h_uf = 0.19769283628926193;

  /* height from roll axis to front suspension */
  _SFD_EML_CALL(0, 84);
  c1_h_ur = 0.19769283628926193;

  /* height from roll axis to rear suspension */
  _SFD_EML_CALL(0, 85);
  c1_h_cg = 0.542000171232475;

  /* height from gound to vehicle CG */
  /* ----------------------------% */
  /* ==tire properties==% */
  _SFD_EML_CALL(0, 89);
  for (c1_i27 = 0; c1_i27 < 8; c1_i27 = c1_i27 + 1) {
    c1_varx[c1_i27] = c1_dv5[c1_i27];
  }

  /* slip curve coordinates (slip-%, mu) */
  _SFD_EML_CALL(0, 94);
  for (c1_i28 = 0; c1_i28 < 10; c1_i28 = c1_i28 + 1) {
    c1_vary[c1_i28] = c1_dv6[c1_i28];
  }

  /* slip curve coordinates (slip-%, mu)  */
  _SFD_EML_CALL(0, 100);
  for (c1_i29 = 0; c1_i29 < 8; c1_i29 = c1_i29 + 1) {
    c1_varM[c1_i29] = c1_dv7[c1_i29];
  }

  /* slip angle (slip-angle, Moment-arm) */
  /* tire properties */
  _SFD_EML_CALL(0, 108);
  c1_t_wid = 0.175;
  _SFD_EML_CALL(0, 109);
  c1_t_rad = 0.292;
  _SFD_EML_CALL(0, 110);
  c1_t_pressure = 275000.0;

  /* ---------------------% */
  /* ==steering inputs==% */
  _SFD_EML_CALL(0, 115);
  c1_d_steer = c1_steer;

  /* -------------------% */
  /* ==calculate internal accelerations==% */
  _SFD_EML_CALL(0, 119);
  c1_a = c1_psi_d;
  c1_b = c1_v_y;
  c1_y = c1_a * c1_b;
  c1_b_b = c1_phi_d;
  c1_b_y = 0.89108767257852384 * c1_b_b;
  c1_b_a = c1_b_y;
  c1_c_b = c1_psi_d;
  c1_c_y = c1_b_a * c1_c_b;
  c1_x = c1_phi;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_b_x = c1_c_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_a = c1_c_y;
  c1_d_b = c1_b_x;
  c1_d_y = c1_c_a * c1_d_b;
  c1_e_b = c1_mpower(chartInstance, c1_psi_d);
  c1_e_y = 0.019926480905731212 * c1_e_b;
  c1_a_sx = ((c1_a_x - c1_y) - c1_d_y) - c1_e_y;
  _SFD_EML_CALL(0, 123);
  c1_d_a = c1_psi_d;
  c1_f_y = c1_d_a;
  c1_f_b = c1_psi_dd;
  c1_g_y = 0.019926480905731212 * c1_f_b;
  c1_d_x = c1_phi;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_e_x = c1_f_x;
  c1_e_x = muDoubleScalarCos(c1_e_x);
  c1_g_b = c1_e_x;
  c1_h_y = 0.44554383628926192 * c1_g_b;
  c1_e_a = c1_h_y;
  c1_h_b = c1_phi_dd;
  c1_i_y = c1_e_a * c1_h_b;
  c1_i_b = c1_mpower(chartInstance, c1_phi_d);
  c1_j_y = 0.44554383628926192 * c1_i_b;
  c1_g_x = c1_phi;
  c1_h_x = c1_g_x;
  c1_i_x = c1_h_x;
  c1_h_x = c1_i_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_f_a = c1_j_y;
  c1_j_b = c1_h_x;
  c1_k_y = c1_f_a * c1_j_b;
  c1_k_b = c1_mpower(chartInstance, c1_psi_d);
  c1_l_y = 0.44554383628926192 * c1_k_b;
  c1_j_x = c1_phi;
  c1_k_x = c1_j_x;
  c1_l_x = c1_k_x;
  c1_k_x = c1_l_x;
  c1_k_x = muDoubleScalarSin(c1_k_x);
  c1_g_a = c1_l_y;
  c1_l_b = c1_k_x;
  c1_m_y = c1_g_a * c1_l_b;
  c1_a_sy = (((c1_f_y + c1_g_y) + c1_i_y) - c1_k_y) - c1_m_y;
  _SFD_EML_CALL(0, 128);
  c1_m_b = c1_mpower(chartInstance, c1_psi_d);
  c1_n_y = 1.0346864809057312 * c1_m_b;
  c1_a_ufx = c1_a_x - c1_n_y;
  _SFD_EML_CALL(0, 129);
  c1_n_b = c1_psi_dd;
  c1_o_y = 1.0346864809057312 * c1_n_b;
  c1_a_ufy = c1_a_y + c1_o_y;
  _SFD_EML_CALL(0, 130);
  c1_o_b = c1_mpower(chartInstance, c1_psi_d);
  c1_p_y = 1.6553135190942689 * c1_o_b;
  c1_a_urx = c1_a_x + c1_p_y;
  _SFD_EML_CALL(0, 131);
  c1_p_b = c1_psi_dd;
  c1_q_y = 1.6553135190942689 * c1_p_b;
  c1_a_ury = c1_a_y - c1_q_y;

  /* -------------------------------------% */
  /* ==rotation Matrix==% */
  _SFD_EML_CALL(0, 135);
  c1_m_x = c1_phi;
  c1_n_x = c1_m_x;
  c1_o_x = c1_n_x;
  c1_n_x = c1_o_x;
  c1_n_x = muDoubleScalarCos(c1_n_x);
  c1_p_x = c1_phi;
  c1_q_x = c1_p_x;
  c1_r_x = c1_q_x;
  c1_q_x = c1_r_x;
  c1_q_x = muDoubleScalarSin(c1_q_x);
  c1_s_x = c1_phi;
  c1_t_x = c1_s_x;
  c1_u_x = c1_t_x;
  c1_t_x = c1_u_x;
  c1_t_x = muDoubleScalarSin(c1_t_x);
  c1_w_x = c1_phi;
  c1_x_x = c1_w_x;
  c1_y_x = c1_x_x;
  c1_x_x = c1_y_x;
  c1_x_x = muDoubleScalarCos(c1_x_x);
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 3; c1_i31 = c1_i31 + 1) {
    c1_ROT[c1_i30] = c1_dv8[c1_i31];
    c1_i30 = c1_i30 + 3;
  }

  c1_ROT[1] = 0.0;
  c1_ROT[4] = c1_n_x;
  c1_ROT[7] = c1_q_x;
  c1_ROT[2] = 0.0;
  c1_ROT[5] = -c1_t_x;
  c1_ROT[8] = c1_x_x;
  _SFD_EML_CALL(0, 139);
  for (c1_i32 = 0; c1_i32 < 9; c1_i32 = c1_i32 + 1) {
    c1_I_b[c1_i32] = c1_dv9[c1_i32];
  }

  _SFD_EML_CALL(0, 143);
  for (c1_i33 = 0; c1_i33 < 9; c1_i33 = c1_i33 + 1) {
    c1_h_a[c1_i33] = c1_ROT[c1_i33];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i34 = 0; c1_i34 < 9; c1_i34 = c1_i34 + 1) {
    c1_i_a[c1_i34] = c1_h_a[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 9; c1_i35 = c1_i35 + 1) {
    c1_dv10[c1_i35] = c1_dv9[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 9; c1_i36 = c1_i36 + 1) {
    c1_dv11[c1_i36] = 0.0;
  }

  c1_eml_xgemm(chartInstance, c1_i_a, c1_dv10, c1_dv11, c1_r_y);
  for (c1_i37 = 0; c1_i37 < 9; c1_i37 = c1_i37 + 1) {
    c1_j_a[c1_i37] = c1_r_y[c1_i37];
  }

  c1_i38 = 0;
  for (c1_i39 = 0; c1_i39 < 3; c1_i39 = c1_i39 + 1) {
    c1_i40 = 0;
    for (c1_i41 = 0; c1_i41 < 3; c1_i41 = c1_i41 + 1) {
      c1_q_b[c1_i41 + c1_i38] = c1_ROT[c1_i40 + c1_i39];
      c1_i40 = c1_i40 + 3;
    }

    c1_i38 = c1_i38 + 3;
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i42 = 0; c1_i42 < 9; c1_i42 = c1_i42 + 1) {
    c1_k_a[c1_i42] = c1_j_a[c1_i42];
  }

  for (c1_i43 = 0; c1_i43 < 9; c1_i43 = c1_i43 + 1) {
    c1_r_b[c1_i43] = c1_q_b[c1_i43];
  }

  for (c1_i44 = 0; c1_i44 < 9; c1_i44 = c1_i44 + 1) {
    c1_dv12[c1_i44] = 0.0;
  }

  c1_eml_xgemm(chartInstance, c1_k_a, c1_r_b, c1_dv12, c1_dv13);
  for (c1_i45 = 0; c1_i45 < 9; c1_i45 = c1_i45 + 1) {
    c1_I_c[c1_i45] = c1_dv13[c1_i45];
  }

  /* chassis M.o.I. tensor */
  _SFD_EML_CALL(0, 145);
  c1_I_zzus = (323.40652562649871 + c1_I_zzuf) + c1_I_zzur;
  _SFD_EML_CALL(0, 149);
  c1_I_xxo = c1_I_c[0];
  _SFD_EML_CALL(0, 150);
  c1_I_zzo = c1_I_c[8] + c1_I_zzus;

  /* effective I_zz */
  /* ---------------------------------------------% */
  /* ==Dynamic Weight Transfer Forces==% */
  _SFD_EML_CALL(0, 154);
  c1_s_b = c1_a_sx;
  c1_s_y = 680.300883630074 * c1_s_b;
  c1_t_b = c1_a_ufx;
  c1_t_y = 19.393667239976594 * c1_t_b;
  c1_u_b = c1_a_urx;
  c1_u_y = 15.756119052254176 * c1_u_b;
  c1_A = (c1_s_y + c1_t_y) + c1_u_y;
  c1_ab_x = c1_A;
  c1_bb_x = c1_ab_x;
  c1_cb_x = c1_bb_x;
  c1_Fzax = c1_cb_x / 5.3800000000000008;
  _SFD_EML_CALL(0, 155);
  c1_v_b = c1_a_sy;
  c1_w_y = 122.14675375451863 * c1_v_b;
  c1_w_b = c1_a_ufy;
  c1_x_y = 19.393667239976594 * c1_w_b;
  c1_x_b = c1_w_y + c1_x_y;
  c1_Fzayf = 0.64935064935064934 * c1_x_b;
  _SFD_EML_CALL(0, 156);
  c1_y_b = c1_a_sy;
  c1_y_y = 64.604054515407313 * c1_y_b;
  c1_ab_b = c1_a_ury;
  c1_ab_y = 15.756119052254176 * c1_ab_b;
  c1_bb_b = c1_y_y + c1_ab_y;
  c1_Fzayr = 0.65359477124183007 * c1_bb_b;
  _SFD_EML_CALL(0, 157);
  c1_cb_b = c1_phi;
  c1_bb_y = 47298.369313023613 * c1_cb_b;
  c1_db_b = c1_phi_d;
  c1_cb_y = 2717.2476562 * c1_db_b;
  c1_eb_b = c1_bb_y + c1_cb_y;
  c1_Fzphif = -0.64935064935064934 * c1_eb_b;
  _SFD_EML_CALL(0, 158);
  c1_fb_b = c1_phi;
  c1_db_y = 37310.859108305551 * c1_fb_b;
  c1_gb_b = c1_phi_d;
  c1_eb_y = 2895.6587717249995 * c1_gb_b;
  c1_hb_b = c1_db_y + c1_eb_y;
  c1_Fzphir = -0.65359477124183007 * c1_hb_b;

  /* ----------------------------------% */
  /* ==Tire Normal Forces==%  */
  _SFD_EML_CALL(0, 162);
  c1_Fzlf = ((5145.3503900297392 - c1_Fzax) - c1_Fzayf) + c1_Fzphif;
  _SFD_EML_CALL(0, 163);
  c1_Fzrf = ((5145.3503900297392 - c1_Fzax) + c1_Fzayf) - c1_Fzphif;
  _SFD_EML_CALL(0, 164);
  c1_Fzlr = ((3216.2031099702594 + c1_Fzax) - c1_Fzayr) + c1_Fzphir;
  _SFD_EML_CALL(0, 165);
  c1_Fzrr = ((3216.2031099702594 + c1_Fzax) + c1_Fzayr) - c1_Fzphir;

  /* ----------------------% */
  /* ==Tire Longitudinal/Lateral Forces==% */
  /* left front wheel velocity */
  _SFD_EML_CALL(0, 171);
  c1_l_a = c1_psi_d;
  c1_fb_y = c1_l_a * 1.54;
  c1_b_A = c1_fb_y;
  c1_db_x = c1_b_A;
  c1_eb_x = c1_db_x;
  c1_fb_x = c1_eb_x;
  c1_gb_y = c1_fb_x / 2.0;
  c1_v_xlf = c1_v_x + c1_gb_y;
  _SFD_EML_CALL(0, 172);
  c1_m_a = c1_psi_d;
  c1_hb_y = c1_m_a * 1.0346864809057312;
  c1_v_ylf = c1_v_y + c1_hb_y;

  /* right front wheel velocity */
  _SFD_EML_CALL(0, 175);
  c1_n_a = c1_psi_d;
  c1_ib_y = c1_n_a * 1.54;
  c1_c_A = c1_ib_y;
  c1_gb_x = c1_c_A;
  c1_hb_x = c1_gb_x;
  c1_ib_x = c1_hb_x;
  c1_jb_y = c1_ib_x / 2.0;
  c1_v_xrf = c1_v_x - c1_jb_y;
  _SFD_EML_CALL(0, 176);
  c1_o_a = c1_psi_d;
  c1_kb_y = c1_o_a * 1.0346864809057312;
  c1_v_yrf = c1_v_y + c1_kb_y;

  /* left rear wheel velocity */
  _SFD_EML_CALL(0, 179);
  c1_p_a = c1_psi_d;
  c1_lb_y = c1_p_a * 1.53;
  c1_d_A = c1_lb_y;
  c1_jb_x = c1_d_A;
  c1_kb_x = c1_jb_x;
  c1_lb_x = c1_kb_x;
  c1_mb_y = c1_lb_x / 2.0;
  c1_v_xlr = c1_v_x + c1_mb_y;
  _SFD_EML_CALL(0, 180);
  c1_q_a = c1_psi_d;
  c1_nb_y = c1_q_a * 1.6553135190942689;
  c1_v_ylr = c1_v_y - c1_nb_y;

  /* right rear wheel velocity */
  _SFD_EML_CALL(0, 183);
  c1_r_a = c1_psi_d;
  c1_ob_y = c1_r_a * 1.53;
  c1_e_A = c1_ob_y;
  c1_mb_x = c1_e_A;
  c1_nb_x = c1_mb_x;
  c1_ob_x = c1_nb_x;
  c1_pb_y = c1_ob_x / 2.0;
  c1_v_xrr = c1_v_x - c1_pb_y;
  _SFD_EML_CALL(0, 184);
  c1_s_a = c1_psi_d;
  c1_qb_y = c1_s_a * 1.6553135190942689;
  c1_v_yrr = c1_v_y - c1_qb_y;

  /* tire updates */
  _SFD_EML_CALL(0, 187);
  c1_omega_lf = c1_b_mpower(chartInstance, c1_mpower(chartInstance, c1_v_xlf) +
    c1_mpower(chartInstance, c1_v_ylf));
  _SFD_EML_CALL(0, 188);
  c1_omega_rf = c1_b_mpower(chartInstance, c1_mpower(chartInstance, c1_v_xrf) +
    c1_mpower(chartInstance, c1_v_yrf));
  _SFD_EML_CALL(0, 189);
  c1_omega_lr = c1_b_mpower(chartInstance, c1_mpower(chartInstance, c1_v_xlr) +
    c1_mpower(chartInstance, c1_v_ylr));
  _SFD_EML_CALL(0, 190);
  c1_omega_rr = c1_b_mpower(chartInstance, c1_mpower(chartInstance, c1_v_xrr) +
    c1_mpower(chartInstance, c1_v_yrr));

  /* ==Linear Cruise Control=% */
  _SFD_EML_CALL(0, 193);
  CV_EML_IF(0, 0, c1_v_x < 11.1);
  _SFD_EML_CALL(0, 194);
  if (CV_EML_IF(0, 1, c1_omega_lf > c1_omega_rf)) {
    _SFD_EML_CALL(0, 195);
    c1_Mtlf = 2020.0;
    _SFD_EML_CALL(0, 196);
    c1_Mtrf = 0.0;
  } else {
    _SFD_EML_CALL(0, 198);
    c1_Mtlf = 0.0;
    _SFD_EML_CALL(0, 199);
    c1_Mtrf = 2020.0;
  }

  /* The tire moments are unused... */
  _SFD_EML_CALL(0, 207);
  c1_Mtlf = 0.0;
  _SFD_EML_CALL(0, 208);
  c1_Mtrf = 0.0;
  _SFD_EML_CALL(0, 209);
  c1_Mtlr = 0.0;
  _SFD_EML_CALL(0, 210);
  c1_Mtrr = 0.0;

  /* -------------------------% */
  /* get steering angle */
  _SFD_EML_CALL(0, 214);
  c1_f_A = c1_d_steer;
  c1_pb_x = c1_f_A;
  c1_qb_x = c1_pb_x;
  c1_rb_x = c1_qb_x;
  c1_rb_y = c1_rb_x / 2874.6;
  c1_t_a = c1_rb_y;
  c1_delta = c1_t_a * 3.1415926535897931;

  /* radians */
  _SFD_EML_CALL(0, 215);
  c1_g_A = c1_v_y;
  c1_sb_x = c1_g_A;
  c1_tb_x = c1_sb_x;
  c1_ub_x = c1_tb_x;
  c1_sb_y = c1_ub_x;
  c1_vb_x = c1_sb_y;
  c1_beta = c1_vb_x;
  c1_wb_x = c1_beta;
  c1_beta = c1_wb_x;
  c1_beta = muDoubleScalarAtan(c1_beta);
  _SFD_EML_CALL(0, 216);
  c1_h_A = c1_v_ylf;
  c1_B = c1_v_xlf;
  c1_xb_x = c1_h_A;
  c1_tb_y = c1_B;
  c1_yb_x = c1_xb_x;
  c1_ub_y = c1_tb_y;
  c1_ac_x = c1_yb_x;
  c1_vb_y = c1_ub_y;
  c1_wb_y = c1_ac_x / c1_vb_y;
  c1_bc_x = c1_wb_y;
  c1_beta_lf = c1_bc_x;
  c1_cc_x = c1_beta_lf;
  c1_beta_lf = c1_cc_x;
  c1_beta_lf = muDoubleScalarAtan(c1_beta_lf);
  _SFD_EML_CALL(0, 217);
  c1_i_A = c1_v_yrf;
  c1_b_B = c1_v_xrf;
  c1_dc_x = c1_i_A;
  c1_xb_y = c1_b_B;
  c1_ec_x = c1_dc_x;
  c1_yb_y = c1_xb_y;
  c1_fc_x = c1_ec_x;
  c1_ac_y = c1_yb_y;
  c1_bc_y = c1_fc_x / c1_ac_y;
  c1_gc_x = c1_bc_y;
  c1_beta_rf = c1_gc_x;
  c1_hc_x = c1_beta_rf;
  c1_beta_rf = c1_hc_x;
  c1_beta_rf = muDoubleScalarAtan(c1_beta_rf);
  _SFD_EML_CALL(0, 218);
  c1_j_A = c1_v_ylr;
  c1_c_B = c1_v_xlr;
  c1_ic_x = c1_j_A;
  c1_cc_y = c1_c_B;
  c1_jc_x = c1_ic_x;
  c1_dc_y = c1_cc_y;
  c1_kc_x = c1_jc_x;
  c1_ec_y = c1_dc_y;
  c1_fc_y = c1_kc_x / c1_ec_y;
  c1_lc_x = c1_fc_y;
  c1_beta_lr = c1_lc_x;
  c1_mc_x = c1_beta_lr;
  c1_beta_lr = c1_mc_x;
  c1_beta_lr = muDoubleScalarAtan(c1_beta_lr);
  _SFD_EML_CALL(0, 219);
  c1_k_A = c1_v_yrr;
  c1_d_B = c1_v_xrr;
  c1_nc_x = c1_k_A;
  c1_gc_y = c1_d_B;
  c1_oc_x = c1_nc_x;
  c1_hc_y = c1_gc_y;
  c1_pc_x = c1_oc_x;
  c1_ic_y = c1_hc_y;
  c1_jc_y = c1_pc_x / c1_ic_y;
  c1_qc_x = c1_jc_y;
  c1_beta_rr = c1_qc_x;
  c1_rc_x = c1_beta_rr;
  c1_beta_rr = c1_rc_x;
  c1_beta_rr = muDoubleScalarAtan(c1_beta_rr);

  /* Interpolate forces */
  /* Linearized Force Coefficients (C_alpha) */
  _SFD_EML_CALL(0, 223);
  c1_ib_b = c1_Fzlf;
  c1_C_alf = 5.0 * c1_ib_b;
  _SFD_EML_CALL(0, 224);
  c1_jb_b = c1_Fzrf;
  c1_C_arf = 5.0 * c1_jb_b;
  _SFD_EML_CALL(0, 225);
  c1_kb_b = c1_Fzlr;
  c1_C_alr = 5.0 * c1_kb_b;
  _SFD_EML_CALL(0, 226);
  c1_lb_b = c1_Fzrr;
  c1_C_arr = 5.0 * c1_lb_b;
  _SFD_EML_CALL(0, 228);
  c1_a_lf = c1_beta_lf - c1_delta;
  _SFD_EML_CALL(0, 229);
  c1_a_rf = c1_beta_rf - c1_delta;
  _SFD_EML_CALL(0, 230);
  c1_a_lr = c1_beta_lr;
  _SFD_EML_CALL(0, 231);
  c1_a_rr = c1_beta_rr;
  _SFD_EML_CALL(0, 233);
  c1_slp_ang[0] = c1_C_alf;
  c1_slp_ang[1] = c1_C_arf;
  c1_slp_ang[2] = c1_C_alr;
  c1_slp_ang[3] = c1_C_arr;

  /* Linear Cruise Control for constant v_x */
  _SFD_EML_CALL(0, 236);
  CV_EML_IF(0, 2, c1_v_x < 11.1);
  _SFD_EML_CALL(0, 237);
  c1_Fxtf = 202000.0;
  _SFD_EML_CALL(0, 242);
  c1_Fxtlf = 0.0;
  _SFD_EML_CALL(0, 243);
  c1_Fxtrf = 0.0;
  _SFD_EML_CALL(0, 244);
  c1_Fxtlr = 0.0;
  _SFD_EML_CALL(0, 245);
  c1_Fxtrr = 0.0;
  _SFD_EML_CALL(0, 247);
  c1_u_a = -c1_a_lf;
  c1_mb_b = c1_C_alf;
  c1_Fytlf = c1_u_a * c1_mb_b;
  _SFD_EML_CALL(0, 248);
  c1_v_a = -c1_a_rf;
  c1_nb_b = c1_C_arf;
  c1_Fytrf = c1_v_a * c1_nb_b;
  _SFD_EML_CALL(0, 249);
  c1_w_a = -c1_a_lr;
  c1_ob_b = c1_C_alr;
  c1_Fytlr = c1_w_a * c1_ob_b;
  _SFD_EML_CALL(0, 250);
  c1_x_a = -c1_a_rr;
  c1_pb_b = c1_C_arr;
  c1_Fytrr = c1_x_a * c1_pb_b;
  _SFD_EML_CALL(0, 253);
  c1_sc_x = c1_delta;
  c1_tc_x = c1_sc_x;
  c1_uc_x = c1_tc_x;
  c1_tc_x = c1_uc_x;
  c1_tc_x = muDoubleScalarCos(c1_tc_x);
  c1_qb_b = c1_tc_x;
  c1_kc_y = 0.0 * c1_qb_b;
  c1_vc_x = c1_delta;
  c1_wc_x = c1_vc_x;
  c1_xc_x = c1_wc_x;
  c1_wc_x = c1_xc_x;
  c1_wc_x = muDoubleScalarSin(c1_wc_x);
  c1_y_a = c1_Fytlf;
  c1_rb_b = c1_wc_x;
  c1_lc_y = c1_y_a * c1_rb_b;
  c1_Fxlf = c1_kc_y - c1_lc_y;
  _SFD_EML_CALL(0, 254);
  c1_yc_x = c1_delta;
  c1_ad_x = c1_yc_x;
  c1_bd_x = c1_ad_x;
  c1_ad_x = c1_bd_x;
  c1_ad_x = muDoubleScalarCos(c1_ad_x);
  c1_sb_b = c1_ad_x;
  c1_mc_y = 0.0 * c1_sb_b;
  c1_cd_x = c1_delta;
  c1_dd_x = c1_cd_x;
  c1_ed_x = c1_dd_x;
  c1_dd_x = c1_ed_x;
  c1_dd_x = muDoubleScalarSin(c1_dd_x);
  c1_ab_a = c1_Fytrf;
  c1_tb_b = c1_dd_x;
  c1_nc_y = c1_ab_a * c1_tb_b;
  c1_Fxrf = c1_mc_y - c1_nc_y;
  _SFD_EML_CALL(0, 255);
  c1_Fxlr = 0.0;
  _SFD_EML_CALL(0, 256);
  c1_Fxrr = 0.0;
  _SFD_EML_CALL(0, 258);
  c1_fd_x = c1_delta;
  c1_gd_x = c1_fd_x;
  c1_hd_x = c1_gd_x;
  c1_gd_x = c1_hd_x;
  c1_gd_x = muDoubleScalarCos(c1_gd_x);
  c1_bb_a = c1_Fytlf;
  c1_ub_b = c1_gd_x;
  c1_oc_y = c1_bb_a * c1_ub_b;
  c1_id_x = c1_delta;
  c1_jd_x = c1_id_x;
  c1_kd_x = c1_jd_x;
  c1_jd_x = c1_kd_x;
  c1_jd_x = muDoubleScalarSin(c1_jd_x);
  c1_vb_b = c1_jd_x;
  c1_pc_y = 0.0 * c1_vb_b;
  c1_Fylf = c1_oc_y + c1_pc_y;
  _SFD_EML_CALL(0, 259);
  c1_ld_x = c1_delta;
  c1_md_x = c1_ld_x;
  c1_nd_x = c1_md_x;
  c1_md_x = c1_nd_x;
  c1_md_x = muDoubleScalarCos(c1_md_x);
  c1_cb_a = c1_Fytrf;
  c1_wb_b = c1_md_x;
  c1_qc_y = c1_cb_a * c1_wb_b;
  c1_od_x = c1_delta;
  c1_pd_x = c1_od_x;
  c1_qd_x = c1_pd_x;
  c1_pd_x = c1_qd_x;
  c1_pd_x = muDoubleScalarSin(c1_pd_x);
  c1_xb_b = c1_pd_x;
  c1_rc_y = 0.0 * c1_xb_b;
  c1_Fyrf = c1_qc_y + c1_rc_y;
  _SFD_EML_CALL(0, 260);
  c1_Fylr = c1_Fytlr;
  _SFD_EML_CALL(0, 261);
  c1_Fyrr = c1_Fytrr;
  _SFD_EML_CALL(0, 263);
  c1_Fout[0] = c1_Fytlf;
  c1_Fout[1] = c1_Fytrf;
  c1_Fout[2] = c1_Fytlr;
  c1_Fout[3] = c1_Fytrr;

  /* The tire moments are unused here... */
  _SFD_EML_CALL(0, 267);
  c1_Mzlf = 0.0;
  _SFD_EML_CALL(0, 268);
  c1_Mzrf = 0.0;
  _SFD_EML_CALL(0, 269);
  c1_Mzlr = 0.0;
  _SFD_EML_CALL(0, 270);
  c1_Mzrr = 0.0;

  /* ---------------------------------------% */
  /* Omeaga/Alpha of Wheels */
  _SFD_EML_CALL(0, 274);
  c1_alpha_lf_new = 0.0;
  _SFD_EML_CALL(0, 275);
  c1_alpha_rf_new = 0.0;
  _SFD_EML_CALL(0, 276);
  c1_alpha_lr_new = 0.0;
  _SFD_EML_CALL(0, 277);
  c1_alpha_rr_new = 0.0;

  /*  alpha_lf_new = 0; */
  /*  alpha_rf_new = 0; */
  /*  alpha_lr_new = 0; */
  /*  alpha_rr_new = 0; */
  /* ==Torques==% */
  _SFD_EML_CALL(0, 286);
  c1_yb_b = c1_phi;
  c1_sc_y = -47298.369313023613 * c1_yb_b;
  c1_ac_b = c1_phi_d;
  c1_tc_y = 2717.2476562 * c1_ac_b;
  c1_T_phif = c1_sc_y - c1_tc_y;
  _SFD_EML_CALL(0, 287);
  c1_bc_b = c1_phi;
  c1_uc_y = -37310.859108305551 * c1_bc_b;
  c1_cc_b = c1_phi_d;
  c1_vc_y = 2895.6587717249995 * c1_cc_b;
  c1_T_phir = c1_uc_y - c1_vc_y;

  /* -----------% */
  /* ==Sum forces and torques==% */
  _SFD_EML_CALL(0, 291);
  c1_sigFx = ((c1_Fxlf + c1_Fxrf) + c1_Fxlr) + c1_Fxrr;
  _SFD_EML_CALL(0, 292);
  c1_sigFy = ((c1_Fylf + c1_Fyrf) + c1_Fylr) + c1_Fyrr;
  _SFD_EML_CALL(0, 293);
  c1_rd_x = c1_phi;
  c1_sd_x = c1_rd_x;
  c1_td_x = c1_sd_x;
  c1_sd_x = c1_td_x;
  c1_sd_x = muDoubleScalarSin(c1_sd_x);
  c1_dc_b = c1_sd_x;
  c1_wc_y = 6673.7516684110269 * c1_dc_b;
  c1_ec_b = c1_a_sy;
  c1_xc_y = 680.300883630074 * c1_ec_b;
  c1_ud_x = c1_phi;
  c1_vd_x = c1_ud_x;
  c1_wd_x = c1_vd_x;
  c1_vd_x = c1_wd_x;
  c1_vd_x = muDoubleScalarCos(c1_vd_x);
  c1_db_a = c1_xc_y;
  c1_fc_b = c1_vd_x;
  c1_yc_y = c1_db_a * c1_fc_b;
  c1_sigTxs = ((c1_T_phif + c1_T_phir) - c1_wc_y) + c1_yc_y;
  _SFD_EML_CALL(0, 295);
  c1_eb_a = c1_Fylf + c1_Fyrf;
  c1_ad_y = c1_eb_a * 1.0346864809057312;
  c1_fb_a = c1_Fylr + c1_Fyrr;
  c1_bd_y = c1_fb_a * 1.6553135190942689;
  c1_gc_b = c1_Fxlf - c1_Fxrf;
  c1_cd_y = 0.77 * c1_gc_b;
  c1_sigTz = (((((c1_ad_y - c1_bd_y) + c1_cd_y) + c1_Mzlf) + c1_Mzrf) + c1_Mzlr)
    + c1_Mzrr;
  _SFD_EML_CALL(0, 299);
  c1_sigFout[0] = c1_sigFx;
  c1_sigFout[1] = c1_sigFy;
  c1_sigFout[2] = c1_sigTxs;
  c1_sigFout[3] = c1_sigTz;

  /* --------------------------% */
  /* ==Update independent variables==% */
  _SFD_EML_CALL(0, 304);
  c1_xd_x = c1_phi;
  c1_yd_x = c1_xd_x;
  c1_ae_x = c1_yd_x;
  c1_yd_x = c1_ae_x;
  c1_yd_x = muDoubleScalarCos(c1_yd_x);
  c1_be_x = c1_phi;
  c1_ce_x = c1_be_x;
  c1_de_x = c1_ce_x;
  c1_ce_x = c1_de_x;
  c1_ce_x = muDoubleScalarSin(c1_ce_x);
  c1_ee_x = c1_sigFx + c1_M_s * (-0.89108767257852384 * c1_phi_d * c1_psi_d *
    c1_yd_x - c1_h_s * c1_psi_dd * c1_ce_x);
  c1_fe_x = c1_ee_x;
  c1_ge_x = c1_fe_x;
  c1_a_x_new = c1_ge_x / 1704.7;
  _SFD_EML_CALL(0, 307);
  c1_hc_b = c1_phi_dd;
  c1_dd_y = -0.44554383628926192 * c1_hc_b;
  c1_he_x = c1_phi;
  c1_ie_x = c1_he_x;
  c1_je_x = c1_ie_x;
  c1_ie_x = c1_je_x;
  c1_ie_x = muDoubleScalarCos(c1_ie_x);
  c1_gb_a = c1_dd_y;
  c1_ic_b = c1_ie_x;
  c1_ed_y = c1_gb_a * c1_ic_b;
  c1_jc_b = c1_mpower(chartInstance, c1_phi_d);
  c1_fd_y = 0.44554383628926192 * c1_jc_b;
  c1_ke_x = c1_phi;
  c1_le_x = c1_ke_x;
  c1_me_x = c1_le_x;
  c1_le_x = c1_me_x;
  c1_le_x = muDoubleScalarSin(c1_le_x);
  c1_hb_a = c1_fd_y;
  c1_kc_b = c1_le_x;
  c1_gd_y = c1_hb_a * c1_kc_b;
  c1_lc_b = c1_mpower(chartInstance, c1_psi_d);
  c1_hd_y = 0.44554383628926192 * c1_lc_b;
  c1_ne_x = c1_phi;
  c1_oe_x = c1_ne_x;
  c1_pe_x = c1_oe_x;
  c1_oe_x = c1_pe_x;
  c1_oe_x = muDoubleScalarSin(c1_oe_x);
  c1_ib_a = c1_hd_y;
  c1_mc_b = c1_oe_x;
  c1_id_y = c1_ib_a * c1_mc_b;
  c1_nc_b = (c1_ed_y + c1_gd_y) + c1_id_y;
  c1_jd_y = 1526.9 * c1_nc_b;
  c1_qe_x = c1_sigFy - c1_jd_y;
  c1_re_x = c1_qe_x;
  c1_se_x = c1_re_x;
  c1_a_y_new = c1_se_x / 1704.7;
  _SFD_EML_CALL(0, 311);
  c1_te_x = c1_phi;
  c1_ue_x = c1_te_x;
  c1_ve_x = c1_ue_x;
  c1_ue_x = c1_ve_x;
  c1_ue_x = muDoubleScalarCos(c1_ue_x);
  c1_oc_b = c1_ue_x;
  c1_kd_y = 21.096972567806741 * c1_oc_b;
  c1_jb_a = c1_kd_y;
  c1_pc_b = c1_psi_dd;
  c1_ld_y = c1_jb_a * c1_pc_b;
  c1_we_x = c1_phi;
  c1_xe_x = c1_we_x;
  c1_ye_x = c1_xe_x;
  c1_xe_x = c1_ye_x;
  c1_xe_x = muDoubleScalarSin(c1_xe_x);
  c1_qc_b = c1_xe_x;
  c1_md_y = 21.096972567806741 * c1_qc_b;
  c1_kb_a = c1_md_y;
  c1_rc_b = c1_phi_d;
  c1_nd_y = c1_kb_a * c1_rc_b;
  c1_lb_a = c1_nd_y;
  c1_sc_b = c1_psi_d;
  c1_od_y = c1_lb_a * c1_sc_b;
  c1_af_x = c1_phi;
  c1_bf_x = c1_af_x;
  c1_cf_x = c1_bf_x;
  c1_bf_x = c1_cf_x;
  c1_bf_x = muDoubleScalarSin(c1_bf_x);
  c1_tc_b = c1_bf_x;
  c1_pd_y = -182.72386552351787 * c1_tc_b;
  c1_df_x = c1_phi;
  c1_ef_x = c1_df_x;
  c1_ff_x = c1_ef_x;
  c1_ef_x = c1_ff_x;
  c1_ef_x = muDoubleScalarCos(c1_ef_x);
  c1_mb_a = c1_pd_y;
  c1_uc_b = c1_ef_x;
  c1_qd_y = c1_mb_a * c1_uc_b;
  c1_nb_a = c1_qd_y;
  c1_vc_b = c1_mpower(chartInstance, c1_psi_d);
  c1_rd_y = c1_nb_a * c1_vc_b;
  c1_gf_x = ((c1_sigTxs - c1_ld_y) + c1_od_y) + c1_rd_y;
  c1_hf_x = c1_gf_x;
  c1_if_x = c1_hf_x;
  c1_phi_dd_new = c1_if_x / 744.014865523518;
  _SFD_EML_CALL(0, 316);
  c1_jf_x = c1_phi;
  c1_kf_x = c1_jf_x;
  c1_lf_x = c1_kf_x;
  c1_kf_x = c1_lf_x;
  c1_kf_x = muDoubleScalarCos(c1_kf_x);
  c1_wc_b = c1_kf_x;
  c1_sd_y = 21.096972567806741 * c1_wc_b;
  c1_ob_a = c1_sd_y;
  c1_xc_b = c1_phi_dd;
  c1_td_y = c1_ob_a * c1_xc_b;
  c1_mf_x = c1_phi;
  c1_nf_x = c1_mf_x;
  c1_of_x = c1_nf_x;
  c1_nf_x = c1_of_x;
  c1_nf_x = muDoubleScalarSin(c1_nf_x);
  c1_yc_b = c1_nf_x;
  c1_ud_y = 21.096972567806741 * c1_yc_b;
  c1_pb_a = c1_ud_y;
  c1_ad_b = c1_mpower(chartInstance, c1_phi_d);
  c1_vd_y = c1_pb_a * c1_ad_b;
  c1_bd_b = c1_a_x;
  c1_wd_y = 680.300883630074 * c1_bd_b;
  c1_pf_x = c1_phi;
  c1_qf_x = c1_pf_x;
  c1_rf_x = c1_qf_x;
  c1_qf_x = c1_rf_x;
  c1_qf_x = muDoubleScalarSin(c1_qf_x);
  c1_qb_a = c1_wd_y;
  c1_cd_b = c1_qf_x;
  c1_xd_y = c1_qb_a * c1_cd_b;
  c1_sf_x = c1_phi;
  c1_tf_x = c1_sf_x;
  c1_uf_x = c1_tf_x;
  c1_tf_x = c1_uf_x;
  c1_tf_x = muDoubleScalarSin(c1_tf_x);
  c1_dd_b = c1_tf_x;
  c1_yd_y = -182.72386552351787 * c1_dd_b;
  c1_vf_x = c1_phi;
  c1_wf_x = c1_vf_x;
  c1_xf_x = c1_wf_x;
  c1_wf_x = c1_xf_x;
  c1_wf_x = muDoubleScalarCos(c1_wf_x);
  c1_rb_a = c1_yd_y;
  c1_ed_b = c1_wf_x;
  c1_ae_y = c1_rb_a * c1_ed_b;
  c1_sb_a = c1_ae_y;
  c1_fd_b = c1_psi_d;
  c1_be_y = c1_sb_a * c1_fd_b;
  c1_tb_a = c1_be_y;
  c1_gd_b = c1_phi_d;
  c1_ce_y = c1_tb_a * c1_gd_b;
  c1_yf_x = (((c1_sigTz - c1_td_y) - c1_vd_y) - c1_xd_y) - c1_ce_y;
  c1_de_y = c1_I_zzo;
  c1_ag_x = c1_yf_x;
  c1_ee_y = c1_de_y;
  c1_bg_x = c1_ag_x;
  c1_fe_y = c1_ee_y;
  c1_psi_dd_new = c1_bg_x / c1_fe_y;

  /* acceleration outputs */
  _SFD_EML_CALL(0, 324);
  c1_acc_out[0] = c1_a_x_new;
  c1_acc_out[1] = c1_a_y_new;
  c1_acc_out[2] = c1_a_sy;
  c1_acc_out[3] = c1_phi_dd_new;
  c1_acc_out[4] = c1_psi_dd_new;

  /* X */
  _SFD_EML_CALL(0, 327);
  c1_pdot[0] = c1_a_x_new;

  /* Y    */
  _SFD_EML_CALL(0, 329);
  c1_pdot[1] = c1_a_y_new;

  /* PHI */
  _SFD_EML_CALL(0, 331);
  c1_pdot[2] = c1_phi_d;
  _SFD_EML_CALL(0, 332);
  c1_pdot[3] = c1_phi_dd_new;

  /* PSI */
  _SFD_EML_CALL(0, 334);
  c1_pdot[4] = c1_psi_d;
  _SFD_EML_CALL(0, 335);
  c1_pdot[5] = c1_psi_dd_new;

  /* WHEELS */
  _SFD_EML_CALL(0, 337);
  c1_pdot[6] = c1_alpha_lf_new;
  _SFD_EML_CALL(0, 338);
  c1_pdot[7] = c1_alpha_rf_new;
  _SFD_EML_CALL(0, 339);
  c1_pdot[8] = c1_alpha_lr_new;
  _SFD_EML_CALL(0, 340);
  c1_pdot[9] = c1_alpha_rr_new;

  /* SPRUNG BODY */
  /* ----------------------------------% */
  /* end */
  /* nd */
  /* d */
  /*  */
  _SFD_EML_CALL(0, -340);
  sf_debug_symbol_scope_pop();
  for (c1_i46 = 0; c1_i46 < 10; c1_i46 = c1_i46 + 1) {
    (*c1_b_pdot)[c1_i46] = c1_pdot[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 4; c1_i47 = c1_i47 + 1) {
    (*c1_b_slp_ang)[c1_i47] = c1_slp_ang[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 5; c1_i48 = c1_i48 + 1) {
    (*c1_b_acc_out)[c1_i48] = c1_acc_out[c1_i48];
  }

  for (c1_i49 = 0; c1_i49 < 4; c1_i49 = c1_i49 + 1) {
    (*c1_b_Fout)[c1_i49] = c1_Fout[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 4; c1_i50 = c1_i50 + 1) {
    (*c1_b_sigFout)[c1_i50] = c1_sigFout[c1_i50];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
}

static void compInitSubchartSimstructsFcn_c1_EE514test1
  (SFc1_EE514test1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_mpower(SFc1_EE514test1InstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 2.0);
}

static real_T c1_power(SFc1_EE514test1InstanceStruct *chartInstance, real_T c1_a,
  real_T c1_b)
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

static void c1_eml_scalar_eg(SFc1_EE514test1InstanceStruct *chartInstance)
{
}

static void c1_eml_error(SFc1_EE514test1InstanceStruct *chartInstance)
{
  int32_T c1_i51;
  static char_T c1_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  int32_T c1_i52;
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
  for (c1_i51 = 0; c1_i51 < 32; c1_i51 = c1_i51 + 1) {
    c1_u[c1_i51] = c1_cv0[c1_i51];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c1_i52 = 0; c1_i52 < 102; c1_i52 = c1_i52 + 1) {
    c1_b_u[c1_i52] = c1_cv1[c1_i52];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_b_eml_scalar_eg(SFc1_EE514test1InstanceStruct *chartInstance)
{
}

static void c1_eml_xgemm(SFc1_EE514test1InstanceStruct *chartInstance, real_T
  c1_A[9], real_T c1_B[9], real_T c1_C[9], real_T c1_b_C
  [9])
{
  int32_T c1_i53;
  real_T c1_b_A[9];
  int32_T c1_i54;
  real_T c1_b_B[9];
  int32_T c1_i55;
  real_T c1_c_A[9];
  int32_T c1_i56;
  real_T c1_c_B[9];
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  for (c1_i53 = 0; c1_i53 < 9; c1_i53 = c1_i53 + 1) {
    c1_b_A[c1_i53] = c1_A[c1_i53];
  }

  for (c1_i54 = 0; c1_i54 < 9; c1_i54 = c1_i54 + 1) {
    c1_b_B[c1_i54] = c1_B[c1_i54];
  }

  for (c1_i55 = 0; c1_i55 < 9; c1_i55 = c1_i55 + 1) {
    c1_c_A[c1_i55] = c1_b_A[c1_i55];
  }

  for (c1_i56 = 0; c1_i56 < 9; c1_i56 = c1_i56 + 1) {
    c1_c_B[c1_i56] = c1_b_B[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 3; c1_i57 = c1_i57 + 1) {
    c1_i58 = 0;
    for (c1_i59 = 0; c1_i59 < 3; c1_i59 = c1_i59 + 1) {
      c1_b_C[c1_i58 + c1_i57] = 0.0;
      c1_i60 = 0;
      for (c1_i61 = 0; c1_i61 < 3; c1_i61 = c1_i61 + 1) {
        c1_b_C[c1_i58 + c1_i57] = c1_b_C[c1_i58 + c1_i57] + c1_c_A[c1_i60 +
          c1_i57] * c1_c_B[c1_i61 + c1_i58];
        c1_i60 = c1_i60 + 3;
      }

      c1_i58 = c1_i58 + 3;
    }
  }
}

static real_T c1_b_mpower(SFc1_EE514test1InstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 0.5);
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i62;
  real_T c1_b_u[4];
  int32_T c1_i63;
  real_T c1_c_u[4];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i62 = 0; c1_i62 < 4; c1_i62 = c1_i62 + 1) {
    c1_b_u[c1_i62] = (*((real_T (*)[4])c1_u))[c1_i62];
  }

  for (c1_i63 = 0; c1_i63 < 4; c1_i63 = c1_i63 + 1) {
    c1_c_u[c1_i63] = c1_b_u[c1_i63];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i64;
  real_T c1_b_u[5];
  int32_T c1_i65;
  real_T c1_c_u[5];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i64 = 0; c1_i64 < 5; c1_i64 = c1_i64 + 1) {
    c1_b_u[c1_i64] = (*((real_T (*)[5])c1_u))[c1_i64];
  }

  for (c1_i65 = 0; c1_i65 < 5; c1_i65 = c1_i65 + 1) {
    c1_c_u[c1_i65] = c1_b_u[c1_i65];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i66;
  real_T c1_b_u[10];
  int32_T c1_i67;
  real_T c1_c_u[10];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i66 = 0; c1_i66 < 10; c1_i66 = c1_i66 + 1) {
    c1_b_u[c1_i66] = (*((real_T (*)[10])c1_u))[c1_i66];
  }

  for (c1_i67 = 0; c1_i67 < 10; c1_i67 = c1_i67 + 1) {
    c1_c_u[c1_i67] = c1_b_u[c1_i67];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 10));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i68;
  real_T c1_b_u[5];
  int32_T c1_i69;
  real_T c1_c_u[5];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i68 = 0; c1_i68 < 5; c1_i68 = c1_i68 + 1) {
    c1_b_u[c1_i68] = (*((real_T (*)[5])c1_u))[c1_i68];
  }

  for (c1_i69 = 0; c1_i69 < 5; c1_i69 = c1_i69 + 1) {
    c1_c_u[c1_i69] = c1_b_u[c1_i69];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 5));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  real_T c1_b_u[9];
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  real_T c1_c_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i70 = 0;
  for (c1_i71 = 0; c1_i71 < 3; c1_i71 = c1_i71 + 1) {
    for (c1_i72 = 0; c1_i72 < 3; c1_i72 = c1_i72 + 1) {
      c1_b_u[c1_i72 + c1_i70] = (*((real_T (*)[9])c1_u))[c1_i72 + c1_i70];
    }

    c1_i70 = c1_i70 + 3;
  }

  c1_i73 = 0;
  for (c1_i74 = 0; c1_i74 < 3; c1_i74 = c1_i74 + 1) {
    for (c1_i75 = 0; c1_i75 < 3; c1_i75 = c1_i75 + 1) {
      c1_c_u[c1_i75 + c1_i73] = c1_b_u[c1_i75 + c1_i73];
    }

    c1_i73 = c1_i73 + 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  real_T c1_b_u[8];
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_i81;
  real_T c1_c_u[8];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i76 = 0;
  for (c1_i77 = 0; c1_i77 < 2; c1_i77 = c1_i77 + 1) {
    for (c1_i78 = 0; c1_i78 < 4; c1_i78 = c1_i78 + 1) {
      c1_b_u[c1_i78 + c1_i76] = (*((real_T (*)[8])c1_u))[c1_i78 + c1_i76];
    }

    c1_i76 = c1_i76 + 4;
  }

  c1_i79 = 0;
  for (c1_i80 = 0; c1_i80 < 2; c1_i80 = c1_i80 + 1) {
    for (c1_i81 = 0; c1_i81 < 4; c1_i81 = c1_i81 + 1) {
      c1_c_u[c1_i81 + c1_i79] = c1_b_u[c1_i81 + c1_i79];
    }

    c1_i79 = c1_i79 + 4;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 4, 2));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_h_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  real_T c1_b_u[10];
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  real_T c1_c_u[10];
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i82 = 0;
  for (c1_i83 = 0; c1_i83 < 2; c1_i83 = c1_i83 + 1) {
    for (c1_i84 = 0; c1_i84 < 5; c1_i84 = c1_i84 + 1) {
      c1_b_u[c1_i84 + c1_i82] = (*((real_T (*)[10])c1_u))[c1_i84 + c1_i82];
    }

    c1_i82 = c1_i82 + 5;
  }

  c1_i85 = 0;
  for (c1_i86 = 0; c1_i86 < 2; c1_i86 = c1_i86 + 1) {
    for (c1_i87 = 0; c1_i87 < 5; c1_i87 = c1_i87 + 1) {
      c1_c_u[c1_i87 + c1_i85] = c1_b_u[c1_i87 + c1_i85];
    }

    c1_i85 = c1_i85 + 5;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 5, 2));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_EE514test1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[57];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i88;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 57));
  for (c1_i88 = 0; c1_i88 < 57; c1_i88 = c1_i88 + 1) {
    c1_r0 = &c1_info[c1_i88];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i88
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i88
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[57])
{
  c1_info[0].context = "";
  c1_info[0].name = "zeros";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]zeros";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "mrdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].fileLength = 432U;
  c1_info[1].fileTime1 = 1277780622U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[2].name = "nargin";
  c1_info[2].dominantType = "";
  c1_info[2].resolved = "[B]nargin";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[3].name = "ge";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]ge";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[4].name = "isscalar";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]isscalar";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[5].name = "rdivide";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[5].fileLength = 403U;
  c1_info[5].fileTime1 = 1245134820U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].name = "gt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]gt";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].name = "isa";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]isa";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[8].name = "eml_div";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[8].fileLength = 4918U;
  c1_info[8].fileTime1 = 1267095810U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[9].name = "isinteger";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]isinteger";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c1_info[10].name = "isreal";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]isreal";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "";
  c1_info[11].name = "mpower";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[11].fileLength = 3710U;
  c1_info[11].fileTime1 = 1238466688U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[12].name = "ndims";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]ndims";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[13].name = "eq";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]eq";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[14].name = "size";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]size";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[15].name = "power";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[15].fileLength = 5380U;
  c1_info[15].fileTime1 = 1228126298U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[16].name = "eml_scalar_eg";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[16].fileLength = 3068U;
  c1_info[16].fileTime1 = 1240294410U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c1_info[17].name = "false";
  c1_info[17].dominantType = "";
  c1_info[17].resolved = "[B]false";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[18].name = "isstruct";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]isstruct";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c1_info[19].name = "class";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]class";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c1_info[20].name = "cast";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]cast";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c1_info[21].name = "plus";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved = "[B]plus";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[22].name = "eml_scalexp_alloc";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[22].fileLength = 932U;
  c1_info[22].fileTime1 = 1261984270U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[23].name = "minus";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[B]minus";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[24].name = "not";
  c1_info[24].dominantType = "logical";
  c1_info[24].resolved = "[B]not";
  c1_info[24].fileLength = 0U;
  c1_info[24].fileTime1 = 0U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[25].name = "lt";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved = "[B]lt";
  c1_info[25].fileLength = 0U;
  c1_info[25].fileTime1 = 0U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[26].name = "eml_scalar_floor";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[26].fileLength = 260U;
  c1_info[26].fileTime1 = 1209363190U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[27].name = "ne";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]ne";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[28].name = "eml_error";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[28].fileLength = 315U;
  c1_info[28].fileTime1 = 1213959144U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[29].name = "strcmp";
  c1_info[29].dominantType = "char";
  c1_info[29].resolved = "[B]strcmp";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "";
  c1_info[30].name = "mtimes";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[30].fileLength = 3425U;
  c1_info[30].fileTime1 = 1251064272U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "";
  c1_info[31].name = "pi";
  c1_info[31].dominantType = "";
  c1_info[31].resolved = "[B]pi";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "";
  c1_info[32].name = "cos";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[32].fileLength = 324U;
  c1_info[32].fileTime1 = 1203480350U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[33].name = "eml_scalar_cos";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[33].fileLength = 602U;
  c1_info[33].fileTime1 = 1209363186U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "";
  c1_info[34].name = "sin";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[34].fileLength = 324U;
  c1_info[34].fileTime1 = 1203480442U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[35].name = "eml_scalar_sin";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[35].fileLength = 601U;
  c1_info[35].fileTime1 = 1209363190U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context = "";
  c1_info[36].name = "uminus";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]uminus";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[37].name = "le";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved = "[B]le";
  c1_info[37].fileLength = 0U;
  c1_info[37].fileTime1 = 0U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[38].name = "eml_index_class";
  c1_info[38].dominantType = "";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[38].fileLength = 909U;
  c1_info[38].fileTime1 = 1192499182U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[39].name = "ones";
  c1_info[39].dominantType = "char";
  c1_info[39].resolved = "[B]ones";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[40].name = "isempty";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved = "[B]isempty";
  c1_info[40].fileLength = 0U;
  c1_info[40].fileTime1 = 0U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[41].name = "eml_xgemm";
  c1_info[41].dominantType = "int32";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[41].fileLength = 3184U;
  c1_info[41].fileTime1 = 1209363252U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[42].name = "length";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[42].fileLength = 326U;
  c1_info[42].fileTime1 = 1226609674U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[43].name = "min";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[43].fileLength = 362U;
  c1_info[43].fileTime1 = 1245134764U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[44].name = "nargout";
  c1_info[44].dominantType = "";
  c1_info[44].resolved = "[B]nargout";
  c1_info[44].fileLength = 0U;
  c1_info[44].fileTime1 = 0U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[45].name = "eml_min_or_max";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[45].fileLength = 9967U;
  c1_info[45].fileTime1 = 1261984270U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[46].name = "ischar";
  c1_info[46].dominantType = "char";
  c1_info[46].resolved = "[B]ischar";
  c1_info[46].fileLength = 0U;
  c1_info[46].fileTime1 = 0U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[47].name = "isnumeric";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]isnumeric";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[48].name = "islogical";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[B]islogical";
  c1_info[48].fileLength = 0U;
  c1_info[48].fileTime1 = 0U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[49].name = "eml_refblas_xgemm";
  c1_info[49].dominantType = "int32";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[49].fileLength = 5748U;
  c1_info[49].fileTime1 = 1228126272U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[50].name = "eml_index_minus";
  c1_info[50].dominantType = "int32";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[50].fileLength = 277U;
  c1_info[50].fileTime1 = 1192499184U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[51].name = "eml_index_times";
  c1_info[51].dominantType = "int32";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[51].fileLength = 280U;
  c1_info[51].fileTime1 = 1192499186U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[52].name = "eml_index_plus";
  c1_info[52].dominantType = "int32";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[52].fileLength = 272U;
  c1_info[52].fileTime1 = 1192499184U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context = "";
  c1_info[53].name = "ctranspose";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved = "[B]ctranspose";
  c1_info[53].fileLength = 0U;
  c1_info[53].fileTime1 = 0U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context = "";
  c1_info[54].name = "atan";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c1_info[54].fileLength = 536U;
  c1_info[54].fileTime1 = 1203480346U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c1_info[55].name = "eml_scalar_atan";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c1_info[55].fileLength = 281U;
  c1_info[55].fileTime1 = 1203480376U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context = "";
  c1_info[56].name = "times";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved = "[B]times";
  c1_info[56].fileLength = 0U;
  c1_info[56].fileTime1 = 0U;
  c1_info[56].fileTime2 = 0U;
}

static const mxArray *c1_i_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_EE514test1InstanceStruct *chartInstance,
  const mxArray *c1_Fout, const char_T *c1_name, real_T
  c1_y[4])
{
  real_T c1_dv14[4];
  int32_T c1_i89;
  sf_mex_import(c1_name, sf_mex_dup(c1_Fout), c1_dv14, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i89 = 0; c1_i89 < 4; c1_i89 = c1_i89 + 1) {
    c1_y[c1_i89] = c1_dv14[c1_i89];
  }

  sf_mex_destroy(&c1_Fout);
}

static void c1_b_emlrt_marshallIn(SFc1_EE514test1InstanceStruct *chartInstance,
  const mxArray *c1_acc_out, const char_T *c1_name,
  real_T c1_y[5])
{
  real_T c1_dv15[5];
  int32_T c1_i90;
  sf_mex_import(c1_name, sf_mex_dup(c1_acc_out), c1_dv15, 1, 0, 0U, 1, 0U, 2, 1,
                5);
  for (c1_i90 = 0; c1_i90 < 5; c1_i90 = c1_i90 + 1) {
    c1_y[c1_i90] = c1_dv15[c1_i90];
  }

  sf_mex_destroy(&c1_acc_out);
}

static void c1_c_emlrt_marshallIn(SFc1_EE514test1InstanceStruct *chartInstance,
  const mxArray *c1_pdot, const char_T *c1_name,
  real_T c1_y[10])
{
  real_T c1_dv16[10];
  int32_T c1_i91;
  sf_mex_import(c1_name, sf_mex_dup(c1_pdot), c1_dv16, 1, 0, 0U, 1, 0U, 1, 10);
  for (c1_i91 = 0; c1_i91 < 10; c1_i91 = c1_i91 + 1) {
    c1_y[c1_i91] = c1_dv16[c1_i91];
  }

  sf_mex_destroy(&c1_pdot);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_EE514test1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_EE514test1,
  const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_EE514test1), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_EE514test1);
  return c1_y;
}

static void init_dsm_address_info(SFc1_EE514test1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_EE514test1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2765137401U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(648568438U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1954387271U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1878614454U);
}

mxArray *sf_c1_EE514test1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2094787625U);
    pr[1] = (double)(3647800096U);
    pr[2] = (double)(3967178185U);
    pr[3] = (double)(1046627340U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
      pr[1] = (double)(5);
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
      pr[0] = (double)(1);
      pr[1] = (double)(4);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_EE514test1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[11],T\"Fout\",},{M[1],M[10],T\"acc_out\",},{M[1],M[5],T\"pdot\",},{M[1],M[12],T\"sigFout\",},{M[1],M[9],T\"slp_ang\",},{M[8],M[0],T\"is_active_c1_EE514test1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_EE514test1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_EE514test1InstanceStruct *chartInstance;
    chartInstance = (SFc1_EE514test1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EE514test1MachineNumber_,
           1,
           1,
           1,
           9,
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
          init_script_number_translation(_EE514test1MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_EE514test1MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EE514test1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"p");
          _SFD_SET_DATA_PROPS(1,1,1,0,"steer");
          _SFD_SET_DATA_PROPS(2,2,0,1,"pdot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"torque");
          _SFD_SET_DATA_PROPS(4,1,1,0,"acc_in");
          _SFD_SET_DATA_PROPS(5,2,0,1,"slp_ang");
          _SFD_SET_DATA_PROPS(6,2,0,1,"acc_out");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Fout");
          _SFD_SET_DATA_PROPS(8,2,0,1,"sigFout");
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,9174);
        _SFD_CV_INIT_EML_IF(0,0,5704,5717,5864,5900);
        _SFD_CV_INIT_EML_IF(0,1,5722,5744,5800,5863);
        _SFD_CV_INIT_EML_IF(0,2,6564,6577,6607,6640);
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
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshall);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshall);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshall);
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
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshall);
        }

        {
          real_T *c1_steer;
          real_T *c1_torque;
          real_T (*c1_p)[10];
          real_T (*c1_pdot)[10];
          real_T (*c1_acc_in)[5];
          real_T (*c1_slp_ang)[4];
          real_T (*c1_acc_out)[5];
          real_T (*c1_Fout)[4];
          real_T (*c1_sigFout)[4];
          c1_sigFout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
          c1_Fout = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
          c1_acc_out = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_slp_ang = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_acc_in = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
          c1_torque = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_pdot = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_p = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_p);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_steer);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_pdot);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_torque);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_acc_in);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_slp_ang);
          _SFD_SET_DATA_VALUE_PTR(6U, *c1_acc_out);
          _SFD_SET_DATA_VALUE_PTR(7U, *c1_Fout);
          _SFD_SET_DATA_VALUE_PTR(8U, *c1_sigFout);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EE514test1MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_EE514test1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_EE514test1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_EE514test1((SFc1_EE514test1InstanceStruct*)
    chartInstanceVar);
  initialize_c1_EE514test1((SFc1_EE514test1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_EE514test1(void *chartInstanceVar)
{
  enable_c1_EE514test1((SFc1_EE514test1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_EE514test1(void *chartInstanceVar)
{
  disable_c1_EE514test1((SFc1_EE514test1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_EE514test1(void *chartInstanceVar)
{
  sf_c1_EE514test1((SFc1_EE514test1InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_EE514test1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_EE514test1
    ((SFc1_EE514test1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_EE514test1();/* state var info */
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

static void sf_internal_set_sim_state_c1_EE514test1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_EE514test1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_EE514test1((SFc1_EE514test1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_EE514test1(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_EE514test1(S);
}

static void sf_opaque_set_sim_state_c1_EE514test1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_EE514test1(S, st);
}

static void sf_opaque_terminate_c1_EE514test1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_EE514test1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_EE514test1((SFc1_EE514test1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c1_EE514test1((SFc1_EE514test1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_EE514test1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_EE514test1((SFc1_EE514test1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_EE514test1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EE514test1","EE514test1",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EE514test1","EE514test1",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EE514test1",
      "EE514test1",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EE514test1","EE514test1",1,4);
      sf_mark_chart_reusable_outputs(S,"EE514test1","EE514test1",1,5);
    }

    sf_set_rtw_dwork_info(S,"EE514test1","EE514test1",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1683292672U));
  ssSetChecksum1(S,(3089661082U));
  ssSetChecksum2(S,(685809825U));
  ssSetChecksum3(S,(2037905156U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_EE514test1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EE514test1", "EE514test1",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_EE514test1(SimStruct *S)
{
  SFc1_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc1_EE514test1InstanceStruct *)malloc(sizeof
    (SFc1_EE514test1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_EE514test1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_EE514test1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_EE514test1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_EE514test1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_EE514test1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_EE514test1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_EE514test1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_EE514test1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_EE514test1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_EE514test1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_EE514test1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_EE514test1;
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

void c1_EE514test1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_EE514test1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_EE514test1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_EE514test1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_EE514test1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
