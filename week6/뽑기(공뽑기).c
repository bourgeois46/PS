#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

void pick(char* balls, int n, int* picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
            printf("%c ", balls[picked[i]]);//최종 출력은 아이템에 넣기
        printf("\n");
        return;
    }// printf("%d ", picked[i]);//먼저 인덱스 확인하기

    lastIndex = m - toPick - 1;

    if (toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(balls, n, picked, m, toPick - 1);
    }
}

int main() {
    char balls[] = "ABCDEFGH";//문자열
    int picked[3];

    pick(balls, 8, picked, 3, 3);
}
