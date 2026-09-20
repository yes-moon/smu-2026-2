#include <stdio.h>

int SequentialSearch(int x,int S[], int n ) {

	int location = 0; // locaton은 index 표현인 i와 동일
	while (location < n && S[location] != x) {
		location++;
	}
	if (location >= n) location = -1;
	return location;
}

int main() {
	int S[10] = { 12,7,10,5,16,8,4,9,6,2 };
	int n = 10;
	int x;
	
	printf("input number: ");
	scanf(%d,)
	SequentialSearch()
}
