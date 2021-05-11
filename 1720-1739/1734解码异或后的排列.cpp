#include <iostream>
#include <vector>
using namespace std;

/**
 * 1. 其中 n 是奇数
 * 2. 为了表达的方便，可以这么定义：将 A XOR B（A和B进行异或运算）简写为AB
 *      既然我们知道了perm = [A, B, C, D, E]，那么encoded = [AB, BC, CD, DE]；
 *      根据perm，我们可以得到ABCDE,根据encoded的BC和DE，我们可以得到BCDE；
 *      将ABCDE和BCDE进行异或运算，得到A，即perm的第一个元素。
 * 3. 由于数组 perm 是前 n 个正整数的排列，因此数组 perm 的全部元素的异或运算结果即为从 1 到 n 的全部正整数的异或运算结果
 */
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n     = encoded.size() + 1;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total ^= i;
        }
        int odd = 0;
        for (int i = 1; i < n - 1; i += 2) {
            odd ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = total ^ odd;
        for (int i = 0; i < n - 1; i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        return perm;
    }
};

int main() {
    Solution    s;
    vector<int> encoded = {6, 5, 4, 6};

    vector<int> decoded = s.decode(encoded);
    for (auto n : decoded) {
        cout << n << " ";
    }
    return 0;
}