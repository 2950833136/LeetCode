#include <stdio.h>

int mySqrt(int x) {
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l   = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x   = 8;
    int ret = mySqrt(x);
    printf("%d", ret);
}