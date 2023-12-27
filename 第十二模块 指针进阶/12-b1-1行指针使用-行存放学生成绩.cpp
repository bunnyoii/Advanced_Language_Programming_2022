/* 2251730 ��07 ������ */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- ���������κ���ʽ��ȫ�ֱ��� --- */

/***************************************************************************
  �������ƣ�average
  ��    �ܣ����һ�ſε�ƽ����
  ���������int(*score)[SCORE_NUM]
  �� �� ֵ��
  ˵    ���������������ں����м���
***************************************************************************/
void average(int(*score)[SCORE_NUM])
{
    double full_score = 0.0;
    for (int(*p)[SCORE_NUM] = score; p < score + STUDENT_NUM; p++)
        full_score += **p;
    cout << "��1�ſε�ƽ���ɼ�Ϊ��" << full_score / STUDENT_NUM << endl;
}

/***************************************************************************
  �������ƣ�fail
  ��    �ܣ��ҳ����������Ͽγ̲������ѧ��
  ���������int(*score)[SCORE_NUM]
  �� �� ֵ��
  ˵    ���������������ں����м���
***************************************************************************/
void fail(int(*score)[SCORE_NUM])
{
    double full_score_fail = 0.0;
    int flag_fail = 0;
    int(*p_row)[SCORE_NUM] = score, * p = score[0];
    for (*p_row; p_row < score + STUDENT_NUM; p_row++) {
        flag_fail = 0;
        full_score_fail = 0.0;
        for (p = *p_row; p < *p_row + SCORE_NUM; p++) {
            full_score_fail += *p;
            if (*p < 60)
                flag_fail += 1;
        }
        if (flag_fail >= 2) {
            cout << "No." << p_row - score + 1 << " ";
            for (p = *p_row; p < *p_row + SCORE_NUM; p++) {
                cout << *p << " ";
            }
            cout << "ƽ����" << full_score_fail / SCORE_NUM << endl;
        }
    }
}

/***************************************************************************
  �������ƣ�good
  ��    �ܣ��ҳ�ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ��
  ���������int(*score)[SCORE_NUM]
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void good(int(*score)[SCORE_NUM])
{
    double full_score_good = 0.0;
    int flag_good = 0;
    int(*p_row)[SCORE_NUM] = score, * p = score[0];
    for (*p_row; p_row < score + STUDENT_NUM; p_row++) {
        full_score_good = 0.0;
        flag_good = 0;
        for (p = *p_row; p < *p_row + SCORE_NUM; p++) {
            full_score_good += *p;
            if (*p >= 85)
                flag_good += 1;
        }
        if (full_score_good / SCORE_NUM >= 90 || flag_good == SCORE_NUM) {
            cout << "No." << p_row - score + 1 << " ";
            for (p = *p_row; p < *p_row + SCORE_NUM; p++) {
                cout << *p << " ";
            }
            cout << "ƽ����" << full_score_good / SCORE_NUM << endl;
        }
    }

}

int main()
{
    int a[STUDENT_NUM][SCORE_NUM] = {
        {91, 81, 71, 61, 51},	//��1��ѧ����1-5�ſεĳɼ�
        {92, 82, 72, 32, 52},   //��2��ѧ����1-5�ſεĳɼ�
        {93, 83, 99, 80, 95},   //��3��ѧ����1-5�ſεĳɼ�
        {97, 85, 87, 91, 88} }; //��4��ѧ����1-5�ſεĳɼ�

    int(*p_row)[SCORE_NUM] = a, * p = a[0];
    cout << "��ʼ��Ϣ��" << endl;
    for (*p_row; p_row < a + STUDENT_NUM; p_row++) {
        cout << "No." << p_row - a + 1 << "��1-5�ſγɼ���";
        for (p = *p_row; p < *p_row + SCORE_NUM; p++) {
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
