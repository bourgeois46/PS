#include <stdio.h>
#include <stdlib.h>

// version 1
int matrixPath_memo(int** m, int r, int c, int i, int j, int** M) {
	
	if (i == 0 && j == 0) 
		return m[0][0];
	
	else if (i == 0) { // 맨 윗 행 -> 왼쪽에서만 올 수 있음
		if (M[0][j - 1] == 0) // 왼쪽 요소까지의 최소 경로 합이 계산되지 x
			M[0][j - 1] = matrixPath_memo(m, r, c, 0, j - 1, M); 
		// 왼쪽 요소까지의 최소 경로 합을 구하고 저장
		
		return M[0][j - 1] + m[i][j]; 
		// 왼쪽 요소까지의 최소 경로 합에 현재 위치의 요소 값을 더한 값 반환
	}

	else if (j == 0) { // 맨 왼쪽 열 -> 위쪽에서만 올 수 있음
		if (M[i - 1][0] == 0) // 위쪽 요소까지의 최소 경로 합이 계산되지 x
			M[i - 1][0] = matrixPath_memo(m, r, c, i - 1, 0, M);
		// 위쪽 요소까지의 최소 경로 합을 구하고 저장

		return M[i - 1][0] + m[i][j];
		// 위쪽 요소까지의 최소 경로 합에 현재 위치의 요소 값을 더한 값을 반환
	}

	else { // 맨 윗 행도 아니고 맨 왼쪽 열도 아닌 경우 
		// 현재 위치로 왼쪽과 위쪽 중에서 최소 경로 합을 선택해야 함

		if (M[i - 1][j] == 0) // 왼쪽 요소까지의 최소 경로 합이 계산되지 않았음
			M[i - 1][j] = matrixPath_memo(m, r, c, i - 1, j, M);
		// 왼쪽 요소까지의 최소 경로 합을 계산하고 저장
		
		if (M[i][j - 1] == 0) // 위쪽 요소까지의 최소 경로 합이 계산되지 않았음
			M[i][j - 1] = matrixPath_memo(m, r, c, i, j - 1, M);
		// 위쪽 요소까지의 최소 경로 합을 계산하고 저장

		return (M[i - 1][j] < M[i][j - 1] ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
		// 왼쪽 요소까지의 최소 경로 합과 위쪽 요소까지의 최소 경로 합 중 더 작은 값을 선택하고 현재 위치의 요소 값을 더하여 반환
	}
	
// version 2
int matrixPath_memo(int** m, int r, int c, int i, int j, int** M) {
	if( M[i][j] != 0 ) // 계산되어있으면 그 값 반환
		return M[i][j];

	// 계산되어 있지 않음
	if ( i == 0 && j == 0 )
		return m[i][j];
	
	else if ( i == 0 ) { // 맨 윗행
		M[i][j] = matrixPath(m,r,c,0,j-1,M)+ m[i][j];
		return M[i][j];
        }
	
	else if ( j == 0 ) { // 맨 왼쪽행
		M[i][j] = matrixPath(m,r,c,i-1,0,M)+ m[i][j];
		return M[i][j];
        }
	
	else { // 맨 윗행, 맨 왼쪽 행 제외
		int a,b;
		a = matrixPath(m,r,c,i-1,j,M);
		b = matrixPath(m,r,c,i,j-1,M);
		M[i][j]= ((a<b)? a:b) + m[i][j];
		return M[i][j];
	}
}

}

int main(void) {
	int** m, ** M; // M은 메모
	int i, j;
	int r = 4, c = 4; // 4x4 matrix

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0; //메모 초기화
		}

	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M));
	
	for (i = 0; i < r; i++)
		free(m[i]);
	free(m);

	for (i = 0; i < r; i++)
		free(M[i]);
	free(M);

	return 0;
}
