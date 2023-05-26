#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r) {
	printf("comb(%d %d)\n", n, r);

	if (r == 0 || n == r)
		return 1;
	else
		//n-1Cr-1 + n-1Cr 
		return comb(n - 1, r - 1) + comb(n - 1, r);
}

int main(void) {
	int C;
	C = comb(4, 2); // 4C2
	printf("%d\n", C);
	return 0;
}
