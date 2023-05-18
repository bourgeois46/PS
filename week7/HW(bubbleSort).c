#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

struct Student {
    int id, math, korean,  english;
};

void bubbleSort(struct Student* A, int n) {
    int i, j;
    struct Student tmp;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++) //내림차순
            if (A[j].korean < A[j + 1].korean) {//국어 점수를 기준으로 
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
}

int main() {
    int n, i;
    struct Student* A;//구조체 배열

    scanf("%d", &n);

    A = (struct Student*)malloc(sizeof(struct Student) * n);//구조체 배열 동적할당

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        A[i].id = i + 1;//학번은 그냥 증가
        A[i].math = rand() % 101;
        A[i].english = rand() % 101;
        A[i].korean = rand() % 101;
    }

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", A[i].id,
            A[i].korean, A[i].english, A[i].math);
    }
    printf("-----------------\n");

    bubbleSort(A, n);

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", A[i].id,
            A[i].korean, A[i].english, A[i].math);
    }

    free(A);
    return 0;
}
