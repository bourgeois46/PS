#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

struct Student {
    int id;
    int english;
    int math;
    int korean;
};
/*void swap(struct Student* a, struct Student* b) {
    struct Student tmp = *a;
    *a = *b;
    *b = tmp;
}*/
int partition(struct Student* A, int p, int r, int m) {
    int i, j, t;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (m == 1) {
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
        if (m == 2) {
            if (A[j].math < A[r].math) {
                i++;
               
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
        if (m == 3) {
            if (A[j].english < A[r].english) {
                i++;

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
        if (m == 4) {
            if (A[j].id < A[r].id) {
                i++;

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

void quickSort(struct Student* A, int p, int r, int m) {
    if (p < r) {
        int q = partition(A, p, r, m);
        quickSort(A, p, q - 1, m);
        quickSort(A, q + 1, r, m);
    }
}

void print(struct Student* A, int n) {
    for (int i = 0; i < n; i++)
        printf("학번 : %d\t영어 : %d\t 수학 : %d\t 국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);

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
        A[i].english = rand() % 101;
        A[i].math = rand() % 101;
        A[i].korean = rand() % 101;
    }

    print(A, n);

    while (1) {
        printf("정렬 기준 선택<1:국어, 2:수학, 3:영어, 4:id<오름차순>, 0:끝내기>: ");
        scanf("%d", &m);

        if (m == 0)
            break;

        quickSort(A, 0, n-1, m);
        print(A, n);
    }

    free(A);
    return 0;
}
