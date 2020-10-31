#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * hash 表
 *      - 利用哈希结构 unordered_map<int, unordered_set<int> > index 存储值对应的下标集合
 *      - 利用 vector<int> nums 存储所有的数字
 *      - 删除的时候利用尾部向前替换待删除的数字，然后进行尾部删除，使得删除操作可以做到 O(1)
 */
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> index;
    vector<int>                            nums;
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // nums 尾部插入数据
        // index hash放入数据，以数据充当下标，在 nums 中的下标充当值
        nums.push_back(val);
        index[val].insert(nums.size() - 1);
        return index[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 不存在返回 false
        if (index.find(val) == index.end()) {
            return false;
        }
        // 从 val 对应的 index 集合中取出首个元素
        int i = *(index[val].begin());
        // 尾部覆盖当前元素
        nums[i] = nums.back();
        // index 集合中删除 val，被覆盖的元素
        index[val].erase(i);
        // 因为 nums 修改了，index 也要修改，删除 nums[i] 用来覆盖的元素，下标变了
        index[nums[i]].erase(nums.size() - 1);
        // 重新插入 nums[i] 元素，
        if (i < nums.size() - 1) {
            index[nums[i]].insert(i);
        }
        // 该元素集合为 0，删除这一元素集合
        if (index[val].size() == 0) {
            index.erase(val);
        }
        // nums 删除最后一个
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main() {
    vector<string> cmd  = {"RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"};
    vector<int>    nums = {0, 1, 1, 2, 0, 1, 0};
    int            len  = cmd.size();

    RandomizedCollection* obj = new RandomizedCollection();
    for (int i = 0; i < len; i++) {
        if (0 == cmd[i].compare("RandomizedCollection")) {
            cout << "null ";
            continue;
        } else if (0 == cmd[i].compare("insert")) {
            bool param_1 = obj->insert(nums[i]);
            cout << (param_1 == 1 ? "true" : "false") << " ";
        } else if (0 == cmd[i].compare("remove")) {
            bool param_2 = obj->remove(nums[i]);
            cout << (param_2 == 1 ? "true" : "false") << " ";
        } else if (0 == cmd[i].compare("getRandom")) {
            int param_3 = obj->getRandom();
            cout << param_3 << " ";
        }
    }

    return 0;
}