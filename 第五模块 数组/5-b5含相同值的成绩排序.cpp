//2251730 信07 刘淑仪
#include<iostream>
using namespace std;
const int N = 1000;
int main()
{
	int num[N] = { 0 }, count[N] = { 0 };
	int i, j, t;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	//将num数组全部置负
	for (i = 0; i < N; i++)
		num[i] = -1;
	//输入数组
	for (i = 0; i < N; i++) {
		cin >> num[i];
		if (num[0] < 0) {
			cout << "无有效输入" << endl;
			return 0;
		}
		else {
			if (num[i] < 0)
				break;
		}
	}

	//打印输入的数组（十个一行）
	cout << "输入的数组为:" << endl;
	for (i = 0; i < N; i++) {
		if (num[i] >= 0) {
			cout << num[i] << ' ';
			if ((i + 1) % 10 == 0 && num[i + 1] >= 0 && i + 1 < N)
				cout << endl;
		}
	}
	cout << endl;

	cout << "分数与名次的对应关系为:" << endl;
	//冒泡排序，大的在上小的在下
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - (i + 1); j++)
			if (num[j] < num[j + 1]) {
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
	//合并相同排名
	for (i = 0; i < N - 1; i++) {
		count[i] = i + 1;
		for (j = 1; j < N; j++)
			if (num[j] == num[j - 1])
				count[j] = count[j - 1];
	}
	//输出结果
	for (i = 0; i < N; i++)
		if (num[i] >= 0)
			cout << num[i] << ' ' << count[i] << endl;

	return 0;
}