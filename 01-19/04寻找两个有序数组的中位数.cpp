#include<stdio.h> 
#include<limits.h>

int max(int x,int y){			//输出大的值 
	return x>y?x:y;
}

int min(int x,int y){			//输出小的值 
	return x<y?x:y;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	//保证数组1一定最短
	if (nums1Size > nums2Size){
		return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
	}
	
	//ai_LMax 为数组割后的左元素最大值。ai_RMin 为数组割后的右元素最小值。 
	int a1_LMax, a1_RMin, a2_LMax, a2_RMin;
	//ci 为第i个数组的切割点。 
	int c1, c2;
	//我们目前是虚拟加了'#'所以数组1是2*n长度
	int low = 0, high = 2*nums1Size;
	//分治——两个数组同时分割 
	while(low<=high){
		c1=(low+high)/2;										//数组1 的切割点 
		c2=nums1Size+nums2Size-c1;								//数组2 的切割点
		
		//判断条件 a1_LMax<=a2_RMin，a2_LMax<=a1_RMin。 
		//但是要是数组1都小于数组2，或都大于数组2，就要引入 INT_MIN、INT_MAX，替代数组的最大值和最小值 
		//就把最大值（最小值）赋给 RMin（LMax），防止继续判断，导致数组下标越界。 
		a1_LMax= (c1==0) ? INT_MIN:nums1[(c1-1)/2];				//切割点左边的值（有序，所以是左边的最大值） 
		a1_RMin= (c1==2*nums1Size) ? INT_MAX:nums1[c1/2];		//切割点右边的值 
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
	//打印结果看看 
	printf("a1_LMax= %d\n",a1_LMax);											
	printf("a1_RMin= %d\n",a1_RMin);
	printf("a2_LMax= %d\n",a2_LMax);
	printf("a2_RMin= %d\n",a2_RMin);
	
	//数组左边最大的和右边最小的得到的就是中位数 
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
