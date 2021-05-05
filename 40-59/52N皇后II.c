#include <stdio.h>

/**
 * 位运算
 *  + 判定一个皇后是否能够放下的条件：行，列，正反斜线都不能有其他的皇后存在
 *      + 所有初始为 0，例如 n=4:
 *          - 列        col   0000
 *          - 主对角线  d1    0000
 *          - 副对角线  d2    0000
 *      + 每行写入，行默认不会重复
 *          - 如果有重复，~(columns | diagonals1 | diagonals2) 的值就不是最大的，就不能递归到 row==n
 */
int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
        return 1;
    } else {
        int count              = 0;
        int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
        while (availablePositions != 0) {
            int position       = availablePositions & (-availablePositions);
            availablePositions = availablePositions & (availablePositions - 1);
            count += solve(n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
        }
        return count;
    }
}

int totalNQueens(int n) {
    return solve(n, 0, 0, 0, 0);
}

int main() {
    int n   = 8;
    int ans = totalNQueens(n);
    printf("%d", ans);

    return 0;
}