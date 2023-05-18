//palindrome에 도달하는 데 몇 번의 뒤집기+더하기 반복
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int reverse_number(int n) {//뒤집은 수 반환
    int ret = 0;
    int remainder = 0;
  
    while (n > 0) {//n != 0 
        ret = ret * 10 + n % 10;//이전의 나머지*10에 나머지 더하기
      //*10 -> 자릿수 왼쪽으로 가게 하기 위해
      
        /*remainder = n % 10;
        ret = ret * 10;
        ret = ret + remainder;*/
      
        n = n / 10;//입력값의 일의 자리 없애기
    }
  //순환 -> 몫을 다시 넣어줌

    return ret;
}

int main(void) {
    int n1, n2;
    int input_number;
    int count = 0;

    scanf("%d", &input_number);

    n1 = input_number;
    n2 = reverse_number(n1);

    while (n1 != n2) {
        count++;

        n1 = n2 + n1;
        n2 = reverse_number(n1);

        if (count > 1000) {
            printf("NaN\n");
           return;
        }

    }
    printf("%d %d\n", count, n1);
}
