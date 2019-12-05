#include <stdio.h> 
#include <malloc.h>

int removeElement(int* nums, int numsSize, int val) {
	int i = 0;							//慢指针，记录重新组合数组下标  
	int j = 0;							//快指针，记录原始数组下标  

	for (j = 0; j < numsSize; j++) {
		if (nums[j] != val) {			//如果不等于就把原始数组当前值赋给重新组合数组
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}

int main() {
	int nums[] = { 0,1,2,2,3,0,4,2 };
	int numsSize = sizeof(nums) / sizeof(int);
	int val = 2;

	int n = removeElement(nums, numsSize, val);
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	return 0;
}
