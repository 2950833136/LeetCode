#include <math.h>
#include <stdio.h>
#include <string.h>

typedef char bool;
#define false 0
#define true 1

/**
 * 动态规划：二维数组
 * 首先判断不符合规则的数组
 *      - 长度小于 2
 *      - 和为奇数
 *      - 最大数大于和的一半
 * 再考虑动态规划
 *      令 dp[i][j] 表示 [0, i]选取若干，是否等于 j(j==target), 则 dp[i][j] 有两种选择方式
 *          - j <  nums[i], 不能选择，即 dp[i][j] = dp[i-1][j]
 *          - j >= nums[i], 可以选择，即 dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]]
 *      最终 dp[i][target](dp[numsSize-1][target])
 */
// bool canPartition(int* nums, int numsSize) {
//     if (numsSize < 2) {
//         return false;
//     }
//     int sum = 0, maxNum = 0;
//     for (int i = 0; i < numsSize; ++i) {
//         sum += nums[i];
//         maxNum = fmax(maxNum, nums[i]);
//     }
//     if (sum & 1) {
//         return false;
//     }
//     int target = sum / 2;
//     if (maxNum > target) {
//         return false;
//     }
//     int dp[numsSize][target + 1];
//     memset(dp, 0, sizeof(dp));
//     for (int i = 0; i < numsSize; i++) {
//         dp[i][0] = true;
//     }
//     dp[0][nums[0]] = true;
//     for (int i = 1; i < numsSize; i++) {
//         int num = nums[i];
//         for (int j = 1; j <= target; j++) {
//             if (j >= num) {
//                 dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }
//     return dp[numsSize - 1][target];
// }

/**
 * 动态规划：一维数组
 * 1、同理排除不符合规则的数组
 * 2、当前行总是参考了它上面一行 「头顶上」 那个位置和「左上角」某个位置的值。因此，我们可以只开一个一维数组，从后向前依次填表即可。
 *      - 逆序填表，防止覆盖
 * 
 */
bool canPartition(int* nums, int numsSize) {
    if (numsSize < 2) {
        return false;
    }
    int sum = 0, maxNum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        maxNum = fmax(maxNum, nums[i]);
    }
    if (sum & 1) {
        return false;
    }
    int target = sum / 2;
    if (maxNum > target) {
        return false;
    }
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j > 0; j--) {
            if (j >= nums[i]) {
                // 当 j 能被 i-1 个元素表示或者 j-nums[i] 能被前 i-1 个数表示就为 1
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
    }
    return dp[target];
}

int main() {
    int nums[]   = {1, 5, 11, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (canPartition(nums, numsSize)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}