#include <stdio.h>

/**
 * 二分法查找
 * 虽然旋转过后不是全部升序排列，但是至少一半是升序排列，所以可以用二分法查找
 * 1、可以先判断 target 处于哪一部分
 *      nums[0] <= nums[mid]
 * 2、在根据是否升序排列且位于其中，判断那个指针位移
 *      nums[0] <= target && target < nums[mid]
 * 3、找到条件
 *      nums[mid] == target  
 */ 

int search(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return -1;
    }
    if (numsSize == 1) {
        return target == nums[0] ? 0 : -1;
    }
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[numsSize - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 0;
    int ans = search(nums, numsSize, target);
    printf("%d", ans);
    return 0;
}