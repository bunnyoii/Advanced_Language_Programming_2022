/* 2251730 信07 刘淑仪 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)
			strncat(result, &chnstr[0], 2);
		break;
	case 1:
		strncat(result, &chnstr[2], 2);
		break;
	case 2:
		strncat(result, &chnstr[4], 2);
		break;
	case 3:
		strncat(result, &chnstr[6], 2);
		break;
	case 4:
		strncat(result, &chnstr[8], 2);
		break;
	case 5:
		strncat(result, &chnstr[10], 2);
		break;
	case 6:
		strncat(result, &chnstr[12], 2);
		break;
	case 7:
		strncat(result, &chnstr[14], 2);
		break;
	case 8:
		strncat(result, &chnstr[16], 2);
		break;
	case 9:
		strncat(result, &chnstr[18], 2);
		break;
	default:
		printf("error");
		break;
	}
}

int main()
{
	double a;
	while (1) {
		printf("请输入[0-100亿)之间的数字:\n");
		int ret = scanf("%lf", &a);
		if (ret == 1) {
			if (a >= 0 && a < 10000000000)
				break;
			else {
				while (getchar() != '\n')
					;
			}
		}
		else {
			while (getchar() != '\n')
				;
		}
	}
	a = a + 0.001;
	printf("大写结果是:\n");
	int b = (int)a;
	int c = (int)(a / 1000000000) % 10;//十亿
	int d = (int)(a / 100000000) % 10;//亿
	int e = (int)(a / 10000000) % 10;//千万
	int f = (int)(a / 1000000) % 10;//百万
	int g = (int)(a / 100000) % 10;//十万
	int h = (int)(a / 10000) % 10;//万
	int i = (int)(a / 1000) % 10;//仟
	int j = (int)(a / 100) % 10;//佰
	int k = (int)(a / 10) % 10;//拾
	a = a / 10 - (int)(a / 10);//降位
	int x = (int)(a * 1000);//扩大
	int y = x / 100 % 10;//圆
	int z = x / 10 % 10;//角
	int p = x % 10;//分

	char  danwei[19] = "拾佰仟万亿圆角分整";
	daxie(c, 0);
	if (c > 0)
		strncat(result, &danwei[0], 2);
	daxie(d, 0);
	if (c > 0 || d > 0)
		strncat(result, &danwei[8], 2);

	if (c > 0 || d > 0)
		daxie(e, f);
	else
		daxie(e, 0);
	if (e > 0)
		strncat(result, &danwei[4], 2);
	if (c > 0 || d > 0 || e > 0)
		daxie(f, g);
	else
		daxie(f, 0);
	if (f > 0)
		strncat(result, &danwei[2], 2);
	if (c > 0 || d > 0 || e > 0 || f > 0)
		daxie(g, h);
	else
		daxie(g, 0);
	if (g > 0)
		strncat(result, &danwei[0], 2);
	daxie(h, 0);
	if (e > 0 || f > 0 || g > 0 || h > 0)
		strncat(result, &danwei[6], 2);

	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0)
		daxie(i, j);
	else
		daxie(i, 0);
	if (i > 0)
		strncat(result, &danwei[4], 2);
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0)
		daxie(j, k);
	else
		daxie(j, 0);
	if (j > 0)
		strncat(result, &danwei[2], 2);
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0)
		daxie(k, y);
	else
		daxie(k, 0);
	if (k > 0)
		strncat(result, &danwei[0], 2);

	if (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && z == 0 && p == 0) {
		daxie(y, 1);
		strncat(result, &danwei[10], 2);
	}
	else if (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || y != 0)
	{
		daxie(y, 0);
		strncat(result, &danwei[10], 2);
	}
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0)
		daxie(z, p);
	else
		daxie(z, 0);
	if (z > 0)
		strncat(result, &danwei[12], 2);
	if (p == 0)
		strncat(result, &danwei[16], 2);
	if (p > 0) {
		if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0 || z > 0)
			daxie(p, 1);
		else
			daxie(p, 0);
		strncat(result, &danwei[14], 2);
	}
	printf("%s\n", result);
	return 0;
}
