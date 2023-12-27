/* 2251730 信07 刘淑仪 */
#include <iostream>
#include<conio.h>
using namespace std;

#define  N  10
#define NULL 0

int main()
{
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;

	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	gets_s(str);
	for (p = str, pa = a, pnum = a; *p != '\0' && (pa - pnum) < 10; p++) {
		if (*p >= '0' && *p <= '9') {
			*pa = *pa * 10 + *p - 48;
			if (*(p + 1) < '0' || *(p + 1) > '9') {
				pa++;
			}
		}
	}
	cout << "共有" << pa - pnum << "个整数" << endl;
	while (1) {
		if (pnum < pa) {
			cout << *pnum << " ";
			pnum++;
		}
		else
			break;
	}
	return 0;
}