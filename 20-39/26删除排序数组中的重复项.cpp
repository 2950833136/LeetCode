#include <stdio.h> 
#include <malloc.h>

int removeDuplicates(int* nums, int numsSize) {		//双指针求解 
	if (numsSize == 0) {
		return 0;
	}
	int n = 0;										//n 记录重新组合数组下标 
	for (int i = 1; i < numsSize; i++) {			//i 记录原始数组下标 
		if (nums[i] != nums[i - 1]) {				//如果不等于就把原始数组当前值赋给重新组合数组 
			n++;
			nums[n] = nums[i];
		}
	}
	return n + 1;
}

int main() {
	int nums[] = { 0,0,1,1,1,2,2,3,3,4 };
	int numsSize = sizeof(nums) / sizeof(int);
	int n = removeDuplicates(nums, numsSize);
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	return 0;
}
