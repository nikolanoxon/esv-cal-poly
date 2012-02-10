/* Include files */

#include "blascompat32.h"
#include "ESCtest3_sfun.h"
#include "c2_ESCtest3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ESCtest3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[7] = { "nargin", "nargout", "v_i",
  "v_j", "psi", "v_x", "v_y" };

/* Function Declarations */
static void initialize_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance);
static void initialize_params_c2_ESCtest3(SFc2_ESCtest3InstanceStruct
  *chartInstance);
static void enable_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance);
static void disable_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ESCtest3(SFc2_ESCtest3InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ESCtest3(SFc2_ESCtest3InstanceStruct
  *chartInstance);
static void set_sim_state_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance);
static void sf_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c2_ESCtest3
  (SFc2_ESCtest3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c2_v_x, const char_T *c2_name);
static uint8_T c2_b_emlrt_marshallIn(SFc2_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ESCtest3, const char_T *c2_name);
static void init_dsm_address_info(SFc2_ESCtest3InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_ESCtest3 = 0U;
}

static void initialize_params_c2_ESCtest3(SFc2_ESCtest3InstanceStruct
  *chartInstance)
{
}

static void enable_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_ESCtest3(SFc2_ESCtest3InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_ESCtest3(SFc2_ESCtest3InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_v_x;
  real_T *c2_v_y;
  c2_v_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_v_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  c2_hoistedGlobal = *c2_v_x;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_v_y;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_ESCtest3;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_v_x;
  real_T *c2_v_y;
  c2_v_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_v_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_v_x = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "v_x");
  *c2_v_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "v_y");
  chartInstance->c2_is_active_c2_ESCtest3 = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "is_active_c2_ESCtest3");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ESCtest3(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance)
{
}

static void sf_c2_ESCtest3(SFc2_ESCtest3InstanceStruct *chartInstance)
{
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_v_i;
  real_T c2_v_j;
  real_T c2_psi;
  uint32_T c2_debug_family_var_map[7];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 2.0;
  real_T c2_v_x;
  real_T c2_v_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T *c2_b_v_x;
  real_T *c2_b_v_y;
  real_T *c2_b_v_i;
  real_T *c2_b_v_j;
  real_T *c2_b_psi;
  c2_b_psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_v_j = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_v_i = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_v_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_v_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1);
  _SFD_DATA_RANGE_CHECK(*c2_b_v_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_v_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_v_i, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_v_j, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_psi, 4U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1);
  c2_hoistedGlobal = *c2_b_v_i;
  c2_b_hoistedGlobal = *c2_b_v_j;
  c2_c_hoistedGlobal = *c2_b_psi;
  c2_v_i = c2_hoistedGlobal;
  c2_v_j = c2_b_hoistedGlobal;
  c2_psi = c2_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_v_i, c2_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_v_j, c2_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_psi, c2_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_v_x, c2_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_v_y, c2_sf_marshall, 6U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  c2_x = c2_psi;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_b_x = c2_c_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_a = c2_v_i;
  c2_b = c2_b_x;
  c2_y = c2_a * c2_b;
  c2_d_x = c2_psi;
  c2_e_x = c2_d_x;
  c2_f_x = c2_e_x;
  c2_e_x = c2_f_x;
  c2_e_x = muDoubleScalarSin(c2_e_x);
  c2_b_a = c2_v_j;
  c2_b_b = c2_e_x;
  c2_b_y = c2_b_a * c2_b_b;
  c2_v_x = c2_y + c2_b_y;
  _SFD_EML_CALL(0, 5);
  c2_g_x = c2_psi;
  c2_h_x = c2_g_x;
  c2_i_x = c2_h_x;
  c2_h_x = c2_i_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_c_a = -c2_v_i;
  c2_c_b = c2_h_x;
  c2_c_y = c2_c_a * c2_c_b;
  c2_j_x = c2_psi;
  c2_k_x = c2_j_x;
  c2_l_x = c2_k_x;
  c2_k_x = c2_l_x;
  c2_k_x = muDoubleScalarCos(c2_k_x);
  c2_d_a = c2_v_j;
  c2_d_b = c2_k_x;
  c2_d_y = c2_d_a * c2_d_b;
  c2_v_y = c2_c_y + c2_d_y;
  _SFD_EML_CALL(0, -5);
  sf_debug_symbol_scope_pop();
  *c2_b_v_x = c2_v_x;
  *c2_b_v_y = c2_v_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_ESCtest3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c2_ESCtest3
  (SFc2_ESCtest3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_ESCtest3InstanceStruct *chartInstance;
  chartInstance = (SFc2_ESCtest3InstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_ESCtest3_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18));
  for (c2_i0 = 0; c2_i0 < 18; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "cos";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[0].fileLength = 324U;
  c2_info[0].fileTime1 = 1203480350U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].name = "nargin";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[B]nargin";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[2].name = "gt";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]gt";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[3].name = "isa";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]isa";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[4].name = "eml_scalar_cos";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[4].fileLength = 602U;
  c2_info[4].fileTime1 = 1209363186U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[5].name = "isreal";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isreal";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "mtimes";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].fileLength = 3425U;
  c2_info[6].fileTime1 = 1251064272U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].name = "isinteger";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]isinteger";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].name = "isscalar";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isscalar";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "strcmp";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved = "[B]strcmp";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "size";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]size";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "eq";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]eq";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].name = "class";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]class";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].name = "not";
  c2_info[13].dominantType = "logical";
  c2_info[13].resolved = "[B]not";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "sin";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[14].fileLength = 324U;
  c2_info[14].fileTime1 = 1203480442U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[15].name = "eml_scalar_sin";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[15].fileLength = 601U;
  c2_info[15].fileTime1 = 1209363190U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "plus";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]plus";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "";
  c2_info[17].name = "uminus";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]uminus";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_ESCtest3InstanceStruct *chartInstance;
  chartInstance = (SFc2_ESCtest3InstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c2_v_x, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_v_x), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_v_x);
  return c2_y;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_ESCtest3InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ESCtest3, const
  char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_ESCtest3), &c2_u0, 1, 3,
                0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_ESCtest3);
  return c2_y;
}

static void init_dsm_address_info(SFc2_ESCtest3InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_ESCtest3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1497374065U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2129655532U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2127096873U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3757328479U);
}

mxArray *sf_c2_ESCtest3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2486767404U);
    pr[1] = (double)(1201516530U);
    pr[2] = (double)(3920488348U);
    pr[3] = (double)(1235606088U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_ESCtest3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[4],T\"v_x\",},{M[1],M[6],T\"v_y\",},{M[8],M[0],T\"is_active_c2_ESCtest3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ESCtest3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ESCtest3InstanceStruct *chartInstance;
    chartInstance = (SFc2_ESCtest3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_ESCtest3MachineNumber_,
          2,
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
          init_script_number_translation(_ESCtest3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_ESCtest3MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ESCtest3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"v_x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v_y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v_i");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v_j");
          _SFD_SET_DATA_PROPS(4,1,1,0,"psi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,113);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);

        {
          real_T *c2_v_x;
          real_T *c2_v_y;
          real_T *c2_v_i;
          real_T *c2_v_j;
          real_T *c2_psi;
          c2_psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_v_j = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_v_i = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_v_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_v_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_v_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_v_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_v_i);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_v_j);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_psi);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ESCtest3MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_ESCtest3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ESCtest3InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*) chartInstanceVar);
  initialize_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ESCtest3(void *chartInstanceVar)
{
  enable_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ESCtest3(void *chartInstanceVar)
{
  disable_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ESCtest3(void *chartInstanceVar)
{
  sf_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_ESCtest3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_ESCtest3();/* state var info */
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

static void sf_internal_set_sim_state_c2_ESCtest3(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ESCtest3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_ESCtest3(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_ESCtest3(S);
}

static void sf_opaque_set_sim_state_c2_ESCtest3(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_ESCtest3(S, st);
}

static void sf_opaque_terminate_c2_ESCtest3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ESCtest3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ESCtest3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ESCtest3((SFc2_ESCtest3InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_ESCtest3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ESCtest3","ESCtest3",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ESCtest3","ESCtest3",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ESCtest3","ESCtest3",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ESCtest3","ESCtest3",2,3);
      sf_mark_chart_reusable_outputs(S,"ESCtest3","ESCtest3",2,2);
    }

    sf_set_rtw_dwork_info(S,"ESCtest3","ESCtest3",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(455261873U));
  ssSetChecksum1(S,(327155981U));
  ssSetChecksum2(S,(3913373879U));
  ssSetChecksum3(S,(3240869071U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_ESCtest3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ESCtest3", "ESCtest3",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ESCtest3(SimStruct *S)
{
  SFc2_ESCtest3InstanceStruct *chartInstance;
  chartInstance = (SFc2_ESCtest3InstanceStruct *)malloc(sizeof
    (SFc2_ESCtest3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_ESCtest3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ESCtest3;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ESCtest3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_ESCtest3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ESCtest3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ESCtest3;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ESCtest3;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ESCtest3;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ESCtest3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ESCtest3;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ESCtest3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ESCtest3;
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

void c2_ESCtest3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ESCtest3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ESCtest3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ESCtest3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ESCtest3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
