#include<stdio.h>

int lengthOfLongestSubstring(char * s){
	int i = 0;								//���ڱ����ַ�������¼�ַ����ñ��������� 
	int j = 0;								//���ڱ����Ӵ�
	int n = 0;								//���ڱ�����󳤶�
	int index = 0;							//����ָ���Ӵ��ĵ�һ��Ԫ��
	while(s[i]!='\0'){						
		for (j = index; j < i; j++){		//�ϸ��Ӵ���ʼ�㣬�������� 
			if (s[j] == s[i]){
				break;
			}
		}
		if (j != i){						//�����������ظ�Ԫ��
			n = (i-index) > n?(i-index):n;
			index = j+1;					//��һ�������ظ����Ӵ��Ŀ�ʼ�� 
		}
		i++;
	}
	n = (i-index) > n?(i-index):n;			//���ַ���û���ظ��Ļ����һ��û���ظ����õ��Ӵ��Ƚ� 
	return n;
} 

int main(){
	char *s=(char *)"abcabcbb";
	int n=lengthOfLongestSubstring(s);
	printf("%d",n);
	
	return 0; 
} 

/*

����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:
����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

*/
