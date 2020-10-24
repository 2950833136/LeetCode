#include <malloc.h>
#include <stdio.h>
#include <string.h>

// 遍历输出，字符串不确定长度
void displayStr(char** pointer, int pointerSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < strlen(*(pointer + i)); j++) {
            printf("%c ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

// 遍历输出，数组确定长度
void displayChar(char** pointer, int pointerSize, int pointerColSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < pointerColSize; j++) {
            printf("%c ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

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
    // 字符串
    char   arr[][16] = {"bella", "label", "roller"};
    int    ASize     = sizeof(arr) / sizeof(arr[0]);
    char** A         = (char**)malloc(sizeof(char*) * ASize);
    for (int i = 0; i < ASize; i++) {
        *(A + i) = arr[i];
    }
    displayStr(A, ASize);

    // 二维字符数组
    char arr2[][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    char** board = (char**)malloc(sizeof(char*) * 9);
    for (int i = 0; i < 9; i++) {
        *(board + i) = arr2[i];
    }
    displayChar(board, 9, 9);

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
    *clipsColSize       = 2;
    for (int i = 0; i < clipsSize; i++) {
        *(clips + i) = arr3[i];
    }
    displayNum(clips, clipsSize, *clipsColSize);

    return 0;
}