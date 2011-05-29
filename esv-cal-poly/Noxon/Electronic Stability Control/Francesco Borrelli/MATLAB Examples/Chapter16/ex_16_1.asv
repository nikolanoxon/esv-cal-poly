% Example 16.1
% Two Mode System
% Francesco Borrelli Feb 2010


% 
% disp('The affine state and output update functions have the form: 
% disp('  x(k+1) = A{i} x(k) + B{i} u(k) + f{i} 
% disp('  y(k)   = C{i} x(k) + D{i} u(k) + g{i} 
% fprintf('\n 

sysStruct1.A = [-1 2; 2 -3];
sysStruct1.B = [0;1]; 
sysStruct1.C = [1 0;0 1]; 
sysStruct1.D = [0;0]; 
sysStruct1.xmin = [-1 0]';
sysStruct1.xmax = [1 1]'; 
sysStruct1.umin = -1; 
sysStruct1.umax = 1; 

sysStruct2.A = [1 -2;1 1];
sysStruct2.B = [1;0];
sysStruct2.C = [1 0;0 1]; 
sysStruct2.D = [0;0]; 
sysStruct2.xmin = [-1 -.5]';
sysStruct2.xmax = [1 0]'; 
sysStruct2.umin = -1; 
sysStruct2.umax = 1; 


%probStruct.Q = eye(2);
probStruct.Q = [1 1; 1 15]
probStruct.R = 10;
probStruct.norm = 2;
probStruct.N = 2;
probStruct.subopt_lev = 0;
probStruct.Tconstraint=0;
ftsize=28;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Computing the four control law corresponding to teh four switches.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Options.newfigure = 0;
figure
hold on

ok11=1;
try
    ctrl11 = mpt_control({sysStruct1 sysStruct1}, probStruct);
    plot(ctrl11,Options);
catch
    ok11=0;
end
ok12=1;
try
    ctrl12 = mpt_control({sysStruct1 sysStruct2}, probStruct);
    plot(ctrl12,Options);
catch
    ok12=0;
end
ok21=1;
try
ctrl21 = mpt_control({sysStruct2 sysStruct1}, probStruct);
plot(ctrl21,Options);
catch
    ok21=0;
end
ok22=1;
try
ctrl22 = mpt_control({sysStruct2 sysStruct2}, probStruct);
plot(ctrl22,Options);
catch
    ok22=0;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Plotting the control Partition
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



figure
hold on
TTt=0.005;
X=[];
Y=[];
Z=[];
ix=0;
X=-0.5:TTt:1;
Y=-0.5:TTt:1;
for i=-0.5:TTt:1;
ix=ix+1;
iy=0;
for j=-0.5:TTt:1;
     iy=iy+1;
     x=[i;j];
    if ok11
        [u11,feasible11,region11,cost11,details11] = mpt_getInput(ctrl11,x);
    else 
        feasible11=0;
        region11=0;
    end
    if ok12
    [u12,feasible12,region12,cost12,details12] = mpt_getInput(ctrl12,x);
    else 
        feasible12=0;
        region12=0;
    end
    if ok21
    [u21,feasible21,region21,cost21,details21] = mpt_getInput(ctrl21,x);
    else 
        feasible21=0;
        region21=0;
    end
    if ok22
    [u22,feasible22,region22,cost22,details22] = mpt_getInput(ctrl22,x);
    else 
        feasible22=0;
        region22=0;
    end
    
    
    if feasible11
        cost(1)=cost11;
    else
        cost(1)=1e100;
    end
    if feasible12
        cost(2)=cost12;
    else
        cost(2)=1e100;
    end
    if feasible21
        cost(3)=cost21;
    else
        cost(3)=1e100;
    end

    if feasible22
        cost(4)=cost22;
    else
        cost(4)=1e100;
    end

    reg(1)=region11;
    reg(2)=region12;
    reg(3)=region21;
    reg(4)=region22;
    
    if feasible11+feasible12+feasible21+feasible22>=1
            [minc,ir]=min(cost);
            Z(ix,iy)=minc;
            if size(ir)>1
            plot(x(1),x(2),'m*');hold on
            Cc(ix,iy)=5;
            else            
            if ir==1;
            plot(x(1),x(2),'r*');hold on
            Cc(ix,iy)=1;
            end
            if ir==2;
            plot(x(1),x(2),'b*');hold on
            Cc(ix,iy)=2;
            end
            if ir==3;
            plot(x(1),x(2),'g*');hold on
            Cc(ix,iy)=3;
            end
            if ir==4;
            Cc(ix,iy)=4;
            plot(x(1),x(2),'k*');hold on
            end
            end

    end
end
end

disp('done plotting')

figure
hold on
ix=1;
iy=1;
for i=-0.5:3*TTt:1;
for j=-0.5:3*TTt:1;
     x=[i;j];     
  if Cc(ix,iy)>0
            if Cc(ix,iy)==5,
            plot(x(1),x(2),'ko','MarkerFaceColor','k','MarkerSize',3);hold on
            else            
            if Cc(ix,iy)==1,
            plot(x(1),x(2),'ro','MarkerFaceColor','r','MarkerSize',3);hold on
            end
            if Cc(ix,iy)==2,
            plot(x(1),x(2),'bo','MarkerFaceColor','b','MarkerSize',3);hold on
            end
            if Cc(ix,iy)==3,
            plot(x(1),x(2),'go','MarkerFaceColor','g','MarkerSize',3);hold on
            end
            if Cc(ix,iy)==4,
            plot(x(1),x(2),'mo','MarkerFaceColor','m','MarkerSize',3);hold on
            end
            end
  end
iy=iy+3;  
end
ix=ix+3;
iy=1;
end
Options.wire=1;
Options.color='k';
plot(ctrl11,Options);
plot(ctrl12,Options);
plot(ctrl21,Options);
plot(ctrl22,Options);
axis([min(sysStruct2.xmin(1),sysStruct1.xmin(1)),max(sysStruct2.xmax(1),sysStruct1.xmax(1)),min(sysStruct2.xmin(2),sysStruct1.xmin(2)),max(sysStruct2.xmax(2),sysStruct1.xmax(2))])
xlabel('$x_1$')
ylabel('$x_2$')
title('')
text(0.5,0.5,'$\bf{v_1}$')
text(-0.2,0.1,'$\bf{v_2}$')
text(0.4,0.1,'$\bf{v_2}$')
text(-0.2,-0.2,'$\bf{v_4}$')
text(0.7,-0.2,'$\bf{v_3}$')
%    text(-5,0,'Reach($\mathcal{X}$)')
  set(0,'defaulttextinterpreter','none')
    width = 6;
laprint(gcf,['ex16_1_fullreg'],'width',width) 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plotting routines
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure
plot(ctrl11)
set(gca,'FontSize',ftsize)
axis([sysStruct1.xmin(1),sysStruct1.xmax(1),sysStruct1.xmin(2),sysStruct1.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_1_11.eps']);

figure
plot(ctrl12)
set(gca,'FontSize',ftsize)
axis([sysStruct1.xmin(1),sysStruct1.xmax(1),sysStruct1.xmin(2),sysStruct1.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_1_12.eps']);

figure
plot(ctrl21)
set(gca,'FontSize',ftsize)
axis([sysStruct2.xmin(1),sysStruct2.xmax(1),sysStruct2.xmin(2),sysStruct2.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_1_21.eps']);

figure
plot(ctrl22)
set(gca,'FontSize',ftsize)
axis([sysStruct2.xmin(1),sysStruct2.xmax(1),sysStruct2.xmin(2),sysStruct2.xmax(2)])
title('')
xlb=['{\it x}_1'];
ylb=['{\it x}_2'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['ex16_1_22.eps']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% all four
%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure
Options.newfigure = 0;
hold on
pt11=ctrl11.Pn;
pt12=ctrl12.Pn;
pt21=ctrl21.Pn;
pt22=ctrl22.Pn;
for k=1:length(pt11)
intpol=0;
for j=1:length(pt12)
    if isfulldim(intersect(pt11(k),pt12(j)))
        intpol=1;
    end
end
   if ~intpol
        Options.wire=0;
        Options.shade=1;
        Options.color='r'
        Options.linewidth=1; 
        plot(pt11(k),Options);        
    else
         Options.wire=0;
         Options.shade=1;
         Options.linewidth=3; 
          Options.color='w'
         plot(pt11(k),Options);
    end
end
for k=1:length(pt12)
intpol=0;
for j=1:length(pt11)
    if isfulldim(intersect(pt12(k),pt11(j)))
        intpol=1;
    end
end
   if ~intpol
        Options.wire=0;
        Options.shade=1;
        Options.color='b'
        Options.linewidth=1; 
        plot(pt12(k),Options);        
    else
         Options.wire=0;
         Options.shade=1;
         Options.linewidth=3; 
          Options.color='w'
         plot(pt12(k),Options);
    end
end
for k=1:length(pt21)
intpol=0;
for j=1:length(pt22)
    if isfulldim(intersect(pt21(k),pt22(j)))
        intpol=1;
    end
end
   if ~intpol
        Options.wire=0;
        Options.shade=1;
        Options.color='g'
        Options.linewidth=1; 
        plot(pt21(k),Options);        
    else
         Options.wire=0;
         Options.shade=1;
         Options.linewidth=3; 
          Options.color='w'
         plot(pt21(k),Options);
    end
end
for k=1:length(pt22)
intpol=0;
for j=1:length(pt21)
    if isfulldim(intersect(pt22(k),pt21(j)))
        intpol=1;
    end
end
   if ~intpol
        Options.wire=0;
        Options.shade=1;
        Options.color='m'
        Options.linewidth=1; 
        plot(pt22(k),Options);        
    else
         Options.wire=0;
         Options.shade=1;
         Options.linewidth=3; 
          Options.color='w'
         plot(pt22(k),Options);
    end
end

axis([min(sysStruct2.xmin(1),sysStruct1.xmin(1)),max(sysStruct2.xmax(1),sysStruct1.xmax(1)),min(sysStruct2.xmin(2),sysStruct1.xmin(2)),max(sysStruct2.xmax(2),sysStruct1.xmax(2))])
xlabel('$x_1$')
ylabel('$x_2$')
title('')
%    text(8,-8,'$\mathcal{X}$')
%    text(-5,0,'Reach($\mathcal{X}$)')
  set(0,'defaulttextinterpreter','none')
    width = 6;
laprint(gcf,['ex16_1_full'],'width',width)  


