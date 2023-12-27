/* 2251730 ��07 ������ */
/* ��cpp���ڴ���ڲ�ʵ�����麯�� */
#include<iostream>
#include <time.h>
#include <windows.h>
#include"popstar.h"
#include "cmd_console_tools.h"
using namespace std;

//����ʼ���
void print_foundation(int line, int column, int search_or_not)
{
	if (search_or_not == 1)
		cout << endl << "��ǰ���飺" << endl;
	else if (search_or_not == 2)
		cout << endl << "���ҽ�����飺" << endl;
	else if (search_or_not == 3)
		cout << endl << "���ҽ�����飨��ɫ��ʶ����" << endl;
	else if(search_or_not == 4)
		cout << endl << "��ֵͬ�鲢�������(��ͬɫ��ʶ):" << endl;
	else if (search_or_not == 5)
		cout << endl << "����������:" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << "  " << i;
	cout << endl;
	cout << "--+-";
	for (int i = 0; i < column; i++)
		cout << "---";
	cout << endl;
}
//�������
void print_chessboard(int line, int column, int chessboard[][12],int search_or_not, char line_choose, char column_choose,char chessboard_search_[][12])
{
	int x, y;
	print_foundation(line, column, search_or_not);
	if (search_or_not == 2)
		chessboard_search(line_choose, column_choose, chessboard, chessboard_search_);
	else if (search_or_not == 5) {
		chessboard_down(line, column, chessboard);
		chessboard_left(line, column, chessboard);
	}
	for (int i = 1; i < line + 1; i++) {
		cout << char(64 + i) << " |";
		for (int j = 1; j < column + 1; j++) {
			cct_setcolor();
			cout << "  ";
			cct_getxy(x, y);
			if (search_or_not == 1 || search_or_not == 5) {
				if (chessboard[i][j] == 0)
					cct_showint(x, y, chessboard[i][j], COLOR_HYELLOW, COLOR_BLACK);
				else
					cct_showint(x, y, chessboard[i][j], COLOR_BLACK, COLOR_WHITE);
			}
			else if (search_or_not == 2)
				cout << chessboard_search_[i][j];
			else {
				if (chessboard_search_[i][j] == '*') {
					if (search_or_not == 4)
						chessboard[i][j] = 0;
					cct_showint(x, y, chessboard[i][j], COLOR_HYELLOW, COLOR_BLACK);
				}
				else
					cct_showint(x, y, chessboard[i][j], COLOR_BLACK, COLOR_WHITE);
			}
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		}
		cout << endl;
	}
	cout << endl;
}
//�����������
void chessboard_generate(int line,int column,int chessboard[][12])
{
	srand((unsigned int)(time(0)));
	int max = column > line ? column : line;
	for (int i = 1; i < max + 1; i++)
		for (int j = 1; j < max + 1; j++)
			chessboard[i][j] = rand() % DIFFICULTY + 9;
}
//Ѱ����ͬ��
void chessboard_search(char line_choose, char column_choose, int chessboard[][12],char chessboard_search_[][12])
{
	if (line_choose == 'J' + 1 || line_choose == 'A' - 1 || column_choose == '12' + 1 || column_choose == '0' - 1)
		return;
	int line = line_choose - 'A' + 1;
	int column = column_choose - '0' + 1;
	chessboard_search_[line][column] = '*';
	if (chessboard[line + 1][column] == chessboard[line][column] && chessboard_search_[line + 1][column] != '*')
		chessboard_search(line_choose + 1, column_choose, chessboard, chessboard_search_);

	if (chessboard[line - 1][column] == chessboard[line][column] && chessboard_search_[line - 1][column] != '*')
		chessboard_search(line_choose - 1, column_choose, chessboard, chessboard_search_);

	if (chessboard[line][column + 1] == chessboard[line][column] && chessboard_search_[line][column + 1] != '*')
		chessboard_search(line_choose, column_choose + 1, chessboard, chessboard_search_);

	if (chessboard[line][column - 1] == chessboard[line][column] && chessboard_search_[line][column - 1] != '*')
		chessboard_search(line_choose, column_choose - 1, chessboard, chessboard_search_);
}
//��������
void chessboard_down(int line, int column,int chessboard[][12])
{
	int t;
	for (int j = 1; j < column + 1; j++)
		for (int i = line; i > 0; i--)
			if (chessboard[i][j] != 0 && chessboard[i + 1][j] == 0 && i + 1 <= line) {
				t = chessboard[i + 1][j];
				chessboard[i + 1][j] = chessboard[i][j];
				chessboard[i][j] = t;
				i += 2;
			}
}
//��������
void chessboard_left(int line, int column, int chessboard[][12])
{
	bool out = 1;
	while (out) {
		int t = 0;
		for (int j = 1; j < column + 1; j++) {
			if (chessboard[line][j] == 0) {
				for (int i = line; i > 0; i--) {
					t = chessboard[i][j];
					chessboard[i][j] = chessboard[i][j + 1];
					chessboard[i][j + 1] = t;
				}
			}
		}
		for (int j = 1; j < column + 1; j++) {
			if (chessboard[line][j] == 0 && chessboard[line][j + 1] != 0) {
				out = 1;
				break;
			}
			else
				out = 0;
		}
	}
}