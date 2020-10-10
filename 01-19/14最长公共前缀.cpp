#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0) {					// û�о�ֱ�ӷ��� "" 
		char* ret = (char*)malloc(1);
		ret[0] = '\0';
		return ret;
	}
	int count = 0;							// ˮƽ���ҵڼ���
	int flag = true;						// ��ʾ�Ƿ��˳� 
	char c;									// ��һ���ַ����ı�׼ 
	char* str = (char*)calloc(128 , sizeof(char));						//����ռ�128�����٣�������ʼ�� 
	while (flag) {
		c = strs[0][count];
		for (int j = 0; j < strsSize; j++) {
			if ((strs[j][count]=='\0') || (strs[j][count] != c)) {		//�˳����� 
				flag = false;
				break; 
			}
		}
		str[count] = c;						// һ�����ַ����� 
		count++;
	}
	str[count-1] = '\0';					// ȥ�����һ�� 
	return str;
}



int main()
{
	const char* s[] = { "flower","flow","flight" };
	char** strs = (char**)s;
	char* buff = longestCommonPrefix(strs, 3);
	puts(buff);
	return 0;
}

