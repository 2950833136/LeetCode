#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> vec) {
    for (auto i : vec) {
        for (auto j : i) {
            cout << setw(4) << j << " ";
        }
        cout << endl;
    }
}

/**
 * 方法一：数学
 *  - 第几行就有几项
 *  - 最左侧和最右侧是 1
 *  - 中间 = 行上一项 + 行上一项列上一项
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; i++) {
            ret[i].resize(i + 1);
            ret[i][0] = 1;
            ret[i][i] = 1;
            for (int j = 1; j < i; j++) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};

int main() {
    int numRows = 10;

    Solution            s;
    vector<vector<int>> ret = s.generate(numRows);
    display(ret);

    return 0;
}