#include <stdio.h> 
#include <malloc.h>

int removeDuplicates(int* nums, int numsSize) {		//˫ָ����� 
	if (numsSize == 0) {
		return 0;
	}
	int n = 0;										//n ��¼������������±� 
	for (int i = 1; i < numsSize; i++) {			//i ��¼ԭʼ�����±� 
		if (nums[i] != nums[i - 1]) {				//��������ھͰ�ԭʼ���鵱ǰֵ��������������� 
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
