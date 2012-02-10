% Author: Nikola Noxon
% email: nikolanoxon@gmail.com
% Jan 2012; Last revision: 1-29-12

%------------- BEGIN CODE --------------

% Initialize
clc
clear

% This example shows how to use linearize to linearize a model at the
% operating point specified in the model. The model operating point
% consists of the model initial state values and input signals.

% Open Simulink model.
sys = 'DVM_Hirtle_test';
load_system(sys);
open_system(sys)


% Specify to linearize the DVM System block using linearization I/O
% points. Each linearization I/O point is associated with a block outport.
sys_io(1)=linio('DVM_Hirtle_test/steer',1,'in');
sys_io(2)=linio('DVM_Hirtle_test/DVM',1,'out');

% Note: When there are multiple block output signals and you want to
% specify an output port other than the first output, enter the desired
% output port number as the second argument of linio.

% Update the model ports to include the linearization I/O points.
% The linearization I/O markers appear in the model. Use this to visualize
% your linearization points.
setlinio(sys,sys_io);

% Open the loop.
% This command removes the effects of the feedback signal on the
% linearization without changing the model operating point. 
sys_io(2).OpenLoop='on';

% Note: Do not open the loop by manually removing the feedback signal from
% the model. Removing the signal manually changes the operating point of
% the model.

% Update the model to reflect the modified linearization I/O object.
% This command also adds the loop opening marker to the model.
setlinio(sys,sys_io);

% Linearize the DVM System block at the model operating point.
% linsys is a state-space model object.
linsys = linearize(sys,sys_io)
% bdclose(sys);

% Plot a Bode plot of the linearized model.
bode(linsys)


%------------- END OF CODE --------------