/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	double a = 3, b = 4, pi = 3.14159;
	double d1, d2;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &d1, &d2);
	printf("Բ�ܳ�     : ");
	printf("%.2lf\n", 2 * pi * d1);
	printf("Բ���     : ");
	printf("%.2lf\n", pi * d1 * d1);
	printf("Բ������ : ");
	printf("%.2lf\n", 4 * pi * d1 * d1);
	printf("Բ�����   : ");
	printf("%.2lf\n", b / a * pi * d1 * d1);
	printf("Բ�����   : ");
	printf("%.2lf\n", pi * d1 * d1 * d2);

	return 0;
}