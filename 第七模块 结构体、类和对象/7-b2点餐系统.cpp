/* 2251730 信07 刘淑仪k */
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
	cout << "                             KFC 2023春季菜单" << endl;
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
		cout << "点单完成，按任意键继续.";
	else
		cout << "输入错误，按任意键继续" << endl;
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
	cout << endl << "【优惠信息】：" << endl;
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
	menu_KFC normal[26] = { {'A',"香辣鸡腿堡",19.5},{'B',"劲脆鸡腿堡",19.5},{'C',"新奥尔良烤鸡腿堡",20},{'D',"老北京鸡肉卷",18.5},
		{'E',"黄金SPA鸡排堡(藤椒风味)",18},{'F',"经典美式风味嫩牛堡(单层)",18},{'G',"吮指原味鸡(1块)",12.5},{'H',"黄金脆皮鸡",13.5},
		{'I',"新奥尔良烤翅(2块)",13.5},{'J',"劲爆鸡米花",12},{'K',"香辣鸡翅(2块)",12.5},{'L',"热辣香骨鸡(3块)",12.5},{'M',"汁汁厚做培根三层和牛堡",55},
		{'N',"薯条(小)",9},{'O',"薯条(中)",12.5},{'P',"薯条(大)",14.5},{'Q',"芙蓉蔬荟汤",9},{'R',"原味花筒冰激凌",6},{'S',"醇香土豆泥",7.5},
		{'T',"黄金鸡块",12.5},{'U',"葡式蛋挞",8},{'V',"百事可乐(小)",8.5},{'W',"百事可乐(中)",10},{'X',"百事可乐(大)",12},{'Y',"九珍果汁",13},{'Z',"雪顶咖啡",14.5}
	};
	menu_combo sale[4] = {
		{"COW","OK三件套(新奥尔良烤鸡腿堡)",33.5},{"HHHHHKKKSUWWW","超级全家桶(脆皮鸡)",101},
		{"APUY","人气明星配四件套(8折)",44},{"GG","吮指原味鸡(2块)",21}
	};
	menu(normal);
	combo_menu(sale, normal);
	cout << endl << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl << "请点单: ";
	//点单
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
	//查看套餐
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
	//计算价格
	for (int j = 0; order[j] != '\0'; j++) {
		for (int k = 0;; k++) {
			if (order[j] == normal[k].number) {
				total_price += normal[k].price;
				break;
			}
		}
	}
	//判断套餐
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
	//排序
	bubble_sort(order);
	//合并菜品输出
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
	//输出点餐内容
	cout << endl << "您的点餐=";
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
	cout << "共计：" << total_price << "元" << endl;
	wait_for_next(1);
	return 0;
}