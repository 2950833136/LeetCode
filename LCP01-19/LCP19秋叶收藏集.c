#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// int minimumOperations(char* leaves) {
//     int n = strlen(leaves);
//     int ans = 0;
//     /**
//      * dif: 红叶与黄叶的比较差值，dif = 黄-红
//      * num: 当前存储的黄叶子数目（num 或 0）
//      * count: 前面的黄叶子总数
//      * pre: 前面黄叶子
//      * mid: 中间红叶子
//      * max_dif: 最大差值
//      * max_num: 最大当前存储的黄叶子数目
//      */
//     int dif = 0, num = 0, count = 0, pre = 0, mid = 0;
//     int max_dif = 0, max_num = 0;
//     // 满足 「红、黄、红」，优先考虑两边
//     if (leaves[0] == 'y') {
//         ans++;
//     }
//     if (leaves[n - 1] == 'y') {
//         ans++;
//     }
//     // 再考虑中间部分
//     for (int i = 1; i < n - 1; i++) {
//         if (leaves[i] == 'y') {
//             dif++;
//             num++;
//             count++;
//         } else {
//             if (dif == 0) {
//                 num = 0;  // 当前存储归零, 红叶子 = 黄叶子，
//             } else {
//                 dif--;
//             }
//         }
//         if (dif > max_dif) {
//             max_dif = dif;
//             pre = count - num;  // 前面黄叶子，黄叶子转化为红叶子，随数量动态变化
//             mid = num - dif;    // 中间红叶子，红叶子转化为黄叶子
//             max_num = num;
//         }
//     }
//     ans += pre + mid + (count - max_num - pre);
//     // 中间是红叶子，需要转换一个黄叶子
//     if (max_num == 0) {
//         ans += 1;
//     }
//     return ans;
// }

/**
    动态转移

    dp[i][0] : 将 leaves[0...i] 转换成 'r-y-r'
    dp[i][1] : 将 leaves[0...i] 转换成 'r-y-'
    dp[i][2] : 将 leaves[0...i] 转换成 'r'
    i >= 2
    leaves[i] == 'r'
        dp[i][0] = min(dp[i-1][0], dp[i-1][1])
        dp[i][1] = 1 + min(dp[i-1][1], dp[i-1][2])
        dp[i][2] = dp[i-1][2]
    leaves[i] == 'y'
        dp[i][0] = 1 + min(dp[i-1][0], dp[i-1][1])
        dp[i][1] = min(dp[i-1][1], dp[i-1][2])
        dp[i][2] = 1 + dp[i-1][2]
*/
int min(int a, int b) {
    return a < b ? a : b;
}

int minimumOperations(char* leaves) {
    int n   = strlen(leaves);
    int isR = 0;
    int dp[3];
    dp[0] = INT_MAX / 2;
    dp[1] = INT_MAX / 2;
    // 此时是 i=0, 保证全红
    dp[2] = (leaves[0] == 'r') ? 0 : 1;
    for (int i = 1; i < n; ++i) {
        isR   = (leaves[i] == 'r');
        dp[0] = (1 - isR) + min(dp[0], dp[1]); // i=1, min(dp[0], dp[1])都很大会被后面替换，所以无效
        dp[1] = min(dp[1], dp[2]) + isR;       // 下回合min(dp[0], dp[1])变小，当 i>=2 时，dp[0]开始有效
        dp[2] = (1 - isR) + dp[2];
    }
    return dp[0];
}

int main() {
    char* leaves = (char*)"ryyryyyrryyyyyryyyrrryyyryryyyyryyrrryryyyryrryrrrryyyrrrrryryyrrrrryyyryyryrryryyryyyyryyrryrryryy";
    int   ans    = minimumOperations(leaves);
    printf("%d", ans);

    return 0;
}