/* 2251730 信07 刘淑仪 */
#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;
int a1[3];
int a2[3][10];
int cnt = 1;

void choose(int n, char src, char tmp, char dst)
{
    int j, i;
    if (src == 'A') {
        a1[0] = n;
        cout << "A:";
        for (i = 0; i < n; i++) {
            a2[0][i] = n - i;
            cout << setw(2) << a2[0][i];
        }
        for (j = 0; j < 2 * (N - i) + 1; j++)
            cout << " ";
        cout << "B:                     C:                    " << endl;
    }
    else if (src == 'B') {
        a1[1] = n;
        cout << "A:                     B:";
        for (i = 0; i < n; i++) {
            a2[1][i] = n - i;
            cout << setw(2) << a2[1][i];
        }
        for (j = 0; j < 2 * (N - i) + 1; j++)
            cout << " ";
        cout << "C:                    " << endl;
    }
    else if (src == 'C') {
        a1[2] = n;
        cout << "A:                     B:                     C:";
        for (i = 0; i < n; i++) {
            a2[2][i] = n - i;
            cout << setw(2) << a2[2][i];
        }
        for (j = 0; j < 2 * (N - i) + 1; j++)
            cout << " ";
        cout << endl;
    }
}

void print(int n, int a1[])
{
    int i, j;
    cout << "A:";
    for (i = 0; i < a1[0]; i++) {
        if (a2[0][i] > 0)
            cout << setw(2) << a2[0][i];
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";

    cout << "B:";
    for (i = 0; i < a1[1]; i++) {
        if (a2[1][i] > 0)
            cout << setw(2) << a2[1][i];
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";

    cout << "C:";
    for (i = 0; i < a1[2]; i++) {
        if (a2[2][i] > 0)
            cout << setw(2) << a2[2][i];
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        cout << " ";
    cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    cout << "第" << setw(4) << setiosflags(ios::right) << cnt << " 步";
    cout << "(" << setw(2) << setiosflags(ios::right) << n << "):" << " " << src << "-->" << dst << " ";
    ++cnt;
    if (src == 'A')
        a2[0][--a1[0]] = 0;
    else if (src == 'B')
        a2[1][--a1[1]] = 0;
    else
        a2[2][--a1[2]] = 0;

    if (dst == 'A')
        a2[0][a1[0]++] = n;
    else if (dst == 'B')
        a2[1][a1[1]++] = n;
    else
        a2[2][a1[2]++] = n;

    print(n, a1);
    hanoi(n - 1, tmp, src, dst);
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

    cout<<"初始:                ";
    choose(n, src, tmp, dst);
    hanoi(n, src, tmp, dst);

    return 0;
}
