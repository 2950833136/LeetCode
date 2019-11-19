#include<stdio.h>

int lengthOfLongestSubstring(char * s){
	int i = 0;								//用于遍历字符串，记录字符串该遍历到哪里 
	int j = 0;								//用于遍历子串
	int n = 0;								//用于保存最大长度
	int index = 0;							//用于指向子串的第一个元素
	while(s[i]!='\0'){						
		for (j = index; j < i; j++){		//上个子串开始点，至遍历点 
			if (s[j] == s[i]){
				break;
			}
		}
		if (j != i){						//代表遇到了重复元素
			n = (i-index) > n?(i-index):n;
			index = j+1;					//下一个不含重复的子串的开始点 
		}
		i++;
	}
	n = (i-index) > n?(i-index):n;			//当字符串没有重复的或最后一次没有重复，得到子串比较 
	return n;
} 

int main(){
	char *s=(char *)"abcabcbb";
	int n=lengthOfLongestSubstring(s);
	printf("%d",n);
	
	return 0; 
} 

/*

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

*/
