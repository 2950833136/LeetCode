#include<stdio.h>
#include<string.h>
#include<malloc.h> 

//bool dp(int i,int j,char *s,char *p){
//	bool ans;
//	if(j == strlen(p) && i == strlen(s)){
//		ans = true;
//	}
//	else{
//		bool first_match = (i < strlen(s) && (p[j] == s[i] || p[j] == '.'));
//	    if (j + 1 < strlen(p) && p[j+1] == '*'){
//	        ans = (dp(i, j+2, s, p) || first_match && dp(i+1, j, s, p));
//	    } 
//		else {
//	        ans = first_match && dp(i+1, j+1, s, p);
//	    }
//	}
//	return ans;
//}

bool isMatch(char * s, char * p){
	int row = strlen(s);	//�� 
	int col = strlen(p);	//�� 
	int i, j, ret;
	//����ռ䣬ȫ����ʼ��Ϊ 0 
	int **dp = (int**)malloc(sizeof(int*)*(row+1));
	for(i = 0; i < row+1; i++) {
	      dp[i] = (int*)malloc(sizeof(int)*(col+1));
		  memset(dp[i], 0, col+1);
	}
	//��ʼ��ʼ��Ϊ 1
	dp[0][0] = 1;
	//��Ϊ '*' ƥ���������ǰ�����һ��Ԫ�أ�������� s û�У��� p Ϊ 'p*' ���ͻ���Ϊ�� 
	for(j = 1; j < col+1; j++) {
      	if(p[j-1] == '*' && dp[0][j-2] == 1){
      		dp[0][j] = 1;
		}
    }
	//ѭ��ƥ�� 
	for(i = 1; i < row+1; i++) {
		for(j = 1; j < col+1; j++) {
			// '.' ƥ�����ⵥ���ַ�
			if(p[j-1] == '.' && dp[i-1][j-1] == 1) {
			    dp[i][j] = 1;
			} 
			// '*' ƥ���������ǰ�����һ��Ԫ��
			else if(p[j-1] == '*') {
			    if(dp[i][j-2] == 1 || dp[i][j-1] == 1 || (dp[i-1][j] == 1 && (s[i-1] == p[j-2] || p[j-2] == '.'))){
			    	dp[i][j] = 1;
				}
			}
			// �ַ�һ�� 
			else {
			    if(dp[i-1][j-1] == 1 && s[i-1] == p[j-1]){
			    	dp[i][j] = 1;
				}
			}
	  	}
	}
	ret = dp[row][col];
	//�ͷ��ڴ� 
	for(i = 0; i <= row; i++)
	      free(dp[i]);
	free(dp);
	
	return ret == 1;
}

int main(){
	char *s = (char *)"aab";
	char *p = (char *)"c*a*b";
	if(isMatch(s, p)==true){
		printf("true");
	}
	else{
		printf("false");
	}
	return 0;
}

