#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//bool isPalindrome(int x){
//    if (x < 0) {
//        return false;
//    }
//    int old = x;
//    long int rev = 0;
//    int pop = 0;
//    while (x != 0) {
//        pop = abs(x % 10);
//        x /= 10;
//        rev = rev * 10 + pop;
//    }
//
//    if (rev > INT_MAX || rev < INT_MIN) {
//        return false;
//    }
//    return rev == old;
//}

bool isPalindrome(int x){
	// ���������
    // ������������ x < 0 ʱ��x ���ǻ�������
    // ͬ���أ�������ֵ����һλ�� 0��Ϊ��ʹ������Ϊ���ģ�
    // �����һλ����ҲӦ���� 0
    // ֻ�� 0 ������һ����
	if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while(x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    // �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
    // ���磬������Ϊ 12321 ʱ���� while ѭ����ĩβ���ǿ��Եõ� x = 12��revertedNumber = 123��
    // ���ڴ�����λ�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
    return x == revertedNumber || x == revertedNumber/10;
}

int main(){
	int num=12321;
	if(isPalindrome(num)==true){
		printf("true");
	}
	else{
		printf("false");
	}
	return 0;
} 
