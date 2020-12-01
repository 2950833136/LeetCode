#include <malloc.h>
#include <stdio.h>
#include <string.h>

void display(char* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%c", nums[i]);
    }
    printf("\n");
}

/**
 * 正整数 n（1 ≤ n ≤ 30）的描述数量，MAX 需要给 '\0' 预留一个  (nums[i] + 1)
 * int nums[30] = {1, 2, 2, 4, 6, 6, 8, 10, 14, 20, 26, 34, 46, 62, 78, 102, 134, 176, 226, 302, 408, 528, 678, 904, 1182, 1540, 2012, 2606, 3410, 4462};
 *
 * 递归
 * *pre:    上一个描述
 * *temp:   等于 pre，不让 pre 指针改变地址
 * *later:  下一个描述
 */
#define MAX 4463

char* countAndSay(int n) {
    if (n == 1) {
        return (char*)"1";
    }

    char* pre   = (char*)malloc(sizeof(char) * MAX);
    pre         = countAndSay(n - 1);
    char* temp  = pre;
    char* later = (char*)malloc(sizeof(char) * MAX);
    int   index = 0;
    int   count = 1;
    while (*temp != '\0') {
        if (*temp == *(temp + 1)) {
            temp++;
            count++;
        } else {
            later[index]     = count + '0';
            later[index + 1] = *temp;
            count            = 1;
            index += 2;
            temp++;
        }
    }
    later[index] = '\0';
    return later;
}

int main() {
    int   n     = 6;
    char* array = (char*)malloc(sizeof(char) * MAX);

    array = countAndSay(n);
    int arraySize = strlen(array);
    display(array, arraySize);
    
    getchar();
    return 0;
}