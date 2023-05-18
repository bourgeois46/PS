#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n) {
	
	printf("%d ", n);//수열 출력
	//수열의 길이를 리턴
	if (n == 1)
		return 1;

	else if (n % 2 == 0) 
		return get_cycle_number(n / 2) + 1;//수열의 길이라서 +1
	else
		return get_cycle_number(n * 3 + 1) + 1;

}
int main(void) {
	int input_number;

	scanf("%d", &input_number);
	printf("\n%d", get_cycle_number(input_number));

}
