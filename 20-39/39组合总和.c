#include <malloc.h>
#include <stdio.h>
#include <string.h>

/**
 * 算法思想：DFS + 回溯
 *  1、初始化参数
 *      returnSize:     表示第几组路径
 *      ret:            保存每条路径
 *      eachItem:       用于保存单条路径
 *      eachItemIndex:  表示当前路径中的元素个数
 *      level:          防止选择之前的数，当前数下标
 *  2、DFS进行遍历时
 *      先对 target 进行判断
 *      若 target > 0 时，将所有满足 target - candidates[i] >= 0 的元素加入，继续执行DFS
 *      若 target < 0 时，则直接剪枝返回
 *  3、需要注意的是，由于不能出现相同的组合，所以设置一个 level 表示从该数之后开始选择，每次执行时都不会选择之前的数，防止重复
 */
#define MAX_RET 1000

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
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, columnSizes, ret, eachItem, eachItemIndex + 1, i);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (candidates == NULL || candidatesSize <= 0) {
        return NULL;
    }
    int** ret           = (int**)calloc(MAX_RET, sizeof(int*));
    int*  columnSizes   = (int*)calloc(MAX_RET, sizeof(int));
    int*  eachItem      = (int*)calloc(MAX_RET, sizeof(int));
    int   eachItemIndex = 0;
    dfs(candidates, candidatesSize, target, returnSize, columnSizes, ret, eachItem, eachItemIndex, 0);
    *returnColumnSizes = columnSizes;
    return ret;
}

int main() {
    int   candidates[]      = {2, 3, 5};
    int   candidatesSize    = sizeof(candidates) / sizeof(candidates[0]);
    int   target            = 8;
    int*  returnSize        = (int*)calloc(MAX_RET, sizeof(int));
    int** returnColumnSizes = (int**)calloc(MAX_RET, sizeof(int*));
    int** ret               = (int**)calloc(MAX_RET, sizeof(int*));

    ret = combinationSum(candidates, candidatesSize, target, returnSize, returnColumnSizes);
    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < *(*returnColumnSizes + i); j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
