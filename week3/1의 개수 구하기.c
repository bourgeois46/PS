//A의 배수 중 모든 자리의 수가 1인 숫자들 중 가장 작은 수 -> C
//A를 입력받아 C에 1이 몇 개 있는지 출력
//1. C구하기 2. C에 1이 몇개 있는지 구하기

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int generate_ones(int k) {//모든 자리수가 1인 수 반환
    int ret = 0;
    int i;

    for (i = 0; i < k; i++)//i 시작 주소 0
        ret = ret * 10 + 1;//순환호출
    // 1 / 1
    // 2 / 11
    // 3 / 111
    // 4 / 1111
    
    return ret;
}

int main(void) {
    int numOfones = 0;//C :모든 자리 수가 1인 수
    int num;//A
    int i = 1;//초기화 1로

    scanf("%d", &num);

    while (1) {
        numOfones = generate_ones(i);//C 발생/1~ break 전까지
      //i = 1의 개수 = main에서의 k

        //C는 A의 배수 중 가장 작은 수
        //C % A == 0 이면 가장 작은 배수 찾음
        if (numOfones % num == 0) {
            break;
        }
        i++;
    }

    printf("%d\n", i);//가장 작은 수 찾았을 때 횟수 == 1의 개수
}
