/* 2251730 信07 刘淑仪 */
#include<iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {
	char bomb[12][28] = { ' ' };
	int show[12][28] = { 0 };
	//初始化
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			bomb[i][j] = ' ';
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			show[i][j] = ' ';
	//插入随机数种子
	srand((unsigned int)(time(0)));
	//定义坐标数组并随机赋值
	int x[50] = { 0 }, y[50] = { 0 }, num = 0;
	for (int i = 0; i < 50; i++) {
		x[i] = rand() % 12;
		y[i] = rand() % 28;
	}
	//埋雷
	for (int i = 0; i < 50; i++) {
		if (bomb[x[i]][y[i]] != '*')
			bomb[x[i]][y[i]] = '*';
		else {
			x[i] = rand() % 12;
			y[i] = rand() % 28;
			--i;
		}
	}
	//定义雷个数
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 28; j++) {
			if (bomb[i][j] != '*') {
				num = 0;
				if (i != 0 && j != 0) {
					if (bomb[i + 1][j] == '*')
						num++;
					if (bomb[i + 1][j + 1] == '*')
						num++;
					if (bomb[i + 1][j - 1] == '*')
						num++;
					if (bomb[i][j + 1] == '*')
						num++;
					if (bomb[i][j - 1] == '*')
						num++;
					if (bomb[i - 1][j - 1] == '*')
						num++;
					if (bomb[i - 1][j + 1] == '*')
						num++;
					if (bomb[i - 1][j] == '*')
						num++;
				}
				else if (i == 0 && j != 0) {
					if (bomb[i + 1][j] == '*')
						num++;
					if (bomb[i + 1][j + 1] == '*')
						num++;
					if (bomb[i + 1][j - 1] == '*')
						num++;
					if (bomb[i][j + 1] == '*')
						num++;
					if (bomb[i][j - 1] == '*')
						num++;
				}
				else if (i != 0 && j == 0) {
					if (bomb[i + 1][j] == '*')
						num++;
					if (bomb[i + 1][j + 1] == '*')
						num++;
					if (bomb[i][j + 1] == '*')
						num++;
					if (bomb[i - 1][j + 1] == '*')
						num++;
					if (bomb[i - 1][j] == '*')
						num++;
				}
				else {
					if (bomb[i + 1][j] == '*')
						num++;
					if (bomb[i + 1][j + 1] == '*')
						num++;
					if (bomb[i][j + 1] == '*')
						num++;
				}
			}
			show[i][j] = num;
		}
	}
	//输出界面
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 28; j++) {
			if (bomb[i][j] == '*')
				cout << bomb[i][j] << " ";
			else
				cout << show[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
