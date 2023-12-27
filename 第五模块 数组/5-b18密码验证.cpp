/* 2251730 –≈07 ¡ı Á“« */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

int main() {
	cin.ignore(65536, '\n');
	int length, uppercase_number, lowercase_number, number, other_number;
	int uppercase = 0, lowercase = 0, number_ = 0, other = 0;
	char password[10][128] = { -1 };
	int length_[10];
	char ch;
	cin >> length >> uppercase_number >> lowercase_number >> other_number >> number;
	getchar();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; (ch = getchar()) != '\n'; j++) {
			password[i][j] = ch;
		}
	}
	for (int i = 0; i < 10; i++) {
		length_[i] = strlen(password[i]);
		if (length_[i] != length || length_[i] > 16 || length_[i] < 12) {
			cout << "¥ÌŒÛ" << endl;
			return 0;
		}
	}
	if (length > 16 || length < 12) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	if (uppercase_number < 2 || uppercase_number > length) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	if (lowercase_number < 2 || lowercase_number > length) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	if (number < 2 || number > length) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	if (other_number < 2 || other_number > length) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	if (uppercase_number + lowercase_number + number + other_number > length) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < length; j++) {
			if (password[i][j] >= 'A' && password[i][j] <= 'Z')
				uppercase++;
			else if (password[i][j] >= 'a' && password[i][j] <= 'z')
				lowercase++;
			else if (password[i][j] >= '0' && password[i][j] <= '9')
				number_++;
			else if (password[i][j] == '!' || password[i][j] == '@' || password[i][j] == '#' || password[i][j] == '$'
				|| password[i][j] == '%' || password[i][j] == '^' || password[i][j] == '&' || password[i][j] == '*'
				|| password[i][j] == '-' || password[i][j] == '_' || password[i][j] == '=' || password[i][j] == '+'
				|| password[i][j] == ',' || password[i][j] == '.' || password[i][j] == '?')
				other++;
			else {
				cout << "¥ÌŒÛ" << endl;
				return 0;
			}
		}
	if (uppercase < uppercase_number || lowercase < lowercase_number || number_ < number || other < other_number) {
		cout << "¥ÌŒÛ" << endl;
		return 0;
	}
	cout << "’˝»∑" << endl;
	return 0;
}