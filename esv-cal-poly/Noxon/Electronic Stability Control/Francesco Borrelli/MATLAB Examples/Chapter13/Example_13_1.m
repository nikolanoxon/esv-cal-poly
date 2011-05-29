%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 13_1
%\label{exini1rob}
% Francesco Borrelli July 05 2009
% Thomas Besselmann, 18.08.08
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
name = 'ex_14_1';
W=polytope([eye(2);-eye(2)],[1;1;1;1]);
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
sysStruct.noise = W;

[Xpre,XpreandX]=preRobAdd_function(sysStruct,name,uselaprint)
[Xreach]=reachRobAdd_function(sysStruct,name,uselaprint)



% --- end of main file ---







