#include <malloc.h>
#include <stdio.h>
#include <string.h>

/**
 * candidates 中的每个数字在每个组合中只能使用一次
 * 算法思想：排序 + DFS + 回溯
 *  1、初始化参数
 *      returnSize:     表示第几组路径
 *      ret:            保存每条路径
 *      eachItem:       用于保存单条路径
 *      eachItemIndex:  表示当前路径中的元素个数
 *      level:          (ilevel + 1) 排除之前包括自己的数    
 *  2、DFS进行遍历时
 *      先对 target 进行判断
 *      - 若 target > 0 时，将所有满足 target - candidates[i] >= 0 的元素加入，继续执行DFS 
 *      - 若 target < 0 时，则直接剪枝返回
 *  3、需要注意的是，由于不能出现相同的组合，所以设置一个 level
 *      - 排序后，从该数之后开始选择，每次执行时都不会选择之前的数，防止重复
 *      - (i + 1)，表示从下一位计算，不包括自己。
 */
#define MAX_RET 1000

void QuickSort(int array[], int low, int high) {
    int i   = low;
    int j   = high;
    int key = array[i];
    if (low < high) {
        while (i < j) {
            while (i < j && array[j] >= key) {
                j--;
            }
            if (i < j) {
                array[i] = array[j];
            }
            while (i < j && array[i] <= key) {
                i++;
            }
            if (i < j) {
                array[j] = array[i];
            }
        }
        array[i]     = key;
        int standard = i;
        QuickSort(array, low, standard - 1);
        QuickSort(array, standard + 1, high);
    }
}

void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int* columnSizes, int** ret, int* eachItem, int eachItemIndex, int level) {
    if (target == 0 && eachItemIndex != 0) {
        ret[*returnSize] = (int*)calloc(eachItemIndex, sizeof(int));
        memcpy(ret[*returnSize], eachItem, eachItemIndex * sizeof(int));
        columnSizes[*returnSize] = eachItemIndex;
        (*returnSize)++;
        return;
    }
    for (int i = level; i < candidatesSize; i++) {
        if (target < 0) {
            return;
        }
        eachItem[eachItemIndex] = candidates[i];
        // i 确保无重复组合
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, columnSizes, ret, eachItem, eachItemIndex + 1, i + 1);
        while (i + 1 < candidatesSize && candidates[i] == candidates[i + 1]) {
            i++;
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    //特殊情况
    if (candidates == NULL || candidatesSize <= 0) {
        return NULL;
    }
    int** ret           = (int**)calloc(MAX_RET, sizeof(int*));
    int*  columnSizes   = (int*)calloc(MAX_RET, sizeof(int));
    int*  eachItem      = (int*)calloc(MAX_RET, sizeof(int));
    int   eachItemIndex = 0;
    QuickSort(candidates, 0, candidatesSize - 1);
    dfs(candidates, candidatesSize, target, returnSize, columnSizes, ret, eachItem, eachItemIndex, 0);
    *returnColumnSizes = columnSizes;
    return ret;
}

int main() {
    int   candidates[]      = {10, 1, 2, 7, 6, 1, 5};
    int   candidatesSize    = sizeof(candidates) / sizeof(candidates[0]);
    int   target            = 8;
    int*  returnSize        = (int*)calloc(MAX_RET, sizeof(int));
    int** returnColumnSizes = (int**)calloc(MAX_RET, sizeof(int*));
    int** ret               = (int**)calloc(MAX_RET, sizeof(int*));

    ret = combinationSum2(candidates, candidatesSize, target, returnSize, returnColumnSizes);
    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < *(*returnColumnSizes + i); j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}