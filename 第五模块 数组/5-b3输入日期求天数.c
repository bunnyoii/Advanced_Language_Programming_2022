//2251730 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool leap(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int day(int L, int m, int d)
{
	int day1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int day0[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = d;
	if (L == 1) {
		for (int i = 0; i < m; i++)
			sum = sum + day1[i];
	}
	else {
		for (int i = 0; i < m; i++)
			sum = sum + day0[i];
	}
	return sum;
}
int main()
{
	int y, m, d, b;
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &y, &m, &d);
	bool L = leap(y);
	if (m > 12 || m < 1) {
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}
	else if ((d > 31 || d <= 0) || (L == 0 && m == 2 && d > 28) || ((m == 4 || m == 6 || m == 9 || m == 11) && d >= 31) || (L == 1 && m == 2 && d > 29)) {
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 0;
	}
	int  a = day(L, m, d);
	printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, a);
	return 0;
}