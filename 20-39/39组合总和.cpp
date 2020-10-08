#include <malloc.h>
#include <stdio.h>
#include <string.h>

/**
 * 算法思想：DFS + 回溯
 *  1、初始化参数
 *      group:  表示第几组路径
 *      result: 保存每条路径
 *      path:   用于保存路径
 *      num:    表示当前路径中的元素个数
 *      level:  防止选择之前的数
 *  2、DFS进行遍历时
 *      先对 target 进行判断
 *      若 target > 0 时，将所有满足 target - candidates[i] >= 0 的元素加入，继续执行DFS
 *      若 target < 0 时，则直接剪枝返回
 *  3、需要注意的是，由于不能出现相同的组合，所以设置一个 level 表示从该数之后开始选择，每次执行时都不会选择之前的数，防止重复
 */
#define MAX_RET 1000

void dfs(int* candidates, int candidatesSize, int target, int* group, int** returnColumnSizes, int** result, int* path, int num, int level) {
    if (target == 0) {
        result[*group] = (int*)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            result[*group][i] = path[i];
        }
        (*returnColumnSizes)[*group] = num;
        (*group)++;
        return;
    }
    for (int i = level; i < candidatesSize; i++) {
        if (target < 0) {
            return;
        }
        path[num] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], group, returnColumnSizes, result, path, num + 1, i);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_RET);
    int   group        = 0;
    int** result       = (int**)malloc(sizeof(int*) * MAX_RET);
    int*  path         = (int*)malloc(sizeof(int) * MAX_RET);
    dfs(candidates, candidatesSize, target, &group, returnColumnSizes, result, path, 0, 0);
    *returnSize = group;
    return result;
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