#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

void insertionSort(int* A, int n) {
    int i, j,tmp, k;

    for (i = 1; i < n; i++) {
        //A[i] 위치에 삽입됨
        for (j = 0; j < i; j++)
            if (A[i] > A[j])
                break;
        //j는 A[i]의 인덱스
        tmp = A[i];
        
        for (k = i; k > j; k--)
            A[k] = A[k - 1];
        //A[j+1] = A[j]

    //삽입
        A[j] = tmp;
    }
}

int main() {
    int n, i;
    int* A;

    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }

    A = (int*)malloc(sizeof(int) * n);
    if (A == NULL) {
        return 0;
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {//난수값 넣 & 정렬 전
        A[i] = rand() % 1000;
        printf("%d ", A[i]);
    }

    printf("\n");

    insertionSort(A, n);

    for (i = 0; i < n; i++)//정렬 후
        printf("%d ", A[i]);
    
    free(A);
    return 0;
}
