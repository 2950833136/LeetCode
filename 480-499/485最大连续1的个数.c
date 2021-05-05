#include <stdio.h>

/**
 * 简单遍历
 *  - 遇到 1，计数加一，并更新最大计数
 *  - 遇到 0，重新计数
 */
// int findMaxConsecutiveOnes(int* nums, int numsSize) {
//     int max = 0;
//     int cnt = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] == 1) {
//             cnt++;
//             max = cnt > max ? cnt : max;
//         } else {
//             cnt = 0;
//         }
//     }
//     return max;
// }

/**
 * 双指针法
 *  - 遇到 0，计算指针间隔，更新最大计数
 *  - 最后如果为 0，循环中就可以计算，如果为 1，需要在外面计算一下
 */
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i = 0, j = 0;
    int max = 0;
    while (j < numsSize) {
        if (nums[j++] == 0) {
            max = (j - i - 1) > max ? (j - i - 1) : max;
            i   = j;
        }
    }
    // 最后一个等于 1
    max = (j - i) > max ? (j - i) : max;
    return max;
}

int main() {
    int nums[]   = {1, 1, 0, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ret = findMaxConsecutiveOnes(nums, numsSize);
    printf("%d", ret);

    return 0;
}