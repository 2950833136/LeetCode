#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void display(vector<string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/**
 *  - 单词拆分
 *  - 递归，回溯
 */
class Solution {
public:
    vector<string> dfs(unordered_map<int, vector<string>>& map, const unordered_set<string>& words, const string& s, const int& start) {
        if (map.count(start)) {
            return map[start];
        }
        vector<string> res;
        if (start == s.size()) {
            res.emplace_back("");
        }
        for (int end = start; end < s.size(); ++end) {
            // 逐步增加截取字符数
            string substr = s.substr(start, end - start + 1);
            // 单词存在继续向后面递归下一个单词
            if (words.count(substr)) {
                for (const auto& next : dfs(map, words, s, end + 1)) {
                    if (next == "") {
                        res.emplace_back(substr);
                    } else {
                        res.emplace_back(substr + " " + next);
                    }
                }
            }
        }
        map[start] = res;

        return res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>              words(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> map;
        return dfs(map, words, s, 0);
    }
};

int main() {
    string         s        = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    display(wordDict);
    Solution       solution;
    vector<string> ret = solution.wordBreak(s, wordDict);
    display(ret);

    return 0;
}
