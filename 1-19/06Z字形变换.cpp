#include<stdio.h>
#include<string.h>
#include<malloc.h>

char* convert(char* s, int numRows){
	if (numRows == 1){												// 1就不用变换 
		return s;	
	}
	
	int key=0;														// 改变指针 
	int step = numRows * 2 - 2; 									// 间距
	int index = 0;													// 记录s的下标
	int add = 0; 													// 真实的间距
	int len=strlen(s);												// 字符串长度 
	char* z=(char*)malloc(sizeof(char)*(len+1));					// 分配空间，至少 len+1,不然会出现越界错误 
	for(int i=0;i<numRows;i++){
		index = i;													// 每行开始初始下标 
		add = i*2;
		while (index < len){										// 超出字符串长度计算下一层
			*(z+key)= s[index]; 									// 当前行的第一个字母 
			key++;
			add = step - add;										// 第一次间距是 step-2*i，第二次是 2*i
			index += (i == 0 || i == numRows-1) ? step : add; 		// 0行和最后一行使用step间距，其余使用add间距
		}
	}
	z[len] = '\0';													// 截止符，不然会出现越界错误  
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
