#include <algorithm>
#include <iostream>
#include <limits.h>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 方法一：模拟
 *  - 无论哪一种情况，我们都将 b1=t 变成了选择任务 a 的时间点，
 *  - 并且由于我们只在任务 a 和 b 的内部进行交换，因此交换后总时间一定不会增加。
 *  - 这样就证明了一定存在一种总时间最少的方法，是通过不断地选择不在冷却中并且剩余执行次数最多的那个任务得到的。
 */
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         unordered_map<char, int> freq;
//         for (char ch : tasks) {
//             ++freq[ch];
//         }

//         // 任务总数
//         int         m = freq.size();
//         vector<int> nextValid, rest;
//         for (auto [_, v] : freq) {
//             nextValid.push_back(1);
//             rest.push_back(v);
//         }

//         int time = 0;
//         for (int i = 0; i < tasks.size(); ++i) {
//             ++time;
//             int minNextValid = INT_MAX;
//             for (int j = 0; j < m; ++j) {
//                 if (rest[j]) {
//                     minNextValid = min(minNextValid, nextValid[j]);
//                 }
//             }
//             time     = max(time, minNextValid);
//             int best = -1;
//             for (int j = 0; j < m; ++j) {
//                 if (rest[j] && nextValid[j] <= time) {
//                     if (best == -1 || rest[j] > rest[best]) {
//                         best = j;
//                     }
//                 }
//             }
//             nextValid[best] = time + n + 1;
//             --rest[best];
//         }

//         return time;
//     }
// };

/**
 * 方法二：构造
 * 
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
                          return u.second < v.second;
                      })->second;
        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};

int main() {
    Solution     s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int          n     = 2;

    int ret = s.leastInterval(tasks, n);
    printf("%d\n", ret);

    return 0;
}