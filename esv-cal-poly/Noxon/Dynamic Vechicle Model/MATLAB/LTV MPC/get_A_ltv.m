function [output] = get_A_ltv(dE, E, current_state)
%get_A_ltv - solves for the variable A_ltv matrix in numeric form
%
% Inputs:
%    A_ltv  - The linearized plant of the discrete vehicle state in
%    variable form
%    E - [x_d y_d phi_d phi psi_d psi]
%    current_state - the current state of the system E
%
% Outputs:
%    output - A_ltv in numeric form with the current state applied
%
% Author: Nikola Noxon
% email: nikolanoxon@gmail.com
% Jan 2012; Last revision: 1-12-12

%------------- BEGIN CODE --------------

syms x_d y_d phi_d phi psi_d psi

dE1 = subs( dE(1:6,1), E, current_state);
dE2 = subs( dE(1:6,2), E, current_state);
dE3 = subs( dE(1:6,3), E, current_state);
dE4 = subs( dE(1:6,4), E, current_state);
dE5 = subs( dE(1:6,5), E, current_state);
dE6 = subs( dE(1:6,6), E, current_state);

output = [dE1 dE2 dE3 dE4 dE5 dE6];

%------------- END OF CODE --------------