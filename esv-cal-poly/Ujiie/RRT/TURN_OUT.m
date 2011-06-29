function TURN_OUT(block)
% Level-2 M file S-Function for unit delay demo.
%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $ 

  setup(block);
  
%endfunction

function setup(block)
  
  block.NumDialogPrms  = 1;
  
  %% Register number of input and output ports
  block.NumInputPorts  = 4;
  block.NumOutputPorts = 1;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;
 
  block.InputPort(1).Dimensions        = [50 6];     %PATH ARRAY
  block.InputPort(1).DirectFeedthrough = false;
  
  block.InputPort(2).Dimensions        = 1;     %CLOCK
  block.InputPort(2).DirectFeedthrough = false;

  block.InputPort(3).Dimensions        = 4;     %VEHICLE DATA
  block.InputPort(3).DirectFeedthrough = false;  
  
  block.InputPort(4).Dimensions        = 1;     %INITIAL SPEED
  block.InputPort(4).DirectFeedthrough = false; %ROUGHLY FT/S
  
  block.OutputPort(1).Dimensions       = 3;
  
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

  SEND = [250 0 0];
  %GET THE PATH ARRAY
  PATH = block.InputPort(1).Data;
  
  %GET THE CURRENT TIME
  TIME = block.InputPort(2).Data;
  
  VEHICLE = block.InputPort(3).Data;    

  SPEED = block.InputPort(4).Data;  
  
  
  %OUTPUT THE STEERING COMMAND FOR THE APPROPRIATE TIME
  CANCEL = 0;
  c=1;
  if (PATH(1,1)<9000)
      
      while ( (PATH(c,2)<=VEHICLE(2)) && CANCEL == 0)
          SEND(2)=PATH(c,6);
          c=c+1;
          if c>49;
              CANCEL =1;
          end
      end
      stopflag = 0;
  else
      stopflag = 1;
  end
  
    SEND(2) = -1*(SEND(2))*120/20+120;
    
if (SPEED == 0)
        stopflag=1;
end
    
   

        %SEND(3) = 145;
        if (stopflag>0)
            SEND(3)=120;
            SEND(2)=120;
        else
            SEND(3) = 3.7702*SPEED+134.99;
        end
        
        SEND(2) = 120;
        
    block.OutputPort(1).Data = SEND;
    %block.OutputPort(1).Data = PATH(1, 4);

 
%endfunction

function Update(block)

  %block.Dwork(1).Data = block.InputPort(1).Data(1);
  
%endfunction

