/* 2251730 信07 刘淑仪 */
#include<iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {

	char str[3][128] = { };
	int i;
	int uppercase = 0, lowercase = 0, number = 0, blank = 0, other = 0;

	//输入
	cout << "请输入第一行" << endl;
	i = 0;
	while ((str[0][i++] = getchar()) != '\n');
	str[0][i - 1] = '\0';
	cout << "请输入第二行" << endl;
	i = 0;
	while ((str[1][i++] = getchar()) != '\n');
	str[1][i - 1] = '\0';
	cout << "请输入第三行" << endl;
	i = 0;
	while ((str[2][i++] = getchar()) != '\n');
	str[2][i - 1] = '\0';

	//判断
	for (int i = 0; i < 3; i++)
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				uppercase++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				lowercase++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				number++;
			else if (str[i][j] == ' ')
				blank++;
			else
				other++;
		}
	cout << "大写 : " << uppercase << endl;
	cout << "小写 : " << lowercase << endl;
	cout << "数字 : " << number << endl;
	cout << "空格 : " << blank << endl;
	cout << "其他 : " << other << endl;
	return 0;
}