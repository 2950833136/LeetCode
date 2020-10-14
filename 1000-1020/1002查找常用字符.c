#include <malloc.h>
#include <stdio.h>
#include <string.h>

// 遍历输出
void displayChar(char** pointer, int pointerSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < strlen(*(pointer + i)); j++) {
            printf("%c ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
}

char** commonChars(char** A, int ASize, int* returnSize) {
    printf("%c", A[0][2]);
    return NULL;
}

int main() {
    char   arr[][16]  = {"bella", "label", "roller"};
    int    ASize      = sizeof(arr) / sizeof(arr[0]);
    int*   returnSize = (int*)malloc(sizeof(int));
    char** A          = (char**)malloc(sizeof(char*) * ASize);
    for (int i = 0; i < ASize; i++) {
        *(A + i) = arr[i];
    }

    displayChar(A, ASize);
    // commonChars(A, ASize, returnSize);

    return 0;
}