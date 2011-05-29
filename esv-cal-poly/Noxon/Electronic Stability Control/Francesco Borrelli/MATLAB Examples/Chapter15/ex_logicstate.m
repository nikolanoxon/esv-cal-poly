% Example 15.3
% Systsem with logic state
% Francesco Borrelli Feb 2010

clear all
Ts=1;
sysStruct = mpt_sys('SLS',Ts);

%*****************************************
%Hysdel Code
%sysStruct.data.hysdel.code
%*****************************************

%*****************************************
%MLD model
% sysStruct.data.MLD
%*****************************************

%*****************************************
x0=[0;0];
Tend=20;
TT=Tend/Ts;
T=0:Ts:Tend;
u1=3;
ftsize=28;

U1=[-8*ones(TT/2,1);8*ones(TT/2,1)];
[X1,U,Y,mode]=mpt_simSys(sysStruct,x0,U1);
X1=[x0';X1];
U2=[-4*ones(TT/4,1);8*ones(3*TT/4,1)];
[X2,U,Y,mode]=mpt_simSys(sysStruct,x0,U2);
X2=[x0';X2];

%***********************************8
close all
figure;
subplot(311)
h=stairs(T,X1(:,1));hold on
set(h,'linewidth',2.0);
h=stairs(T,X2(:,1));
set(h,'linewidth',2.0,'linestyle','--');
ylabel('Continuous state {\it x}_1');
h=stairs(T,-1+0*T);
set(h,'linewidth',1.0,'linestyle','-.');

grid on

subplot(312)
h=stairs(T,X1(:,2));hold on
set(h,'linewidth',2.0);
h=stairs(T,X2(:,2));
set(h,'linewidth',2.0,'linestyle','--');
ylabel('Logic state {\it x}_2');
axis([0 TT -.5 1.5]);
grid on


subplot(313)
h=stairs(T(1:end-1),U1);
set(h,'linewidth',2.0);hold on
h=stairs(T(1:end-1),U2);
set(h,'linewidth',2.0,'linestyle','--');
ylabel('Continuous input u');
grid on
xlabel('time steps')

%set(gcf,'Position',[318    96   511   820]);
%h=plot(T,[mode(1); mode]);
%set(h,'linewidth',2.0);
%set(gca,'FontSize',ftsize)
%set(gca,'YLim',[1 4],'YTick',[1,2,3,4])
%axis([sysStruct.xmin(1),sysStruct.xmax(1),sysStruct.xmin(2),sysStruct.xmax(2)])
print(gcf,'-depsc2',['switch3-OLsim']);
