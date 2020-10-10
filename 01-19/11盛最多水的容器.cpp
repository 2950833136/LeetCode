#include<stdio.h>
#include<string.h>
#include<malloc.h>

//第一种解法 （全部遍历） 
//int min(int x,int y){
//	return x<y?x:y;
//}
//
//int max(int x,int y){
//	return x>y?x:y;
//}
//
//int maxArea(int* height, int heightSize){
//	int res=0;
//	for(int i=0;i<heightSize-1;i++){
//		for(int j=i+1;j<heightSize;j++){
//			int area=(j-i)*min(height[i],height[j]);
//			res=max(area,res);
//		}
//	}
//	return res;
//}

//第二种解法 （双指针求解） 
int maxArea(int* height, int heightSize){
	int left = 0;
	int right = heightSize-1;
	int Area=0,maxArea=0;
	while(left<right){
	    if(height[left] > height[right]){
	        Area = (right-left)*height[right];
	        right--;
	    }
	    else{
	        Area = (right-left)*height[left];
	        left++;
	    }
	    maxArea=Area>maxArea?Area:maxArea;
	}
	return maxArea;
}

int main(){
	int height[]={1,8,6,2,5,4,8,3,7};
	int *heights=(int*)height;
	int heightSize=sizeof(height)/sizeof(int);
	int max=maxArea(heights,heightSize);
	printf("%d\n",max);
	return 0;
} 
