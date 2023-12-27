/*2251730 信07 刘淑仪*/
#include<iostream>
#include<cmath>
using namespace std;

void f1(double a, double b, double d)
{//不等实根
	double x1, x2;

	x1 = (-b) / (a * 2) + sqrt(d) / (a * 2);
	x2 = (-b) / (a * 2) - sqrt(d) / (a * 2);
	if (x1 > x2) {
		if (fabs(x2) >= 1e-6)
			;
		else
			x2 = 0;
	}
	else {
		if (fabs(x1) >= 1e-6 || x1 == 0) {
			x2 = (-b) / (a * 2) + sqrt(d) / (a * 2);
			x1 = (-b) / (a * 2) - sqrt(d) / (a * 2);
		}
		else {
			x1 = 0;
			x2 = (-b) / (a * 2) + sqrt(d) / (a * 2);
		}
	}
	if (x1 == -0)
		x1 = 0;
	if (x2 == -0)
		x2 = 0;
	cout << "有两个不等实根：" << endl << "x1=" << x1 << endl << "x2=" << x2 << endl;
	return;

}