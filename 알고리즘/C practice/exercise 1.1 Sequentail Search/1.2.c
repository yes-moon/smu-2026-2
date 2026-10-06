#include <stdio.h>

int sequencesum(int n, int S[]){
	int result = 0;
	for(int i=0; i < n; i++){
		result = result + S[i];

	}
	return result;
}

int main(){
	int n = 10;
	int S[10] = {12, 7, 10, 5, 16, 8, 4, 9, 6, 2};
	int result = sequencesum(n,S);

	printf("sum result is %d\n", result);
	return 0;

}