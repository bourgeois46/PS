#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> /

struct Student {
    int id, korean, math, english;
};

int partition(struct Student* A, int p, int r) {
    int i, j, t;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (A[j].korean < A[r].korean) {
            i++;
            //다른 과목, 학점도 같이 이동
            t = A[i].id;
            A[i].id = A[j].id;
            A[j].id = t;

            t = A[i].korean;
            A[i].korean = A[j].korean;
            A[j].korean = t;

            t = A[i].english;
            A[i].english = A[j].english;
            A[j].english = t;

            t = A[i].math;
            A[i].math = A[j].math;
            A[j].math = t;
        }
    }

    i++;

    t = A[i].id;
    A[i].id = A[r].id;
    A[r].id = t;

    t = A[i].korean;
    A[i].korean = A[r].korean;
    A[r].korean = t;

    t = A[i].english;
    A[i].english = A[j].english;
    A[j].english = t;

    t = A[i].math;
    A[i].math = A[r].math;
    A[r].math = t;

    return i;
}

void quickSortDescendingByKorean(struct Student* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSortDescendingByKorean(A, p, q - 1);
        quickSortDescendingByKorean(A, q + 1, r);
    }
}

int main() {
    int n, i;
    struct Student* A;//구조체 배열

    scanf("%d", &n);

    A = (struct Student*)malloc(sizeof(struct Student) * n);//구조체 배열 동적할당

    //srand(time(NULL));
    for (i = 0; i < n; i++) {
        A[i].id = i + 1;
        A[i].math = rand() % 101;
        A[i].english = rand() % 101;
        A[i].korean = rand() % 101;
    }

    for (i = 0; i < n; i++) {//정렬 전
        printf("%d\t%d\t%d\t%d\n", A[i].id,
            A[i].korean, A[i].english, A[i].math);
    }
    printf("------------------------------\n");

    quickSortDescendingByKorean(A, 0, n-1);

    for (i = 0; i < n; i++) {//정렬 후
        printf("%d\t%d\t%d\t%d\n", A[i].id,
            A[i].korean, A[i].english, A[i].math);
    }

    free(A);

    return 0;
}
