//2251730 ��07 ������
#include<iostream>
using namespace std;
int main() {
	double a;
	int b, c, d, e, f, g, h, i, j, k, x, y;
	cout << "����������ֵ��" << endl;
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
	cout << "��" << b + c + d + e + f + g + h + i + j + k << "�����㣬�������£�" << endl;
	while (b > 0) {
		cout << "50Ԫ : " << b << "��" << endl;
		break;
	}
	while (c > 0) {
		cout << "20Ԫ : " << c << "��" << endl;
		break;
	}
	while (d > 0) {
		cout << "10Ԫ : " << d << "��" << endl;
		break;
	}
	while (e > 0) {
		cout << "5Ԫ  : " << e << "��" << endl;
		break;
	}
	while (f > 0) {
		cout << "1Ԫ  : " << f << "��" << endl;
		break;
	}
	while (g > 0) {
		cout << "5��  : " << g << "��" << endl;
		break;
	}
	while (h > 0) {
		cout << "1��  : " << h << "��" << endl;
		break;
	}
	while (i > 0) {
		cout << "5��  : " << i << "��" << endl;
		break;
	}
	while (j > 0) {
		cout << "2��  : " << j << "��" << endl;
		break;
	}
	while (k > 0) {
		cout << "1��  : " << k << "��" << endl;
		break;
	}
	return 0;
}