/* 2251730 ��07 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */
int count = 1;

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
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    printf("%5d: ", count);
    printf("%2d# %c-->%c\n", n, src, dst);
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
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        int ret1 = scanf("%d", &n);
        if (ret1 == 1) {
            if (n >= 1 && n <= 16)
                break;
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }
    while (getchar() != '\n')
        ;
    while (1) {
        printf("��������ʼ��(A-C)\n");
        int ret2 = scanf("%c", &src);
        if (ret2 == 1) {
            if (src > 68)
                src -= 32;
            if (src == 65 || src == 66 || src == 67)
                break;
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }
    while (getchar() != '\n')
        ;

    while (1) {
        printf("������Ŀ����(A-C)\n");
        int ret3 = scanf("%c", &dst);
        if (ret3 == 1) {
            if (dst > 68)
                dst -= 32;
            if (src > 68)
                src -= 32;
            if (dst == src) {
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
                while (getchar() != '\n')
                    ;
            }
            else {
                if (dst == 65 || dst == 66 || dst == 67)
                    break;
                else {
                    while (getchar() != '\n')
                        ;
                }
            }
        }
        else {
            while (getchar() != '\n')
                ;
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

    printf("�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}