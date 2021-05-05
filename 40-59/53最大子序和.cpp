#include <iostream>
#include <vector>
using namespace std;

/**
 * 1. 动态规划
 *      f(i) = max{f(i−1)+nums[i], nums[i]}
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre    = 0;
        int maxAns = nums[0];
        for (auto& num : nums) {
            pre    = max(pre + num, num);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main() {
    Solution    s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}