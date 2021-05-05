#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一： 计算接壤边
 *  - 周长 = 陆地 * 4 - 接壤边 * 2
 */
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int row   = grid.size();
//         int col   = grid[0].size();
//         int count = 0;
//         int bound = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 0) {
//                     continue;
//                 }
//                 count++;
//                 // 防止边界溢出
//                 if (i + 1 < row && grid[i + 1][j] == 1) {
//                     bound++;
//                 }
//                 if (j + 1 < col && grid[i][j + 1] == 1) {
//                     bound++;
//                 }
//             }
//         }
//         return count * 4 - bound * 2;
//     }
// };

/**
 * 方法二：迭代
 *  - 直接计算边界 
 */
// 下{0, 1}, 右{1, 0}, 上{0, -1}, 左{-1, 0}
// constexpr static int dx[4] = {0, 1, 0, -1};
// constexpr static int dy[4] = {1, 0, -1, 0};
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (grid[i][j]) {
//                     int cnt = 0;
//                     for (int k = 0; k < 4; ++k) {
//                         int tx = i + dx[k];
//                         int ty = j + dy[k];
//                         // 说明不存在接壤，边界 +1
//                         if (tx < 0 || tx >= n || ty < 0 || ty >= m || !grid[tx][ty]) {
//                             cnt += 1;
//                         }
//                     }
//                     ans += cnt;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法三：深度优先搜索
 *  - 题目中规定，只有一个岛屿
 *  - 需要注意的是为了防止陆地格子在深度优先搜索中被重复遍历导致死循环，我们需要将遍历过的陆地格子标记为已经遍历过，下面的代码中我们设定值为 2 的格子为已经遍历过的陆地格子。
 *  - 每当在 DFS 遍历中，从一个岛屿方格走向一个非岛屿方格（水域方格、网格的边界），就将周长加 1
 */
// 特别声明: constexpr static 放在外面，通常情况类的静态成员不应该在类的内部初始化，就算在内部初始化，在类外需要定义
// VSCode 中 g++ 编译放在内部不通过
// LeetCode 提交和 VS 编译放在内部可通过
constexpr static int dx[4] = {0, 1, 0, -1};
constexpr static int dy[4] = {1, 0, -1, 0};
class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 1;
        }
        if (grid[x][y] == 2) {
            return 0;
        }
        grid[x][y] = 2;
        int res    = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 题目中规定，只有一个岛屿，遇到陆地开始深度优先搜索
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };

    Solution s;
    int      ret = s.islandPerimeter(grid);
    cout << ret;

    return 0;
}