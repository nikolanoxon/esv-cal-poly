function fig_generate

close all

label_font_size = 14;
tick_font_size = 10;
line_width = 2;
figure_name = 'fig_4_3_b';

V1 = [-6 0; -3 6; -3 -6; 0 0];
V2 = [0 0; 3 6; 3 -6; 6 0];
P1 = polytope(V1);
P2 = polytope(V2);
Pconv = hull([P1 P2]);

plot(Pconv, 'y', struct('linewidth', line_width));
axis([-6 6 -15 15]);
text(-2, 0, 'convR');

% custom axis labels & font size
h = xlabel('x_1');
set(h, 'FontSize', label_font_size);
h = ylabel('x_2');
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
close all
plot(Pconv, 'y', struct('linewidth', line_width));
axis([-6 6 -15 15]);
text(-2, 0, '\text{conv}(\mathcal{R})');
h = xlabel('x_1');
set(h, 'FontSize', label_font_size);
h = ylabel('x_2');
set(h, 'FontSize', label_font_size);
set(gca, 'FontSize', tick_font_size);
laprint(gcf, [figure_name '_tex']);

fprintf('Figure "%s" generated...\n', figure_name);
disp('Use PSFRAG substitution: "convR" -> "\text{conv}(\mathcal{R})"');

close all
