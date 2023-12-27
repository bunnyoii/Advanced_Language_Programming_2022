#pragma once
/* 2251730 信07 刘淑仪 */

#define DIFFICULTY 5
#define SCREEN_LINE 38
#define SCREEN_COLUMN 67
#define PATCHES_STA_X 4
#define PATCHES_STA_Y 3
#define MOVE_SLEEP 1
#define PATCHES_SLEEP 10

//打印颜色的坐标的数组为chessboar[(x + 2) /6][y / 3]
//popstar-base
void print_foundation(int line, int column, int search_or_not);
void print_chessboard(int line, int column, int chessboard[][12], int search_or_not, char line_choose, char column_choose, char chessboard_search_[][12]);
void chessboard_generate(int line, int column, int chessboard[][12]);
void chessboard_search(char line_choose, char column_choose, int chessboard[][12], char chessboard_search_[][12]);
void chessboard_down(int line, int column, int chessboard[][12]);
void chessboard_left(int line, int column, int chessboard[][12]);

//popstar-tools
void input(int*line, int* column);
void select(int line, int column, char coordinate[], char* line_choose, char* column_choose, int chessboard[][12]);
bool judge_the_choice(char line_choose, char column_choose, int chessboard[][12]);
void chessboard_search_initialize(char chessboard_search_[][12]);
char eliminate(char line_choose, char column_choose);
void wait_for_end(void);
int grade(char chessboard_search_[][12]);
void enter_for_sth(int choose);
int non_eliminable(int line, int column, int chessboard[][12]);
int game_over(int line, int column, int chessboard[][12]);
int reward(int line, int column, int chessboard[][12]);
void menu_A(void);
void menu_B(void);
void menu_C(void);
void menu_D(void);
void menu_E(void);
void menu_F(void);
void menu_G(void);

//popstar-console
void blank_4(int line, int column);
void blank_3(int line, int column);
void color_patches(int line, int column, int chessboard[][12],bool separate);
void color_patches_opposite(int x, int y, int chessboard[][12], bool separate, char line_choose = '0', char column_choose = '0');
void mouse_or_keycode_color(int* x, int* y, int line, int column, int chessboard[][12], bool separate, char choose, char* line_choose, char* column_choose);
void prompt_information(int line, int X, int Y, bool separate);
bool legitimate_or_not(bool separate, int column, int line, int X, int Y, int chessboard[][12]);
bool no_removal(bool separate, int column, int line, int X, int Y, int x, int y);
void eliminate_patches(int line, int column, char chessboard_search_[][12], int chessboard[][12], bool separate);
void change_chessboard(int line, int column, int chessboard[][12], char chessboard_search_[][12]);
void down_patches_color(int line, int column, int chessboard[][12], char chessboard_search_[][12], bool separate);
void left_patches_color(int line, int column, int chessboard[][12], char chessboard_search_[][12], bool separate);
void color_patches_opposite_restore(int x, int y,int chessboard[][12], bool separate);
int eliminate_confirm(bool separate, int column, int line, int* x, int* y, int chessboard[][12], char chessboard_search_[][12]);
void eliminate_move_restore(int line, int column, int chessboard[][12], char chessboard_search_[][12], bool separate);

//popstar-main
int main(void);
int menu_and_choose(void);