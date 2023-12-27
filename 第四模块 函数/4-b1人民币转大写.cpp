/* 2251730 信07 刘淑仪 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}
int main()
{
	double a;
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> a;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (a >= 0 && a < 10000000000)
			break;
	}
	a = a + 0.001;
	cout << "大写结果是:" << endl;
	int b = (int)a;
	int c = (int)(a / 1000000000) % 10;//十亿
	int d = (int)(a / 100000000) % 10;//亿
	int e = (int)(a / 10000000) % 10;//千万
	int f = (int)(a / 1000000) % 10;//百万
	int g = (int)(a / 100000) % 10;//十万
	int h = (int)(a / 10000) % 10;//万
	int i = (int)(a / 1000) % 10;//仟
	int j = (int)(a / 100) % 10;//佰
	int k = (int)(a / 10) % 10;//拾
	a = a / 10 - (int)(a / 10);//降位
	int x = (int)(a * 1000);//扩大
	int y = x / 100 % 10;//圆
	int z = x / 10 % 10;//角
	int p = x % 10;//分
	daxie(c, 0);
	if (c > 0)
		cout << "拾";
	daxie(d, 0);
	if (c > 0 || d > 0)
		cout << "亿";

	if (c > 0 || d > 0)
		daxie(e, f);
	else
		daxie(e, 0);
	if (e > 0)
		cout << "仟";
	if (c > 0 || d > 0 || e > 0)
		daxie(f, g);
	else
		daxie(f, 0);
	if (f > 0)
		cout << "佰";
	if (c > 0 || d > 0 || e > 0 || f > 0)
		daxie(g, h);
	else
		daxie(g, 0);
	if (g > 0)
		cout << "拾";
	daxie(h, 0);
	if (e > 0 || f > 0 || g > 0 || h > 0)
		cout << "万";

	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0)
		daxie(i, j);
	else
		daxie(i, 0);
	if (i > 0)
		cout << "仟";
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0)
		daxie(j, k);
	else
		daxie(j, 0);
	if (j > 0)
		cout << "佰";
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0)
		daxie(k, y);
	else
		daxie(k, 0);
	if (k > 0)
		cout << "拾";

	if (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && z == 0 && p == 0) {
		daxie(y, 1);
		cout << "圆";
	}
	else if (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || y != 0)
	{
		daxie(y, 0);
		cout << "圆";
	}
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0)
		daxie(z, p);
	else
		daxie(z, 0);
	if (z > 0)
		cout << "角";
	if (p == 0)
		cout << "整";
	if (p > 0) {
		if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0 || z > 0)
			daxie(p, 1);
		else
			daxie(p, 0);
		cout << "分";
	}
	cout << endl;

	return 0;
}