#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main() {
	int n;

	printf("몇 번째까지의 피보나치 수열: ");
	scanf("%d", &n);

	printf("%d\n", fib(n));
	return 0;
}
