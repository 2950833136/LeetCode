#include <stdio.h> 
#include <malloc.h>

int removeElement(int* nums, int numsSize, int val) {
	int i = 0;							//��ָ�룬��¼������������±�  
	int j = 0;							//��ָ�룬��¼ԭʼ�����±�  

	for (j = 0; j < numsSize; j++) {
		if (nums[j] != val) {			//��������ھͰ�ԭʼ���鵱ǰֵ���������������
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
