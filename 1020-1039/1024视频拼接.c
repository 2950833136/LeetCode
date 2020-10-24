#include <malloc.h>
#include <stdio.h>
#include <string.h>

// 遍历输出，数组确定长度
void displayNum(int** pointer, int pointerSize, int pointerColSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < pointerColSize; j++) {
            printf("%d ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // 二维数字数组
    int arr3[][2] = {
        {0, 2},
        {4, 6},
        {8, 10},
        {1, 9},
        {1, 5},
        {5, 9},
    };
    int** clips        = (int**)malloc(sizeof(int*) * 2);
    int   clipsSize    = sizeof(arr3) / sizeof(arr3[0]);
    int*  clipsColSize = (int*)malloc(sizeof(int));
    *clipsColSize      = 2;
    for (int i = 0; i < clipsSize; i++) {
        *(clips + i) = arr3[i];
    }
    displayNum(clips, clipsSize, *clipsColSize);

    return 0;
}