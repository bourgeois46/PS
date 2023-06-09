#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// version 1
int comb(int **m, int n, int r) {
	printf("comb(%d %d)\n", n, r);

	if (r == 0 || n == r)
		return 1;

	if (m[n - 1][r] == 0) {
		m[n - 1][r] = comb(m, n - 1, r - 1) + comb(m, n - 1, r);
	}
	return m[n - 1][r];

}

// version 2
int comb(int** m, int n, int r) {
	printf("comb(%d %d)\n", n, r);

	if (m[n-1][r] != 0) // 계산되어있으면 그 값 반환
		return m[n-1][r];

	// 계산X
	if (r == 0 || n == r)
		return 1;

	return m[n - 1][r] = comb(m, n - 1, r - 1) + comb(m, n - 1, r);
}

}

int main(void) {
	int C;
	int n, r;
	int i, j;
	int** m; // 이전에 계산한 조합의 값 저장

	printf("Enter n and r(nCr): ");
	scanf("%d %d", &n, &r);

	m = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) 
		m[i] = (int*)malloc(sizeof(int) * (r + 1));

	for (i = 0; i < n; i++)
		for (j = 0; j < r + 1; j++)
			m[i][j] = 0;

	C = comb(m, n, r);
	printf("%d\n", C);

	for (i = 0; i < n; i++)
		free(m[i]);
	free(m);

	return 0;
}
