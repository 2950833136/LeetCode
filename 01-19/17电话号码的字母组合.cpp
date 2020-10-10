#include<stdio.h>
#include<string.h>
#include<malloc.h>

//char** letterCombinations(char* digits, int* returnSize) {
//	int n = strlen(digits);
//	if (n == 0) {
//		*returnSize = 0;
//		return NULL;
//	}
//	int count = 1;
//	for (int i = 0; i < n; i++) {							//�������ո��� 
//		if (digits[i] == '7' || digits[i] == '9') {
//			count *= 4;
//		}
//		else {
//			count *= 3;
//		}
//	}
//	char** res = (char**)malloc(sizeof(char*) * count);		//����ռ� 
//	for (int i = 0; i < count; i++) {
//		res[i] = (char*)malloc(sizeof(char) * (n+1));
//	}
//	int k = 0;
//	int row = 1;
//	for (int i = 0; i < n; i++) {
//		switch (digits[i]) {
//		case '2':
//			for (int j = 0; j < row; j++) {					//��������� 
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++) {					//����������ĸ 
//				res[j][k] = 'a';
//				res[j + row][k] = 'b';
//				res[j + 2 * row][k] = 'c';
//			}
//			k++;
//			row *= 3;										//������ 
//			break;
//		case '3':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 'd';
//				res[j + row][k] = 'e';
//				res[j + 2 * row][k] = 'f';
//			}
//			k++;
//			row *= 3;
//			break;
//		case '4':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 'g';
//				res[j + row][k] = 'h';
//				res[j + 2 * row][k] = 'i';
//			}
//			k++;
//			row *= 3;
//			break;
//		case '5':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 'j';
//				res[j + row][k] = 'k';
//				res[j + 2 * row][k] = 'l';
//			}
//			k++;
//			row *= 3;
//			break;
//		case '6':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 'm';
//				res[j + row][k] = 'n';
//				res[j + 2 * row][k] = 'o';
//			}
//			k++;
//			row *= 3;
//			break;
//		case '7':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//				strcpy(res[j + 3 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 'p';
//				res[j + row][k] = 'q';
//				res[j + 2 * row][k] = 'r';
//				res[j + 3 * row][k] = 's';
//			}
//			k++;
//			row *= 4;
//			break;
//		case '8':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 't';
//				res[j + row][k] = 'u';
//				res[j + 2 * row][k] = 'v';
//			}
//			k++;
//			row *= 3;
//			break;
//		case '9':
//			for (int j = 0; j < row; j++){
//				strcpy(res[j + row], res[j]);
//				strcpy(res[j + 2 * row], res[j]);
//				strcpy(res[j + 3 * row], res[j]);
//			}
//			for (int j = 0; j < row; j++){
//				res[j][k] = 'w';
//				res[j + row][k] = 'x';
//				res[j + 2 * row][k] = 'y';
//				res[j + 3 * row][k] = 'z';
//			}
//			k++;
//			row *= 4;
//			break;
//		}
//	}
//	for (int i = 0; i < count; i++){
//		res[i][k] = '\0';
//	}
//	*returnSize = count;
//	return res;
//}

char** letterCombinations(char* digits, int* returnSize) {
	if (!strcmp(digits, "") || digits == NULL) {				//��ֱ�ӷ��� 
		*returnSize = 0;
		return NULL;
	}

	const char* str[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	int inputLength = strlen(digits);							//����ĳ��� 
	int* number = (int*)malloc(sizeof(int) * inputLength);
	int outputLength = 1;										//����ĸ��� 
	for (int i = 0; i < inputLength; i++) {						//�ó������������ 
		number[i] = digits[i] - '0';							//����� 0 �Ĳ�ֵ��ASCII�룩 
		outputLength *= strlen(str[number[i] - 2]);				//�� 2 ��ʼ�� 
	}
	char** ch = (char**)malloc(sizeof(char*) * outputLength);	//�������ָ��ռ� 
	for (int i = 0; i < outputLength; i++) {
		ch[i] = (char*)malloc(sizeof(char) * (inputLength + 1));//����һ��ָ��ռ䣬�����һ���Ž����� 
	}

	int k = 1;
	for (int i = 0; i < inputLength; i++) {
		int len = strlen(str[number[i] - 2]);					//���嵱ǰ���ִ������ַ� 
		k *= len;
		int block = outputLength / k;							//������ 
		for (int j = 0; j < k; j++) {							//���μ��뵱ǰ���ֵ��ַ� 
			for (int r = j * block; r < (j + 1) * block; r++) {	//�������ֵ 
				ch[r][i] = str[number[i] - 2][j % len];			
			}
		}
	}

	for (int i = 0; i < outputLength; i++) {					//������ 
		ch[i][inputLength] = '\0';
	}
	*returnSize = outputLength;
	return ch;
}

int main(){
	char* digits=(char*)"23";
	int* returnSize=(int*)malloc(sizeof(int)*1);
	int length=sizeof(digits)/sizeof(char);
	char** res=letterCombinations(digits,returnSize);
	
	for(int i=0;i<*returnSize;i++){
		for(int j=0;j<length;j++){
			printf("%c",res[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
