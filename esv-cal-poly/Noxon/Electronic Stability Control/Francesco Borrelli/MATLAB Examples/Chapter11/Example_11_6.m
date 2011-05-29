%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 11_6
%\label{ex:ddfeas}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

% System Definiton 
Double_Integrator;
sysStruct.B = [0;1];
sysStruct.xmin = [-5;-5];
sysStruct.xmax = [ 5; 5];
X=polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Computing the Terminal Invariant set
probStruct.Q = eye(2);
probStruct.R = 1;
probStruct.Tconstraint = 0; % LQR terminal cost and contraint
[Kdummy,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
Xdec2=polytope([eye(2);-eye(2);-Kdummy;+Kdummy],[sysStruct.xmax;-sysStruct.xmin;sysStruct.umax;-sysStruct.umin]);
[Oinf,tstar,fd,isemptypoly] = mpt_infset(sysStruct.A-sysStruct.B*Kdummy,Xdec2,100);

% Scaling the invariant (for graphical reasons)
Xf=Oinf*0.5;

% Start Options for colors ad drawing
ftsize=28;
Options.color=[0 0 0]; 
Options.linewidth=2;
Options.wirestyle='--';
Options.wire=1;
Options_col3.color=[0.5 0.5 0.5]; % Gray color
Options_col3.wire=0;
% End Options for colors ad drawing

Options2.Tset=Xf;
Options2.Kinf=1; 
[Cinf,iterations, Piter] = mpt_maxCtrlSet(sysStruct,Options2);
interation0=iterations;

%%% Start Plot Sets
figure
hold on
plot(Piter(end),Options_col3)
for i=1:iterations
plot(Piter(i),Options)
end
Options_col3.color=[0.5 0.5 0.1]; % Gray color
plot(Piter(1),Options_col3)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1)-1,sysStruct.xmax(1)+1,sysStruct.xmin(2)-1,sysStruct.xmax(2)+1])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2','ex_feas_0.eps');
%%% End Plot Sets


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Case 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Options2.Tset=X;
Options2.Kinf=1; 
Options3.color=[0.5 0.5 0.5]; % Gray color
Options3.wire=0;
[Cinf,iterations, Piter] = mpt_maxCtrlSet(sysStruct,Options2);

figure
hold on
%plot(Piter(end),Options3)
for i=1:iterations
plot(Piter(i),Options)
end
plot(Piter(end),Options_col3)
%Options3.color=[0.5 0.5 0.1]; % Gray color
%plot(Piter(1),Options3)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1)-1,sysStruct.xmax(1)+1,sysStruct.xmin(2)-1,sysStruct.xmax(2)+1])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2','ex_feas_1.eps');




