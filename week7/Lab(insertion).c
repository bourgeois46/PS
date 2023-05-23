#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

// 삽입 위치 찾기 & 삽입 위치 이후로 다 뒤로 한칸씩 이동
// 첫 번째 원소는 정렬되었다고 가정

void insertionSort(int* A, int n) {
    int i, j,tmp, k;

    for (i = 1; i < n; i++) { // 첫 번째 원소 정렬되었으므로 제외하고 시작
        //A[j] 위치에 삽입됨
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
