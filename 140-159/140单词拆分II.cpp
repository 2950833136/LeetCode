#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    }
};

int main() {
    string         s        = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    Solution       solution;
    vector<string> ret = wordDict;
    //solution.wordBreak(s, wordDict);

    vector<string>::iterator item = ret.begin();
    for (; item != ret.end(); item++) {
        cout << *item << endl;
    }

    return 0;
}
