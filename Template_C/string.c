#include <stdio.h>
#include <string.h>

void display(char* str) {
    while (*str != '\0') {
        printf("%c ", *str);
        *str++;
    }
    printf("\n");
}

int main() {
    char* str = (char*)"ab#c";
    display(str);

    return 0;
}