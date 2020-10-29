#include <iostream>
using namespace std;

/**
 * 方法一：快速幂 + 递归
 *  + 「快速幂算法」的本质是分治算法
 *      - 当我们要计算 x^n 时，我们可以先递归地计算出 y=x^(n/2)，其中 ⌊a⌋ 表示对 a 进行下取整
 *      - 根据递归计算的结果，如果 n 为偶数，那么 x^n=y^2；如果 n 为奇数，那么 x^n = y^2 * x
 *      - 递归的边界为 n=0，任意数的 0 次方均为 1
 */
// class Solution {
// public:
//     double quickMul(double x, long long N) {
//         if (N == 0) {
//             return 1.0;
//         }
//         double y = quickMul(x, N / 2);
//         return N % 2 == 0 ? y * y : y * y * x;
//     }

//     double myPow(double x, int n) {
//         long long N = n;
//         return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
//     }
// };

/**
 * 方法二：快速幂 + 迭代
 *  - 很妙
 *  - https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/
 */
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main() {

    double x = 2.00000;
    int    n = -2;

    Solution s;
    double   ret = s.myPow(x, n);
    printf("%lf", ret);

    return 0;
}