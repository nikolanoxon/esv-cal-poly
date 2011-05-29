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


%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
probStruct.Q = eye(2);
probStruct.R = 1;
probStruct.norm = 2;
probStruct.N = 2;
probStruct.subopt_lev = 0;
ctrl = mpt_control(sysStruct, probStruct);
Options.newfigure = 1;
plot(ctrl,Options);



