/*2251730 ��07 ������*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a = 3, b = 4;
	double d1, d2, c, s1, s2, v1, v2, pi = 3.14159;
	cout << "������뾶�͸߶�" << endl;
	cin >> d1 >> d2;
	cout << setiosflags(ios::fixed) << setprecision(2);
	c = 2 * pi * d1;
	s1 = pi * d1 * d1;
	s2 = 4 * pi * d1 * d1;
	v1 = b / a * pi * d1 * d1;
	v2 = pi * d1 * d1 * d2;
	cout << "Բ�ܳ�     : " << c << endl;
	cout << "Բ���     : " << s1 << endl;
	cout << "Բ������ : " << s2 << endl;
	cout << "Բ�����   : " << v1 << endl;
	cout << "Բ�����   : " << v2 << endl;

	return 0;
}