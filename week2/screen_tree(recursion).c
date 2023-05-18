#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];
#include <stdio.h>

void draw_tree(int row, int left, int right) {
	int mid;

	if (right - left < 2)
		return;//순환호출 멈춤
	
	mid = (right + left) / 2;
	//중간 위치 계산, 중간에 x 출력, 주어진 영역 2개로 나눠서 순환호출
	
	screen[row][mid] = 'X';//0행 중간, 1행 중간,,, 중간에 X 출력
	
	draw_tree(row+1, left, mid);//왼쪽 영역/왼쪽 끝 ~ mid
	draw_tree(row+1, mid+1, right);//오른쪽 영역//mind +1 ~ 오른쪽 끝
	//row + 1 -> 순환호출 다음행 계속 
}
void init(char s[][MAX_WIDTH]) {//스크린 문자열을 초기화
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}
void display(char s[][MAX_WIDTH], int width) {//입력받은 width로 출력
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			printf("%c", s[i][j]);
		printf("\n");
	}
}

int main(void) {
	int width;

	init(screen);//초기화

	printf("Enter a width(<= 70) of a screen: ");
	scanf("%d", &width);

	draw_tree(0, 0, width-1);//-1 하든안하든 결과는 같음
	display(screen, width);
}
