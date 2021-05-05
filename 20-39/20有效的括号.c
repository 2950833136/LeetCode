#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(char* s) {
    int length = strlen(s); //求长度
    if (length == 0) {
        return true;
    }
    char* stack = (char*)malloc(sizeof(char) * (length / 2 + 1)); //分配最大空间
    int   top   = -1;

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') { // ([{ 就加入栈当中
            top++;
            stack[top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') { // )]} 就把 ([{ 移除
            if (top == -1) {                                    // 还有)]} 但没有 ([{
                return false;
            } else if (s[i] == ')' && stack[top] == '(') { //移除
                top--;
            } else if (s[i] == ']' && stack[top] == '[') {
                top--;
            } else if (s[i] == '}' && stack[top] == '{') {
                top--;
            } else { //其它字符返回 false
                return false;
            }
        } else { //其它字符返回 false
            return false;
        }
    }
    return (top == -1 ? true : false); //top==-1,在栈顶等于栈底为真
}

int main() {
    char* s = (char*)"()[]";
    if (isValid(s) == true) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}
