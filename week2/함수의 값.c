#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H(int n) {
	
	if (n == 0 || n == 1) {
		return 1;
	}
  
	else if (n > 1) {//else 
		int i, sum = 0;

		for (i = 0; i < n; i++)// 0~ n-1
			sum = sum + H(i) * H(n - i - 1);//규칙 -> 더해서 n-1
		return sum;
	}
	
}

int main(void) {
	int input_number;
	
	scanf("%d", &input_number);
	printf("%d\n", H(input_number));
}
