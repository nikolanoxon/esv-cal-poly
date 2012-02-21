% Author: Nikola Noxon
% California Polytehnic State University
% email: nikolanoxon@gmail.com
% Oct 2011; Last revision: 1-12-16

% The following code solves for the 8 DOF dynamic vehicle model (DVM) in
% variable form. This is done to significantly decrease computation
% overhead during real-time calculation
% The uncoupled, discrete, linearized 8 DOF DVM has the forumulation:
% ?(k + 1) = Ak,t*?(k) + Bk,t*U(k) + dk,t(k),
% dk,t = ?k+1,t ? Ak,t*?k,t ? Bk,t*Ut
%
% The code returns Ak,t and Bk,t

% The solver assumes the following for calculation simplification:
% cos(phi) = 1;
% sin(phi) = 0;

%------------- BEGIN CODE --------------

% the following variables comprise all constants, states, and inputs used
% in calculation
% syms    tau g a_x v_x a_y v_y phi_d phi psi_d psi delta d_steer...
%         l_fs l_rs t_f t_r h_f h_r h_cgs h_cguf h_cgur M M_uf M_ur...
%         I_xxs I_xys I_xzs I_yys I_yzs I_zzs I_zzuf I_zzur...
%         I_tlf I_trf I_tlr I_trr vary K_spf K_spr B_f B_r K_rf K_rr K_sr...
%         M_s L l_cgs l_f l_r h_o h_s h_uf h_ur Fzlf Fzrf Fzlr Fzrr...
%         K_phif K_phir B_phif B_phir
syms    tau g a_x v_x a_y v_y phi_d phi psi_d psi delta...
        M11 M14 M22 M23 M32 M33 M34 M41 M43 M44 A1 B1 C1 C2 C3 C4 D1 D2...
        l_fs l_rs t_f t_r h_f h_r h_cgs h_cguf h_cgur M M_uf M_ur...
        I_xxs I_xys I_xzs I_yys I_yzs I_zzs I_zzuf I_zzur I_zzo...
        I_tlf I_trf I_tlr I_trr vary K_spf K_spr B_f B_r K_rf K_rr K_sr...
        M_s L l_cgs l_f l_r h_o h_s h_uf h_ur Fzlf Fzrf Fzlr Fzrr...
        K_phif K_phir B_phif B_phir
% %---------------------------------------%
% %ROTATION MATRIX
% %---------------------------------------%
% ROT = [1            0           0;
%        0     cos(phi)    sin(phi);
%        0    -sin(phi)   cos(phi)];
%  
% I_b = [    I_xxs+M_s*h_s^2                      I_xys   I_xzs+M_s*h_s*l_cgs
%                      I_xys  I_yys+M_s*(h_s^2+l_cgs^2)                 I_yzs
%        I_xzs+M_s*h_s*l_cgs                      I_yzs   I_zzs+M_s*l_cgs^2];
%    
% I_c = ROT*I_b*ROT'; %chassis M.o.I. tensor
%  
% I_zzus = M_uf*l_f^2 + ...
%          M_ur*l_r^2 + ...
%          I_zzuf + I_zzur;
%  
% I_zzo = I_c(3,3) + I_zzus; %effective I_zz
% %---------------------------------------%

%---------------------------------------%
%TIRE LONGITUDINAL/CORNERING SPEEDS
%---------------------------------------%
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
%---------------------------------------%

%---------------------------------------%
%SLIP ANGLES
%---------------------------------------%
%steer angle in radians
%delta = d_steer/(180*K_sr)*pi;

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

%---------------------------------------%
%TIRE LONGITUDINAL/CORNERING FORCES
%---------------------------------------%
C_alf = vary*Fzlf;
C_arf = vary*Fzrf;
C_alr = vary*Fzlr;
C_arr = vary*Fzrr;

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

%---------------------------------------%
%TIRE TORQUES
%---------------------------------------%
T_phif = -K_phif*phi - B_phif*phi_d;
T_phir = -K_phir*phi - B_phir*phi_d;
%---------------------------------------%
 
%---------------------------------------%
%SUMMATION OF FORCES AND MOMENTS
%---------------------------------------%
sigFx   = Fxlf + Fxrf + Fxlr + Fxrr;
sigFy   = Fylf + Fyrf + Fylr + Fyrr;
sigTxs  = T_phif + T_phir;
sigTz   = (Fylf + Fyrf)*l_f - (Fylr + Fyrr)*l_r + ...
          t_f/2*(Fxlf - Fxrf) + t_r/2*(Fxlr - Fxrr);
%---------------------------------------%

% %---------------------------------------%
% %EQUATIONS OF MOTION
% %---------------------------------------%
% %mass matrix for coupled equations of motion
% M11 = M;
% M14  = M_s*h_s*sin(phi);
% M22 = M;
% M23 = -M_s*h_s*cos(phi);
% M32 = M_s*h_s*cos(phi);
% M33 = I_xxs+M_s*h_s^2*(1+cos(phi)^2);
% M34 = (I_xzs+2*M_s*h_s*l_cgs)*cos(phi);
% M41 = M_s*h_s*sin(phi);
% M43 = (I_xzs+M_s*h_s*l_cgs)*cos(phi);
% M44 = I_zzo;
% 
% Mass_Matrix =   [M11     0     0   M14
%                    0   M22   M23     0
%                    0   M32   M33   M34
%                  M41     0   M43   M44];
% 
% %coupled equations of motion
% A1 = -2*M_s*h_s*cos(phi);
% B1 = -M_s*h_s*sin(phi);
% C1 = (I_xzs+M_s*h_s*l_cgs)*sin(phi);
% C2 = (I_zzs - I_yys)*sin(phi)*cos(phi);
% C3 = M_s*h_s^2*sin(phi)*cos(phi);
% C4 = -M_s*h_s*cos(phi);
% D1 = -(I_xzs+M_s*h_s*l_cgs)*sin(phi);
% D2 = -(I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi);
% 
% 
% F1 = sigFx  + A1*phi_d*psi_d;
% F2 = sigFy  + B1*(phi_d^2 + psi_d^2);
% F3 = sigTxs + C1*phi_d*psi_d + C2*psi_d^2 + C3*phi_d^2 + C4*psi_d*v_x;
% F4 = sigTz  + D1*phi_d^2     + D2*psi_d*phi_d;
% 
% F_c = [F1; F2; F3; F4];             
% 
% %decouple the EoM
% F_u = Mass_Matrix^-1*F_c; 
% 
% %extract the left hand side of the EoM
% a_x = F_u(1);
% a_y = F_u(2);
% phi_dd = F_u(3);
% psi_dd = F_u(4);
% %---------------------------------------%

%---------------------------------------%
%EQUATIONS OF MOTION
%---------------------------------------%
%mass matrix for coupled equations of motion
% M11 = M;
% M14  = 0;
% M22 = M;
% M23 = -M_s*h_s;
% M32 = M_s*h_s;
% M33 = I_xxs+2*M_s*h_s^2;
% M34 = (I_xzs+2*M_s*h_s*l_cgs);
% M41 = 0;
% M43 = (I_xzs+M_s*h_s*l_cgs);
% M44 = I_zzo;

Mass_Matrix =   [M11     0     0     0
                   0   M22   M23     0
                   0   M32   M33   M34
                   0     0   M43   M44];

%coupled equations of motion
% A1 = -2*M_s*h_s;
% B1 = 0;
% C1 = 0;
% C2 = 0;
% C3 = 0;
% C4 = -M_s*h_s;
% D1 = 0;
% D2 = 0;


F1 = sigFx  + A1*phi_d*psi_d;
F2 = sigFy;
F3 = sigTxs + C4*psi_d*v_x;
F4 = sigTz;

F_c = [F1; F2; F3; F4];             

%decouple the EoM
F_u = Mass_Matrix^-1*F_c; 

%extract the left hand side of the EoM
a_x = F_u(1);
a_y = F_u(2);
phi_dd = F_u(3);
psi_dd = F_u(4);
%---------------------------------------%


% define the state space
E = [v_x; v_y; phi_d; phi; psi_d; psi];

% define the state trajectory
F_E = [a_x; a_y; phi_dd; phi_d; psi_dd; psi_d];   

% % discretize using the Euler Method
% F_Ed = tau*F_E + E;

% differentiate the discretized system
dFde1 = diff(F_E,E(1));
dFde2 = diff(F_E,E(2));
dFde3 = diff(F_E,E(3));
dFde4 = diff(F_E,E(4));
dFde5 = diff(F_E,E(5));
dFde6 = diff(F_E,E(6));

A_kt = [dFde1, dFde2, dFde3, dFde4, dFde5, dFde6]

dF1du = diff(F_E(1),delta);
dF2du = diff(F_E(2),delta);
dF3du = diff(F_E(3),delta);
dF4du = diff(F_E(4),delta);
dF5du = diff(F_E(5),delta);
dF6du = diff(F_E(6),delta);

B_kt = [dF1du; dF2du; dF3du; dF4du; dF5du; dF6du]

%------------- END OF CODE --------------
