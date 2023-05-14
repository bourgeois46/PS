#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student {
	int id, korean, english, math;
};//
void selectionSort(struct Student* A, int n) {//����ü �迭
	int i, j, max_idx;//max ���ְ� max_idx��!!
	struct Student temp;

	for (i = 0; i < n - 1; i++) {
		 max_idx = 0;

		for (j = 1; j < n - i; j++)
			//max 2��° ������ ���� �Ŷ� j = 1 ����
			if (A[max_idx].korean > A[j].korean)//��������
				max_idx = j;

		//A[max_id] <-> A[n-1-i]/swap
		//j�� �ϸ� ����
		temp = A[max_idx];
		A[max_idx] = A[n - i - 1];
		A[n-i-1] = temp;
	}

	
}
int main() {
	int n, i;
	struct Student* A;//

	srand(time(NULL));

	scanf("%d", &n);

	A = (struct Student*)malloc(sizeof(struct Student) * n);//

	for (i = 0; i < n; i++) {
		A[i].id = i + 1;//�й��� �׳� ����
		A[i].math = rand() % 101;
		A[i].english = rand() % 101;
		A[i].korean = rand() % 101;
	}

	for (i = 0; i < n; i++) //���� ��
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	printf("============================\n");
	selectionSort(A, n);

	for (i = 0; i < n; i++) //���� ��
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	free(A);
}