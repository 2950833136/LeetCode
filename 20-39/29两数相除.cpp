#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int divide(int dividend, int divisor) {
	int res = 0;
	bool flag = (dividend ^ divisor) < 0;			//�жϷ����Ƿ���ͬ����ͬΪ0����ͬΪ1�����������
	if (divisor == 1) {								//����Ϊ 1������
		return dividend;
	}
	if (divisor == INT_MIN) {					
		return dividend == INT_MIN ? 1 : 0;			//��������ֵ
	}

	if (dividend == INT_MIN) {						//����������ֵ
		if (divisor == -1) {						//���
			return INT_MAX;
		}
		else {										//Ϊ����ȡ����������dividend
			dividend = divisor < 0 ? dividend - divisor : INT_MAX - divisor + 1;
			res = 1;
		}
	}
	dividend = dividend < 0 ? -dividend : dividend;	//ȡ����
	divisor = divisor < 0 ? -divisor : divisor;
	for (int i = 31; i >= 0; i--) {					//����̰���㷨����λ���
		if (dividend >> i >= divisor) {
			res += 1 << i;
			dividend -= divisor << i;
		}
	}
	return flag ? -res : res;						//1Ϊ����0Ϊ��
}

int main() {
	int dividend;
	int divisor;
	printf("������ dividend: ");
	scanf("%d", &dividend);
	printf("������ divisor : ");
	scanf("%d", &divisor);

	int res = divide(dividend, divisor);
	printf("%d", res);

	return 0;
}
