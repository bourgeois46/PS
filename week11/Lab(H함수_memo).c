#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int *m, int n) {
	int sum = 0;

	if (m[n] != 0) // 이미 계산된 값이 있으면 그대로 반환
		return m[n];

	if (n == 0 || n == 1) // 가장 작은 값이 1이고 나머지는 1보다 큼 -> 0으로 memo 초기화 가능
		return 1;
	
	for (int i = 0; i < n; i++)
		sum = sum + H(m, i) * H(m, n - 1 - i);
	m[n] = sum;

	return m[n];

	/*else if (n > 1) { // 이전에 계산된 값이 없는 경우
		int i, sum = 0;

		for (i = 0; i < n; i++)
			sum = sum + H(m, i) * H(m, n - 1 - i);

		m[n] = sum;

		return sum;
	}*/
  
}

int main(void) {
	int n, i;
	int *m;

	printf("0보다 큰 정수: ");
	scanf("%d", &n);

	m = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n + 1; i++)
		m[i] = 0;

	printf("결과는 %d\n", H(m, n));

	free(m);
	return 0;
}
