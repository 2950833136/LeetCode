#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 方法一：哈希表 + 最小堆
 *  - 由于需要将数组分割成一个或多个由连续整数组成的子序列，因此只要知道子序列的最后一个数字和子序列的长度，就能确定子序列。
 *  - 当 x 在数组中时，如果存在一个子序列以 x−1 结尾，长度为 k，则可以将 x 加入该子序列中，得到长度为 k+1 的子序列。
 *    如果不存在以 x−1 结尾的子序列，则必须新建一个只包含 x 的子序列，长度为 1。
 *  - 当 x 在数组中时，如果存在多个子序列以 x−1 结尾，应该将 x 加入其中的哪一个子序列？
 *    由于题目要求每个子序列的长度至少为 3，显然应该让最短的子序列尽可能长，因此应该将 x 加入其中最短的子序列。
 */
// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         // 无序散列表，指向优先队列（由大到小）
//         unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
//         // 遍历数组
//         for (auto& x : nums) {
//             // 如果等于结尾就根据优先队列新建一个无序散列
//             if (mp.find(x) == mp.end()) {
//                 mp[x] = priority_queue<int, vector<int>, greater<int>>();
//             }
//             // 如果结尾刚好比数据小 1，找到最短加入
//             if (mp.find(x - 1) != mp.end()) {
//                 // 因为由大到小排列，所以取出的是最短的
//                 int prevLength = mp[x - 1].top();
//                 mp[x - 1].pop();
//                 if (mp[x - 1].empty()) {
//                     mp.erase(x - 1);
//                 }
//                 mp[x].push(prevLength + 1);
//             } else {
//                 mp[x].push(1);
//             }
//         }
//         // 判断长度
//         for (auto it = mp.begin(); it != mp.end(); ++it) {
//             priority_queue<int, vector<int>, greater<int>> queue = it->second;
//             if (queue.top() < 3) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

/**
 * 方法二：贪心
 *  - 题目要求分割成的子序列的长度都不小于 33，因此应该尽量避免新建短的子序列。
 *  - 使用两个哈希表，第一个哈希表存储数组中的每个数字的剩余次数，第二个哈希表存储数组中的每个数字作为结尾的子序列的数量。
 *  - 
 */
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;

        // 计数
        for (auto& x : nums) {
            int count   = countMap[x] + 1;
            countMap[x] = count;
        }
        for (auto& x : nums) {
            int count = countMap[x];
            if (count > 0) {
                int prevEndCount = endMap[x - 1];
                if (prevEndCount > 0) {
                    countMap[x]   = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x]     = endMap[x] + 1;
                } else {
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0) {
                        countMap[x]     = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2]   = endMap[x + 2] + 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

/**
 * [【最优贪心解法】O(N) 时间 + O(1) 空间](https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/tan-xin-o1-kong-jian-fu-za-du-de-zui-you-jie-fa-by/)
 */
// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         int n   = nums.size();
//         int dp1 = 0, dp2 = 0, dp3 = 0;
//         int i = 0;

//         while (i < n) {
//             int start = i;
//             int x     = nums[i];
//             while (i < n && nums[i] == x) {
//                 i++;
//             }
//             int cnt = i - start;

//             if (start > 0 && x != nums[start - 1] + 1) {
//                 if (dp1 + dp2 > 0) {
//                     return false;
//                 } else {
//                     dp1 = cnt;
//                     dp2 = dp3 = 0;
//                 }
//             } else {
//                 if (dp1 + dp2 > cnt)
//                     return false;
//                 int left = cnt - dp1 - dp2;
//                 int keep = min(dp3, left);
//                 dp3      = keep + dp2;
//                 dp2      = dp1;
//                 dp1      = left - keep;
//             }
//         }
//         return dp1 == 0 && dp2 == 0;
//     }
// };

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 5};

    Solution s;
    bool     ret = s.isPossible(nums);
    if (ret) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}