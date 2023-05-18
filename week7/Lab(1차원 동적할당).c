#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int n, i;
	int* A;//배열처럼 사용

	srand(time(NULL));//디버깅할때 시드 고정//srand(303);

	scanf("%d", &n);

	if (input_number <= 0)
		return 0; 

	A = (int*)malloc(sizeof(int) * n);

	/*if (p = NULL)
		return 0;*/

	for (i = 0; i < n; i++) {//난수값 넣어주고 출력
		A[i] = rand()%1000;//rand()
		printf("%d ", A[i]);
	}

	free(A);
}
