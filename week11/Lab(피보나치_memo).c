#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//version 1
int fib(int n, int* memo) {
    if (n == 1 || n == 2) // 피보나치 1, 2항은 1이니까 그대로 반환
        return 1;

    else { // memo 배열을 확인하여 현재 인덱스 n에 해당하는 값이 이미 계산되어 저장되어있는지 확인
        if (memo[n - 1] == 0) // 계산되지 않음
            memo[n - 1] = fib(n - 1, memo); // 이전 항의 값 계산 후 배열에 저장

        if (memo[n - 2] == 0)
            memo[n - 2] = fib(n - 2, memo);
    }

    /* 각각 else if로 하는 것과 차이 있음
    else if -> 각 조건이 독립적으로 평가되어 위 else if가 참이어도 아래 조건 평가
    else -> 위 조건이 참인 경우 아래 조건 넘어감    
    */

   // 위 else문에서 계산된 결과를 더한 값을 반환
    return memo[n - 1] + memo[n - 2]; // 현재 항의 값 계산
}

//version 2
int fib(int n, int* memo) {
    if (memo[n] != 0) // 이미 계산된 값이 저장되어있음
        return memo[n]; // 그 값 반환

    if (n == 1 || n == 2) 
        return 1;

    else { // memo[n] 계산
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }
}


int main() {
    int n, i;
    int* memo; // memorization을 저장할 배열

    printf("몇 번째까지의 피보나치 수열: ");
    scanf("%d", &n);

    memo = (int*)malloc(sizeof(int) * (n + 1)); //인덱스 + 1
    for (i = 0; i < n + 1; i++)
        memo[i] = 0;// 모든 요소 0으로 초기화 -> 한 번도 나오지 않았음을 의미

    printf("%d\n", fib(n, memo));

    free(memo);
    return 0;
}
