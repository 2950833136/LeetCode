#include <iostream>
using namespace std;

/**
 * 返回结果在 a 中
 *  - 先补充位数到一样，以 0 填充
 *  - 在从最后计算，以 flag 作为进位
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        // 先补充位数到一样，以 0 填充
        while (len_a < len_b) {
            a = '0' + a;
            len_a++;
        }
        while (len_b < len_a) {
            b = '0' + b;
            len_b++;
        }
        // 在从最后计算，以 flag 作为进位
        int len  = len_a;
        int flag = 0;
        int sum  = 0;
        for (int i = len - 1; i >= 0; i--) {
            sum = (a[i] - '0') + (b[i] - '0') + flag;
            if (sum == 0) {
                a[i] = '0';
                flag = 0;
            } else if (sum == 1) {
                a[i] = '1';
                flag = 0;
            } else if (sum == 2) {
                a[i] = '0';
                flag = 1;
            } else if (sum == 3) {
                a[i] = '1';
                flag = 1;
            }
        }
        if (flag == 1) {
            a = '1' + a;
        }
        return a;
    }
};

int main() {
    string a = "1010";
    string b = "1011";

    Solution s;
    string   ret = s.addBinary(a, b);
    cout << ret;

    return 0;
}