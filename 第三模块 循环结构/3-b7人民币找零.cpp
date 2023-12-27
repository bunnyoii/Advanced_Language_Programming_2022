//2251730 信07 刘淑仪
#include<iostream>
using namespace std;
int main() {
	double a;
	int b, c, d, e, f, g, h, i, j, k, x, y;
	cout << "请输入找零值：" << endl;
	cin >> a;
	b = int(a / 50);
	c = int((a - 50 * b) / 20);
	d = int((a - 50 * b - c * 20) / 10);
	e = int((a - 50 * b - c * 20 - d * 10) / 5);
	f = int(a - 50 * b - c * 20 - d * 10 - e * 5);
	x = int((a - int(a)) * 10 + 0.0001);
	g = x / 5;
	h = x - g * 5;
	y = int((a - int(a)) * 100 - x * 10 + 0.0002);
	i = y / 5;
	j = (y - i * 5) / 2;
	k = y - i * 5 - j * 2;
	cout << "共" << b + c + d + e + f + g + h + i + j + k << "张找零，具体如下：" << endl;
	while (b > 0) {
		cout << "50元 : " << b << "张" << endl;
		break;
	}
	while (c > 0) {
		cout << "20元 : " << c << "张" << endl;
		break;
	}
	while (d > 0) {
		cout << "10元 : " << d << "张" << endl;
		break;
	}
	while (e > 0) {
		cout << "5元  : " << e << "张" << endl;
		break;
	}
	while (f > 0) {
		cout << "1元  : " << f << "张" << endl;
		break;
	}
	while (g > 0) {
		cout << "5角  : " << g << "张" << endl;
		break;
	}
	while (h > 0) {
		cout << "1角  : " << h << "张" << endl;
		break;
	}
	while (i > 0) {
		cout << "5分  : " << i << "张" << endl;
		break;
	}
	while (j > 0) {
		cout << "2分  : " << j << "张" << endl;
		break;
	}
	while (k > 0) {
		cout << "1分  : " << k << "张" << endl;
		break;
	}
	return 0;
}