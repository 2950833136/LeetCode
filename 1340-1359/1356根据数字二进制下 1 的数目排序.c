#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 常规思路：计算包含 1
 */
// int bitCount(int num) {
//     int bit = 0;
//     while (num) {
//         if (num % 2 == 1) {
//             bit++;
//         }
//         num /= 2;
//     }
//     return bit;
// }

// int* sortByBits(int* arr, int arrSize, int* returnSize) {
//     int* bits = (int*)malloc(sizeof(int) * arrSize);

//     for (int i = 0; i < arrSize; i++) {
//         bits[i] = bitCount(arr[i]);
//     }

//     for (int i = 0; i < arrSize - 1; i++) {
//         for (int j = arrSize - 1; j > i; j--) {
//             if (bits[j - 1] > bits[j] || ((bits[j - 1] == bits[j]) && (arr[j - 1] > arr[j]))) {
//                 int temp1   = bits[j - 1];
//                 bits[j - 1] = bits[j];
//                 bits[j]     = temp1;

//                 int temp2  = arr[j - 1];
//                 arr[j - 1] = arr[j];
//                 arr[j]     = temp2;
//             }
//         }
//     }
//     *returnSize = arrSize;
//     return arr;
// }

/**
 * 修改方法：利用 qsort 改变 sort 规则
 */
int getNum1(int n) { //获取二进制下1的个数
    int num = 0;
    while (n > 0) {
        n &= (n - 1);
        num++;
    }
    return num;
}

int cmp(const void* a, const void* b) {
    int a1 = getNum1(*(int*)a);
    int b1 = getNum1(*(int*)b);
    return a1 == b1 ? *(int*)a - *(int*)b : a1 - b1;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmp);
    return arr;
}

int main() {
    int arr[]      = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    int arrSize    = sizeof(arr) / sizeof(arr[0]);
    int returnSize = 0;

    int* ret = sortByBits(arr, arrSize, &returnSize);
    display(ret, returnSize);

    return 0;
}