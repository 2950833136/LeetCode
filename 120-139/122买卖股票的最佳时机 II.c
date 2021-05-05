#include <math.h>
#include <stdio.h>

/**
 * 常规做法
 */
// int maxProfit(int* prices, int pricesSize) {
//     int money = 0;

//     for (int i = 1; i < pricesSize; i++) {
//         if (prices[i - 1] < prices[i]) {
//             money += prices[i] - prices[i - 1];
//         }
//     }

//     return money;
// }

/**
 * 动态规划
 *  - 定义状态 dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，
 *  - dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）。
 */
int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}

int main() {
    int prices[]   = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int ret = maxProfit(prices, pricesSize);
    printf("%d\n", ret);

    return 0;
}