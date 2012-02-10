function [zdot,alpha] =  DVM3(z, steer, F_in)

%Inputs
v_x = z(1);
v_y = z(2);
psi_d = z(3);

%Car physical variables
M = 1704.7;                 %total vehicle mass
l_fs = 1.01476;             %length from CG to front suspension
I_zzs = 2619.28;            %sprung ZZ inertia
K_sr = 15.97;               %steering-to-wheel angle ratio
C_af = 25730;               %Lateral Slip Stiffness


%Slip Angle
delta = steer/(180*K_sr)*pi;
beta = atan(v_x/v_y);

alpha = beta-delta;

%Tire Forces
F_x = 0;
F_y = l_fs*alpha;
T_z = C_af*alpha;

%State Output
a_x = (1/M)*(v_y*psi_d+F_x);
a_y = (1/M)*(-v_x*psi_d+F_y);
psi_dd = (1/I_zzs)*(T_z);

zdot = [a_x, a_y, psi_dd];

%----------------------------------%
%end


