#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for (int i = 1; i < n; i++) {
            res ^= start + 2 * i;
        }
        return res;
    }
};

int main() {
    Solution s;
    int      n     = 4;
    int      start = 3;
    cout << s.xorOperation(n, start);
    return 0;
}