#include <stdio.h> 
#include <malloc.h>
#include <string.h> 

int strStr(char* haystack, char* needle) {
	if (needle[0] == '\0') {		//needle Ϊ�շ��� 0 
		return 0;
	}

	int len1 = strlen(haystack);	//��ȡ�ַ������� 
	int len2 = strlen(needle);

	if (len2 > len1) {				 
		return -1;
	}

	int i;							//���峤�Ȳneedle����Ƽ��� 
	int j;							//�Ƚ��Ƿ���� 
	for (i = 0; i <= (len1 - len2); i++) {
		for (j = 0; j < len2; j++) {
			if (haystack[i + j] != needle[j]) {
				break;				//һ������Ⱦ��˳� 
			}
		}
		if (j == len2) {			//��ȫ������������ȿ�ʼ���±� 
			return i;
		}
	}

	return -1;
}

int main() {
	char* haystack = (char*)malloc(sizeof(char) * 100);
	char* needle = (char*)malloc(sizeof(char) * 100);
	printf("������ haystack: ");
	scanf("%s", haystack);
	printf("������ needle  : ");
	scanf("%s", needle);

	int n = strStr(haystack, needle);
	printf("%d", n);

	return 0;
}
