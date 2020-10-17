#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

void display(char*** pRet, int* pRetSize, int n) {
    for (int i = 0; i < *pRetSize; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%c ", pRet[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
/**
 * 回溯法
 *  + 判定一个皇后是否能够放下的条件：行，列，正反斜线都不能有其他的皇后存在
 *      - 一行一行的写入，所以行不会重复
 *      - visited[]，记录皇后写入的列位置
 *      + 判断条件（等于表示重复）
 *          - 列不重复          col       ? visited[i]
 *          - 主对角线不重复    row - col ? i - visited[i]
 *          - 副对角线不重复    row + col ? i + visited[i]
 *      - 重复就回溯，不重复递归
 *      - 最后 row == n 表示满足所有条件，记录信息
 */
bool check(int* visited, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (col == visited[i] || row - col == i - visited[i] || row + col == i + visited[i]) {
            return false;
        }
    }
    return true;
}

void backtrack(int n, int row, int* visited, char*** result, int* returnSize) {
    if (row == n) {
        result[*returnSize] = (char**)malloc(sizeof(char*) * n);
        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = (char*)calloc(n + 1, sizeof(char));
            memset(result[*returnSize][i], '.', n);
            result[*returnSize][i][visited[i]] = 'Q';
        }
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check(visited, row, i)) {
            continue;
        }
        visited[row] = i;
        backtrack(n, row + 1, visited, result, returnSize);
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize     = 0;
    int*    visited = (int*)calloc(n, sizeof(int));
    char*** result  = (char***)malloc(sizeof(char**) * n * n * n);
    backtrack(n, 0, visited, result, returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}

int main() {
    int   n                 = 4;
    int*  returnSize        = (int*)malloc(sizeof(int));
    int** returnColumnSizes = (int**)malloc(sizeof(int*));

    char*** ans = solveNQueens(n, returnSize, returnColumnSizes);
    display(ans, returnSize, n);

    return 0;
}