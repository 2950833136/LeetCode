#include <malloc.h>
#include <stdio.h>
#include <string.h>

//int matchSubstr(char* s, char** words, int* wordsNum, int wordsSize) {
//	int i = 0;
//	int strlength = strlen(s);
//	int cnt = 0;
//	int* wordsNumTmp = (int*)malloc(wordsSize * sizeof(int));
//
//	memcpy(wordsNumTmp, wordsNum, wordsSize * sizeof(int));		//memcpy 拷贝
//	for (int j = 0; j < wordsSize && i < strlength;) {
//		if (wordsNumTmp[j] == 1) {
//			if (!strncmp(s + i, words[j], strlen(words[j]))) {	//strncmp 比较，相等为 0
//				wordsNumTmp[j] = 0;
//				cnt++;
//				i += strlen(words[j]);
//				j = 0;
//				if (cnt == wordsSize) {							//全部相等
//					return 1;
//				}
//				continue;
//			}
//		}
//		j++;
//	}
//	return 0;
//}
//int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
//	int i, j;
//	int slen = strlen(s);
//	int* indexs = (int*)malloc(10000 * sizeof(int));
//	int wordslen = 0;
//	int indexnum = 0;
//	int* wordsNum = (int*)malloc(wordsSize * sizeof(int));
//	memset(indexs, 0, 10000 * sizeof(int));		//indexs 全部置 0
//
//	for (i = 0; i < wordsSize; i++) {
//		wordsNum[i] = 1;						//初始化 wordsNum 全为 1
//		wordslen += strlen(words[i]);			//所有单词总长度
//	}
//
//	for (i = 0; i + wordslen <= slen; i++) {	//暴力遍历
//		if (matchSubstr(s + i, words, wordsNum, wordsSize) == 1) {
//			indexs[indexnum++] = i;				//记录下标
//		}
//	}
//
//	*returnSize = indexnum;						//指针记录个数
//	return indexs;								//返回下标字符串
//}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    static int out[1000];
    int        cnt = 0;
    if (s == NULL || wordsSize == NULL || wordsSize <= 0) {
        *returnSize = cnt; //为空，返回0
        return out;
    }
    int slen = strlen(s);        //求字符串 s 的长度
    int wlen = strlen(words[0]); //求一个单词的的长度（因为长度相同）
    int sum  = 0;
    for (int i = 0; i < wordsSize; i++) {
        sum += words[i][0]; //每个单词首字母 ASCII 码和
    }
    for (int i = 0; i < wlen; i++) {
        int times = (slen - i) / wlen - wordsSize + 1; //可以移动的次数
        int tmp   = 0;
        for (int j = 0; j < (wordsSize - 1); j++) {
            tmp += s[i + j * wlen]; //s 字符串以 wlen 间隔的字母 ASCII 码和，wordsSize - 1 个
        }
        for (int j = 0; j < times; j++) {
            tmp += s[i + (j + wordsSize - 1) * wlen]; //加上最后一个字母 ASCII 码
            if (tmp == sum) {                         //相等说明可能匹配
                char flags[wordsSize];
                memset(flags, 0, wordsSize);                                                             //memset 将 flags 的内容全部设置 0
                for (int m = 0; m < wordsSize; m++) {                                                    //s 字符串间隔
                    for (int n = 0; n < wordsSize; n++) {                                                //第 n 个单词
                        if ((flags[n] == 0) && (strncmp(&s[i + (j + m) * wlen], words[n], wlen) == 0)) { //strncmp 字符串比较函数，相等返回 0
                            flags[n] = 1;
                            break;
                        }
                    }
                }
                int ccc = 0; //记录匹配个数
                for (int m = 0; m < wordsSize; m++) {
                    if (flags[m] == 1) {
                        ccc++;
                    }
                }
                if (ccc == wordsSize) {        //如果匹配个数等于单词数，说明全部匹配
                    out[cnt++] = i + j * wlen; //记录下标
                }
            }
            tmp -= s[i + j * wlen]; //减去第一个字母 ASCII 码
        }
    }
    *returnSize = cnt; //指针记录个数
    return out;        //返回下标数组
}

int main() {
    char* s          = (char*)"barfoothefoobarman";
    char* words[2]   = {"foo", "bar"};
    int   wordsSize  = 2;
    int*  returnSize = (int*)malloc(sizeof(int));

    int* res = findSubstring(s, words, wordsSize, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("%d", res[i]);
    }

    return 0;
}
