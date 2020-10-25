#include <malloc.h>
#include <stdio.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 方法一：暴力求解
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                count++;
            }
            *(ret + i) = count;
        }
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