%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 13_4
%\label{ex:robinvset1}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

close all
clear all

%%% use laprint to produce pictures
uselaprint=1;

% Stable System
A=[0.5 0;1 -0.5];
B=[0;0];
C=[0 1];
D=0;
sysStruct = mpt_sys(ss(A,B,C,D,1)); %
sysStruct.umin = -5;
sysStruct.umax = 5;
sysStruct.xmin = [-10;-10];
sysStruct.xmax = [ 10; 10];
name = 'ex_14_1';
W=polytope([eye(2);-eye(2)],[1;1;1;1]);
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
sysStruct.noise = W;



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Start Computation of robust Invariant
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


nx = size(sysStruct.A,1);
nu = size(sysStruct.B,2);

% laprint options
if uselaprint
    set(0,'defaulttextinterpreter','none')
    width = 6;
end

% plot options
ftsize=28;
Options.color=[.5 .5 .5]; % Gray color
Options2.color=[.7 .7 .7]; % Light Gray
Options2.shade = 0.5;

W=sysStruct.noise;
X = polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
U = polytope([1;-1],[sysStruct.umax;-sysStruct.umin]);

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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% End Computation of robust Invariant
% "Omega" is the invariant Set
% The determineness index is "iter"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


figure
plot(X,Options2)
hold on
plot(Xpre,Options) 
border = 1;
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])

if uselaprint
    xlabel('$x_1$')
    ylabel('$x_2$')
    title('')
    text(8,-8,'\large $\mathcal{X}$')
    text(-4.5,-0.5,'\large Pre($\mathcal{X}$,$\mathcal{W}$)')
    laprint(gcf,['RobInv_' name],'width',width)    
else
    set(gca,'FontSize',ftsize)
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
    % H = text(8,-8,'{\it X}')
    % get(H)
    % set(H,'FontSize',ftsize)
    % text(-1,-1,'Pre({\it X})')
    print(gcf,'-depsc2',['RobInv_' name '.eps']);
end

