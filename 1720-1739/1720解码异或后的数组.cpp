#include <iostream>
#include <vector>
using namespace std;

/**
 * 前一位和加密后的异或得到后一位
 */
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res{first};
        for (auto num : encoded) {
            res.push_back(num ^ res.back());
        }
        return res;
    }
};

int main() {
    Solution    s;
    vector<int> encoded = {6, 2, 7, 3};
    int         first   = 4;
    vector<int> res     = s.decode(encoded, first);
    for (auto num : res) {
        cout << num;
    }

    return 0;
}