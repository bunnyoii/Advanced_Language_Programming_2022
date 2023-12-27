/* 2251730 ��07 ������ */
/* ��cpp���ڴ�Ź��ú���������� */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include "popstar.h"
#include "cmd_console_tools.h"
using namespace std;
//��������
void input(int* line, int* column)
{
    while (1) {
        cout << "������������8-10��" << endl;
        cin >> *line;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (*line >= 8 && *line <= 10)
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
        cout << "������������8-10��" << endl;
        cin >> *column;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (*column >= 8 && *column <= 10)
                break;
            else {
                cin.clear();
                cin.ignore(65536, '\n');
            }
        }
    }
    cin.clear();
    cin.ignore(65536, '\n');
    cout << endl;
}
//ѡ������
void select(int line, int column, char coordinate[], char* line_choose, char* column_choose, int chessboard[][12])
{
    int x, y;
    while (1) {
        cout << endl;
        cout << "������ĸ+��ѧ��ʽ[����c2]����������꣺";
        cct_getxy(x, y);
        for (int i = 0; i < 21; i++)
            coordinate[i] = 0;
        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
        cct_gotoxy(x, y);
        for (int i = 1; i < 22; i++) {
            if (i == 21) {
                for (int i = 0; i < 21; i++)
                    coordinate[i] = 0;
                i = 1;
                cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
                cct_gotoxy(0, y + 1);
                cout << "�����������������";
                cct_gotoxy(x, y);
                continue;
            }
            coordinate[i] = _getch();
            if ((coordinate[i] >= 33 && coordinate[i] <= 126) || coordinate[i] == '\r') {
                cout << coordinate[i];
                if (coordinate[i] >= 'a' && coordinate[i] <= 'z')
                    coordinate[i] -= 32;
            }
            else {
                if (coordinate[i] != 32)
                    char sb = _getch();
                coordinate[i] = 0;
                i--;
            }
            if (coordinate[i] == '\r')
                break;
        }//end of for;
        if (coordinate[1] >= 'A' && coordinate[1] < 'A' + line && coordinate[2] >= '0' && coordinate[2] < column + '0' && coordinate[3] == '\r') {
            *line_choose = coordinate[1];
            *column_choose = coordinate[2];
            cout << endl;
            cout << "����Ϊ" << *line_choose << "��" << *column_choose << "��        ";
            cout << endl;
            if (judge_the_choice(*line_choose, *column_choose, chessboard)) {
                if (*column_choose < 'A') {
                    if (chessboard[*line_choose - 'A' + 1][*column_choose - '0' + 1] == 0)
                        cout << "����ľ�������λ��Ϊ0���Ƿ�λ�ã�������������";
                    else
                        break;
                }
            }
            else
                cout << "����ľ�������λ�ô���������ֵͬ������������";
            continue;
        }
        else {
            cout << endl << "�����������������";
            continue;
        }//end of if;
    }//end of while(1);
}
//�ж������Ƿ�����ͬ���������Ƿ�Ϸ���
bool judge_the_choice(char line_choose, char column_choose, int chessboard[][12])
{
    if (chessboard[line_choose - 'A' + 1][column_choose - '0' + 1] != chessboard[line_choose - 'A' + 2][column_choose - '0' + 1] &&
        chessboard[line_choose - 'A' + 1][column_choose - '0' + 1] != chessboard[line_choose - 'A'][column_choose - '0' + 1] &&
        chessboard[line_choose - 'A' + 1][column_choose - '0' + 1] != chessboard[line_choose - 'A' + 1][column_choose - '0' + 2] &&
        chessboard[line_choose - 'A' + 1][column_choose - '0' + 1] != chessboard[line_choose - 'A' + 1][column_choose - '0'])
        return 0;
    else
        return 1;
    //0����Χû����ֵͬ
    //1����Χ����ֵͬ
}
//Ѱ�����̳�ʼ��
void chessboard_search_initialize(char chessboard_search_[][12])
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            chessboard_search_[i][j] = '0';
}
//ȷ���Ƿ�����
char eliminate(char line_choose, char column_choose)
{
    int x, y;
    char eliminate_or_not;
    cout << "��ȷ���Ƿ��" << line_choose << column_choose << "��Χ����ֵͬ����(Y/N/Q)��";
    cct_getxy(x, y);
    while (1) {
        eliminate_or_not = _getch();
        cout << eliminate_or_not;
        if (eliminate_or_not >= 'a' && eliminate_or_not <= 'z')
            eliminate_or_not -= 32;
        if (eliminate_or_not == 'Y' || eliminate_or_not == 'N' || eliminate_or_not == 'Q')
            break;
        else
            cct_gotoxy(x, y);
    }
    return eliminate_or_not;
}
//����end���ز˵�
void wait_for_end(void)
{
    int x, y;
    char end[4];
    cout << endl << "��С�����������End����...";
    cct_getxy(x, y);
    while (1) {
        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 4);
        cct_gotoxy(x, y);
        for (int i = 1; i < 5; i++) {
            end[i] = _getch();
            if ((end[i] >= 33 && end[i] <= 126) || end[i] == '\r') {
                cout << end[i];
                if (end[i] >= 'a' && end[i] <= 'z')
                    end[i] -= 32;
            }
            else {
                if (end[i] != 32)
                    char sb = _getch();
                end[i] = 0;
                i--;
            }
            if (end[i] == '\r')
                break;
        }
        if (end[1] == 'E' && end[2] == 'N' && end[3] == 'D')
            break;
        else
            continue;
    }
    cct_cls();
    main();
}
//�÷�
int grade(char chessboard_search_[][12])
{
    int cnt = 0;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            if (chessboard_search_[i][j] == '*')
                cnt++;
    if (cnt != 0)
        return cnt * 10;
    else
        return 0;
}
//�س�����
void enter_for_sth(int choose)
{
    if (choose == 0)
        cout << endl << "���س���������������Ĳ���";
    else if (choose == 1)
        cout << endl << "�����������������س���������һ�ε�����...";
    while (_getch() != '\r');
    cout << endl;
}
//ͳ�Ʋ���������
int non_eliminable(int line, int column, int chessboard[][12])
{
    int non_eliminable_num = 0;
    for (int i = 1; i < line + 1; i++)
        for (int j = 1; j < column + 1; j++) {
            if (chessboard[i][j] != 0)
                non_eliminable_num++;
        }
    return non_eliminable_num;
}
//�ж���Ϸ�Ƿ����
int game_over(int line, int column, int chessboard[][12])
{
    for (int i = 1; i < line + 1; i++) {
        for (int j = 1; j < column + 1; j++) {
            if (chessboard[i][j] != 0) {
                if (judge_the_choice(i + 'A' - 1, j + '0' - 1, chessboard))
                    return 1;
            }
        }
    }
    return 0;
}
//�����÷�
int reward(int line, int column, int chessboard[][12])
{
    int num = 0;
    for(int i=1;i< line + 1;i++)
        for (int j = 1; j < column + 1; j++) {
            if (chessboard[i][j] != 0)
                num += 1;
        }
    if (num >= 10)
        return 0;
    else
        return (10 - num) * 20;
}
//�˵�ѡ��
void menu_A(void)
{
    char line_choose = '0', column_choose = '0';
    int line, column;
    int chessboard[12][12] = { 0 };
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    chessboard_search_initialize(chessboard_search_);
    input(&line, &column);
    chessboard_generate(line, column, chessboard);
    print_chessboard(line, column, chessboard, 1, line_choose, column_choose, chessboard_search_);
    select(line, column, coordinate, &line_choose, &column_choose, chessboard);
    print_chessboard(line, column, chessboard, 2, line_choose, column_choose, chessboard_search_);
    print_chessboard(line, column, chessboard, 3, line_choose, column_choose, chessboard_search_);
    wait_for_end();
}
void menu_B(void)
{
    char line_choose = '0', column_choose = '0';
    int line, column;
    int chessboard[12][12] = { 0 };
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    int grade_all = 0;
    char eliminate_or_not;
    chessboard_search_initialize(chessboard_search_);
    input(&line, &column);
    chessboard_generate(line, column, chessboard);
    print_chessboard(line, column, chessboard, 1, line_choose, column_choose, chessboard_search_);
    select(line, column, coordinate, &line_choose, &column_choose, chessboard);
    print_chessboard(line, column, chessboard, 2, line_choose, column_choose, chessboard_search_);
    print_chessboard(line, column, chessboard, 3, line_choose, column_choose, chessboard_search_);
    eliminate_or_not = eliminate(line_choose, column_choose);
    if (eliminate_or_not == 'Q')
        wait_for_end();
    else if (eliminate_or_not == 'N')
        wait_for_end();
    cout << endl;
    print_chessboard(line, column, chessboard, 4, line_choose, column_choose, chessboard_search_);
    cout << "���ε÷֣�" << grade(chessboard_search_) << " �ܵ÷֣�" << grade(chessboard_search_) << endl;
    enter_for_sth(0);
    print_chessboard(line, column, chessboard, 5, line_choose, column_choose, chessboard_search_);
    wait_for_end();
}
void menu_C(void)
{
    char line_choose = '0', column_choose = '0';
    int line, column, non_eliminable_num = 0;
    int chessboard[12][12] = { 0 };
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    int grade_all = 0, grade_once = 0;
    input(&line, &column);
    chessboard_generate(line, column, chessboard);
    char eliminate_or_not;
    while (1) {
        chessboard_search_initialize(chessboard_search_);
        print_chessboard(line, column, chessboard, 1, line_choose, column_choose, chessboard_search_);
        if (!game_over(line, column, chessboard)) {
            cout << endl << "ʣ��" << non_eliminable(line, column, chessboard) << "��������������ؽ���!" << endl;
            break;
        }
        select(line, column, coordinate, &line_choose, &column_choose, chessboard);
        print_chessboard(line, column, chessboard, 2, line_choose, column_choose, chessboard_search_);
        print_chessboard(line, column, chessboard, 3, line_choose, column_choose, chessboard_search_);
        eliminate_or_not = eliminate(line_choose, column_choose);
        if (eliminate_or_not == 'Q')
            wait_for_end();
        else if (eliminate_or_not == 'N') {
            cout << endl;
            continue;
        }
        print_chessboard(line, column, chessboard, 4, line_choose, column_choose, chessboard_search_);
        grade_once = grade(chessboard_search_);
        grade_all = grade_all + grade_once;
        cout << "���ε÷֣�" << grade_once << " �ܵ÷֣�" << grade_all << endl;
        enter_for_sth(0);
        print_chessboard(line, column, chessboard, 5, line_choose, column_choose, chessboard_search_);
        enter_for_sth(1);
    }
    wait_for_end();
}
void menu_D(void)
{
    int x = PATCHES_STA_X, y = PATCHES_STA_Y;
    cct_setcursor(CURSOR_INVISIBLE);
    int line, column;
    int chessboard[12][12] = { 0 };
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    char line_choose = '0', column_choose = '0';
    chessboard_search_initialize(chessboard_search_);
    input(&line, &column);
    chessboard_generate(line, column, chessboard);
    cct_setconsoleborder(SCREEN_COLUMN - 6 * (10 - column) + 3, SCREEN_LINE - 3 * (10 - line) + 3, SCREEN_COLUMN - 6 * (10 - column) + 3, SCREEN_LINE - 3 * (10 - line) + 2);
    blank_3(line, column);
    cct_gotoxy(0, 0);
    cout << "��Ļ��ǰ����Ϊ��" << SCREEN_LINE - 3 * (10 - line) << "��" << SCREEN_COLUMN - 6 * (10 - column) << "��" << endl;
    color_patches(line, column, chessboard, 0);
    cct_gotoxy(0, 3 * (line + 1) + 1);
    cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���";
    cct_enable_mouse();
    mouse_or_keycode_color(&x,&y,line, column, chessboard, 0, 'D', &line_choose, &column_choose);
    wait_for_end();
}
void menu_E(void)
{
    int x = PATCHES_STA_X, y = PATCHES_STA_Y;
    cct_setcursor(CURSOR_INVISIBLE);
    int line, column;
    int chessboard[12][12] = { 0 };
    char line_choose = '0', column_choose = '0';
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    chessboard_search_initialize(chessboard_search_);
    input(&line, &column);
    chessboard_generate(line, column, chessboard);
    cct_setconsoleborder(SCREEN_COLUMN - 8 * (10 - column) + 20, SCREEN_LINE - 4 * (10 - line) + 10, SCREEN_COLUMN - 8 * (10 - column) + 20, SCREEN_LINE - 4 * (10 - line) + 10);
    blank_4(line, column);
    cct_gotoxy(0, 0);
    cout << "��Ļ��ǰ����Ϊ��" << SCREEN_LINE - 4 * (10 - line) + 9 << "��" << SCREEN_COLUMN - 8 * (10 - column) + 18 << "��" << endl;
    color_patches(line, column, chessboard, 1);
    cct_gotoxy(0, 4 * (line + 1));
    cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���";
    cct_enable_mouse();
    mouse_or_keycode_color(&x,&y,line, column, chessboard, 1, 'E', &line_choose, &column_choose);
    wait_for_end();
}
void menu_F(void)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int _ret = 0;
    int x = PATCHES_STA_X, y = PATCHES_STA_Y;
    char line_choose = '0', column_choose = '0';
    int line, column, non_eliminable_num = 0;
    int chessboard[12][12] = { 0 };
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    int grade_all = 0, grade_once = 0;
    chessboard_search_initialize(chessboard_search_);
    input(&line, &column);
    chessboard_generate(line, column, chessboard);
    cct_setconsoleborder(SCREEN_COLUMN - 6 * (10 - column) + 3, SCREEN_LINE - 3 * (10 - line) + 3, SCREEN_COLUMN - 6 * (10 - column) + 3, SCREEN_LINE - 3 * (10 - line) + 2);
    blank_3(line, column);
    cct_gotoxy(0, 0);
    cout << "��Ļ��ǰ����Ϊ��" << SCREEN_LINE - 3 * (10 - line) << "��" << SCREEN_COLUMN - 6 * (10 - column) << "��" << endl;
    color_patches(line, column, chessboard, 0);
    cct_gotoxy(0, 3 * (line + 1) + 1);
    cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���";
    cout << endl;
    cct_enable_mouse();
    while (1) {
        chessboard_search_initialize(chessboard_search_);
        if (!game_over(line, column, chessboard)) {
            cct_setcolor(0, COLOR_HYELLOW);
            cout << endl << "ʣ��" << non_eliminable(line, column, chessboard) << "��������������ؽ���!" << endl;
            break;
        }
        mouse_or_keycode_color( &x,&y,line, column, chessboard, 0, 'F',&line_choose, &column_choose);
        //��chessboard_search == '*'�ĵط�����
        chessboard_search(line_choose, column_choose, chessboard, chessboard_search_);
        for (int i = 1; i < line + 1; i++) {
            for (int j = 1; j < column + 1; j++) {
                if (chessboard_search_[i][j] == '*') {
                    color_patches_opposite(6 * j - 2, i * 3, chessboard, 0,line_choose, column_choose );
                }
            }
        }
        if (!judge_the_choice(line_choose, column_choose, chessboard)) {
            cct_showstr(0, 3 * (line + 1) + 1, "��Χ����ֵͬ,", 0, COLOR_HYELLOW, 1);
            cct_setcolor();
            cout << "��ͷ��/����ƶ����س���/�������ѡ��Q/�����Ҽ�����";
            _ret = eliminate_confirm(0, column, line, &x, &y, chessboard, chessboard_search_);
            if (_ret == 1)
                continue;
        }
        else {
            cct_gotoxy(0, 3 * (line + 1) + 1);
            cct_setcolor();
            cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
            _ret = eliminate_confirm(0, column, line, &x, &y, chessboard, chessboard_search_);
            if (_ret == 1) {
                continue;
            }
            else if (_ret == 2) {
                eliminate_patches(line, column, chessboard_search_, chessboard, 0);
                cct_showstr(0, 3 * (line + 1) + 1, " ", 0, 0, 50);
                cct_showstr(0, 3 * (line + 1) + 1, "�ϳ���ɣ��س���/�����������0", 0, 7, 1);
                while (1) {
                    _ret = eliminate_confirm(0, column, line, &x, &y, chessboard, chessboard_search_);
                    if (_ret == 2 || _ret == 3) {
                        down_patches_color(line, column, chessboard, chessboard_search_, 0);
                        left_patches_color(line, column, chessboard, chessboard_search_, 0);
                        break;
                    }
                }
            }
        }
        cct_showstr(0, 3 * (line + 1) + 1, " ", 0, 0, 50);
        cct_showstr(0, 3 * (line + 1) + 1, "���κϳɽ�������C/�������������һ�εĺϳ�", 0, COLOR_HYELLOW, 1);
        int ret, X, Y, maction, keycode1, keycode2;
        bool loop = 1;
        while (loop) {
            ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
            if (ret == CCT_MOUSE_EVENT) {
                switch (maction) {
                case MOUSE_LEFT_BUTTON_CLICK:
                    loop = 0;
                    break;
                default:
                    break;
                }
            }
            else if (ret == CCT_KEYBOARD_EVENT) {
                switch (maction) {
                case 'C':
                case 'c':
                    loop = 0;
                    break;
                default:
                    break;
                }
            }
        }
        wait_for_end();
    }
}
void menu_G(void)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int _ret = 0;
    int x = PATCHES_STA_X, y = PATCHES_STA_Y;
    char line_choose = '0', column_choose = '0';
    int line, column, non_eliminable_num = 0;
    int chessboard[12][12] = { 0 };
    char chessboard_search_[12][12] = { '0' };
    char coordinate[21] = { ' ' };
    int grade_all = 0, grade_once = 0;
    chessboard_search_initialize(chessboard_search_);
    input(&line, &column);
    while(1){
        chessboard_generate(line, column, chessboard);
        cct_setconsoleborder(SCREEN_COLUMN - 8 * (10 - column) + 20, SCREEN_LINE - 4 * (10 - line) + 10, SCREEN_COLUMN - 8 * (10 - column) + 20, SCREEN_LINE - 4 * (10 - line) + 10);
        blank_4(line, column);
        cct_gotoxy(0, 0);
        cout << "��Ļ��ǰ����Ϊ��" << SCREEN_LINE - 4 * (10 - line) + 9 << "��" << SCREEN_COLUMN - 8 * (10 - column) + 18 << "��" << endl;
        color_patches(line, column, chessboard, 1);
        cct_gotoxy(0, 4 * (line + 1));
        cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���";
        cout << endl;
        cct_enable_mouse();
        while (1) {
            chessboard_search_initialize(chessboard_search_);
            if (!game_over(line, column, chessboard)) {
                cct_setcolor();
                cct_gotoxy(0, 4 * (line + 1));
                cout << endl << "ʣ��" << non_eliminable(line, column, chessboard) << "��������������ؽ���!";
                cct_gotoxy(0, 0);
                cct_setcolor(0, 9);
                grade_all += reward(line, column, chessboard);
                cout << " �ܵ÷֣�" << grade_all << "�����к������÷�" << reward(line, column, chessboard) << endl;
                break;
            }
            mouse_or_keycode_color(&x, &y, line, column, chessboard, 1, 'F', &line_choose, &column_choose);
            /* ��chessboard_search == '*'�ĵط����� */
            //Ѱ����Χ�Ƿ�����ֵͬ
            chessboard_search(line_choose, column_choose, chessboard, chessboard_search_);
            for (int i = 1; i < line + 1; i++) {
                for (int j = 1; j < column + 1; j++) {
                    if (chessboard_search_[i][j] == '*') {
                            color_patches_opposite(8 * j - 2, i * 4, chessboard, 1, line_choose, column_choose);
                    }
                }
            }
            if (!judge_the_choice(line_choose, column_choose, chessboard)) {
                cct_showstr(0, 4 * (line + 1), "��Χ����ֵͬ,", 0, COLOR_HYELLOW, 1);
                cct_setcolor();
                cout << "��ͷ��/����ƶ����س���/�������ѡ��Q/�����Ҽ�����";
                while (_ret = eliminate_confirm(1, column, line, &x, &y, chessboard, chessboard_search_) != 1)
                    continue;
                continue;
            }
            else {
                cct_gotoxy(0, 4 * (line + 1));
                cct_setcolor();
                cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�,Q/q�˳���Ϸ     ";
                _ret = eliminate_confirm(1, column, line, &x, &y, chessboard, chessboard_search_);
                if (_ret == 1)
                    continue;
                else if (_ret == 2 || _ret == 3) {
                    eliminate_patches(line, column, chessboard_search_, chessboard, 1);
                    Sleep(PATCHES_SLEEP);
                    down_patches_color(line, column, chessboard, chessboard_search_, 1);
                    left_patches_color(line, column, chessboard, chessboard_search_, 1);
                    if (_ret == 3 || !(legitimate_or_not(1, column, line, x, y, chessboard))) {
                        bool end = 1;
                        for (int j = 1; j < column + 1; j++) {
                            for (int i = 1; i < line + 1; i++)
                                if (chessboard[i][j] != 0 && chessboard[i - 1][j] == 0) {
                                    x = j * 8 - 4;
                                    y = i * 4;
                                    end = 0;
                                    break;
                                }
                            if (end == 0)
                                break;
                        }
                        color_patches_opposite(x, y, chessboard, 1);
                    }
                }
            }
            grade_once = grade(chessboard_search_);
            grade_all += grade_once;
            cct_gotoxy(0, 0);
            cct_setcolor();
            cout << "���ε÷֣�" << grade_once << " �ܵ÷֣�" << grade_all << "    "<<endl;
        }
        cct_setcolor();
        cct_gotoxy(0, 4 * (line + 1) + 2);
        cout << "�س�������һ��...";
        while (_getch() != '\r');
    }
}