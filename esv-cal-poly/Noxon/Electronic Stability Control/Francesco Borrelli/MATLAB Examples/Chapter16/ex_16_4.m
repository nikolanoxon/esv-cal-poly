% Exmaple 15.2
% Spring-mass system
% Francesco Borrelli Feb 2010

close all
clear all

M=1;
b1=1;
b2=50;
k1=1;
k2=3;
d1=1;
d2=7.5;
xm=1;
Ts=0.5;

A1=[0 1;-k1/M -b1/M]; B1=[0 0;1/M -d1/M];
A2=[0 1;-k1/M -b2/M]; B2=[0 0;1/M -d1/M];
A3=[0 1;-k2/M -b1/M]; B3=[0 0;1/M -d2/M];
A4=[0 1;-k2/M -b2/M]; B4=[0 0;1/M -d2/M];
C=eye(2);D=zeros(2,2);
[Az1,Bz1]=c2d(A1,B1,Ts);
[Az2,Bz2]=c2d(A2,B2,Ts);
[Az3,Bz3]=c2d(A3,B3,Ts);
[Az4,Bz4]=c2d(A4,B4,Ts);

A111=Az1(1,1);A112=Az1(1,2);A121=Az1(2,1);A122=Az1(2,2);
A211=Az1(1,1);A212=Az2(1,2);A221=Az2(2,1);A222=Az2(2,2);
A311=Az1(1,1);A312=Az3(1,2);A321=Az3(2,1);A322=Az3(2,2);
A411=Az1(1,1);A412=Az4(1,2);A421=Az4(2,1);A422=Az4(2,2);
B111=Bz1(1,1);B112=Bz1(1,2);B121=Bz1(2,1);B122=Bz1(2,2);
B211=Bz1(1,1);B212=Bz2(1,2);B221=Bz2(2,1);B222=Bz2(2,2);
B311=Bz1(1,1);B312=Bz3(1,2);B321=Bz3(2,1);B322=Bz3(2,2);
B411=Bz1(1,1);B412=Bz4(1,2);B421=Bz4(2,1);B422=Bz4(2,2);

sysStruct = mpt_sys('springmass',Ts);

%*****************************************
% PWA matrices
for i=1:length(sysStruct.A),
     disp(sprintf('Mode %d:',i));
     sysStruct.A{i},sysStruct.B{i},sysStruct.f{i}
 end
%*****************************************
 
%*****************************************
%Hysdel Code
%sysStruct.data.hysdel.code
%*****************************************

%*****************************************
%MLD model
% sysStruct.data.MLD
%*****************************************

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CONTROL DESIGN
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear probStruct
probStruct.subopt_lev = 0;
probStruct.Q =  1*eye(2);
probStruct.R = [0.2  0 ;0 1];
probStruct.norm = 2;
probStruct.N = 3;
probStruct.subopt_lev = 0;
ctrl = mpt_control(sysStruct, probStruct);

figure
Options.newfigure = 1;
plot(ctrl,Options);
ftsize=28;
plot(ctrl)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_4_sol1.eps']);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MPC SIMULATIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Tend=25;
T=0:Ts:Tend*Ts;
u1=3;
ftsize=28;
x0=[3;4];
[X,U,Y,D,cost,trajectory,feasible]=mpt_computeTrajectory(ctrl,x0,Tend);
figure
hold on
hp=plot(T,X(:,1))
hs=plot(T,X(:,2))
set(hs,'linewidth',2.0);
set(hp,'linewidth',2.0);
set(hp,'linestyle','--');
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
axis([0,Tend*Ts,-1,4])
title('')
xlb=['time'];
ylb=['{\it x}_1 and {\it x}_2'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_4_1.eps']);

figure
hold on
hp=plot(T(1:end-1),U(:,1))
hs=plot(T(1:end-1),U(:,2),'*')
set(hs,'linewidth',2.0);
set(hp,'linewidth',2.0);
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
axis([0,Tend*Ts,-3,3])
title('')
xlb=['time'];
ylb=['{\it u}_1 and {\it u}_2'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_4_2.eps']);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CONTROL DESIGN WITH TERMINAL CONSTRAINT 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

probStruct.subopt_lev = 0;
probStruct.Tconstraint = 2;
Xzero=polytope([eye(2);-eye(2)],[0.01;0.01;0.01;0.01]);
probStruct.Tset=Xzero;
ctrl2 = mpt_control(sysStruct, probStruct);

figure
Options.newfigure = 1;
plot(ctrl2,Options);
ftsize=28;
plot(ctrl2)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_4_sol2.eps']);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MPC SIMULATIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



x0=[3;4];
horizon=25;
[X,U,Y,D,cost,trajectory,feasible]=mpt_computeTrajectory(ctrl2,x0,Tend);
figure
hold on
hp=plot(T,X(:,1))
hs=plot(T,X(:,2))
set(hs,'linewidth',2.0);
set(hp,'linewidth',2.0);
set(hp,'linestyle','--');
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
axis([0,Tend*Ts,-2,4])
title('')
xlb=['time'];
ylb=['{\it x}_1 and {\it x}_2'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_4_3.eps']);

figure
hold on
hp=plot(T(1:end-1),U(:,1))
hs=plot(T(1:end-1),U(:,2),'*')
set(hs,'linewidth',2.0);
set(hp,'linewidth',2.0);
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
axis([0,Tend*Ts,-8,3])
title('')
xlb=['time'];
ylb=['{\it u}_1 and {\it u}_2'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_4_4.eps']);


