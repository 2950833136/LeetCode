#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length() - 1;
        int res = 0;
        while (len >= 0 && s[len] == ' ') {
            len--;
        }
        while (len >= 0 && s[len] != ' ') {
            res++;
            len--;
        }
        return res;
    }
};

int main() {
    Solution s;
    string   str = "Hello World";
    cout << s.lengthOfLastWord(str);
    return 0;
}