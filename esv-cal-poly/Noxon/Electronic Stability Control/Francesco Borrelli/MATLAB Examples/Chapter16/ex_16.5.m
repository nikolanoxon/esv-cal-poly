>> H=[-1 1; -3 -1; 0.2 1; -1 0; 1 0; 0 -1]; %Polytopic state constraints Hx(k)<=K
>> K=[ 15; 25; 9; 6; 8; 10]; %Polytopic state constraints Hx(k)<=K
>> sysStruct.C{1} = [1 0]; %System Dynamics 1: y(k)=Cx(k)+Du(k)+g
>> sysStruct.D{1} = 0; %System Dynamics 1: y(k)=Cx(k)+Du(k)+g
>> sysStruct.g{1} = [0]; %System Dynamics 1: y(k)=Cx(k)+Du(k)+g
>> sysStruct.A{1} = [0.5 0.2; 0 1]; %System Dynamics 1: x(k+1)=Ax(k)+Bu(k)+f
>> sysStruct.B{1} = [0; 1]; %System Dynamics 1: x(k+1)=Ax(k)+Bu(k)+f
>> sysStruct.f{1} = [0.5; 0]; %System Dynamics 1: x(k+1)=Ax(k)+Bu(k)+f
>> sysStruct.guardX{1} = [1 0; H]; %Dynamics 1 defined in guardX*x <= guardC
>> sysStruct.guardC{1} = [ 1; K]; %Dynamics 1 defined in guardX*x <= guardC
>> sysStruct.C{2} = [1 0]; %System Dynamics 2: y(k)=Cx(k)+Du(k)+g
>> sysStruct.D{2} = 0; %System Dynamics 2: y(k)=Cx(k)+Du(k)+g
>> sysStruct.g{2} = [0]; %System Dynamics 2: y(k)=Cx(k)+Du(k)+g
>> sysStruct.A{2} = [0.5 0.2; 0 1]; %System Dynamics 2: x(k+1)=Ax(k)+Bu(k)+f
>> sysStruct.B{2} = [0; 1]; %System Dynamics 2: x(k+1)=Ax(k)+Bu(k)+f
>> sysStruct.f{2} = [0.5; 0]; %System Dynamics 2: x(k+1)=Ax(k)+Bu(k)+f
>> sysStruct.guardX{2} = [-1 0; H]; %Dynamics 2 defined in guardX*x <= guardC
>> sysStruct.guardC{2} = [ -1; K]; %Dynamics 2 defined in guardX*x <= guardC
>> sysStruct.ymin = -10; %Output constraints for dynamic 1 and 2
>> sysStruct.ymax = 10; %Output constraints for dynamic 1 and 2
>> sysStruct.umin = -1; %Input constraints for dynamic 1 and 2
>> sysStruct.umax = 1; %Input constraints for dynamic 1 and 2
we can now compute the low complexity feedback controller by defining the problem
10 Examples 69
>> probStruct.norm=2; %Quadratic Objective
>> probStruct.Q=eye(2); %Objective: min_U J=sum x’Qx + u’Ru...
>> probStruct.R=0.1; %Objective: min_U J=sum x’Qx + u’Ru...
>> probStruct.subopt_lev=1; %Compute low complexity controller.
and calling the control function,
>> ctrl=mpt_control(sysStruct,probStruct);
>> plot(ctrl)