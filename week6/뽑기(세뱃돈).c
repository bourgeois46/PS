#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* picked, int m, int k) {
	int i, lastIndex, smallest, total = 0;

	if (k == 0) {//다 골랐으면 total을 먼저 구하고 
		//total이 6000이 되면, 출력

		for (i = 0; i < m; i++)
			total += item[picked[i]];//값!을 다 저장

		if (total == 1000 * m) {//6000원이 되면
			for (i = 0; i < m; i++)//picked 를 출력(값으로)
				if (item[picked[i]] != 0)//단, 0출력x
					printf("%d ", item[picked[i]]);
			printf("\n");
		}
		return;//무한호출x
	}

	lastIndex = m - k - 1;

	if (m == k)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(item, n, picked, m, k - 1);
	}
	
}

int main(void) {
	int item[4] = { 1000, 5000, 10000, 0 };
	int money, m, *picked;

	scanf("%d", &money);
	m = money / 1000;///다 1000단위라서

	picked = (int*)malloc(sizeof(int) * m);
	pick(item, 4, picked, m, m);//6
  
	//bucketSize, toPick 때문에 1000으로 나눔
	//6000원 기준 최대 가지수 6이기 때문에 
	//bucketSize -> money/1000이 되는 것

}
