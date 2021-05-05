#include <malloc.h>
#include <stdio.h>
#include <string.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int centerExpand(char* s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--; //判断是否相等，相等就向两边继续扩展
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int L     = 0; //记录回文子串最大长度
    int start = 0; //记录回文子串开始位置
    int end   = 0; //记录回文子串截至位置
    int len   = strlen(s);
    if (len == 0 || len == 1) //一个一下直接返回
        return s;
    for (int i = 0; i < len; i++) {
        int l1 = centerExpand(s, i, i, len);     //以 i 为中心的扩展
        int l2 = centerExpand(s, i, i + 1, len); //以 i 和 i+1 为中心的扩展
        L      = max(max(l1, l2), L);            //取最大长度为最大回文子串

        if (L > end - start + 1) {
            start = i - (L - 1) / 2; //修改开始位置
            end   = i + L / 2;       //修改截至位置
        }
    }

    char* p = (char*)malloc(sizeof(char) * (L + 1)); //分配空间（长度加一个截至符）
    strncpy(p, s + start, L);                        //复制（从 s+start 到后面的 L 长度的字符）
    p[L] = '\0';                                     //截至符
    return p;
}

int main() {
    char* s = (char*)"cbbd";
    char* p = longestPalindrome(s);

    while (*p != '\0') {
        printf("%c", *p);
        p++;
    }

    return 0;
}
