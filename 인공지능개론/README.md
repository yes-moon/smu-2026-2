# 인공지능개론

기계학습의 기초를 MATLAB으로 실습하는 과목. 주교재는 『단단한 머신러닝』(조우쯔화).

환경: MATLAB R2025b + Statistics and Machine Learning Toolbox

## 2주차 — MATLAB 기초, 선형 모델

| 파일 | 내용 |
|---|---|
| `practice1.m` | 행렬 인덱싱, `zeros`/`ones`/`length`, `plot`/`stem`/`bar`/`subplot`, `find` |
| `HW1.m` | 키→몸무게 선형 모델 `Weight = 0.2·Height + 30` 을 행렬곱 `W = H·t` 로 표현하고 `Weight - H·t = 0` 으로 검증 |

핵심: 기계학습 모델 `f(x) = w·x + b` 는 결국 **기울기(w)와 절편(b)을 정하는 것**이고, 이를 행렬로 쓰면 `H·t` 한 줄이 된다.

## 3주차 — 유사성 기반: k-Nearest Neighbor

Iris 데이터셋(150개, 4특징, 3종)으로 kNN 분류.

| 파일 | 내용 |
|---|---|
| `ex1_dataload_visualization.m` | `load fisheriris`, 종별 산점도(sepal / petal), 문자열 라벨 → 숫자 변환, 학습 60 / 평가 40 분리 |
| `ex2_knn_using_matlab.m` | `fitcknn` + `predict` (k=3, 유클리디안). sepal 2특징·2종(versicolor/virginica) → 정확도 60% |

배운 것:
- **특징 선택이 성능을 좌우한다.** sepal length/width만으로는 versicolor와 virginica가 겹쳐 60%에 그치지만, petal까지 4특징을 쓰면 98%로 올라간다.
- 학습에 쓴 데이터로 평가하면 안 된다 → 학습/평가 분리. 학습 데이터를 다시 학습/검증으로 나눠 과적합 방지.
- kNN은 학습이 없고(데이터를 저장할 뿐) 분류할 때마다 전체 거리를 계산 → 학습은 빠르고 분류는 느리다.
- k는 홀수로 시작(동점 방지). 3종 이상에서는 동점이 생기며 `fitcknn`의 `BreakTies` 옵션으로 처리.
- 거리: L1(맨해튼) vs L2(유클리디안). 어느 걸 쓰느냐에 따라 뽑히는 이웃이 달라진다.

직접 구현(반복문 + `sort` + `mode`)과 `fitcknn` 결과가 완전히 일치하는 것을 확인했다. 3종·4특징으로 확장한 버전과 `meshgrid`로 결정 경계를 그리는 실습은 수업 배포 코드라 저장소에는 없다.
