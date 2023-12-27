/* 2251730 信07 刘淑仪 */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- 不允许定义任何形式的全局变量 --- */

/***************************************************************************
  函数名称：
  功    能：求第一门课的平均分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void average(int(*score)[STUDENT_NUM])
{
    double full_score = 0.0;
    int(*p_row)[STUDENT_NUM] = score, * p = p_row[0];
    for (p; p < p_row[0] + SCORE_NUM - 1; p++)
        full_score += *p;
    cout << "第1门课的平均成绩为：" << full_score / STUDENT_NUM << endl;
}

/***************************************************************************
  函数名称：
  功    能：找出有两门以上课程不及格的学生
  输入参数：
  返 回 值：
  说    明：
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
            cout << "平均：" << full_score_fail / SCORE_NUM << endl;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：找出平均成绩在90分以上或全部成绩在85分以上的学生
  输入参数：
  返 回 值：
  说    明：
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
            cout << "平均：" << full_score_good / SCORE_NUM << endl;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    int a[SCORE_NUM][STUDENT_NUM] = {
        {91,92,93,97},  //第1-4个学生的第1门课成绩
        {81,82,83,85},  //第1-4个学生的第2门课成绩
        {71,72,99,87},  //第1-4个学生的第3门课成绩
        {61,32,80,91},  //第1-4个学生的第4门课成绩
        {51,52,95,88} };//第1-4个学生的第5门课成绩
    /* 除上面的预置数组外，本函数中仅允许定义 1个行指针变量 + 1个简单指针变量 */

    int(*p_row)[STUDENT_NUM] = a, * p = a[0];
    cout << "初始信息：" << endl;
    for (*p_row; p_row < a + SCORE_NUM; p_row++) {
        cout << "No.1-4学生的第" << p_row - a + 1 << "门课成绩：";
        for (p = *p_row; p < *p_row + STUDENT_NUM; p++) {
            cout << *p << " ";
        }
        cout << endl;
    }

    p_row = a;
    average(p_row);
    cout << "\n2门以上不及格的学生：\n";
    fail(p_row);
    cout << "\n平均90以上或全部85以上的学生：\n";
    good(p_row);

    return 0;
}
