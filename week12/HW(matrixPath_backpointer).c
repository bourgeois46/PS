#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 0
#define LEFT 1
#define UP 2

#define NOT_AVAILABLE 0 
#define AVAILABLE 1 

int matrixPath(int** m, int r, int c, int i, int j, int** Memo, int** M1, int** bp) {
    
    if (M1[i][j] != NOT_AVAILABLE) // 계산 o -> 반환
        return Memo[i][j];
    M1[i][j] = AVAILABLE;

    if (i == 0 && j == 0) { // (0, 0)
        Memo[i][j] = m[i][j];
        return m[i][j];
    }
    
    else if (i == 0) { // 맨 위행 -> 왼쪽에서 옴
        Memo[i][j] = matrixPath(m, r, c, 0, j - 1, Memo, M1, bp) + m[i][j];
        bp[i][j] = LEFT;
        return Memo[i][j];
    }

    else if (j == 0) { // 맨 왼쪽행 -> 위에서 옴
        Memo[i][j] = matrixPath(m, r, c, i - 1, 0, Memo,  M1, bp) + m[i][j];
        bp[i][j] = UP;
        return Memo[i][j];
    }

    else { /// 안쪽
        int a, b;
        a = matrixPath(m, r, c, i - 1, j, Memo, M1, bp);
        b = matrixPath(m, r, c, i, j - 1, Memo, M1, bp);
        Memo[i][j] = ((a < b) ? a : b) + m[i][j];

        if (a < b)
            bp[i][j] = UP;
        else
            bp[i][j] = LEFT;

        return Memo[i][j];
    }
}

int main(void) {
    int** m, ** M, ** M1, ** bp; //M1은 메모 상태 나타냄
    int i, j, r, c;
    r = c = 4; // 4x4 matrix

    m = (int**)malloc(sizeof(int*) * r);
    M = (int**)malloc(sizeof(int*) * r);
    M1 = (int**)malloc(sizeof(int*) * r);
    bp = (int**)malloc(sizeof(int*) * r);

    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int) * c);
        M[i] = (int*)malloc(sizeof(int) * c);
        M1[i] = (int*)malloc(sizeof(int) * c);
        bp[i] = (int*)malloc(sizeof(int) * c);
    }

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]); // 행렬 원소 입력

            M1[i][j] = NOT_AVAILABLE; //메모 초기화
            bp[i][j] = DEFAULT; //메모 초기화
            // 이전 위치에서 현재 위치로 이동하는 방향 저장
        }

    printf("%d\n", matrixPath(m, r, c, 3, 3, M, M1, bp));
}
