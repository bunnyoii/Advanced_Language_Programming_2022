/*2251730 ��07 ������*/
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	double pi = 3.14159;
	int a, b, c;
	float x, S;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;

	cout << setiosflags(ios::fixed) << setprecision(3);
	x = pi * c / 180;
	S = 0.5 * a * b * sin(x);
	cout << "�����ε����Ϊ : " << S << endl;
	return 0;
}