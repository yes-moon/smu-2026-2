#include <stdio.h>

/*
 * Lecture 02 p.13~14 : 교환정렬 (Exchange Sort)
 *
 * [의사코드]
 * void exchangesort(int n, keytype S[])
 * {
 *     index i, j;
 *     for (i = 1; i <= n - 1; i++)
 *         for (j = i + 1; j <= n; j++)
 *             if (S[j] < S[i])
 *                 exchange S[i] and S[j];
 * }
 *
 * 주의: 의사코드는 인덱스가 1..n 이지만, C 배열은 0..n-1 이다.
 *       i = 0 .. n-2, j = i+1 .. n-1 로 바꿔서 작성할 것.
 */


/* 교환정렬 */
void ExchangeSort(int n, int S[]) {
	int temp;

	for (int i = 0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (S[i] > S[j]){
				temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
}

int main() {
	int S[10] = { 12, 7, 10, 5, 16, 8, 4, 9, 6, 2 };
	int n = 10;
	ExchangeSort(n,S);
	for (int idx=0; idx < n; idx++ ) printf("%d ", S[idx]);
	
}

/*
 * [분석용 메모 - p.14]
 * 단위연산: S[j] 와 S[i] 의 비교
 * 입력크기: 정렬할 원소의 수 n
 * 비교 횟수: (n-1) + (n-2) + ... + 1 = n(n-1)/2
 *  → 시간복잡도 T(n) = n(n-1)/2
 */
