#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void readMatrix(int a[][3]) {
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}
void matrixAdd(int a[][3], int b[][3], int x[][3]) {
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int a[][3]) {
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++) 
			printf("%d ", a[i][j]);
		printf("\n");
		}
}
int main(void) {
	int A[3][3], B[3][3], sum[3][3];

	printf("(3 X 3) 행렬 A 입력: \n");
	readMatrix(A);

	printf("(3 X 3) 행렬 B 입력: \n");
	readMatrix(B);

	printf("행렬합: \n");
	matrixAdd(A, B, sum);
	printMatrix(sum);

	return 0;
}
