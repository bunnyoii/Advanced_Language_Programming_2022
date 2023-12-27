/* 2251730 信07 刘淑仪*/
#include <iostream>

using namespace std;

void input(int& input)
{
	while (1) {
		cout << "请输入月份（1-12）" << endl;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "Invalid" << endl;
			continue;
		}
		else if (input > 12 || input < 1) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "Invalid" << endl;
			continue;
		}
		else
			break;
	}
}
void output(int input, const char* month[])
{
	const char** p = month;
	cout << *(p + input - 1) << endl;
}

int main()
{
	int InPut;
	const char* month[12] = { "January","Feburuary","March","April","May","June",
				"July","August","September","October","November","December" };
	input(InPut);
	output(InPut, month);
	return 0;
}