/*2251730 信07 刘淑仪*/
#include<iostream>
using namespace std;

int main() {
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
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
	if (c > 0) {//处理十亿部分
		switch (c) {
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
		}
		cout << "拾";
		if (d == 0)
			cout << "亿";
	}
	if (d > 0) {//处理亿部分
		switch (d) {
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
		}
		cout << "亿";
	}


	if ((e == 0 && (f != 0 || g != 0 || h != 0)) || (f == 0 && (g != 0 || h != 0)) || (g == 0 && h != 0))
		cout << "零";
	if (e > 0) {//处理仟万部分
		switch (e) {
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
		}
		cout << "仟";
	}
	if (f > 0) {//处理佰万部分
		switch (f) {
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
		}
		cout << "佰";
	}
	if (g > 0) {//处理拾万部分
		switch (g) {
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
		}
		cout << "拾";
	}
	if (h > 0) {//处理万部分
		if (g == 0 && (c != 0 || d != 0 || e != 0 || f != 0) && h > 0)
			cout << "零";
		switch (h) {
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
		}
		cout << "万";
	}
	else if (h == 0 && (/*c != 0 || d != 0 ||*/ e != 0 || f != 0 || g != 0))
		cout << "万";

	if (((j > 0 && i == 0) || (k > 0 && (i == 0 || j == 0))) && (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0))
		cout << "零";
	if (i > 0) {//处理仟部分
		switch (i) {
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
		}
		cout << "仟";
	}
	if (j > 0) {//处理佰部分
		switch (j) {
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
		}
		cout << "佰";
	}
	else if (j == 0 && (i > 0 && k > 0))
		cout << "零";
	if (k > 0) {//处理拾部分
		switch (k) {
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
		}
		cout << "拾";
	}

	a = a / 10 - (int)(a / 10);//降位
	int x = (int)(a * 1000);//扩大
	int y = x / 100 % 10;//圆
	int z = x / 10 % 10;//角
	int p = x % 10;//分


	if (y > 0) {//处理圆部分
		if (((j == 0 || k == 0) && (i != 0 || h != 0 || g != 0 || c != 0 || d != 0)) || (i != 0 && j == 0 && k == 0) || (j != 0 && k == 0))
			cout << "零";
		switch (y) {
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
		}
		cout << "圆";
	}
	else if (y == 0 && ((z != 0 || p != 0) && (b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0)))
		cout << "圆";
	else if (y == 0 && ((z == 0 && p == 0) && (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0)))
		cout << "零圆";
	else if (y == 0 && ((z != 0 || p != 0) && (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0)))
		cout << "零圆";
	if (z > 0) {//处理角部分
		switch (z) {
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
		}
		cout << "角";
	}
	else if (z == 0 && p == 0)
		cout << "整";


	if (p > 0) {//处理分部分
		if (z == 0 && p > 0)
			cout << "零";
		switch (p) {
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
		}
		cout << "分";
	}
	return 0;
}