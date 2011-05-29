function mat2latexmat(Hi,name,filename);

% Write tex file with solution to problem #i
%

fid=fopen(filename,'a');
%fprintf(fid,'\\documentclass{article}\n \\begin{document}\n \\[ \n');
fprintf(fid,'\\[ \n');

fprintf(fid,'%s =  ',name);
      fprintf(fid,sprintf('\\\\smallmat{'));

  for i=1:size(Hi,1),
      for j=1:size(Hi,2),
         fprintf(fid,sprintf('%7.2f',Hi(i,j)));
      if j~=size(Hi,2),   fprintf(fid,' & '); end
      end
      if i~=size(Hi,1),  fprintf(fid,'\\\\  \n '); end
  end
  fprintf(fid,'} \n ');
fprintf(fid,'\\] \n');

fclose(fid);
