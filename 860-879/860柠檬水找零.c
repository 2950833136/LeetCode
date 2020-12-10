#include <stdbool.h>
#include <stdio.h>

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five == 0) {
                return false;
            }
            five--;
            ten++;
        } else {
            if (five > 0 && ten > 0) {
                five--;
                ten--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    int bills[]   = {5, 5, 5, 10, 20};
    int billsSize = sizeof(bills) / sizeof(bills[0]);

    if (lemonadeChange(bills, billsSize)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}