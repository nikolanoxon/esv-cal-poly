function fig_generate

close all
psfrag = {};

% other options
label_font_size = 14;
tick_font_size = 10;
line_width = 2;
figure_name = mfilename;

V1 = [0 2; 0 -2; 2 4; 2 -4; 4 2; 4 -2];
V2 = [0 2; 0 -2; -2 4; -2 -4; -4 2; -4 -2];
C1 = polytope(V1);
C2 = polytope(V2);
B = unitbox(2)*0.5;

H = hull([C1 C2]);

% plot the result

plot(H, 'r');
hold on
plot([C1 C2], 'k', struct('edgecolor', 'k', 'wire', 1, 'wirestyle', '--', 'linewidth', line_width));
axis([-5 5 -5 5]);

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
for i = 1:size(psfrag, 2)
    disp(['Use PSFRAG substitution: "' psfrag{i}{1} '" -> "' psfrag{i}{2} '"']);
end

close all
