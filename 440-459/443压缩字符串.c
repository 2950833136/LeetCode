/*****************************************************************************
 * C
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

int compress(char *chars, int charsSize) {
    int cur = 0;                                         // 游标，覆盖后数组的下标
    char num[1000] = {0};                                // 记录个数的数组
    for (int i = 0, j = 0; i < charsSize; j = i) {       // 没有相等的就 j=i,读取下一个压缩
        while (i < charsSize && chars[i] == chars[j]) {  // 同字符 i++
            i++;
        }
        chars[cur++] = chars[j];  // 存入字符
        if (i - j == 1) {
            continue;
        }
        int numLen = sprintf(num, "%d", i - j);  // 格式化输出数字到数组中
        for (int k = 0; k < numLen; k++) {       // 依次单个存入数字
            chars[cur++] = num[k];               // 存入数字
        }
    }
    return cur;
}

int main() {
    // char chars[100] = {'a', 'a', 'a', 'b', 'b', 'b'};
    char chars[100] = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c'};
    int charsSize = strlen(chars);

    for (int i = 0; i < charsSize; i++) {
        printf("%c ", chars[i]);
    }
    printf("\n");

    int cur = compress(chars, charsSize);
    for (int j = 0; j < cur; j++) {
        printf("%c ", chars[j]);
    }

    return 0;
}

/*****************************************************************************
 * C++
 *****************************************************************************/
// #include <string.h>
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
//    public:
//     int compress(vector<char>& chars) {
//         if (chars.empty()) return 0;

//         size_t j = 0;
//         int cnt = 0;
//         for (size_t i = 1; i <= chars.size(); i++) {
//             cnt++;
//             if (i == chars.size() || chars[i] != chars[j]) {
//                 j++;
//                 if (cnt != 1) {
//                     string scnt = to_string(cnt);
//                     for (auto c : scnt) {
//                         chars[j++] = c;
//                     }
//                 }
//                 if (i == chars.size()) break;
//                 chars[j] = chars[i];
//                 cnt = 0;
//             }
//         }
//         return j;
//     }
// };

// int main() {
//     vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

//     for (int i = 0; i < chars.size(); i++) {
//         printf("%c ", chars[i]);
//     }
//     printf("\n");

//     Solution solution;
//     int cur = solution.compress(chars);
//     for (int j = 0; j < cur; j++) {
//         printf("%c ", chars[j]);
//     }

//     return 0;
// }
