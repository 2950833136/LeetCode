#include <malloc.h>
#include <stdio.h>

void quickSort(int* nums, int first, int end) { //快速排序
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

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int   sum             = 0;  //和
    int   base_alloc_size = 16; //基本内存
    int** res             = (int**)malloc(sizeof(int*) * base_alloc_size);
    (*returnSize)         = 0;
    *returnColumnSizes    = (int*)malloc(sizeof(int) * base_alloc_size);

    if (numsSize < 4 || nums == NULL) {
        return NULL;
    }

    quickSort(nums, 0, numsSize - 1); //排序

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) { //去重
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) { //去重
                continue;
            }
            int left  = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    res[*returnSize]    = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1]) { //去重
                        left++;
                    }
                    left++;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }

                if (*returnSize == base_alloc_size) { //空间不足，扩充内存
                    base_alloc_size      = base_alloc_size * 2;
                    res                  = (int**)realloc(res, base_alloc_size * sizeof(int*));
                    (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), base_alloc_size * sizeof(int));
                }
            }
        }
    }
    return res;
}

int main() {
    int  num[]      = {1, 0, -1, 0, -2, 2};
    int* nums       = (int*)num;
    int  numsSize   = sizeof(num) / sizeof(int);
    int  target     = 0;
    int* returnSize = (int*)malloc(sizeof(int) * 1);
    //这里的内存分配最大值,即排列组合知识,C几取3
    //C6取3 == 20
    int** returnColumnSizes = (int**)malloc(sizeof(int*) * 1);
    int** res               = fourSum(nums, numsSize, target, returnSize, returnColumnSizes);

    for (int i = 0; i < *returnSize; i++) { //打印
        for (int j = 0; j < 4; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
