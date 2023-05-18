#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define X_VALUE 5 //행
#define Y_VALUE 5 //열
void readBombInfo(char grid[][Y_VALUE + 1]);
void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]);
void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]);

int main(void) {
    char grid[X_VALUE][Y_VALUE + 1]; //문자열의 경우 마지막에 NULL이 들어가야 -> 5X5 배열이 아닌 5X6 배열이 되어야 함
    int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; //지뢰의 개수를 넣는 정수형 5X5 배열
    readBombInfo(grid);
    countBomb(grid, numOfBombs);
    display_numOfBombs(grid, numOfBombs);
}

void readBombInfo(char grid[][Y_VALUE + 1]) {
    int i;
    // grid 및 지뢰 정보 입력 
    for (i = 0; i < X_VALUE; i++)
        scanf("%s", grid[i]);
}

void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]) {
    int i, j;

    for (i = 0; i < X_VALUE; i++)
        for (j = 0; j < Y_VALUE; j++)
            if (grid[i][j] == '*') 
            {
                //위
                if (i - 1 >= 0) {
                    numOfBombs[i - 1][j]++;
                    if (j - 1 >= 0)
                        numOfBombs[i - 1][j - 1]++;
                    if (j + 1 < Y_VALUE)
                        numOfBombs[i - 1][j + 1]++;
                }

                //아래 
                if (i + 1 < X_VALUE) {
                    numOfBombs[i + 1][j]++;
                    if (j - 1 >= 0)
                        numOfBombs[i + 1][j - 1]++;
                    if (j + 1 < Y_VALUE)
                        numOfBombs[i + 1][j + 1]++;
                }

                //좌
                if (j - 1 >= 0)
                    numOfBombs[i][j - 1]++;
                //우
                if (j + 1 < Y_VALUE)
                    numOfBombs[i][j + 1]++;
            }
}

void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]) {
    int i, j;

    for (i = 0; i < X_VALUE; i++) {
        for (j = 0; j < Y_VALUE; j++)
            if (grid[i][j] == '*')
                printf("*");
            else
                printf("%d", numOfBombs[i][j]);
        printf("\n");
    }
}
