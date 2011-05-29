% Exmaple 15.2
% Spring-mass system
% Francesco Borrelli Feb 2010

M=1;
b1=1;
b2=50;
k1=1;
k2=3;
d1=1;
d2=7.5;
xm=1;
Ts=0.5;

figure(3)
x1=-10:.1:10;
k=(k1*x1+d1).*(x1<=xm)+(k2*x1+d2).*(x1>xm);
plot(x1,k)

A1=[0 1;-k1/M -b1/M]; B1=[0 0;1/M -d1/M];
A2=[0 1;-k1/M -b2/M]; B2=[0 0;1/M -d1/M];
A3=[0 1;-k2/M -b1/M]; B3=[0 0;1/M -d2/M];
A4=[0 1;-k2/M -b2/M]; B4=[0 0;1/M -d2/M];
C=eye(2);D=zeros(2,2);
[Az1,Bz1]=c2d(A1,B1,Ts);
[Az2,Bz2]=c2d(A2,B2,Ts);
[Az3,Bz3]=c2d(A3,B3,Ts);
[Az4,Bz4]=c2d(A4,B4,Ts);

A111=Az1(1,1);A112=Az1(1,2);A121=Az1(2,1);A122=Az1(2,2);
A211=Az1(1,1);A212=Az2(1,2);A221=Az2(2,1);A222=Az2(2,2);
A311=Az1(1,1);A312=Az3(1,2);A321=Az3(2,1);A322=Az3(2,2);
A411=Az1(1,1);A412=Az4(1,2);A421=Az4(2,1);A422=Az4(2,2);
B111=Bz1(1,1);B112=Bz1(1,2);B121=Bz1(2,1);B122=Bz1(2,2);
B211=Bz1(1,1);B212=Bz2(1,2);B221=Bz2(2,1);B222=Bz2(2,2);
B311=Bz1(1,1);B312=Bz3(1,2);B321=Bz3(2,1);B322=Bz3(2,2);
B411=Bz1(1,1);B412=Bz4(1,2);B421=Bz4(2,1);B422=Bz4(2,2);

sysStruct = mpt_sys('springmass',Ts);

%*****************************************
% PWA matrices
for i=1:length(sysStruct.A),
     disp(sprintf('Mode %d:',i));
     sysStruct.A{i},sysStruct.B{i},sysStruct.f{i}
 end
%*****************************************
 
%*****************************************
%Hysdel Code
%sysStruct.data.hysdel.code
%*****************************************

%*****************************************
%MLD model
% sysStruct.data.MLD
%*****************************************

 
 
 
x0=[0;0];
Tend=10;
TT=Tend/Ts;
T=0:Ts:Tend;
u1=3;
ftsize=28;

%****************************************
U1=[u1*ones(TT,1) zeros(TT,1)];
[X,U,Y,mode]=mpt_simSys(sysStruct,x0,U1);
X=[x0';X];
figure(1)
subplot(2,1,1)
h=plot(T,X(:,1));
set(h,'linewidth',2.0);
%title('Position x_1 (m) for u_2=0 (large damping)');
%xlabel('time (s)')
set(gca,'FontSize',ftsize)
%axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['time'];
ylb=['Position {\it x}_1'];
xlabel(xlb)
ylabel(ylb)
grid on
subplot(2,1,2)
h=plot(T,[mode(1); mode]);
set(h,'linewidth',2.0);
set(gca,'FontSize',ftsize)
set(gca,'YLim',[1 4],'YTick',[1,2,3,4])
%axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['time'];
ylb=['Mode'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['spring-mass-u2=0.eps']);

%****************************************
U2=[u1*ones(TT,1) ones(TT,1)];
[X,U,Y,mode]=mpt_simSys(sysStruct,x0,U2)
X=[x0';X];
figure(2)
subplot(2,1,1)
h=plot(T,X(:,1));
set(h,'linewidth',2.0);
set(gca,'FontSize',ftsize)
%axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['time'];
ylb=['Position {\it x}_1'];
xlabel(xlb)
ylabel(ylb)
grid on
subplot(2,1,2)
h=plot(T,[mode(1); mode]);
set(h,'linewidth',2.0);
set(gca,'FontSize',ftsize)
set(gca,'YLim',[1 4],'YTick',[1,2,3,4])
%axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
title('')
xlb=['time'];
ylb=['Mode'];
xlabel(xlb)
ylabel(ylb)
print(gcf,'-depsc2',['spring-mass-u2=1.eps']);
%****************************************

