#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划
 *  - f(i,j)=f(i−1,j)+f(i,j−1)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> step(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            step[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            step[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                step[i][j] = step[i - 1][j] + step[i][j - 1];
            }
        }
        return step[m - 1][n - 1];
    }
};

/**
 * 组合数学
 *  - 从左上角到右下角的过程中，我们需要移动 m+n-2 次，其中有 m-1 次向下移动，n-1 次向右移动。
 */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         long long ans = 1;
//         for (int x = n, y = 1; y < m; ++x, ++y) {
//             ans = ans * x / y;
//         }
//         return ans;
//     }
// };

int main() {
    int m = 3;
    int n = 3;

    Solution s;
    int      ret = s.uniquePaths(m, n);
    cout << ret << endl;

    return 0;
}