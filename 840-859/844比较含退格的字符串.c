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
char* update(char* str) {
    int   index = 0;
    int   n     = strlen(str);
    char* temp  = (char*)malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++) {
        if (str[i] != '#') {
            temp[index++] = str[i];
        } else if (index > 0) {
            index--;
        }
    }
    temp[index] = '\0';
    // display(temp);
    return temp;
}

bool backspaceCompare(char* S, char* T) {
    return strcmp(update(S), update(T)) == 0;
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