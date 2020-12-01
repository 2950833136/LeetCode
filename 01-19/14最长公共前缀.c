#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* ret = (char*)malloc(1);
        ret[0]    = '\0';
        return ret;
    }
    int   count = 0;                              // 水平查找第几个
    int   flag  = true;                           // 表示是否退出
    char  c;                                      // 第一个字符串的标准
    char* str = (char*)calloc(128, sizeof(char)); //分配空间128（至少），并初始化
    while (flag) {
        c = strs[0][count];
        for (int j = 0; j < strsSize; j++) {
            if ((strs[j][count] == '\0') || (strs[j][count] != c)) { //退出条件
                flag = false;
                break;
            }
        }
        str[count] = c; // 一样的字符保存
        count++;
    }
    str[count - 1] = '\0'; // 去除最后一个
    return str;
}

int main() {
    const char* s[]  = {"flower", "flow", "flight"};
    char**      strs = (char**)s;
    char*       buff = longestCommonPrefix(strs, 3);
    puts(buff);
    return 0;
}
