/* 2251730 ��07 ������ */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- ���������κ���ʽ��ȫ�ֱ��� --- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����һ�ſε�ƽ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void average(int(*score)[STUDENT_NUM])
{
    double full_score = 0.0;
    int(*p_row)[STUDENT_NUM] = score, * p = p_row[0];
    for (p; p < p_row[0] + SCORE_NUM - 1; p++)
        full_score += *p;
    cout << "��1�ſε�ƽ���ɼ�Ϊ��" << full_score / STUDENT_NUM << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ҳ����������Ͽγ̲������ѧ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fail(int(*score)[STUDENT_NUM])
{
    double full_score_fail = 0.0;
    int flag_fail = 0, i = 0;
    int(*p_row)[STUDENT_NUM] = score, * p = *p_row;
    for (i = 0; i < STUDENT_NUM; i++) {
        full_score_fail = 0.0;
        flag_fail = 0;
        for (p_row = score; p_row < score + SCORE_NUM; p_row++) {
            p = *p_row + i;
            full_score_fail += *p;
            if (*p < 60)
                flag_fail += 1;
        }
        if (flag_fail >= 2) {
            cout << "No." << i + 1 << " ";
            for (p = score[0] + i; p < score[0] + i + SCORE_NUM * STUDENT_NUM; p += STUDENT_NUM)
                cout << *p << " ";
            cout << "ƽ����" << full_score_fail / SCORE_NUM << endl;
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ҳ�ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void good(int(*score)[STUDENT_NUM])
{
    double full_score_good = 0.0;
    int flag_good = 0, i = 0;
    int(*p_row)[STUDENT_NUM] = score, * p = *p_row;
    for (i = 0; i < STUDENT_NUM; i++) {
        full_score_good = 0.0;
        flag_good = 0;
        for (p_row = score; p_row < score + SCORE_NUM; p_row++) {
            p = *p_row + i;
            full_score_good += *p;
            if (*p >= 85)
                flag_good += 1;
        }
        if (full_score_good / SCORE_NUM >= 90 || flag_good == SCORE_NUM) {
            cout << "No." << i + 1 << " ";
            for (p = score[0] + i; p < score[0] + i + SCORE_NUM * STUDENT_NUM; p += STUDENT_NUM)
                cout << *p << " ";
            cout << "ƽ����" << full_score_good / SCORE_NUM << endl;
        }
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    int a[SCORE_NUM][STUDENT_NUM] = {
        {91,92,93,97},  //��1-4��ѧ���ĵ�1�ſγɼ�
        {81,82,83,85},  //��1-4��ѧ���ĵ�2�ſγɼ�
        {71,72,99,87},  //��1-4��ѧ���ĵ�3�ſγɼ�
        {61,32,80,91},  //��1-4��ѧ���ĵ�4�ſγɼ�
        {51,52,95,88} };//��1-4��ѧ���ĵ�5�ſγɼ�
    /* �������Ԥ�������⣬�������н������� 1����ָ����� + 1����ָ����� */

    int(*p_row)[STUDENT_NUM] = a, * p = a[0];
    cout << "��ʼ��Ϣ��" << endl;
    for (*p_row; p_row < a + SCORE_NUM; p_row++) {
        cout << "No.1-4ѧ���ĵ�" << p_row - a + 1 << "�ſγɼ���";
        for (p = *p_row; p < *p_row + STUDENT_NUM; p++) {
            cout << *p << " ";
        }
        cout << endl;
    }

    p_row = a;
    average(p_row);
    cout << "\n2�����ϲ������ѧ����\n";
    fail(p_row);
    cout << "\nƽ��90���ϻ�ȫ��85���ϵ�ѧ����\n";
    good(p_row);

    return 0;
}
