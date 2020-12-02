#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/***************************************************************************
 * @date   2020/12/02
 * @brief  比较子数组数值大小
 * @param  subseq       子数组
 * @param  subseqSize   子数组大小
 * @param  index        子数组下标
 * @return difference   两个数组的差值
 ***************************************************************************/
int compare(int* subseq1, int subseq1Size, int index1, int* subseq2, int subseq2Size, int index2) {
    while (index1 < subseq1Size && index2 < subseq2Size) {
        int difference = subseq1[index1] - subseq2[index2];
        if (difference != 0) {
            return difference;
        }
        index1++;
        index2++;
    }
    // 某个数组遍历结束
    return (subseq1Size - index1) - (subseq2Size - index2);
}

/***************************************************************************
 * @date   2020/12/02
 * @brief  合并数组，以最大排序
 * @param  subseq       子数组
 * @param  subseqSize   子数组大小
 * @return merged       合并后最大数组
 ***************************************************************************/
int* merge(int* subseq1, int subseq1Size, int* subseq2, int subseq2Size) {
    if (subseq1Size == 0) {
        return subseq2;
    }
    if (subseq2Size == 0) {
        return subseq1;
    }
    int  mergeLength = subseq1Size + subseq2Size;
    int* merged      = malloc(sizeof(int) * (subseq1Size + subseq2Size));
    int  index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++) {
        if (compare(subseq1, subseq1Size, index1, subseq2, subseq2Size, index2) > 0) {
            merged[i] = subseq1[index1++];
        } else {
            merged[i] = subseq2[index2++];
        }
    }
    return merged;
}

/***************************************************************************
 * @date   2020/12/02
 * @brief  获取数组中指定个数的最大子数组
 * @param  nums     原数组
 * @param  numsSize 原数组大小
 * @param  k        指定个数
 * @return stack    最大子数组
 ***************************************************************************/
int* MaxSubsequence(int* nums, int numsSize, int k) {
    int* stack = malloc(sizeof(int) * k);
    memset(stack, 0, sizeof(int) * k);
    int top = -1;
    // 剩余个数
    int remain = numsSize - k;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while (top >= 0 && stack[top] < num && remain > 0) {
            top--;
            remain--;
        }
        if (top < k - 1) {
            stack[++top] = num;
        } else {
            remain--;
        }
    }
    return stack;
}

void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b, *b = tmp;
}

/**
 * 1．要使构成的数字最大，就要使从左到右的每一位尽可能的最大，即单调递减
 * 2．枚举所有情况，即从两个数组分别取 i,j 个元素，并且 i+j= k，然后再进行合并
 * 3．从一个数组中以相对顺序取 i 个元素使构成的数字最大，可用单调栈；当剩余元素不足以做挑选时，只能都取
 * 4．要使两个数组合并后构成的数字最大，每一位尽可能取最大值，若当前位置值一样，那就保证下一位最大
 */
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    *returnSize         = k;
    int* maxSubsequence = malloc(sizeof(int) * k);
    memset(maxSubsequence, 0, sizeof(int) * k);

    int start = fmax(0, k - nums2Size);
    int end   = fmin(k, nums1Size);
    for (int i = start; i <= end; i++) {
        int* subseq1           = MaxSubsequence(nums1, nums1Size, i);
        int* subseq2           = MaxSubsequence(nums2, nums2Size, k - i);
        int* curMaxSubsequence = merge(subseq1, i, subseq2, k - i);
        if (compare(curMaxSubsequence, k, 0, maxSubsequence, k, 0) > 0) {
            swap(&curMaxSubsequence, &maxSubsequence);
        }
    }
    return maxSubsequence;
}

int main() {
    int nums1[]    = {3, 4, 6, 5};
    int nums1Size  = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[]    = {9, 1, 2, 5, 8, 3};
    int nums2Size  = sizeof(nums2) / sizeof(nums2[0]);
    int k          = 5;
    int returnSize = 0;

    int* ret = maxNumber(nums1, nums1Size, nums2, nums2Size, k, &returnSize);
    display(ret, returnSize);

    return 0;
}