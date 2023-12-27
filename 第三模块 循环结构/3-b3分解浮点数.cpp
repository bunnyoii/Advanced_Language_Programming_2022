/*2251730 信07 刘淑仪*/
#include <iostream>
using namespace std;
int main() {
	double a;
	int b, c, d, e;
	cout << "请输入[0-100亿)之间的数字 : " << endl;
	cin >> a;

	a = a + 0.001;

	cout << "十亿位 : " << (int)(a / 1000000000) % 10 << endl;
	cout << "亿位   : " << (int)(a / 100000000) % 10 << endl;
	cout << "千万位 : " << (int)(a / 10000000) % 10 << endl;
	cout << "百万位 : " << (int)(a / 1000000) % 10 << endl;
	cout << "十万位 : " << (int)(a / 100000) % 10 << endl;
	cout << "万位   : " << (int)(a / 10000) % 10 << endl;
	cout << "千位   : " << (int)(a / 1000) % 10 << endl;
	cout << "百位   : " << (int)(a / 100) % 10 << endl;
	cout << "十位   : " << (int)(a / 10) % 10 << endl;

	a = a / 10 - (int)(a / 10);
	b = (int)(a * 1000);
	c = b / 100 % 10;
	d = b / 10 % 10;
	e = b % 10;
	cout << "圆     : " << c << endl;
	cout << "角     : " << d << endl;
	cout << "分     : " << e << endl;
	return 0;
}
