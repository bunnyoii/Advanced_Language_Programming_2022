/*2251730 信07 刘淑仪*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a = 3, b = 4;
	double d1, d2, c, s1, s2, v1, v2, pi = 3.14159;
	cout << "请输入半径和高度" << endl;
	cin >> d1 >> d2;
	cout << setiosflags(ios::fixed) << setprecision(2);
	c = 2 * pi * d1;
	s1 = pi * d1 * d1;
	s2 = 4 * pi * d1 * d1;
	v1 = b / a * pi * d1 * d1;
	v2 = pi * d1 * d1 * d2;
	cout << "圆周长     : " << c << endl;
	cout << "圆面积     : " << s1 << endl;
	cout << "圆球表面积 : " << s2 << endl;
	cout << "圆球体积   : " << v1 << endl;
	cout << "圆柱体积   : " << v2 << endl;

	return 0;
}