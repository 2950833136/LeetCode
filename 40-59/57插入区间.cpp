#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int                 left   = newInterval[0];
        int                 right  = newInterval[1];
        bool                placed = false;
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            } else {
                // 与插入区间有交集，计算它们的并集
                left  = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> intervals   = {{1, 3}, {6, 9}};
    vector<int>         newInterval = {2, 5};

    Solution            s;
    vector<vector<int>> ret = s.insert(intervals, newInterval);

    return 0;
}