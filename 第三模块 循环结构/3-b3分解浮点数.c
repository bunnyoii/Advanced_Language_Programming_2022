/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	int b, c, d, e;
	printf("������[0-100��)֮������� : \n");
	scanf("%lf", &a);

	a = a + 0.001;

	printf("ʮ��λ : ");
	printf("%d\n", (int)(a / 1000000000) % 10);
	printf("��λ   : ");
	printf("%d\n", (int)(a / 100000000) % 10);
	printf("ǧ��λ : ");
	printf("%d\n", (int)(a / 10000000) % 10);
	printf("����λ : ");
	printf("%d\n", (int)(a / 1000000) % 10);
	printf("ʮ��λ : ");
	printf("%d\n", (int)(a / 100000) % 10);
	printf("��λ   : ");
	printf("%d\n", (int)(a / 10000) % 10);
	printf("ǧλ   : ");
	printf("%d\n", (int)(a / 1000) % 10);
	printf("��λ   : ");
	printf("%d\n", (int)(a / 100) % 10);
	printf("ʮλ   : ");
	printf("%d\n", (int)(a / 10) % 10);

	a = a / 10 - (int)(a / 10);
	b = (int)(a * 1000);
	c = b / 100 % 10;
	d = b / 10 % 10;
	e = b % 10;
	printf("Բ     : ");
	printf("%d\n", c);
	printf("��     : ");
	printf("%d\n", d);
	printf("��     : ");
	printf("%d\n", e);
	return 0;
}