#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//최소 경로의 합 구하기

int matrixPath(int** m, int r, int c, int i, int j) {
	if (i == 0 && j == 0) // (0, 0)인 경우 현재 값 반환
		return m[i][j];

	else if (i == 0) // 맨 윗 행 //현재 위치의 요소 값과 왼쪽 요소까지의 최소 경로 합을 구하기 
		return matrixPath(m, r, c, 0, j - 1) + m[i][j];

	/* 열 인덱스 1 감소시켜서 왼쪽 요소로 이동 후 현재 값 더하기
	경로는 좌측상단에서 우측하단으로 이동하기 때문에 왼쪽 요소로 이동하기 위해서
	현재 열에서 왼쪽으로 한 칸 이동해야 한다.
	이를 통해 왼쪽 요소까지의 최소 경로 합을 구할 수 있다.
	*/

	else if (j == 0) // 맨 왼쪽 열 // 현재 위치의 요소 값과 위쪽 요소까지의 최소 경로 합을 구하기
		return matrixPath(m, r, c, i - 1, 0) + m[i][j];
	
	/*행 인덱스 i를 1 감소시켜서 위쪽 요소로 이동한다. 
	위쪽 요소까지의 최소 경로 합에 현재 위치의 요소 값을 더한 값을 반환
	*/

	/*현재 위치가 좌측 상단이 아니고 맨 윗 행이나 맨 왼쪽 열에도 속하지 않는 경우 
	현재 위치에서 왼쪽 요소까지의 최소 경로 합과 위쪽 요소까지의 최소 경로 합을 계산하여 
	더 작은 값을 선택*/

	else { 
		int a, b;
		a = matrixPath(m, r, c, i - 1, j); // 왼쪽 요소까지의 최소 경로 합
		b = matrixPath(m, r, c, i, j - 1); // 위쪽 요소까지의 최소 경로 합
		
		return ((a < b) ? a : b) + m[i][j];
		// 삼항 연산자 -> a와 b 중에서 작은 값 선택

		/*왼쪽 요소까지의 최소 경로 합과 위쪽 요소까지의 최소 경로 합 중에서 작은 값을 선택하고, 
		현재 위치의 요소 값을 더한 값이므로, 현재 위치까지의 최소 경로 합을 계산하는 것
		-> 반환값은 현재 위치 (i, j)까지의 최소 경로 합
		*/
	}
}

int main(void) {
	int** m;
	int i, j;
	int r = 4, c = 4; // 4x4 matrix

	m = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++)
		m[i] = (int*)malloc(sizeof(int) * c);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &m[i][j]);

	printf("%d\n", matrixPath(m, r, c, 3, 3)); // (3, 3)값
  
	for (i = 0; i < r; i++)
		free(m[i]);
	free(m);
        return 0;
}
