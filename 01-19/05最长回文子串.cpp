#include<stdio.h>
#include<string.h>
#include<malloc.h>

int max(int x,int y){
	return x>y?x:y;
}

int centerExpand(char* s,int left,int right,int len){
	while(left>=0 && right<len && s[left]==s[right]){
        left--;									//�ж��Ƿ���ȣ���Ⱦ������߼�����չ 
        right++;
    }
    return right-left-1;
}
 
char* longestPalindrome(char* s){
	int L=0;									//��¼�����Ӵ���󳤶� 
	int start=0;								//��¼�����Ӵ���ʼλ�� 
	int end=0;									//��¼�����Ӵ�����λ�� 
	int len=strlen(s);
	if(len==0||len==1)							//һ��һ��ֱ�ӷ��� 
        return s;
	for(int i=0;i<len;i++){
		int l1=centerExpand(s,i,i,len);			//�� i Ϊ���ĵ���չ 
		int l2=centerExpand(s,i,i+1,len);		//�� i �� i+1 Ϊ���ĵ���չ 
		L=max(max(l1,l2),L);					//ȡ��󳤶�Ϊ�������Ӵ� 
		
		if(L>end-start+1){
			start=i-(L-1)/2;					//�޸Ŀ�ʼλ�� 
			end=i+L/2;							//�޸Ľ���λ�� 
		}
	}
	
	char* p=(char*)malloc(sizeof(char)*(L+1));	//����ռ䣨���ȼ�һ���������� 
	strncpy(p,s+start,L);						//���ƣ��� s+start ������� L ���ȵ��ַ��� 
	p[L] = '\0';								//������ 
	return p;
}

int main(){
	char* s=(char*)"cbbd";
	char* p=longestPalindrome(s);
	
	while(*p!='\0'){
		printf("%c",*p);
		p++;
	}
	
	return 0;
} 
