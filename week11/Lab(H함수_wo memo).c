#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int n) {
	if (n == 0 || n == 1)
		return 1;

	else if (n > 1) {
		int i, sum = 0;

		for (i = 0; i < n; i++)
			sum = sum + H(i) * H(n - 1 - i);
		return sum;
	}
  
  /*else if문 없이 가능
	 for (i = 0; i < n; i++)
			sum = sum + H(i) * H(n - 1 - i);
	  return sum;
	*/

}

int main(void) {
	int n;
	printf("0보다 큰 정수: ");
	scanf("%d", &n);
	printf("결과는 %d\n", H(n));  
  return 0;
}
