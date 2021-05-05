#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 遍历输出，数组确定长度
void displayNum(int** pointer, int pointerSize, int* pointerColSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < *pointerColSize; j++) {
            printf("%d ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * 排序
 *  - 将每个点到原点的欧几里得距离的平方从小到大排序后，取出前 K 个即可。
 */
int cmp(const void* a, const void* b) {
    int x1 = (*(int**)a)[0];
    int y1 = (*(int**)a)[1];

    int x2 = (*(int**)b)[0];
    int y2 = (*(int**)b)[1];

    return ((x1 * x1 + y1 * y1) - (x2 * x2 + y2 * y2));
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
    // 数组排序
    qsort(points, pointsSize, sizeof(int**), cmp);
    *returnColumnSizes = (int*)malloc(K * sizeof(int));
    memset(*returnColumnSizes, 0, sizeof(int) * K);

    for (int i = 0; i < K; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = K;

    // 返回排序后的数组，通过returnColumnSizes指定只有K个元素；
    return points;
}

int main() {

    // 二维数字数组
    int arr[][2] = {
        {3, 3},
        {5, -1},
        {-2, 4},
    };
    int   pointsColSize = 2;
    int   pointsSize    = sizeof(arr) / sizeof(arr[0]);
    int** points        = (int**)malloc(sizeof(int*) * pointsSize);
    for (int i = 0; i < pointsSize; i++) {
        *(points + i) = (int*)malloc(sizeof(int) * pointsColSize);
        *(points + i) = arr[i];
    }
    displayNum(points, pointsSize, &pointsColSize);

    int   K                 = 2;
    int*  returnSize        = (int*)malloc(sizeof(int));
    int** returnColumnSizes = (int**)malloc(sizeof(int*));

    int** ret = kClosest(points, pointsSize, &pointsColSize, K, returnSize, returnColumnSizes);
    displayNum(ret, *returnSize, *returnColumnSizes);

    return 0;
}