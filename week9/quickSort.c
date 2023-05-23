#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 마지막 원소를 pivot으로 지정 A[r]

int partition(int* A, int p, int r) {
    int i, j;
    int t;

    i = p - 1; // 요소 교환을 위한 임시 변수 // 제일 왼쪽 원소 -1

    for (j = p; j < r; j++) { // 배열을 순회하기 위한 인덱스 
        if (A[j] < A[r]) {
            i++; // 배열에서 pivot 보다 작은 개수
            
          // A[i] <-> A[j] 
          // A[i]가 pivot 보다 작으면 i 범위 증가 -> pivot 보다 작은 값이 i 왼쪽에 위치하도록
          
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

  // 반복문 끝나고 피봇 <-> A[i] // 기준값을 정확한 위치로
  
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i; // pivot의 위치 반환
}

void quickSort(int* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // pivot 먼저 구하기
        quickSort(A, p, q - 1); // pivot 기준 왼쪽 정렬
        quickSort(A, q + 1, r); // pivot 기준 오른쪽 정렬
    }
}

int main() {
    int* A;
    int i, n;

    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    A = (int*)malloc(sizeof(int) * n);

    if (A == NULL)
         return 0;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 100;

    for (i = 0; i < n; i++)//정렬 전
        printf("%d ", A[i]);
    printf("\n");

    quickSort(A, 0, n - 1);

    for (i = 0; i < n; i++)//정렬 후
        printf("%d ", A[i]);
    printf("\n");

    free(A);

    return 0;
}
