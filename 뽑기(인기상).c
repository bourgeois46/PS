#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include <string.h>
#include <stdlib.h>//동적할당

void pick(char* actors[], int n, int* picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
            printf("%s ", actors[picked[i]]);
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;

    if (toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;//조합

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(actors, n, picked, m, toPick - 1);
    }
}

int main() {
    char* actors[] = { "공유", "김수현","송중기", "지성", "현빈" };
    
    int *picked, m;//버켓을 동적할당으로//여기서 int형 했으니까 다 int형
    
    scanf("%d", &m);
    picked = (int*)malloc(sizeof(int) * m);

    pick(actors, 5, picked, m, m);
}
