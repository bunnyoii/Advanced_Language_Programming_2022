/*2251730 ��07 ������*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	int x;
	int m = 1;
	double n, e = 1, e0 = 0;//mΪ��ĸ�׳ˣ�iΪָ��
	cout << "������x��ֵ[-10~+65]" << endl;
	cin >> x;
	while (x > 65 || x < -10) {
		cout << "����Ƿ�������������" << endl;
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