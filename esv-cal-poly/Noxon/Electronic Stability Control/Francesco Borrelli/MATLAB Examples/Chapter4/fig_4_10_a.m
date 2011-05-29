function fig_generate

close all

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

% plot the result
plot(C2, 'g', C1, 'c', B, 'r');
axis([-5 5 -5 5]);
% text in polytopes
text(0, 0, 'B');
text(-2.5, 0, 'C2');
text(2, 0, 'C1');
psfrag{1}{1} = 'B'; psfrag{1}{2} = '\mathcal{B}';
psfrag{2}{1} = 'C1'; psfrag{2}{2} = '\mathcal{C}_1';
psfrag{3}{1} = 'C2'; psfrag{3}{2} = '\mathcal{C}_2';

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
close all
% plot the result
plot(C2, 'g', C1, 'c', B, 'r');
axis([-5 5 -5 5]);
axis off
% text in polytopes
text(0, 0, '\mathcal{B}');
text(-2.5, 0, '\mathcal{C}_2');
text(2, 0, '\mathcal{C}_1');
% custom axis labels & font size
h = xlabel('x_1');
set(h, 'FontSize', label_font_size);
h = ylabel('x_2');
set(h, 'FontSize', label_font_size);
h = zlabel('x_3');
set(h, 'FontSize', label_font_size);
% font size of tick labels
set(gca, 'FontSize', tick_font_size);

laprint(gcf, [figure_name '_tex']);

fprintf('Figure "%s" generated...\n', figure_name);
for i = 1:size(psfrag, 2)
    disp(['Use PSFRAG substitution: "' psfrag{i}{1} '" -> "' psfrag{i}{2} '"']);
end

close all
