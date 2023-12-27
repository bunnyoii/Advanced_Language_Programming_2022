/* 2251730 ��07 ������ */
#include<iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {
	char bomb[12][28] = { ' ' };
	int show[12][28] = { 0 };
	//��ʼ��
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			bomb[i][j] = ' ';
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			show[i][j] = 0;
	//�������������
	srand((unsigned int)(time(0)));
	//�����������鲢�����ֵ
	int x[50] = { 0 }, y[50] = { 0 }, num = 0;
	for (int i = 0; i < 50; i++) {
		x[i] = rand() % 10 + 1;
		y[i] = rand() % 26 + 1;
	}
	//����
	for (int i = 0; i < 50; i++) {
		if (bomb[x[i]][y[i]] != '*')
			bomb[x[i]][y[i]] = '*';
		else {
			x[i] = rand() % 10 + 1;
			y[i] = rand() % 26 + 1;
			i--;
		}
	}
	//�����׸���
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			num = 0;
			if (bomb[i][j - 1] == '*')
				num++;
			if (bomb[i][j + 1] == '*')
				num++;
			if (bomb[i - 1][j] == '*')
				num++;
			if (bomb[i - 1][j - 1] == '*')
				num++;
			if (bomb[i - 1][j + 1] == '*')
				num++;
			if (bomb[i + 1][j] == '*')
				num++;
			if (bomb[i + 1][j - 1] == '*')
				num++;
			if (bomb[i + 1][j + 1] == '*')
				num++;
			show[i][j] = num;
		}
	}
	//�������
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			if (bomb[i][j] == '*')
				cout << bomb[i][j] << " ";
			else
				cout << show[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}