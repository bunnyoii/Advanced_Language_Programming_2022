/*2251730 信07 刘淑仪*/
#include<iostream>
#include<cmath>
using namespace std;

void f1(double a, double b, double d);
void f2(double a, double b, double d);
void f3(double a, double b, double d);
void f4(double a);
int main() {
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
