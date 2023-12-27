/* 2251730 信07 刘淑仪 */
/* 本cpp用于存放输入、调用菜单 */
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "popstar.h"
using namespace std;

int menu_and_choose()
{
    //初始化菜单界面
    cout << "--------------------------------------------" << endl;
    cout << "A.命令行找出可消除项并标识" << endl;
    cout << "B.命令行完成一次消除（分步骤显示）" << endl;
    cout << "C.命令行完成一关（分步骤显示）" << endl;
    cout << "D.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl;
    cout << "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl;
    cout << "F.伪图形界面完成一次消除（分步骤）" << endl;
    cout << "G.伪图形界面完整版" << endl;
    cout << "Q.退出" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "[请选择:]";
    //输入选择内容
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
