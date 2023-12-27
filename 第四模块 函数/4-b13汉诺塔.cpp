/* 2251730 ��07 ������ */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int count = 1;
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    cout << setw(5) << setiosflags(ios::right) << count << ": ";
    cout << setw(2) << setiosflags(ios::right) << n << "#" << " " << src << "-->" << dst << endl;
    ++count;
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else {
            if (n >= 1 && n <= 16)
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
        cout << "������Ŀ����(A-C)" << endl;
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
                cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
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

    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;
}
