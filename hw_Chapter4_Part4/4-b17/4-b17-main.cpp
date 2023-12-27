/*2251730 信07 刘淑仪*/
#include<iostream>
#include<cmath>
using namespace std;

double a, b, c, d;

void f1();
void f2();
void f3();
void f4();
int main() {
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;

	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	d = b * b - 4 * a * c;
	if (fabs(d) < 1e-6)
		d = 0;

	if (a == 0)
		f4();
	else {
		if (d > 0)
			f1();
		else if (d < 0)
			f2();
		else
			f3();
	}

	return 0;
}
