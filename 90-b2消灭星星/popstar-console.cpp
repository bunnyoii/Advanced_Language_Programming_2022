/* 2251730 信07 刘淑仪 */
/* 本cpp用于实现伪图形界面 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include"popstar.h"
#include "cmd_console_tools.h"
using namespace std;
//画空白格子
void blank_3(int line, int column)
{
	cct_gotoxy(1, 1);
	int x, y;
	char alphabet;
	for (int i = 0; i < column; i++)
		cout << "     " << i;
	cout << endl;
	cct_getxy(x, y);
	cct_showstr(x + 2, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(x + 4, y, "═══", COLOR_HWHITE, COLOR_BLACK, column);
	cct_showstr(x + 4 + 6 * column, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int y0 = y + 1; y0 < 3 * (line + 1); y0++) {
		int order = (y0 - 4) / 3;
		if ((y0 - 4) % 3 == 0) {
			alphabet = 'A' + order;
			cct_showch(0, y0, alphabet, COLOR_BLACK, COLOR_HWHITE, 1);
		}
		cct_showstr(x + 2, y0, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 0; i < 6; i++) {
			cct_showstr(x + i * column + 4, y0, " ", COLOR_HWHITE, COLOR_BLACK, column);
			Sleep(PATCHES_SLEEP);
		}
		cct_showstr(x + 4 + 6 * column, y0, "║", COLOR_HWHITE, COLOR_BLACK, 1);
	}
	cct_showstr(x + 2, 3 * (line + 1), "╚", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(x + 4, 3 * (line + 1), "═══", COLOR_HWHITE, COLOR_BLACK, column);
	cct_showstr(x + 4 + 6 * column, 3 * (line + 1), "╝", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();
}
void blank_4(int line, int column)
{
	cct_gotoxy(1, 1);
	int x, y;
	char alphabet;
	for (int i = 0; i < column; i++)
		cout << "     " << i << "  ";
	cout << endl;
	cct_getxy(x, y);
	int x0 = x;
	cct_showstr(x + 2, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(x + 4, y, "═══╦", COLOR_HWHITE, COLOR_BLACK, column - 1);
	cct_showstr(x + 4 + 8 * (column - 1), y, "═══╗", COLOR_HWHITE, COLOR_BLACK, 1);

	for (int y0 = y + 1; y0 < 4 * (line + 1) - 2; y0++) {
		int order = y0 / 4 - 1;
		if (y0 % 4 == 0) {
			alphabet = 'A' + order;
			cct_showch(0, y0, alphabet, COLOR_BLACK, COLOR_HWHITE, 1);
		}
		if ((y0 - 2) % 4 == 0) {
			cct_showstr(x0 + 2, y0, "╠", COLOR_HWHITE, COLOR_BLACK, 1);
			for (x = x0 + 4; x < 8 * column; x += 8) {
				cct_showstr(x, y0, "═", COLOR_HWHITE, COLOR_BLACK, 3);
				if (x == 8 * column - 4) {
					cct_showstr(x + 6, y0, "╣", COLOR_HWHITE, COLOR_BLACK, 1);
					break;
				}
				Sleep(PATCHES_SLEEP);
				cct_showstr(x + 6, y0, "╬", COLOR_HWHITE, COLOR_BLACK, 1);

			}
		}
		else {
			for (x = x0 + 2; x < 8 * column; x += 8) {
				cct_showstr(x, y0, "║", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(x + 2, y0, " ", COLOR_HWHITE, COLOR_BLACK, 6);
				Sleep(PATCHES_SLEEP);
			}
			cct_showstr(x, y0, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}
	x = x0;
	y = 4 * (line + 1) - 2;
	cct_showstr(x + 2, y, "╚", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(x + 4, y, "═══╩", COLOR_HWHITE, COLOR_BLACK, column - 1);
	cct_showstr(x + 4 + 8 * (column - 1), y, "═══╝", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();
}
//画色块
void color_patches(int line, int column, int chessboard[][12], bool separate)
{
	for (int x = PATCHES_STA_X, n = 1; x < 4 + (6 + 2 * separate) * column; x += (6 + 2 * separate), n++) {
		for (int y = PATCHES_STA_Y, m = 1; y < (3 + separate) * (line + 1 - separate); y += 3 + separate, m++) {
			int color, fg_color;
			if (chessboard[m][n] == 0) {
				color = 15;
				fg_color = 15;
			}
			else {
				color = chessboard[m][n];
				fg_color = 0;
			}
			cct_showstr(x, y, "╔═╗", color, fg_color, 1);
			cct_showstr(x, y + 1, "║★║", color, fg_color, 1);
			cct_showstr(x, y + 2, "╚═╝", color, fg_color, 1);
		}
	}
	cct_setcolor();
}
//单个色块反显
void color_patches_opposite(int x, int y, int chessboard[][12], bool separate, char line_choose , char column_choose)
{
	int color, fg_color = 7;
	int x0 = (x + 2 + 2 * separate) / (6 + 2 * separate) * (6 + 2 * separate) - 2 - 2 * separate;
	int y0 = ((y + separate) / (3 + separate)) * (3 + separate) - separate;
	if (chessboard[(y + separate) / (3 + separate)][(x + 2 + 2 * separate) / (6 + 2 * separate)] == 0)
		color = 15;
	else
		color = chessboard[(y + separate) / (3 + separate)][(x + 2 + 2 * separate) / (6 + 2 * separate)];
	if (((x + 2 + 2 * separate) / (6 + 2 * separate) == column_choose - '0' + 1 && (y + separate) / (3 + separate) == line_choose - 'A' + 1)
		&& judge_the_choice(line_choose, column_choose,  chessboard))
		fg_color = 15;
	cct_showstr(x0, y0, "╔═╗", color, fg_color, 1);
	cct_showstr(x0, y0 + 1, "║★║", color, fg_color, 1);
	cct_showstr(x0, y0 + 2, "╚═╝", color, fg_color, 1);
	cct_setcolor();
}
//鼠标或键盘反应
void mouse_or_keycode_color(int* x, int* y, int line, int column, int chessboard[][12], bool separate, char choose, char* line_choose, char* column_choose)
{
	int ret, X, Y, maction, keycode1, keycode2;
	color_patches_opposite(*x, *y, chessboard, separate, *line_choose, *column_choose);
	bool loop = 1;
	while (loop) {
		cct_setcolor();
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_showstr(0, (3 + separate) * (line + 1) + 1 - separate, "[当前鼠标] ", 0, 15, 1);
			switch (maction) {
			case MOUSE_ONLY_MOVED://移动
				if (no_removal(separate, column, line, X, Y, *x, *y))
					color_patches_opposite_restore(*x, *y, chessboard, separate);
				if (legitimate_or_not(separate, column, line, X, Y, chessboard)) {
					prompt_information(line, X, Y, separate);
					color_patches_opposite(X, Y, chessboard, separate, *line_choose, *column_choose);
					*x = X;
					*y = Y;
				}
				else
					cct_showstr(11, (3 + separate) * (line + 1) + 1 - separate, "位置非法！                                      ", 0, 12, 1);
				break;
			case MOUSE_LEFT_BUTTON_CLICK:			//左键
			case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//双击左键
				if (!no_removal(separate, column, line, X, Y, *x, *y)) {
					if (legitimate_or_not(separate, column, line, X, Y, chessboard)) {
						cct_showch(0, (3 + separate) * (line + 1) + 1 - separate, ' ', 0, 7, 80);
						cct_gotoxy(0, (3 + separate) * (line + 1) + 1 - separate);
						cout << "选中了" << char('A' + (Y + separate) / (3 + separate) - 1) << "行" << (X + 2 + 2 * separate) / (6 + 2 * separate) - 1 << "列" << endl;
						if (choose == 'F') {
							*line_choose = 'A' + (Y + separate) / (3 + separate) - 1;
							*column_choose = (X + 2 + 2 * separate) / (6 + 2 * separate) - 1 + '0';
						}
						loop = 0;
					}
				}
				else {
					color_patches_opposite_restore(*x, *y, chessboard, separate);
					if (legitimate_or_not(separate, column, line, X, Y, chessboard)) {
						prompt_information(line, X, Y, separate);
						color_patches_opposite(X, Y, chessboard, separate, *line_choose, *column_choose);
						*x = X;
						*y = Y;
					}
					else
						cct_showstr(11, (3 + separate) * (line + 1) + 1 - separate, "位置非法！                                      ", 0, 12, 1);
				}
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:			//右键
			case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//双击右键
				if (legitimate_or_not(separate, column, line, X, Y, chessboard)) {
					cct_gotoxy(0, 4 * (line + 1));
					wait_for_end();
				}
				break;
			} //end of switch(maction)
		}//end of CCT_MOUSE_EVENT
		else if (ret == CCT_KEYBOARD_EVENT) {
			cct_gotoxy(0, (3 + separate) * (line + 1) + 1 - separate);
			cct_showstr(0, (3 + separate) * (line + 1) + 1 - separate, "[当前键盘] ", 0, 15, 1);
			color_patches_opposite_restore(*x, *y, chessboard, separate);
			X = *x;
			Y = *y;
			switch (keycode1) {
			case 224:
				switch (keycode2) {
				case KB_ARROW_UP://上箭头
					while (1) {
						if (Y < PATCHES_STA_Y)
							Y = PATCHES_STA_Y + (3 + separate) * (line - 1);
						else
							Y -= 3 + separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				case KB_ARROW_DOWN://下箭头
					while (1) {
						if (Y >= PATCHES_STA_Y + (3 + separate) * (line - 1)) {
							Y = PATCHES_STA_Y;
						}
						else
							Y += 3 + separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				case KB_ARROW_LEFT://左箭头
					while (1) {
						if (X < PATCHES_STA_X)
							X = PATCHES_STA_X + (6 + 2 * separate) * (column - 1);
						else
							X -= 6 + 2 * separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				case KB_ARROW_RIGHT://右箭头
					while (1) {
						if (X >= PATCHES_STA_X + (6 + 2 * separate) * (column - 1))
							X = PATCHES_STA_X;
						else
							X += 6 + 2 * separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				}
				color_patches_opposite(X, Y, chessboard, separate, *line_choose, *column_choose);
				prompt_information(line, X, Y, separate);
				*x = X;
				*y = Y;
				break;
			case 13:
				cct_gotoxy(0, (3 + separate) * (line + 1) + 1 - separate);
				cout << "选中了" << char('A' + (Y + separate) / (3 + separate) - 1) << "行" << (X + 2 + 2 * separate) / (6 + 2 * separate) - 1 << "列" << endl;
				if (choose == 'F') {
					*line_choose = 'A' + (Y + separate) / (3 + separate) - 1;
					*column_choose = (X + 2 + 2 * separate) / (6 + 2 * separate) - 1 + '0';
				}
				loop = 0;
				break;
			case 'Q':
			case 'q':
				cct_gotoxy(0, (3 + separate) * (line + 1));
				wait_for_end();
			}//end of swicth(keycode1)
		}//end of CCT_KEYBOARD_EVENT
	}
}
void prompt_information(int line,int X,int Y,bool separate)
{
	cct_showch(11, (3 + separate) * (line + 1) + 1 - separate, ' ', 0, 7, 80);
	cct_gotoxy(11, (3 + separate) * (line + 1) + 1 - separate);
	cct_setcolor(0, 10);
	cout << char('A' + (Y + separate) / (3 + separate) - 1) << "行" << (X + 2 + 2 * separate) / (6 + 2 * separate) - 1 << "列";
	cct_showch(17, (3 + separate) * (line + 1) + 1 - separate, ' ', 0, 7, 50);
}
//确认位置是否合法
bool legitimate_or_not(bool separate, int column, int line, int X, int Y, int chessboard[][12])
{
	if (separate) {
		if (X >= PATCHES_STA_X && X < PATCHES_STA_X + 8 * column && Y >= PATCHES_STA_Y && Y < PATCHES_STA_Y + 4 * line
			&& (Y - 2) % 4 != 0 && (X - 10) % 8 != 0 && (X - 11) % 8 != 0
			&& chessboard[(Y + 1) / 4][(X + 4) / 8] != 0)
			return 1;
	}
	else {
		if (X >= PATCHES_STA_X && X < PATCHES_STA_X + 6 * column && Y >= PATCHES_STA_Y && Y < PATCHES_STA_Y + 3 * line
			&& chessboard[Y / 3][(X + 2) / 6] != 0)
			return 1;
	}
	return 0;
	//1:合法
	//0:不合法
}
//确认移动后坐标是否在色块内
bool no_removal(bool separate, int column, int line, int X, int Y, int x, int y)
{
	if (separate) {
		if ((X + 4) / 8 != (x + 4) / 8 || (Y + 1) / 4 != (y + 1) / 4 ||
			(Y - 2) % 4 == 0 || (X - 10) % 8 == 0 || (X - 11) % 8 == 0)
			return 1;
	}
	else {
		if ((X + 2) / 6 != (x + 2) / 6 || Y / 3 != y / 3)
			return 1;
	}
	return 0;
	//1:不在
	//0:在
}
//消除
void eliminate_patches(int line, int column, char chessboard_search_[][12], int chessboard[][12], bool separate)
{
	int x, y;
	for (int i = 1; i < line + 1; i++) {
		for (int j = 1; j < column + 1; j++) {
			x = (6 + 2 * separate) * j - (2 + 2 * separate);
			y = i * (3 + separate) - separate;
			if (chessboard_search_[i][j] == '*') {
				cct_showstr(x, y, " ", 15, 15, 6);
				cct_showstr(x, y + 1, " ", 15, 15, 6);
				cct_showstr(x, y + 2, " ", 15, 15, 6);
				chessboard[i][j] = 0;
			}
		}
	}
	cct_setcolor();
}
//将消除的星星置0
void change_chessboard(int line, int column, int chessboard[][12], char chessboard_search_[][12])
{
	for (int i = 1; i < line + 1; i++)
		for (int j = 1; j < column + 1; j++) {
			if (chessboard_search_[i][j] == '*')
				chessboard[i][j] = 0;
		}
}
//下落
void down_patches_color(int line, int column, int chessboard[][12], char chessboard_search_[][12], bool separate)
{
	change_chessboard(line, column, chessboard, chessboard_search_);
	int t;
	int color;
	//[(x + 2) /6][y / 3]
	for (int j = 1; j < column + 1; j++)
		for (int i = line; i > 0; i--) {
			if (chessboard[i][j] != 0 && chessboard[i + 1][j] == 0 && i + 1 <= line) {
				color = chessboard[i][j];
				int x = (6 + 2 * separate) * j - (2 + 2 * separate);
				for (int y = (i + 1) * (3 + separate) - 2 * separate; y < (i + 2) * (3 + separate) - 2 * separate; y++) {
					cct_showstr(x, y, "╚═╝", color, COLOR_BLACK, 1);
					cct_showstr(x, y - 1, "║★║", color, COLOR_BLACK, 1);
					cct_showstr(x, y - 2, "╔═╗", color, COLOR_BLACK, 1);
					cct_showstr(x, y - 3, "═══", 15, 15, 1);
					if ((y - 1) % 4 == 0 && separate == 1)
						cct_showstr(x, y - 3, "═══", 15, 0, 1);
					Sleep(MOVE_SLEEP);
				}
				t = chessboard[i + 1][j];
				chessboard[i + 1][j] = chessboard[i][j];
				chessboard[i][j] = t;
				i += 2;

			}
		}
}
//左移
void left_patches_color(int line, int column, int chessboard[][12], char chessboard_search_[][12], bool separate)
{
	int t = 0;
	bool out = 1;
	int color;
	for (int j = 2; j < column + 1; j++)
		if (chessboard[line][j - 1] == 0 && chessboard[line][j] != 0) {
			for (int i = line; chessboard[i][j] != 0; i--) {
				color = chessboard[i][j];
				int y = i * (3 + separate) - 1 + 2 * separate;
				for (int x = (6 + 2 * separate) * j - (2 + 2 * separate); x > (6 + 2 * separate) * (j - 1) - (2 + 2 * separate) - 1; x--) {
					cct_showstr(x, y, "╚═╝", color, 0, 1);
					cct_showstr(x + 6, y, " ", 15, 0, 1);
					cct_showstr(x, y - 1, "║★║", color, 0, 1);
					cct_showstr(x + 6, y - 1, " ", 15, 0, 1);
					cct_showstr(x, y - 2, "╔═╗", color, 0, 1);
					cct_showstr(x + 6, y - 2, " ", 15, 0, 1);
					if ((x + 4) % 8 == 0 && separate == 1) {
						cct_showstr(x + 6, y, "║", 15, 0, 1);
						cct_showstr(x + 6, y - 1, "║", 15, 0, 1);
						cct_showstr(x + 6, y - 2, "║", 15, 0, 1);
					}
					Sleep(MOVE_SLEEP);
				}
				t = chessboard[i][j - 1];
				chessboard[i][j - 1] = chessboard[i][j];
				chessboard[i][j] = t;
			}
			j = 1;
		}
}
//按键进行操作
int eliminate_confirm(bool separate, int column, int line, int *x, int *y, int chessboard[][12], char chessboard_search_[][12])
{
	int ret, X, Y, maction, keycode1, keycode2;
	bool loop = 1;
	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
				switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
				case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//双击左键
					if (!no_removal(separate, column, line, X, Y, *x, *y))
						return 2;
					else {
						eliminate_move_restore(line, column, chessboard, chessboard_search_, separate);
						return 1;
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
				case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:
					if (legitimate_or_not(separate, column, line, X, Y, chessboard)) {
						cct_gotoxy(0, 4 * (line + 1));
						wait_for_end();
					}
					break;
				case MOUSE_ONLY_MOVED:
					if (no_removal(separate, column, line, X, Y, *x, *y)) {
						eliminate_move_restore(line, column, chessboard, chessboard_search_, separate);
						return 1;
					}
					break;
				} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (keycode1) {
			case 224:
				X = *x;
				Y = *y;
				eliminate_move_restore(line, column, chessboard, chessboard_search_, separate);
				switch (keycode2) {
				case KB_ARROW_UP:
					while (1) {
						if (Y < PATCHES_STA_Y)
							Y = PATCHES_STA_Y + (3 + separate) * line - 1;
						else
							Y -= 3 + separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				case KB_ARROW_DOWN:
					while (1) {
						if (Y >= PATCHES_STA_Y + (3 + separate) * line)
							Y = PATCHES_STA_Y;
						else
							Y += 3 + separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				case KB_ARROW_LEFT:
					while (1) {
						if (X < PATCHES_STA_X)
							X = PATCHES_STA_X + (6 + 2 * separate) * column - 2;
						else
							X -= 6 + 2 * separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				case KB_ARROW_RIGHT:
					while (1) {
						if (X >= PATCHES_STA_X + (6 + 2 * separate) * column)
							X = PATCHES_STA_X;
						else
							X += 6 + 2 * separate;
						if (chessboard[(Y + separate) / (3 + separate)][(X + 2 + 2 * separate) / (6 + 2 * separate)] != 0)
							break;
					}
					break;
				}
				*x = X;
				*y = Y;
				color_patches_opposite(X, Y, chessboard, separate);
				return 1;
				break;
			case 13:
				return 3;
				break;
			case 'Q':
			case 'q':
				cct_gotoxy(0, 4 * (line + 1)); 
				wait_for_end();
			case 'C':
			case 'c':
				return 2;
			}//end of swicth(keycode1)
		}//end of else if(ret == CCT_KEYBOARD_EVENT）
	} //end of while(1)
	return 0;
}
void eliminate_move_restore(int line,int column, int chessboard[][12], char chessboard_search_[][12],bool separate)
{
	for (int i = 1; i < line + 1; i++) {
		for (int j = 1; j < column + 1; j++) {
			if (chessboard_search_[i][j] == '*') {
				color_patches_opposite_restore((6 + 2 * separate) * j - 2 - 2 * separate, i * (3 + separate), chessboard, separate);
				cct_showch(0, (3 + separate) * (line + 1) + 1 - separate, ' ', 0, 7, 80);
			}
		}
	}
}
//单个色块恢复(取消反显)
void color_patches_opposite_restore(int x, int y, int chessboard[][12], bool separate)
{
	int color, fg_color;
	int x0 = (x + 2 + 2 * separate) / (6 + 2 * separate) * (6 + 2 * separate) - 2 - 2 * separate;
	int y0 = ((y + separate) / (3 + separate)) * (3 + separate) - separate;
	color = chessboard[(y + separate) / (3 + separate)][(x + 2 + 2 * separate) / (6 + 2 * separate)];
	if (chessboard[(y + separate) / (3 + separate)][(x + 2 + 2 * separate) / (6 + 2 * separate)] == 0) {
		color = 15;
		fg_color = 15;
	}
	else {
		color = chessboard[(y + separate) / (3 + separate)][(x + 2 + 2 * separate) / (6 + 2 * separate)];
		fg_color = 0;
	}
	cct_showstr(x0, y0, "╔═╗", color, fg_color, 1);
	cct_showstr(x0, y0 + 1, "║★║", color, fg_color, 1);
	cct_showstr(x0, y0 + 2, "╚═╝", color, fg_color, 1);
	cct_setcolor();
}