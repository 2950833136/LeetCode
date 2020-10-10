#include<stdio.h>

//int romanToInt(char * s){
//	int num = 0;
//	int i=0;
//	while(s[i] != '\0'){
//		switch(s[i]){
//			case 'M':num += 1000;break;
//			case 'D':num += 500;break;
//			case 'C':
//				switch(s[i+1]){
//					case 'D':num += 400;i++;break;
//					case 'M':num += 900;i++;break;
//					default :num += 100;break;
//				};
//				break;
//			case 'L':num += 50;break;
//			case 'X':
//				switch(s[i+1]){
//					case 'L':num += 40;i++;break;
//					case 'C':num += 90;i++;break;
//					default :num += 10;break;
//				};
//				break;
//			case 'V':num += 5;break;
//			case 'I':
//				switch(s[i+1]){
//					case 'V':num += 4;i++;break;
//					case 'X':num += 9;i++;break;
//					default :num += 1;break;
//				};
//				break;
//		}
//		i++;
//	}
//	return num;
//}

int romanToInt(char * s){
	int num=0;
	while(*s != '\0'){
		switch(*s){
			case 'M':num += 1000;break;
			case 'D':num += 500;break;
			case 'C':
				switch(*(s+1)){
					case 'D':num += 400;*s++;break;
					case 'M':num += 900;*s++;break;
					default :num += 100;break;
				};
				break;
			case 'L':num += 50;break;
			case 'X':
				switch(*(s+1)){
					case 'L':num += 40;*s++;break;
					case 'C':num += 90;*s++;break;
					default :num += 10;break;
				};
				break;
			case 'V':num += 5;break;
			case 'I':
				switch(*(s+1)){
					case 'V':num += 4;*s++;break;
					case 'X':num += 9;*s++;break;
					default :num += 1;break;
				};
				break;
		}
		*s++;
	}
	return num;
}

int main(){
	char *s=(char*)"MCMXCIV";
	int num=romanToInt(s); 
	printf("%d\n",num);
	return 0;
} 
