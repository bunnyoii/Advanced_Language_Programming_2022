/*2251730 ��07 ������*/
#include<iostream>
#include<cmath>
using namespace std;

void f3(double a, double b, double d)//���ʵ��
{
	double x;
	x = (-b + sqrt(d)) / (a * 2);
	if (fabs(x) >= 1e-6)
		;
	else
		x = 0;
	if (x == -0)
		x = 0;
	cout << "���������ʵ����" << endl << "x1=x2=" << x << endl;
	return;
}