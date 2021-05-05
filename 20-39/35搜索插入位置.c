#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > target) {
            return i;
        } else if (nums[i] == target) {
            return i;
        } else if (nums[numsSize - 1] < target) {
            return numsSize;
        }
    }
    return 0;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 2;

    int ret = searchInsert(nums, numsSize, target);
    printf("%d", ret);

    return 0;
}