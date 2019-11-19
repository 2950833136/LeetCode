#include<stdio.h>
#include<string.h>
#include<limits.h>

int myAtoi(char *str) {
	int key = 0;					//��¼�ַ����±�
	int N = strlen(str);			//��¼�ַ�������
	int sign = 1;					//��¼����
	int ret = 0;					//��¼���
	// 1�������ַ���ǰ��Ŀո�
	while (key < N && str[key] == ' ') key++;

	// 2.1�������ڷǿո��ַ�c
	if (key == N) return 0;
	// 2.2��cΪ'-'
	else if (str[key] == '-') sign = -1;
	// 2.2��cΪ'+'
	else if (str[key] == '+') sign = 1;
	// 2.4��cΪ����
	else if ('0' <= str[key] && str[key] <= '9') ret = str[key] - '0';
	// 2.5���������
	else 
		return 0;

	// 3����������c����������ַ�
	while (key++ < N && '0' <= str[key] && str[key] <= '9') {
		int t = (str[key] - '0') * sign;
		// ����������INT_MAX������INT_MAX
		if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && t > 7) return INT_MAX;
		// ������С��INT_MIN������INT_MIN
		if (ret < INT_MIN / 10 || ret == INT_MIN / 10 && t < -8) return INT_MIN;
		ret = ret * 10 + t;
	}
	return ret;
}

int main(){
	char *str =(char*) "4193 with words";
	int x = myAtoi(str);
	printf("%d", x);
	return 0;
}
