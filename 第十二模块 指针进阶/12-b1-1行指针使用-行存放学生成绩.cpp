/* 2251730 信07 刘淑仪 */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- 不允许定义任何形式的全局变量 --- */

/***************************************************************************
  函数名称：average
  功    能：求第一门课的平均分
  输入参数：int(*score)[SCORE_NUM]
  返 回 值：
  说    明：相关输出都放在函数中即可
***************************************************************************/
void average(int(*score)[SCORE_NUM])
{
    double full_score = 0.0;
    for (int(*p)[SCORE_NUM] = score; p < score + STUDENT_NUM; p++)
        full_score += **p;
    cout << "第1门课的平均成绩为：" << full_score / STUDENT_NUM << endl;
}

/***************************************************************************
  函数名称：fail
  功    能：找出有两门以上课程不及格的学生
  输入参数：int(*score)[SCORE_NUM]
  返 回 值：
  说    明：相关输出都放在函数中即可
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
            cout << "平均：" << full_score_fail / SCORE_NUM << endl;
        }
    }
}

/***************************************************************************
  函数名称：good
  功    能：找出平均成绩在90分以上或全部成绩在85分以上的学生
  输入参数：int(*score)[SCORE_NUM]
  返 回 值：
  说    明：
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
            cout << "平均：" << full_score_good / SCORE_NUM << endl;
        }
    }

}

int main()
{
    int a[STUDENT_NUM][SCORE_NUM] = {
        {91, 81, 71, 61, 51},	//第1个学生的1-5门课的成绩
        {92, 82, 72, 32, 52},   //第2个学生的1-5门课的成绩
        {93, 83, 99, 80, 95},   //第3个学生的1-5门课的成绩
        {97, 85, 87, 91, 88} }; //第4个学生的1-5门课的成绩

    int(*p_row)[SCORE_NUM] = a, * p = a[0];
    cout << "初始信息：" << endl;
    for (*p_row; p_row < a + STUDENT_NUM; p_row++) {
        cout << "No." << p_row - a + 1 << "的1-5门课成绩：";
        for (p = *p_row; p < *p_row + SCORE_NUM; p++) {
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
