/*2251730 ��07 ������*/

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
    1����main����
    2����ʼ����Ļ
    3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
    4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
    1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
    2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
    3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

int main()
{
    /* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
    cct_setconsoleborder(120, 40, 120, 9000);
    int choose = menu_and_choose();
    switch (choose) {
    case 0:
        break;
    case 1:
        menu_one();
        break;
    case 2:
        menu_two();
        break;
    case 3:
        menu_three();
        break;
    case 4:
        menu_four();
        break;
    case 5:
        menu_five();
        break;
    case 6:
        menu_six();
        break;
    case 7:
        menu_seven();
        break;
    case 8:
        menu_eight();
        break;
    case 9:
        menu_nine();
        break;
    }

    return 0;
}
