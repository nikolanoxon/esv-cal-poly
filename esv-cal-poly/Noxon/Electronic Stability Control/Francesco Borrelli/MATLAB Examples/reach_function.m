function [Xreach1]=reach_fucntion(sysStruct,name,uselaprint)
nx = size(sysStruct.A,1);
nu = size(sysStruct.B,2);

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


X = polytope([eye(nx);-eye(nx)],[sysStruct.xmax;-sysStruct.xmin]);
U = polytope([eye(nu);-eye(nu)],[sysStruct.umax;-sysStruct.umin]);
[H,K] = double(X);
[Hu,Ku] = double(U);


%%% reach set 1
% Computing sysStruct.B*U , MPT gives error since it works only for
% invertible matrices
Vu=extreme(U); % Vertices are listed by row!
Vx=extreme(X);

M1=[];
for j=1: size(Vu,1)
    M1(:,j)=sysStruct.B*Vu(j,:)';
end
M1=M1';
M2=[];
for j=1: size(Vx,1)
    M2(:,j)=sysStruct.A*Vx(j,:)';
end
M2=M2';

M=[];
k=0;
for j=1:size(M1,1);
    for i=1:size(M2,1);
        k=k+1;
        M(k,:)=M1(j,:)+M2(i,:);
    end
end

Xreach1 =hull(M);

figure
plot(X,Options2)
hold on
plot(Xreach1,Options) 
border = 6;
%axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])

if uselaprint
    xlabel('$x_1$')
    ylabel('$x_2$')
    title('')
   % text(8,-8,'$\mathcal{X}$')
    text(-5,0,'Reach($\mathcal{X}$)')
    laprint(gcf,['reachSet1_' name],'width',width)    
else
    set(gca,'FontSize',ftsize)
    %axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
    print(gcf,'-depsc2',['reachSet1_' name '.eps']);
end
end
