#include <malloc.h>
#include <stdio.h>
#include <string.h>

// 遍历输出
void displayChar(char** pointer, int pointerSize) {
    for (int i = 0; i < pointerSize; i++) {
        for (int j = 0; j < strlen(*(pointer + i)); j++) {
            printf("%c ", *(*(pointer + i) + j));
        }
        printf("\n");
    }
}
void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * hash 计算
 *      + 以第一个为基础数据，得到初始 hash 表
 *      + 遍历后面的，比较得到最小 hash 表、count 值
 *      + 返回都包括的字符
 */
#define CHARS 26
char** commonChars(char** A, int ASize, int* returnSize) {
    if (0 == ASize) {
        *returnSize = 0;
        return NULL;
    }

    int count = 0;
    int hash[CHARS];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < strlen(*A); i++) {
        hash[*(*A + i) - 'a']++;
        count++;
    }

    int perCount = 0;
    int perHash[CHARS];
    for (int i = 1; i < ASize; i++) {
        memset(perHash, 0, sizeof(perHash));
        for (int j = 0; j < strlen(*(A + i)); j++) {
            perHash[*(*(A + i) + j) - 'a']++;
        }
        for (int k = 0; k < CHARS; k++) {
            hash[k] = perHash[k] < hash[k] ? perHash[k] : hash[k];
            perCount += hash[k];
        }
        count    = perCount < count ? perCount : count;
        perCount = 0;
    }

    char** ans  = (char**)malloc(sizeof(char*) * count);
    *returnSize = 0;
    for (int i = 0; i < CHARS; i++) {
        while (hash[i] != 0) {
            ans[*returnSize]    = (char*)malloc(sizeof(char) * 2);
            ans[*returnSize][0] = i + 'a';
            ans[*returnSize][1] = '\0';
            (*returnSize)++;
            hash[i]--;
        }
    }
    return ans;
}

int main() {
    char   arr[][16]  = {"cool", "lock", "cook"};
    int    ASize      = sizeof(arr) / sizeof(arr[0]);
    int*   returnSize = (int*)malloc(sizeof(int));
    char** A          = (char**)malloc(sizeof(char*) * ASize);
    for (int i = 0; i < ASize; i++) {
        *(A + i) = arr[i];
    }
    displayChar(A, ASize);

    char** ans = commonChars(A, ASize, returnSize);
    displayChar(ans, *returnSize);

    return 0;
}