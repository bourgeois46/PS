#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void pick(int n, int picked[], int m, int toPick) {
	int smallest, lastIndex, i;

	if (toPick == 0) {//고를게x -> 출력
		for (i = 0; i < m; i++)//뽑은 개수만큼 출력
			printf("%d ", picked[i]);
		printf("\n");
    
		return;//제일 마지막에 수행되는 조건문 -> main으로 return
	}

	lastIndex = m - toPick - 1;//마지막에 채워진 것의 인덱스

	if (m == toPick)//처음 고르는 거면
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;//마지막으로 뽑은 수 + 1

	for (i = smallest; i < n; i++) {//뽑을 수 있는 수의 범위 i
		picked[lastIndex + 1] = i;
		pick(n, picked, m, toPick - 1);//하나뽑았으니까 -1
	}//모든 조합의 수
	//smallest 부터 n-1까지 하나씩 picked에 넣고 그 뒤 재귀호출(반복)
}

int main(void) {
	int picked[4];
	pick(7, picked, 4, 4);
}
