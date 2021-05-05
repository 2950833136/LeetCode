#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void display(vector<vector<string>> words) {
    for (auto line : words) {
        for (auto word : line) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * 方法一：排序
 *   - 由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，
 *     故可以将排序之后的字符串作为哈希表的键。
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            map[key].emplace_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto item = map.begin(); item != map.end(); item++) {
            ret.emplace_back(item->second);
        }
        return ret;
    }
};

/**
 * 方法二：计数
 *  - 由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，
 *    故可以将每个字母出现的次数使用字符串表示，作为哈希表的键。
 *  - 由于字符串只包含小写字母，因此对于每个字符串，可以使用长度为 26 的数组记录每个字母出现的次数。
 */
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         // 自定义对 array<int, 26> 类型的哈希函数
//         auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
//             return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
//                 return (acc << 1) ^ fn(num);
//             });
//         };

//         unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
//         for (string& str : strs) {
//             array<int, 26> counts{};
//             int            length = str.length();
//             for (int i = 0; i < length; ++i) {
//                 counts[str[i] - 'a']++;
//             }
//             mp[counts].emplace_back(str);
//         }
//         vector<vector<string>> ans;
//         for (auto it = mp.begin(); it != mp.end(); ++it) {
//             ans.emplace_back(it->second);
//         }
//         return ans;
//     }
// };

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution               s;
    vector<vector<string>> ret = s.groupAnagrams(strs);
    display(ret);

    return 0;
}