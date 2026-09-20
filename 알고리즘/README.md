# 알고리즘

강의 의사코드를 C로 직접 구현하며 알고리즘을 익히는 과목.

환경: C, Visual Studio

## 구현 목록

`C practice/exercise 1.1 Sequentail Search/`

| 파일 | 알고리즘 | 출처 | 상태 |
|---|---|---|---|
| `1.1 Sequential Search.c` | 순차 탐색 | Lecture 02 | 함수 완성, main 작성 중 |
| `1.2.c` | 배열 합 | Lecture 02 | 작성 중 |
| `1.3 Exchange Sort.c` | 교환 정렬 | Lecture 02 p.13~14 | 완성 |
| `1.4 Matrix Multiplication.c` | 행렬 곱셈 (n×n) | Lecture 02 p.15~18 | 완성 |
| `1.5 Binary Search.c` | 이분 검색 | Lecture 02 p.21~22 | 완성 |

## 배운 것

- 의사코드는 인덱스가 `1..n` 이지만 C 배열은 `0..n-1` — `i = 0..n-2`, `j = i+1..n-1` 로 바꿔서 작성
- 이진 탐색은 `mid ± 1` 로 범위를 좁혀야 무한루프에 빠지지 않는다
