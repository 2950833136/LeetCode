#include<stdio.h> 
#include<limits.h>

int max(int x,int y){			//������ֵ 
	return x>y?x:y;
}

int min(int x,int y){			//���С��ֵ 
	return x<y?x:y;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	//��֤����1һ�����
	if (nums1Size > nums2Size){
		return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
	}
	
	//ai_LMax Ϊ���������Ԫ�����ֵ��ai_RMin Ϊ���������Ԫ����Сֵ�� 
	int a1_LMax, a1_RMin, a2_LMax, a2_RMin;
	//ci Ϊ��i��������и�㡣 
	int c1, c2;
	//����Ŀǰ���������'#'��������1��2*n����
	int low = 0, high = 2*nums1Size;
	//���Ρ�����������ͬʱ�ָ� 
	while(low<=high){
		c1=(low+high)/2;										//����1 ���и�� 
		c2=nums1Size+nums2Size-c1;								//����2 ���и��
		
		//�ж����� a1_LMax<=a2_RMin��a2_LMax<=a1_RMin�� 
		//����Ҫ������1��С������2���򶼴�������2����Ҫ���� INT_MIN��INT_MAX�������������ֵ����Сֵ 
		//�Ͱ����ֵ����Сֵ������ RMin��LMax������ֹ�����жϣ����������±�Խ�硣 
		a1_LMax= (c1==0) ? INT_MIN:nums1[(c1-1)/2];				//�и����ߵ�ֵ��������������ߵ����ֵ�� 
		a1_RMin= (c1==2*nums1Size) ? INT_MAX:nums1[c1/2];		//�и���ұߵ�ֵ 
		a2_LMax= (c2==0) ? INT_MIN:nums2[(c2-1)/2];
		a2_RMin= (c2==2*nums2Size) ? INT_MAX:nums2[c2/2];
		
		if (a1_LMax > a2_RMin){									 
			high=c1-1;
		}
		else if (a2_LMax > a1_RMin){
			low=c1+1;
		}
		else{
			break;
		}
	}
	//��ӡ������� 
	printf("a1_LMax= %d\n",a1_LMax);											
	printf("a1_RMin= %d\n",a1_RMin);
	printf("a2_LMax= %d\n",a2_LMax);
	printf("a2_RMin= %d\n",a2_RMin);
	
	//����������ĺ��ұ���С�ĵõ��ľ�����λ�� 
	return (max(a1_LMax, a2_LMax) + min(a1_RMin, a2_RMin)) / 2.0;
}

int main(){
//	int array1[]={2,3,5};
//	int array2[]={1,4,7,9};
	int array1[]={1,2,3,4};
	int array2[]={6,7,8,9,11};
	int size1=sizeof(array1)/sizeof(int);
	int size2=sizeof(array2)/sizeof(int);
	
	double result=findMedianSortedArrays(array1,size1,array2,size2);
	printf("%lf",result);
	
	return 0;
}
