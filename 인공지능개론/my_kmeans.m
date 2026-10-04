function [Final_label, my_CP] = my_kmeans(setdata, grp, class)
% k-means 직접 구현
% 입력: setdata - 입력 데이터 (행: 데이터, 열: 특징)
%       grp     - 그룹 수 (k)
%       class   - 클래스 번호 배열 (예: [1 2 3])
% 출력: Final_label - 각 데이터에 할당된 그룹
%       my_CP       - 각 그룹의 중심 좌표

% [0단계: 초기 객체 선정]
% 수업 때처럼 1~grp번째 데이터를 초기 중심좌표로 사용
my_CP = setdata(1:grp,:);

% [1단계: 객체 군집 배정]
my_label = [];
for kk=1:1:length(setdata)
    tmp_set = setdata(kk,:); % kk번째 데이터 가져오기

    % 각 중심좌표와 데이터 간의 유클리디안 거리를 계산
    udist = zeros(grp, 1);
    for jj=1:1:grp
        udist(jj,1) = norm(tmp_set - my_CP(jj,:));
    end

    % 거리가 가장 짧은 중심좌표의 그룹으로 할당
    [sv, si] = sort(udist, 'ascend');
    my_label(kk,1) = class(si(1));
end

% [2, 3단계 반복: 군집 중심좌표 산출 -> 재배정 -> 수렴 조건 점검]
% 몇 번 반복해야 할지 모르니까 while문 사용
Final_label = [];
chk = 1;
loop = 0;
while(chk)
    loop = loop + 1;

    % 각 그룹에 할당된 데이터의 평균으로 중심좌표 다시 계산
    for kk=1:1:grp
        idx = find(my_label == class(kk));
        tmp_data = setdata(idx,:);
        my_CP(kk,:) = mean(tmp_data);
    end

    % 새로운 중심좌표로 데이터 재할당
    my_label_new = [];
    for kk=1:1:length(setdata)
        tmp_set = setdata(kk,:);

        udist = zeros(grp, 1);
        for jj=1:1:grp
            udist(jj,1) = norm(tmp_set - my_CP(jj,:));
        end

        [sv, si] = sort(udist, 'ascend');
        my_label_new(kk,1) = class(si(1));
    end

    % 이전 할당 결과와 같으면 종료, 다르면 반복
    idx = find(my_label_new ~= my_label);
    if length(idx) == 0
        chk = 0;
        Final_label = my_label_new;
    else
        my_label = my_label_new;
    end
end

end
