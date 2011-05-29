function fig_generate

label_font_size = 14;
tick_font_size = 10;
figure_name = 'fig_4_0';

close all
V = [-7.7 3.5; -4 6; 0.5 7.9; 7 8; 7.5 -5; -2.5 -8; -7.3 -1.9];
P = polytope(V);
plot(P, 'y');
hold on
plot(V(:, 1), V(:, 2), 'k.', 'markersize', 16);
axis([-10 10 -10 10]);

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
xlabel('$x_1$')
ylabel('$x_2$')
title('')
laprint(gcf, [figure_name '_tex']);

fprintf('Figure "%s" generated...\n', figure_name);
close all
