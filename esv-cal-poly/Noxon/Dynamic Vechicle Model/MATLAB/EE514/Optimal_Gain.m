function G = Optimal_Gain(p,acc_in,steer,torque,x_in,Du)


p = [20,0,0,0,0,0.1];
acc_in = [0,0,0,0,0];
steer = 90;
torque = 0;

x_in = [20,0,0.1]';
Du = steer;

[pdot,slp_ang,acc_out,Fout,DfDu] = DVM(p,steer,torque,acc_in);

G = bicycle_stability(x_in,DfDu,Du)
