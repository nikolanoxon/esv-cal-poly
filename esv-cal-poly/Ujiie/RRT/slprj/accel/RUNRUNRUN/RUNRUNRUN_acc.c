/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * RUNRUNRUN_acc.c
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
#include <math.h>
#include "RUNRUNRUN_acc.h"
#include "RUNRUNRUN_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T B_0_4_0;
  real_T taskTimeV;
  real_T tNextAdjuested;
  uint32_T numCycles;
  int32_T i;

  /* M-S-Function: '<Root>/Level-2 M-file S-Function' */
  /* Call into Simulink */
  ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);
  memcpy((void *)(&((D_Work *) ssGetRootDWork(S))->Path[0]), (void *)(&((BlockIO
            *) _ssGetBlockIO(S))->B_0_13_0[0]), 300U * sizeof(real_T));
  ssWriteToDataStoreWithPath(S, ((D_Work *) ssGetRootDWork(S))->dsmIdx,
    "RUNRUNRUN/Data Store Write", NULL);
  if (ssGetErrorStatus(S) != (NULL)) {
    return;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Scope: '<Root>/Scope2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 0, 2, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsSampleHit(S, 2, 0)) {
    taskTimeV = ssGetTaskTime(S,0);
    tNextAdjuested = (real_T)ssGetTNextWasAdjustedPtr(S)[2];
    if (tNextAdjuested != 0.0) {
      ((D_Work *) ssGetRootDWork(S))->nextTime = (real_T)_ssGetVarNextHitTime(S,
        0);
    }

    if (((D_Work *) ssGetRootDWork(S))->justEnabled != 0) {
      ((D_Work *) ssGetRootDWork(S))->justEnabled = 0;
      if (taskTimeV >= ((Parameters *) ssGetDefaultParam(S))->P_3) {
        tNextAdjuested = (taskTimeV - ((Parameters *) ssGetDefaultParam(S))->P_3)
          / ((Parameters *) ssGetDefaultParam(S))->P_1;
        numCycles = (uint32_T)(int32_T)muDoubleScalarFloor(tNextAdjuested);
        if (muDoubleScalarAbs((real_T)(numCycles + 1U) - tNextAdjuested) <
            DBL_EPSILON * tNextAdjuested) {
          numCycles++;
        }

        ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = (int32_T)numCycles;
        tNextAdjuested = ((real_T)numCycles * ((Parameters *) ssGetDefaultParam
          (S))->P_1 + ((Parameters *) ssGetDefaultParam(S))->P_3) + ((Parameters
          *) ssGetDefaultParam(S))->P_2 * ((Parameters *) ssGetDefaultParam(S)
          )->P_1 / 100.0;
        if (taskTimeV < tNextAdjuested) {
          ((D_Work *) ssGetRootDWork(S))->currentValue = 1;
          ((D_Work *) ssGetRootDWork(S))->nextTime = tNextAdjuested;
        } else {
          ((D_Work *) ssGetRootDWork(S))->currentValue = 0;
          ((D_Work *) ssGetRootDWork(S))->nextTime = (real_T)(numCycles + 1U) *
            ((Parameters *) ssGetDefaultParam(S))->P_1 + ((Parameters *)
            ssGetDefaultParam(S))->P_3;
        }
      } else {
        ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = ((Parameters *)
          ssGetDefaultParam(S))->P_3 != 0.0 ? -1 : 0;
        ((D_Work *) ssGetRootDWork(S))->currentValue = 0;
        ((D_Work *) ssGetRootDWork(S))->nextTime = ((Parameters *)
          ssGetDefaultParam(S))->P_3;
      }
    } else {
      if (((D_Work *) ssGetRootDWork(S))->nextTime <= taskTimeV) {
        if (((D_Work *) ssGetRootDWork(S))->currentValue == 1) {
          ((D_Work *) ssGetRootDWork(S))->currentValue = 0;
          ((D_Work *) ssGetRootDWork(S))->nextTime = (real_T)(((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles + 1) * ((Parameters *)
            ssGetDefaultParam(S))->P_1 + ((Parameters *) ssGetDefaultParam(S))
            ->P_3;
        } else {
          ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = ((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles + 1;
          ((D_Work *) ssGetRootDWork(S))->currentValue = 1;
          ((D_Work *) ssGetRootDWork(S))->nextTime = (((Parameters *)
            ssGetDefaultParam(S))->P_2 * ((Parameters *) ssGetDefaultParam(S))
            ->P_1 * 0.01 + (real_T)((D_Work *) ssGetRootDWork(S))
            ->numCompleteCycles * ((Parameters *) ssGetDefaultParam(S))->P_1) +
            ((Parameters *) ssGetDefaultParam(S))->P_3;
        }
      }
    }

    _ssSetVarNextHitTime(S, (int_T)0.0, ((D_Work *) ssGetRootDWork(S))->nextTime);
    if (((D_Work *) ssGetRootDWork(S))->currentValue == 1) {
      ((BlockIO *) _ssGetBlockIO(S))->B_0_3_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_0;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_0_3_0 = 0.0;
    }
  }

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = ssGetTaskTime(S,0);
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampB;
    real_T *lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      B_0_4_0 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      B_0_4_0 = (((BlockIO *) _ssGetBlockIO(S))->B_0_3_0 - *lastU++) / deltaT;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_0_7_0 = (real_T)(B_0_4_0 > rtC(S)->B_0_5_0);

  /* Scope: '<Root>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 0, 8, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_0_9_0[0] = ((Parameters *)
      ssGetDefaultParam(S))->P_5[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_9_0[1] = ((Parameters *)
      ssGetDefaultParam(S))->P_5[1];
    for (i = 0; i < 5; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_0_10_0[i] = ((Parameters *)
        ssGetDefaultParam(S))->P_6[i];
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_0_11_0[0] = ((Parameters *)
      ssGetDefaultParam(S))->P_7[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_11_0[1] = ((Parameters *)
      ssGetDefaultParam(S))->P_7[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_12_0[0] = ((Parameters *)
      ssGetDefaultParam(S))->P_8[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_12_0[1] = ((Parameters *)
      ssGetDefaultParam(S))->P_8[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_12_0[2] = ((Parameters *)
      ssGetDefaultParam(S))->P_8[2];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_12_0[3] = ((Parameters *)
      ssGetDefaultParam(S))->P_8[3];
  }

  ssReadFromDataStoreWithPath(S, ((D_Work *) ssGetRootDWork(S))->dsmIdx,
    "RUNRUNRUN/Data Store Read", NULL);
  if (ssGetErrorStatus(S) != (NULL)) {
    return;
  }

  memcpy((void *)(&((BlockIO *) _ssGetBlockIO(S))->B_0_13_0[0]), (void *)
         (&((D_Work *) ssGetRootDWork(S))->Path[0]), 300U * sizeof(real_T));

  /* ToWorkspace: '<Root>/To Workspace' */

  /* Call into Simulink for To Workspace */
  ssCallAccelRunBlock(S, 0, 14, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_0_15_0 = muDoubleScalarSin(((Parameters *)
    ssGetDefaultParam(S))->P_11 * ssGetTaskTime(S,0) + ((Parameters *)
    ssGetDefaultParam(S))->P_12) * ((Parameters *) ssGetDefaultParam(S))->P_9 +
    ((Parameters *) ssGetDefaultParam(S))->P_10;

  /* Scope: '<Root>/Scope1' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 0, 16, SS_CALL_MDL_OUTPUTS);

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* Update for M-S-Function: '<Root>/Level-2 M-file S-Function' */
  /* Call into Simulink */
  ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_UPDATE);

  /* Update for Derivative: '<Root>/Derivative' */
  {
    real_T timeStampA = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T timeStampB = ((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampB;
    real_T* lastTime = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.TimeStampA;
    real_T* lastU = &((D_Work *) ssGetRootDWork(S))
      ->Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.TimeStampB;
        lastU = &((D_Work *) ssGetRootDWork(S))->Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(S,0);
    *lastU++ = ((BlockIO *) _ssGetBlockIO(S))->B_0_3_0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 2365062554U);
  ssSetChecksumVal(S, 1, 3331254878U);
  ssSetChecksumVal(S, 2, 2436187078U);
  ssSetChecksumVal(S, 3, 4119254877U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);

  /* constant block I/O */
  _ssSetConstBlockIO(S, &rtInvariantSignals);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
