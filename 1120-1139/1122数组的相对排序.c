#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

typedef enum {
    false = 0,
    true  = 1
} bool;

/**
 * - 含有的值数记录次数 countArr
 *      - 根据数组二依次写入数据次数
 * - 不含有的数值到 TailArr
 *      - 排序
 */
int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {

    int* countArr = (int*)malloc(sizeof(int) * arr2Size);
    memset(countArr, 0, sizeof(int) * arr2Size);

    int* TailArr = (int*)malloc(sizeof(int) * arr1Size);
    memset(TailArr, 0, sizeof(int) * arr1Size);

    int* ReslArr = (int*)malloc(sizeof(int) * arr1Size);
    memset(ReslArr, 0, sizeof(int) * arr1Size);
    int Count = 0;

    //输出数组2元素的数量，同时将没匹配的放数组中
    for (int i = 0; i < arr1Size; i++) {
        bool bmatch = false;
        for (int j = 0; j < arr2Size; j++) {
            if (arr1[i] == arr2[j]) {
                countArr[j]++;
                bmatch = true;
                break;
            }
        }
        //如果没有匹配上，放入tail数组
        if (bmatch == false) {
            TailArr[Count++] = arr1[i];
        }
    }

    //处理匹配上，放数组前面
    int index = 0;
    for (int k = 0; k < arr2Size; k++) {
        for (int j = 0; j < countArr[k]; j++) {
            ReslArr[index++] = arr2[k];
        }
    }

    //处理尾部数据
    qsort(TailArr, Count, sizeof(int), cmp);
    for (int l = 0; l < Count; l++) {
        ReslArr[index++] = TailArr[l];
    }

    *returnSize = arr1Size;
    return ReslArr;
}

int main() {
    int arr1[]     = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int arr1Size   = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[]     = {2, 1, 4, 3, 9, 6};
    int arr2Size   = sizeof(arr2) / sizeof(arr2[0]);
    int returnSize = 0;

    int* ret = relativeSortArray(arr1, arr1Size, arr2, arr2Size, &returnSize);

    return 0;
}