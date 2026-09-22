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
| `1.5 Binary Search.c` | 이분 검색 (while) | Lecture 02 p.21~22 | `binsearch()` 작성 중 |
| `2.1 Binary Search Recursive.c` | 이분 검색 (재귀) | Lecture 03 p.6~12 | 완성 |
| `2.2 Mergesort.c` | 합병 정렬 | Lecture 03 p.16~42 | 완성 |

## 배운 것

- 의사코드는 인덱스가 `1..n` 이지만 C 배열은 `0..n-1` — `i = 0..n-2`, `j = i+1..n-1` 로 바꿔서 작성
- 이진 탐색은 `mid ± 1` 로 범위를 좁혀야 무한루프에 빠지지 않는다
- 재귀 이분검색은 종료 조건 `if (low > high) return -1` 이 `mid` 계산보다 먼저 와야 하고, 재귀 호출 앞에 `return` 을 빼면 찾은 값이 위로 안 올라온다
- Lecture 03부터는 교수님 방식대로 `S`, `x`, `n`, `sorted[]` 를 전역변수로 두고 함수는 `low`, `high` 만 받는다
- `merge()` 의 `k` 는 0이 아니라 `low` 부터 — 구간 `[low..high]` 만 정렬해서 같은 자리에 복사하기 때문
- MSVC는 C99 가변길이배열(VLA)을 지원하지 않아 `int A[n][n]` 매개변수는 `#define n 3` 같은 매크로 상수여야 한다
