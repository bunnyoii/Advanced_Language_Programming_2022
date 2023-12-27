/*2251730 信07 刘淑仪*/
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	double pi = 3.14159;
	int a, b, c;
	float x, S;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;

	cout << setiosflags(ios::fixed) << setprecision(3);
	x = pi * c / 180;
	S = 0.5 * a * b * sin(x);
	cout << "三角形的面积为 : " << S << endl;
	return 0;
}