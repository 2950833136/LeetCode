#include <math.h>
#include <stdio.h>

/**
 * 一遍遍历
 *  - 从最开始记录就是最大的，不用循环遍历
 *  - 只有是山峰型才记录
 */
int longestMountain(int* A, int ASize) {
    int left  = 0;
    int right = 0;
    int max   = 0;
    int i     = 0;
    while (i < ASize - 1) {
        // 上坡，左边增加
        while (i < ASize - 1 && A[i] < A[i + 1]) {
            left++;
            i++;
        }
        // 下坡，右边增加
        while (i < ASize - 1 && A[i] > A[i + 1]) {
            right++;
            i++;
        }
        // 相等只是 i++
        if (i < ASize - 1 && A[i] == A[i + 1]) {
            i++;
        }
        // 只有是山峰型才记录
        if (left > 0 && right > 0) {
            max = fmax(max, left + right + 1);
        }
        // 复原
        left  = 0;
        right = 0;
    }
    return max;
}

int main() {
    int A[]   = {2, 1, 4, 7, 3, 2, 5};
    int ASize = sizeof(A) / sizeof(A[0]);

    int ret = longestMountain(A, ASize);
    printf("%d", ret);

    return 0;
}