#include <malloc.h>
#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') { //needle 为空返回 0
        return 0;
    }

    int len1 = strlen(haystack); //获取字符串长度
    int len2 = strlen(needle);

    if (len2 > len1) {
        return -1;
    }

    int i; //定义长度差，needle最多移几次
    int j; //比较是否相等
    for (i = 0; i <= (len1 - len2); i++) {
        for (j = 0; j < len2; j++) {
            if (haystack[i + j] != needle[j]) {
                break; //一个不相等就退出
            }
        }
        if (j == len2) { //完全包括，返回相等开始的下标
            return i;
        }
    }

    return -1;
}

int main() {
    char* haystack = (char*)malloc(sizeof(char) * 100);
    char* needle   = (char*)malloc(sizeof(char) * 100);
    printf("请输入 haystack: ");
    scanf("%s", haystack);
    printf("请输入 needle  : ");
    scanf("%s", needle);

    int n = strStr(haystack, needle);
    printf("%d", n);

    return 0;
}
