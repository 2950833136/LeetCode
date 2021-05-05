#include <iostream>
#include <queue>
using namespace std;

/**
 * 判断哪个先，然后禁用（除去）不是同阵营的
 * 自己往后调整位置
 */
class Solution {
public:
    string predictPartyVictory(string senate) {
        int        n = senate.length();
        queue<int> radiant;
        queue<int> dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front()) {
                radiant.push(radiant.front() + n);
            } else {
                dire.push(dire.front() + n);
            }
            radiant.pop();
            dire.pop();
        }
        return !radiant.empty() ? "Radiant" : "Dire";
    }
};

int main() {
    string senate = "RDD";

    Solution s;
    string   ret = s.predictPartyVictory(senate);
    cout << ret << endl;

    return 0;
}