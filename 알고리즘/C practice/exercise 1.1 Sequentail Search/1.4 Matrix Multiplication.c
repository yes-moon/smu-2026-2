#include <stdio.h>

#define n 3

/*
 * Lecture 02 p.15~18 : 행렬곱셈 (Matrix Multiplication)
 *
 * 문제  : 두 n x n 행렬의 곱을 구하시오.
 * 입력  : 정수 n(>0), n x n 2차원 배열 A, B
 * 출력  : A와 B의 행렬곱 2차원 배열 C
 *
 * [의사코드 - p.17]
 * algorithm matrixmult is
 * input : n×n array A, B, C
 * output: C as a matrix multiplication of A and B
 *
 *     for i = 0 to n-1
 *         for j = 0 to n-1
 *             C[i][j] <- 0
 *             for k = 0 to n-1
 *                 C[i][j] <- C[i][j] + A[i][k] × B[k][j]
 *     return C
 *
 * 요구사항 (p.18)
 *  - matrixmult() 함수와 main() 함수를 분리해서 작성
 *  - print_matrix() 함수로 행렬을 2차원 모양에 맞게 출력
 */


 /* 행렬곱 C = A x B */
void matrixmult(int A[n][n], int B[n][n], int C[n][n]) {

	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			C[i][j] = 0;
			for (int k = 0; k <= n - 1; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
}

/* 행렬을 2차원 모양으로 출력 */
void print_matrix(int M[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", M[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int A[3][3] = {
		{ 2,  5,  1 },
		{ 0, -1,  3 },
		{ 7,  2,  8 }
	};
	int B[3][3] = {
		{ 0,  1,  1 },
		{ 1,  0, -1 },
		{ 0,  0,  1 }
	};
	int C[3][3];

	matrixmult(A, B, C);

	printf("\n행렬곱 C = A x B:\n");
	print_matrix(C);

	return 0;
}

/*
 * [분석용 메모]
 * 단위연산: 곱셈 A[i][k] × B[k][j]  (덧셈도 같은 횟수만큼 일어남)
 * 입력크기: 행렬의 한 변의 길이 n
 * 곱셈 횟수: 3중 for 문이므로 n × n × n
 *  → 시간복잡도 T(n) = n^3
 */
