#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_array(int* A, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
}

void print_array(int* A, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int* A, int i, int j) {
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

int partition(int* A, int p, int r) {
    int i = p - 1;
    int j = p; // j는 p~ r-1 순환
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

void quickSort(int* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
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

    init_array(A, n);
    print_array(A, n); // 정렬 전

    quickSort(A, 0, n - 1);

    print_array(A, n); // 정렬 후

    free(A);
    return 0;
}
