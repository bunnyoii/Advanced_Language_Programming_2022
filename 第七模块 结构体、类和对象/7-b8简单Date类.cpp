/* 2251730 信07 刘淑仪 */
#include <iostream>
#include <conio.h>
using namespace std;

/* --- 如果有需要的宏定义、只读全局变量等，写于此处 --- */

/* --- 如果有其它全局函数需要声明，写于此处 --- */
bool day_ture(int year, int month, int day);
/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */

public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
	Date(int y, int m, int d);//三参构造
	Date();//无参构造
	Date(int d);//一参构造
	void show();
	void set(int y, int m = 1, int d = 1);
	void get(int& y, int& m, int& d);
};

/* 构造函数 */
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d)
{
	if (y > 2099 || y < 1900)
		year = 2000;
	else
		year = y;

	if (m > 12 || m < 1)
		month = 1;
	else
		month = m;

	if (day_ture(y, m, d))
		day = d;
	else
		day = 1;
}

Date::Date(int d)
{
	int _day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int transmigration, rest_year, rest_day;
	day = 1;
	month = 1;
	/* 日期非法 */
	if (d < 0 || d > 73047) {
		if (d < 0) {
			year = 1900;
			month = 1;
			day = 1;
		}
		else {
			year = 2099;
			month = 12;
			day = 31;
		}
	}
	/* 日期合法 */
	else {
		/* 排除前四年（1900不是闰年）*/
		if (d > 1460) {
			d -= 1460;//28540
			year = 1904;
			transmigration = d / 1461;
		}
		else {
			year = 1900;
			transmigration = 0;
		}
		rest_year = (d - transmigration * 1461) / 365;
		year += transmigration * 4 + rest_year;
		rest_day = (d - transmigration * 1461) % 365;
		rest_day -= 1;
		if (!rest_day)
			rest_day = 1;
		/* 如果恰好为一年的最后一天 */
		if (!rest_day) {
			year -= 1;
			rest_day = 365;
		}
		for (int i = 0; rest_day > _day[i]; i++) {
			rest_day -= _day[i];
			month += 1;
		}
		day = rest_day;
	}
}

/* 显示show函数 */
void Date::show()
{
	cout << year << "." << month << "." << day << endl;
}

/* 设置对象日期set函数 */
void Date::set(int y, int m, int d)
{
	if (y > 2099 || y < 1900)
		year = 2000;
	else
		year = y;

	if (m > 12 || m < 1)
		month = 1;
	else
		month = m;

	if (day_ture(y, m, d))
		day = d;
	else
		day = 1;
}

/* 取对象当前日期get函数 */
void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}


/* 全局函数 */
/* 判断日是否非法 */
bool day_ture(int year, int month, int day)
{
	if (year > 2023 || year < 2000)
		year = 2000;
	bool leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day > 31 || day < 1)
		return 0;
	else {
		/* 判断二月 */
		if (month == 2 && day > 28 + leap)
			return 0;
		/* 判断小月 */
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return 0;
	}
	return 1;
}
/* -- 替换标记行 -- 本行不要做任何改动 -- 本行不要删除 -- 在本行的下面不要加入任何自己的语句，作业提交后从本行开始会被替换 -- 替换标记行 -- */

void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2023, 6, 7);	//2023.6.7

		cout << "无参及三参构造函数测试（完全正确）" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是2000.1.1，实际为：";
		d1.show();
		cout << "d2应该是2023.6.7，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2023, 6, 32);  //2023.6.1

		cout << "三参构造函数测试（年、月、日非法）" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2023.6.1， 实际为：";
		d4.show();

		/* 多个错，按年月日顺序处理 */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5应该是2000.2.29，实际为：";
		d5.show();
		cout << "d6应该是2000.2.1， 实际为：";
		d6.show();
		cout << "d7应该是2000.1.31，实际为：";
		d7.show();
		cout << "d8应该是2000.1.1， 实际为：";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "三参构造函数测试（闰年）" << endl;
		cout << "========================" << endl;

		cout << "d1应该是2022.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2020.2.29，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1461);          //1900.1.1
		Date d2(73048);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		Date d5(30000);      //1982.2.19
		Date d6(45083);      //2023.6.7

		cout << "一参构造函数测试，包括合法及非法值" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();
		cout << "d5应该是1982.2.19， 实际为：";
		d5.show();
		cout << "d6应该是2023.6.7，  实际为：";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		cout << "=================" << endl;

		d1.set(2023, 6, 7);	//2023.6.7
		d2.set(2023, 6);	//2023.6.1
		d3.set(2023);		//2023.1.1

		cout << "d1应该是2023.6.7，实际为：";
		d1.show();
		cout << "d2应该是2023.6.1，实际为：";
		d2.show();
		cout << "d3应该是2023.1.1，实际为：";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "测试set，年、月、日非法" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2023, 5, 32);  //2023.5.1
		d4.set(2023, 13, 12); //2023.1.12

		cout << "d1应该是2000.2.29， 实际为：";
		d1.show();
		cout << "d2应该是2019.2.1，  实际为：";
		d2.show();
		cout << "d3应该是2023.5.1，  实际为：";
		d3.show();
		cout << "d4应该是2023.1.12， 实际为：";
		d4.show();

		/* 多个错+带缺省值，按年月日顺序处理 */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5应该是2000.2.29， 实际为：";
		d5.show();
		cout << "d6应该是2000.2.1，  实际为：";
		d6.show();
		cout << "d7应该是2000.2.1，  实际为：";
		d7.show();
		cout << "d8应该是2020.2.1，  实际为：";
		d8.show();
		cout << "d9应该是2020.1.1，  实际为：";
		d9.show();
		cout << "d10应该是2000.1.31，实际为：";
		d10.show();
		cout << "d11应该是2000.1.1， 实际为：";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 6, 7);
		int y, m, d;

		cout << "测试get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "应该y=2023,m=6,d=7，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}