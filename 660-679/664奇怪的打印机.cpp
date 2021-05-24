#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i][j] 代表的是字符串在区间 [i,j] 中需要最少的打印次数
 *  打印一个字符串的次数为 1，因此 dp[i][i] = 1 
 *  判断是否两边区间字符相等 s[i] == s[j]
 *      如果相等，打印次数可以从子区间的打印次数转移而来 dp[i][j] = dp[i][j-1]
 *      如果不相等，则枚举所有的可能组合，然后取其最优解
 */
class Solution {
public:
    int strangePrinter(string s) {
        int                 n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    string   str = "aaabbb";
    Solution s;
    cout << s.strangePrinter(str) << endl;

    return 0;
}