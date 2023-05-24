#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}
void matrixAdd(int **a, int **b, int **x, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int **a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}
int main(void) {
	int **A, **B;
	int** X; // A + B
	int aRow, aCol;
	int i;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	// 동적으로 행렬 A, B, X 생성 // 모두 aRow x aCol
	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	B = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		B[i] = (int*)malloc(sizeof(int) * aCol);

	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		X[i] = (int*)malloc(sizeof(int) * aCol);

	// A B 행렬값 입력 및 x 행렬 초기화
	printf("행렬 A 입력:\n");
	readMatrix(A, aRow, aCol);

	printf("\n행렬 B 입력:\n");
	readMatrix(B, aRow, aCol);

	matrixAdd(A, B, X, aRow, aCol);

	printf("\n행렬합: \n");
	printMatrix(X, aRow, aCol);

	// 동적 할당 해제
	for (i = 0; i < aRow; i++)
		free(A[i]);
	free(A);

	for (i = 0; i < aRow; i++)
		free(B[i]);
	free(B);

	for (i = 0; i < aRow; i++)
		free(X[i]);
	free(X);

	return 0;
}
