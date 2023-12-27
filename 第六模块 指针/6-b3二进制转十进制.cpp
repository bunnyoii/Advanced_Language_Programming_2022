/* 2251730 信07 刘淑仪 */
#include <iostream>
using namespace std;

int main()
{
	char str[33] = " ", * p = str;
	int oct = 0;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	for (p = str; (*p = getchar()) != '\n'; p++);
	*p = '\0';
	for (p = str; *p != '\0'; p++)
		oct = oct * 2 + (*p - 48);
	cout << oct;
	return 0;
}