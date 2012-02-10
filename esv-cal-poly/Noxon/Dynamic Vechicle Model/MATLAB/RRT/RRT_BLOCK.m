function RRT_BLOCK(block)
% Level-2 M file S-Function for unit delay demo.
%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $ 

  setup(block);
  
%endfunction

function setup(block)
  
  block.NumDialogPrms  = 1;
  
  %% Register number of input and output ports
  block.NumInputPorts  = 5;
  block.NumOutputPorts = 1;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;
 
  block.InputPort(1).Dimensions        = 4;     %VEHICLE
  block.InputPort(1).DirectFeedthrough = false;
  
  block.InputPort(2).Dimensions        = 5;     %OBSTACLE
  block.InputPort(2).DirectFeedthrough = false;
  
  block.InputPort(3).Dimensions        = 2;     %ROAD
  block.InputPort(3).DirectFeedthrough = false;
  
  block.InputPort(4).Dimensions        = 2;     %GOAL
  block.InputPort(4).DirectFeedthrough = false;
  
  block.InputPort(5).Dimensions        = 1;     %GOGO FLAG
  block.InputPort(5).DirectFeedthrough = false;
  
  block.OutputPort(1).Dimensions       = [50 6];
  
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


  GOGO = block.InputPort(5).Data;
  
  %block.OutputPort(1).Data = GOGO;
  
  if GOGO>0
    VEHICLE=block.InputPort(1).Data;
    OBSTACLE=block.InputPort(2).Data;
    ROAD(1)=block.InputPort(3).Data(1);
    ROAD(2)=block.InputPort(3).Data(2);
    GOAL(1:2)=block.InputPort(4).Data(1:2);
  
    FINAL_PATH = RUN_RRT(VEHICLE, OBSTACLE, ROAD, GOAL);
  
    block.OutputPort(1).Data = FINAL_PATH;
  end
  %block.OutputPort(1).Data = block.InputPort(4).Data(1);
  %FINAL_PATH = RUN_RRT(VEHICLE, OBSTACLE, ROAD, GOAL)
%endfunction

function Update(block)

  %block.Dwork(1).Data = block.InputPort(1).Data(1);
  
%endfunction

