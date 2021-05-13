#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        int         maxColumn = min(arrLen - 1, steps);
        vector<int> dp(maxColumn + 1);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> dpNext(maxColumn + 1);
            for (int j = 0; j <= maxColumn; j++) {
                dpNext[j] = dp[j];
                if (j - 1 >= 0) {
                    dpNext[j] = (dpNext[j] + dp[j - 1]) % MODULO;
                }
                if (j + 1 <= maxColumn) {
                    dpNext[j] = (dpNext[j] + dp[j + 1]) % MODULO;
                }
            }
            dp = dpNext;
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    int      steps  = 3;
    int      arrLen = 2;
    cout << s.numWays(steps, arrLen) << endl;

    return 0;
}