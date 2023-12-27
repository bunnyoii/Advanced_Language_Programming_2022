/*2251730 信07 刘淑仪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	double a = 3, b = 4, pi = 3.14159;
	double d1, d2;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &d1, &d2);
	printf("圆周长     : ");
	printf("%.2lf\n", 2 * pi * d1);
	printf("圆面积     : ");
	printf("%.2lf\n", pi * d1 * d1);
	printf("圆球表面积 : ");
	printf("%.2lf\n", 4 * pi * d1 * d1);
	printf("圆球体积   : ");
	printf("%.2lf\n", b / a * pi * d1 * d1);
	printf("圆柱体积   : ");
	printf("%.2lf\n", pi * d1 * d1 * d2);

	return 0;
}