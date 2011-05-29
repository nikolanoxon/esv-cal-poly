%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 12_1
% \label{ex:rhc2}
% Francesco Borrelli July 05 2009
% Thomas Besselmann, 18.08.08
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

Double_Integrator;
sysStruct.B = [0;1];
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];
probStruct.Q = eye(2);
probStruct.R = 0.01;
probStruct.norm = 2;
[Kdummy,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
probStruct.P_N=P;
ftsize=28;
% P_N is automatically set to solution of Lyapunov equation 
% (if not specified)
%probStruct.N = inf;
%ctrl{1} = mpt_control(sysStruct,probStruct);

%%%%%%%%%%
%% Case 1
probStruct.N = 2;
probStruct.Tconstraint = 2;
Xzero=polytope([eye(2);-eye(2)],[0*sysStruct.xmax+1e-5;0*sysStruct.xmin+1e-5]);
probStruct.Tset=Xzero;
ctrl{1} = mpt_control(sysStruct,probStruct);
opcrtl{1}=mpt_simplify(ctrl{1});
ctrlonline{1} = mpt_control(sysStruct,probStruct,'on-line');
%%%%%%%%%%
%% Case 2
probStruct.N = 2;
probStruct.Tconstraint = 2;
X=polytope([eye(2);-eye(2);-Kdummy;+Kdummy],[sysStruct.xmax;-sysStruct.xmin;sysStruct.umax;-sysStruct.umin]);
[Oinf,tstar,fd,isemptypoly] = mpt_infset(sysStruct.A-sysStruct.B*Kdummy,X,100);
probStruct.Tset=Oinf;
ctrl{2} = mpt_control(sysStruct,probStruct);
opcrtl{2}=mpt_simplify(ctrl{2});
ctrlonline{2} = mpt_control(sysStruct,probStruct,'on-line');

%%%%%%%%%%
%% Case 3
probStruct.Tconstraint = 0;
probStruct.N = 6;
ctrl{3} = mpt_control(sysStruct,probStruct);
opcrtl{3}=mpt_simplify(ctrl{3});
opcrtl{3}=mpt_simplify(opcrtl{3});
ctrlonline{3} = mpt_control(sysStruct,probStruct,'on-line');

for ii = 1:3,
figure 
plot(opcrtl{ii})
set(gca,'FontSize',ftsize)
axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['double_int_case' num2str(ii) '.eps']);
end

[H1,K1]=double(opcrtl{1}.Pn);
F1=opcrtl{1}.Fi;
G1=opcrtl{1}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'case1sol',1,2,1,1);

[H1,K1]=double(opcrtl{2}.Pn);
F1=opcrtl{2}.Fi;
G1=opcrtl{2}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'case2sol',1,2,1,1);

[H1,K1]=double(opcrtl{3}.Pn);
F1=opcrtl{3}.Fi;
G1=opcrtl{3}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'case3sol',1,2,1,1);

%% Store QP matrices
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
!del QPmatcase1
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.H,'H','QPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.F,'F','QPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.Y,'Y','QPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.G,'G','QPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.E,'E','QPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.W,'W','QPmatcase1')


!del QPmatcase2
mat2latexmat(ctrlonline{2}.details.yalmipMatrices.H,'H','QPmatcase2')
mat2latexmat(ctrlonline{2}.details.yalmipMatrices.F,'F','QPmatcase2')
mat2latexmat(ctrlonline{2}.details.yalmipMatrices.Y,'Y','QPmatcase2')
mat2latexmat(ctrlonline{2}.details.yalmipMatrices.G,'G','QPmatcase2')
mat2latexmat(ctrlonline{2}.details.yalmipMatrices.E,'E','QPmatcase2')
mat2latexmat(ctrlonline{2}.details.yalmipMatrices.W,'W','QPmatcase2')

!del QPmatcase3
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.H,'H','QPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.F,'F','QPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.Y,'Y','QPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.G,'G','QPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.E,'E','QPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.W,'W','QPmatcase3')

