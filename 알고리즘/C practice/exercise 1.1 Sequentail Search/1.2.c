#include <stdio.h>

int SumArray(int n, int S[]){
	int result;
	for (int i = 0; i< n; i++){
		result = result + S[i];
	}

	return result;
}

int main() {
	int S[10] = { 12,7,10,5,16,8,4,9,6,2 };
	int n = 10;
	SumArray(n, S[10]);
	printf(result);
}