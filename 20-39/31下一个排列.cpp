#include <stdio.h>

/**
 * 题目：找到下一个更大的数，否则逆序排列 
 * 更大的数必定左边大于右边
 * 1、从右边遍历找到不是降序排列的，找到右边小于左边的数，即 nums[i] > nums[i+1]，这就是交换点
 * 2、从右边遍历找到比交换点大的数，即 nums[j] > nums[i]
 * 3、交换 nums[j] 和 nums[i]
 * 4、仅仅需要找到下一个更大的数，将 nums[i] 后面降序逆转为升序，即可找到最小的更大数
 * 
 */
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void reserve(int* nums, int i, int j) {
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    // 从右边遍历找到不是降序排列的，找到右边小于左边的数，即 nums[i] > nums[i+1]，这就是交换点
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        // 从右边遍历找到比交换点大的数，即 nums[j] > nums[i]
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        // 交换 nums[j] 和 nums[i]
        swap(nums, i, j);
    }
    // 仅仅需要找到下一个更大的数，将 nums[i] 后面降序逆转为升序，即可找到最小的更大数
    reserve(nums, i + 1, numsSize - 1);
}

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(int);

    display(nums, numsSize);
    nextPermutation(nums, numsSize);
    display(nums, numsSize);
    return 0;
}