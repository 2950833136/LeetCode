#include <stdio.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

/**
 * 方法一：
 *  - 是否能找到山顶
 *  - 是否能找到山脚
 */
bool validMountainArray(int* A, int ASize) {
    if (ASize < 3) {
        return false;
    }
    int i = 0;
    while ((i < ASize) && (i + 1 < ASize) && A[i + 1] > A[i]) {
        i++;
    }
    if (i == 0 || i == ASize - 1) {
        return false;
    }
    int j = i;
    while ((j < ASize) && (j + 1 < ASize) && (A[j + 1] < A[j])) {
        j++;
    }
    if (j == ASize - 1) {
        return true;
    } else {
        return false;
    }
}

/**
 * 方法二：
 *  - 两边查找
 *  - 是否能找到山顶
 */
// bool validMountainArray(int* A, int ASize) {
//     int left  = 0;
//     int right = ASize - 1;
//     // 从左边往右边找，一直找到山峰为止
//     while (left < ASize - 1 && A[left] < A[left + 1]) {
//         left++;
//     }
//     // 从右边往左边找，一直找到山峰为止
//     while (right > 1 && A[right] < A[right - 1]) {
//         right--;
//     }
//     // 判断从左边和从右边找的山峰是不是同一个
//     return left > 0 && right < ASize - 1 && left == right;
// }

int main() {
    int A[]   = {0, 2, 3, 3, 5, 2, 1, 0};
    int ASize = sizeof(A) / sizeof(A[0]);

    if (validMountainArray(A, ASize)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}