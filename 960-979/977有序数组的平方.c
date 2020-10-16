#include <malloc.h>
#include <stdio.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * 方法一：计算后，排序
 */
// void quickSort(int* nums, int low, int hight) {
//     if (low < hight) {
//         int key = nums[low];
//         int i   = low;
//         int j   = hight;
//         while (i < j) {
//             while (i < j && key <= nums[j]) {
//                 j--;
//             }
//             if (i < j) {
//                 nums[i] = nums[j];
//             }

//             while (i < j && key >= nums[i]) {
//                 i++;
//             }
//             if (i < j) {
//                 nums[j] = nums[i];
//             }
//         }
//         nums[i] = key;
//         quickSort(nums, low, i - 1);
//         quickSort(nums, i + 1, hight);
//     }
// }

// int* sortedSquares(int* A, int ASize, int* returnSize) {
//     for (int i = 0; i < ASize; i++) {
//         A[i] = A[i] * A[i];
//     }
//     quickSort(A, 0, ASize - 1);
//     *returnSize = ASize;
//     return A;
// }

/**
 * 方法二：
 *  判断绝对值最大值（左右两边最大），额外数组然后进行向前填充
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int  index  = ASize - 1;
    int* left   = A;
    int* right  = A + index;
    int* ans    = (int*)malloc(sizeof(int) * ASize);
    while (left <= right) {
        *left  = *left > 0 ? *left : *left * -1;
        *right = *right > 0 ? *right : *right * -1;
        if (*left > *right) {
            ans[index--] = *left * (*left);
            *left++;
        } else {
            ans[index--] = *right * (*right);
            *right--;
        }
    }
    return ans;
}

int main() {
    int nums[]     = {-4, -1, 0, 3, 10};
    int numsSize   = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    display(nums, numsSize);
    int* ans = sortedSquares(nums, numsSize, &returnSize);
    display(ans, returnSize);

    return 0;
}