#include <stdio.h>

/*
 * Lecture 03 p.16~42 : 합병정렬 (Mergesort)
 *
 * 문제  : n개의 원소를 오름차순으로 정렬
 * 입력  : 정수 배열 S, index low, index high
 * 출력  : 오름차순으로 정렬된 배열 S
 *
 * [분할정복 3단계 - p.16]
 *  1. 분할: 배열을 반으로 분할한다
 *  2. 정복: 분할된 배열들을 각자 따로 정렬한다 (더 쪼갤 수 있으면 재귀호출)
 *  3. 취합: 정렬된 분할들을 합병(merge)하여 전체 정렬된 배열을 구한다
 *
 * [의사코드 - p.21 mergesort]
 * void mergesort(int S[], int low, int high)
 *     int mid
 *     if low < high,
 *         mid <- floor( (low + high) / 2 )
 *         mergesort(S, low, mid)          // 왼쪽 절반
 *         mergesort(S, mid + 1, high)     // 오른쪽 절반
 *         merge(S, low, mid, high)        // 두 절반 합병
 *
 * [의사코드 - p.41 merge]
 * void merge(int S[], int low, int mid, int high)
 *     int i, j, k, m
 *     i <- low, j <- mid + 1, k <- low
 *     while (i <= mid && j <= high)
 *         if S[i] <= S[j], sorted[k++] <- S[i++]
 *         else,            sorted[k++] <- S[j++]
 *     while (i <= mid),  sorted[k++] <- S[i++]     // 왼쪽에 남은 것
 *     while (j <= high), sorted[k++] <- S[j++]     // 오른쪽에 남은 것
 *     for (m = low to high), S[m] <- sorted[m]     // 원본으로 복사
 *
 * Note (p.41, 42): 정렬 결과를 저장하는 배열 sorted[] 는 전역변수로 설정
 */


 /* 전역변수 */
int S[8] = { 27, 10, 12, 20, 25, 13, 15, 22 };
int n = 8;
int sorted[8];      // merge 결과를 임시로 담는 배열

/* 합병: S[low..mid] 와 S[mid+1..high] 가 각각 정렬돼 있다고 가정하고 하나로 합침 */
void merge(int S[], int low, int mid, int high) {
	int i, j, k, m;

	i = low;        // 왼쪽 구간 S[low..mid] 의 시작
	j = mid + 1;    // 오른쪽 구간 S[mid+1..high] 의 시작
	k = low;        // sorted[] 에 채워 넣을 위치

	// 양쪽 다 남아 있는 동안: 작은 쪽을 sorted 에 넣고 그쪽만 전진
	while (i <= mid && j <= high) {
		if (S[i] <= S[j]) {
			sorted[k++] = S[i++];
		}
		else {
			sorted[k++] = S[j++];
		}
	}

	// 한쪽이 먼저 끝나면 다른 쪽 남은 것을 그대로 붙임 (둘 중 하나만 실행됨)
	while (i <= mid)  sorted[k++] = S[i++];
	while (j <= high) sorted[k++] = S[j++];

	// sorted[low..high] 를 원본 S 로 복사
	for (m = low; m <= high; m++) {
		S[m] = sorted[m];
	}
}

/* 합병정렬 (재귀) */
void mergesort(int S[], int low, int high) {
	int mid;

	if (low < high) {                  // 원소가 2개 이상일 때만 (1개면 이미 정렬됨)
		mid = (low + high) / 2;
		mergesort(S, low, mid);        // 분할·정복: 왼쪽 절반
		mergesort(S, mid + 1, high);   // 분할·정복: 오른쪽 절반
		merge(S, low, mid, high);      // 취합
	}
}

int main() {
	printf("정렬 전: ");
	for (int i = 0; i < n; i++) printf("%d ", S[i]);
	printf("\n");

	mergesort(S, 0, n - 1);

	printf("정렬 후: ");
	for (int i = 0; i < n; i++) printf("%d ", S[i]);
	printf("\n");

	return 0;
}

/*
 * [손으로 따라가기 - p.17~20, p.22~38]
 * 27 10 12 20 25 13 15 22
 *   분할 -> 27 10 12 20 | 25 13 15 22
 *   분할 -> 27 10 | 12 20 | 25 13 | 15 22
 *   분할 -> 27 | 10 | 12 | 20 | 25 | 13 | 15 | 22   (원소 1개 = 이미 정렬됨, 종료)
 *   합병 -> 10 27 | 12 20 | 13 25 | 15 22
 *   합병 -> 10 12 20 27 | 13 15 22 25
 *   합병 -> 10 12 13 15 20 22 25 27
 *
 * 주의
 *  - sorted[k] 의 k 가 0 이 아니라 low 부터 시작하는 이유:
 *    구간 [low..high] 만 정렬해서 같은 위치에 다시 복사하기 때문
 *  - S[i] <= S[j] 의 '=' : 같은 값이면 왼쪽 것을 먼저 (안정 정렬)
 *  - mergesort 의 종료 조건은 if (low < high) — 원소가 1개면 아무것도 안 함
 */
