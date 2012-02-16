clc
clear
%p = [10,0,0,0,0,0]
p = [10,0,0,-0.002,0,0.08]
acc_in = [0,0,0,0,0]
steer = 42
%==constants==%
g = 9.81;
%-------------%
 
%==current states==%
v_x = p(1);
v_y = p(2);
phi = p(3);
phi_d = p(4);
psi = p(5);
psi_d = p(6);
 
a_x = acc_in(1);
a_y = acc_in(2);
phi_dd = acc_in(4);
psi_dd = acc_in(5);
%------------------%
 
%Car physical variables
l_fs = 1.01476;             %length from sprung mass CG to front suspension
l_rs = 1.67524;             %length from sprung mass CG to rear suspension
t_f = 1.540;                %front vehicle width
t_r = 1.530;                %rear vehicle width
h_f = 0.130;                %height from ground to front suspension
h_r = 0.110;                %height from ground to rear suspension
h_cgs = 0.567851;           %height from ground to sprung CG
h_cguf = 0.320;             %height from ground to front unsprung CG
h_cgur = 0.320;             %height from ground to rear unsprung CG
M = 1704.7;                 %total vehicle mass
M_uf = 98.1;                %unsprung front mass
M_ur = 79.7;                %unsprung rear mass
I_xxs = 440.911;            %sprung XX inertia
I_xys = 0;                  %sprung XY inertia
I_xzs = 7.54097;            %sprung XZ inertia
I_yys = 2498.900;           %sprung YY inertia
I_yzs = 0;                  %sprung yz inertia
I_zzs = 2619.28;            %sprung ZZ inertia
I_zzuf = M_uf*(t_f/2)^2;    %front unsprung ZZ inertia
I_zzur = M_ur*(t_r/2)^2;    %rear unsprung ZZ inertia
I_tlf = 0.99;               %front left tire inertia
I_trf = 0.99;               %front right tire inertia
I_tlr = 0.99;               %rear left tire inertia
I_trr = 0.99;               %rear right tire inertia
 
%spring/dampers
K_spf = 27.85; %N/mm
K_spr = 18.16; %N/mm
 
B_f = 2.9915; %N-s/mm
B_r = 2.9915; %N-s/mm
 
%anti_roll bars
K_rf = 384.0*180/pi; %Nm/rad
K_rr = 344.4*180/pi;
 
%roll stiffness
K_phif = 0.766*K_spf*1000*t_f^2/2 + K_rf;%
K_phir = 0.827*K_spr*1000*t_r^2/2 + K_rr;%
K_phi = (K_phif + K_phir);
 
%roll damping
B_phif = 0.766*B_f*1000*t_f^2/2; %Nm-s/rad
B_phir = 0.827*B_r*1000*t_r^2/2;
B_phi = (B_phif + B_phir);
 
K_sr = 15.97; %steering-to-wheel angle ratio
 
%==calculated parameters==%
L = l_fs + l_rs;                    %distance from front to rear suspension
M_s = M - M_uf - M_ur;              %sprung mass
M_u = M - M_s;                      %total unsprung mass
l_cgs = (M_ur*l_rs - M_uf*l_fs)/M;  %distance from vehicle CG to sprung CG
l_f = l_fs + l_cgs;                 %distance from vehicle CG to front suspension
l_r = l_rs - l_cgs;                 %distance from vehicle CG to rear suspension
M_f = M*l_r/L;                      %front vehicle mass
M_r = M*l_f/L;                      %rear vehicle mass
h_o = h_f + l_f*(h_r - h_f)/L;      %height from ground to roll axis
h_s = h_cgs - h_o;                  %height from roll axis to sprung CG
h_uf = h_cguf - h_o;                %height from roll axis to front suspension
h_ur = h_cgur - h_o;                %height from roll axis to rear suspension
h_cg = (M_s*h_cgs + M_uf*h_cguf + M_ur*h_cgur)/M;   %height from gound to vehicle CG
%----------------------------%
 
%==tire properties==%
varx = [...
    0.0, 0.0;...
    0.1, 0.6;...
    0.15, 0.85;...
    1.0, 0.4]; %slip curve coordinates (slip-%, mu)
vary = [...
    0.0, 0.0;...
    0.08, 0.4;...
    0.15, 0.6;...
    0.3, 0.8;...
    1.0, 0.4]; %slip curve coordinates (slip-%, mu) 
varM = [...
    0.0, 0.0;...
    0.1, 0.0005;...
    0.3, 0.00025;...
    1.0, 0.0]; %slip angle (slip-angle, Moment-arm)
 
 
%tire properties
t_wid = 0.175;
t_rad = 0.292;
t_pressure = 275000;
 
%---------------------%
 
%==steering inputs==%
d_steer = steer;
delta = d_steer/(180*K_sr)*pi; %radians
%-------------------%
 
%==calculate internal accelerations==%
a_sx = a_x ...
     - psi_d*v_y ...
     - 2*h_s*phi_d*psi_d*cos(phi) ...
     - l_cgs*psi_d^2;
a_sy = psi_d*v_x ...
     + l_cgs*psi_dd ...
     + h_s*cos(phi)*phi_dd ...
     - h_s*phi_d^2*sin(phi) ...
     - h_s*psi_d^2*sin(phi);
a_ufx = a_x - l_f*psi_d^2;
a_ufy = a_y + l_f*psi_dd;
a_urx = a_x + l_r*psi_d^2;
a_ury = a_y - l_r*psi_dd;
%-------------------------------------%
 
%==rotation Matrix==%
ROT = [1,0,0;
       0,cos(phi),sin(phi);
       0,-sin(phi),cos(phi)];
 
I_b = [I_xxs+M_s*h_s^2,I_xys,I_xzs+M_s*h_s*l_cgs;...
       I_xys,I_yys+M_s*(h_s^2+l_cgs^2),I_yzs;...
       I_xzs+M_s*h_s*l_cgs,I_yzs,I_zzs+M_s*l_cgs^2];
   
I_c = ROT*I_b*ROT'; %chassis M.o.I. tensor
 
I_zzus = M_uf*l_f^2 + ...
         M_ur*l_r^2 + ...
         I_zzuf + I_zzur;
 
I_zzo = I_c(3,3) + I_zzus; %effective I_zz
%---------------------------------------------%
 
%==Dynamic Weight Transfer Forces==%
% Fzax = (M_s*h_s*a_sx + M_uf*h_uf*a_ufx + M_ur*h_ur*a_urx)/(2*L);
% 
% Fzayf = 1/t_f*(M_s*l_r*h_f/L*a_sy + M_uf*h_uf*a_ufy);
% Fzayr = 1/t_r*(M_s*l_f*h_r/L*a_sy + M_ur*h_ur*a_ury);
% 
% Fzphif = -1/t_f*(K_phif*phi + B_phif*phi_d);
% Fzphir = -1/t_r*(K_phir*phi + B_phir*phi_d);
%----------------------------------%
 
%==Tire Normal Forces==% 
% Fzlf = M*g*l_r/(2*L) - Fzax - Fzayf + Fzphif;
% Fzrf = M*g*l_r/(2*L) - Fzax + Fzayf - Fzphif;
% Fzlr = M*g*l_f/(2*L) + Fzax - Fzayr + Fzphir;
% Fzrr = M*g*l_f/(2*L) + Fzax + Fzayr - Fzphir;

Fzlf = M*g*l_r/(2*L);
Fzrf = M*g*l_r/(2*L);
Fzlr = M*g*l_f/(2*L);
Fzrr = M*g*l_f/(2*L);
%----------------------%
 
%==Tire Longitudinal/Lateral Forces==%
%left front wheel velocity
vx_lf = v_x + psi_d*t_f/2;
vy_lf = v_y + psi_d*l_f;
 
%right front wheel velocity
vx_rf = v_x - psi_d*t_f/2;
vy_rf = v_y + psi_d*l_f;
 
%left rear wheel velocity
vx_lr = v_x + psi_d*t_r/2;
vy_lr = v_y - psi_d*l_r;
 
%right rear wheel velocity
vx_rr = v_x - psi_d*t_r/2;
vy_rr = v_y - psi_d*l_r;  

% %---------------------------------------%
% %SLIP ANGLES HIRTLE
% %---------------------------------------%
% beta_lf = atan(vy_lf/vx_lf);
% beta_rf = atan(vy_rf/vx_rf);
% beta_lr = atan(vy_lr/vx_lr);
% beta_rr = atan(vy_rr/vx_rr);
%  
% a_lf = beta_lf - delta;
% a_rf = beta_rf - delta;
% a_lr = beta_lr;
% a_rr = beta_rr;
%  
% slp_ang = [a_lf,a_rf,a_lr,a_rr];
% %---------------------------------------%
% %END SLIP ANGLES HIRTLE
% %---------------------------------------%

%---------------------------------------%
%SLIP ANGLES NIKOLA
%---------------------------------------%
% Tire longitudinal and cornering velocities
vc_lf = vy_lf*cos(delta) - vx_lf*sin(delta);
vl_lf = vy_lf*sin(delta) + vx_lf*cos(delta);

vc_rf = vy_rf*cos(delta) - vx_rf*sin(delta);
vl_rf = vy_rf*sin(delta) + vx_rf*cos(delta);

vc_lr = vy_lr;
vl_lr = vx_lr;

vc_rr = vy_rr;
vl_rr = vx_rr;

% Slip angles
a_lf = atan(vc_lf/vl_lf);
a_rf = atan(vc_rf/vl_rf);
a_lr = atan(vc_lr/vl_lr);
a_rr = atan(vc_rr/vl_rr);

slp_ang = [a_lf,a_rf,a_lr,a_rr];
%---------------------------------------%
%END SLIP ANGLES NIKOLA
%---------------------------------------%

%Linearized Force Coefficients (C_alpha)
C_alf = vary(2,2)/vary(2,1)*Fzlf;
C_arf = vary(2,2)/vary(2,1)*Fzrf;
C_alr = vary(2,2)/vary(2,1)*Fzlr;
C_arr = vary(2,2)/vary(2,1)*Fzrr;

Fxtlf = 0;
Fxtrf = 0;
Fxtlr = 0;
Fxtrr = 0;
 
Fytlf = -a_lf*C_alf;
Fytrf = -a_rf*C_arf;
Fytlr = -a_lr*C_alr;
Fytrr = -a_rr*C_arr;
 
Fxlf = Fxtlf*cos(delta) - Fytlf*sin(delta);
Fxrf = Fxtrf*cos(delta) - Fytrf*sin(delta);
Fxlr = Fxtlr;
Fxrr = Fxtrr;
 
Fylf = Fytlf*cos(delta) + Fxtlf*sin(delta);
Fyrf = Fytrf*cos(delta) + Fxtrf*sin(delta);
Fylr = Fytlr;
Fyrr = Fytrr;
 
Fout = [Fylf,Fyrf,Fylr,Fyrr];
%---------------------------------------%

%==Tire Moments==%
Mzlf = 0;
Mzrf = 0;
Mzlr = 0;
Mzrr = 0;

%==Torques==%
T_phif = -K_phif*phi - B_phif*phi_d;
T_phir = -K_phir*phi - B_phir*phi_d;
%-----------%
 
%==Sum forces and torques==%
sigFx   = Fxlf + Fxrf + Fxlr + Fxrr;
sigFy   = Fylf + Fyrf + Fylr + Fyrr;
% sigTxs  = T_phif + T_phir - ...
%           M_s*g*h_s*sin(phi);
sigTxs  = T_phif + T_phir - ...
          M_s*g*h_s*sin(phi) + M_s*h_s*a_sy*cos(phi);
sigTz   = (Fylf + Fyrf)*l_f - (Fylr + Fyrr)*l_r + ...
          t_f/2*(Fxlf - Fxrf) + t_r/2*(Fxlr - Fxrr) + ...
          Mzlf + Mzrf + Mzlr + Mzrr;
%--------------------------%

% %---------------------------------------%
% %EoM HIRTLE
% %---------------------------------------%
% a_x_new =  psi_d*v_y + (sigFx + ...
%            M_s.*(-2*h_s.*phi_d.*psi_d.*cos(phi) - ...
%            h_s.*psi_dd.*sin(phi)))./M;
% a_y_new = -psi_d*v_x + (sigFy - ...
%            M_s*(-h_s*phi_dd*cos(phi) + ...
%            h_s*phi_d^2*sin(phi) + ...
%            h_s*psi_d^2*sin(phi)))./M;
% phi_dd_new = (sigTxs - ...
%            (I_xzs-M_s*h_s*l_cgs)*cos(phi)*psi_dd + ...
%            (I_xzs-M_s*h_s*l_cgs)*sin(phi)*phi_d*psi_d + ...
%            (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi)*psi_d^2)./ ...
%            (I_xxs+M_s*h_s^2)
% psi_dd_new = (sigTz - ...
%            (I_xzs-M_s*h_s*l_cgs)*cos(phi)*phi_dd - ...
%            (I_xzs-M_s*h_s*l_cgs)*sin(phi)*phi_d^2 - ...
%             M_s*h_s*a_x*sin(phi) - ...
%            (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi)*psi_d*phi_d)./ ...
%             I_zzo;
% %---------------------------------------%
% %EoM HIRTLE END
% %---------------------------------------%

%---------------------------------------%
%EoM NOXON
%---------------------------------------%
%==Equations of Motion==%

% mass matrix for coupled equations of motion
Am  = M_s*h_s*sin(phi);
Bm  = -M_s*h_s*cos(phi);
Cm  = (I_xzs+M_s*h_s*l_cgs)*cos(phi);
Dm1 = M_s*h_s*sin(phi);
Dm2 = (I_xzs+M_s*h_s*l_cgs)*cos(phi);

Mass_Matrix =   [M                  0     0                                 M_s*h_s*sin(phi)
                 0                  M     -M_s*h_s*cos(phi)                 0
                 0                  0     (I_xxs+M_s*h_s^2)                 (I_xzs+M_s*h_s*l_cgs)*cos(phi)
                 M_s*h_s*sin(phi)   0     (I_xzs+M_s*h_s*l_cgs)*cos(phi)    I_zzo];

% coupled equations of motion
A1 = -2*M_s*h_s*cos(phi);
B1 = -M_s*h_s*sin(phi);
C1 = (I_xzs+M_s*h_s*l_cgs)*sin(phi);
C2 = (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi);
D1 = -(I_xzs+M_s*h_s*l_cgs)*sin(phi);
D2 = -(I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi);

F_c = zeros(4,1);             

F_c(1) = sigFx  + A1*phi_d*psi_d;
F_c(2) = sigFy  + B1*(phi_d^2 + psi_d^2);
F_c(3) = sigTxs + C1*phi_d*psi_d + C2*psi_d^2;
F_c(4) = sigTz  + D1*phi_d^2     + D2*psi_d*phi_d;

% decouple the EoM
F_u = Mass_Matrix^-1*F_c; 

% extract the left hand side of the EoM
a_x_new = F_u(1);
a_y_new = F_u(2);
phi_dd_new = F_u(3);
psi_dd_new = F_u(4);
%---------------------------------------%
%EoM NOXON END
%---------------------------------------%

% %---------------------------------------%
% %EoM NOXON NEW
% %---------------------------------------%
% %==Equations of Motion==%
% 
% % mass matrix for coupled equations of motion
% Am  = M_s*h_s*sin(phi);
% Bm  = -M_s*h_s*cos(phi);
% Cm  = (I_xzs+M_s*h_s*l_cgs)*cos(phi);
% Dm1 = M_s*h_s*sin(phi);
% Dm2 = (I_xzs+M_s*h_s*l_cgs)*cos(phi);
% 
% Mass_Matrix =   [M                  0     0                                 M_s*h_s*sin(phi)
%                  0                  M     -M_s*h_s*cos(phi)                 0
%                  0                  0     (I_xxs+M_s*h_s^2*sin(phi)^2)      I_xzs*cos(phi)
%                  M_s*h_s*sin(phi)   0     (I_xzs+M_s*h_s*l_cgs)*cos(phi)    I_zzo];
% 
% % coupled equations of motion
% A1 = -2*M_s*h_s*cos(phi);
% B1 = -M_s*h_s*sin(phi);
% C1 = (I_xzs+M_s*h_s*l_cgs)*sin(phi);
% C2 = (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi);
% D1 = -(I_xzs+M_s*h_s*l_cgs)*sin(phi);
% D2 = -(I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi);
% 
% F_c = zeros(4,1);             
% 
% F_c(1) = sigFx  + A1*phi_d*psi_d;
% F_c(2) = sigFy  + B1*(phi_d^2 + psi_d^2);
% 
% F_c(3) = sigTxs + C1*phi_d*psi_d + C2*psi_d^2 + M_s*h_s*cos(phi)*psi_d*v_x - M_s*h_s^2*sin(phi)*cos(phi)*(phi_d^2 + psi_d^2);
%  
% F_c(4) = sigTz  + D1*phi_d^2     + D2*psi_d*phi_d;
% 
% % decouple the EoM
% F_u = Mass_Matrix^-1*F_c; 
% 
% % extract the left hand side of the EoM
% a_x_new = F_u(1);
% a_y_new = F_u(2);
% phi_dd_new = F_u(3);
% psi_dd_new = F_u(4);
% %---------------------------------------%
% %EoM NOXON NEW END
% %---------------------------------------%

%==Update independent variables==%
%acceleration outputs
acc_out = [a_x_new;a_y_new;a_sy;phi_dd_new;psi_dd_new];        
pdot = [a_x_new;a_y_new;phi_d;phi_dd_new;psi_d;psi_dd_new]
%----------------------------------%
%end
%nd
%d
%
