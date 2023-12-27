/* 2251730 信07 刘淑仪*/
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
	cout << "sinxdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	value = definite_integration(low, high, n, sin);
	cout << "sinxdx[" << low << "~" << high << "/n=" << n << "]的值为 ： " << value << endl;

	cout << "cosxdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	value = definite_integration(low, high, n, cos);
	cout << "cosxdx[" << low << "~" << high << "/n=" << n << "]的值为 ： " << value << endl;

	cout << "e^xdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	value = definite_integration(low, high, n, exp);
	cout << "e^xdx[" << low << "~" << high << "/n=" << n << "]的值为 ： " << value << endl;

	return 0;
}