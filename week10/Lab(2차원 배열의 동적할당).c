#include <stdio.h>
#include <stdlib.h>

int main() {
	int row, col, i, j;
	int sum = 0;
	int** p;

	printf("2차원 배열의 크기?\n");
	scanf("%d", &row);
	scanf("%d", &col);

	p = (int**)malloc(sizeof(int*) * row); // r행 동적할당
	for (i = 0; i < row; i++)
		p[i] = (int*)malloc(sizeof(int) * col); // 각 행마다 열 할당

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf("%d", &p[i][j]);

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			sum += p[i][j];

	printf("합 = %d\n", sum);

	for (i = 0; i < row; i++)
		free(p[i]); // 각 열을 반환
	
	free(p); // 행을 반환
}
