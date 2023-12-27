/* 2251730 ��07 ������*/
#include <iostream>
#include <cmath>

using namespace std;

double definite_integration(double low, double high, int n, double (*math)(double)) {
	double value = 0;
	double pieces = (high - low) / n;
	for (double i = low; i < high; i += pieces)
		value += math(i + pieces) * pieces;
	return value;
}


int main()
{
	int n;
	double low, high, value;
	cout << "sinxdx�����ޡ����޼����仮������" << endl;
	cin >> low >> high >> n;
	value = definite_integration(low, high, n, sin);
	cout << "sinxdx[" << low << "~" << high << "/n=" << n << "]��ֵΪ �� " << value << endl;

	cout << "cosxdx�����ޡ����޼����仮������" << endl;
	cin >> low >> high >> n;
	value = definite_integration(low, high, n, cos);
	cout << "cosxdx[" << low << "~" << high << "/n=" << n << "]��ֵΪ �� " << value << endl;

	cout << "e^xdx�����ޡ����޼����仮������" << endl;
	cin >> low >> high >> n;
	value = definite_integration(low, high, n, exp);
	cout << "e^xdx[" << low << "~" << high << "/n=" << n << "]��ֵΪ �� " << value << endl;

	return 0;
}