/*2251730 信07 刘淑仪*/
#include<iostream>
using namespace std;
int main()
{
	int a[9][9] = { 0 };
	int k = 0;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) {
				cin >> a[i][j];
				if (cin.good()) {
					if (a[i][j] >= 1 && a[i][j] <= 9) {
						break;
					}
					else {
						cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
						continue;
					}
				}
				else {
					cin.clear();
					cin.ignore(65536, '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
			}
		}
	}
	int row = 0, column = 0, square = 0;

	int sign2[9] = { 0 };
	for (int i = 0; i < 9; i++) {
		int sign1[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			sign1[a[i][j] - 1] = 1;
		}
		int b = 0;
		for (int j = 0; j < 9; j++)
			b += sign1[j];
		if (b == 9)
			sign2[i] = 1;
	}
	int c = 0;
	for (int j = 0; j < 9; j++)
		c += sign2[j];
	if (c == 9)
		row = 1;

	int sign4[9] = { 0 };
	for (int i = 0; i < 9; i++) {
		int sign3[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			sign3[a[j][i] - 1] = 1;
		}
		int d = 0;
		for (int j = 0; j < 9; j++)
			d += sign3[j];
		if (d == 9)
			sign4[i] = 1;
	}
	int e = 0;
	for (int j = 0; j < 9; j++)
		e += sign4[j];
	if (e == 9)
		column = 1;

	int sign6[9] = { 0 };
	int counter = 0;
	for (int m = 0; m < 3; m++)
	{
		for (int k = 0; k < 3; k++)
		{
			int sign5[9] = { 0 };
			for (int i = 0 + k * 3; i < 3 + k * 3; i++)
				for (int j = 0 + m * 3; j < 3 + m * 3; j++) {
					sign5[a[i][j] - 1] = 1;
				}
			int g = 0;
			for (int j = 0; j < 9; j++)
				g += sign5[j];
			if (g == 9)
				sign6[counter++] = 1;
		}
	}
	int f = 0;
	for (int j = 0; j < 9; j++)
		f += sign6[j];
	if (f == 9)
		square = 1;
	if (row == 1 && column == 1 && square == 1)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}