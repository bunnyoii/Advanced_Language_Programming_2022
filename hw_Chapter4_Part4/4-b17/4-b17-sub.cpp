/*2251730 ��07 ������*/
#include<iostream>
#include<cmath>
using namespace std;
extern double a, b, c, d;
void f1()
{//����ʵ��
	double x1, x2;

	x1 = (-b) / (a * 2) + sqrt(d) / (a * 2);
	x2 = (-b) / (a * 2) - sqrt(d) / (a * 2);
	if (x1 > x2) {
		if (fabs(x2) >= 1e-6)
			;
		else
			x2 = 0;
	}
	else {
		if (fabs(x1) >= 1e-6 || x1 == 0) {
			x2 = (-b) / (a * 2) + sqrt(d) / (a * 2);
			x1 = (-b) / (a * 2) - sqrt(d) / (a * 2);
		}
		else {
			x1 = 0;
			x2 = (-b) / (a * 2) + sqrt(d) / (a * 2);
		}
	}
	if (x1 == -0)
		x1 = 0;
	if (x2 == -0)
		x2 = 0;
	cout << "����������ʵ����" << endl << "x1=" << x1 << endl << "x2=" << x2 << endl;
	return;

}

void f2()
{//���
	double xd, xf;
	xd = (-b) / (a * 2);
	xf = sqrt(-d) / (a * 2);
	if (fabs(xd) < 1e-6)
		xd = 0;
	if (xd == 0) {
		if (xf < 0)
			xf = -xf;
		if (fabs(xf - 1) < 1e-6 || fabs(xf) == 1)
			cout << "�����������" << endl << "x1=i" << endl << "x2=-i" << endl;
		else
			cout << "�����������" << endl << "x1=" << fabs(xf) << "i" << endl << "x2=" << "-" << fabs(xf) << "i" << endl;
	}
	else {
		if (xf < 0)
			xf = -xf;
		if (fabs(xf - 1) < 1e-6 || fabs(xf) == 1)
			cout << "�����������" << endl << "x1=" << xd << "+i" << endl << "x2=" << xd << "-i" << endl;
		else
			cout << "�����������" << endl << "x1=" << xd << "+" << fabs(xf) << "i" << endl << "x2=" << xd << "-" << fabs(xf) << "i" << endl;
	}
	return;
}

void f3()//���ʵ��
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

void f4()
{//a=0
	cout << "����һԪ���η���" << endl;
	return;
}