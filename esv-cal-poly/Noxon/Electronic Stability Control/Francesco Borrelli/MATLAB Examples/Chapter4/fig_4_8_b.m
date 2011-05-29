function fig_generate

close all

% other options
label_font_size = 14;
tick_font_size = 10;
line_width = 3;
figure_name = 'fig_4_8_b';

Q = unitbox(2)*1;
P = unitbox(2)*4;
PpQ = P + Q;

% plot the result
plot(PpQ, 'y', P, 'g', Q, 'c');
axis([-5.5 5.5 -5.5 5.5]);
% text in polytopes
text(-4.8, 4.5, 'PpQ');
text(-3.8, 3.5, 'P');
text(-0.5, 0, 'Q');


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
plot(PpQ, 'y', P, 'g', Q, 'c');
axis([-5.5 5.5 -5.5 5.5]);
% text in polytopes
text(-4.8, 4.5, '\mathcal{P} \oplus \mathcal{Q}');
text(-3.8, 3.5, '\mathcal{P}');
text(-0.5, 0, '\mathcal{Q}');
h = xlabel('x_1');
set(h, 'FontSize', label_font_size);
h = ylabel('x_2');
set(h, 'FontSize', label_font_size);
set(gca, 'FontSize', tick_font_size);
laprint(gcf, [figure_name '_tex']);

fprintf('Figure "%s" generated...\n', figure_name);
disp('Use PSFRAG substitution: "P" -> "\mathcal{P}"');
disp('Use PSFRAG substitution: "PpQ" -> "\mathcal{P} \oplus \mathcal{Q}"');
disp('Use PSFRAG substitution: "Q" -> "\mathcal{Q}"');

close all
