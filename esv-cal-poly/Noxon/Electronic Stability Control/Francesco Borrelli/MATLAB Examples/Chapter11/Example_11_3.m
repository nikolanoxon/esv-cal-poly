%%%%%%%%%%%%%%%%% 
% Example 11.3
% \label{ex:chCOC_invcomp}
%%%%%%%%%%%%%%%%%

%System Definition
A=[0.5 0;1 -0.5];
B=[1;1];
C=[0 1];
D=0;
sysStruct = mpt_sys(ss(A,B,C,D,1)); %
sysStruct.umin = -5;
sysStruct.umax = 5;
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
ftsize=28;
Options.color=[.5 .5 .5]; % Gray color

[Oinf,tstar,fd,isemptypoly] = mpt_infset(A,X,100)

figure
plot(Oinf,Options) 
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2','invariantex1.eps');
% [       1           0]      [     10]
% [       0           1]      [     10]
% [      -1          -0]      [     10]
% [      -0          -1] x <= [     10]
% [     0.1      -0.05 ]      [1]
% [     -0.1       0.05]      [1]


