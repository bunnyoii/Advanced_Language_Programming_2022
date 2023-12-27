/* 2251730 信07 刘淑仪 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

public:
	Days(int y, int m, int d);		//初始化变量
	int calc_days();				//计算是当年的第几天
	bool input_ture();				//判断日期输入是否正确
};

/* --- 此处给出类成员函数的体外实现 --- */
//初始化变量
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

bool Days::input_ture()
{
	bool leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	/* 大于31天小于1天输入错误 */
	if (day > 31 || day < 1)
		return 0;
	else {
		if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
			/* 判断闰年2月日期输入是否正确*/
			if (!leap) {
				if (month == 2 && day > 28)
					return 0;
			}
			else
				if (month == 2 && day > 29)
					return 0;
			/* 判断小月日期是否大于30 */
			if (month != 2 && day > 30)
				return 0;
		}
	}

	return 1;
}

int Days::calc_days()
{
	int total_days;
	int month1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int month2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	bool leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (input_ture()) {
		total_days = day;
		if (leap)
			for (int i = 0; i < month - 1; i++)
				total_days += month2[i];
		else {
			for (int i = 0; i < month - 1; i++)
				total_days += month1[i];
		}
	}
	else
		total_days = -1;
	return total_days;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}