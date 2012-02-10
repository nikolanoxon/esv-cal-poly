/* Include files */

#include "blascompat32.h"
#include "ESCtest3_sfun.h"
#include "c3_ESCtest3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ESCtest3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c3_debug_family_names[9] = { "nargin", "nargout", "delta_p",
  "x_old", "y_old", "psi", "p", "x", "y" };

/* Function Declarations */
static void initialize_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance);
static void initialize_params_c3_ESCtest3(SFc3_ESCtest3InstanceStruct
  *chartInstance);
static void enable_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance);
static void disable_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ESCtest3(SFc3_ESCtest3InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_ESCtest3(SFc3_ESCtest3InstanceStruct
  *chartInstance);
static void set_sim_state_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance);
static void sf_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c3_ESCtest3
  (SFc3_ESCtest3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static real_T c3_mpower(SFc3_ESCtest3InstanceStruct *chartInstance, real_T c3_a);
static void c3_eml_error(SFc3_ESCtest3InstanceStruct *chartInstance);
static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[32]);
static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u);
static real_T c3_emlrt_marshallIn(SFc3_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c3_p, const char_T *c3_name);
static uint8_T c3_b_emlrt_marshallIn(SFc3_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_ESCtest3, const char_T *c3_name);
static void init_dsm_address_info(SFc3_ESCtest3InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_ESCtest3 = 0U;
}

static void initialize_params_c3_ESCtest3(SFc3_ESCtest3InstanceStruct
  *chartInstance)
{
}

static void enable_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_ESCtest3(SFc3_ESCtest3InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_ESCtest3(SFc3_ESCtest3InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T *c3_p;
  real_T *c3_x;
  real_T *c3_f_y;
  c3_f_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_p = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(4));
  c3_hoistedGlobal = *c3_p;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_x;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_f_y;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_is_active_c3_ESCtest3;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 3, c3_e_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_p;
  real_T *c3_x;
  real_T *c3_y;
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_p = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_p = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "p");
  *c3_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "x");
  *c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "y");
  chartInstance->c3_is_active_c3_ESCtest3 = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "is_active_c3_ESCtest3");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_ESCtest3(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance)
{
}

static void sf_c3_ESCtest3(SFc3_ESCtest3InstanceStruct *chartInstance)
{
  int32_T c3_previousEvent;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_delta_p;
  real_T c3_x_old;
  real_T c3_y_old;
  real_T c3_psi;
  uint32_T c3_debug_family_var_map[9];
  real_T c3_nargin = 4.0;
  real_T c3_nargout = 3.0;
  real_T c3_p;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_a;
  real_T c3_b;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_c_y;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T *c3_b_p;
  real_T *c3_j_x;
  real_T *c3_b_delta_p;
  real_T *c3_d_y;
  real_T *c3_b_x_old;
  real_T *c3_b_y_old;
  real_T *c3_b_psi;
  c3_b_psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_y_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_x_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_delta_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_j_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_p = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2);
  _SFD_DATA_RANGE_CHECK(*c3_b_p, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_j_x, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_delta_p, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_d_y, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_b_x_old, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_b_y_old, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_b_psi, 6U);
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2);
  c3_hoistedGlobal = *c3_b_delta_p;
  c3_b_hoistedGlobal = *c3_b_x_old;
  c3_c_hoistedGlobal = *c3_b_y_old;
  c3_d_hoistedGlobal = *c3_b_psi;
  c3_delta_p = c3_hoistedGlobal;
  c3_x_old = c3_b_hoistedGlobal;
  c3_y_old = c3_c_hoistedGlobal;
  c3_psi = c3_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_nargin, c3_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c3_nargout, c3_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c3_delta_p, c3_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c3_x_old, c3_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c3_y_old, c3_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c3_psi, c3_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c3_p, c3_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c3_x, c3_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c3_y, c3_sf_marshall, 8U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 5);
  c3_b_x = c3_psi;
  c3_c_x = c3_b_x;
  c3_d_x = c3_c_x;
  c3_c_x = c3_d_x;
  c3_c_x = muDoubleScalarCos(c3_c_x);
  c3_a = c3_delta_p;
  c3_b = c3_c_x;
  c3_b_y = c3_a * c3_b;
  c3_x = c3_x_old + c3_b_y;
  _SFD_EML_CALL(0, 6);
  c3_e_x = c3_psi;
  c3_f_x = c3_e_x;
  c3_g_x = c3_f_x;
  c3_f_x = c3_g_x;
  c3_f_x = muDoubleScalarSin(c3_f_x);
  c3_b_a = c3_delta_p;
  c3_b_b = c3_f_x;
  c3_c_y = c3_b_a * c3_b_b;
  c3_y = c3_y_old + c3_c_y;
  _SFD_EML_CALL(0, 7);
  c3_h_x = c3_mpower(chartInstance, c3_x) + c3_mpower(chartInstance, c3_y);
  c3_p = c3_h_x;
  if (c3_p < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_i_x = c3_p;
  c3_p = c3_i_x;
  c3_p = muDoubleScalarSqrt(c3_p);
  _SFD_EML_CALL(0, -7);
  sf_debug_symbol_scope_pop();
  *c3_b_p = c3_p;
  *c3_j_x = c3_x;
  *c3_d_y = c3_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_ESCtest3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c3_ESCtest3
  (SFc3_ESCtest3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static real_T c3_mpower(SFc3_ESCtest3InstanceStruct *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_ak = c3_b_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static void c3_eml_error(SFc3_ESCtest3InstanceStruct *chartInstance)
{
  int32_T c3_i0;
  static char_T c3_cv0[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[31];
  const mxArray *c3_y = NULL;
  int32_T c3_i1;
  static char_T c3_cv1[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c3_b_u[77];
  const mxArray *c3_b_y = NULL;
  for (c3_i0 = 0; c3_i0 < 31; c3_i0 = c3_i0 + 1) {
    c3_u[c3_i0] = c3_cv0[c3_i0];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c3_i1 = 0; c3_i1 < 77; c3_i1 = c3_i1 + 1) {
    c3_b_u[c3_i1] = c3_cv1[c3_i1];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c3_y, 14, c3_b_y);
}

static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_ESCtest3InstanceStruct *chartInstance;
  chartInstance = (SFc3_ESCtest3InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_ESCtest3_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[32];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i2;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 32));
  for (c3_i2 = 0; c3_i2 < 32; c3_i2 = c3_i2 + 1) {
    c3_r0 = &c3_info[c3_i2];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i2);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[32])
{
  c3_info[0].context = "";
  c3_info[0].name = "cos";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[0].fileLength = 324U;
  c3_info[0].fileTime1 = 1203480350U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[1].name = "nargin";
  c3_info[1].dominantType = "";
  c3_info[1].resolved = "[B]nargin";
  c3_info[1].fileLength = 0U;
  c3_info[1].fileTime1 = 0U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[2].name = "gt";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[B]gt";
  c3_info[2].fileLength = 0U;
  c3_info[2].fileTime1 = 0U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[3].name = "isa";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[B]isa";
  c3_info[3].fileLength = 0U;
  c3_info[3].fileTime1 = 0U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[4].name = "eml_scalar_cos";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[4].fileLength = 602U;
  c3_info[4].fileTime1 = 1209363186U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[5].name = "isreal";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[B]isreal";
  c3_info[5].fileLength = 0U;
  c3_info[5].fileTime1 = 0U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "";
  c3_info[6].name = "mtimes";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[6].fileLength = 3425U;
  c3_info[6].fileTime1 = 1251064272U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[7].name = "isinteger";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[B]isinteger";
  c3_info[7].fileLength = 0U;
  c3_info[7].fileTime1 = 0U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[8].name = "isscalar";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[B]isscalar";
  c3_info[8].fileLength = 0U;
  c3_info[8].fileTime1 = 0U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].name = "strcmp";
  c3_info[9].dominantType = "char";
  c3_info[9].resolved = "[B]strcmp";
  c3_info[9].fileLength = 0U;
  c3_info[9].fileTime1 = 0U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].name = "size";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved = "[B]size";
  c3_info[10].fileLength = 0U;
  c3_info[10].fileTime1 = 0U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[11].name = "eq";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved = "[B]eq";
  c3_info[11].fileLength = 0U;
  c3_info[11].fileTime1 = 0U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[12].name = "class";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved = "[B]class";
  c3_info[12].fileLength = 0U;
  c3_info[12].fileTime1 = 0U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[13].name = "not";
  c3_info[13].dominantType = "logical";
  c3_info[13].resolved = "[B]not";
  c3_info[13].fileLength = 0U;
  c3_info[13].fileTime1 = 0U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context = "";
  c3_info[14].name = "plus";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved = "[B]plus";
  c3_info[14].fileLength = 0U;
  c3_info[14].fileTime1 = 0U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context = "";
  c3_info[15].name = "sin";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[15].fileLength = 324U;
  c3_info[15].fileTime1 = 1203480442U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[16].name = "eml_scalar_sin";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[16].fileLength = 601U;
  c3_info[16].fileTime1 = 1209363190U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context = "";
  c3_info[17].name = "mpower";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[17].fileLength = 3710U;
  c3_info[17].fileTime1 = 1238466688U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[18].name = "ndims";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved = "[B]ndims";
  c3_info[18].fileLength = 0U;
  c3_info[18].fileTime1 = 0U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[19].name = "power";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[19].fileLength = 5380U;
  c3_info[19].fileTime1 = 1228126298U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[20].name = "eml_scalar_eg";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[20].fileLength = 3068U;
  c3_info[20].fileTime1 = 1240294410U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c3_info[21].name = "false";
  c3_info[21].dominantType = "";
  c3_info[21].resolved = "[B]false";
  c3_info[21].fileLength = 0U;
  c3_info[21].fileTime1 = 0U;
  c3_info[21].fileTime2 = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[22].name = "isstruct";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved = "[B]isstruct";
  c3_info[22].fileLength = 0U;
  c3_info[22].fileTime1 = 0U;
  c3_info[22].fileTime2 = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c3_info[23].name = "cast";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved = "[B]cast";
  c3_info[23].fileLength = 0U;
  c3_info[23].fileTime1 = 0U;
  c3_info[23].fileTime2 = 0U;
  c3_info[24].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[24].name = "eml_scalexp_alloc";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[24].fileLength = 932U;
  c3_info[24].fileTime1 = 1261984270U;
  c3_info[24].fileTime2 = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[25].name = "minus";
  c3_info[25].dominantType = "double";
  c3_info[25].resolved = "[B]minus";
  c3_info[25].fileLength = 0U;
  c3_info[25].fileTime1 = 0U;
  c3_info[25].fileTime2 = 0U;
  c3_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[26].name = "lt";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved = "[B]lt";
  c3_info[26].fileLength = 0U;
  c3_info[26].fileTime1 = 0U;
  c3_info[26].fileTime2 = 0U;
  c3_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[27].name = "eml_scalar_floor";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[27].fileLength = 260U;
  c3_info[27].fileTime1 = 1209363190U;
  c3_info[27].fileTime2 = 0U;
  c3_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[28].name = "ne";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved = "[B]ne";
  c3_info[28].fileLength = 0U;
  c3_info[28].fileTime1 = 0U;
  c3_info[28].fileTime2 = 0U;
  c3_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[29].name = "eml_error";
  c3_info[29].dominantType = "char";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[29].fileLength = 315U;
  c3_info[29].fileTime1 = 1213959144U;
  c3_info[29].fileTime2 = 0U;
  c3_info[30].context = "";
  c3_info[30].name = "sqrt";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[30].fileLength = 572U;
  c3_info[30].fileTime1 = 1203480444U;
  c3_info[30].fileTime2 = 0U;
  c3_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[31].name = "eml_scalar_sqrt";
  c3_info[31].dominantType = "double";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[31].fileLength = 664U;
  c3_info[31].fileTime1 = 1209363194U;
  c3_info[31].fileTime2 = 0U;
}

static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  boolean_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_ESCtest3InstanceStruct *chartInstance;
  chartInstance = (SFc3_ESCtest3InstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((boolean_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static real_T c3_emlrt_marshallIn(SFc3_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c3_p, const char_T *c3_name)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_name, sf_mex_dup(c3_p), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_p);
  return c3_y;
}

static uint8_T c3_b_emlrt_marshallIn(SFc3_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_ESCtest3, const
  char_T *c3_name)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_name, sf_mex_dup(c3_b_is_active_c3_ESCtest3), &c3_u0, 1, 3,
                0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_b_is_active_c3_ESCtest3);
  return c3_y;
}

static void init_dsm_address_info(SFc3_ESCtest3InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_ESCtest3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2089230071U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2291786943U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(729805430U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(945824607U);
}

mxArray *sf_c3_ESCtest3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1626395753U);
    pr[1] = (double)(3920430778U);
    pr[2] = (double)(1306779772U);
    pr[3] = (double)(4293345033U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c3_ESCtest3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"p\",},{M[1],M[9],T\"x\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c3_ESCtest3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ESCtest3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ESCtest3InstanceStruct *chartInstance;
    chartInstance = (SFc3_ESCtest3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ESCtest3MachineNumber_,
          3,
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
          init_script_number_translation(_ESCtest3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ESCtest3MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ESCtest3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"p");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"delta_p");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y");
          _SFD_SET_DATA_PROPS(4,1,1,0,"x_old");
          _SFD_SET_DATA_PROPS(5,1,1,0,"y_old");
          _SFD_SET_DATA_PROPS(6,1,1,0,"psi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,137);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshall);

        {
          real_T *c3_p;
          real_T *c3_x;
          real_T *c3_delta_p;
          real_T *c3_y;
          real_T *c3_x_old;
          real_T *c3_y_old;
          real_T *c3_psi;
          c3_psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_y_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_x_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_delta_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_p = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_p);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_delta_p);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_x_old);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_y_old);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_psi);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ESCtest3MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_ESCtest3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ESCtest3InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*) chartInstanceVar);
  initialize_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_ESCtest3(void *chartInstanceVar)
{
  enable_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_ESCtest3(void *chartInstanceVar)
{
  disable_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_ESCtest3(void *chartInstanceVar)
{
  sf_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c3_ESCtest3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c3_ESCtest3();/* state var info */
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

static void sf_internal_set_sim_state_c3_ESCtest3(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ESCtest3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c3_ESCtest3(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_ESCtest3(S);
}

static void sf_opaque_set_sim_state_c3_ESCtest3(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_ESCtest3(S, st);
}

static void sf_opaque_terminate_c3_ESCtest3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ESCtest3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ESCtest3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_ESCtest3((SFc3_ESCtest3InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ESCtest3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ESCtest3","ESCtest3",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ESCtest3","ESCtest3",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ESCtest3","ESCtest3",3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ESCtest3","ESCtest3",3,4);
      sf_mark_chart_reusable_outputs(S,"ESCtest3","ESCtest3",3,3);
    }

    sf_set_rtw_dwork_info(S,"ESCtest3","ESCtest3",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(905944864U));
  ssSetChecksum1(S,(534356432U));
  ssSetChecksum2(S,(1670970016U));
  ssSetChecksum3(S,(1977010898U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_ESCtest3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ESCtest3", "ESCtest3",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_ESCtest3(SimStruct *S)
{
  SFc3_ESCtest3InstanceStruct *chartInstance;
  chartInstance = (SFc3_ESCtest3InstanceStruct *)malloc(sizeof
    (SFc3_ESCtest3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ESCtest3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_ESCtest3;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_ESCtest3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_ESCtest3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ESCtest3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ESCtest3;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_ESCtest3;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_ESCtest3;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_ESCtest3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ESCtest3;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ESCtest3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_ESCtest3;
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

void c3_ESCtest3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ESCtest3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ESCtest3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ESCtest3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ESCtest3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
