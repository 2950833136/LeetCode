#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>

void dfs(char** result, char* str, int left, int right, int n, int* returnSize) {
	if ((left + right) == 2 * n) {							//���������ս�� 
		result[*returnSize] = (char*)malloc(sizeof(char*) * (2 * n + 1));
		memcpy(result[*returnSize], str, 2 * n);			//��������� str �� result 
		result[*returnSize][2 * n] = '\0';					//������ 
		*returnSize = *returnSize + 1;						//ÿ���һ���������� 1 
		return;
	}
	if (left < n) {											//Ҫ�����ź������ȿ��������ţ��������� >= ���������� 
		strcat(str, "(");									//׷�ӿ��� 
		dfs(result, str, left + 1, right, n, returnSize);	//�ݹ� 
		str[left + right] = '\0';
	}
	if (left > right) {										//ͬ�� 
		strcat(str, ")");
		dfs(result, str, left, right + 1, n, returnSize);
		str[left + right] = '\0';
	}
}

char** generateParenthesis(int n, int* returnSize) {
	char** result = (char**)malloc(sizeof(char*) * 1500);		// ����ռ� 
	char* outStr = (char*)malloc(sizeof(char) * (n * 2 + 1));	//��2n+1�� ��������� 
	*outStr = 0;												//����ֵ 
	*returnSize = 0;
	
	dfs(result, outStr, 0, 0, n, returnSize);					//������ȱ��� 

	return result;
}

int main() {
	int n = 0;
	int* returnSize = (int*)malloc(sizeof(int) * 1);
	printf("���������Ŷ���\n");
	scanf("%d", &n);

	char** ans = generateParenthesis(n, returnSize);
	for (int i = 0; i < *returnSize; i++) {
		for (int j = 0; j < 2 * n + 1; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
