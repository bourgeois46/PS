#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 합병 정렬은 분할 + 정복

void merge(int* A, int p, int q, int r, int* temp) {
    int i, j, t;

    i = p; // 왼쪽 부분 배열의 시작 원소
    j = q + 1; // 오른쪽 부분 배열의 시작 원소
    t = p;

    while (i <= q && j <= r) { // i가 왼쪽 부분 배열의 끝에 도달하거나 j가 오른쪽 부분 배열의 끝에 도달할 때까지
        if (A[i] < A[j]) // 더 작은 원소를 임시 배열에 넣기
            temp[t++] = A[i++]; 
        else
            temp[t++] = A[j++];
    }

    while (i <= q) //j > r // i가 왼쪽 부분 배열의 끝에 도달한 경우 나머지 요소 복사
        temp[t++] = A[i++];

    while (j <= r) // i가 오른쪽 부분 배열의 끝에 도달한 경우 나머지 요소 복사
        temp[t++] = A[j++];

    for (i = p; i <= r; i++) // 임시 배열의 값을 원래의 배열에 복사
        A[i] = temp[i];
}

void mergeSort(int* A, int p, int r, int* temp) {
    if (p < r) { // 원소가 하나만 남을 때까지 
        int q = (p + r) / 2;      
        mergeSort(A, p, q, temp); // 왼쪽 분할 -> 원소 하나만 남을 때까지 다 떨어뜨림
        mergeSort(A, q + 1, r, temp); // 오른쪽 분할 -> 원소 하나만 남을 때까지 다 떨어뜨림
        merge(A, p, q, r, temp); // 정복
    }
}

int main() {
	int* A;
	int i, n;
        int* temp;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);
       temp = (int*)malloc(sizeof(int) * n);

       srand(time(NULL));
       for (i = 0; i < n; i++) {//정렬 전
           A[i] = rand() % 100;
           printf("%d ", A[i]);
    }
       mergeSort(A, 0, n-1, temp);

       printf("\n");
       for (i = 0; i < n; i++)//정렬 후
           printf("%d ", A[i]);
       printf("\n");

       free(A);
       free(temp);

	return 0;
}
