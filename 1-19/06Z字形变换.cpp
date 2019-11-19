#include<stdio.h>
#include<string.h>
#include<malloc.h>

char* convert(char* s, int numRows){
	if (numRows == 1){												// 1�Ͳ��ñ任 
		return s;	
	}
	
	int key=0;														// �ı�ָ�� 
	int step = numRows * 2 - 2; 									// ���
	int index = 0;													// ��¼s���±�
	int add = 0; 													// ��ʵ�ļ��
	int len=strlen(s);												// �ַ������� 
	char* z=(char*)malloc(sizeof(char)*(len+1));					// ����ռ䣬���� len+1,��Ȼ�����Խ����� 
	for(int i=0;i<numRows;i++){
		index = i;													// ÿ�п�ʼ��ʼ�±� 
		add = i*2;
		while (index < len){										// �����ַ������ȼ�����һ��
			*(z+key)= s[index]; 									// ��ǰ�еĵ�һ����ĸ 
			key++;
			add = step - add;										// ��һ�μ���� step-2*i���ڶ����� 2*i
			index += (i == 0 || i == numRows-1) ? step : add; 		// 0�к����һ��ʹ��step��࣬����ʹ��add���
		}
	}
	z[len] = '\0';													// ��ֹ������Ȼ�����Խ�����  
	return z;
}

int main(){
	char* s=(char*)"LEETCODEISHIRING";
	
	char* z1=convert(s,3);
	printf("numRows=%d  ",3);
	printf("%s",z1);
	printf("\n");
	
	char* z2=convert(s,4);
	printf("numRows=%d  ",4);
	printf("%s",z2);
	
	return 0;
} 
