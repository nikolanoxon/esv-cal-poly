function generate_figures

w = warning;
warning('off');

% cd(D);
d = dir('.');
for i = 1:length(d)
    n = d(i).name;
    if length(n) <= length('fig_')
        continue
    end
    if ~isempty(findstr(n, '_matlab'))
        % skip all m-files to which we export the FIG files
        continue
    end
    [p, n, e] = fileparts(n);
    if isequal(e, '.m') && isequal(n(1:4), 'fig_')
        fprintf('\nRunning %s...\n', n);
        lasterr('');
        try
            run(n);
        catch
            disp(lasterr);
        end
    end
end
warning(w);
