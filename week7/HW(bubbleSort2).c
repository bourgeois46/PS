#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

struct Student {
    int id;
    int math;
    int korean;
    int english;
};
/*void swap(struct Student* a, struct Student* b) {
    struct Student tmp = *a;
    *a = *b;
    *b = tmp;
}*/
void bubbleSort(struct Student* A, int n, int s) {
    int i, j;
    struct Student tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (s == 1)
                if (A[j].korean < A[j + 1].korean) {
                    tmp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = tmp;
                }

            if (s == 2)
                if (A[j].math < A[j + 1].math) {
                    tmp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = tmp;
                }

            if (s == 3)
                if (A[j].english < A[j + 1].english) {
                    tmp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = tmp;
                }
           
            if (s == 4)
                if (A[j].id > A[j + 1].id) {
                    tmp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = tmp;
                }
        }
    }
}

void print(struct Student* A, int n) {
    for (int i = 0; i < n; i++) 
        printf("학번 : %d\t영어 : %d\t 수학 : %d\t 국어 : %d\n", A[i].id, A[i].english, A[i].math,  A[i].korean);
    
    printf("\n");
}

int main() {
    int n, i, m;
    struct Student* A;

    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);

    A = (struct Student*)malloc(sizeof(struct Student) * n);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        A[i].id = i + 1;
        A[i].math = rand() % 101;
        A[i].english = rand() % 101;
        A[i].korean = rand() % 101;
    }

    print(A, n);

    while (1) {
        printf("정렬 기준 선택<1:국어, 2:수학, 3:영어, 4:id<오름차순>, 0:끝내기>: ");
        scanf("%d", &m);

        if (m == 0)
            break;

        bubbleSort(A, n, m);
        print(A, n);
    }

    free(A);
}
