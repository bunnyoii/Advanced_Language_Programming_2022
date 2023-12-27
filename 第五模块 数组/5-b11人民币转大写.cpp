/* 2251730 信07 刘淑仪*/
#include <iostream>
#include <cstring>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */


void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)
			result = result + chnstr[0] + chnstr[1];
		break;
	case 1:
		result = result + chnstr[2] + chnstr[3];
		break;
	case 2:
		result = result + chnstr[4] + chnstr[5];
		break;
	case 3:
		result = result + chnstr[6] + chnstr[7];
		break;
	case 4:
		result = result + chnstr[8] + chnstr[9];
		break;
	case 5:
		result = result + chnstr[10] + chnstr[11];
		break;
	case 6:
		result = result + chnstr[12] + chnstr[13];
		break;
	case 7:
		result = result + chnstr[14] + chnstr[15];
		break;
	case 8:
		result = result + chnstr[16] + chnstr[17];
		break;
	case 9:
		result = result + chnstr[18] + chnstr[19];
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
		result = result + "拾";
	daxie(d, 0);
	if (c > 0 || d > 0)
		result = result + "亿";

	if (c > 0 || d > 0)
		daxie(e, f);
	else
		daxie(e, 0);
	if (e > 0)
		result = result + "仟";
	if (c > 0 || d > 0 || e > 0)
		daxie(f, g);
	else
		daxie(f, 0);
	if (f > 0)
		result = result + "佰";
	if (c > 0 || d > 0 || e > 0 || f > 0)
		daxie(g, h);
	else
		daxie(g, 0);
	if (g > 0)
		result = result + "拾";
	daxie(h, 0);
	if (e > 0 || f > 0 || g > 0 || h > 0)
		result = result + "万";

	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0)
		daxie(i, j);
	else
		daxie(i, 0);
	if (i > 0)
		result = result + "仟";
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0)
		daxie(j, k);
	else
		daxie(j, 0);
	if (j > 0)
		result = result + "佰";
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0)
		daxie(k, y);
	else
		daxie(k, 0);
	if (k > 0)
		result = result + "拾";

	if (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && z == 0 && p == 0) {
		daxie(y, 1);
		result = result + "圆";
	}
	else if (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || y != 0)
	{
		daxie(y, 0);
		result = result + "圆";
	}
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0)
		daxie(z, p);
	else
		daxie(z, 0);
	if (z > 0)
		result = result + "角";
	if (p == 0)
		result = result + "整";
	if (p > 0) {
		if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0 || z > 0)
			daxie(p, 1);
		else
			daxie(p, 0);
		result = result + "分";
	}
	cout << result << endl;

	return 0;
}
