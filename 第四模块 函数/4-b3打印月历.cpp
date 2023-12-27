/* 2251730 信07 刘淑仪 */
#include <iostream>
#include<iomanip>
using namespace std;
int zeller(int y, int m) {
	int c, w{}, d = 1;
	if (m >= 3) {
		c = y / 100;
		y = y - c * 100;
		w = y + int(y / 4) + int(c / 4) - 2 * c + int((13 * (m + 1) / 5)) + d - 1;
	}
	else if (m == 1 || m == 2) {
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
		w = y + int(y / 4) + int(c / 4) - 2 * c + int((13 * (m + 13) / 5)) + d - 1;
	}
	for (int i = 1; w < 0; i++) {
		w = w + 7 * 1;
	}
	w = w % 7;
	return w;
}

void calendar(int y, int m) {
	bool leap;
	leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	cout << y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六  " << endl;
	cout << "======================================================" << endl;
	int d = 1;
	int w = zeller(y, m);
	cout << "  ";
	for (int i = 1; i <= w; i++) {
		cout << "        ";
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		for (d; d <= 30; d++) {
			cout << setw(2) << setiosflags(ios::right) << d << "      ";
			if ((d + w) % 7 == 0)
				cout << endl << "  ";
		}
	}
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		for (d; d <= 31; d++) {
			cout << setw(2) << setiosflags(ios::right) << d << "      ";
			if ((d + w) % 7 == 0)
				cout << endl << "  ";
		}
	}
	else if (leap == 1 && m == 2) {
		for (d; d <= 29; d++) {
			cout << setw(2) << setiosflags(ios::right) << d << "      ";
			if ((d + w) % 7 == 0)
				cout << endl << "  ";
		}
	}
	else if (leap == 0 && m == 2) {
		for (d; d <= 28; d++) {
			cout << setw(2) << setiosflags(ios::right) << d << "      ";
			if ((d + w) % 7 == 0)
				cout << endl << "  ";
		}
	}
}

int main() {
	int w{}, c{}, y, m;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;
		bool leap;
		leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (y > 2100 || y < 1900) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "年份不正确，请重新输入" << endl;
		}
		else if (m > 12 || m < 1) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "月份不正确，请重新输入" << endl;
		}
		else
			break;
	}
	cout << endl;
	calendar(y, m);
	cout << endl;
	cout << endl;
	return 0;
}