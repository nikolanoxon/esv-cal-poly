%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 13_1
%\label{exini2rob}
% Francesco Borrelli July 05 2009
% Thomas Besselmann, 18.08.08
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


close all
%%% use laprint to produce pictures
uselaprint=1;


% Unstable System
A=[1.5 0;1 -1.5];
B=[1;0];
C=[0 1];
D=0;
sysStruct = mpt_sys(ss(A,B,C,D,1)); %
sysStruct.umin = -5;
sysStruct.umax = 5;
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];
W=polytope([eye(2);-eye(2)],[1;1;1;1]);
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
sysStruct.noise = W;

name = 'ex_14_2';
[Xpre,XpreandX]=preRobAdd_function(sysStruct,name,uselaprint)
[Xreach]=reachRobAdd_function(sysStruct,name,uselaprint)



% --- end of main file ---





