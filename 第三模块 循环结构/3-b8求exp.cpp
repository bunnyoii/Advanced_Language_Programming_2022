/*2251730 信07 刘淑仪*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	int x;
	int m = 1;
	double n, e = 1, e0 = 0;//m为分母阶乘，i为指数
	cout << "请输入x的值[-10~+65]" << endl;
	cin >> x;
	while (x > 65 || x < -10) {
		cout << "输入非法，请重新输入" << endl;
		cin >> x;
	}
	cout << setprecision(10);
	int i = 1, j = 1;
	for (i, j; i <= 20 && j <= 20; ++i, ++j) {
		e0 = pow(x, i);
		m = m * j;
		n = e0 / m;
		e = e + n;
		if ((abs(n)) >= 1e-6)
			continue;
		else
			break;
	}
	cout << "e^" << x << "=" << e << endl;
	return 0;
}