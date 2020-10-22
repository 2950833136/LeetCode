#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void display(int* nums, int* returnSize) {
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
}

/**
 * 双指针求解
 *  + 原理：
 *      - 同一个字母只会出现在其中的一个片段
 *      - 片段里，某个字符最后出现的下标大于片段中其他字符最后出现的下标
 *  + 步骤
 *      - 先遍历得到每个字符最后出现的下标
 *      - 再遍历求解当前字符出现最后下标
 *          - 如果当前字符就是最后下标，就可以截断前面了
 *              - 记录片段长度
 *              - 更新下一个片段开启位置
 *          - 如果不是，继续遍历
 *              - 说明当前字符被某个字符包括
 */
int* partitionLabels(char* S, int* returnSize) {
    int last[26];
    int length = strlen(S);
    for (int i = 0; i < length; i++) {
        last[S[i] - 'a'] = i;
    }
    int* partition = (int*)malloc(sizeof(int) * length);
    int  start = 0, end = 0;
    *returnSize = 0;
    for (int i = 0; i < length; i++) {
        end = fmax(end, last[S[i] - 'a']);
        if (i == end) {
            partition[(*returnSize)++] = end - start + 1;
            start                      = end + 1;
        }
    }
    return partition;
}

int main() {
    char* str        = (char*)"ababcbacadefegdehijhklij";
    int*  returnSize = (int*)malloc(sizeof(int));

    int* ans = partitionLabels(str, returnSize);
    display(ans, returnSize);

    return 0;
}