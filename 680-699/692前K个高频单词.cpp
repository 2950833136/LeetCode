#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * hash + 排序
 */
class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> cnt;
        for (auto &word : words) {
            ++cnt[word];
        }
        vector<string> rec;
        for (auto &[key, value] : cnt) {
            rec.emplace_back(key);
        }
        sort(rec.begin(), rec.end(), [&](const string &a, const string &b) -> bool {
            /**
             * 相等 按照字母次序排序
             * 不等 进行出现次数排序
             */
            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
        });
        rec.erase(rec.begin() + k, rec.end());
        return rec;
    }
};

int main() {
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    int            k     = 2;

    Solution s;
    for (auto word : s.topKFrequent(words, k)) {
        cout << word << endl;
    }

    return 0;
}