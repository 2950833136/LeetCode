#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>

void dfs(char** result, char* str, int left, int right, int n, int* returnSize) {
	if ((left + right) == 2 * n) {							//结束，最终结果 
		result[*returnSize] = (char*)malloc(sizeof(char*) * (2 * n + 1));
		memcpy(result[*returnSize], str, 2 * n);			//拷贝合理的 str 到 result 
		result[*returnSize][2 * n] = '\0';					//截至符 
		*returnSize = *returnSize + 1;						//每完成一个，计数加 1 
		return;
	}
	if (left < n) {											//要是括号合理，优先考虑左括号（左括号数 >= 右括号数） 
		strcat(str, "(");									//追加拷贝 
		dfs(result, str, left + 1, right, n, returnSize);	//递归 
		str[left + right] = '\0';
	}
	if (left > right) {										//同理 
		strcat(str, ")");
		dfs(result, str, left, right + 1, n, returnSize);
		str[left + right] = '\0';
	}
}

char** generateParenthesis(int n, int* returnSize) {
	char** result = (char**)malloc(sizeof(char*) * 1500);		// 分配空间 
	char* outStr = (char*)malloc(sizeof(char) * (n * 2 + 1));	//（2n+1） 多个截至符 
	*outStr = 0;												//赋初值 
	*returnSize = 0;
	
	dfs(result, outStr, 0, 0, n, returnSize);					//深度优先遍历 

	return result;
}

int main() {
	int n = 0;
	int* returnSize = (int*)malloc(sizeof(int) * 1);
	printf("请输入括号对数\n");
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
