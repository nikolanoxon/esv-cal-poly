%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 12_1
% \label{ex:qppropaga}
% Francesco Borrelli October 24 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

sysStruct.A=[     1     0.3
                 0     1];
sysStruct.B = [0;1];
sysStruct.C= [1 0];
sysStruct.D= [0];
sysStruct.xmin = [-8;-8];
sysStruct.xmax = [ 8; 8];
sysStruct.umin=-0.5;
sysStruct.umax=0.5;
probStruct.Q = eye(2);
probStruct.R = 1.5;
probStruct.norm = 2;
probStruct.Tconstraint = 0;
[Klqr,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
%probStruct.P_N=P;
probStruct.P_N=probStruct.Q ;
ftsize=28;
% P_N is automatically set to solution of Lyapunov equation  (if not specified)

probStruct.N = 3;
ctrl = mpt_control(sysStruct,probStruct);
ctrlonline = mpt_control(sysStruct,probStruct,'on-line');
close all
plot(ctrl)
Mat=ctrlonline.details.yalmipMatrices;
[Pn,Fi,Gi,activeConstraints,Phard,details]=mpt_mpqp(Mat);

clear Options
Options.linewidth=0.1;
Options.FontSize=16;
plot(Pn,Options)
hold on
for j=1:length(Pn)
[x,r]=chebyball(Pn(j));
aa=[ 'CR' num2str(j)];
text(x(1),x(2),aa,Options)
end

xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2','Example7_6.eps');

xlabel('$x_1$')
ylabel('$x_2$')
title('')
laprint(gcf,'Example76l','width',6)    


break
%% Store QP matrices
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.G,'G','QPmat1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.E,'E','QPmat1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.W,'W','QPmat1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.H,'H','QPmat1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.F,'F','QPmat1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.Y,'Y','QPmat1')

