/*2251730 信07 刘淑仪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	double a;
	int b, c, d, e, f, g, h, i, j, k, x, y;
	printf("请输入找零值：\n");
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
	printf("共");
	printf("%d", b + c + d + e + f + g + h + i + j + k);
	printf("张找零，具体如下：\n");
	while (b > 0) {
		printf("50元 : ");
		printf("%d", b);
		printf("张\n");
		break;
	}
	while (c > 0) {
		printf("20元 : ");
		printf("%d", c);
		printf("张\n");
		break;
	}
	while (d > 0) {
		printf("10元 : ");
		printf("%d", d);
		printf("张\n");
		break;
	}
	while (e > 0) {
		printf("5元 : ");
		printf("%d", e);
		printf("张\n");
		break;
	}
	while (f > 0) {
		printf("1元 : ");
		printf("%d", f);
		printf("张\n");
		break;
	}
	while (g > 0) {
		printf("5角 : ");
		printf("%d", g);
		printf("张\n");
		break;
	}
	while (h > 0) {
		printf("1角 : ");
		printf("%d", h);
		printf("张\n");
		break;
	}
	while (i > 0) {
		printf("5分 : ");
		printf("%d", i);
		printf("张\n");
		break;
	}
	while (j > 0) {
		printf("2分 : ");
		printf("%d", j);
		printf("张\n");
		break;
	}
	while (k > 0) {
		printf("1分 : ");
		printf("%d", k);
		printf("张\n");
		break;
	}
	return 0;
}