#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 方法一：排序 
 * 
 */
int max(int a, int b) {
    return a > b ? a : b;
}
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ret    = (int*)malloc(sizeof(int) * max(nums1Size, nums2Size));
    *returnSize = 0;

    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int index1 = 0;
    int index2 = 0;
    while (index1 < nums1Size && index2 < nums2Size) {
        int num1 = nums1[index1];
        int num2 = nums2[index2];
        if (num1 == num2) {
            // 保证加入元素的唯一性
            if (!(*returnSize) || num1 != ret[(*returnSize) - 1]) {
                ret[(*returnSize)++] = num1;
            }
            index1++;
            index2++;
        } else if (num1 < num2) {
            index1++;
        } else {
            index2++;
        }
    }
    return ret;
}

int main() {
    int nums1[]    = {4, 9, 5};
    int nums2[]    = {9, 4, 9, 8, 4};
    int nums1Size  = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size  = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize = 0;

    int* ret = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    display(ret, returnSize);

    return 0;
}