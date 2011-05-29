function fig_generate

label_font_size = 14;
tick_font_size = 10;
line_width = 3;
figure_name = 'fig_4_5';

close all
V = [4.5 -9; 8 0; 1 8.5; -4 6; -5 -3];
% V = [-7.7 3.5; -4 6; 0.5 7.9; 7 8; 7.5 -5; -2.5 -8; -7.3 -1.9];
P = polytope(V);
[H, K] = double(P);
plot(P, 'y');
hold on
for i = 1:size(H, 1)
    h = H(i, :);
    k = K(i);
    x1 = [-10 10];
    x2 = [(k-h(1)*x1(1))/h(2) (k-h(1)*x1(2))/h(2)];
    plot(x1, x2, 'k', 'LineWidth', line_width);
end
[x, r] = chebyball(P);

% plot the center of the chebyball
plot(x(1), x(2), 'b.', 'MarkerSize', 14);

% plot the chebyball circle
clear i
plot(r*exp(sqrt(-1)*linspace(0,2*pi,1000))+x'*[1 sqrt(-1)].', 'b-', 'LineWidth', line_width);

axis([-10 10 -10 10]);
axis('square');

% custom axis labels & font size
h = xlabel('$x_1$');
set(h, 'FontSize', label_font_size);
h = ylabel('$x_2$');
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
%close all
