#include <malloc.h>
#include <stdio.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
}

/**
 * hash 求重复数值
 * 1-n 的规律求和：(1+n)n/2
 *      本来的和 - 现在的和 = 多余（少于）的数值
 *      再加上重复数，就是缺失的数
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ans         = (int*)malloc(sizeof(int) * 2);
    int  sum         = 0;
    int  hash[10001] = {0};

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
        sum += nums[i];
        if (hash[nums[i]] > 1) {
            ans[0] = nums[i];
        }
    }
    ans[1]      = (1 + numsSize) * numsSize / 2 - sum + ans[0];
    *returnSize = 2;
    return ans;
}

int main() {
    int nums[]     = {1, 2, 2, 4};
    int numsSize   = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    // display(nums, numsSize);

    int* ans = findErrorNums(nums, numsSize, &returnSize);
    display(ans, returnSize);

    return 0;
}