/* Include files */

#include "DVM_Hirtle_global_frame_sfun.h"
#include "c1_DVM_Hirtle_global_frame.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _DVM_Hirtle_global_frameMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void DVM_Hirtle_global_frame_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void DVM_Hirtle_global_frame_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DVM_Hirtle_global_frame_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_DVM_Hirtle_global_frame_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DVM_Hirtle_global_frame_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2496905924U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1455023912U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3061043382U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3061275182U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2947537997U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3781689519U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2521394305U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(834272931U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DVM_Hirtle_global_frame_get_check_sum(mxArray *plhs[]);
          sf_c1_DVM_Hirtle_global_frame_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1166041078U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(726025480U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4460659U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2412342285U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DVM_Hirtle_global_frame_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_DVM_Hirtle_global_frame_get_autoinheritance_info
          (void);
        plhs[0] = sf_c1_DVM_Hirtle_global_frame_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DVM_Hirtle_global_frame_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_DVM_Hirtle_global_frame_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DVM_Hirtle_global_frame_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void DVM_Hirtle_global_frame_debug_initialize(void)
{
  _DVM_Hirtle_global_frameMachineNumber_ = sf_debug_initialize_machine(
    "DVM_Hirtle_global_frame","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_DVM_Hirtle_global_frameMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(_DVM_Hirtle_global_frameMachineNumber_,0);
}

void DVM_Hirtle_global_frame_register_exported_symbols(SimStruct* S)
{
}
