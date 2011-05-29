function fig_generate

close all

% plot the lines connecting 3D original with 2D projection?
plot_connecting_lines = true;

% other options
label_font_size = 14;
tick_font_size = 10;
line_width = 3;
figure_name = mfilename;
shift_up = [0; 0; 4];


V3d = [1.36329353773768 -0.45548263159156 -0.96672211203804;-0.27524991966334 0.84273442175719 -1.07950987824651;-0.33688442700986 -1.19378220956279 -1.21608005249281;1 0.75 0.49294012634954;-0.45351251111816 -0.73553800566471 -0.19723318642597];
P3d = polytope(V3d) + shift_up;
P2d = projection(P3d, [1 2]);
V2d = extreme(P2d);
Options5.shade=0;
Options5.linewidth=line_width;
plot(P3d, 'r', Options5);
hold on
plot(P2d, 'g', struct('linewidth', line_width));

% plot the lines connecting 3D original with 2D projection?
if plot_connecting_lines
    V3d = extreme(P3d);
    for i = 1:size(V3d, 1)
        arrow(V3d(i, :), [V3d(i, 1:2) 0], 'Width', line_width);
    end
end

axis([-1 1.5 -2 1.5 0 5]);


% custom axis labels & font size
h = xlabel('x_1');
set(h, 'FontSize', label_font_size);
h = ylabel('x_2');
set(h, 'FontSize', label_font_size);
h = zlabel('x_3');
set(h, 'FontSize', label_font_size);

% font size of tick labels
set(gca, 'FontSize', tick_font_size);

% generate FIG file
saveas(gcf, [figure_name '_matlab'], 'fig');

% generate color EPS
print('-depsc2', '-r300', [figure_name '_color.eps']);

% generate B&W EPS
print('-deps', '-r300', [figure_name '_bw.eps']);

% print using laprint
laprint(gcf, [figure_name '_tex']);

fprintf('Figure "%s" generated...\n', figure_name);
close all
