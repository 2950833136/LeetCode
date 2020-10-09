#include <malloc.h>
#include <stdio.h>

/**
 * arr[0]: 分子
 * arr[1]: 分母
 *
 * 1、简单的通分，因为每次都是 1/a，所以需要分数反转，即分子分母交换一下
 * 2、这题不需要约分，本来就是最简
 */
int* fraction(int* cont, int contSize, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 2);
    arr[0] = 1;
    arr[1] = 0;
    for (int i = contSize - 1; i >= 0; i--) {
        int temp = arr[1];
        arr[1] = arr[0];
        arr[0] = cont[i] * arr[1] + temp;
    }
    *returnSize = 2;
    return arr;
}

int main() {
    int cont[] = {3, 2, 0, 2};
    int contSize = sizeof(cont) / sizeof(int);
    int* returnSize = (int*)malloc(sizeof(int));

    int* arr = (int*)malloc(sizeof(int) * 2);
    arr = fraction(cont, contSize, returnSize);
    printf("[%d, %d]", arr[0], arr[1]);

    return 0;
}