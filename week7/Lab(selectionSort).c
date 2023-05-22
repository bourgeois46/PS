#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 각 루프마다 최대 원소 찾고, 최대 원소와 맨 오른쪽 원소를 교환한다. 처음에 첫번째 원소를 max로 설정한다. 범위에서 맨 오른쪽 원소를 제외한다.
이를 원소가 하나만 남을 때까지 반복 -> n-1 회*/

void selectionSort(int *A, int n) {
	int i, j, temp;

	for (i = 0; i < n-1 ; i++) {
		int max_idx = 0;
		//max 제외
		for (j = 1; j < n - i; j++) 
			//max 2번째 값부터 비교,  j = 1 부터
			if (A[max_idx] < A[j])//내림차순
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

	if (n <= 0)
		return 0; 

	A = (int*)malloc(sizeof(int) * n);

	if (A = NULL)
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
