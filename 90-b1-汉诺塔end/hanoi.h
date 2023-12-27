/*2251730 信07 刘淑仪*/
#pragma once

/* ------------------------------------------------------------------------------------------------------
	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

//调用函数
int main();
int menu_and_choose();
void stop(int delay);
void wait_for_enter();
void input(char* src, char* tmp, char* dst, int* n, int* delay, int choose);
void hanoi(int n, char src, char tmp, char dst, int choose);
void print(int n,char src, char dst, int choose);
void longitudinal(int n, char src, char dst, int visualization);
void longitudinal_initial(int n, char src, char dst,int choose, int visualization);
void transverse(int n,char src,char dst,int choose);
void origen(int n, char src, char dst, int visualization);
void stack_initialize(int n,char src, char dst);
void initialize();
void stack_change(int n,char src, char dst);
void print_columns();
void print_firstplate(int n, char src, char dst);
void move(int n, char src, char tmp,char dst, int choose);
void input_initialize(char input[]);
void menu_one();
void menu_two();
void menu_three();
void menu_four();
void menu_five();
void menu_six();
void menu_seven();
void menu_eight();
void menu_nine();



