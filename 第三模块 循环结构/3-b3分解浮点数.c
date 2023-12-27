/*2251730 信07 刘淑仪*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a;
	int b, c, d, e;
	printf("请输入[0-100亿)之间的数字 : \n");
	scanf("%lf", &a);

	a = a + 0.001;

	printf("十亿位 : ");
	printf("%d\n", (int)(a / 1000000000) % 10);
	printf("亿位   : ");
	printf("%d\n", (int)(a / 100000000) % 10);
	printf("千万位 : ");
	printf("%d\n", (int)(a / 10000000) % 10);
	printf("百万位 : ");
	printf("%d\n", (int)(a / 1000000) % 10);
	printf("十万位 : ");
	printf("%d\n", (int)(a / 100000) % 10);
	printf("万位   : ");
	printf("%d\n", (int)(a / 10000) % 10);
	printf("千位   : ");
	printf("%d\n", (int)(a / 1000) % 10);
	printf("百位   : ");
	printf("%d\n", (int)(a / 100) % 10);
	printf("十位   : ");
	printf("%d\n", (int)(a / 10) % 10);

	a = a / 10 - (int)(a / 10);
	b = (int)(a * 1000);
	c = b / 100 % 10;
	d = b / 10 % 10;
	e = b % 10;
	printf("圆     : ");
	printf("%d\n", c);
	printf("角     : ");
	printf("%d\n", d);
	printf("分     : ");
	printf("%d\n", e);
	return 0;
}