/*2251730 信07 刘淑仪*/
#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    cout << "请输入一个[1..30000]间的整数:" << endl;
    cin >> a;
    b = a / 10000 % 10;
    c = a / 1000 % 10;
    d = a / 100 % 10;
    e = a / 10 % 10;
    f = a % 10;
    cout << "万位 : " << b << endl;
    cout << "千位 : " << c << endl;
    cout << "百位 : " << d << endl;
    cout << "十位 : " << e << endl;
    cout << "个位 : " << f << endl;

    return 0;
}