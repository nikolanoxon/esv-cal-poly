%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 10_1
% \label{ex:unconinfnorm}
% Francesco Borrelli July November 09 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
clear all

%x(k+1)=Ax(k)+Bu(k)
sysStruct.A= [1 1; 0 1];
sysStruct.B= [0; 1];
A= [1 1; 0 1];
B= [0; 1];

%y(k)=Cx(k)+Du(k)
sysStruct.C= [1 0; 0 1];
sysStruct.D= [0;0];
C= [1 0; 0 1];
D= [0;0];


% string labels for states, inputs and outputs
sysStruct.StateName = { 'Position', 'Speed' }; 
sysStruct.InputName = 'Acceleration';
sysStruct.OutputName = { 'Position', 'Speed' };

%set constraints on input and outputs
sysStruct.umin    =   -inf;
sysStruct.umax    =   inf;
sysStruct.ymin = [-inf;-inf];
sysStruct.ymax = [ inf; inf];

Q = eye(2);
R = 20;
probStruct.norm = inf;
probStruct.Tconstraint = 0; % no terminal contriant
ftsize=28;


%  STEP N-1 Translation of problem :
%  min                         eps
%     eps,epsu,epsx,u(N-1)  
%
%	s.t.    epsu+epsx					<=eps
%       	  r*u(N-1)					<=epsu
%          -r*u(N-1)					<=epsu
%       	  q*(x(N-1)+u(N-1)+1)	<=epsu
%          -q*(x(N-1)+u(N-1)+1)	<=epsu
%       	  q*(x(N-1)+u(N-1)-1)	<=epsu
%          -q*(x(N-1)+u(N-1)-1)	<=epsu
%

% Result of solution of Step N-1 
%    Jopt=PWLf(x(N-1)) x(N-1).  Let nR the number of PWLfunctions

% Step N-2 Problem formulation:
%  min       |r*u(N-2)+|q*x(N-1)|+Jopt(x(N-1))  
%     u(N-2)  
%
% 7 - Translation of problem:
%  min                         eps
%     eps,epsu,epsx,epsJopt,u(N-2)  
%
%	s.t.    epsu+epsx+epsJopt<=eps
%  
%				"c1*x(N-1)=c1*(Ax(N-2)+Bu(N-2))+d1<=epsJopt"   
%				c1*(Ax(N-2)+Bu(N-2))+d2 <=epsJopt   
%				c2*(Ax(N-2)+Bu(N-2))+d3 <=epsJopt   
%                    :           <=   :
%				cnR*(Ax(N-2)+Bu(N-2))<=epsJopt   
%				-c1*(Ax(N-2)+Bu(N-2))-d1	<=epsJopt   
%				-c2*(Ax(N-2)+Bu(N-2))-d2	<=epsJopt
%							:           <=   :
%				-cnR*(x(N-1)+u(N-2)-1)<=epsJopt   
%           r*u(N-2)					<=epsu
%           -r*u(N-2)				<=epsu
%       	   q*(x(N-2)+u(N-2)+1)	<=epsu
%           -q*(x(N-2)+u(N-2)+1)	<=epsu
%       	   q*(x(N-2)+u(N-2)-1)	<=epsx
%           -q*(x(N-2)+u(N-2)-1)	<=epsx
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%% Algorithm Implementation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

nu=1;
nx=2;
ny=2;
Inu=eye(nu);
xe=[0;0];
ue=0;
maxiter=100;
%%%%%%%%%%%%%%%%%%%%%
%%% Intialization:
%%%%%%%%%%%%%%%%%%%
% Option 1 Pn=0
% nR=0;
% Option 2 Pn=Q
 nR=4;
 Joptl{1}=Q(1,:);
 Joptl{2}=-Q(1,:);
 Joptl{3}=Q(2,:);
 Joptl{4}=-Q(2,:);
 Joptc{1}=0;
 Joptc{2}=0;
 Joptc{3}=0;
 Joptc{4}=0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%% Algorithm Starts
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


notfound=1;
jj=0;
while notfound & jj<maxiter
   jj=jj+1;
   fprintf('************ STEP %d *************\n', jj);
   %At time j: Build cost function and constraint matrices
   % optvar=[ eps,epsJopt,epsuj,epsxj,uj]  
   % f= epsJopt
   f=[1 0 0 0 zeros(1,nu)]';
   
	% to construct G optvar<=S+Wx
	% G=[- 1           	1				1             1               zeros(1,nu) ;
    %    zeros(2*nu,2) 					I1            zeros(2*nu,nu)  I2				;
	%    zeros(nR,1)  	Ij				zeros(nR,1)   zeros(nR,nu)    Ju          ; 
	%    zeros(2*nu,2) 					zeros(2*nx,1) I3            	L 	         ;
	%    zeros(2*nu,2) 					zeros(o,2)     					Bc 			]
	% W=[0;zeros(2*nu,nx);Jx; W; -Ac];
	% S=[0;S1;Jc;S2;Cc];


   I1	=	-1*ones(2*nu,1);
   I2	=	[R;-R];
   S1	=	[-R*ue;R*ue]; 
   Ij	=	-1*ones(nR,1);
   if nR>0,
   	Ju=[];
   	Jx=[];
   	Jc=[];
   	for k=1:nR;
     	 Ju=[Ju;Joptl{k}*B];
     	 Jx=[Jx;-Joptl{k}*A];
     	 Jc=[Jc;-Joptc{k}];
      end
   else
   	Ju=zeros(nR,nu);
   	Jx=zeros(nR,nx);
   	Jc=zeros(nR,1);
    Joptl=[];
   end
   
   
   I3 = -1*ones(2*nx,1);
   L 	= [-Q*B;+Q*B]; 
   W  = [Q*A;-Q*A]; 
   S2 = [-Q*xe;Q*xe];
   
   %% CONSTRUCT NOW THE MATRICES%%%
   % optvar=[ eps,epsJopt,epsuj,epsxj,uj]  
   % G optvar<=S+W xj+O wj

    G=[ -1           	1				   1             1               zeros(1,nu) ;
        zeros(2*nu,2) 					I1            zeros(2*nu,nu)  I2				;
	    zeros(nR,1)  	Ij					zeros(nR,1)   zeros(nR,nu)    Ju          ; 
	    zeros(2*nx,2) 					zeros(2*nx,1) I3            	L 	         ];
	 W=[zeros(1,nx);zeros(2*nu,nx);Jx; W];
	 S=[0;S1;Jc;S2];
	
   
	% Solve mp-LP
   % If its the first step and the cost to go is 0, remove the variable epsJopt
   if jj==1 & nR==0,
      G(:,2)=[];
      f(2)=[];
   end
    Matrices.H=f;
    Matrices.G=G;   
    Matrices.W=S;
    Matrices.E=W;
    Matrices.bndA=[1 0;-1 0;0 1; 0 -1];   
    %Limits on exploration space, i.e. bndA*x<=bndb
    Matrices.bndb=[ 100;100;100;100];
    [Pn,Fi,Gi,activeConstraints,Phard,details]=mpt_mplp(Matrices)   
    
    [Hi,Ki]=double(Pn);
    nR=length(Ki);
   
   % Compute Joptf Joptc;
    nR=length(Ki);
    Joptlnew=[];
    Joptcnew=[];
    for j=1:nR,
       Joptlnew{j}=details.Bi{j};
       Joptcnew{j}=details.Ci{j};
    end
% Check if converged
if length(Joptlnew)==length(Joptl),
    notequalJfound=0;
    kk=1;
    while kk<=nR & ~notequalJfound
     nl=0;
     ii=1;
     while ii<=nR & ~nl
        if norm(Joptlnew{kk}-Joptl{ii},2)<1e-10 & norm(Joptcnew{kk}-Joptc{ii},2)<1e-10,
           nl=1;
        end
      ii=ii+1;
     end
    notequalJfound=~nl;
    kk=kk+1;
    end
else
        notequalJfound=1;
end

notfound=notequalJfound;
Joptl=Joptlnew;
Joptc=Joptcnew;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%% Algorithm Ends
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if nR>0,
    Jx=[];
    for k=1:nR;
        Jx=[Jx;Joptl{k}];
    end
end

figure 
    plot(Pn)
    set(gca,'FontSize',ftsize)
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    zlb=['{\it J}^*({\it x})'];
    xlabel(xlb)
    ylabel(ylb)
    set(gca,'FontSize',ftsize)
%    axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
    hold on
    mpt_plotPWA(Pn,Joptl,Joptc);
    zlabel(zlb);
    title('')
    print(gcf,'-depsc',['dd_inf_infinite_Nr_' num2str(length(Fi)) '.eps']);

matlab2latex2(Hi,Ki,Fi,Gi,[],'test',1,2,1,1);
