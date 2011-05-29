%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 11_2
%\label{exini2}
% Francesco Borrelli July 05 2009
% Thomas Besselmann, 18.08.08
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

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
name = 'ex_12_2';
[Xpre,XpreandX]=pre_function(sysStruct,name,uselaprint)
[Xreach]=reach_function(sysStruct,name,uselaprint)

