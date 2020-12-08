#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

/**
 * 方法一：回溯 + 剪枝
 *  + 回溯
 *      - 根据斐波那契式序列的要求，从第 3 个数开始，每个数都等于前 2 个数的和，因此从第 3 个数开始，
 *        需要判断拆分出的数是否等于前 2 个数的和，只有满足要求时才进行拆分，否则不进行拆分。
 *  + 剪枝
 *      - 拆分出的数如果不是 0，则不能以 0 开头
 *      - 拆分出的数必须符合 32 位有符号整数类型，即每个数必须在 [0, 2^31 − 1] 的范围内
 *      - 如果列表中至少有 2 个数，并且拆分出的数已经大于最后 2 个数的和，就不需要继续尝试拆分了
 */
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backTrack(list, S, S.length(), 0, 0, 0);
        return list;
    }
    bool backTrack(vector<int>& list, string S, int length, int index, long long sum, int prev) {
        if (index == length) {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++) {
            if (i > index && S[index] == '0') {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX) {
                break;
            }
            if (list.size() >= 2) {
                if (curr < sum) {
                    continue;
                } else if (curr > sum) {
                    break;
                }
            }
            list.push_back(curr);
            if (backTrack(list, S, length, i + 1, prev + curr, curr)) {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};

int main() {
    string S = "123456579";

    Solution    s;
    vector<int> ret = s.splitIntoFibonacci(S);
    for (auto num : ret) {
        cout << num << " ";
    }

    return 0;
}