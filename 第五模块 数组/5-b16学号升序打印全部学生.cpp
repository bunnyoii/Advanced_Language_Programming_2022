/* 2251730 信07 刘淑仪 */
#include<iostream>
using namespace std;

void bubble_sort(int grade[], int n, string number[], string name[])
{
	int i, j, t;
	string Tnum;
	string Tname;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - (i + 1); j++) {
			if (number[j] > number[j + 1]) {
				t = grade[j];
				Tnum = number[j];
				Tname = name[j];

				grade[j] = grade[j + 1];
				number[j] = number[j + 1];
				name[j] = name[j + 1];

				grade[j + 1] = t;
				number[j + 1] = Tnum;
				name[j + 1] = Tname;
			}
		}
	}
}
void input(string name[], string number[], int grade[])
{
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> number[i] >> name[i] >> grade[i];
	}
}
void output(string name[], string number[], int grade[])
{
	cout << endl;
	cout << "全部学生(学号升序):" << endl;
	for (int i = 0; i < 10; i++)
		cout << name[i] << " " << number[i] << " " << grade[i] << endl;
}
int main() {
	string name[10];
	string number[10];
	int grade[10];
	input(name, number, grade);
	bubble_sort(grade, 10, number, name);
	output(name, number, grade);
	return 0;
}