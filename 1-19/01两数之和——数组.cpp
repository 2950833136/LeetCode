#include<stdio.h>
#include<malloc.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int n=0;
	int *array=(int*)malloc(sizeof(int)*numsSize);
	for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                array[n]=i;
                array[n+1]=j;
                n=n+2;
            }
        }
    }
    *returnSize=n;
    if(*returnSize==0){
		printf("没有符合条件！");
	}
    return array;
}

int main(){
	int nums[]={2,7,11,15,3,4,5,6};
	int numsSize=sizeof(nums)/sizeof(int);
	printf("%d\n",numsSize);
	int target=9;
	int* returnSize=(int*)malloc(sizeof(int)*numsSize);
	
	int* array=twoSum(nums,numsSize,target,returnSize);
	
	for(int i=0;i<*returnSize/2;i++){
		printf("%d ",array[i*2]);
		printf("%d ",array[i*2+1]);	
		printf("\n");
	}
	
	return 0;
} 


/*

给定 nums = [2, 7, 11, 15], target = 9 因为 nums[0] + nums[1] = 2 + 7 = 9 所以返回 [0, 1]

*/ 
