%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 10_10
% \label{ex:unconinfnorm}
% Francesco Borrelli November 08 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

%x(k+1)=Ax(k)+Bu(k)
sysStruct.A= [1 1; 0 1];
sysStruct.B= [0; 1];

%y(k)=Cx(k)+Du(k)
sysStruct.C= [1 0; 0 1];
sysStruct.D= [0;0];


% string labels for states, inputs and outputs
sysStruct.StateName = { 'Position', 'Speed' }; 
sysStruct.InputName = 'Acceleration';
sysStruct.OutputName = { 'Position', 'Speed' };

%set constraints on input and outputs
sysStruct.umin    =   -inf;
sysStruct.umax    =   inf;
sysStruct.ymin = [-inf;-inf];
sysStruct.ymax = [ inf; inf];

probStruct.Q = eye(2);
probStruct.R = 20;
probStruct.Tconstraint = 0; % no terminal constriant
ftsize=28;

probStruct.N = 19; % this is calculated with version 2 of the example
ctrl = mpt_control(sysStruct,probStruct);
ftsize=28;

figure 
    plot(ctrl)
    set(gca,'FontSize',ftsize)
    axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
%    print(gcf,'-depsc2',['dd_inf_infinite_Nr_' num2str(length(ctrl)) '.eps']);

%    ctrl_red=mpt_simplify(ctrl,'Optimal')
%    figure 
%    plot(mpt_simplify(ctrl),'Optimal')
%    plot(ctrl_red)
    set(gca,'FontSize',ftsize)
    axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
%    print(gcf,'-depsc',['dd_inf_infinite_reduced_Nr_' num2str(length(ctrl_red)) '.eps']);

% to get structure from the control objects use:
% csrtuct = struct(ctrl{1});
[H1,K1]=double(ctrl_red.Pn);
F1=ctrl_red.Fi;
G1=ctrl_red.Gi;
matlab2latex2(H1,K1,F1,G1,[],'test',1,2,1,1);

% ctrl.Bi  and ctrl.Ci have the  optimal cost. compare it with Jx. Note
% that mpt does not solve teh uncostrained problem this is why there is a
% difference


