#include <stdio.h>

/*
 * Lecture 02 p.21~22 : 이분검색 (Binary Search)
 *
 * 문제  : 원소가 n개인 오름차순으로 정렬된 배열 S에 원소 x가 있는가?
 * 입력  : 정수 n(>0), 정렬된 정수 배열 S, 정수 x
 * 출력  : 원소 x가 위치한 index, 없을 경우 -1
 *
 * [의사코드 - p.21]
 * algorithm binarysearch is
 * input : sorted array S with length n, a key x to search for
 * output: location of x in S if x in S, -1 if x not in S
 *
 *     location <- -1, low <- 0, high <- n-1
 *     while low <= high and location == -1
 *         mid <- floor( (low + high) / 2 )
 *         if      x == S[mid]  then location <- mid
 *         else if x <  S[mid]  then high <- mid - 1
 *         else                      low  <- mid + 1
 *     return location
 *
 * 요구사항 (p.22)
 *  - 키보드로부터 x를 입력 받아 index를 출력
 *  - binsearch() 함수와 main() 함수를 분리해서 작성
 */


 /* 이분검색: 찾으면 index, 없으면 -1 반환 */
int binsearch(int n, int S[], int x) {
	// TODO: location = -1, low = 0, high = n - 1 로 초기화
	//       while (low <= high && location == -1)
	//           mid = (low + high) / 2;          // 정수 나눗셈이 곧 floor
	//           x == S[mid] 이면 location = mid
	//           x <  S[mid] 이면 high = mid - 1
	//           그 외          low  = mid + 1
	//       return location

}

int main() {
	int S[10] = { 2, 4, 5, 6, 7, 8, 9, 10, 12, 16 };
	int n = 10;
	int x;
	int location;

	printf("배열 S: ");
	for (int i = 0; i < n; i++) printf("%d ", S[i]);
	printf("\n");

	printf("찾을 값 x: ");
	scanf("%d", &x);

	location = binsearch(n, S, x);

	if (location == -1) {
		printf("%d 은(는) 배열에 없습니다. (-1)\n", x);
	}
	else {
		printf("%d 은(는) index %d 에 있습니다.\n", x, location);
	}

	return 0;
}

/*
 * [분석용 메모 - p.22 Q]
 * 단위연산: x 와 S[mid] 의 비교
 * 입력크기: 배열의 원소 수 n
 *
 * 한 번 비교할 때마다 탐색 범위가 절반으로 줄어든다.
 *  - 최선: 1회   (첫 mid 에서 바로 찾는 경우)
 *  - 최악: floor(log2 n) + 1 회   → n = 10 이면 4회
 *  - 평균: 약 log2 n 회
 *
 * → 시간복잡도 T(n) = log2 n
 *   (순차검색의 n 회와 비교해볼 것: n=10 이면 10회 vs 4회,
 *    n=1000 이면 1000회 vs 10회로 차이가 급격히 벌어진다)
 */
