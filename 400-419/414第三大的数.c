#include <limits.h>
#include <stdio.h>

/**
 * 求第三大的数
 *  + 直接创建三个变量保存第一大，第二大，第三大数
 *      - long 型数据，因为有数字是 -2147483648，int 会出错
 *      - 有相等的不算入在内，继续循环
 *      - 有大的数据，一次更新数据
 */
int thirdMax(int* nums, int numsSize) {
    long first  = LONG_MIN;
    long second = LONG_MIN;
    long third  = LONG_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == first || nums[i] == second || nums[i] == third) {
            continue;
        }

        if (nums[i] > first) {
            third  = second;
            second = first;
            first  = nums[i];
        } else if (nums[i] > second) {
            third  = second;
            second = nums[i];
        } else if (nums[i] > third) {
            third = nums[i];
        }
    }
    return (third == LONG_MIN) ? first : third;
}

int main() {
    int nums[]   = {1, 2, -2147483648};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ans = thirdMax(nums, numsSize);
    printf("%d", ans);

    return 0;
}