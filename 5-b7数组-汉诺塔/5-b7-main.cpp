/* 2251730 信07 刘淑仪 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include"5-b7.h"
using namespace std;

#define N 10
int cnt = 1;
int top1 = 0, top2 = 0, top3 = 0;
int A[N] = { 0 }, B[N] = { 0 }, C[N] = { 0 };
static int delay = 0;
static bool interior = 0;

void stop(int delay, int interior)
{
    if (delay != 0)
        Sleep((5 - delay) * 200);
    else {
        while (getchar() != '\n')
            ;
    }
}

void choose(int n, char src, char tmp, char dst, int delay)//选择及初始化
{
    cct_gotoxy(28, 17);
    if (src == 'A') {
        top1 = n;
        cout << "A:";
        for (int i = 0; i < n; i++) {
            cct_gotoxy(30 + 2 * i, 17);
            A[i] = n - i;
            cout << setw(2) << A[i];
            cct_gotoxy(8, 13 - i);
            cout << setw(2) << setiosflags(ios::right) << A[i];
        }
        cct_gotoxy(51, 17);
        cout << "B:                     C:                    " << endl;
    }
    else if (src == 'B') {
        top2 = n;
        cout << "A:                     B:";
        for (int i = 0; i < n; i++) {
            cct_gotoxy(53 + 2 * i, 17);
            B[i] = n - i;
            cout << setw(2) << B[i];
            cct_gotoxy(18, 13 - i);
            cout << setw(2) << setiosflags(ios::right) << B[i];
        }
        cct_gotoxy(74, 17);
        cout << "C:                   " << endl;
    }
    else if (src == 'C') {
        top3 = n;
        cout << "A:                     B:                     C:";
        for (int i = 0; i < n; i++) {
            cct_gotoxy(76 + 2 * i, 17);
            C[i] = n - i;
            cout << setw(2) << C[i];
            cct_gotoxy(28, 13 - i);
            cout << setw(2) << setiosflags(ios::right) << C[i];
        }
        cout << endl;
    }

    stop(delay, interior);

}

void print(int n, int top1, int top2, int top3)
{
    int i, j;
    cct_gotoxy(28, 17);
    cout << "A:";
    for (i = 0; i < top1; i++) {
        if (A[i] > 0) {
            cct_gotoxy(30 + 2 * i, 17);
            cout << setw(2) << A[i];
        }
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";

    cout << "B:";
    for (i = 0; i < top2; i++) {
        if (B[i] > 0) {
            cct_gotoxy(53 + 2 * i, 17);
            cout << setw(2) << B[i];
        }
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";

    cout << "C:";
    for (i = 0; i < top3; i++) {
        if (C[i] > 0) {
            cct_gotoxy(76 + 2 * i, 17);
            cout << setw(2) << C[i];
        }

    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";
    cout << endl;

}

void hanoi(int n, char src, char tmp, char dst, bool interior, int delay)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp, interior, delay);
    cct_gotoxy(7, 17);
    cout << "第" << setw(4) << setiosflags(ios::right) << cnt << " 步";
    cout << "(" << setw(2) << setiosflags(ios::right) << n << "):" << " " << src << "-->" << dst << " ";

    stop(delay, interior);

    if (src == 'A') {
        A[--top1] = 0;
        cct_gotoxy(8, 13 - top1);
        cout << "  ";
        stop(delay, interior);
    }
    else if (src == 'B') {
        B[--top2] = 0;
        cct_gotoxy(18, 13 - top2);
        cout << "  ";
        stop(delay, interior);
    }
    else {
        C[--top3] = 0;
        cct_gotoxy(28, 13 - top3);
        cout << "  ";
        stop(delay, interior);
    }//起始

    if (dst == 'A') {
        A[top1++] = n;
        cct_gotoxy(8, 14 - top1);
        cout << setw(2) << setiosflags(ios::right) << n;
        stop(delay, interior);
    }
    else if (dst == 'B') {
        B[top2++] = n;
        cct_gotoxy(18, 14 - top2);
        cout << setw(2) << setiosflags(ios::right) << n;
        stop(delay, interior);
    }
    else {
        C[top3++] = n;
        cct_gotoxy(28, 14 - top3);
        cout << setw(2) << setiosflags(ios::right) << n;
        stop(delay, interior);
    }//终止
    cct_gotoxy(26, 17);
    if (interior == 1)
        print(n, top1, top2, top3);
    else
        ;
    ++cnt;
    hanoi(n - 1, tmp, src, dst, interior, delay);
}

int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (n >= 1 && n <= 10)
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
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (src > 68)
                src -= 32;
            if (src == 65 || src == 66 || src == 67)
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
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (dst > 68)
                dst -= 32;
            if (src > 68)
                src -= 32;
            if (dst == src) {
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else {
                if (dst == 65 || dst == 66 || dst == 67)
                    break;
                else {
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
            }
        }
    }

    if (src == 'A' || src == 'a') {
        src = 'A';
        if (dst == 'B' || dst == 'b') {
            tmp = 'C';
            dst = 'B';
        }
        else {
            tmp = 'B';
            dst = 'C';
        }
    }
    else if (src == 'B' || src == 'b') {
        src = 'B';
        if (dst == 'A' || dst == 'a') {
            tmp = 'C';
            dst = 'A';
        }
        else {
            tmp = 'A';
            dst = 'C';
        }
    }
    else {
        src = 'C';
        if (dst == 'A' || dst == 'a') {
            tmp = 'B';
            dst = 'A';
        }
        else {
            tmp = 'A';
            dst = 'B';
        }
    }

    cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> delay;
    cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    cin >> interior;
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << " ，共 " << n << " 层，延时设置为 " << delay << "，";
    if (interior == 1)
        cout << "显示内部数组值" << endl;
    else
        cout << "不显示内部数组值" << endl;
    stop(delay, interior);
    cct_gotoxy(7, 17);
    cout << "初始:                ";
    stop(delay, interior);
    cct_gotoxy(7, 14);
    cout << "=========================" << endl;
    cout << "         A         B         C" << endl;
    stop(delay, interior);
    choose(n, src, tmp, dst, delay);

    hanoi(n, src, tmp, dst, interior, delay);

    cct_gotoxy(7, 20);
    system("pause");
    return 0;
}