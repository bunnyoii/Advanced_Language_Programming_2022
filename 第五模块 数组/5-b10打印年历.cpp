/*2251730 信07 刘淑仪*/
#include<iostream>
#include<iomanip>
using namespace std;

int zeller(int y, int m) {
	int c, w = 0, d = 1;
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

void calendar_title(int i)
{
	for (i = 0; i < 3; i++) {
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		if (i < 2)
			cout << "     ";
	}
	cout << endl;
}

void calendar(int y, int m)
{
	bool leap;
	leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	int d[12][42] = { 0 };
	int day[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 0; i < 12; i++) {
		int first = 0;
		for (int j = zeller(y, i + 1); j < day[i] + zeller(y, i + 1); j++) {
			first++;
			d[i][j] = first;
		}
	}


	//打印
	for (int i = 0; i < 3; i++) {
		cout << "            " << i + 1 << "月";
		if (i < 2)
			cout << "                 ";
	}
	cout << endl;
	calendar_title(0);
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 7; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 2)
			cout << "    ";
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 7; i < 14; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 2)
			cout << "    ";
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 14; i < 21; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 2)
			cout << "    ";
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 21; i < 28; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 2)
			cout << "    ";
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 28; i < 35; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 2)
			cout << "    ";
	}
	cout << endl;
	if (!(d[0][35] == 0 && d[1][35] == 0 && d[2][35] == 0)) {
		for (int j = 0; j < 3; j++) {
			for (int i = 35; i < 42; i++) {
				if (d[j][i] != 0)
					cout << setw(4) << setiosflags(ios::left) << d[j][i];
				else
					cout << "    ";
			}
			if (j < 2)
				cout << "    ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 3; i < 6; i++) {
		cout << "            " << i + 1 << "月";
		if (i < 5)
			cout << "                 ";
	}
	cout << endl;
	calendar_title(0);

	for (int j = 3; j < 6; j++) {
		for (int i = 0; i < 7; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 5)
			cout << "    ";
	}
	cout << endl;
	for (int j = 3; j < 6; j++) {
		for (int i = 7; i < 14; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 5)
			cout << "    ";
	}
	cout << endl;
	for (int j = 3; j < 6; j++) {
		for (int i = 14; i < 21; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 5)
			cout << "    ";
	}
	cout << endl;
	for (int j = 3; j < 6; j++) {
		for (int i = 21; i < 28; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 5)
			cout << "    ";
	}
	cout << endl;
	for (int j = 3; j < 6; j++) {
		for (int i = 28; i < 35; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 5)
			cout << "    ";
	}
	cout << endl;
	if (!(d[3][35] == 0 && d[4][35] == 0 && d[5][35] == 0)) {
		for (int j = 3; j < 6; j++) {
			for (int i = 35; i < 42; i++) {
				if (d[j][i] != 0)
					cout << setw(4) << setiosflags(ios::left) << d[j][i];
				else
					cout << "    ";
			}
			if (j < 5)
				cout << "    ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 6; i < 9; i++) {
		cout << "            " << i + 1 << "月";
		if (i < 8)
			cout << "                 ";
	}
	cout << endl;
	calendar_title(0);

	for (int j = 6; j < 9; j++) {
		for (int i = 0; i < 7; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 8)
			cout << "    ";
	}
	cout << endl;
	for (int j = 6; j < 9; j++) {
		for (int i = 7; i < 14; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 8)
			cout << "    ";
	}
	cout << endl;
	for (int j = 6; j < 9; j++) {
		for (int i = 14; i < 21; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 8)
			cout << "    ";
	}
	cout << endl;
	for (int j = 6; j < 9; j++) {
		for (int i = 21; i < 28; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 8)
			cout << "    ";
	}
	cout << endl;
	for (int j = 6; j < 9; j++) {
		for (int i = 28; i < 35; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 8)
			cout << "    ";
	}
	cout << endl;
	if (!(d[6][35] == 0 && d[7][35] == 0 && d[8][35] == 0)) {
		for (int j = 6; j < 9; j++) {
			for (int i = 35; i < 42; i++) {
				if (d[j][i] != 0)
					cout << setw(4) << setiosflags(ios::left) << d[j][i];
				else
					cout << "    ";
			}
			if (j < 8)
				cout << "    ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 9; i < 12; i++) {
		cout << "           " << i + 1 << "月";
		if (i < 11)
			cout << "                 ";
	}
	cout << endl;
	calendar_title(0);

	for (int j = 9; j < 12; j++) {
		for (int i = 0; i < 7; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 11)
			cout << "    ";
	}
	cout << endl;
	for (int j = 9; j < 12; j++) {
		for (int i = 7; i < 14; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 11)
			cout << "    ";
	}
	cout << endl;
	for (int j = 9; j < 12; j++) {
		for (int i = 14; i < 21; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 11)
			cout << "    ";
	}
	cout << endl;
	for (int j = 9; j < 12; j++) {
		for (int i = 21; i < 28; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 11)
			cout << "    ";
	}
	cout << endl;
	for (int j = 9; j < 12; j++) {
		for (int i = 28; i < 35; i++) {
			if (d[j][i] != 0)
				cout << setw(4) << setiosflags(ios::left) << d[j][i];
			else
				cout << "    ";
		}
		if (j < 11)
			cout << "    ";
	}
	cout << endl;
	if (!(d[9][35] == 0 && d[10][35] == 0 && d[11][35] == 0)) {
		for (int j = 9; j < 12; j++) {
			for (int i = 35; i < 42; i++) {
				if (d[j][i] != 0)
					cout << setw(4) << setiosflags(ios::left) << d[j][i];
				else
					cout << "    ";
			}
			if (j < 11)
				cout << "    ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int w = 0, y;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> y;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (y > 2100 || y < 1900) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	cout << y << "年的日历:" << endl;
	cout << endl;

	calendar(y, 1);
	cout << endl;

	return 0;
}