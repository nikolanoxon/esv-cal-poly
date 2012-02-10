function [pdot,slp_ang,acc_out,Fout, DfDu] = DVM_Hirtle(p,steer,torque,acc_in)
 
%==output==%
pdot=zeros(10,1);
 
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
l_fs = 1.01476;
l_rs = 1.67524;
t_f = 1.540;
t_r = 1.530;
h_f = 0.130;
h_r = 0.110;
h_cgs = 0.567851;
h_cguf = 0.320;
h_cgur = 0.320;
M = 1704.7;
M_uf = 98.1;
M_ur = 79.7;
I_xxs = 440.911;
I_xys = 0;
I_xzs = 7.54097;
I_yys = 2498.900;
I_yzs = 0;
I_zzs = 2619.28;
I_zzuf = M_uf*(t_f/2)^2;
I_zzur = M_ur*(t_r/2)^2;
I_tlf = 0.99;
I_trf = 0.99;
I_tlr = 0.99;
I_trr = 0.99;
 
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
L = l_fs + l_rs;
M_s = M - M_uf - M_ur;
l_cgs = (M_ur*l_rs - M_uf*l_fs)/M;
l_f = l_fs + l_cgs;
l_r = l_rs - l_cgs;
M_f = M*l_r/L;
M_r = M*l_f/L;
h_o = h_f + l_f*(h_r - h_f)/L;
h_s = h_cgs - h_o;
h_uf = h_cguf - h_o;
h_ur = h_cgur - h_o;
h_cg = (M_s*h_cgs + M_uf*h_cguf + M_ur*h_cgur)/M;
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
 
I_xxo = I_c(1,1);
I_zzo = I_c(3,3) + I_zzus; %effective I_zz
%---------------------------------------------%
 
%==Dynamic Weight Transfer Forces==%
Fzax = (M_s*h_s*a_sx + M_uf*h_uf*a_ufx + M_ur*h_ur*a_urx)/(2*L);
Fzayf = 1/t_f*(M_s*l_r*h_f/L*a_sy + M_uf*h_uf*a_ufy);
Fzayr = 1/t_r*(M_s*l_f*h_r/L*a_sy + M_ur*h_ur*a_ury);
Fzphif = -1/t_f*(K_phif*phi + B_phif*phi_d);
Fzphir = -1/t_r*(K_phir*phi + B_phir*phi_d);
%----------------------------------%
 
%==Tire Normal Forces==% 
Fzlf = M*g*l_r/(2*L) - Fzax - Fzayf + Fzphif;
Fzrf = M*g*l_r/(2*L) - Fzax + Fzayf - Fzphif;
Fzlr = M*g*l_f/(2*L) + Fzax - Fzayr + Fzphir;
Fzrr = M*g*l_f/(2*L) + Fzax + Fzayr - Fzphir;
%----------------------%
 
%==Tire Longitudinal/Lateral Forces==%
 
%left front wheel velocity
v_xlf = v_x + psi_d*t_f/2;
v_ylf = v_y + psi_d*l_f;
 
%right front wheel velocity
v_xrf = v_x - psi_d*t_f/2;
v_yrf = v_y + psi_d*l_f;
 
%left rear wheel velocity
v_xlr = v_x + psi_d*t_r/2;
v_ylr = v_y - psi_d*l_r;
 
%right rear wheel velocity
v_xrr = v_x - psi_d*t_r/2;
v_yrr = v_y - psi_d*l_r;
 
%tire updates
omega_lf = (v_xlf^2 + v_ylf^2)^(1/2);
omega_rf = (v_xrf^2 + v_yrf^2)^(1/2);
omega_lr = (v_xlr^2 + v_ylr^2)^(1/2);
omega_rr = (v_xrr^2 + v_yrr^2)^(1/2);
 
%==Linear Cruise Control=%
if v_x < 11.1
    if omega_lf > omega_rf
        Mtlf = (11.1 - v_x)*200;
        Mtrf = 0;
    else
        Mtlf = 0;
        Mtrf = (11.1 - v_x)*200;
    end
else
    Mtlf = 0;
    Mtrf = 0;
end
 
Mtlf = 0;
Mtrf = 0;
Mtlr = 0;
Mtrr = 0;
%-------------------------%
 
%get steering angle
delta = d_steer/(180*K_sr)*pi; %radians
beta = atan(v_y/v_x);
beta_lf = atan(v_ylf/v_xlf);
beta_rf = atan(v_yrf/v_xrf);
beta_lr = atan(v_ylr/v_xlr);
beta_rr = atan(v_yrr/v_xrr);
 
%Interpolate forces
%Linearized Force Coefficients (C_alpha)
C_alf = vary(2,2)/vary(2,1)*Fzlf;
C_arf = vary(2,2)/vary(2,1)*Fzrf;
C_alr = vary(2,2)/vary(2,1)*Fzlr;
C_arr = vary(2,2)/vary(2,1)*Fzrr;
 
a_lf = beta_lf - delta;
a_rf = beta_rf - delta;
a_lr = beta_lr;
a_rr = beta_rr;
 
slp_ang = [a_lf,a_rf,a_lr,a_rr];
 
%Linear Cruise Control for constant v_x
if v_x < 11.1
    Fxtf = (11.1-v_x)*20000;
else
    Fxtf = 0; %no torque
end
 
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
 

sigF_c = (Fxtlf+Fxtrf+Fxtlr+Fxtrr);
sigF_l = (Fytlf+Fytrf+Fytlr+Fytrr);
sigT_lc =(Fytlf + Fytrf)*l_f - (Fytlr + Fytrr)*l_r + ...
        t_f/2*(Fxtlf - Fxtrf) + t_r/2*(Fxtlr - Fxtrr);
sigT_cl =(Fxtlf + Fxtrf)*l_f - (Fxtlr + Fxtrr)*l_r + ...
        t_f/2*(Fytlf - Fytrf) + t_r/2*(Fytlr - Fytrr);

DfDx = -(1/M)*(sigF_c*cos(delta)+sigF_l*sin(delta));
DfDy = (1/M)*(sigF_l*cos(delta)+sigF_c*sin(delta));
DfDz = (1/I_zzs)*(sigT_lc*cos(delta)+sigT_cl*sin(delta));
    
    
Fout = [Fylf,Fyrf,Fylr,Fyrr];
DfDu = [DfDx,DfDy,DfDz];

%tire moments are unused...
Mzlf = 0;
Mzrf = 0;
Mzlr = 0;
Mzrr = 0;
%---------------------------------------%
 
%Omeaga/Alpha of Wheels
alpha_lf_new = (Fxtlf*t_rad + Mtlf)/I_tlf;
alpha_rf_new = (Fxtrf*t_rad + Mtrf)/I_trf;
alpha_lr_new = (Fxtlr*t_rad + Mtlr)/I_tlr;
alpha_rr_new = (Fxtrr*t_rad + Mtrr)/I_trr;
 
% alpha_lf_new = 0;
% alpha_rf_new = 0;
% alpha_lr_new = 0;
% alpha_rr_new = 0;
 
 
%==Torques==%
T_phif = -K_phif*phi - B_phif*phi_d;
T_phir = -K_phir*phi - B_phir*phi_d;
%-----------%
 
%==Sum forces and torques==%
sigFx = Fxlf + Fxrf + Fxlr + Fxrr;
sigFy = Fylf + Fyrf + Fylr + Fyrr;
sigTxs = T_phif + T_phir - ...
         M_s*g*h_s*sin(phi) + M_s*h_s*a_sy*cos(phi);
sigTz = (Fylf + Fyrf)*l_f - (Fylr + Fyrr)*l_r + ...
        t_f/2*(Fxlf - Fxrf) + t_r/2*(Fxlr - Fxrr) + ...
        Mzlf + Mzrf + Mzlr + Mzrr;
    

DfDu = [DfDx,DfDy,DfDz];
%--------------------------%
 
%==Update independent variables==%
a_x_new = (sigFx + ...
           M_s.*(-2*h_s.*phi_d.*psi_d.*cos(phi) - ...
           h_s.*psi_dd.*sin(phi)))./M;
a_y_new = (sigFy - ...
           M_s*(-h_s*phi_dd*cos(phi) + ...
           h_s*phi_d^2*sin(phi) + ...
           h_s*psi_d^2*sin(phi)))./M;
phi_dd_new = (sigTxs - ...
           (I_xzs+M_s*h_s*l_cgs)*cos(phi)*psi_dd + ...
           (I_xzs+M_s*h_s*l_cgs)*sin(phi)*phi_d*psi_d + ...
           (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi)*psi_d^2)./ ...
           (I_xxs+M_s*h_s^2);
psi_dd_new = (sigTz - ...
           (I_xzs+M_s*h_s*l_cgs)*cos(phi)*phi_dd - ...
           (I_xzs+M_s*h_s*l_cgs)*sin(phi)*phi_d^2 - ...
            M_s*h_s*a_x*sin(phi) - ...
           (I_zzs - I_yys - M_s*h_s^2)*sin(phi)*cos(phi)*psi_d*phi_d)./ ...
            I_zzo;
 
%acceleration outputs
acc_out = [a_x_new,a_y_new,a_sy,phi_dd_new,psi_dd_new];        
        
%X
pdot(1) = a_x_new;
%Y   
pdot(2) = a_y_new;
%PHI
pdot(3) = phi_d;
pdot(4) = phi_dd_new;
%PSI
pdot(5) = psi_d;
pdot(6) = psi_dd_new;
%WHEELS
pdot(7) = alpha_lf_new;
pdot(8) = alpha_rf_new;
pdot(9) = alpha_lr_new;
pdot(10) = alpha_rr_new;
%SPRUNG BODY
%----------------------------------%
%end
%nd
%d
%
