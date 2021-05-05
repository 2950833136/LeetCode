#include <limits.h>
#include <stdio.h>
#include <string.h>

int myAtoi(char* str) {
    int key  = 0;           //记录字符串下标
    int N    = strlen(str); //记录字符串长度
    int sign = 1;           //记录符号
    int ret  = 0;           //记录结果
    // 1、跳过字符串前面的空格
    while (key < N && str[key] == ' ')
        key++;

    // 2.1、不存在非空格字符c
    if (key == N)
        return 0;
    // 2.2、c为'-'
    else if (str[key] == '-')
        sign = -1;
    // 2.2、c为'+'
    else if (str[key] == '+')
        sign = 1;
    // 2.4、c为数字
    else if ('0' <= str[key] && str[key] <= '9')
        ret = str[key] - '0';
    // 2.5、其它情况
    else
        return 0;

    // 3、继续处理c后面的数字字符
    while (key++ < N && '0' <= str[key] && str[key] <= '9') {
        int t = (str[key] - '0') * sign;
        // 如果结果大于INT_MAX，返回INT_MAX
        if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && t > 7)
            return INT_MAX;
        // 如果结果小于INT_MIN，返回INT_MIN
        if (ret < INT_MIN / 10 || ret == INT_MIN / 10 && t < -8)
            return INT_MIN;
        ret = ret * 10 + t;
    }
    return ret;
}

int main() {
    char* str = (char*)"4193 with words";
    int   x   = myAtoi(str);
    printf("%d", x);
    return 0;
}
