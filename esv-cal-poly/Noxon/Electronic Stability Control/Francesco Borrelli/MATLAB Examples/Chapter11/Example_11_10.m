%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 11_10
% \label{ex:mintime}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

Double_Integrator;
sysStruct.B = [0;1];
sysStruct.ymin = [-10;-10];
sysStruct.ymax = [ 10; 10];
probStruct.Q = eye(2);
probStruct.R = 0.1;
probStruct.norm = 2;
[Kdummy,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
Xautonomous=polytope([eye(2);-eye(2);-Kdummy;+Kdummy],[sysStruct.ymax;-sysStruct.ymin;sysStruct.umax;-sysStruct.umin]);
[Oinf,tstar,fd,isemptypoly] = mpt_infset(sysStruct.A-sysStruct.B*Kdummy,Xautonomous,100);

probStruct.subopt_lev = 1; % Compute Minimum time solution
probStruct.Tconstraint=2;
probStruct.Tset = Oinf; % Oinf LQR terminal contraint
probStruct.P_N=P;
ftsize=28;
probStruct.N = inf;
ctrl = mpt_control(sysStruct,probStruct);
Optionsc.wire=1;
Optionsc.linewidth=3;

     %%%%%%%%%Plot Control partition
     figure 
     plot(ctrl,Optionsc)
     set(gca,'FontSize',ftsize)
     hold on
     Options2.color=[.5 .5 .5]; % Gray color
     plot(Oinf,Options2)
     axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])

     title('')
     xlb=['{\it x}_1'];
     ylb=['{\it x}_2'];
     xlabel(xlb)
     ylabel(ylb)
     print(gcf,'-depsc2',['mintime_partition.eps']);
 
     %%%%%%%%%%%%%% plot Controller
     Options5.shade=0.2;
     Options5.samecolors=0; 
     figure 
     mpt_plotPWA(ctrl.Pn,ctrl.Fi,ctrl.Gi,Options5) 
     set(gca,'FontSize',ftsize)
     %axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
     title('')
     xlb=['{\it x}_1'];
     ylb=['{\it x}_2'];
     zlb=['{\it u}'];
     xlabel(xlb)
     ylabel(ylb)
     zlabel(zlb)
     print(gcf,'-depsc2',['mintime_ctrl.eps']);

     
% 
% [H1,K1]=double(crtl.Pn);
% F1=crtl.Fi;
% G1=crtl.Gi;
% matlab2latex2(H1,K1,F1,G1,[],'test',1,2,1,1);
% 
