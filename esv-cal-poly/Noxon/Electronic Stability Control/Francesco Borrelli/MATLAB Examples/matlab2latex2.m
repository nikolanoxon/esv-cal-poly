function matlab2latex2(Hi,Ki,Fi,Gi,same,filename,nu,nx,ny,I1);

% Write tex file with solution to problem #i
%
% (C) 1999 by A. Bemporad, Zurich, 25/6/99

tempin=find(I1);
index=tempin(1);

% Build an array of numbers from 1:length(Hi) of regions which have
% not been joined, to which 'same' refers to

% orig_reg=[1:length(same)]';
% for j=1:length(same),
%    for h=1:length(same{j}),
%       i=find(orig_reg==same{j}(h));
%       orig_reg(i)=[];
%    end
% end

fid=fopen(filename,'w');
%fprintf(fid,'\\documentclass{article}\n \\begin{document}\n \\[ \n');
fprintf(fid,'\\[ \n');

fprintf(fid,'u = \\left\\{\\ba{lcll}\n');

nR=length(Ki);
orig_reg=[1:nR]';

nx=size(Hi{1},2);

for i=1:nR,
   %	if ~isempty(Hi{i}),   
   %polyplot([Hi{i};eye(2);-eye(2)],[Ki{i};xmax;xmax;xmax;xmax],rand(1,3));
   %polyplot(Hi{i},Ki{i},rand(1,3));
   
   isFi=0;
   if norm(Fi{i}(index,:),'inf')>=1e-5,
      isFi=1;
      fprintf(fid,sprintf('\\\\smallmat{'));
      for h=1:nx,
         fprintf(fid,sprintf('%7.2f',Fi{i}(index,h)));
         if h<nx,
            fprintf(fid,' & ');
         end
      end
      %fprintf(fid,sprintf('\\\\\\\\%7.2f & %7.2f',Fi{i}(2,1),Fi{i}(2,1)));
      fprintf(fid,'}\n x');
   end
   aux=Gi{i}(index);
   if norm(aux,'inf')>=1e-5,
      if isFi & (aux>0),
         fprintf(fid,'+');
      end
      if aux<0,
         fprintf(fid,'-');
      end
      %fprintf(fid,'\\smallmat{');
      fprintf(fid,sprintf('\\\\smallnum{ %7.2f}',abs(aux)));
      %fprintf(fid,sprintf('\\\\\\\\ %7.2f',Gi{i}(2)));
      %fprintf(fid,'}');
   end
   fprintf(fid,'& \\mbox{if} &  \n \\smallmat{');
   
   nn=length(Ki{i}); % -4 because of the additional constraints (xmax)
   for j=1:nn,
      for h=1:nx,
         fprintf(fid,sprintf('%7.2f',Hi{i}(j,h)));
         if h<nx,
            fprintf(fid,' & ');
         end
      end
      
      if j<nn,
         fprintf(fid,'\\\\ \n');
      end
   end            
   fprintf(fid,'} x \\leq \\smallmat{');
   
   for j=1:nn,
      fprintf(fid,sprintf('%7.2f & %7.2f',Ki{i}(j)));
      if j<nn,
         fprintf(fid,'\\\\ \n');
      end
   end            
   fprintf(fid,'} & ');
   fprintf(fid,sprintf('\\\\ \\\\mbox{(Region \\\\#%d',orig_reg(i)));
%    aux=same{i};
%    for j=1:length(aux),
%       fprintf(fid,sprintf(', \\\\#%d',aux(j)));
%    end
   fprintf(fid,')}');
   fprintf(fid,'\\\\ \\\\ \n');
   %   end
end
fprintf(fid,'\\ea\\right.\n \ea\right. \n');
%fprintf(fid,'\\] \n \\end{document}');
fprintf(fid,'\\] \n');

fclose(fid);
