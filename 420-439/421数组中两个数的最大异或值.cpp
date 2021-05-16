#include <iostream>
#include <vector>
using namespace std;

/**
 * 暴力超时
 */
// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int         len = nums.size();
//         vector<int> temp;
//         int         res = 0;

//         for (int i = 0; i < len - 1; i++) {
//             for (int j = i + 1; j < len; j++) {
//                 temp.push_back(nums[i] ^ nums[j]);
//                 res = max(res, temp.back());
//             }
//         }
//         return res;
//     }
// };

/**
 * 排序，剪枝 
 */
// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         long long maxValue = 0;
//         for (int i = n -1; i >= 1; i--) {
//             for (int j = i -1; j >= 0; j--) {
//                 if ((long long)(nums[i]) + nums[j] < maxValue) {
//                     break;
//                 }
//                 maxValue = max(maxValue, (long long)(nums[i] ^ nums[j]));
//             }
//         }
//         return maxValue;
//     }
// };

/**
 * 字典树
 */
struct Trie {
    // 左子树指向表示 0 的子节点
    Trie* left = nullptr;
    // 右子树指向表示 1 的子节点
    Trie* right = nullptr;

    Trie() {}
};

class Solution {
private:
    // 字典树的根节点
    Trie* root = new Trie();
    // 最高位的二进制位编号为 30
    static constexpr int HIGH_BIT = 30;

public:
    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = new Trie();
                }
                cur = cur->left;
            }
            else {
                if (!cur->right) {
                    cur->right = new Trie();
                }
                cur = cur->right;
            }
        }
    }

    int check(int num) {
        Trie* cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                // a_i 的第 k 个二进制位为 0，应当往表示 1 的子节点 right 走
                if (cur->right) {
                    cur = cur->right;
                    x = x * 2 + 1;
                }
                else {
                    cur = cur->left;
                    x = x * 2;
                }
            }
            else {
                // a_i 的第 k 个二进制位为 1，应当往表示 0 的子节点 left 走
                if (cur->left) {
                    cur = cur->left;
                    x = x * 2 + 1;
                }
                else {
                    cur = cur->right;
                    x = x * 2;
                }
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            // 将 nums[i-1] 放入字典树，此时 nums[0 .. i-1] 都在字典树中
            add(nums[i - 1]);
            // 将 nums[i] 看作 ai，找出最大的 x 更新答案
            x = max(x, check(nums[i]));
        }
        return x;
    }
};

int main() {
    Solution    s;
    vector<int> nums = {8, 10, 2};

    cout << s.findMaximumXOR(nums) << endl;

    return 0;
}