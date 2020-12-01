#include <stdbool.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int divide(int dividend, int divisor) {
    int  res  = 0;
    bool flag = (dividend ^ divisor) < 0; //判断符号是否相同，相同为0，不同为1（二进制异或）
    if (divisor == 1) {                   //除数为 1，不变
        return dividend;
    }
    if (divisor == INT_MIN) {
        return dividend == INT_MIN ? 1 : 0; //除数特殊值
    }

    if (dividend == INT_MIN) { //被除数特殊值
        if (divisor == -1) {   //溢出
            return INT_MAX;
        } else { //为后面取正数，计算dividend
            dividend = divisor < 0 ? dividend - divisor : INT_MAX - divisor + 1;
            res      = 1;
        }
    }
    dividend = dividend < 0 ? -dividend : dividend; //取正数
    divisor  = divisor < 0 ? -divisor : divisor;
    for (int i = 31; i >= 0; i--) { //类似贪心算法，移位求解
        if (dividend >> i >= divisor) {
            res += 1 << i;
            dividend -= divisor << i;
        }
    }
    return flag ? -res : res; //1为负，0为正
}

int main() {
    int dividend;
    int divisor;
    printf("请输入 dividend: ");
    scanf("%d", &dividend);
    printf("请输入 divisor : ");
    scanf("%d", &divisor);

    int res = divide(dividend, divisor);
    printf("%d", res);

    return 0;
}
