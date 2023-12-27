/* 2251730 ��07 ������k */
#define LONG 73
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

void menu(struct menu_KFC normal[]);
void wait_for_next(bool end_or_wrong);
void bubble_sort(char order[]);
void combo_menu(struct menu_combo sale[], struct menu_KFC normal[]);
void judge_the_same(char order[], int same[]);
int min(int array[]);
int main();

struct menu_KFC {
	char number;
	char name[256];
	double price;
};
struct menu_combo {
	char combo_number[256];
	char combo_name[256];
	double combo_price;
};
void menu(struct menu_KFC normal[]) {
	cout << setw(LONG) << setfill('=') << "=" << endl;
	cout << "                             KFC 2023�����˵�" << endl;
	cout << setw(LONG) << setfill('=') << "=" << endl;
	for (int i = 0; i < 26; i++) {
		cout << " " << normal[i].number << " ";
		cout << setw(26) << setfill(' ') << setiosflags(ios::left) << normal[i].name;
		cout << setw(7) << setfill(' ') << setiosflags(ios::left) << normal[i].price;
		if (int(normal[i].number) % 2 == 0)
			cout << endl;
		else
			cout << "|  ";
	}
}
void wait_for_next(bool end_or_wrong)
{
	char ch;
	if (end_or_wrong)
		cout << "�㵥��ɣ������������.";
	else
		cout << "������󣬰����������" << endl;
	ch = _getch();
	system("cls");
	main();
}
void combo_menu(struct menu_combo sale[], struct menu_KFC normal[])
{
	int same[4][26] = { 0 };
	for (int k = 0; k < 4; k++)
		judge_the_same(sale[k].combo_number, same[k]);
	for (int k = 0; k < 4; k++) {
		for (int i = 0; sale[k].combo_number[i] != '\0'; i++) {
			if (sale[k].combo_number[i] == '0') {
				i++;
				continue;
			}
			for (int j = i + 1; sale[k].combo_number[j] != '\0'; j++) {
				if (sale[k].combo_number[j] == sale[k].combo_number[i]) {
					sale[k].combo_number[j] = '0';
				}
			}
		}
	}
	cout << endl << "���Ż���Ϣ����" << endl;
	for (int i = 0; i < 4; i++) {
		cout << sale[i].combo_name << "=";
		for (int j = 0; sale[i].combo_number[j] != '\0'; j++) {
			if (sale[i].combo_number[j] != '0') {
				if (j != 0)
					cout << "+";
				cout << normal[sale[i].combo_number[j] - 'A'].name;
				if ((i == 1 || i == 3) && same[i][sale[i].combo_number[j] - 'A'] != 0)
					cout << "*" << same[i][sale[i].combo_number[j] - 'A'] + 1;
			}
		}
		cout << "=";
		cout << sale[i].combo_price;
		cout << endl;
	}
}
void judge_the_same(char order[], int same[])
{
	for (int i = 0; order[i] != '\0'; i++)
		if (order[i] == order[i + 1])
			same[order[i] - 'A'] ++;
}
int min(int array[])
{
	int min = 0;
	for (int i = 0; i < 26; i++) {
		if (array[i] != 0)
			min = array[i];
	}
	for (int i = 0; i < 26; i++) {
		if (array[i] < min && array[i] > 0)
			min = array[i];
	}
	return min;
}
void bubble_sort(char order[])
{
	int j, t;
	for (int i = 0; order[i + 1] != '\0'; i++)
		for (j = 0; order[j + 1] != '\0'; j++) {
			if (order[j] > order[j + 1] && order[j + 1] != '0') {
				t = order[j];
				order[j] = order[j + 1];
				order[j + 1] = t;
			}
		}
}
int main()
{
	system("mode con cols=100 lines=45");
	char order[4096];
	double total_price = 0;
	int same[26] = { 0 };
	char* p;
	menu_KFC normal[26] = { {'A',"�������ȱ�",19.5},{'B',"���༦�ȱ�",19.5},{'C',"�°¶��������ȱ�",20},{'D',"�ϱ��������",18.5},
		{'E',"�ƽ�SPA���ű�(�ٽ���ζ)",18},{'F',"������ʽ��ζ��ţ��(����)",18},{'G',"˱ָԭζ��(1��)",12.5},{'H',"�ƽ��Ƥ��",13.5},
		{'I',"�°¶�������(2��)",13.5},{'J',"�������׻�",12},{'K',"��������(2��)",12.5},{'L',"������Ǽ�(3��)",12.5},{'M',"֭֭������������ţ��",55},
		{'N',"����(С)",9},{'O',"����(��)",12.5},{'P',"����(��)",14.5},{'Q',"ܽ��������",9},{'R',"ԭζ��Ͳ������",6},{'S',"����������",7.5},
		{'T',"�ƽ𼦿�",12.5},{'U',"��ʽ��̢",8},{'V',"���¿���(С)",8.5},{'W',"���¿���(��)",10},{'X',"���¿���(��)",12},{'Y',"�����֭",13},{'Z',"ѩ������",14.5}
	};
	menu_combo sale[4] = {
		{"COW","OK������(�°¶��������ȱ�)",33.5},{"HHHHHKKKSUWWW","����ȫ��Ͱ(��Ƥ��)",101},
		{"APUY","�����������ļ���(8��)",44},{"GG","˱ָԭζ��(2��)",21}
	};
	menu(normal);
	combo_menu(sale, normal);
	cout << endl << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl << "��㵥: ";
	//�㵥
	int i = 0;
	while (1) {
		order[i] = _getch();
		cout << order[i];
		if (order[0] == '0' && order[1] == 13)
			return 0;
		if (order[0] == 13) {
			cout << endl;
			wait_for_next(0);
		}
		if (order[i] == 13)
			break;
		i++;
	}
	cout << endl;
	order[i] = '\0';
	for (int i = 0; order[i] != '\0'; i++) {
		if (order[i] >= 'a' && order[i] <= 'z')
			order[i] -= 32;
		if (order[i] == 32)
			wait_for_next(0);
	}
	//�鿴�ײ�
	int flag[4][26] = { 0 };
	for (int k = 0; k < 4; k++) {
		for (p = order; *p != '\0'; p++) {
			if (k == 0) {
				if (*p == 'C' || *p == 'O' || *p == 'W')
					flag[k][*p - 'A']++;
			}
			else if (k == 1) {
				if (*p == 'H' || *p == 'K' || *p == 'S' || *p == 'U' || *p == 'W')
					flag[k][*p - 'A']++;
			}
			else if (k == 2) {
				if (*p == 'A' || *p == 'P' || *p == 'U' || *p == 'Y')
					flag[k][*p - 'A']++;
			}
			else if (k == 3) {
				if (*p == 'G')
					flag[k][*p - 'A']++;
			}
		}
	}
	//����۸�
	for (int j = 0; order[j] != '\0'; j++) {
		for (int k = 0;; k++) {
			if (order[j] == normal[k].number) {
				total_price += normal[k].price;
				break;
			}
		}
	}
	//�ж��ײ�
	if (1) {
		flag[1]['H' - 'A'] /= 5;
		flag[1]['K' - 'A'] /= 3;
		flag[1]['W' - 'A'] /= 3;
		if (flag[0]['C' - 'A'] > 0 && flag[0]['O' - 'A'] > 0 && flag[0]['W' - 'A'] > 0) {
			total_price -= 9 * min(flag[0]);
		}
		if (flag[1]['H' - 'A'] > 0 && flag[1]['K' - 'A'] > 0 && flag[1]['W' - 'A'] > 0 &&
			flag[1]['S' - 'A'] > 0 && flag[1]['U' - 'A'] > 0) {
			total_price -= 49.5 * min(flag[1]);
		}
		if (flag[2]['A' - 'A'] > 0 && flag[2]['P' - 'A'] > 0 && flag[2]['U' - 'A'] > 0 && flag[2]['Y' - 'A'] > 0) {
			total_price -= 11 * min(flag[2]);
		}
		if (flag[3]['G' - 'A'] / 2 > 0) {
			total_price -= 4.0 * (flag[3]['G' - 'A'] / 2);
		}
	}
	//����
	bubble_sort(order);
	//�ϲ���Ʒ���
	judge_the_same(order, same);
	for (int i = 0; order[i] != '\0'; i++) {
		if (order[i] != '0') {
			for (int j = i + 1; order[j] != '\0'; j++) {
				if (order[j] == order[i]) {
					order[j] = '0';
				}
			}
		}
		else
			continue;
	}
	//����������
	cout << endl << "���ĵ��=";
	for (int j = 0; order[j] != '\0'; j++) {
		if (order[j] != '0') {
			if (j != 0)
				cout << "+";
			for (int k = 0;; k++) {
				if (order[j] == normal[k].number) {
					cout << normal[k].name;
					if (same[order[j] - 'A'] != 0)
						cout << "*" << same[order[j] - 'A'] + 1;
					break;
				}
			}
		}
	}
	cout << endl;
	cout << "���ƣ�" << total_price << "Ԫ" << endl;
	wait_for_next(1);
	return 0;
}