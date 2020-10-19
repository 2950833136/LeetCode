#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

void display(char* str) {
    while (*str != '\0') {
        printf("%c ", *str);
        *str++;
    }
    printf("\n");
}

/**
 * 栈思想
 * 字母压入， '#' 压出
 */
// char* update(char* str) {
//     int   index = 0;
//     int   n     = strlen(str);
//     char* temp  = (char*)malloc(sizeof(char) * (n + 1));

//     for (int i = 0; i < n; i++) {
//         if (str[i] != '#') {
//             temp[index++] = str[i];
//         } else if (index > 0) {
//             index--;
//         }
//     }
//     temp[index] = '\0';
//     // display(temp);
//     return temp;
// }

// bool backspaceCompare(char* S, char* T) {
//     return strcmp(update(S), update(T)) == 0;
// }

/**
 * 双指针
 *  skip 记录 '#' 的个数
 *  从后往前遍历
 */
bool backspaceCompare(char* S, char* T) {
    int i     = strlen(S) - 1;
    int j     = strlen(T) - 1;
    int skipS = 0;
    int skipT = 0;

    while (i >= 0 || j >= 0) {
        // 逆序找到 S 没被删除的数
        while (i >= 0) {
            if (S[i] == '#') {
                skipS++, i--;
            } else if (skipS > 0) {
                skipS--, i--;
            } else {
                break;
            }
        }
        // 逆序找到 T 没被删除的数
        while (j >= 0) {
            if (T[j] == '#') {
                skipT++, j--;
            } else if (skipT > 0) {
                skipT--, j--;
            } else {
                break;
            }
        }
        /**
         * 判断是否相等
         *  + 都还有字符
         *      - 不相等返回 false
         *  + 其中一个没有字符，另一个还有
         *      - 返回 false
         */
        if (i >= 0 && j >= 0) {
            if (S[i] != T[j]) {
                return false;
            }
        } else {
            if (i >= 0 || j >= 0) {
                return false;
            }
        }
        // 相等继续循环
        i--, j--;
    }
    return true;
}

int main() {
    char* S = (char*)"ab#c";
    char* T = (char*)"ad#c";

    if (backspaceCompare(S, T)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}