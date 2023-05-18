#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// % -> 나머지
// / -> 몫(재귀호출)

int main(void) {
	int n1, n2;
	int r1, r2;//각 자릿수마다 계산 -> 뒷자리부터 계산 
	int carry = 0;//발생 유무/flag 변수
	int carry_count = 0;//발생 횟수

	scanf("%d %d", &n1, &n2);//123, 999

	while (n1 > 0 || n2 > 0) {//n1 != 0 || n2 != 0
		r1 = n1 % 10;//123 -> 3/12 -> 2/1
		r2 = n2 % 10;//999 -> 9//99 -> 9/9
		//뒷자리수부터 하나씩 
		
		//계산은 r1, r2로(뒤부터 한자리씩)
		if (r1 + r2 + carry >= 10) {//+carry 왜 포함되는지?? 없어도 정상 작동
			carry = 1;//발생
			carry_count++;//1, 1, 1
		}
		else
			carry = 0;//이전에 발생했는지 반드시 체크 -> 이전의 발생이 이후의 계산에 영향 주는 경우 있기 때문

		n1 = n1 / 10;//123 -> 12/12 -> 1
		n2 = n2 / 10;//999 -> 99/99 -> 9

	}

	printf("%d\n", carry_count);
}
