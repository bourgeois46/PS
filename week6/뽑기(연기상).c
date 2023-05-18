#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void pick(char* actor[], int n, int* picked, int m, int toPick) {
	int i, lastIndex;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%s\t", actor[picked[i]]);//%s
		   //printf("%d ", picked[i]);//인덱스 먼저 확인
		printf("\n");
		return;
	}
	lastIndex = m - toPick - 1;

	//이미 뽑혔는지 검사
	for (i = 0; i < n; i++) {//루프 연습 
		int j, flag = 0;//bucket == picked

		for (j = 0; j <= lastIndex; j++)
			if (picked[j] == i) 
				flag = 1;//뽑혀있다!
		//여기서 continue하면 안쪽 루프로 돌아감
		//의도는 바깥루프로 돌아가게하는 것
		if (flag == 1) continue;

		picked[lastIndex + 1] = i;
		pick(actor, n, picked, m, toPick - 1);
	}
}

int main(void) {//문자열을 뽑는 것
	char* actor[] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int *picked, m;
	
	printf("상의 종류는? ");
	scanf("%d", &m);//상의 종류

	picked = (int*)malloc(sizeof(int) * m);

	pick(actor, 5, picked, m, m);

	free(picked);
}
