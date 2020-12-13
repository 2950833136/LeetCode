#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * hash
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            }
            hash.insert(nums[i]);
        }
        return false;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 1};

    Solution s;
    if (s.containsDuplicate(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}