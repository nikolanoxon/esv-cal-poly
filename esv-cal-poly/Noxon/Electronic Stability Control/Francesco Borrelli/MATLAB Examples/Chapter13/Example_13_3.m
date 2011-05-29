%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 13_3
%\label{exini3rob}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

close all

%%% use laprint to produce pictures
uselaprint=1;

% Stable System
A=[0.5 0;1 -0.5];
B=[0;0];
C=[0 1];
D=0;
sysStruct = mpt_sys(ss(A,B,C,D,1)); %
sysStruct.umin = -5;
sysStruct.umax = 5;
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];
name = 'ex_14_3';
W=polytope([eye(2);-eye(2)],[1;1;1;1]);
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
sysStruct.noise = W;

sysStruct.Aunc = {[1 0;0 0]};
%Wcal=hull([0;0];[0;0.5]);
%Vertices of teh disturbance set
sysStruct.Wcal{1}=[0];
sysStruct.Wcal{2}=[0.5];
sysStruct.Bunc = {0*B};

[Xpre,XpreandX]=preRobAddPar_function(sysStruct,name,uselaprint)

