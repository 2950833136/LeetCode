#include <iostream>
#include <vector>
using namespace std;

/**
 * 困难题   数学推导，证明
 * 当且仅当以下两个条件至少满足一个时，Alice 必胜
 *      数组 nums 的全部元素的异或结果等于 0
 *      数组 nums 的长度是偶数
 */
class Solution {
public:
    bool xorGame(vector<int> &nums) {
        if (nums.size() % 2 == 0) {
            return true;
        }
        int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }
        return xorsum == 0;
    }
};

int main() {
    vector<int> nums = { 1, 1, 2 };
    Solution    s;
    cout << s.xorGame(nums) << endl;

    return 0;
}