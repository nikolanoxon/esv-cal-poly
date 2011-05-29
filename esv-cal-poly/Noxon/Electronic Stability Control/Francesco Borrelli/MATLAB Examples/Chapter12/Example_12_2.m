%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Example 12_2
% \label{ex:rhc2}
% Francesco Borrelli July 05 2009
% prepared by Stefan Richter, 27th August 2008
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5



clear all
sysStruct.A=[     2     1
    0     0.5];
sysStruct.B = [1;0];
sysStruct.C= eye(2);
sysStruct.D= [0;0];
sysStruct.xmin    =   [-10; -10];
sysStruct.xmax    =   [10; 10];
sysStruct.ymin    =   sysStruct.xmin;
sysStruct.ymax    =   sysStruct.xmax;
sysStruct.umin    =   -1;
sysStruct.umax    =   1;
probStruct.norm = 2;
probStruct.Q=eye(2); % keep Q fixed all the time
probStruct.subopt_lev=0;
probStruct.Tconstraint = 0;
probStruct.P_N=zeros(2,2) ;
ftsize=28;
ftsize_small=20;

%%% use laprint to produce pictures
uselaprint=0;
% laprint options
if uselaprint
    set(0,'defaulttextinterpreter','none')
    width = 10;
end
border = 0; % around state-space in figures

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Compute controllers for 3 different parameter settings +  plot their
% corresponding closed loop trajectories starting from same x(0)'s
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all
figure
hold on;
grid on
clear Options;

R = {10, 2, 1};
N = { 2, 3, 4};
ctrl = {};
% ctrlonline = {};

for i=1:length(R)
    probStruct.R = R{i};
    probStruct.N = N{i};
    ctrl{i} = mpt_control(sysStruct,probStruct);
    %     ctrlonline{i} = mpt_control(sysStruct,probStruct,'on-line');
end

% generate a set of initial states
% idea: sample uniformly from a polytope being the Minkowski Sum of C_inf
% and the unitbox
% C_inf
interv_length = 1.5;
C_inf = cinf_function(sysStruct);
sample_box = C_inf + unitbox(2,0.5);
sample_box = intersect(sample_box, unitbox(2,10)); % bound it

% generate samples over state space
X01 = sysStruct.xmin(1):interv_length:sysStruct.xmax(1);
X02 = sysStruct.xmax(2):-interv_length:sysStruct.xmin(2);
X0 = [];
for i=1:length(X01)
    for j=1:length(X02)
        x0_temp = [X01(i); X02(j)];
        if isinside(sample_box, x0_temp)
            X0 = [X0, x0_temp];
        end
    end
end
% plot(X0(1,:), X0(2,:), 'ko')
% hold on
% plot(C_inf, struct('wire', 1))
% pause

% simulate system
n_time_steps_sim = 10;
X={};
linespecs = {'k-', 'k-', 'k-'}; % for different settings 1,2,3
fname_suff = {'a', 'b', 'c'};

for i=1:length(R)
    figure(i)
    hold on;
    grid minor
    for j=1:size(X0,2)
        [X{i}{j},U_temp,Y_temp,D_temp,cost,trajectory,feasible]=...
            mpt_computeTrajectory(ctrl{i},X0(:,j),n_time_steps_sim,[]);
        % plot
        linewidth=1;
        % emphasize trajectory starting at [-4;7]
        if all(X0(:,j) == [-4;7])
            linewidth=2;
        end
        % mark all trajectories leading to feasible closed-loop
        % trajectories with boxes otherwise use circles
        marker = 'o';
        if (size(X{i}{j},1)==(n_time_steps_sim+1))
            marker = 's';
            plot(X{i}{j}(:,1), X{i}{j}(:,2), [linespecs{i}, marker],'LineWidth',linewidth,'MarkerFaceColor','k','MarkerSize',10)
        else            
        plot(X{i}{j}(:,1), X{i}{j}(:,2), [linespecs{i}, marker],'LineWidth',linewidth,'MarkerSize',10)
        end
    end
    % save figure
    axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])
    hold off
    if uselaprint
        xlabel('$x_1$')
        ylabel('$x_2$')
        title('')
        laprint(gcf,['Example13-2', fname_suff{i}, '.eps'],'width',width)
    else
        set(gca,'FontSize',ftsize)
        title('')
        xlb=['{\it x}_1'];
        ylb=['{\it x}_2'];
        xlabel(xlb)
        ylabel(ylb)
        print(gcf,'-depsc2',['Example13-2', fname_suff{i}, '.eps']);
    end
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Compute O_inf for all 3 controllers + plot
%%%%%%%%%%%%%%
figure
hold on;
clear Options;

% plot C_inf
Options.color='white';
Options.edgecolor='black';
Options.linewidth=2;
Options_C_inf = Options;
plot(C_inf, Options_C_inf)

% O_inf
invCtrl = {};
for i=1:length(R)
    invCtrl{i} = mpt_invariantSet(ctrl{i});
end

% 3rd controller: O_inf consists of 9 regions that give the non-convex
% object
clear Options
Options.color=[.7 .7 .7];
Options.edgecolor = Options.color;
for i=1:length(invCtrl{3}.Pn)
    plot(invCtrl{3}.Pn(i), Options), hold on
end

% vertex representation:
% % V3 = [];
% % for i=1:length(invCtrl{3}.Pn)
% %     V3 = [V3; extreme(invCtrl{3}.Pn(i))];
% % end
% % % NOTE: By inspection, we found the following vertices of the non-convex
% % % O_inf:
V3 = [-7.6667,10;-6.4583,10;-4.6667,8;-3.8,7.2;1,0;7.6667,-10;...
    6.4583,-10;4.6667,-8;3.8,-7.2;-1,0;-7.6667,10;]
% plot it:
plot(V3(:,1), V3(:,2), 'k-', 'Linewidth', 2);


% 2nd controller: O_inf consists of 5 regions that give the non-convex
% object
clear Options
Options.color=[.5 .5 .5];
Options.edgecolor = Options.color;
for i=1:length(invCtrl{2}.Pn)
    plot(invCtrl{2}.Pn(i), Options), hold on
end

% vertex representation:
% % V2 = [];
% % for i=1:length(invCtrl{2}.Pn)
% %     V2 = [V2; extreme(invCtrl{2}.Pn(i))];
% % end
% % % NOTE: By inspection, we found the following vertices of the non-convex
% % % O_inf:
V2 = [-6.02,8.88;-3.4167,6;-1,3;5,-6;7.6667,-10;6.8056,-10;6.02,-8.88;...
    3.4167,-6;1,-3;-7.6667,10;-6.8056,10;-6.02,8.88;]
% plot it:
plot(V2(:,1), V2(:,2), 'k-', 'Linewidth', 2);


% 1st controller: O_inf = {0}
plot(0, 0, ['k','.'], 'Linewidth', 2, 'MarkerSize',15);

% do prettify:
% frame the regions:
Options_C_inf.wire=1;
Options_C_inf.color='black';
Options_C_inf.edgecolor=Options_C_inf.color;
plot(C_inf, Options_C_inf)

% plot the initial conditions [-4,7] and [-4, 8.5] that is used in the discussion of the
% example
plot(-4, 7, 'kx', 'Linewidth', 2, 'MarkerSize',10);
plot(-4, 8.5, 'kx', 'Linewidth', 2, 'MarkerSize',10);

grid minor
axis([sysStruct.xmin(1)-border,sysStruct.xmax(1)+border,sysStruct.xmin(2)-border,sysStruct.xmax(2)+border])

if uselaprint
    xlabel('$x_1$')
    ylabel('$x_2$')
    title('')
    laprint(gcf,'Example13-2d','width',width)
else
    set(gca,'FontSize',ftsize)
    title('')
    xlb=['{\it x}_1'];
    ylb=['{\it x}_2'];
    xlabel(xlb)
    ylabel(ylb)
    H = text(-3,7,'{\it x(0)=[-4,7]}')
    get(H)
    set(H,'FontSize',ftsize_small)
    G = text(-3.5,8.5,'{\it x(0)=[-4,8.5]}')
    get(G)
    set(G,'FontSize',ftsize_small)
       
    print(gcf,'-depsc2','Example13-2d.eps');
end
hold off


