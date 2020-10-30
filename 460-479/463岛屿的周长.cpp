#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：暴力
 *  - 周长 = 陆地 * 4 - 接壤边 * 2
 */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row   = grid.size();
        int col   = grid[0].size();
        int count = 0;
        int bound = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                count++;
                // 防止边界溢出
                if (i + 1 < row && grid[i + 1][j] == 1) {
                    bound++;
                }
                if (j + 1 < col && grid[i][j + 1] == 1) {
                    bound++;
                }
            }
        }
        return count * 4 - bound * 2;
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