#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* A, int n) {
	int i, j, temp;
	
	/*i = 0 n-1 회 버블
	* i = 1 n-2 회 버블
	* i = 2 n-3 회 버블
	*/
	
	for (i = 0; i < n-1; i++) // 총 n-1 회 버블
		for (j = 0; j <= n-i-1; j++) // 범위 1씩 감소
			if (A[j] > A[j + 1]) { 
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}

}

int main() {
	int n, i;
	int* A;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	A = (int*)malloc(sizeof(int) * n);

	if (n = NULL)
		return 0;

	srand(time(NULL));
	for (i = 0; i < n; i++) {//정렬 전
		A[i] = rand() % 1000;
		printf("%d ", A[i]);
	}

	bubbleSort(A, n);

	printf("\n");
	for (i = 0; i < n; i++) {//정렬 후
		printf("%d ", A[i]);
	}

	free(A);
}
