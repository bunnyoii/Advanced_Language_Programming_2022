/*��07 2251730 ������*/
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int y, m, w, d;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (y <= 2030 && y >= 2000 && m >= 1 && m <= 12)
			break;
		cout << "����Ƿ�������������" << endl;
	}
	bool leap;
	leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;

	if (y <= 2030 && y >= 2000 && m >= 1 && m <= 12) {
		while (1) {
			cout << "������" << y << "��" << m << "��1�յ�����(0-6��ʾ������-������) : ";
			cin >> w;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(2048, '\n');
			}
			else if (w >= 0 && w <= 6)
				break;
			cout << "����Ƿ�������������" << endl;
		}
		cout << endl;
		cout << y << "��" << m << "�µ�����Ϊ: huu8u" << endl;
		cout << "������  " << "����һ  " << "���ڶ�  " << "������  " << "������  " << "������  " << "������" << endl;
		if (m == 4 || m == 6 || m == 9 || m == 11) {
			switch (w) {
			case 0:
				for (d = 1; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if (d % 7 == 0)
						cout << endl;
				}
				break;
			case 1:
				cout << "           1       2       3       4       5       6" << endl;
				for (d = 7; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 1) % 7 == 0)
						cout << endl;
				}
				break;
			case 2:
				cout << "                   1       2       3       4       5" << endl;
				for (d = 6; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 2) % 7 == 0)
						cout << endl;
				}
				break;
			case 3:
				cout << "                           1       2       3       4" << endl;
				for (d = 5; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 3) % 7 == 0)
						cout << endl;
				}
				break;
			case 4:
				cout << "                                   1       2       3" << endl;
				for (d = 4; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 4) % 7 == 0)
						cout << endl;
				}
				break;
			case 5:
				cout << "                                           1       2" << endl;
				for (d = 3; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 5) % 7 == 0)
						cout << endl;
				}
				break;
			case 6:
				cout << "                                                   1" << endl;
				for (d = 2; d <= 30; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 6) % 7 == 0)
						cout << endl;
				}
				break;
			}
		}
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			switch (w) {
			case 0:
				for (d = 1; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if (d % 7 == 0)
						cout << endl;
				}
				break;
			case 1:
				cout << "           1       2       3       4       5       6" << endl;
				for (d = 7; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 1) % 7 == 0)
						cout << endl;
				}
				break;
			case 2:
				cout << "                   1       2       3       4       5" << endl;
				for (d = 6; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 2) % 7 == 0)
						cout << endl;
				}
				break;
			case 3:
				cout << "                           1       2       3       4" << endl;
				for (d = 5; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 3) % 7 == 0)
						cout << endl;
				}
				break;
			case 4:
				cout << "                                   1       2       3" << endl;
				for (d = 4; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 4) % 7 == 0)
						cout << endl;
				}
				break;
			case 5:
				cout << "                                           1       2" << endl;
				for (d = 3; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 5) % 7 == 0)
						cout << endl;
				}
				break;
			case 6:
				cout << "                                                   1" << endl;
				for (d = 2; d <= 31; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 6) % 7 == 0)
						cout << endl;
				}
				break;
			}
		}
		if (leap == 1 && m == 2) {
			switch (w) {
			case 0:
				for (d = 1; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if (d % 7 == 0)
						cout << endl;
				}
				break;
			case 1:
				cout << "           1       2       3       4       5       6" << endl;
				for (d = 7; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 1) % 7 == 0)
						cout << endl;
				}
				break;
			case 2:
				cout << "                   1       2       3       4       5" << endl;
				for (d = 6; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 2) % 7 == 0)
						cout << endl;
				}
				break;
			case 3:
				cout << "                           1       2       3       4" << endl;
				for (d = 5; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 3) % 7 == 0)
						cout << endl;
				}
				break;
			case 4:
				cout << "                                   1       2       3" << endl;
				for (d = 4; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 4) % 7 == 0)
						cout << endl;
				}
				break;
			case 5:
				cout << "                                           1       2" << endl;
				for (d = 3; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 5) % 7 == 0)
						cout << endl;
				}
				break;
			case 6:
				cout << "                                                   1" << endl;
				for (d = 2; d <= 29; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 6) % 7 == 0)
						cout << endl;
				}
				break;
			}
		}
		if (leap == 0 && m == 2) {
			switch (w) {
			case 0:
				for (d = 1; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if (d % 7 == 0)
						cout << endl;
				}
				break;
			case 1:
				cout << "           1       2       3       4       5       6" << endl;
				for (d = 7; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 1) % 7 == 0)
						cout << endl;
				}
				break;
			case 2:
				cout << "                   1       2       3       4       5" << endl;
				for (d = 6; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 2) % 7 == 0)
						cout << endl;
				}
				break;
			case 3:
				cout << "                           1       2       3       4" << endl;
				for (d = 5; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 3) % 7 == 0)
						cout << endl;
				}
				break;
			case 4:
				cout << "                                   1       2       3" << endl;
				for (d = 4; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 4) % 7 == 0)
						cout << endl;
				}
				break;
			case 5:
				cout << "                                           1       2" << endl;
				for (d = 3; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 5) % 7 == 0)
						cout << endl;
				}
				break;
			case 6:
				cout << "                                                   1" << endl;
				for (d = 2; d <= 28; d++) {
					cout << "  ";
					cout << setw(2) << setiosflags(ios::right) << d << "    ";
					if ((d + 6) % 7 == 0)
						cout << endl;
				}
				break;
			}
		}
	}
	cout << endl;
	return 0;
}