#include <iostream>
#include <vector>
using namespace std;

/**
 * 原理
 *  S_{i} = S_{i-1} ^ arr_{i-1}
 *      所以 [i, j) 区间的异或，相当于 S_{i} ^ S_{j}
 *      同理 [j, k] 区间的异或，相当于 S_{j} ^ S_{k+1}
 *  a == b
 *      S_{i} ^ S_{j} = S_{j} ^ S_{k+1}
 *  S_{i} == S_{k+1}
 */

/**
 * 三重循环
 * 两重循环     简化后与 j 没有关系       
 */
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int         n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] ^ arr[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if (s[i] == s[k + 1]) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> arr = {2, 3, 1, 6, 7};
    Solution    s;
    cout << s.countTriplets(arr) << endl;

    return 0;
}