#include <stdio.h>

void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
}

int main() {
    int nums[]   = {1, 1, 0, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    display(nums, numsSize);

    return 0;
}