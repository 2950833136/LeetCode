#include <iostream>
using namespace std;

/**
 * 方法一： 把字符串转变纯字母和数字，在比较
 */
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string sgood;
//         for (char ch : s) {
//             if (isalnum(ch)) {
//                 sgood += tolower(ch);
//             }
//         }
//         // cout << sgood << endl;
//         int n     = sgood.size();
//         int left  = 0;
//         int right = n - 1;
//         while (left < right) {
//             if (sgood[left] != sgood[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

/**
 * 方法二： 双指针在原字符串上直接判断
 *  - 如果不是字符或数字就继续
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int n     = s.size();
        int left  = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";

    Solution solution;
    if (solution.isPalindrome(s)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}