/* 2251730 ��07 ������ */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

public:
	Days(int y, int m, int d);		//��ʼ������
	int calc_days();				//�����ǵ���ĵڼ���
	bool input_ture();				//�ж����������Ƿ���ȷ
};

/* --- �˴��������Ա����������ʵ�� --- */
//��ʼ������
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

bool Days::input_ture()
{
	bool leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	/* ����31��С��1��������� */
	if (day > 31 || day < 1)
		return 0;
	else {
		if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
			/* �ж�����2�����������Ƿ���ȷ*/
			if (!leap) {
				if (month == 2 && day > 28)
					return 0;
			}
			else
				if (month == 2 && day > 29)
					return 0;
			/* �ж�С�������Ƿ����30 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}