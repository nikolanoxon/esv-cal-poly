function fig_generate

label_font_size = 14;
tick_font_size = 10;
figure_name = 'fig_4_0_1';

close all
V = 100*[0 0 0; 1 1 1; 1 1 2 ; 1 2 1];
P = polytope(V);
plot(P, 'y');
hold on
plot3(V(:, 1)/100, V(:, 2)/100,V(:, 3)/100, 'k.', 'markersize', 16);
%plot(0.4, 0.8, 'k.', 'markersize', 16);
%text(0.42,0.82,'\bar{x}');
axis([-0.5 10 -0.5 10 -0.5 10]);

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
xlabel('$x_1$')
ylabel('$x_2$')
zlabel('$x_3$')
title('')
laprint(gcf, [figure_name '_tex']);

fprintf('Figure "%s" generated...\n', figure_name);
%close all
