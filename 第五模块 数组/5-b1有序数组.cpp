/* 信07 2251730 刘淑仪*/
#include <iostream>
#include <cmath>
using namespace std;

const int N = 21;

int main()
{
	int num1[N] = { 0 }, num2, i;
	int count = 0;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < N - 1; i++) {
		cin >> num1[i];
		if (num1[0] <= 0) {
			cout << "无有效输入" << endl;
			return 0;
		}
		else {
			if (num1[i] <= 0)
				break;
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

	cout << "原数组为：" << endl;
	for (i = 0; i < N - 1; i++) {
		if (num1[i] > 0)
			cout << num1[i] << " ";
		else
			;
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;
	cin >> num2;
	cout << "插入后的数组为：" << endl;
	if (num2 > 0)
		num1[20] = num2;
	else
		cout << num2 << ' ';
	for (i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (num1[j] > num1[j + 1]) {
				int t = num1[j];
				num1[j] = num1[j + 1];
				num1[j + 1] = t;
			}
	for (i = 0; i < N; i++) {
		if (num1[i] > 0)
			cout << num1[i] << ' ';
	}
	cout << endl;
	return 0;
}