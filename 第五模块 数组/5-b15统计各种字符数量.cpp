/* 2251730 ��07 ������ */
#include<iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {

	char str[3][128] = { };
	int i;
	int uppercase = 0, lowercase = 0, number = 0, blank = 0, other = 0;

	//����
	cout << "�������һ��" << endl;
	i = 0;
	while ((str[0][i++] = getchar()) != '\n');
	str[0][i - 1] = '\0';
	cout << "������ڶ���" << endl;
	i = 0;
	while ((str[1][i++] = getchar()) != '\n');
	str[1][i - 1] = '\0';
	cout << "�����������" << endl;
	i = 0;
	while ((str[2][i++] = getchar()) != '\n');
	str[2][i - 1] = '\0';

	//�ж�
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
	cout << "��д : " << uppercase << endl;
	cout << "Сд : " << lowercase << endl;
	cout << "���� : " << number << endl;
	cout << "�ո� : " << blank << endl;
	cout << "���� : " << other << endl;
	return 0;
}