#include <malloc.h>
#include <stdio.h>
#include <string.h>

void display(char* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%c", nums[i]);
    }
    printf("\n");
}

void reverseString(char* s, int sSize) {
    int  i = 0, j = sSize - 1;
    char temp;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char s[100] = "hello";
    int sSize = strlen(s);

    display(s, sSize);
    reverseString(s, sSize);
    display(s, sSize);
    
    return 0;
}