/*
 * RUNRUNRUN_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "RUNRUNRUN_acc.mdl".
 *
 * Model version              : 1.15
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C source code generated on : Sun May 15 13:46:09 2011
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_RUNRUNRUN_acc_h_
#define RTW_HEADER_RUNRUNRUN_acc_h_
#ifndef RUNRUNRUN_acc_COMMON_INCLUDES_
# define RUNRUNRUN_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#endif                                 /* RUNRUNRUN_acc_COMMON_INCLUDES_ */

#include "RUNRUNRUN_acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T B_0_3_0;                      /* '<Root>/Pulse Generator' */
  real_T B_0_7_0;                      /* '<Root>/Data Type  Conversion' */
  real_T B_0_9_0[2];                   /* '<Root>/GOAL' */
  real_T B_0_10_0[5];                  /* '<Root>/Obstacle' */
  real_T B_0_11_0[2];                  /* '<Root>/ROAD' */
  real_T B_0_12_0[4];                  /* '<Root>/Vehicle' */
  real_T B_0_15_0;                     /* '<Root>/Sine Wave' */
  real_T B_0_13_0[300];                /* '<Root>/Data Store Read' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Level2MfileSFunction_x0;      /* '<Root>/Level-2 M-file S-Function' */
  real_T nextTime;                     /* '<Root>/Pulse Generator' */
  real_T Path[300];                    /* '<Root>/Data Store Path' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<Root>/Derivative' */

  void *Level2MfileSFunction_PWORK[11];/* '<Root>/Level-2 M-file S-Function' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *ToWorkspace_PWORK;             /* '<Root>/To Workspace' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int32_T justEnabled;                 /* '<Root>/Pulse Generator' */
  int32_T currentValue;                /* '<Root>/Pulse Generator' */
  int32_T numCompleteCycles;           /* '<Root>/Pulse Generator' */
  int32_T dsmIdx;                      /* '<Root>/Data Store Path' */
} D_Work;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T B_0_5_0;                /* '<S1>/Constant' */
} ConstBlockIO;

/* For easy access from the SimStruct */
#define rtC(S)                         ((ConstBlockIO *) _ssGetConstBlockIO(S))

/* Parameters (auto storage) */
struct Parameters_ {
  real_T P_0;                          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T P_1;                          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T P_2;                          /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T P_3;                          /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T P_4;                          /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T P_5[2];                       /* Expression: [2, 40]
                                        * Referenced by: '<Root>/GOAL'
                                        */
  real_T P_6[5];                       /* Expression: [-9 25 2 2 1]
                                        * Referenced by: '<Root>/Obstacle'
                                        */
  real_T P_7[2];                       /* Expression: [-5 5]
                                        * Referenced by: '<Root>/ROAD'
                                        */
  real_T P_8[4];                       /* Expression: [2 0 0 2]
                                        * Referenced by: '<Root>/Vehicle'
                                        */
  real_T P_9;                          /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T P_10;                         /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T P_11;                         /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T P_12;                         /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T P_13[300];                    /* Expression: zeros(50, 6)
                                        * Referenced by: '<Root>/Data Store Path'
                                        */
};

extern Parameters rtDefaultParameters; /* parameters */
extern const ConstBlockIO rtInvariantSignals;/* constant block i/o */

#endif                                 /* RTW_HEADER_RUNRUNRUN_acc_h_ */
