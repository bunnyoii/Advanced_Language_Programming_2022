/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstring>
#include <cstdio>
#include <Windows.h>
#include"hanoi.h"
#include "cmd_console_tools.h"

using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
    1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
    1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
    2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
    3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
    4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
#define N 10
#define Line_X 7
#define Line_Y 14
#define Column_X 1
#define Column_Y 15
#define Column 23
#define Interval 9
int delay = -1;
int cnt = 1;
int number[3][10];
int top[3];
//��ʱ����
void stop(int delay)
{
    if (delay == -1)
        Sleep(50);
   else if (delay != 0)
        Sleep((5 - delay) * 100);
    else {
        while (getchar() != '\n');
    }
}
void wait_for_enter()
{
    cout << endl << "���س�������";
    while (_getch() != '\r')
        ;
    cct_cls();
    main();
}
// ��������
void input(char* src, char* tmp, char* dst, int* n, int* delay, int choose)
{
    cout << endl;
    int visualization = 0;
    if (choose == 8 || choose == 9)
        visualization = 15;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> *n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (*n >= 1 && *n <= 10)
                break;
            else {
                cin.clear();
                cin.ignore(65536, '\n');
            }
        }
    }
    cin.clear();
    cin.ignore(65536, '\n');

    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> *src;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (*src > 'D')
                *src -= 32;
            if (*src == 'A' || *src == 'B' || *src == 'C')
                break;
            else {
                cin.clear();
                cin.ignore(65536, '\n');
            }
        }
    }
    cin.clear();
    cin.ignore(65536, '\n');

    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> *dst;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (*dst > 'D')
                *dst -= 32;
            if (*src > 'D')
                *src -= 32;
            if (*dst == *src) {
                cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else {
                if (*dst == 'A' || *dst == 'B' || *dst == 'C')
                    break;
                else {
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
            }
        }
    }

    if (*src == 'A' || *src == 'a') {
        *src = 'A';
        if (*dst == 'B' || *dst == 'b') {
            *tmp = 'C';
            *dst = 'B';
        }
        else {
            *tmp = 'B';
            *dst = 'C';
        }
    }
    else if (*src == 'B' || *src == 'b') {
        *src = 'B';
        if (*dst == 'A' || *dst == 'a') {
            *tmp = 'C';
            *dst = 'A';
        }
        else {
            *tmp = 'A';
            *dst = 'C';
        }
    }
    else {
        *src = 'C';
        if (*dst == 'A' || *dst == 'a') {
            *tmp = 'B';
            *dst = 'A';
        }
        else {
            *tmp = 'A';
            *dst = 'B';
        }
    }
    if (choose == 4||choose==8) {
        cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���)";
        cin >> *delay;
        cct_cls();
        stop(*delay);
    }
}
// �ݹ�������
void hanoi(int n,char src,char tmp,char dst,int choose)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp, choose);
    print(n, src, dst, choose);
    hanoi(n - 1, tmp, src, dst, choose); 
}

//��ӡ
void print(int n,char src,char dst,int choose)
{
    int visualization = 0;
    if (choose == 8 || choose == 9)
        visualization = 15;
    if (choose == 1)
        cout << n << "#" << " " << src << "---->" << dst << endl;
    else if (choose == 2 || choose == 3 || choose == 4 || choose == 8 || choose == 9) {
        if (choose == 2 || choose == 3) {
            cout << "��" << setw(4) << cnt << " ��";
            cout << "(" << setw(2) << n << "#" << " " << src << "---->" << dst << ") ";
            if (choose == 2)
                cout << endl;
            else {
                stack_change(n, src, dst);
                transverse(n, src, dst, 3);
            }
        }
        else {
            longitudinal(n, src, dst, visualization);
            stack_change(n, src, dst);
            cct_gotoxy(0, Line_Y + 4 + visualization);
            cout << "��" << setw(4) << cnt << " ��";
            cout << "(" << setw(2) << n << "#" << " " << src << "---->" << dst << ") ";
            transverse(n, src, dst, choose);
            if (choose == 9 || choose == 8) {
                stack_change(n, dst, src);
                move(n, src, 0, dst, choose);
                stack_change(n, src, dst);
            }
            stop(delay);
        }
    }
    cnt++;
}

// 3/4/8���ã������������
void transverse(int n,char src,char dst,int choose)
{
    int i = 0, j = 0;
    cout << "A:";
    for (i = 0; i < top[0]; i++)
        if (number[0][i] > 0)
            cout << setw(2) << number[0][i];
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";

    cout << "B:";
    for (i = 0; i < top[1]; i++)
        if (number[1][i] > 0)
            cout << setw(2) << number[1][i];
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";

    cout << "C:";
    for (i = 0; i < top[2]; i++)
        if (number[2][i] > 0)
            cout << setw(2) << number[2][i];
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";
    cout << endl;
}

// 4/8���ã������������
void longitudinal(int n,char src, char dst,int visualization)
{
    cct_gotoxy(Line_X + 1 + (dst - 'A') * 10, Line_Y - 1 - top[dst - 'A'] + visualization);
    cout << setw(2) << number[src - 'A'][top[src - 'A'] - 1];
    cct_gotoxy(Line_X + 1 + (src - 'A') * 10, Line_Y - top[src - 'A'] + visualization);
    cout << "  ";
}
void longitudinal_initial(int n, char src, char dst,int choose,int visualization)
{
    cct_gotoxy(0, 0);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
    if (choose != 9)
        cout << "����ʱ����Ϊ " << delay;
    cct_gotoxy(Line_X, Line_Y + visualization);
    cout << "=========================" << endl;
    cct_gotoxy(Line_X + 2, Line_Y + 1 + visualization);
    cout << "A         B         C" << endl;
    cct_gotoxy(0, Line_Y + 4 + visualization);
    cout << "��ʼ:  ";
    origen(n, src, dst, visualization);
    stop(delay);
}

 //�����ʼ�к���
void origen(int n,char src, char dst,int visualization)
{
    int i = 0, j = 0;
    cct_gotoxy(6, Line_Y + 4 + visualization);
    cout << "A: ";
    for (int i = 0; i < n; i++)
        number[0][i] == 0 ? cout << " " : cout << setw(2) << number[0][i];

    cct_gotoxy(30, Line_Y + 4 + visualization);
    cout << "B: ";
    for (int i = 0; i < n; i++)
        number[1][i] == 0 ? cout << " " : cout << setw(2) << number[1][i];

    cct_gotoxy(54, Line_Y + 4 + visualization);
    cout << "C: ";
    for (int i = 0; i < n; i++)
        number[2][i] == 0 ? cout << " " : cout << setw(2) << number[2][i];
    cout << endl;
    cct_gotoxy(Line_X + 1 + (src - 'A') * 10, Line_Y - 1 + visualization);
    for (int i = 0; i < n; i++) {
        number[src - 'A'][i] == 0 ? cout << "  " : cout << setw(2) << number[src - 'A'][i] << " ";
        cct_gotoxy(Line_X + 1 + (src - 'A') * 10, Line_Y - i - 2 + visualization);
    }
}

//ջ����ʼ������
void stack_initialize(int n,char src,char dst)
{
    top[src - 'A'] = n;
    for (int i = 0; i < n; i++)
        number[src - 'A'][i] = n - i;
}
//��ʼ������
void initialize()
{
    delay = -1;
    cnt = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++)
            number[i][j] = 0;
        top[i] = 0;
    }
}
//ջ���ƶ�����
void stack_change(int n,char src, char dst)
{
    number[dst - 'A'][top[dst - 'A']++] = number[src - 'A'][top[src - 'A'] - 1];
    number[src - 'A'][--top[src - 'A']] = 0;
}

// 5/6/7/8/9���ã���������
void print_columns()
{
    cct_showch(Column_X, Column_Y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, Column);
    cct_showch(Column_X + Column + Interval, Column_Y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, Column);
    cct_showch(Column_X + 2 * ( Column + Interval ), Column_Y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, Column);
    for (int y = Column_Y - 1; y > 2; y--)
        for (int i = 0; i < 3; i++) {
            cct_showch(Column_X + (Column - 1) / 2 + i * (Column + Interval), y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
            Sleep(50);
        }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
// 6/7/8���ã���ʼ�̺���
void print_firstplate(int n, char src,char dst)
{
    stack_initialize(n, src, dst);
    for (int i = 1; i < n + 1; i++) {
        cct_showch(Column_X + (src - 65) * (Column + Interval) + 10 - n + i, Column_Y - i, ' ', n + 1 - i, n + 1 - i, 2 * (n + 1 - i) + 1);
        Sleep(50);
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
// 7/8/9���ã������ƶ�����
void move(int n, char src,char tmp,char dst,int choose)
{
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    if (choose == 7) {
        delay = 4;
        if (n % 2 == 0)
            dst = tmp;
    }
    int x, y;
    int color = number[src - 'A'][top[src - 'A'] - 1];
    int length = 2 * number[src - 'A'][top[src - 'A'] - 1] + 1;
    int up_start_X = Column_X + (Column - 1) / 2 + (src - 'A') * (Column + Interval) - (length - 1) / 2;
    int down_end_X = Column_X + (dst - 'A') * (Column + Interval) + (Column - 1) / 2 - (length - 1) / 2;
    int right_or_left_start = Column_X + (src - 'A') * (Column + Interval) + (Column - 1) / 2 - (length - 1) / 2;
    int right_or_left_end = Column_X + (dst - 'A') * (Column + Interval) + +(Column - 1) / 2 - (length - 1) / 2;

    //����
    for (y = Column_Y - top[src - 'A']; y > 0; y--) {
        cct_showstr(up_start_X, y, " ", color, color, length);
        delay != 0 ? stop(delay) : Sleep(4);
        if (y > 1) {
            cct_showch(up_start_X, y, ' ', COLOR_BLACK, COLOR_WHITE, length);
            if (y > 2)
                cct_showch(Column_X + (Column - 1) / 2 + (src - 'A') * (Column + Interval), y, ' ', 14, 14, 1);
        }
    }
    //������
    if (src < dst) {//��
        for (x = right_or_left_start; x < right_or_left_end; x++) {
            cct_showch(x, 1, ' ', color, color, length);
            delay != 0 ? stop(delay) : Sleep(4);
            if (x < right_or_left_end)
                cct_showch(x, 1, ' ', COLOR_BLACK, COLOR_WHITE, length);
        }
    }
    else{//��
        for (x = right_or_left_start; x > right_or_left_end; x--) {
            cct_showch(x, 1, ' ', color, color, length);
            delay != 0 ? stop(delay) : Sleep(4);
            if (x > right_or_left_end)
                cct_showch(x, 1, ' ', COLOR_BLACK, COLOR_WHITE, length);
        }
    }
    //����
    for (y = 1; y < Column_Y - top[dst - 'A']; y++) {
        cct_showstr(down_end_X, y, " ", color, color, length);
        delay != 0 ? stop(delay) : Sleep(4);
        if (y < Column_Y - top[dst - 'A'] - 1) {
            cct_showch(down_end_X, y, ' ', COLOR_BLACK, COLOR_WHITE, length);
            if (y > 2)
                cct_showch(Column_X + (Column - 1) / 2 + (dst - 'A') * (Column + Interval), y, ' ', 14, 14, 1);
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
void input_initialize(char input[])
{
    for (int i = 0; i < 21; i++)
        input[i] = 0;
}

// �˵�ѡ��
void menu_one()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 1);
    stack_initialize(n, src, dst);
    hanoi(n, src, tmp, dst, 1);
    wait_for_enter();
}
void menu_two()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 2);
    stack_initialize(n, src, dst);
    hanoi(n, src, tmp, dst, 2);
    wait_for_enter();
}
void menu_three()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 3);
    stack_initialize(n, src, dst);
    hanoi(n, src, tmp, dst, 3);
    wait_for_enter();
}
void menu_four()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 4);
    stack_initialize(n, src, dst);
    longitudinal_initial(n, src, dst, 4,0);
    hanoi(n, src, tmp, dst, 4);
    wait_for_enter();
}
void menu_five()
{
    cct_cls();
    print_columns();
    cct_gotoxy(0, 37);
    wait_for_enter();
}
void menu_six()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 6);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
    print_columns();
    print_firstplate(n,src,dst);
    cct_gotoxy(0, 37);
    wait_for_enter();
}
void menu_seven()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 7);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
    print_columns();
    print_firstplate(n, src,dst);
    stack_initialize(n, src, dst);
    move(n, src, tmp, dst, 7);
    cct_gotoxy(0, 37);
    wait_for_enter();
}
void menu_eight()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 8);
    cct_cls();
    stack_initialize(n, src, dst);
    print_columns();
    print_firstplate(n, src,dst);
    longitudinal_initial(n, src, dst, 8, 15);
    hanoi(n, src, tmp, dst, 8);
    wait_for_enter();
}
void menu_nine()
{
    initialize();
    int n;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &n, &delay, 9);
    int dst_end = dst;
    cct_cls();
    stack_initialize(n, src, dst);
    print_columns();
    longitudinal_initial(n, src, dst, 9, 15);
    print_firstplate(n, src, dst);
    char _input[21] = { 0 };
    cct_gotoxy(0, Line_Y + 21);
    cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
    while (1) {
        input_initialize(_input);
        cct_showch(0, Line_Y + 23, ' ', COLOR_BLACK, COLOR_WHITE, 20);
        cct_showch(60, Line_Y + 21, ' ', COLOR_BLACK, COLOR_WHITE, 20);
        cct_gotoxy(60, Line_Y + 21);
        for (int i = 1; i < 22; i++) {
            if (i == 21) {
                input_initialize(_input);
                i = 1;
                cct_showch(60, Line_Y + 21, ' ', COLOR_BLACK, COLOR_WHITE, 20);
                cct_gotoxy(60, Line_Y + 21);
                continue;
            }
            _input[i] = _getch();
            if ((_input[i] >= 33 && _input[i] <= 126) || _input[i] == '\r') {
                cout << _input[i];
                if (_input[i] >= 'a' && _input[i] <= 'z')
                    _input[i] -= 32;
            }
            else {
                if (_input[i] != 32)
                    _getch();
                _input[i] = 0;
                i--;
            }
            if (_input[i] == '\r')
                break;
        }
        if (_input[1] == 'Q' && _input[2] == '\r') {
            cct_gotoxy(0, Line_Y + 23);
            cout << "��Ϸ��ֹ!!!";
            wait_for_enter();
        }
        if (_input[1] >= 'A' && _input[1] <= 'C' && _input[2] >= 'A' && _input[2] <= 'C' && _input[3] == '\r') {
            src = _input[1];
            dst = _input[2];
            if (top[dst - 'A'] > 0 && top[src - 'A'] >= 0 && (number[src - 'A'][top[src - 'A'] - 1] > number[dst - 'A'][top[dst - 'A'] - 1])
                ) {
                cct_gotoxy(0, Line_Y + 23);
                cout << "����ѹС��!!";
                while (_getch() != '\r');
                continue;
            }
            if (top[src - 'A'] == 0) {
                cct_gotoxy(0, Line_Y + 23);
                cout << "Դ��Ϊ��!!";
                while (_getch() != '\r');
                continue;
            }
            print(n, src, dst, 9);
            cct_gotoxy(0, Line_Y + 22);
            if (n > 0 && top[dst_end - 'A'] == n && number[dst_end - 'A'][top[dst_end - 'A'] - 1] == 1) {
                cct_gotoxy(0, Line_Y + 23);
                cout << "��Ϸ��������ϲ����ս�ɹ�" << endl;
                wait_for_enter();
            }
        }
        else
            continue;
    }
}
