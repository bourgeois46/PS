#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//중복순열
#include <stdlib.h>
#include <limits.h>


void pick(char* signs, int n, int* picked, int m, int toPick, int*A, int N, int*max) {
    //정수배열, 정수배열의 크기, 최대값
    int lastIndex, i, sum;
  
    if (toPick == 0) {//수식들을 다 뽑았으면
        sum = 0;
        //item[bucket[[0]] == '*' -> return//호출할때보다 느림

        for (i = 0; i < m; i++) {

            if (picked[i] == 0) //signs[picked] == '+'//인덱스 or 값
                sum += A[i];
            
            else  if (picked[i] == 1)
                sum -= A[i];
            
            else 
                sum *= A[i];

        }
        if (sum > *max)//max[0]로 쓸 수 있다
            *max = sum;

        return;
    }

    lastIndex = m - toPick - 1;

    for (i = 0; i < n; i++) {//smallest = 0
        if (m == toPick && i == 2) continue;
        //첫번째 뽑을 때, *를 뽑으면 넘어가라
        //continue는 아래 코드를 수행하지 않고 다음 루프로 

        picked[lastIndex + 1] = i;
        pick(signs, n, picked, m, toPick - 1, A, N, max);
    }
}

int main() {
	char sign[] = "+-x";//이걸 뽑는 것
	int* A;//정수 배열
	int N;//정수 배열의 크기 
    int* picked;//연산자를 뽑아서 넣는 버킷
    int max = 0;

	scanf("%d", &N);//정수배열의 크기

    //정수배열의 크기 = picked의 크기/숫자 개수 = 연산자 개수
    A = (int*)malloc(sizeof(int) * N);
	picked = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) //정수 배열 값 입력
        scanf("%d", &A[i]);
	
    pick(sign, 3, picked, N, N, A, N, &max);

    printf("%d", max);

	free(A);
    free(picked);
}
