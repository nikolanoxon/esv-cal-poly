%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 13_8
%\label{ex:robinvset2}
% CROC-CL Design
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all
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
probStruct.N=7;

% Polyhedral sets.
nx = size(sysStruct.A,1); % Number of states
nu = size(sysStruct.B,2); % Number of inputs
nw = nx;
X=polytope([eye(nx);-eye(nx)],[sysStruct.xmax;-sysStruct.xmin]);
W=polytope([eye(nw);-eye(nw)],[sysStruct.dmax;-sysStruct.dmin]);
U = polytope([eye(nu);-eye(nu)],[sysStruct.umax;-sysStruct.umin]);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute MAx robust COntrollable set
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Omega=X;
notfound=1;
maxiter=100;
iter=0;
while notfound && iter<maxiter
M=Omega-W;
if ~isfulldim(M) 
    return
end
[H,K] = double(M);
[Hu,Ku] = double(U);
%%% pre set
Hpre = [H*sysStruct.A   H*sysStruct.B;
         zeros(2*nu,nx)  Hu];
Kpre = [K;Ku];
Xpre = projection(polytope(Hpre,Kpre),[1,2])
Xpre=Xpre&X
if Xpre==Omega,
    notfound=0;
end
iter=iter+1;
Omega=Xpre;
end
iter
pause

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Min MAx robust Control
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Model data
A = sysStruct.A;
B = sysStruct.B;
C = sysStruct.C;


E = eye(nx);
% Prediction horizon
N = probStruct.N;
% States x(k), ..., x(k+N)
x = sdpvar(repmat(nx,1,N),repmat(1,1,N));
% Inputs u(k), ..., u(k+N) (last one not used)
u = sdpvar(repmat(nu,1,N),repmat(1,1,N));
% Uncertainty w(k), ..., w(k+N) (last one not used)
w = sdpvar(repmat(nw,1,N),repmat(1,1,N));


% initialization;
J{N} = norm(probStruct.P*x{N},inf);
Xf{N}=X;

for k = N-1:-1:1   

    [Hf,Kf]=double(Xf{k+1});
    
    % Feasible region
    F = [sysStruct.umin <= u{k}     <= sysStruct.umax, sysStruct.ymin<= C*x{k} <= sysStruct.ymax];
    if ~isempty(Hf)
        F = [F, Hf*(A*x{k} + B*u{k} + E*w{k}) <= Kf];
    end

    % Bounded exploration space
    F = [F, -100 <= x{k} <= 100];

    % Uncertain value function
    Jw = replace(J{k+1},x{k+1},A*x{k} + B*u{k} + E*w{k});

    % Declare uncertainty model
    F = [F, uncertain(w{k})];
    F = [F, sysStruct.dmin <= w{k} <= sysStruct.dmax];

    % Cost in value iteration
    obj = norm(probStruct.Q*x{k},inf) + norm(probStruct.R*u{k},inf) + Jw;

    % Solve one-step problem   
    [sol{k},diagnost{k},Uz{k},J{k},Optimizer{k}] = solvemp(F,obj,[],x{k},u{k});
    Xf{k}=sol{k}{1}.Pfinal;
    
    disp('Step') 
    k 
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Generate Plots
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% plot options
uselaprint=1;
if uselaprint
    set(0,'defaulttextinterpreter','none')
    width = 6;
end
name = 'ex_14_minmax';

figure
%plot(X,Options2)
hold on
plot(sol{1}{1}.Pn) 
border = 0.4;
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])
xlabel('$x_1$')
      ylabel('$x_2$')
      title('')
%     text(8,-8,'$\mathcal{X}$')
%     text(-5,0,'Reach($\mathcal{X},\mathcal{X}$)')
     laprint(gcf,['Sol_' name],'width',width)    

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Since we are going backwad and the horizon is 7
% solution (sol{2}{1}) at step 2 will correspond to an horizon N=5
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

opcrtl{2}=mpt_simplify(sol{2}{1});
figure
hold on
plot(opcrtl{2}.Pn) 
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])
xlabel('$x_1$')
ylabel('$x_2$')
title('')
laprint(gcf,['partdd_rob_cl'],'width',width)    

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Options.color=[0 0 0]; 
Options.linewidth=2;
Options.wirestyle='--';
Options.wire=1;
Options3.color=[0.5 0.5 0.5]; % Gray color
Options3.wire=0;
figure
hold on
for j=2:length(Xf)
    plot(Xf{j},Options)
end
    plot(Xf{1},Options3)    
%plot(sol{1}.Pfinal,'r')
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])
xlabel('$x_1$')
ylabel('$x_2$')
title('')
laprint(gcf,['Feasset_' name],'width',width)

save datatCL
