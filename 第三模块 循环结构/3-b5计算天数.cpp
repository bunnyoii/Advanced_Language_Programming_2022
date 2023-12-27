//2251730 信07 刘淑仪
#include<iostream>
using namespace std;
int main()
{
	int y, m, d, b;
	int i = 0, a = 0;
	bool leap;
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d;
	leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	if (m > 12 || m < 1) {
		cout << "输入错误-月份不正确" << endl;
	}
	else if (d > 31 || d <= 0 || leap == 0 && m == 2 && d > 28 || m == 4 || m == 6 || m == 9 || m == 11 && d >= 31 || leap == 1 && m == 2 && d > 29) {
		cout << "输入错误-日与月关系非法" << endl;
	}
	else if (leap == 1) {
		if (m == 1)
			a = d;
		else if (m == 2)
			a = 31 + d;
		else if (m == 3)
			a = 31 + 29 + d;
		else if (m == 4)
			a = 31 + 29 + 31 + d;
		else if (m == 5)
			a = 31 + 29 + 31 + 30 + d;
		else if (m == 6)
			a = 31 + 29 + 31 + 30 + 31 + d;
		else if (m == 7)
			a = 31 + 29 + 31 + 30 + 31 + 30 + d;
		else if (m == 8)
			a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + d;
		else if (m == 9)
			a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + d;
		else if (m == 10)
			a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d;
		else if (m == 11)
			a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d;
		else if (m == 12)
			a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d;
		cout << "“" << y << "-" << m << "-" << d << "是" << y << "年的第" << a << "天”" << endl;
	}
	else if (leap == 0) {
		if (m == 1)
			a = d;
		else if (m == 2)
			a = 31 + d;
		else if (m == 3)
			a = 31 + 28 + d;
		else if (m == 4)
			a = 31 + 28 + 31 + d;
		else if (m == 5)
			a = 31 + 28 + 31 + 30 + d;
		else if (m == 6)
			a = 31 + 28 + 31 + 30 + 31 + d;
		else if (m == 7)
			a = 31 + 28 + 31 + 30 + 31 + 30 + d;
		else if (m == 8)
			a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + d;
		else if (m == 9)
			a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + d;
		else if (m == 10)
			a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d;
		else if (m == 11)
			a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d;
		else if (m == 12)
			a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d;
		cout << "“" << y << "-" << m << "-" << d << "是" << y << "年的第" << a << "天”" << endl;
	}
	return 0;
}