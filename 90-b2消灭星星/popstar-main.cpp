/* 2251730 ��07 ������ */
/* ��cpp���ڴ�����롢���ò˵� */
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "popstar.h"
using namespace std;

int menu_and_choose()
{
    //��ʼ���˵�����
    cout << "--------------------------------------------" << endl;
    cout << "A.�������ҳ����������ʶ" << endl;
    cout << "B.���������һ���������ֲ�����ʾ��" << endl;
    cout << "C.���������һ�أ��ֲ�����ʾ��" << endl;
    cout << "D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�" << endl;
    cout << "E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�" << endl;
    cout << "F.αͼ�ν������һ���������ֲ��裩" << endl;
    cout << "G.αͼ�ν���������" << endl;
    cout << "Q.�˳�" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "[��ѡ��:]";
    //����ѡ������
    char choose;
    while (1) {
        choose = _getch();
        if (choose >= 'A' && choose <= 'G' || choose=='Q') {
            cout << choose << endl;
            Sleep(300);
            break;
        }
        else if (choose >= 'a' && choose <= 'g' || choose == 'q') {
            cout << choose << endl;
            Sleep(300);
            break;
        }
        else {
            _getch();
            continue;
        }
    }
    return choose;
}

int main()
{
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setconsoleborder(67, 38, 67, 38);
    int choose = menu_and_choose();
    switch (choose) {
    case 'q':
    case 'Q':
        break;
    case 'A':
    case 'a':
        cct_cls();
        menu_A();
        break;
    case 'B':
    case 'b':
        cct_cls();
        menu_B();
        break;
    case 'C':
    case 'c':
        cct_cls();
        menu_C();
        break;
    case 'D':
    case 'd':
        cct_cls();
        menu_D();
        break;
    case 'E':
    case 'e':
        cct_cls();
        menu_E();
        break;
    case 'F':
    case 'f':
        cct_cls();
        menu_F();
        break;
    case 'G':
    case 'g':
        cct_cls();
        menu_G();
        break;
    default:
        break;
    }
    return 0;
}
