%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 12_5
% \label{ex2:mpc_1norm}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5


Double_Integrator
%Double_Integrator;
sysStruct.umin    =   -1;
sysStruct.umax    =   1;
sysStruct.xmin = [-5;-5];
sysStruct.xmax = [ 5; 5];
probStruct=[];
probStruct.Q = eye(2);
probStruct.R = 20;
probStruct.norm=Inf;
%[Kdummy,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
%probStruct.P_N=P;
ftsize=28;


%%%%%%%%%%
%% Case 1

probStruct.N = 6;
probStruct.Tconstraint = 0;
%probStruct.P_N=rand(10,2);
%Xzero=polytope([eye(2);-eye(2)],[0*sysStruct.xmax+1e-5;0*sysStruct.xmin+1e-5]);
%probStruct.Tset=Xzero;
ctrl{1} = mpt_control(sysStruct,probStruct);
opcrtl{1}=mpt_simplify(ctrl{1});
ctrlonline{1} = mpt_control(sysStruct,probStruct,'on-line');
%%%%%%%%%%

%%%%%%%%%%
%% Case 2
probStruct.N = 18;
probStruct.Tconstraint = 0;
%probStruct.P_N=rand(10,2);
%Xzero=polytope([eye(2);-eye(2)],[0*sysStruct.xmax+1e-5;0*sysStruct.xmin+1e-5]);
%probStruct.Tset=Xzero;
ctrl{2} = mpt_control(sysStruct,probStruct);
opcrtl{2}=mpt_simplify(ctrl{2});
ctrlonline{2} = mpt_control(sysStruct,probStruct,'on-line');
%%%%%%%%%%

[U,feasible,region,cost,details] = mpt_getInput(ctrl{2},[0;0]);
%details.inwhich
nrc=length(details.inwhich);
Ptcost=[];
for j=1:nrc
Ptcost=[Ptcost;ctrl{2}.Bi{details.inwhich(j)}];
end

%%%%%%%%%%
%% Case 3
probStruct.N = 6;
probStruct.Tconstraint = 0;
probStruct.P_N=Ptcost;
ctrl{3} = mpt_control(sysStruct,probStruct);
opcrtl{3}=mpt_simplify(ctrl{3});
ctrlonline{3} = mpt_control(sysStruct,probStruct,'on-line');



XSet=union(opcrtl{1}.Pn);
Options.color=white; 
Options.linewidth=2;
Options.wirestyle='--';

for ii = 1:3,
X0 = [-4,2; -2, 2; 0, 0.5; 4, -2; -1, -1; 2, -0.5];
figure 
hold on
%plot(ctrl{ii})
plot(XSet, Options)
for k=1:size(X0,1)
    n_points = 50;
    [X,U,Y,D,cost,trajectory,feasible]=mpt_computeTrajectory(ctrl{ii},X0(k,:)',n_points,[]);
    plot(X(:,1), X(:,2),'ko-','LineWidth',2,'MarkerSize',7),
end
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['double_int_ninf_case' num2str(ii) '.eps']);
end

for ii = 1:3,
figure 
hold on
plot(opcrtl{ii})
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ddouble_int_ninf_case' num2str(ii) '.eps']);
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Store LP matrices
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
!del LPmatcase1
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.H,'H','LPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.G,'G','LPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.E,'E','LPmatcase1')
mat2latexmat(ctrlonline{1}.details.yalmipMatrices.W,'W','LPmatcase1')

!del LPmatcase3
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.H,'H','LPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.G,'G','LPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.E,'E','LPmatcase3')
mat2latexmat(ctrlonline{3}.details.yalmipMatrices.W,'W','LPmatcase3')

%% infinite time solution
[H1,K1]=double(ctrl{2}.Pn(details.inwhich));
F1=ctrl{2}.Fi(details.inwhich);
G1=ctrl{2}.Gi(details.inwhich);
matlab2latex2(H1,K1,F1,G1,[],'ItimeNinfsol',1,2,1,1);


%% infinite time solution
[H1,K1]=double(opcrtl{1}.Pn);
F1=opcrtl{1}.Fi;
G1=opcrtl{1}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'solninf1',1,2,1,1);

%% infinite time solution
[H1,K1]=double(opcrtl{3}.Pn);
F1=opcrtl{3}.Fi;
G1=opcrtl{3}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'solninf3',1,2,1,1);



