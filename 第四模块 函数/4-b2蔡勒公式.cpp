/*2251730 ��07 ������*/
#include<iostream>
using namespace std;
int zeller(int y, int m, int d) {
	int c, w{};
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

int main() {
	int w{}, c, y, m, d;
	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
		bool leap;
		leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�����������������" << endl;
		}
		else if (y > 2100 || y < 1900){
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "��ݲ���ȷ������������" << endl;
		}
		else if (m > 12 || m < 1){
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�·ݲ���ȷ������������" << endl;
		}
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30 || d < 1){
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�ղ���ȷ������������" << endl;
		}
		else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31 || d < 1){
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�ղ���ȷ������������" << endl;
		}
		else if (leap == 1 && m == 2 && d > 29 || d < 1){
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�ղ���ȷ������������" << endl;
		}
		else if (leap == 0 && m == 2 && d > 28 || d < 1){
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�ղ���ȷ������������" << endl;
		}
		else
			break;
	}
	w = zeller(y, m, d);
	cout << "����";
	switch (w) {
	case 0:
		cout << "��" << endl;
		break;
	case 1:
		cout << "һ" << endl;
		break;
	case 2:
		cout << "��" << endl;
		break;
	case 3:
		cout << "��" << endl;
		break;
	case 4:
		cout << "��" << endl;
		break;
	case 5:
		cout << "��" << endl;
		break;
	case 6:
		cout << "��" << endl;
		break;
	}
	return 0;
}