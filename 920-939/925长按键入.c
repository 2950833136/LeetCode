#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

/**
 * 双指针
 *  - name 和 typed 字符匹配
 *  + 当 typed 指针没有遍历完时
 *      - 如果 name 和 typed 字符匹配，指针同时加 i++,j++
 *      - 如果 typed 字符重复，说明存在一次长按键入，此时只将 j++
 *      - 如果 name 和 typed 字符不匹配，直接返回 false
 *  + 当 typed 指针遍历完时
 *      - 如果 name 也遍历完，说明可以相等
 */
bool isLongPressedName(char* name, char* typed) {
    int n = strlen(name);
    int m = strlen(typed);
    int i = 0, j = 0;
    while (j < m) {
        if (i < n && name[i] == typed[j]) {
            i++;
            j++;
        } else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        } else {
            return false;
        }
    }
    return i == n;
}

int main() {
    char* name  = (char*)"saed";
    char* typed = (char*)"ssaaedd";

    if (isLongPressedName(name, typed)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}