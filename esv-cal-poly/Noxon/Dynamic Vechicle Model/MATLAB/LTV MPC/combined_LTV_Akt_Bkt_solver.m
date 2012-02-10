% Author: Nikola Noxon
% California Polytehnic State University
% email: nikolanoxon@gmail.com
% Oct 2011; Last revision: 1-12-16

%This code combines the features of LTV_solver and Akt_Bkt_solver
% it is very slow and cumbersome, but is useful as a guideline of what the
% solvers do

%------------- BEGIN CODE --------------

%--------------------------------
% SETUP
%--------------------------------

syms x_d y_d phi_d phi psi_d psi

% set Initial Conditions
initial_state = [10,0,0,0,0,0];
delta = 0.1; % rad

% set Constants
tau = 0.1; % sec
g   = 9.81; % m/s^2

%--------------------------------
% TRAXAS SLASH PHYSICAL VARIABLES
%--------------------------------
% Longitudinal distance between the center of tire and vehicle center of mass
l_fs =0.212; % m			 
l_rs =0.126; % m		

% Front and rear track width
t_f =0.307; % m
t_r =0.307; % m

% Distance between ground and static roll center
h_f =0.021; % m				
h_r = 0.045; % m

% Height of sprung mass CG above ground
h_cgs = 0.107; % m

% Height of front/rear unsprung mass CG above ground
h_cguf = 0.051; % m
h_cgur =0.051; % m

% Total vehicle mass
M =3.116; % kg;

% Front/Rear unsprung mass
M_uf =0.342; % kg
M_ur =0.329; % kg

% Moments of inertia of sprung mass about its CG
I_xxs = 0.005; % g-mm2
I_yys = 0.043; % g-mm2
I_zzs = 0.045; % g-mm2

% Products of inertia of sprung mass about its CG
I_xys = 0.0006; % g-mm2
I_xzs = 0.0009; % g-mm2
I_yzs = 0.00006; % g-mm2

% Moment of inertia of wheel about its spin axis
I_trf =  0.0002; % kg-m^2
I_tlf =  0.0002; % kg-m^2
I_trr =  0.0002; % kg-m^2
I_tlr =  0.0002; % kg-m^2

% Front/rear spring stiffness
% to be calculated
K_spf = 0; % N/m
K_spr = 0; % N/m

% Front/rear spring damping 
% to be calculated
B_f = 0; % N-s/m
B_r = 0; % N-s/m
 
% Front/Rear anti-roll bar stiffness
K_rf = 0; % N-m/rad
K_rr = 0; % N-m/rad
 
% Steering-to-wheel angle ratio
% to be calculated
K_sr = 1;

% Tire Width
t_wid =0.044; % m

% Tire Radius
t_rad =0.054; % m

% Normalized Tire properties
varx = [...
    0.0, 0.0;...
    0.1, 0.6;...
    0.15, 0.85;...
    1.0, 0.4]; %slip curve coordinates (rad, mu)
vary = [...
    0.0, 0.0;...
    0.08, 0.4;...
    0.15, 0.6;...
    0.3, 0.8;...
    1.0, 0.4]; %slip curve coordinates (rad, mu) 
varM = [...
    0.0, 0.0;...
    0.1, 0.0005;...
    0.3, 0.00025;...
    1.0, 0.0]; %slip angle (slip-angle, Moment-arm)

%----------------------
% CONSTANT CALCULATED PARAMETERS
%----------------------
% Roll stiffness
K_phif = 0.766*K_spf*t_f^2/2 + K_rf;
K_phir = 0.827*K_spr*t_r^2/2 + K_rr;
K_phi = (K_phif + K_phir); 

% Roll damping
B_phif = 0.766*B_f*t_f^2/2; % Nm-s/rad
B_phir = 0.827*B_r*t_r^2/2; % Nm-s/rad
B_phi = (B_phif + B_phir); % Nm-s/rad
 
% Moment of inertia of unsprung front/rear mass about their CoG
I_zzuf = M_uf*(t_f/2)^2;
I_zzur = M_ur*(t_r/2)^2;

% Wheelbase
L = l_fs + l_rs;

% Sprung Mass
M_s = M - M_uf - M_ur;

% Longitudinal distance from sprung CG to total mass CG
l_cgs = (M_ur*l_rs - M_uf*l_fs)/M;

% Longitudinal distance from total CG to front axle
l_f = l_fs + l_cgs;
% Longitudinal distance from total CG to rear axle
l_r = l_rs - l_cgs;

% Front/rear vehicle static axle mass
M_f = M*l_r/L;
M_r = M*l_f/L;

% Height of sprung mass CG above roll center (height of roll center origin)
h_o = h_f + l_f*(h_r - h_f)/L;

% Height of sprung mass CG above the origin
h_s = h_cgs - h_o;

% Height of front/rear unsprung mass above the origin
h_uf = h_cguf - h_o;
h_ur = h_cgur - h_o;

% Height of total vehicle CG
h_cg = (M_s*h_cgs + M_uf*h_cguf + M_ur*h_cgur)/M;

% Chassis Inertial Tensor
I_body = [I_xxs+M_s*h_s^2,I_xys,I_xzs+M_s*h_s*l_cgs;...
       I_xys,I_yys+M_s*(h_s^2+l_cgs^2),I_yzs;...
       I_xzs+M_s*h_s*l_cgs,I_yzs,I_zzs+M_s*l_cgs^2];
   
I_zzus = M_uf*l_f^2 + ...
         M_ur*l_r^2 + ...
         I_zzuf + I_zzur;
 

I_xxo = I_body(1,1);
I_zzo = I_body(3,3) + I_zzus;

% Tire vertical forces
Fz_f = l_r*M*g/(2*L);
Fz_r = l_f*M*g/(2*L);

% Linearized cornering coefficients
C_af = vary(2,2)/vary(2,1)*Fz_f;
C_ar = vary(2,2)/vary(2,1)*Fz_r;

%----------------------
% VARIABLE CALCULATED PARAMETERS
%----------------------

%left front wheel velocity
vx_lf = x_d + psi_d*t_f/2;
vy_lf = y_d + psi_d*l_f;
 
%right front wheel velocity
vx_rf = x_d - psi_d*t_f/2;
vy_rf = y_d + psi_d*l_f;
 
%left rear wheel velocity
vx_lr = x_d + psi_d*t_r/2;
vy_lr = y_d - psi_d*l_r;
 
%right rear wheel velocity
vx_rr = x_d - psi_d*t_r/2;
vy_rr = y_d - psi_d*l_r;  

% Tire longitudinal and cornering velocities
vc_lf = vy_lf*cos(delta) - vx_lf*sin(delta);
vc_rf = vy_rf*cos(delta) - vx_rf*sin(delta);
vc_lr = vy_lr*cos(delta) - vx_lr*sin(delta);
vc_rr = vy_rr*cos(delta) - vx_rr*sin(delta);

vl_lf = vy_lf*sin(delta) + vx_lf*cos(delta);
vl_rf = vy_rf*sin(delta) + vx_rf*cos(delta);
vl_lr = vy_lr*sin(delta) + vx_lr*cos(delta);
vl_rr = vy_rr*sin(delta) + vx_rr*cos(delta);

% Slip angles
a_lf = atan(vc_lf/vl_lf);
a_rf = atan(vc_rf/vl_rf);
a_lr = atan(vc_lr/vl_lr);
a_rr = atan(vc_rr/vl_rr);

% Tire longitudinal and cornering forces
Fc_lf = -a_lf*C_af;
Fc_rf = -a_rf*C_af;
Fc_lr = -a_lr*C_ar;
Fc_rr = -a_rr*C_ar;

Fl_lf = 0; %assumes longitudinal forces are negligible
Fl_rf = 0;
Fl_lr = 0;
Fl_rr = 0;
 
%Normal components of tire forces
Fxlf = Fl_lf*cos(delta) - Fc_lf*sin(delta);
Fxrf = Fl_rf*cos(delta) - Fc_rf*sin(delta);
Fxlr = Fl_lr;
Fxrr = Fl_rr;
 
Fylf = Fl_lf*sin(delta) + Fc_lf*cos(delta);
Fyrf = Fl_rf*sin(delta) + Fc_rf*cos(delta);
Fylr = Fc_lr;
Fyrr = Fc_rr;

% Tire Torques
T_phif = -K_phif*phi - B_phif*phi_d;
T_phir = -K_phir*phi - B_phir*phi_d;
 
% Sum forces and torques
sigFx = Fxlf + Fxrf + Fxlr + Fxrr;
sigFy = Fylf + Fyrf + Fylr + Fyrr;
sigTxs = T_phif + T_phir - M_s*g*h_s*sin(phi); %aerodynamic roll moment = 0
sigTz = (Fylf + Fyrf)*l_f - (Fylr + Fyrr)*l_r + t_f/2*(Fxlf - Fxrf)...
        + t_r/2*(Fxlr - Fxrr);
    
%-------------------
%EQUATIONS OF MOTION
%-------------------


% constant EoM parameters
A1 = M_s*h_s/M;
A2 = 1/M;
A3 = -2*M_s*h_s/M;

B1 = -M_s/M;
B2 = 1/M;
B3 = -M_s*h_s/M;
B4 = -M_s*h_s/M;

C1 = (I_xzs-M_s*h_s*l_cgs)/(I_xxs+M_s*h_s^2);
C2 = 1/(I_xxs+M_s*h_s^2);
C3 = (I_xzs-M_s*h_s*l_cgs)/(I_xxs+M_s*h_s^2);
C4 = (I_zzs-I_yys-M_s*h_s^2)/(I_xxs+M_s*h_s^2);

D1 = (I_xzs-M_s*h_s*l_cgs)/I_zzo;
D2 = M_s*h_s/I_zzo;
D3 = 1/I_zzo;
D4 = -(I_xzs - M_s*h_s*l_cgs)/I_zzo;
D5 = -(I_xzs-M_s*h_s*l_cgs)/I_zzo;
D6 = -(I_xzs - M_s*h_s*l_cgs)/I_zzo;

% mass matrix for coupled EoM
Mass_Matrix =   [1              0       0               A1*sin(phi)
                 0              1       B1*cos(phi)     0
                 0              0       1               C1*cos(phi)
                 D2*sin(phi)    0       D1*cos(phi)     1];
             
% coupled equations of motion for x_dd, y_dd, phi_dd, psi_dd
F_Ec =  [A2*sigFx + psi_d*x_d + A3*cos(phi)*phi_d*psi_d
        B2*sigFy - psi_d*y_d + B3*sin(phi)*phi_d^2+B4*sin(phi)*psi_d^2
        C2*sigTxs + C3*sin(phi)*cos(phi)*phi_d*psi_d...
        + C4*sin(phi)*cos(phi)*psi_d^2
        D3*sigTz + D4*sin(phi)*cos(phi)*phi_d*psi_d...
        + D5*sin(phi)*phi_d^2 + D6*sin(phi)*cos(phi)*psi_d^2];

% decouple the EoM
F_Eu = Mass_Matrix^-1*F_Ec;

% extract the left hand side of the EoM
x_dd = F_Eu(1);
y_dd = F_Eu(2);
phi_dd = F_Eu(3);
psi_dd = F_Eu(4);


% define the state space
E = [x_d; y_d; phi_d; phi; psi_d; psi];

% define the state trajectory
F_E = [x_dd; y_dd; phi_dd; phi_d; psi_dd; psi_d];   

% discretize using the Euler Method
F_Ed = tau*F_E + E;

% differentiate the discretized system
dFde1 = diff(F_Ed,E(1));
dFde2 = diff(F_Ed,E(2));
dFde3 = diff(F_Ed,E(3));
dFde4 = diff(F_Ed,E(4));
dFde5 = diff(F_Ed,E(5));
dFde6 = diff(F_Ed,E(6));

dFdE = [dFde1, dFde2, dFde3, dFde4, dFde5, dFde6];

current_state = [1 1 1 1 1 1];
get_A_ltv(dFdE, E, current_state)

% % solve for the initial state trajectory
% E_k1 = get_next_step(F_Ed, E, initial_state);
% 
% for time = 0.0: tau: 1.0
%     E_k = E_k1;
%     E_k1 = get_next_step(F_Ed, E, E_k);
% end

%------------- END OF CODE --------------
