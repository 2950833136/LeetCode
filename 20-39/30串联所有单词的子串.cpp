#include <stdio.h>
#include <string.h>
#include <malloc.h>

//int matchSubstr(char* s, char** words, int* wordsNum, int wordsSize) {
//	int i = 0;
//	int strlength = strlen(s);
//	int cnt = 0;
//	int* wordsNumTmp = (int*)malloc(wordsSize * sizeof(int));
//
//	memcpy(wordsNumTmp, wordsNum, wordsSize * sizeof(int));		//memcpy ����
//	for (int j = 0; j < wordsSize && i < strlength;) {
//		if (wordsNumTmp[j] == 1) {
//			if (!strncmp(s + i, words[j], strlen(words[j]))) {	//strncmp �Ƚϣ����Ϊ 0
//				wordsNumTmp[j] = 0;
//				cnt++;
//				i += strlen(words[j]);
//				j = 0;
//				if (cnt == wordsSize) {							//ȫ�����
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
//	memset(indexs, 0, 10000 * sizeof(int));		//indexs ȫ���� 0
//
//	for (i = 0; i < wordsSize; i++) {
//		wordsNum[i] = 1;						//��ʼ�� wordsNum ȫΪ 1
//		wordslen += strlen(words[i]);			//���е����ܳ���
//	}
//
//	for (i = 0; i + wordslen <= slen; i++) {	//��������
//		if (matchSubstr(s + i, words, wordsNum, wordsSize) == 1) {
//			indexs[indexnum++] = i;				//��¼�±�
//		}
//	}
//
//	*returnSize = indexnum;						//ָ���¼����
//	return indexs;								//�����±��ַ���
//}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
	static int out[1000];
	int cnt = 0;
	if (s == NULL || wordsSize == NULL || wordsSize <= 0) {
		*returnSize = cnt;						//Ϊ�գ�����0
		return out;
	}
	int slen = strlen(s);						//���ַ��� s �ĳ���
	int wlen = strlen(words[0]);				//��һ�����ʵĵĳ��ȣ���Ϊ������ͬ��
	int sum = 0;								
	for (int i = 0; i < wordsSize; i++) {
		sum += words[i][0];						//ÿ����������ĸ ASCII ���
	}
	for (int i = 0; i < wlen; i++) {
		int times = (slen - i) / wlen - wordsSize + 1;		//�����ƶ��Ĵ���
		int tmp = 0;										
		for (int j = 0; j < (wordsSize - 1); j++) {
			tmp += s[i + j * wlen];							//s �ַ����� wlen �������ĸ ASCII ��ͣ�wordsSize - 1 ��
		}
		for (int j = 0; j < times; j++) {
			tmp += s[i + (j + wordsSize - 1) * wlen];		//�������һ����ĸ ASCII ��
			if (tmp == sum) {								//���˵������ƥ��
				char flags[wordsSize];
				memset(flags, 0, wordsSize);				//memset �� flags ������ȫ������ 0
				for (int m = 0; m < wordsSize; m++) {		//s �ַ������
					for (int n = 0; n < wordsSize; n++) {	//�� n ������ 
						if ((flags[n] == 0) && (strncmp(&s[i + (j + m) * wlen], words[n], wlen) == 0)) {	//strncmp �ַ����ȽϺ�������ȷ��� 0
							flags[n] = 1;
							break;
						}
					}
				}
				int ccc = 0;								//��¼ƥ�����
				for (int m = 0; m < wordsSize; m++) {
					if (flags[m] == 1) {
						ccc++;
					}
				}
				if (ccc == wordsSize) {						//���ƥ��������ڵ�������˵��ȫ��ƥ��
					out[cnt++] = i + j * wlen;				//��¼�±�
				}
			}
			tmp -= s[i + j * wlen];							//��ȥ��һ����ĸ ASCII ��
		}
	}
	*returnSize = cnt;										//ָ���¼����
	return out;												//�����±�����
}

int main() {
	char* s = (char*)"barfoothefoobarman";
	char* words[2] = { "foo","bar" };
	int wordsSize = 2;
	int* returnSize = (int*)malloc(sizeof(int));

	int* res = findSubstring(s, words, wordsSize, returnSize);
	for (int i = 0; i < *returnSize; i++) {
		printf("%d", res[i]);
	}

	return 0;
}
