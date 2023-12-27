/* 2251730 信07 刘淑仪 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include <windows.h>
#include<cstring>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
void password_generate(char password[], int uppercase_number, int lowercase_number, int number, int other_number, int length)
{
	//存放密码
	int sign0 = 0, sign1 = 0, sign2 = 0, sign3 = 0;
	for (int i = 0; i < length; i++) {
		int a = rand() % 4;
		if (i > uppercase_number + lowercase_number + number + other_number) {
			switch (a) {
			case 0:
				password[i] = 65 + rand() % 26;
				break;
			case 1:
				password[i] = 97 + rand() % 26;
				break;
			case 2:
				password[i] = 48 + rand() % 10;
				break;
			case 3:
				password[i] = other[rand() % 15];
				break;
			}
		}
		else {
			if (a == 0) {
				if (sign0 > uppercase_number)
					i--;
				else {
					password[i] = 65 + rand() % 26;
					sign0++;
				}
			}
			else if (a == 1) {
				if (sign1 > lowercase_number)
					i--;
				else {
					password[i] = 97 + rand() % 26;
					sign1++;
				}
			}
			else if (a == 2) {
				if (sign2 > number)
					i--;
				else {
					password[i] = 48 + rand() % 10;
					sign2++;
				}
			}
			else if (a == 3) {
				if (sign3 > other_number)
					i--;
				else {
					password[i] = other[rand() % 15];
					sign3++;
				}
			}
		}
	}
}
int main() {
	int length, uppercase_number, lowercase_number, number, other_number;
	char password[128] = { -1 };
	cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其他符号个数(≥2)" << endl;
	cin >> length >> uppercase_number >> lowercase_number >> number >> other_number;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	else if (length > 16 || length < 12) {
		cout << "密码长度[" << length << "]不正确" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	else if (uppercase_number < 2 || uppercase_number > length) {
		cout << "大写字母数字个数[" << uppercase_number << "]不正确" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	else if (lowercase_number < 2 || lowercase_number > length) {
		cout << "小写字母数字个数[" << lowercase_number << "]不正确" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	else if (number < 2 || number > length) {
		cout << "数字个数[" << number << "]不正确" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	else if (other_number < 2 || other_number > length) {
		cout << "其他字符个数[" << other_number << "]不正确" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	else if (uppercase_number + lowercase_number + number + other_number > length) {
		cout << "所有字符类型之和[" << uppercase_number << "+" << lowercase_number << "+" << number << "+" << other_number << "]大于密码总长度[" << length << "]" << endl;
		cin.clear();
		cin.ignore(65536, '\n');
		return 0;
	}
	cout << length << " " << uppercase_number << " " << lowercase_number << " " << number << " " << other_number << " " << endl;

	srand((unsigned int)(time(0)));
	for (int j = 0; j < 10; j++) {
		password_generate(password, uppercase_number, lowercase_number, number, other_number, length);
		for (int i = 0; i < length; i++)
			cout << password[i];
		cout << endl;
	}
	return 0;
}