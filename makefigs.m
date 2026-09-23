D = fullfile(fileparts(mfilename('fullpath')), '인공지능개론', 'docs');
cd(fullfile(fileparts(mfilename('fullpath')), '인공지능개론'));

ex1_dataload_visualization
figs = findall(0,'Type','figure');
for k = 1:numel(figs), set(figs(k),'Color','w'); end
exportgraphics(figure(2), fullfile(D,'iris_sepal.png'), 'Resolution',150);
exportgraphics(figure(3), fullfile(D,'iris_petal.png'), 'Resolution',150);
close all

ex5_knn_space
figs = findall(0,'Type','figure');
for k = 1:numel(figs), set(figs(k),'Color','w'); end
exportgraphics(figure(3), fullfile(D,'knn_decision_boundary.png'), 'Resolution',150);
close all
disp('figures saved');
