/* 2251730 信07 刘淑仪 */
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//用getch，因此不需要支持Linux
#include <string.h>	//Dev/CB的strlen需要
using namespace std;

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;	//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //思考一下，||的左右两个条件能否互换
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt << "，按回车键继续";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

void system_time_output(const time_t input_time)  //time_t的本质是64位无符号整数
{
	struct tm* tt;	//struct tm 为系统定义的结构体

	tt = localtime(&input_time);	//localtime为系统函数

	/* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
	cout << setfill('0') << setw(4) << tt->tm_year + 1900 << '-'
		<< setw(2) << tt->tm_mon + 1 << '-'
		<< setw(2) << tt->tm_mday << ' '
		<< setw(2) << tt->tm_hour << ':'
		<< setw(2) << tt->tm_min << ':'
		<< setw(2) << tt->tm_sec << endl;

	return;
}

void tj_time_output(const struct tj_time* const tp)
{
	/* 实现自定义结构的输出，输出形式与system_time_output相同 */
	cout << setfill('0') << setw(4) << tp->tj_year << '-'
		<< setw(2) << tp->tj_month << '-'
		<< setw(2) << tp->tj_day << ' '
		<< setw(2) << tp->tj_hour << ':'
		<< setw(2) << tp->tj_minute << ':'
		<< setw(2) << tp->tj_second << endl;
}

struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//定义静态局部变量，不准动
	int rest_year;
	result.tj_month = 1;
	result.tj_day = 1;
	//计算秒数
	input_time += 28800;
	result.tj_second = input_time % 60;
	input_time = input_time / 60;
	//计算分钟
	result.tj_minute = input_time % 60;
	input_time = input_time / 60;
	//计算小时
	result.tj_hour = input_time % 24;
	//计算一共有多少个闰年
	int leap_year = input_time / (1461 * 24);
	//计算减去这些闰年后还剩多少小时
	input_time = input_time - leap_year * (1461 * 24);
	//计算剩下的小时共多少年
	if (input_time >= 0 && input_time < 8760)
		rest_year = 0;
	else if (input_time >= 8760 && input_time < 17520)
		rest_year = 1;
	else if (input_time >= 17520 && input_time < 26304)
		rest_year = 2;
	else
		rest_year = 3;
	result.tj_year = 1970 + leap_year * 4 + rest_year;
	int day1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	//计算剩下的小时共多少天
	switch (rest_year) {
	case 1:
		input_time = input_time - 365 * 24;
		break;
	case 2:
		input_time = input_time - (365 + 366) * 24;
		break;
	case 3:
		input_time = input_time - (365 * 2 + 366) * 24;
		break;
	}
	result.tj_day += input_time / 24;
	if (rest_year == 1) {
		for (int i = 0; result.tj_day > day2[i]; i++) {
			result.tj_day = result.tj_day - day2[i];
			result.tj_month++;
		}
	}
	else {
		for (int i = 0; result.tj_day > day1[i]; i++) {
			result.tj_day = result.tj_day - day1[i];
			result.tj_month++;
		}
	}
	return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		cin >> read_time; //因为采用输入重定向，此处不加任何提示

		/* 输入错误或<0则退出循环 */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "秒数             : " << read_time << endl;
		cout << "系统转换的结果   : ";
		system_time_output(read_time);

		cout << "自定义转换的结果 : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

		cout << "当前系统时间     : " << t << endl;
		cout << "系统转换的结果   : ";
		system_time_output(t);

		cout << "自定义转换的结果 : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}