#include<stdio.h>
#include<string.h>
#include<malloc.h>

bool isValid(char* s) {
	int length = strlen(s);										//�󳤶� 
	if (length == 0) {
		return true;
	}
	char* stack = (char*)malloc(sizeof(char) * (length/2+1));	//�������ռ� 
	int top = -1;

	for (int i = 0; i < length; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {		// ([{ �ͼ���ջ���� 
			top++;
			stack[top] = s[i];
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {	// )]} �Ͱ� ([{ �Ƴ� 
			if (top == -1) {									// ����)]} ��û�� ([{ 
				return false;
			}
			else if (s[i] == ')' && stack[top] == '(') {		//�Ƴ� 
				top--;
			}
			else if (s[i] == ']' && stack[top] == '[') {
				top--;
			}
			else if (s[i] == '}' && stack[top] == '{') {
				top--;
			}
			else {												//�����ַ����� false 
				return false;
			}
		}
		else {													//�����ַ����� false
			return false;
		}
	}
	return (top == -1 ? true : false);							//top==-1,��ջ������ջ��Ϊ�� 
}

int main() {
	char* s = (char*)"()[]";
	if (isValid(s) == true) {
		printf("true");
	}
	else {
		printf("false");
	}
	return 0;
}
