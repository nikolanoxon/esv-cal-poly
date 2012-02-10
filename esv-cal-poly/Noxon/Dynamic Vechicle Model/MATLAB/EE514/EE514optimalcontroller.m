%Define Initial Conditions
p = [20,0,0,0,0,0.1];
acc_in = [0,0,0,0,0];
steer = 10;
torque = 0;

x_in = [20,0,0.1]';
Du = steer;

%Output to Dynamic Models
[pdot,slp_ang,acc_out,F_in,DfDu] = DVM(p,steer,torque,acc_in);
[zdot,alpha] =  DVM3(x_in, steer, F_in);

%Calculate Feedback Gains
[K_state,Csys,K,Dsys,G] = bicycle_stability(x_in,DfDu,Du);

Ad = Dsys.a;
Bd = Dsys.b;

%Output State Feedback
G %optimal discrete
K %optimal continuous
K_state %state feedback
%end