/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	double a;
	int b, c, d, e, f, g, h, i, j, k, x, y;
	printf("����������ֵ��\n");
	scanf("%lf", &a);
	b = (int)(a / 50);
	c = (int)((a - 50 * b) / 20);
	d = (int)((a - 50 * b - c * 20) / 10);
	e = (int)((a - 50 * b - c * 20 - d * 10) / 5);
	f = (int)(a - 50 * b - c * 20 - d * 10 - e * 5);
	x = (int)((a - (int)(a)) * 10 + 0.0001);
	g = x / 5;
	h = x - g * 5;
	y = (int)((a - (int)(a)) * 100 - x * 10 + 0.0002);
	i = y / 5;
	j = (y - i * 5) / 2;
	k = y - i * 5 - j * 2;
	printf("��");
	printf("%d", b + c + d + e + f + g + h + i + j + k);
	printf("�����㣬�������£�\n");
	while (b > 0) {
		printf("50Ԫ : ");
		printf("%d", b);
		printf("��\n");
		break;
	}
	while (c > 0) {
		printf("20Ԫ : ");
		printf("%d", c);
		printf("��\n");
		break;
	}
	while (d > 0) {
		printf("10Ԫ : ");
		printf("%d", d);
		printf("��\n");
		break;
	}
	while (e > 0) {
		printf("5Ԫ : ");
		printf("%d", e);
		printf("��\n");
		break;
	}
	while (f > 0) {
		printf("1Ԫ : ");
		printf("%d", f);
		printf("��\n");
		break;
	}
	while (g > 0) {
		printf("5�� : ");
		printf("%d", g);
		printf("��\n");
		break;
	}
	while (h > 0) {
		printf("1�� : ");
		printf("%d", h);
		printf("��\n");
		break;
	}
	while (i > 0) {
		printf("5�� : ");
		printf("%d", i);
		printf("��\n");
		break;
	}
	while (j > 0) {
		printf("2�� : ");
		printf("%d", j);
		printf("��\n");
		break;
	}
	while (k > 0) {
		printf("1�� : ");
		printf("%d", k);
		printf("��\n");
		break;
	}
	return 0;
}