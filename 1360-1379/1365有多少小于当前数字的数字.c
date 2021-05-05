#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 方法一：暴力求解
 */
// int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
//     int* ret = (int*)malloc(sizeof(int) * numsSize);
//     for (int i = 0; i < numsSize; i++) {
//         int count = 0;
//         for (int j = 0; j < numsSize; j++) {
//             if (nums[i] > nums[j]) {
//                 count++;
//             }
//             *(ret + i) = count;
//         }
//     }
//     *returnSize = numsSize;
//     return ret;
// }

/**
 * 方法二：快速排序
 *  - 用二级指正记录数值和下标
 *  - 根据数值排序，排序后的下标就是有几个比它小，遍历写入结果
 *      - idx 记录有几个比它小
 *      - 如果一样 idx 不更新
 */
// int cmp(const void* a, const void* b) {
//     return (*(int**)a)[0] - (*(int**)b)[0];
// }

// int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
//     int* data[numsSize];
//     for (int i = 0; i < numsSize; i++) {
//         data[i]    = (int*)malloc(sizeof(int) * 2);
//         data[i][0] = nums[i];
//         data[i][1] = i;
//     }
//     qsort(data, numsSize, sizeof(int*), cmp);

//     int  idx = -1;
//     int* ret = (int*)malloc(sizeof(int) * numsSize);
//     for (int i = 0; i < numsSize; i++) {
//         if (idx == -1 || data[i][0] != data[i - 1][0]) {
//             idx = i;
//         }
//         ret[data[i][1]] = idx;
//     }
//     *returnSize = numsSize;
//     return ret;
// }

/**
 * 方法三：计数排序
 *  - 注意到数组元素的值域为 [0,100]，所以可以考虑建立一个频次数组 cnt
 *  - cnt[i] 表示数字 i 出现的次数。那么对于数字 i 而言，小于它的数目就为 cnt[0...i−1] 的总和。
 *      - 小于它的数目就为 cnt[0...i−1] 的总和。
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int cnt[101];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (int i = 1; i < 101; i++) {
        cnt[i] += cnt[i - 1];
    }

    int* ret = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        ret[i] = nums[i] == 0 ? 0 : cnt[nums[i] - 1];
    }
    *returnSize = numsSize;
    return ret;
}

int main() {
    int  nums[]     = {8, 1, 2, 2, 3};
    int  numsSize   = sizeof(nums) / sizeof(nums[0]);
    int* returnSize = (int*)malloc(sizeof(int));
    display(nums, numsSize);

    int* ret = smallerNumbersThanCurrent(nums, numsSize, returnSize);
    display(ret, numsSize);

    return 0;
}
