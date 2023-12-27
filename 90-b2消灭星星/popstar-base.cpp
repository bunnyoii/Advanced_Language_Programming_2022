/* 2251730 信07 刘淑仪 */
/* 本cpp用于存放内部实现数组函数 */
#include<iostream>
#include <time.h>
#include <windows.h>
#include"popstar.h"
#include "cmd_console_tools.h"
using namespace std;

//画初始横杠
void print_foundation(int line, int column, int search_or_not)
{
	if (search_or_not == 1)
		cout << endl << "当前数组：" << endl;
	else if (search_or_not == 2)
		cout << endl << "查找结果数组：" << endl;
	else if (search_or_not == 3)
		cout << endl << "查找结果数组（颜色标识）：" << endl;
	else if(search_or_not == 4)
		cout << endl << "相同值归并后的数组(不同色标识):" << endl;
	else if (search_or_not == 5)
		cout << endl << "下落后的数组:" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << "  " << i;
	cout << endl;
	cout << "--+-";
	for (int i = 0; i < column; i++)
		cout << "---";
	cout << endl;
}
//输出棋盘
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
//随机生成棋盘
void chessboard_generate(int line,int column,int chessboard[][12])
{
	srand((unsigned int)(time(0)));
	int max = column > line ? column : line;
	for (int i = 1; i < max + 1; i++)
		for (int j = 1; j < max + 1; j++)
			chessboard[i][j] = rand() % DIFFICULTY + 9;
}
//寻找相同数
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
//数组下落
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
//数组左移
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