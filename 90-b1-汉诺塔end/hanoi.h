/*2251730 ��07 ������*/
#pragma once

/* ------------------------------------------------------------------------------------------------------
	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

//���ú���
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



