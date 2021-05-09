#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int flowers  = 0;
        int length   = bloomDay.size();
        for (int i = 0; i < length && bouquets < m; i++) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    /**
     * bloomDay 开花时间
     * m        需要制作 m 束花
     * k        相邻的 k 束花
     */
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m > bloomDay.size() / k) {
            return -1;
        }
        int low  = __INT_MAX__;
        int high = 0;
        int len  = bloomDay.size();
        for (int i = 0; i < len; i++) {
            low  = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while (low < high) {
            // 二分查找
            int days = (high - low) / 2 + low;
            if (canMake(bloomDay, days, m, k)) {
                high = days;
            } else {
                low = days + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution    s;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int         m        = 3;
    int         k        = 1;
    cout << "The min days is: " << s.minDays(bloomDay, m, k) << endl;
    return 0;
}