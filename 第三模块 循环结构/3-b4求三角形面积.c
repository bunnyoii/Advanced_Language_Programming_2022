/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	double pi = 3.14159;
	int a, b, c;
	float x, S;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &a, &b, &c);

	x = (float)(pi * c / 180);
	S = (float)(0.5 * a * b * sin(x));

	printf("�����ε����Ϊ : ");
	printf("%.3lf", S);
	return 0;
}