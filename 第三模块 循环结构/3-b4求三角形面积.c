/*2251730 信07 刘淑仪*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	double pi = 3.14159;
	int a, b, c;
	float x, S;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &c);

	x = (float)(pi * c / 180);
	S = (float)(0.5 * a * b * sin(x));

	printf("三角形的面积为 : ");
	printf("%.3lf", S);
	return 0;
}