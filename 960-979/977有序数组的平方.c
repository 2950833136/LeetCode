#include <math.h>
#include <stdio.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void quickSort(int* nums, int low, int hight) {
    if (low < hight) {
        int key = nums[low];
        int i   = low;
        int j   = hight;
        while (i < j) {
            while (i < j && key >= nums[j]) {
                j--;
            }
            if (i < j) {
                nums[i] = nums[j];
            }

            while (i < j && key <= nums[i]) {
                i++;
            }
            if (i < j) {
                nums[j] = nums[i];
            }
        }
        nums[i] = key;
        quickSort(nums, low, i - 1);
        quickSort(nums, i + 1, hight);
    }
}

int main() {
    int nums[]   = {4, 1, 0, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    display(nums, numsSize);
    quickSort(nums, 0, numsSize-1);
    display(nums, numsSize);

    return 0;
}