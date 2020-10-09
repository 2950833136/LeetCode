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
 * 动态转移
 * 全红     0
 * 红黄     1
 * 红黄红   2
 * 示性函数: isRed,isYellow
 * f[i][0]: 黄色调整红色
 * f[i][1]: 红色调整黄色
 * f[i][2]: 黄色调整红色
 */
int minimumOperations(char* leaves) {
    int n = strlen(leaves);
    int f[n][3];
    f[0][0] = (leaves[0] == 'y');
    f[0][1] = f[0][2] = f[1][2] = INT_MAX;
    for (int i = 1; i < n; ++i) {
        int isRed    = (leaves[i] == 'r');
        int isYellow = (leaves[i] == 'y');
        f[i][0]      = f[i - 1][0] + isYellow;
        f[i][1]      = fmin(f[i - 1][0], f[i - 1][1]) + isRed;
        if (i >= 2) {
            f[i][2] = fmin(f[i - 1][1], f[i - 1][2]) + isYellow;
        }
    }
    return f[n - 1][2];
}

int main() {
    char* leaves = (char*)"ryyryyyrryyyyyryyyrrryyyryryyyyryyrrryryyyryrryrrrryyyrrrrryryyrrrrryyyryyryrryryyryyyyryyrryrryryy";
    int   ans    = minimumOperations(leaves);
    printf("%d", ans);

    return 0;
}