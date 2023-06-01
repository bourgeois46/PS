#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}

int** matrixMultiply(int** a, int** b, int r1, int c1, int r2, int c2) {
	int i, j, k;
	
	int** result = (int**)malloc(sizeof(int*) * r1);
	for (i = 0; i < r1; i++)
		result[i] = (int*)malloc(sizeof(int) * c2);

	for (i = 0; i < r1; i++) {
		for (j = 0; j < c2; j++) {
			result[i][j] = 0;
			for (k = 0; k < c1; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return result;
}

int** transposeMatrix(int** a, int r, int c) {
	int i, j;
	
	int** result = (int**)malloc(sizeof(int*) * c);
	for (i = 0; i < c; i++)
		result[i] = (int*)malloc(sizeof(int) * r);

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			result[j][i] = a[i][j];
		}
	}

	return result;
}

void printMatrix(int** a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
}

int main(void) {
	int** A, ** C;
	int** multiplyResult, ** transpose;
	int aRow, aCol;
	int cRow, cCol;
	int i;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	printf("Enter 행렬 C의 행과 열의 개수<c의 행은 4이어야>: ");
	scanf("%d %d", &cRow, &cCol);

	// 동적으로 행렬 A, C 할당
	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	C = (int**)malloc(sizeof(int*) * cRow);
	for (i = 0; i < cRow; i++)
		C[i] = (int*)malloc(sizeof(int) * cCol);

	// A, C 행렬값 입력
	printf("%d x %d 행렬 A 입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("\n%d x %d 행렬 C 입력:\n", cRow, cCol);
	readMatrix(C, cRow, cCol);

	// A와 C의 곱 계산
	multiplyResult = matrixMultiply(A, C, aRow, aCol, cRow, cCol);

	// A의 전치행렬 계산
	transpose = transposeMatrix(A, aRow, aCol);

	printf("\n행렬곱:\n");
	printMatrix(multiplyResult, aRow, cCol);

	printf("\n전치행렬:\n");
	printMatrix(transpose, aCol, aRow);

	// 동적 할당 해제
	for (i = 0; i < aRow; i++)
		free(A[i]);
	free(A);

	for (i = 0; i < cRow; i++)
		free(C[i]);
	free(C);

	for (i = 0; i < aRow; i++)
		free(multiplyResult[i]);
	free(multiplyResult);

	for (i = 0; i < aCol; i++)
		free(transpose[i]);
	free(transpose);

	return 0;
}
