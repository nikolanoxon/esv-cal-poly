% Example 15.1
% Two Mode System
% Francesco Borrelli Feb 2010

sysStruct = mpt_sys('bm99');

% 
% disp('The affine state and output update functions have the form:');
% disp('  x(k+1) = A{i} x(k) + B{i} u(k) + f{i}');
% disp('  y(k)   = C{i} x(k) + D{i} u(k) + g{i}');
% fprintf('\n');
% disp('Dynamic no. 1 is defined as follows:');
% fprintf('\n');
% disp('>> sysStruct.A{1} = 0.8*[cos(-pi/3) -sin(-pi/3); sin(-pi/3) cos(-pi/3)];');
% disp('>> sysStruct.B{1} = [0;1];');
% disp('>> sysStruct.f{1} = [0;0];');
% disp('>> sysStruct.C{1} = [1 0;0 1];');
% disp('>> sysStruct.D{1} = [0;0];');
% disp('>> sysStruct.g{1} = [0;0];');
% fprintf('\n');
% disp('The dynamic is active in a polyhedral set given by the following equation:');
% disp('  guardX{1}*x(k) <= guardC{1}');
% fprintf('\n');
% disp('>> sysStruct.guardX{1} = [1 0];');
% disp('>> sysStruct.guardC{1} = [  0];');
% fprintf('\n\n');    
% disp('And then dynamic no. 2:');
% fprintf('\n');
% disp('>> sysStruct.A{2} = 0.8*[cos(pi/3) -sin(pi/3); sin(pi/3) cos(pi/3)];');
% disp('>> sysStruct.B{2} = [0;1];');
% disp('>> sysStruct.f{2} = [0;0];');
% disp('>> sysStruct.C{2} = [1 0;0 1];');
% disp('>> sysStruct.D{2} = [0;0];');
% disp('>> sysStruct.g{2} = [0;0];');
% fprintf('\n');
% disp('The dynamic is active in a polyhedral set given by the following equation:');
% disp('  guardX{2}*x(k) <= guardC{2}');
% fprintf('\n');
% disp('>> sysStruct.guardX{2} = [-1 0];');
% disp('>> sysStruct.guardC{2} = [   0];');
% fprintf('\n');
% disp('Along with the system constraints:');
% disp('>> sysStruct.ymin = [-10;-10];');
% disp('>> sysStruct.ymax = [10;10];');
% disp('>> sysStruct.umin = -1;');
% disp('>> sysStruct.umax = 1;');


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CONTOL DESING WITH INFTY NORM
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
probStruct.Q = eye(2);
probStruct.R = 1;
%%%%%%%Use infinity norm
probStruct.norm = inf;
probStruct.N = 3;
probStruct.subopt_lev = 0;
probStruct.Tconstraint = 2;
Xzero=polytope([eye(2);-eye(2)],[0.01;0.01;0.01;0.01]);
probStruct.Tset=Xzero;
ctrl = mpt_control(sysStruct, probStruct);

figure 
ftsize=28;
plot(ctrl)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_3_1.eps']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MPC SIMULATIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Tend=25;
T=0:Ts:Tend*Ts;
u1=3;
ftsize=28;
x0=[-2;2];
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
axis([0,Tend*Ts,-2,2])
title('')
xlb=['time'];
ylb=['{\it x}_1 and {\it x}_2'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_3_s1.eps']);

figure
hold on
hp=plot(T(1:end-1),U(:,1))
set(hp,'linewidth',2.0);
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
axis([0,Tend*Ts,-2,2])
title('')
xlb=['time'];
ylb=['{\it u}'];
xlabel(xlb)
ylabel(ylb)
grid on 
print(gcf,'-depsc2',['ex16_3_s2.eps']);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CONTOL DESING WITH TWO NORM
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
probStruct.norm = 2;
ctrln2 = mpt_control(sysStruct, probStruct);
figure 
ftsize=28;
plot(ctrln2)
set(gca,'FontSize',ftsize)
axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_3_2.eps']);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MPC SIMULATIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Tend=25;
T=0:Ts:Tend*Ts;
u1=3;
ftsize=28;
x0=[-2;2];
[X,U,Y,D,cost,trajectory,feasible]=mpt_computeTrajectory(ctrln2,x0,Tend);
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
axis([0,Tend*Ts,-2,2])
title('')
xlb=['time'];
ylb=['{\it x}_1 and {\it x}_2'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_3_s3.eps']);

figure
hold on
hp=plot(T(1:end-1),U(:,1))
set(hp,'linewidth',2.0);
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
axis([0,Tend*Ts,-2,2])
title('')
xlb=['time'];
ylb=['{\it u}'];
xlabel(xlb)
ylabel(ylb)
grid on
print(gcf,'-depsc2',['ex16_3_s4.eps']);

