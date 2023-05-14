#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int *A, int n) {//배열, 배열 크기
	int i, j, temp;

	for (i = 0; i < n-1 ; i++) {
		int max_idx = 0;
		//max 제외
		for (j = 1; j < n - i; j++) 
			//max 2번째 값부터 비교할 거라서 j = 1 부터
			if (A[max_idx] < A[j]) 
				max_idx = j;

		//A[max_id] <-> A[n-1-i]/swap
		temp = A[max_idx];
		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = temp;
	}
}
int main() {
	int n, i;
	int* A;

	srand(time(NULL));

	scanf("%d", &n);

	if (input_number <= 0)
		return 0; 

	A = (int*)malloc(sizeof(int) * n);

	if (p = NULL)
		return 0;

	for (i = 0; i < n; i++) {//정렬 전
		A[i] = rand() % 1000;//난수값 넣고 출력
		printf("%d ", A[i]);
	}

	selectionSort(A, n);

	printf("\n");
	for (i = 0; i < n; i++) {//정렬 후
		printf("%d ", A[i]);
	}

	free(A);
}
