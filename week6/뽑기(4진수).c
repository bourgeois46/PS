#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>//빼먹지말기
void pick(int *num, int n, int* picked, int m, int toPick) {//item 생각
	int i, lastIndex, smallest;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", num[picked[i]]);
		printf("\n");
		return;
	}
	//중복순열 매번 전체에서 뽑는다

	lastIndex = m - toPick - 1;

	smallest = 0;

	for (i = smallest; i < n; i++) {//중복순열이니까 smallest 대신 바로 0사용 가능
		picked[lastIndex + 1] = i;
		pick(num, n, picked, m, toPick - 1);
	}
}

int main(void) {//입력 -> 자릿수
	//4진법 -> 0, 1, 2, 3의 조합
	int num[] = { 0, 1, 2, 3 };
	int *picked, m;

	scanf("%d", &m);
	picked = (int*)malloc(sizeof(int) * m);

	pick(num, 4, picked, m, m);//입력받은 수만큼 골라야
	//4진법이니까 4 픽스
	//여기서는 어차피 범위가 0~ n(itemSize)라서 item 생략 가능*
  
	free(picked);
}
