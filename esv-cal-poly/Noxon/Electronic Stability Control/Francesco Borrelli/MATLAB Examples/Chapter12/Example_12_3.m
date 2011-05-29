%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 12_3
% \label{ex:rhc1rev}
% Francesco Borrelli July 05 2009
% Thomas Besselmann, 18.08.08
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
clear all
sysStruct.A=[     1     1
                 0     1];
sysStruct.B = [0;1];
sysStruct.C= [1 0];
sysStruct.D= [0];
sysStruct.xmin = [-5;-5];
sysStruct.xmax = [ 5; 5];
sysStruct.umin=-0.5;
sysStruct.umax=0.5;
probStruct.Q = eye(2);
probStruct.R = 10;
probStruct.norm = 2;
probStruct.Tconstraint = 0;
[Klqr,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
%probStruct.P_N=P;
probStruct.P_N=probStruct.Q ;
ftsize=28;
% P_N is automatically set to solution of Lyapunov equation  (if not specified)

ii=1
probStruct.N = 3;
ctrl1{ii} = mpt_control(sysStruct,probStruct);
ctrlonline{ii} = mpt_control(sysStruct,probStruct,'on-line');



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Compute Trajectory for two initial Points
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear Options;
for kk=1:2
    if kk==1, x0=[-4.5;2.0]; else x0=[-4.5;3.0]; end 
    Options.openloop = 1;
    X0 = [x0'];
    x0_temp=x0
    feas_flag=1
    for j=1:16
        [U,feasible,region,cost,details] = mpt_getInput(ctrlonline{1},x0_temp,Options);
%        if feasible==0 && feas_flag=1.
%        end       
        if feasible==0, feas_flag=0; end
        % U
        % feasible
        if feas_flag,
            [X,U,Y,mode]=mpt_simSys(sysStruct,x0_temp,U);
            X = [x0_temp';X];
            plot(X(:,1), X(:,2), 'k*-.')
            x0_temp=X(2,:)';
            X0 = [X0; x0_temp'];
        end
    end
    if kk==1, plot(X0(:,1), X0(:,2), 'ks-','LineWidth',2,'MarkerSize',10), 
    else plot(X0(:,1), X0(:,2), 'ro-','LineWidth',2,'MarkerSize',10), 
    end
   end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Compute O_inf and X0 for given controller and plot
%%%%%%%%%%%%%%
invCtrl = mpt_invariantSet(ctrl1{1});
inv_set = union(invCtrl.Pn);
XoSet = union(ctrl1{1}.Pn);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Plot Infeasible initial state +  O_inf and X0 
%%%%%%%%%%%%%%

figure
hold on;
clear Options;
%    Options.wire=1;
%    Options.wirestyle='--';
% Options.wire=;
Options.color=white; 
Options.linewidth=2;
Options.wirestyle='--';
plot(XoSet, Options)
clear Options;
  Options.color=[ 0.5 0.5 0.5];
    plot(inv_set, Options)
    %axis([-5 5.2 0 5])
plot(X0(:,1), X0(:,2), 'ro--','LineWidth',2),
%grid on
grid minor
set(gca,'FontSize',ftsize)
axis([-5 5.2 0 5])
%axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['Example13-1d.eps']);



