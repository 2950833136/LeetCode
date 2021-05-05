#include <iostream>
#include <vector>
using namespace std;

/**
 * 贪心
 *  + 给定一个翻转方案，则它们之间任意交换顺序后，得到的结果保持不变。
 *      - 因此，我们总可以先考虑所有的行翻转，再考虑所有的列翻转。
 *  + 为了得到最高的分数，矩阵的每一行的最左边的数都必须为 1。
 *      - 为了做到这一点，我们可以翻转那些最左边的数不为 1 的那些行，而其他的行则保持不动。
 *  + 当将每一行的最左边的数都变为 1 之后，就只能进行列翻转了。
 *      - 为了使得总得分最大，我们要让每个列中 1 的数目尽可能多。
 *      - 因此，我们扫描除了最左边的列以外的每一列，如果该列 0 的数目多于 1 的数目，就翻转该列，其他的列则保持不变。
 */
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        // 先计算出第一位全部为 1 的值
        int ret = m * (1 << (n - 1));
        for (int j = 1; j < n; j++) {
            int nOnes = 0;
            for (int i = 0; i < m; i++) {
                // 判断该 i 行最左边是否翻转
                // nOnes += A[i][0] ^ A[i][j]; // 明显更简单，但耗时还长
                if (A[i][0] == 1) {
                    nOnes += A[i][j];
                } else {
                    nOnes += (1 - A[i][j]); // 如果这一行进行了行反转，则该元素的实际取值为 1 - A[i][j]
                }
            }
            // nOnes: 记录 1 个数， (m - nOnes): 记录 0 的个数，可以翻转所以取最大即可
            int k = max(nOnes, m - nOnes);
            // 每列的值
            ret += k * (1 << (n - j - 1));
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> A = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
    };

    Solution s;
    int      ret = s.matrixScore(A);
    cout << ret << endl;

    return 0;
}