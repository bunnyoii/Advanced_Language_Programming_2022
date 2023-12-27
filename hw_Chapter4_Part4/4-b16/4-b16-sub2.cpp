/*2251730 信07 刘淑仪*/
#include<iostream>
#include<cmath>
using namespace std;

void f2(double a, double b, double d)
{//虚根
	double xd, xf;
	xd = (-b) / (a * 2);
	xf = sqrt(-d) / (a * 2);
	if (fabs(xd) < 1e-6)
		xd = 0;
	if (xd == 0) {
		if (xf < 0)
			xf = -xf;
		if (fabs(xf - 1) < 1e-6 || fabs(xf) == 1)
			cout << "有两个虚根：" << endl << "x1=i" << endl << "x2=-i" << endl;
		else
			cout << "有两个虚根：" << endl << "x1=" << fabs(xf) << "i" << endl << "x2=" << "-" << fabs(xf) << "i" << endl;
	}
	else {
		if (xf < 0)
			xf = -xf;
		if (fabs(xf - 1) < 1e-6 || fabs(xf) == 1)
			cout << "有两个虚根：" << endl << "x1=" << xd << "+i" << endl << "x2=" << xd << "-i" << endl;
		else
			cout << "有两个虚根：" << endl << "x1=" << xd << "+" << fabs(xf) << "i" << endl << "x2=" << xd << "-" << fabs(xf) << "i" << endl;
	}
	return;
}