function [K_state,Csys,K,Dsys,G] = bicycle_stability(x_in, DfDu, Du)

%Define Inputs
v_x =   x_in(1);
v_y =   x_in(2);
psi_d = x_in(3);

f_x =   DfDu(1);
f_y =   DfDu(2);
m_z =   DfDu(3);

%State Matricies
A = [psi_d,0,v_y
    0,-psi_d,v_x
    0,0,0];

B = [f_x,f_y,m_z]';

C = [1,1,1];

D = 0;

%Convert to discrete
Csys = ss(A,B,C,D);
Ts = 0.2;

k=5;

Dsys = c2d(Csys,Ts);
Ad = Dsys.a;
Bd = Dsys.b;
Cd = Dsys.c;
Dd = Dsys.d;

%Evaluate controlability/observability
C_SYS_OBS = rank(obsv(Csys));
C_SYS_CTRL = rank(ctrb(Dsys));

D_SYS_OBS = rank(obsv(Dsys));
D_SYS_CTRL = rank(ctrb(Dsys));

if (D_SYS_CTRL==3)
    %Controller
    Q = eye(3);
    R = eye(1);
    M = 0;
    
    H11 = Ad+Bd*R^-1*Bd'*Ad'*Q;
    H12 = -Bd*R^-1*Bd'*(Ad')^-1;
    H21 = -(Ad')^-1*Q;
    H22 = (Ad')^-1;
    
    H = [H11 H12
         H21 H22];
    
    EF = [eye(3),zeros(3)]';

     while (k > 0)
         
         EF = H^(-k)*EF;
         
         E = EF(1:3,1:3);
         F = EF(4:6,1:3);
         W = E*F^-1;
         G = [R+Bd'*W*Bd]^-1*Bd'*W*Ad;
         
         k = k - 1;
     end
     
[K,S,e] = lqr(Csys,Q,R,M);
K_state = [0, 2*psi_d^2, 2*psi_d]';
end

