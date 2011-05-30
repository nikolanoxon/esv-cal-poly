function IMU_DATA(block)
% Level-2 M file S-Function for unit delay demo.
%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $ 

  setup(block);
  
%endfunction

function setup(block)
  
  block.NumDialogPrms  = 1;
  
  %% Register number of input and output ports
  block.NumInputPorts  = 1;
  block.NumOutputPorts = 1;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;
 
  block.InputPort(1).Dimensions        = [1 2];     %IMU data in 8 bit ints
  block.InputPort(1).DirectFeedthrough = false;
  
  block.OutputPort(1).Dimensions       = [1 1];    %IMU data in 16 bit ints
  
  %block.OutputPort(2).Dimensions       = 1;
  
  %% Set block sample time to inherited
  block.SampleTimes = [0 0];
  
  %% Register methods
  block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
  block.RegBlockMethod('InitializeConditions',    @InitConditions);  
  block.RegBlockMethod('Outputs',                 @Output);  
  block.RegBlockMethod('Update',                  @Update);  
  
%endfunction

function DoPostPropSetup(block)

  %% Setup Dwork
  block.NumDworks = 1;
  block.Dwork(1).Name = 'x0'; 
  block.Dwork(1).Dimensions      = 1;
  block.Dwork(1).DatatypeID      = 0;
  block.Dwork(1).Complexity      = 'Real';
  block.Dwork(1).UsedAsDiscState = true;

%endfunction

function InitConditions(block)

  %% Initialize Dwork
  block.Dwork(1).Data = block.DialogPrm(1).Data;
  
%endfunction

function Output(block)

  IMUlarge= [0];  
  %GET THE IMU ARRAY
  IMUsmall = block.InputPort(1).Data;
    
  %CONCATINATE DATA
  
    IMUlarge(1) = IMUsmall(1) * (2^8) + IMUsmall(2);
%     IMUlarge(2) = IMUsmall(3) * (2^8) + IMUsmall(4);
%     IMUlarge(3) = IMUsmall(5) * (2^8) + IMUsmall(6);
%     IMUlarge(4) = IMUsmall(7) * (2^8) + IMUsmall(8);
%     IMUlarge(5) = IMUsmall(9) * (2^8) + IMUsmall(10);
%     IMUlarge(6) = IMUsmall(11) * (2^8) + IMUsmall(12);
  
%   IMUlarge(1) = bitor(bitshift(typecast(double(IMUsmall(1)), 'uint8'),8),typecast(double(IMUsmall(2)), 'uint8'));
%   IMUlarge(2) = bitor(bitshift(typecast(double(IMUsmall(3)), 'uint8'),8),typecast(double(IMUsmall(4)), 'uint8'));
%   IMUlarge(3) = bitor(bitshift(typecast(double(IMUsmall(5)), 'uint8'),8),typecast(double(IMUsmall(6)), 'uint8'));
%   IMUlarge(4) = bitor(bitshift(typecast(double(IMUsmall(7)), 'uint8'),8),typecast(double(IMUsmall(8)), 'uint8'));
%   IMUlarge(5) = bitor(bitshift(typecast(double(IMUsmall(9)), 'uint8'),8),typecast(double(IMUsmall(10)), 'uint8'));
%   IMUlarge(6) = bitor(bitshift(typecast(double(IMUsmall(11)), 'uint8'),8),typecast(double(IMUsmall(12)), 'uint8')); 
  

    block.OutputPort(1).Data = IMUlarge;
    %block.OutputPort(1).Data = PATH(1, 4);

 
%endfunction

function Update(block)

  %block.Dwork(1).Data = block.InputPort(1).Data(1);
  
%endfunction

