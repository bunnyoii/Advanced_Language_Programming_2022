/* 2251730 ��07 ������ */
#include <iostream>
#include <conio.h>
using namespace std;

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */

/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */
bool day_ture(int year, int month, int day);
/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */

public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date(int y, int m, int d);//���ι���
	Date();//�޲ι���
	Date(int d);//һ�ι���
	void show();
	void set(int y, int m = 1, int d = 1);
	void get(int& y, int& m, int& d);
};

/* ���캯�� */
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
	/* ���ڷǷ� */
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
	/* ���ںϷ� */
	else {
		/* �ų�ǰ���꣨1900�������꣩*/
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
		/* ���ǡ��Ϊһ������һ�� */
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

/* ��ʾshow���� */
void Date::show()
{
	cout << year << "." << month << "." << day << endl;
}

/* ���ö�������set���� */
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

/* ȡ����ǰ����get���� */
void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}


/* ȫ�ֺ��� */
/* �ж����Ƿ�Ƿ� */
bool day_ture(int year, int month, int day)
{
	if (year > 2023 || year < 2000)
		year = 2000;
	bool leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day > 31 || day < 1)
		return 0;
	else {
		/* �ж϶��� */
		if (month == 2 && day > 28 + leap)
			return 0;
		/* �ж�С�� */
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return 0;
	}
	return 1;
}
/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2023, 6, 7);	//2023.6.7

		cout << "�޲μ����ι��캯�����ԣ���ȫ��ȷ��" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.1.1��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2023.6.7��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2023, 6, 32);  //2023.6.1

		cout << "���ι��캯�����ԣ��ꡢ�¡��շǷ���" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.3.15��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2000.3.4�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2005.1.15��ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2023.6.1�� ʵ��Ϊ��";
		d4.show();

		/* �������������˳���� */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5Ӧ����2000.2.29��ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1�� ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.1.31��ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2000.1.1�� ʵ��Ϊ��";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "���ι��캯�����ԣ����꣩" << endl;
		cout << "========================" << endl;

		cout << "d1Ӧ����2022.2.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2020.2.29��ʵ��Ϊ��";
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

		cout << "һ�ι��캯�����ԣ������Ϸ����Ƿ�ֵ" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����1900.1.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2099.12.31��ʵ��Ϊ��";
		d4.show();
		cout << "d5Ӧ����1982.2.19�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2023.6.7��  ʵ��Ϊ��";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //����2000.1.1

		cout << "����set����ȱʡֵ" << endl;
		cout << "=================" << endl;

		d1.set(2023, 6, 7);	//2023.6.7
		d2.set(2023, 6);	//2023.6.1
		d3.set(2023);		//2023.1.1

		cout << "d1Ӧ����2023.6.7��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2023.6.1��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2023.1.1��ʵ��Ϊ��";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "����set���ꡢ�¡��շǷ�" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2023, 5, 32);  //2023.5.1
		d4.set(2023, 13, 12); //2023.1.12

		cout << "d1Ӧ����2000.2.29�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2019.2.1��  ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2023.5.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2023.1.12�� ʵ��Ϊ��";
		d4.show();

		/* �����+��ȱʡֵ����������˳���� */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5Ӧ����2000.2.29�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1��  ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.2.1��  ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2020.2.1��  ʵ��Ϊ��";
		d8.show();
		cout << "d9Ӧ����2020.1.1��  ʵ��Ϊ��";
		d9.show();
		cout << "d10Ӧ����2000.1.31��ʵ��Ϊ��";
		d10.show();
		cout << "d11Ӧ����2000.1.1�� ʵ��Ϊ��";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 6, 7);
		int y, m, d;

		cout << "����get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "Ӧ��y=2023,m=6,d=7��ʵ��Ϊ��";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}