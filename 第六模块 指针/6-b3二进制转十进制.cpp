/* 2251730 ��07 ������ */
#include <iostream>
using namespace std;

int main()
{
	char str[33] = " ", * p = str;
	int oct = 0;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	for (p = str; (*p = getchar()) != '\n'; p++);
	*p = '\0';
	for (p = str; *p != '\0'; p++)
		oct = oct * 2 + (*p - 48);
	cout << oct;
	return 0;
}