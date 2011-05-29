function C_inf = cinf(sysStruct)
% function that computes max control invariant set
% 
% taken from Thomas Besselmann's function PreSets,
% slightly changed by Stefan Richter,
% August 2008

nx = size(sysStruct.A,2);
nu = size(sysStruct.B,2);

X = polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
U = polytope([1;-1],[sysStruct.umax;-sysStruct.umin]);
[Hx,Kx] = double(X);
[Hu,Ku] = double(U);
[H,K] = double(X);

max_i = 1000;
for i = 1:max_i
    Hpre = [H*sysStruct.A   H*sysStruct.B;
            Hx              zeros(2*nx,nu);
            zeros(2*nu,nx)  Hu];
    Kpre = [K;Kx;Ku];
    Xtemp = projection(polytope(Hpre,Kpre),1:1:nx);
    if eq(Xtemp,X,struct('abs_tol', 1e-10))
        disp(['determinedness index is ', num2str(i)])
        C_inf = Xtemp;
        break;
    else
        X = Xtemp;
    end
    
    [H,K] = double(X);
end
if i==max_i
    error('Max number of iterations reached. C_inf not found.')
end
