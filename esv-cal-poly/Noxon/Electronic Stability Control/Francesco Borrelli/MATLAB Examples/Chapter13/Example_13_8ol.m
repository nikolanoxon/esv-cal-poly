%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 13_8
%\label{ex:ddrobust}
% CROC-OL Design
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%x(k+1)=Ax(k)+Bu(k)
sysStruct.A= [1 1; 0 1];
sysStruct.B = [0;1];

%y(k)=Cx(k)+Du(k)
sysStruct.C= [1 0; 0 1];
sysStruct.D= [0;0];

%set constraints on output
sysStruct.ymin = [-10;-10];
sysStruct.ymax = [ 10; 10];

%set constraints on state
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];

%set constraints on input
sysStruct.umin    =   -3;
sysStruct.umax    =   3;

%set constraints on disturbace
sysStruct.dmin = [-1;-1];
sysStruct.dmax = [ 1; 1];

% string labels for states, inputs and outputs
sysStruct.StateName = { 'Position', 'Speed' }; 
sysStruct.InputName = 'Acceleration';
sysStruct.OutputName = { 'Position', 'Speed' };

probStruct.norm=inf;
probStruct.Q=[1 1;0 1];
probStruct.P=[1 1;0 1];
probStruct.R=1.8;

% This is the max horizon.
% The CROC-OL problem is infeasible for N>4
probStruct.N=7; %

% Polyhedral sets.
nx = size(sysStruct.A,1); % Number of states
nu = size(sysStruct.B,2); % Number of inputs
nw = nx;
X=polytope([eye(nx);-eye(nx)],[sysStruct.xmax;-sysStruct.xmin]);
W=polytope([eye(nw);-eye(nw)],[sysStruct.dmax;-sysStruct.dmin]);
U = polytope([eye(nu);-eye(nu)],[sysStruct.umax;-sysStruct.umin]);


% Model data
A = sysStruct.A;
B = sysStruct.B;
C = sysStruct.C;


E = eye(nx);
% Prediction horizon
Nf = probStruct.N;

clear sol
for N=2:Nf
clear x
clear u
clear w
clear x0
clear F
clear obj

% States x(k), ..., x(k+N)
%x = sdpvar(repmat(nx,1,N),repmat(1,1,N));
% Inputs u(k), ..., u(k+N) (last one not used)
u = sdpvar(repmat(nu,1,N),repmat(1,1,N));
% Uncertainty w(k), ..., w(k+N) (last one not used)
w = sdpvar(repmat(nw,1,N),repmat(1,1,N));
x0 = sdpvar(nx,1);
% initialization;
obj = 0;
Xf{N}=X;
x=x0;
[Hf,Kf]=double(Xf{N});
norm(probStruct.Q*0,inf);
F=[sysStruct.ymin<= C*x0 <= sysStruct.ymax];
for k = 1:N-1   
    x=A*x + B*u{k} + E*w{k};
    % Feasible region
if k<N-1
    F = [F, sysStruct.umin <= u{k} <= sysStruct.umax, sysStruct.ymin<= C*x <= sysStruct.ymax];
    F = [F, uncertain(w{k})];
    F = [F, sysStruct.dmin <= w{k} <= sysStruct.dmax];
    obj = obj+ norm(probStruct.Q*x,inf) + norm(probStruct.R*u{k},inf);
else
F = [F, sysStruct.umin <= u{k} <= sysStruct.umax];
if ~isempty(Hf)
F = [F, Hf*x<= Kf];
F = [F, uncertain(w{k})];
F = [F, sysStruct.dmin <= w{k} <= sysStruct.dmax];
end
obj = obj+ norm(probStruct.P*x,inf) + norm(probStruct.R*u{k},inf);
end
    % Cost in value iteratio
end
%  Solve oexplicit problem   
[sol{N},diagnost,Uz,J,Optimizer] = solvemp(F,obj,[],x0,u{1});
end


% Generate Plots
uselaprint=1;
if uselaprint
    set(0,'defaulttextinterpreter','none')
    width = 6;
end
name = 'ex_14_minmaxOL';

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure
%plot(X,Options2)
hold on
%plot(sol{1}{1}.Pn,Options2) 
plot(sol{5}{1}.Pn) 
border = 0.4;
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])
xlabel('$x_1$')
      ylabel('$x_2$')
      title('')
%     text(8,-8,'$\mathcal{X}$')
%     text(-5,0,'Reach($\mathcal{X},\mathcal{X}$)')
     laprint(gcf,['Sol_' name],'width',width)    

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Print only solution with horizon 5
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
opcrtl=mpt_simplify(sol{5}{1});
figure
%plot(X,Options2)
hold on
%plot(sol{1}{1}.Pn,Options2) 
plot(opcrtl.Pn) 
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])
xlabel('$x_1$')
ylabel('$x_2$')
title('')
%     text(8,-8,'$\mathcal{X}$')
%     text(-5,0,'Reach($\mathcal{X},\mathcal{X}$)')
laprint(gcf,['partdd_rob_ol'],'width',width) 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Printing evolution of feasible set of the CROC-OL for different horizons
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Options.color=[0 0 0]; 
Options.linewidth=2;
Options.wirestyle='--';
Options.wire=1;
Options3.color=[0.5 0.5 0.5]; % Gray color
Options3.wire=0;
figure
hold on
plot(X,Options)
for j=2:Nf
    try 
        plot(sol{j}{1}.Pfinal,Options)
    end
end
%    plot(Xf{1},Options3)    
%plot(sol{1}.Pfinal,'r')
xlabel('$x_1$')
ylabel('$x_2$')
title('')
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])

laprint(gcf,['Feasset_' name],'width',width)

save datatOL

%     text(8,-8,'$\mathcal{X}$')
%     text(-5,0,'Reach($\mathcal{X},\mathcal{X}$)')
%     laprint(gcf,['reachSet1_' name],'width',width)    




