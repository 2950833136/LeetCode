#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void quickSort(int* nums, int first, int end) {     //�������� 
	int temp, l, r;
	if (first >= end) {
		return;
	}
	temp = nums[first];
	l = first;
	r = end;
	while (l < r) {
		while (l < r && nums[r] >= temp) {
			r--;
		}
		if (l < r) {
			nums[l] = nums[r];
		}
		while (l < r && nums[l] <= temp) {
			l++;
		}
		if (l < r) {
			nums[r] = nums[l];
		}
	}
	nums[l] = temp;
	quickSort(nums, first, l - 1);
	quickSort(nums, l + 1, end);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i = 0;								//��ǰ��ֵ�±�
	int left = i + 1;						//��ָ��
	int right = numsSize - 1;				//��ָ��
	int sum = 0;							//��
	int base_alloc_size = 16;				//�����ڴ�
	int** res = (int**)malloc(sizeof(int*) * base_alloc_size);
	(*returnSize) = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * base_alloc_size);

	if (numsSize < 3 || nums == NULL) {
		return NULL;
	}

	quickSort(nums, 0, numsSize - 1);                           //����

	for (i = 0; i <= numsSize - 3; i++) {
		left = i + 1;
		right = numsSize - 1;
		if (nums[i] > 0) {										// �����ǰ���ִ���0��������֮��һ������0�����Խ���ѭ��
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {						// ȥ��
			continue;
		}
		while (left < right) {
			sum = nums[i] + nums[left] + nums[right];
			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				res[*returnSize] = (int*)calloc(3, sizeof(int));
				res[*returnSize][0] = nums[i];
				res[*returnSize][1] = nums[left];
				res[*returnSize][2] = nums[right];

				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;

				while (left < right && nums[left] == nums[left + 1]) {		//ȥ���ظ���
					left++;
				}
				while (left < right && nums[right] == nums[right - 1]) {
					right--;
				}
				left++; right--;
			}

			if (*returnSize == base_alloc_size) {							//�ռ䲻�㣬�����ڴ�
				base_alloc_size = base_alloc_size * 2;
				res = (int**)realloc(res, base_alloc_size * sizeof(int*));
				(*returnColumnSizes) = (int*)realloc((*returnColumnSizes), base_alloc_size * sizeof(int));
			}
		}
	}
	return res;
}

int main() {
	int num[] = { -1, 0, 1, 2, -1, -4 };
	int* nums = (int*)num;
	int numsSize = sizeof(num) / sizeof(int);
	int* returnSize = (int*)malloc(sizeof(int)*1);
	//������ڴ�������ֵ,���������֪ʶ,C��ȡ3
	//C6ȡ3 == 20
	int** returnColumnSizes = (int**)malloc(sizeof(int*) * (numsSize * (numsSize - 1) * (numsSize - 2)) / 6);
	int** res = threeSum(nums, numsSize, returnSize, returnColumnSizes);

	for (int i = 0; i < *returnSize; i++) {				//��ӡ
		for (int j = 0; j < 3; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
