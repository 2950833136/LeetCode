#include <limits.h>
#include <stdio.h>

int reverse(int x) {
    int result = 0;
    int pop    = 0;
    while (x != 0) {
        pop = x % 10;
        x   = x / 10;
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
            return 0;
        } else if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
            return 0;
        } else {
            result = result * 10 + pop;
        }
    }
    return result;
}

int main() {
    int number = -21474;
    int x      = reverse(number);
    printf("%d", x);

    return 0;
}
