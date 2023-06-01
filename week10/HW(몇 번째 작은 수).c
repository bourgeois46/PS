#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_array(int *A, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		A[i] = rand() % 100;
}

void print_array(int* A, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}

void swap(int *A, int i, int j) {
	int temp = A[j];
	A[j] = A[i];
	A[i] = temp;
}

int partition(int* A, int p, int r) { //퀵 정렬의 partition
	int i = p - 1;
	int j = p;
	int pivot = A[r];

	while (j < r) {
		if (A[j] < pivot) {
			swap(A, ++i, j);
		}
		j++;
	}
	swap(A, ++i, j);

	return i;
}

/* ++i 사용되는 이유
A[i]는 현재까지 작은 값들이 위치한 부분을 가리키고, A[j]는 아직 정렬되지 않은 값들을 순회하며 검사하기 위해 사용됨. 
A[j]가 pivot보다 작을 경우, A[i]의 위치를 증가시키고 A[i]와 A[j]의 값을 교환하여 작은 값들을 앞쪽으로 모음.
i의 값을 먼저 증가시킨 후에 swap 함수에 전달되므로 A[i]와 A[j]의 위치를 올바르게 교환할 수 있음. */

int find (int *A, int p, int r, int orderIndex) {
	if (p <= r) {
		int q = partition(A, p, r);

		if (orderIndex == q)
			return A[orderIndex]; // 찾으면 그 수 반환

		else if (orderIndex < q) // 찾고자 하는 수의 인덱스가 partition보다 작으면 왼쪽에서 찾기
			find(A, p, q - 1, orderIndex);

		else
			find(A, q + 1, r, orderIndex); // 크면 오른쪽에서 찾기
	}
}

int main(void) {
	int n, k;
	int* A;

	printf("Enter the number of numbers: ");
	scanf("%d", &n);

	printf("몇번째로 작은 수: ");
	scanf("%d", &k);

	A = (int*)malloc(sizeof(int) * n);

	init_array(A, n);
	print_array(A, n);

	int order_num = find(A, 0, n - 1, k - 1);
	printf("\n%d번째 작은 수는 : %d\n", k, order_num);

	free(A);
	return 0;
}
