#include <stdio.h>

/*
 * Lecture 03 p.6~12 : 이분검색 - 재귀 (Binary Search, Recursion)
 *
 * 문제  : 원소가 n개인 오름차순으로 정렬된 배열 S에 원소 x가 있는가?
 * 입력  : 정수 n(>0), 정렬된 정수 배열 S, 정수 x
 * 출력  : 원소 x가 위치한 index, 없을 경우 -1
 *
 * [분할정복 3단계 - p.7]
 *  1. 분할: 배열을 가운데 값 기준으로 왼쪽 또는 오른쪽 분할로 진행
 *  2. 정복: 분할된 배열에 x가 있는지 결정. 없으면 1.을 반복
 *  3. 취합: 분할된 배열에 x가 있으면 그 index가 전체 배열에 대한 답
 *
 * [의사코드 - p.8]
 * int binsearch(int low, int high)
 *     int mid
 *     if low > high, return -1
 *     mid <- floor( (low + high) / 2 )
 *     if x == S[mid], return mid
 *     else if x < S[mid],
 *         return binsearch(low, mid - 1)
 *     else
 *         return binsearch(mid + 1, high)
 *
 * Note (p.8): S, x, n 등은 함수 매개변수로 넘기지 않고 전역변수로 정의
 *
 * 요구사항 (p.12)
 *  - 키보드로부터 x를 입력 받아 index를 출력, 없으면 -1
 *  - 반드시 재귀(recursion) 방식 사용
 */


 /* 전역변수 - 함수에서 매개변수 없이 바로 사용 */
int S[16] = { 5, 10, 12, 13, 14, 18, 20, 25, 27, 30, 35, 40, 45, 47, 53, 61 };
int n = 16;
int x;

/* 이분검색 (재귀): 찾으면 index, 없으면 -1 반환 */
int binsearch(int low, int high) {
	int mid;

	if (low > high) {
		return -1;                       // 재귀 종료: 탐색 범위가 비었음
	}

	mid = (low + high) / 2;

	if (x == S[mid]) {
		return mid;                      // 취합: 찾은 index가 곧 답
	}
	else if (x < S[mid]) {
		return binsearch(low, mid - 1);  // 분할: 왼쪽 절반
	}
	else {
		return binsearch(mid + 1, high); // 분할: 오른쪽 절반
	}
}

int main() {
	int location;

	printf("배열 S: ");
	for (int i = 0; i < n; i++) printf("%d ", S[i]);
	printf("\n");

	printf("찾을 값 x: ");
	scanf("%d", &x);

	location = binsearch(0, n - 1);

	if (location == -1) {
		printf("%d 은(는) 배열에 없습니다. (-1)\n", x);
	}
	else {
		printf("%d 은(는) index %d 에 있습니다.\n", x, location);
	}

	return 0;
}

/*
 * [분석용 메모 - p.13~15]
 * 단위연산: x 와 S[mid] 의 비교
 * 입력크기: 배열의 원소 수 n (2의 거듭제곱 가정)
 * 최악의 경우: x가 배열의 어떤 원소보다 크거나 작을 때
 *
 * 재현식 (recurrence)
 *   W(n) = W(n/2) + 1
 *   W(1) = 1
 * 해답
 *   W(n) = log2 n + 1
 *   n이 2의 거듭제곱이 아니면 W(n) = floor(log2 n) + 1  ->  Θ(log2 n)
 *
 * 1.5 (while문) 와의 대응
 *   while (low <= high)   <->  if (low > high) return -1
 *   high = mid - 1        <->  return binsearch(low, mid - 1)
 *   low  = mid + 1        <->  return binsearch(mid + 1, high)
 */
