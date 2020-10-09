#include <math.h>
#include <stdio.h>

int minCount(int* coins, int coinsSize) {
    int ans = 0;
    for (int i = 0; i < coinsSize; ++i) {
        ans += (coins[i] + 1) / 2;
    }
    return ans;
}

// int minCount(int* coins, int coinsSize) {
//     int ans = 0;
//     for (int i = 0; i < coinsSize; ++i) {
//         if (coins[i] % 2 == 0) {
//             ans += coins[i] / 2;
//         } else {
//             ans += 1 + coins[i] / 2;
//         }
//     }
//     return ans;
// }

int main() {
    int coins[]   = {2, 3, 10};
    int coinsSize = sizeof(coins) / sizeof(int);

    int ans = minCount(coins, coinsSize);
    printf("%d", ans);
    return 0;
}