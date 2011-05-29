%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 11_7
%\label{ex:Gilbertcftcoqp}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

Double_Integrator;
sysStruct.B = [0;1];
sysStruct.ymin = [-10;-10];
sysStruct.ymax = [ 10; 10];
probStruct.Q = eye(2);
probStruct.R = 0.1;
probStruct.norm = 2;
probStruct.Tconstraint = 0; % LQR terminal cost and contraint
[Ksummy,P,Edummy] = dlqr(sysStruct.A,sysStruct.B,probStruct.Q,probStruct.R);
probStruct.P_N=P;
ftsize=28;
% Note that P_N is automatically set to solution of Lyapunov equation  (if not specified)

NNN=6
for ii = 1:NNN,
    probStruct.N = ii;
    ctrl{ii} = mpt_control(sysStruct,probStruct);
    figure 
    plot(ctrl{ii})
    set(gca,'FontSize',ftsize)
    axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
    title('')
    xlb=['{\it x}_1(' num2str(NNN-ii) ')'];
    ylb=['{\it x}_2(' num2str(NNN-ii) ')'];
    xlabel(xlb)
    ylabel(ylb)
    print(gcf,'-depsc2',['double_int_ft_h' num2str(ii) '_Nr_' num2str(length(ctrl{ii})) '.eps']);
end

% this conde next repeats the plotting for the control law where polyhedra with the same controllers are merged
for ii = 1:NNN,
    probStruct.N = ii;
    ctrl{ii} = mpt_control(sysStruct,probStruct);
    opcrtl{ii}=mpt_simplify(ctrl{ii},'Optimal');
    figure 
    plot(opcrtl{ii})
    set(gca,'FontSize',ftsize)
    axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
    title('')
    xlb=['{\it x}_1(' num2str(NNN-ii) ')'];
    ylb=['{\it x}_2(' num2str(NNN-ii) ')'];
    xlabel(xlb)
    ylabel(ylb)
    print(gcf,'-depsc2',['double_int_ft_reduced_h' num2str(ii) '_Nr_' num2str(length(opcrtl{ii})) '.eps']);
end

[H1,K1]=double(opcrtl{1}.Pn);
F1=opcrtl{1}.Fi;
G1=opcrtl{1}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'test',1,2,1,1);

[H1,K1]=double(opcrtl{2}.Pn);
F1=opcrtl{2}.Fi;
G1=opcrtl{2}.Gi;
matlab2latex2(H1,K1,F1,G1,[],'test2',1,2,1,1);


%%%
% Remeber:
% to get structure from the control objects use:
% csrtuct = struct(ctrl{1});
% to simplify the controller (using optimal merging of regions):
% cs1_simple = mpt_simplify(ctrl{1},'optimal');