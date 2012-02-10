/* Include files */

#include "blascompat32.h"
#include "EE514test1_sfun.h"
#include "c3_EE514test1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EE514test1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c3_debug_family_names[25] = { "v_x", "v_y", "psi_d", "F_x",
  "F_y", "T_z", "M", "l_fs", "I_zzs", "K_sr", "C_af", "delta", "beta", "F_xt",
  "F_yt", "a_x", "a_y", "psi_dd", "nargin", "nargout", "z", "steer", "F_in",
  "zdot", "alpha" };

/* Function Declarations */
static void initialize_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance);
static void initialize_params_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance);
static void enable_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance);
static void disable_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_EE514test1(SFc3_EE514test1InstanceStruct *
  chartInstance);
static void set_sim_state_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance);
static void sf_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c3_EE514test1
  (SFc3_EE514test1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[22]);
static const mxArray *c3_e_sf_marshall(void *chartInstanceVoid, void *c3_u);
static real_T c3_emlrt_marshallIn(SFc3_EE514test1InstanceStruct *chartInstance,
  const mxArray *c3_alpha, const char_T *c3_name);
static void c3_b_emlrt_marshallIn(SFc3_EE514test1InstanceStruct *chartInstance,
  const mxArray *c3_zdot, const char_T *c3_name, real_T c3_y[3]);
static uint8_T c3_c_emlrt_marshallIn(SFc3_EE514test1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_EE514test1, const char_T
  *c3_name);
static void init_dsm_address_info(SFc3_EE514test1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_EE514test1 = 0U;
}

static void initialize_params_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance)
{
}

static void enable_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_EE514test1(SFc3_EE514test1InstanceStruct *
  chartInstance)
{
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  int32_T c3_i0;
  real_T c3_b_hoistedGlobal[3];
  int32_T c3_i1;
  real_T c3_b_u[3];
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_alpha;
  real_T (*c3_zdot)[3];
  c3_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_zdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3));
  c3_hoistedGlobal = *c3_alpha;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0 = c3_i0 + 1) {
    c3_b_hoistedGlobal[c3_i0] = (*c3_zdot)[c3_i0];
  }

  for (c3_i1 = 0; c3_i1 < 3; c3_i1 = c3_i1 + 1) {
    c3_b_u[c3_i1] = c3_b_hoistedGlobal[c3_i1];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_c3_EE514test1;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_EE514test1(SFc3_EE514test1InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[3];
  int32_T c3_i2;
  real_T *c3_alpha;
  real_T (*c3_zdot)[3];
  c3_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_zdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_alpha = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "alpha");
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "zdot", c3_dv0);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2 = c3_i2 + 1) {
    (*c3_zdot)[c3_i2] = c3_dv0[c3_i2];
  }

  chartInstance->c3_is_active_c3_EE514test1 = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_EE514test1");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_EE514test1(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance)
{
}

static void sf_c3_EE514test1(SFc3_EE514test1InstanceStruct *chartInstance)
{
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_previousEvent;
  int32_T c3_i6;
  real_T c3_hoistedGlobal[3];
  real_T c3_b_hoistedGlobal;
  int32_T c3_i7;
  real_T c3_c_hoistedGlobal[4];
  int32_T c3_i8;
  real_T c3_z[3];
  real_T c3_steer;
  int32_T c3_i9;
  real_T c3_F_in[4];
  uint32_T c3_debug_family_var_map[25];
  static const char *c3_sv0[25] = { "v_x", "v_y", "psi_d", "F_x", "F_y", "T_z",
    "M", "l_fs", "I_zzs", "K_sr", "C_af", "delta", "beta"
    , "F_xt", "F_yt", "a_x", "a_y", "psi_dd", "nargin", "nargout", "z", "steer",
    "F_in", "zdot",
    "alpha" };

  real_T c3_v_x;
  real_T c3_v_y;
  real_T c3_psi_d;
  real_T c3_F_x;
  real_T c3_F_y;
  real_T c3_T_z;
  real_T c3_M;
  real_T c3_l_fs;
  real_T c3_I_zzs;
  real_T c3_K_sr;
  real_T c3_C_af;
  real_T c3_delta;
  real_T c3_beta;
  real_T c3_F_xt;
  real_T c3_F_yt;
  real_T c3_a_x;
  real_T c3_a_y;
  real_T c3_psi_dd;
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 2.0;
  real_T c3_zdot[3];
  real_T c3_alpha;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_y;
  real_T c3_a;
  real_T c3_b_A;
  real_T c3_B;
  real_T c3_d_x;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_c_y;
  real_T c3_f_x;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_f_y;
  real_T c3_c_b;
  real_T c3_c_a;
  real_T c3_d_b;
  real_T c3_g_y;
  real_T c3_e_b;
  real_T c3_f_b;
  int32_T c3_i10;
  real_T *c3_b_steer;
  real_T *c3_b_alpha;
  real_T (*c3_b_zdot)[3];
  real_T (*c3_b_F_in)[4];
  real_T (*c3_b_z)[3];
  c3_b_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_F_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_zdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_z = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3 = c3_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_z)[c3_i3], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_steer, 1U);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4 = c3_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_zdot)[c3_i4], 2U);
  }

  for (c3_i5 = 0; c3_i5 < 4; c3_i5 = c3_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_F_in)[c3_i5], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_alpha, 4U);
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1);
  for (c3_i6 = 0; c3_i6 < 3; c3_i6 = c3_i6 + 1) {
    c3_hoistedGlobal[c3_i6] = (*c3_b_z)[c3_i6];
  }

  c3_b_hoistedGlobal = *c3_b_steer;
  for (c3_i7 = 0; c3_i7 < 4; c3_i7 = c3_i7 + 1) {
    c3_c_hoistedGlobal[c3_i7] = (*c3_b_F_in)[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8 = c3_i8 + 1) {
    c3_z[c3_i8] = c3_hoistedGlobal[c3_i8];
  }

  c3_steer = c3_b_hoistedGlobal;
  for (c3_i9 = 0; c3_i9 < 4; c3_i9 = c3_i9 + 1) {
    c3_F_in[c3_i9] = c3_c_hoistedGlobal[c3_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c3_sv0, c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_v_x, c3_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c3_v_y, c3_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c3_psi_d, c3_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c3_F_x, c3_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c3_F_y, c3_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c3_T_z, c3_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c3_M, c3_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c3_l_fs, c3_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c3_I_zzs, c3_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c3_K_sr, c3_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c3_C_af, c3_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c3_delta, c3_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c3_beta, c3_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c3_F_xt, c3_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c3_F_yt, c3_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c3_a_x, c3_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c3_a_y, c3_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c3_psi_dd, c3_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c3_nargin, c3_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c3_nargout, c3_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(c3_z, c3_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c3_steer, c3_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(c3_F_in, c3_c_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(c3_zdot, c3_b_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c3_alpha, c3_sf_marshall, 24U);
  CV_EML_FCN(0, 0);

  /* Inputs */
  _SFD_EML_CALL(0, 4);
  c3_v_x = c3_z[0];
  _SFD_EML_CALL(0, 5);
  c3_v_y = c3_z[1];
  _SFD_EML_CALL(0, 6);
  c3_psi_d = c3_z[2];
  _SFD_EML_CALL(0, 8);
  c3_F_x = c3_F_in[0];
  _SFD_EML_CALL(0, 9);
  c3_F_y = c3_F_in[1];
  _SFD_EML_CALL(0, 10);
  c3_T_z = c3_F_in[2];

  /* Car physical variables */
  _SFD_EML_CALL(0, 13);
  c3_M = 1704.7;

  /* total vehicle mass */
  _SFD_EML_CALL(0, 14);
  c3_l_fs = 1.01476;

  /* length from CG to front suspension */
  _SFD_EML_CALL(0, 15);
  c3_I_zzs = 2619.28;

  /* sprung ZZ inertia */
  _SFD_EML_CALL(0, 16);
  c3_K_sr = 15.97;

  /* steering-to-wheel angle ratio */
  _SFD_EML_CALL(0, 17);
  c3_C_af = 25730.0;

  /* Lateral Slip Stiffness */
  /* Slip Angle */
  _SFD_EML_CALL(0, 20);
  c3_A = c3_steer;
  c3_x = c3_A;
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  c3_y = c3_c_x / 2874.6;
  c3_a = c3_y;
  c3_delta = c3_a * 3.1415926535897931;
  _SFD_EML_CALL(0, 21);
  c3_b_A = c3_v_y;
  c3_B = c3_v_x;
  c3_d_x = c3_b_A;
  c3_b_y = c3_B;
  c3_e_x = c3_d_x;
  c3_c_y = c3_b_y;
  c3_f_x = c3_e_x;
  c3_d_y = c3_c_y;
  c3_e_y = c3_f_x / c3_d_y;
  c3_g_x = c3_e_y;
  c3_beta = c3_g_x;
  c3_h_x = c3_beta;
  c3_beta = c3_h_x;
  c3_beta = muDoubleScalarAtan(c3_beta);
  _SFD_EML_CALL(0, 23);
  c3_alpha = c3_beta - c3_delta;

  /* Tire Forces */
  _SFD_EML_CALL(0, 26);
  c3_F_xt = 0.0;
  _SFD_EML_CALL(0, 27);
  c3_b = c3_alpha;
  c3_F_yt = -25730.0 * c3_b;

  /* F_x = -F_yt*sin(delta); */
  /* F_y = F_yt*cos(delta); */
  /* T_z = -l_fs*C_af*cos(alpha); */
  /* State Output */
  _SFD_EML_CALL(0, 34);
  c3_b_a = c3_v_y;
  c3_b_b = c3_psi_d;
  c3_f_y = c3_b_a * c3_b_b;
  c3_c_b = c3_f_y + c3_F_x;
  c3_a_x = 0.000586613480377779 * c3_c_b;
  _SFD_EML_CALL(0, 35);
  c3_c_a = -c3_v_x;
  c3_d_b = c3_psi_d;
  c3_g_y = c3_c_a * c3_d_b;
  c3_e_b = c3_g_y + c3_F_y;
  c3_a_y = 0.000586613480377779 * c3_e_b;
  _SFD_EML_CALL(0, 36);
  c3_f_b = c3_T_z;
  c3_psi_dd = 0.00038178430713783939 * c3_f_b;
  _SFD_EML_CALL(0, 38);
  c3_zdot[0] = c3_a_x;
  c3_zdot[1] = c3_a_y;
  c3_zdot[2] = c3_psi_dd;

  /* ----------------------------------% */
  /* end */
  _SFD_EML_CALL(0, -38);
  sf_debug_symbol_scope_pop();
  for (c3_i10 = 0; c3_i10 < 3; c3_i10 = c3_i10 + 1) {
    (*c3_b_zdot)[c3_i10] = c3_zdot[c3_i10];
  }

  *c3_b_alpha = c3_alpha;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_EE514test1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c3_EE514test1
  (SFc3_EE514test1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc3_EE514test1InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i11;
  real_T c3_b_u[3];
  int32_T c3_i12;
  real_T c3_c_u[3];
  const mxArray *c3_b_y = NULL;
  SFc3_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc3_EE514test1InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i11 = 0; c3_i11 < 3; c3_i11 = c3_i11 + 1) {
    c3_b_u[c3_i11] = (*((real_T (*)[3])c3_u))[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 3; c3_i12 = c3_i12 + 1) {
    c3_c_u[c3_i12] = c3_b_u[c3_i12];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i13;
  real_T c3_b_u[4];
  int32_T c3_i14;
  real_T c3_c_u[4];
  const mxArray *c3_b_y = NULL;
  SFc3_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc3_EE514test1InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i13 = 0; c3_i13 < 4; c3_i13 = c3_i13 + 1) {
    c3_b_u[c3_i13] = (*((real_T (*)[4])c3_u))[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 4; c3_i14 = c3_i14 + 1) {
    c3_c_u[c3_i14] = c3_b_u[c3_i14];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i15;
  real_T c3_b_u[3];
  int32_T c3_i16;
  real_T c3_c_u[3];
  const mxArray *c3_b_y = NULL;
  SFc3_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc3_EE514test1InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i15 = 0; c3_i15 < 3; c3_i15 = c3_i15 + 1) {
    c3_b_u[c3_i15] = (*((real_T (*)[3])c3_u))[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 3; c3_i16 = c3_i16 + 1) {
    c3_c_u[c3_i16] = c3_b_u[c3_i16];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_EE514test1_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[22];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i17;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22));
  for (c3_i17 = 0; c3_i17 < 22; c3_i17 = c3_i17 + 1) {
    c3_r0 = &c3_info[c3_i17];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i17);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i17);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i17);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i17);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i17);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i17
                    );
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i17
                    );
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[22])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileLength = 3425U;
  c3_info[0].fileTime1 = 1251064272U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[1].name = "nargin";
  c3_info[1].dominantType = "";
  c3_info[1].resolved = "[B]nargin";
  c3_info[1].fileLength = 0U;
  c3_info[1].fileTime1 = 0U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[2].name = "gt";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[B]gt";
  c3_info[2].fileLength = 0U;
  c3_info[2].fileTime1 = 0U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[3].name = "isa";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[B]isa";
  c3_info[3].fileLength = 0U;
  c3_info[3].fileTime1 = 0U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[4].name = "isinteger";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved = "[B]isinteger";
  c3_info[4].fileLength = 0U;
  c3_info[4].fileTime1 = 0U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].name = "isscalar";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[B]isscalar";
  c3_info[5].fileLength = 0U;
  c3_info[5].fileTime1 = 0U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[6].name = "strcmp";
  c3_info[6].dominantType = "char";
  c3_info[6].resolved = "[B]strcmp";
  c3_info[6].fileLength = 0U;
  c3_info[6].fileTime1 = 0U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[7].name = "size";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[B]size";
  c3_info[7].fileLength = 0U;
  c3_info[7].fileTime1 = 0U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[8].name = "eq";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[B]eq";
  c3_info[8].fileLength = 0U;
  c3_info[8].fileTime1 = 0U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].name = "class";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[B]class";
  c3_info[9].fileLength = 0U;
  c3_info[9].fileTime1 = 0U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].name = "not";
  c3_info[10].dominantType = "logical";
  c3_info[10].resolved = "[B]not";
  c3_info[10].fileLength = 0U;
  c3_info[10].fileTime1 = 0U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context = "";
  c3_info[11].name = "mrdivide";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[11].fileLength = 432U;
  c3_info[11].fileTime1 = 1277780622U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[12].name = "ge";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved = "[B]ge";
  c3_info[12].fileLength = 0U;
  c3_info[12].fileTime1 = 0U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[13].name = "rdivide";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[13].fileLength = 403U;
  c3_info[13].fileTime1 = 1245134820U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[14].name = "eml_div";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[14].fileLength = 4918U;
  c3_info[14].fileTime1 = 1267095810U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c3_info[15].name = "isreal";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved = "[B]isreal";
  c3_info[15].fileLength = 0U;
  c3_info[15].fileTime1 = 0U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context = "";
  c3_info[16].name = "pi";
  c3_info[16].dominantType = "";
  c3_info[16].resolved = "[B]pi";
  c3_info[16].fileLength = 0U;
  c3_info[16].fileTime1 = 0U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context = "";
  c3_info[17].name = "atan";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c3_info[17].fileLength = 536U;
  c3_info[17].fileTime1 = 1203480346U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c3_info[18].name = "eml_scalar_atan";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c3_info[18].fileLength = 281U;
  c3_info[18].fileTime1 = 1203480376U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "minus";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved = "[B]minus";
  c3_info[19].fileLength = 0U;
  c3_info[19].fileTime1 = 0U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context = "";
  c3_info[20].name = "uminus";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved = "[B]uminus";
  c3_info[20].fileLength = 0U;
  c3_info[20].fileTime1 = 0U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context = "";
  c3_info[21].name = "plus";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved = "[B]plus";
  c3_info[21].fileLength = 0U;
  c3_info[21].fileTime1 = 0U;
  c3_info[21].fileTime2 = 0U;
}

static const mxArray *c3_e_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  boolean_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc3_EE514test1InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((boolean_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static real_T c3_emlrt_marshallIn(SFc3_EE514test1InstanceStruct *chartInstance,
  const mxArray *c3_alpha, const char_T *c3_name)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_name, sf_mex_dup(c3_alpha), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_alpha);
  return c3_y;
}

static void c3_b_emlrt_marshallIn(SFc3_EE514test1InstanceStruct *chartInstance,
  const mxArray *c3_zdot, const char_T *c3_name,
  real_T c3_y[3])
{
  real_T c3_dv1[3];
  int32_T c3_i18;
  sf_mex_import(c3_name, sf_mex_dup(c3_zdot), c3_dv1, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c3_i18 = 0; c3_i18 < 3; c3_i18 = c3_i18 + 1) {
    c3_y[c3_i18] = c3_dv1[c3_i18];
  }

  sf_mex_destroy(&c3_zdot);
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_EE514test1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_EE514test1,
  const char_T *c3_name)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_name, sf_mex_dup(c3_b_is_active_c3_EE514test1), &c3_u0, 1, 3,
                0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_b_is_active_c3_EE514test1);
  return c3_y;
}

static void init_dsm_address_info(SFc3_EE514test1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_EE514test1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1312924174U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3037692585U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3634467357U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1449651051U);
}

mxArray *sf_c3_EE514test1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2628193095U);
    pr[1] = (double)(4288528059U);
    pr[2] = (double)(2196569633U);
    pr[3] = (double)(754103975U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c3_EE514test1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"alpha\",},{M[1],M[5],T\"zdot\",},{M[8],M[0],T\"is_active_c3_EE514test1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_EE514test1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_EE514test1InstanceStruct *chartInstance;
    chartInstance = (SFc3_EE514test1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EE514test1MachineNumber_,
           3,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"z");
          _SFD_SET_DATA_PROPS(1,1,1,0,"steer");
          _SFD_SET_DATA_PROPS(2,2,0,1,"zdot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"F_in");
          _SFD_SET_DATA_PROPS(4,2,0,1,"alpha");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,809);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);

        {
          real_T *c3_steer;
          real_T *c3_alpha;
          real_T (*c3_z)[3];
          real_T (*c3_zdot)[3];
          real_T (*c3_F_in)[4];
          c3_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_F_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
          c3_zdot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_steer = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_z = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_steer);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_zdot);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_F_in);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_alpha);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EE514test1MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_EE514test1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_EE514test1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_EE514test1((SFc3_EE514test1InstanceStruct*)
    chartInstanceVar);
  initialize_c3_EE514test1((SFc3_EE514test1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_EE514test1(void *chartInstanceVar)
{
  enable_c3_EE514test1((SFc3_EE514test1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_EE514test1(void *chartInstanceVar)
{
  disable_c3_EE514test1((SFc3_EE514test1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_EE514test1(void *chartInstanceVar)
{
  sf_c3_EE514test1((SFc3_EE514test1InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c3_EE514test1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_EE514test1
    ((SFc3_EE514test1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c3_EE514test1();/* state var info */
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

static void sf_internal_set_sim_state_c3_EE514test1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_EE514test1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_EE514test1((SFc3_EE514test1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c3_EE514test1(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_EE514test1(S);
}

static void sf_opaque_set_sim_state_c3_EE514test1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_EE514test1(S, st);
}

static void sf_opaque_terminate_c3_EE514test1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_EE514test1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_EE514test1((SFc3_EE514test1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c3_EE514test1((SFc3_EE514test1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_EE514test1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_EE514test1((SFc3_EE514test1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_EE514test1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EE514test1","EE514test1",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EE514test1","EE514test1",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EE514test1",
      "EE514test1",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EE514test1","EE514test1",3,3);
      sf_mark_chart_reusable_outputs(S,"EE514test1","EE514test1",3,2);
    }

    sf_set_rtw_dwork_info(S,"EE514test1","EE514test1",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1940051022U));
  ssSetChecksum1(S,(2212742613U));
  ssSetChecksum2(S,(2413909115U));
  ssSetChecksum3(S,(81389363U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_EE514test1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EE514test1", "EE514test1",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_EE514test1(SimStruct *S)
{
  SFc3_EE514test1InstanceStruct *chartInstance;
  chartInstance = (SFc3_EE514test1InstanceStruct *)malloc(sizeof
    (SFc3_EE514test1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_EE514test1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_EE514test1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_EE514test1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_EE514test1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_EE514test1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_EE514test1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_EE514test1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_EE514test1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_EE514test1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_EE514test1;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_EE514test1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_EE514test1;
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

void c3_EE514test1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_EE514test1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_EE514test1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_EE514test1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_EE514test1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
