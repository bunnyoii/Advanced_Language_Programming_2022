/*2251730 ��07 ������*/
#include <iostream>
using namespace std;
int main() {
	double a;
	int b, c, d, e;
	cout << "������[0-100��)֮������� : " << endl;
	cin >> a;

	a = a + 0.001;

	cout << "ʮ��λ : " << (int)(a / 1000000000) % 10 << endl;
	cout << "��λ   : " << (int)(a / 100000000) % 10 << endl;
	cout << "ǧ��λ : " << (int)(a / 10000000) % 10 << endl;
	cout << "����λ : " << (int)(a / 1000000) % 10 << endl;
	cout << "ʮ��λ : " << (int)(a / 100000) % 10 << endl;
	cout << "��λ   : " << (int)(a / 10000) % 10 << endl;
	cout << "ǧλ   : " << (int)(a / 1000) % 10 << endl;
	cout << "��λ   : " << (int)(a / 100) % 10 << endl;
	cout << "ʮλ   : " << (int)(a / 10) % 10 << endl;

	a = a / 10 - (int)(a / 10);
	b = (int)(a * 1000);
	c = b / 100 % 10;
	d = b / 10 % 10;
	e = b % 10;
	cout << "Բ     : " << c << endl;
	cout << "��     : " << d << endl;
	cout << "��     : " << e << endl;
	return 0;
}
