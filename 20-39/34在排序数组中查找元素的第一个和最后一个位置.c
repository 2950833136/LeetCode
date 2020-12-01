#include <malloc.h>
#include <stdio.h>

/**
 * 双指针遍历
 */
// int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
//     int* ret = (int*)malloc(sizeof(int) * 2);
//     ret[0] = -1, ret[1] = -1;
//     int i = 0, j = numsSize - 1;
//     while (i <= j) {
//         if (nums[i] == target) {
//             ret[0] = i;
//         } else {
//             i++;
//         }
//         if (nums[j] == target) {
//             ret[1] = j;
//         } else {
//             j--;
//         }
//         if (ret[0] != -1 && ret[1] != -1) {
//             break;
//         }
//     }
//     *returnSize = 2;
//     return ret;
// }

/**
 * 二分查找法
 * 找到中间，向两边查找边界
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;
    *returnSize     = 2;
    if (numsSize == 0) {
        return ret;
    }
    int l = 0, r = numsSize - 1, mid = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) {
            break;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l = r = mid;
    while (l >= 0 && nums[l] == target) {
        ret[0] = l;
        l--;
    }
    while (r <= numsSize - 1 && nums[r] == target) {
        ret[1] = r;
        r++;
    }
    return ret;
}

/**
 * 二分查找法
 * 直接查找两个边界
 */
// int extremeInsertionIndex(int* nums, int numsSize, int target, bool left) {
//     int l   = 0;
//     int r   = numsSize - 1;
//     int mid = 0;
//     while (l <= r) {
//         mid = (l + r) / 2;
//         if (nums[mid] == target) {
//             left ? (r = mid - 1) : (l = mid + 1);
//         } else if (nums[mid] < target) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     return l;
// }

// int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
//     int* targetRange = (int*)malloc(sizeof(int) * 2);
//     targetRange[0] = targetRange[1] = -1;
//     *returnSize                     = 2;
//     if (numsSize == 0) {
//         return targetRange;
//     }

//     int leftIdx = extremeInsertionIndex(nums, numsSize, target, true);
//     if (leftIdx == -1 || leftIdx == numsSize || nums[leftIdx] != target) {
//         return targetRange;
//     }
//     int rightIdx   = extremeInsertionIndex(nums, numsSize, target, false);
//     targetRange[0] = leftIdx;
//     targetRange[1] = rightIdx - 1;
//     return targetRange;
// }

int main() {
    int  nums[]     = {2, 2};
    int  numsSize   = sizeof(nums) / sizeof(int);
    int  target     = -1;
    int* returnSize = (int*)malloc(sizeof(int));

    int* ret = (int*)malloc(sizeof(int) * 2);
    ret      = searchRange(nums, numsSize, target, returnSize);
    printf("[%d, %d]", ret[0], ret[1]);

    return 0;
}