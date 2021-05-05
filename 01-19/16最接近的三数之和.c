#include <math.h>
#include <stdio.h>

// 快速排序
void quickSort(int* nums, int first, int end) {
    int temp, l, r;
    if (first >= end) {
        return;
    }
    temp = nums[first];
    l    = first;
    r    = end;
    while (l < r) {
        while (l < r && nums[r] >= temp) {
            r--;
        }
        if (l < r) {
            nums[l] = nums[r];
        }
        while (l < r && nums[l] <= temp) {
            l++;
        }
        if (l < r) {
            nums[r] = nums[l];
        }
    }
    nums[l] = temp;
    quickSort(nums, first, l - 1);
    quickSort(nums, l + 1, end);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i   = 0;                           //当前数值下标
    int res = nums[0] + nums[1] + nums[2]; //和,初始化

    if (numsSize < 3 || nums == NULL) {
        return NULL;
    }

    quickSort(nums, 0, numsSize - 1); //排序

    for (i = 0; i <= numsSize - 3; i++) {
        int left  = i + 1;                     //左指针
        int right = numsSize - 1;              //右指针
        if (i > 0 && nums[i] == nums[i - 1]) { //去重
            continue;
        }
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(res - target)) { //取最近的和
                res = sum;
            }
            if (sum > target) {
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                right--;
            } else if (sum < target) {
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                left++;
            } else {
                return sum;
            }
        }
    }
    return res;
}

int main() {
    int  num[]    = {1, 1, 1, 1};
    int* nums     = (int*)num;
    int  numsSize = sizeof(num) / sizeof(int);
    int  target   = 100;
    int  sum      = threeSumClosest(nums, numsSize, target);
    printf("%d\n", sum);
    return 0;
}
