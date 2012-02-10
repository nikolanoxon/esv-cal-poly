p = [20,0,0,0,0,0.1];
x_in = [20,0,0.1]';
acc_in = [0,0,0,0,0];

steer = 90;
torque = 0;
Ts = 0.1;
Tf = 1;
T = 0;

Du = steer;

[pdot,slp_ang,acc_out,Fout,DfDu] = DVM(p,steer,torque,acc_in);

bicycle_stability(x_in,DfDu,Du)
