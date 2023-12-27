/* 2251730 信07 刘淑仪*/
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int max(int a, int b, int c)
{
	int d = max(a, b);
	return d > c ? d : c;
}
int max(int a, int b, int c, int d)
{
	int e = max(a, b, c);
	return e > d ? e : d;
}
int main()
{
	int num;
	int num_compared[2048];
	bool loop;
	while (1) {
		loop = 1;
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		/* 判断输入个数是否正确*/
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (num > 4 || num < 2) {
			cout << "个数输入错误" << endl;
			return 0;
		}
		/* 判断输入的数是否正确*/
		for (int i = 0; i < num; i++) {
			cin >> num_compared[i];
			if (num_compared[i] <= 0) {
				loop = 0;
				break;
			}
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		/* 判断输入是否正确，是否退出循环 */
		if (!loop) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	switch (num) {
	case 2:
		cout << "max=" << max(num_compared[0], num_compared[1]) << endl;
		break;
	case 3:
		cout << "max=" << max(num_compared[0], num_compared[1], num_compared[2]) << endl;
		break;
	case 4:
		cout << "max=" << max(num_compared[0], num_compared[1], num_compared[2], num_compared[3]) << endl;
		break;
	}
	return 0;
}