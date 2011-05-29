%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 11_9 -DP Version -------
% \label{ex:FOTOC_DP}
% Francesco Borrelli February 2010
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Double_Integrator;
sysStruct.B = [0;1];
sysStruct.ymin = [-10;-10];
sysStruct.ymax = [ 10; 10];
probStruct.Q = eye(2);
probStruct.R = 0.8;
probStruct.norm = inf;
probStruct.Tconstraint = 0; % no terminal contriant
ftsize=28;

NNN=6;
for ii = 1:NNN,
    probStruct.N = 1;
    if ii>1
        % Do not use terminal constraint.
        probStruct.P_N = zeros(2,2);
    end
    [G,W,S,c,f]=mpt_constructMatrices(sysStruct,probStruct);
    %     J=min_eps   c eps + fx
    %     G U <= W + S x(0)
    % Variables are eps=[u,epsx_j,epsx_{j+1},eps_u]
    if ii>1
        % Modify G,W,S to take into account the rerminal cost
        %epsx_{j+1}<=Jcdual*(Ax)+Jcdual*(By)+J1dual=(-W'*Vx.V')';
        mcost=size(Jcdual,1);
        nu=size(sysStruct.B,2);
        nx=size(sysStruct.B,1);
        Gadd=[-Jcdual*sysStruct.B,zeros(mcost,1),-ones(mcost,1),zeros(mcost,1)];
        Sadd=Jcdual*sysStruct.A;
        Wadd=J1dual;
        G=[G;Gadd];
        S=[S;Sadd];
        W=[W;Wadd];
        Gadd=[Jcdual*sysStruct.B,zeros(mcost,1),-ones(mcost,1),zeros(mcost,1)];
        Sadd=-Jcdual*sysStruct.A;
        Wadd=-J1dual;
        G=[G;Gadd];
        S=[S;Sadd];
        W=[W;Wadd];
        [Ared,Bred]=double(polytope([G -S],W));
        W=Bred;
        G=Ared(:,1:end-nx);
        S=-Ared(:,end-nx+1:end);
    end
    
     Aa1=-G'; 
     Ab1=c';

    %**************************************
    % This should work but cdd-mex has a problem with equality constaitns!
%     Aa2=-eye(size(Aa1,2));
%     Ab2=zeros(size(Aa1,2),1);
%     Hx=struct('A',[Aa1;Aa2],'B',[Ab1;Ab2],'lin',(1:size(Ab1,1))');
%     % H.lin=indices of equality constraints
%     Vx=cddmex('extreme',Hx);
%     %Computing feasible region Xf
%     Xbdual=(W'*Vx.R')';
%     Xadual=(-S'*Vx.R')';
%     %Computing cost to go
%     J1dual=(-W'*Vx.V')';
%     Jcdual=(-S'*Vx.V')';
%     %**************************************
%**************************************
    % This should work but cdd-mex  has a problem with rays?
%     N=null(Aa1);
%     v0=Aa1\Ab1;
%     Hxx=struct('A',[-N],'B',[v0]);
%     Vx=cddmex('extreme',Hxx);
%     %Computing feasible region Xf
%     Xbdual=(W'*(N*Vx.R'))';
%     Xadual=(-S'*(N*Vx.R'))';
%     %Computing cost to go
%     J1dual=(-W'*(repmat(v0,1,size(Vx.V,1))+N*Vx.V'))';
%     Jcdual=(-S'*(repmat(v0,1,size(Vx.V,1))+N*Vx.V'))';
%     figure 
%     Xf=polytope(Xadual,Xbdual);
%********************************************
% Just using the primal fasible solution
    Xf=projection(polytope([-S G],W),[1:nx])
    plot(Xf)
   set(gca,'FontSize',ftsize)
   axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
   title('')
   xlb=['{\it x}_1(' num2str(NNN-ii) ')'];
   ylb=['{\it x}_2(' num2str(NNN-ii) ')'];
   xlabel(xlb)
   ylabel(ylb)
   %print(gcf,'-depsc2',['double_int_ft_ninf_h' num2str(ii) '_Nr_' num2str(length(ctrl{ii})) '.eps']);
   probStruct.Tconstraint = 2; % terminal contriant
   probStruct.Tset = Xf; %terminal contriant
   probStruct.P_N = Jcdual; %terminal cost
end
    Matrices.H=c;
    Matrices.G=G;   
    Matrices.W=W;
    Matrices.E=S;
    [bndA,bndb]=double(unitbox(2, 10));
    Matrices.bndA=bndA;   
    Matrices.bndb=bndb;
    [Pn,Fi,Gi,activeConstraints,Phard,details]=mpt_mplp(Matrices)

   %probStruct.P_N;

% [H1,K1]=double(opcrtl{1}.Pn);
% F1=opcrtl{1}.Fi;
% G1=opcrtl{1}.Gi;
% matlab2latex2(H1,K1,F1,G1,[],'test',1,2,1,1);
% 
% [H1,K1]=double(opcrtl{2}.Pn);
% F1=opcrtl{2}.Fi;
% G1=opcrtl{2}.Gi;
% matlab2latex2(H1,K1,F1,G1,[],'test2',1,2,1,1);


% to get structure from the control objects use:
% csrtuct = struct(ctrl{1});

% to simplify the controller (using optimal merging of regions):
% cs1_simple = mpt_simplify(ctrl{1},'optimal');