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

void f3(double a, double b, double d)//相等实根
{
	double x;
	x = (-b + sqrt(d)) / (a * 2);
	if (fabs(x) >= 1e-6)
		;
	else
		x = 0;
	if (x == -0)
		x = 0;
	cout << "有两个相等实根：" << endl << "x1=x2=" << x << endl;
	return;
}

void f4(double a)
{//a=0
	cout << "不是一元二次方程" << endl;
	return;
}

int main(){
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;

	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	double d = b * b - 4 * a * c;
	if (fabs(d) < 1e-6)
		d = 0;

	if (a == 0)
		f4(a);
	else {
		if (d > 0)
			f1(a, b, d);
		else if (d < 0)
			f2(a, b, d);
		else
			f3(a, b, d);
	}

	return 0;
}