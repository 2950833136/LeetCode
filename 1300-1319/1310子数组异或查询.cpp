#include <iostream>
#include <vector>
using namespace std;

/**
 * 超时 O(nm)
 */
// class Solution {
// public:
//     int xorArr(vector<int>& arr, int begin, int end) {
//         int res = 0;
//         for (int i = begin; i <= end; i++) {
//             res ^= arr[i];
//         }
//         return res;
//     }

//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         vector<int> res;
//         int begin = 0;
//         int end   = 0;
//         for (int i = 0; i < queries.size(); i++) {
//             begin = queries[i][0];
//             end   = queries[i][1];
//             res.push_back(xorArr(arr, begin, end));
//         }
//         return res;
//     }
// };

/**
 * 前缀异或
 * 令 xors[i] = arr[0] ^ ... ^ arr[i-1] 则
 *      Q(left, right) 
 *      = arr[left] ^ ... ^ arr[right]
 *      = xors[left] ^ xors[right + 1]     
 */
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int         n = arr.size();
        int         m = queries.size();
        vector<int> xors(n + 1);
        vector<int> res(m);
        for (int i = 0; i < n; i++) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        for (int i = 0; i < m; i++) {
            res[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }
        return res;
    }
};

int main() {
    vector<int>         arr     = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    Solution            s;

    vector<int> res = s.xorQueries(arr, queries);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}