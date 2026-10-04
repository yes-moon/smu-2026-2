clear all; close all; clc;

load fisheriris.mat;

% sepal length, width, petal length, width 4개 특징 모두 이용
setdata = [];
setdata = meas(:,1:4);

% 매트랩 내부함수. 출력: mat_label: 그룹 할당 결과, mat_CP: 각 그룹의 중심 좌표
[mat_label, mat_CP] = kmeans(setdata, 3, 'Start', setdata(1:3,:));

%%
grp = 3; % k = 3;
class = [1 2 3];

my_CP = setdata(1:grp,:); 

% 수업시간에 구현한 my_kmeans 부분을 함수로 만들어서 호출
[Final_label, my_CP] = my_kmeans(setdata, grp, class);

figure;
subplot(311); plot(mat_label); axis tight; title('kmeans');
subplot(312); plot(Final_label); axis tight; title('my kmeans');
subplot(313); plot(mat_label-Final_label); axis tight; title('difference');

my_CP
mat_CP

% 매트랩 내장함수 결과와 다른 데이터 개수 (0이면 완전히 같음)
length(find(mat_label ~= Final_label))
