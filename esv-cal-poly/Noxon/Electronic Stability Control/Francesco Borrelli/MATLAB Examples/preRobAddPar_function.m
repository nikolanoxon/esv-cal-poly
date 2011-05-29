function [Xpre,XpreandX]=preRobAddPar_function(sysStruct,name,uselaprint)
nx = size(sysStruct.A,1);
nu = size(sysStruct.B,2);
np=length(sysStruct.Wcal);


% laprint options
if uselaprint
    set(0,'defaulttextinterpreter','none')
    width = 6;
end

% plot options
ftsize=28;
Options.color=[.5 .5 .5]; % Gray color
Options2.color=[.7 .7 .7]; % Light Gray
Options2.shade = 0.5;

W=sysStruct.noise;
X = polytope([eye(2);-eye(2)],[sysStruct.xmax;-sysStruct.xmin]);
U = polytope([1;-1],[sysStruct.umax;-sysStruct.umin]);

M=X-W;
[H,K] = double(M);
[Hu,Ku] = double(U);
%%% pre set
Hpre = [ zeros(2*nu,nx)  Hu];
Kpre = [Ku];
for i=1:np
Aunc=sysStruct.A;
Bunc=sysStruct.B;
for j=1:length(sysStruct.Aunc)
    Aunc=Aunc+sysStruct.Aunc{j}*sysStruct.Wcal{i}(j);
    Bunc=Bunc+sysStruct.Bunc{j}*sysStruct.Wcal{i}(j);
end
Hpre = [Hpre;H*Aunc   H*Bunc];
Kpre = [Kpre;K];
end
Xpre = projection(polytope(Hpre,Kpre),[1,2])
XpreandX=Xpre&X


figure
plot(X,Options2)
hold on
plot(XpreandX,Options) 
border = 1;
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])

if uselaprint
    xlabel('$x_1$')
    ylabel('$x_2$')
    title('')
    text(8,-8,'\large $\mathcal{X}$')
    text(-4.5,-0.5,'\large Pre($\mathcal{X}$,$\mathcal{W}$)')
    laprint(gcf,['preSet_' name],'width',width)    
else
    set(gca,'FontSize',ftsize)
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
    % H = text(8,-8,'{\it X}')
    % get(H)
    % set(H,'FontSize',ftsize)
    % text(-1,-1,'Pre({\it X})')
    print(gcf,'-depsc2',['preSet_' name '.eps']);
end




