#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 方法一：hash 表 ==> hash[arr[i]+1000]
 *      -1000 <= arr[i] <= 1000
 *  - 范围在 -1000 <= arr[i] <= 1000，全部加 1000 即可
 *  - 再构建一张存在表，记录次数
 */
// #define N 2001
// bool uniqueOccurrences(int* arr, int arrSize) {
//     int hash[N]  = {0};
//     int exist[N] = {0};
//     for (int i = 0; i < arrSize; i++) {
//         hash[arr[i] + 1000]++;
//     }
//     for (int i = 0; i < 2001; i++) {
//         if (hash[i] > 0 && exist[hash[i]] > 0) {
//             return false;
//         } else {
//             exist[hash[i]] = 1;
//         }
//     }
//     return true;
// }

/**
 * 方法二：排序计算
 */
#define MAXSIZE 1000
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool uniqueOccurrences(int* arr, int arrSize) {
    if (arrSize == 1) {
        return true;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    int exist[MAXSIZE] = {0};
    int count          = 1;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        } else {
            exist[count]++;
            count = 1;
        }
    }
    // 最后一个元素出现次数
    exist[count]++;
    // 遍历 exist 数组，如果出现大于1的，说明出现次数相同的数字
    for (int i = 0; i < MAXSIZE; i++) {
        if (exist[i] > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[]   = {1, 2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    display(arr, arrSize);

    if (uniqueOccurrences(arr, arrSize)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}