%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 11_8
%\label{ex:infgil}
% Francesco Borrelli July 05 2009
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5


Double_Integrator;
sysStruct.B = [0;1];
sysStruct.ymin = [-10;-10];
sysStruct.ymax = [ 10; 10];
probStruct.Q = eye(2);
probStruct.R = 0.1;
probStruct.norm = 2;
probStruct.Tconstraint = 1; % LQR terminal cost and contraint
probStruct.N = inf;
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
    print(gcf,'-depsc2',['dd_infinite_Nr_' num2str(length(ctrl)) '.eps']);

    ctrl_red=mpt_simplify(ctrl,'Optimal')
    figure 
%    plot(mpt_simplify(ctrl),'Optimal')
    plot(ctrl_red)
    set(gca,'FontSize',ftsize)
    axis([sysStruct.ymin(1),sysStruct.ymax(1),sysStruct.ymin(2),sysStruct.ymax(2)])
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
    print(gcf,'-depsc',['dd_infinite_reduced_Nr_' num2str(length(ctrl_red)) '.eps']);

% to get structure from the control objects use:
% csrtuct = struct(ctrl{1});
[H1,K1]=double(ctrl_red.Pn);
F1=ctrl_red.Fi;
G1=ctrl_red.Gi;
matlab2latex2(H1,K1,F1,G1,[],'test',1,2,1,1);

