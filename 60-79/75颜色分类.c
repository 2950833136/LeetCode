#include <stdio.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * 单指针
 *  index 为新数组的下标
 *  第一次遍历将 0 交换到前面（index 增加）
 *  第二次遍历将 1 交换到前面（index 增加此时在 0 后面）
 *  此时排序好了，后面的都是 2
 */
// void sortColors(int* nums, int numsSize) {
//     int index = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] == 0) {
//             swap(&nums[i], &nums[index]);
//             index++;
//         }
//     }
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] == 1) {
//             swap(&nums[i], &nums[index]);
//             index++;
//         }
//     }
// }

/**
 * 双指针
 *  把 0 往前交换，l++
 *  把 2 往后交换，交换后，还要再判断交换来的数值，r-- i--
 */
void sortColors(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    for (int i = 0; i <= r; i++) {
        if (nums[i] == 0) {
            swap(&nums[l], &nums[i]);
            l++;
        } else if (nums[i] == 2) {
            swap(&nums[i], &nums[r]);
            r--;
            i--;
        }
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    display(nums, numsSize);
    sortColors(nums, numsSize);
    display(nums, numsSize);

    return 0;
}