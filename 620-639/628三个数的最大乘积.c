#include <limits.h>
#include <stdio.h>

/**
 * 排序判断大小
 */
// int* cmp(const void* a, const void* b) {
//     return *(int*)a - *(int*)b;
// }

// int maximumProduct(int* nums, int numsSize) {
//     qsort(nums, numsSize, sizeof(int), cmp);
//     int result1 = nums[0] * nums[1] * nums[numsSize - 1];
//     int result2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
//     return result1 > result2 ? result1 : result2;
// }

/**
 * 三个数的最大乘积
 *  + 如果全部为正数或负数
 *      - 直接就是最大的三个相乘（排序后最靠后面的）
 *  + 如果存在负数
 *      - 两个最小负数与第二大第三大正数比较，大的与最大值相乘
 */
int maximumProduct(int* nums, int numsSize) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] <= min2) {
            min2 = nums[i];
        }

        if (nums[i] >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] >= max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] >= max3) {
            max3 = nums[i];
        }
    }
    // printf("%d %d %d %d %d\n", min1, min2, max1, max2, max3);
    return (min1 * min2) > (max2 * max3) ? (min1 * min2 * max1) : (max1 * max2 * max3);
}

int main() {
    int nums[]   = {-4, -3, -2, -1, 60};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ans = maximumProduct(nums, numsSize);
    printf("%d", ans);

    return 0;
}