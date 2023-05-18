#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void pick(char* signs, int n, int* picked, int m, int toPick) {
    int lastIndex, i, sum = 0;
    //입력 2라고 가정
    //인덱스를 이용해서! picked[0] -> '+' picked[1] -> '-'
     //i+1 -> 입력 2일 때 1, 2이므로(인덱스+1)

    if (toPick == 0) {
        for (i = 0; i < m; i++) {
            // printf("%d", picked[i]);
            if (picked[i] == 0) {
                printf("+ %d ", i + 1);//출력되는 연속되어있는수
                //기존에 쓰이고 있던 i를 이용한 것
                //1부터 연속적으로 출력되도록!

                sum += (i + 1);
            }
            else {// if (picked[i] == 1)
                printf("- %d ", i + 1);
                sum -= (i + 1);
            }
        }
        printf(" = %d\n", sum);//위치*
        return;
    }

    lastIndex = m - toPick - 1;

    for (i = 0; i < n; i++) {//smallest = 0
        picked[lastIndex + 1] = i;
        pick(signs, n, picked, m, toPick - 1);
    }
}
    
int main() {
    char signs[] = "+-";//ball처럼 *안씀//배우 문제처럼 문자열 아님
    int *picked, m;

    scanf("%d", &m);
    picked = (int*)malloc(sizeof(int) * m);

    pick(signs, 2, picked, m, m);

    free(picked);
}
