#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

void selectionSort_max_B(int* A, int* B, int N, int K) {//선택정렬
	//A의 K개 숫자를 B의 K개 숫자와 바궈서 B의 합을 최대로

	//A 내림 B 오름
	
	//A 선택정렬 5 4 3 2 1
	int i, j, max_idx, temp;

	for (i = 0; i < K; i++) {//K번만 수행
		max_idx = 0;

		for (j = 1; j < N - i; j++)
			if (A[max_idx] > A[j])//내림차순
				max_idx = j;

		temp = A[max_idx];
		A[max_idx] = A[N - i - 1];
		A[N - i - 1] = temp;
	}

	/*for (i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");*/

	//B 선택정렬  1 2 3 4 50
	for (i = 0; i < K; i++) {
		max_idx = 0;

		for (j = 1; j < N - i; j++)
			if (B[max_idx] < B[j])//오름차순
				max_idx = j;

		temp = B[max_idx];
		B[max_idx] = B[N - i - 1];
		B[N - i - 1] = temp;
	}

	/*for (i = 0; i < N; i++)
		printf("%d ", B[i]);*/

	int p = 0;

	for (i = 0; i < K; i++) {//앞에서부터 바꿔
		p = A[i];
		A[i] = B[i];
		B[i] = p;
	}


	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += B[i];

	printf("%d", sum);

	return;

}
int main() {
	int* A;
	int* B;
	int N;//정수 배열 크기
	int K;//바꾸어야 할 숫자의 개수

	scanf("%d", &N);
	scanf("%d", &K);

	A = (int*)malloc(sizeof(int) * N);
	B = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	selectionSort_max_B(A, B, N, K);

	//바뀐 배열B의 숫자 합 출력

	free(A);
	free(B);
}
