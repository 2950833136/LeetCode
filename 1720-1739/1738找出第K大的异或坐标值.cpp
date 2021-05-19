#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 异或 前缀和
 *      为了使其不讨论边界情况，我们在数组的左边与上边插入一排0(惯用手法)。
 */
class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        vector<int>         res;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                res.push_back(pre[i][j]);
            }
        }
        sort(res.begin(), res.end(), greater<int>());
        return res[k - 1];
    }
};

int main() {
    vector<vector<int>> matrix = {
        { 5, 2 },
        { 1, 6 }
    };
    int      k = 1;
    Solution s;
    cout << s.kthLargestValue(matrix, k) << endl;

    return 0;
}