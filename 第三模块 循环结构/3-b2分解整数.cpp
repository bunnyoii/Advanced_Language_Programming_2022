/*2251730 ��07 ������*/
#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    cout << "������һ��[1..30000]�������:" << endl;
    cin >> a;
    b = a / 10000 % 10;
    c = a / 1000 % 10;
    d = a / 100 % 10;
    e = a / 10 % 10;
    f = a % 10;
    cout << "��λ : " << b << endl;
    cout << "ǧλ : " << c << endl;
    cout << "��λ : " << d << endl;
    cout << "ʮλ : " << e << endl;
    cout << "��λ : " << f << endl;

    return 0;
}