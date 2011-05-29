%%%%%%%%%%%%%%%%% 
% Example 11.4
% \label{ex:chCOC_cinvcomp}
%%%%%%%%%%%%%%%%%

A=[1.5 0;1 -1.5];
B=[1;0];
C=[0 1];
D=0;
sysStruct = mpt_sys(ss(A,B,C,D,1)); %
sysStruct.umin = -5;
sysStruct.umax = 5;
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
[Cinf,iterations, Piter] = mpt_maxCtrlSet(sysStruct)
Options.color=[.5 .5 .5]; % Gray color

figure
plot(Cinf,Options)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2','invariantex2.eps');


% [      0          -1]      [     4]
% [     -1           0]      [    10]
% [      1           0]      [    10]
% [      0           1] x <= [     4]
% [-0.25     0.375]      [1]

% [ 0.25    -0.375]      [1]