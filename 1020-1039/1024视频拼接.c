#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 遍历输出，数组确定长度
void displayNum(int** pointer, int pointerSize, int* pointerColSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < *pointerColSize; j++) {
            printf("%d ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * 方法一：贪心算法
 *  + 因为返回所需片段的最小数目（不是返回最短时间）
 *      - 所以只要片段左边小于上一个片段右边，找到满足条件片段的最大右边即可
 *  + 步骤
 *      - 循环 next < T
 *      - 遍历数组找到满足条件片段的最大右边
 *      - 如果没有，循环一次 next 不变 那么 right == right，直接结束
 *      - 如果有，就个数 +1，更新 right
 */
// int videoStitching(int** clips, int clipsSize, int* clipsColSize, int T) {
//     if (clips == NULL || T == 0) {
//         return -1;
//     }

//     int ans   = 0;
//     int right = 0;
//     int next  = 0;
//     while (next < T) {
//         for (int i = 0; i < clipsSize; i++) {
//             if (clips[i][0] <= right) {
//                 next = clips[i][1] > next ? clips[i][1] : next;
//             }
//         }
//         // 循环一次没有结果，直接返回 -1
//         if (right == next) {
//             return -1;
//         }
//         ans++;
//         right = next;
//     }

//     return ans;
// }

/**
 * 精简：排序后只需要遍历一遍
 */
// int Cmp(const void* a, const void* b) {
//     return (*(int**)a)[0] - (*(int**)b)[0];
// }

// int Max(int a, int b) {
//     return a > b ? a : b;
// }

// int videoStitching(int** clips, int clipsSize, int* clipsColSize, int T) {
//     qsort(clips, clipsSize, sizeof(int*), Cmp);
//     int count = 0;
//     int right = 0;
//     while (right < T) {
//         int nextRight = right;
//         for (int i = 0; i < clipsSize; i++) {
//             if (clips[i][0] <= right) {
//                 nextRight = Max(nextRight, clips[i][1]);
//             }
//         }
//         if (right == nextRight) {
//             return -1;
//         }
//         right = nextRight;
//         count++;
//     }
//     return count;
// }

/**
 * 方法二：动态规划
 *  - 令 dp[i] 表示将区间 [0,i) 覆盖所需的最少子区间的数量
 *  - 而前半部分则可以用 dp[aj] 对应的最优方法进行覆盖
 *      - dp[i] = min{dp[i], dp[aj]+1}  (aj​<i≤bj​)
 */
int Min(int a, int b) {
    return a < b ? a : b;
}

int videoStitching(int** clips, int clipsSize, int* clipsColSize, int T) {
    int dp[T + 1];
    memset(dp, 0x3f, sizeof(dp));

    dp[0] = 0;
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < clipsSize; j++) {
            if (clips[j][0] < i && i <= clips[j][1]) {
                dp[i] = Min(dp[i], dp[clips[j][0]] + 1);
            }
        }
    }
    return dp[T] == 0x3f3f3f3f ? -1 : dp[T];
}

int main() {
    // 二维数字数组
    int arr3[][2] = {
        {0, 2},
        {4, 6},
        {8, 10},
        {1, 9},
        {1, 5},
        {5, 9},
    };
    int   clipsColSize = 2;
    int   clipsSize    = sizeof(arr3) / sizeof(arr3[0]);
    int** clips        = (int**)malloc(sizeof(int*) * clipsSize);
    for (int i = 0; i < clipsSize; i++) {
        *(clips + i) = (int*)malloc(sizeof(int) * clipsColSize);
        *(clips + i) = arr3[i];
    }
    // displayNum(clips, clipsSize, &clipsColSize);

    int T   = 10;
    int ans = videoStitching(clips, clipsSize, &clipsColSize, T);
    printf("%d", ans);

    return 0;
}