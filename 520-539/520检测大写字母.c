#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

/**
 * 暴力遍历
 *  - 情况: "good","goOD"; "Good","GOOD","GOod"
 *  - 如果第一个和第二个字母都为大写，则后续都应为大写
 *  - 如果第一个字母为大写而第二个字母为小写，则后续都应为小写
 *  - 如果第一个字母为小写，则后续都应为小写
 */
bool detectCapitalUse(char* word) {
    int len = strlen(word);
    if (word[0] >= 'A' && word[0] <= 'Z') {
        if (word[1] >= 'A' && word[1] <= 'Z') {
            for (int i = 1; i < len; i++) {
                if (word[i] >= 'a' && word[i] <= 'z') {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < len; i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    return false;
                }
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            }
        }
    }
    return true;
}

/**
 * 方法二：统计大写字母出现次数
 *  + true
 *      - 全部是大写字母
 *      - 全部小写
 *      - 头部大写字母
 *  + false
 */
// bool detectCapitalUse(char* word) {
//     int len = strlen(word);
//     int cnt = 0;
//     for (int i = 0; i < len; i++) {
//         if ((word[i] >= 'A') && (word[i] <= 'Z')) {
//             cnt++;
//         }
//     }
//     if ((cnt == len) || (cnt == 0)) {
//         return true;
//     } else if (((word[0] >= 'A') && (word[0] <= 'Z') && (cnt == 1))) {
//         return true;
//     } else {
//         return false;
//     }
// }

int main() {
    char* str = (char*)"FFFFf";

    if (detectCapitalUse(str)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}