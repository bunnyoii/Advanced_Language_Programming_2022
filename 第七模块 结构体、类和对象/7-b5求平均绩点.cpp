/* 2251730 刘淑仪 信07 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、最多允许添加一个函数，且需要满足要求
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
	int   gpa;		//某课程的绩点（同济规则，[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	float average_gpa;
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：此处最多允许添加一个函数，且函数的形参、自动变量等都必须是简单变量（即不允许[]形式）
***************************************************************************/
void value_to_gpa(struct student* stu, int num)
{
	int i, j;
	float all_grade = 0;
	float all_weight = 0;
	/* 求单科绩点 */
	for (i = 0; i < num; i++, stu++) {
		for (j = 0; j < 3; j++) {
			if ((stu->score + j)->value >= 0 && (stu->score + j)->value < 60)
				(stu->score + j)->gpa = 0;
			else if ((stu->score + j)->value >= 60 && (stu->score + j)->value < 70)
				(stu->score + j)->gpa = 2;
			else if ((stu->score + j)->value >= 70 && (stu->score + j)->value < 80)
				(stu->score + j)->gpa = 3;
			else if ((stu->score + j)->value >= 80 && (stu->score + j)->value < 90)
				(stu->score + j)->gpa = 4;
			else if ((stu->score + j)->value >= 90 && (stu->score + j)->value <= 100)
				(stu->score + j)->gpa = 5;
		}
	}
	/* 求平均绩点 */
	for (stu -= 10, i = 0; i < num; i++, stu++) {
		all_weight = 0;
		all_grade = 0;
		for (j = 0; j < 3; j++) {
			all_grade += ((stu->score + j)->gpa * (stu->score + j)->weight);
			all_weight += (stu->score + j)->weight;
		}
		stu->average_gpa = all_grade / all_weight;
	}
}
/***************************************************************************
  函数名称：input
  功    能：输入10个学生的信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void input(struct student* stu, int num)
{
	int i, j;
	for (i = 0; i < num; i++, stu++) {
		cout << "请输入第" << setw(2) << i + 1 << "个学生的信息 : ";
		cin >> stu->no >> stu->name;
		for (j = 0; j < 3; j++) {
			cin >> (stu->score + j)->value >> (stu->score + j)->weight;
		}
	}
}

/***************************************************************************
  函数名称：output_base
  功    能：输出基本信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	struct student* ps;
	struct course* pc;
	value_to_gpa(stu, num);
	cout << endl << "10个学生的成绩" << endl;
	cout << "序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点" << endl;
	cout << "==================================================================" << endl;
	for (ps = stu; ps - stu < 10; ps++) {
		cout << resetiosflags(ios::fixed) << setw(5) << setiosflags(ios::left) << ps - stu + 1
			<< setw(8) << setiosflags(ios::left) << ps->no
			<< setw(9) << setiosflags(ios::left) << ps->name;
		for (pc = ps->score; pc - ps->score < 3; pc++)
			cout << setw(6) << setiosflags(ios::left) << pc->gpa
			<< setw(6) << setiosflags(ios::left) << pc->weight;
		cout << setw(6) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(3) << ps->average_gpa;
		cout << endl;
	}
	ps = stu;
}

/***************************************************************************
  函数名称：output_max
  功    能：输出绩点最高的学生（可能有并列）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* 本函数中允许定义各种类型的简单变量，但不允许定义数组 */
	struct student* ps;
	struct student* ps0 = stu;
	struct course* pc;
	int i;
	cout << endl << "绩点最高的学生为" << endl;
	cout << "序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点" << endl;
	cout << "==================================================================" << endl;
	/* 找到最高绩点 */
	for (i = 1; i < num; i++) {
		if (stu->average_gpa < (stu + i)->average_gpa) {
			stu += i;
			i = 0;
		}
	}
	ps = stu;
	/* 输出绩点最高的人 */
	for (stu = ps0; stu - ps0 < num; stu++) {
		if (stu->average_gpa == ps->average_gpa) {
			cout << resetiosflags(ios::fixed) << setw(5) << setiosflags(ios::left) << stu - ps0 + 1
				<< setw(8) << setiosflags(ios::left) << stu->no
				<< setw(9) << setiosflags(ios::left) << stu->name;
			for (pc = stu->score; pc - stu->score < 3; pc++)
				cout << setw(6) << setiosflags(ios::left) << pc->gpa
				<< setw(6) << setiosflags(ios::left) << pc->weight;
			cout << setw(6) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(3) << ps->average_gpa;
			cout << endl;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, N);		//输入10个学生的信息
	output_base(stu, N);	//输出10个学生的基本信息
	output_max(stu, N);	//输出最高（可能有多个）

	return 0;
}
/*
测试数据，复制到cmd即可（测试时，不限于这一组）

2150844 温在豪 76.5 4 82 5 52 2
2154284 杨骏昊 63 4 49 1 87 6
2253105 赵浩天 56 3 76 4 69 5
2254319 徐希文 44.5 2 83.5 4 87 6
2251754 孙耀阳 91 4 43.5 1 66 3
2250269 司徒成傑 79 6 85.5 3 62 2
2252558 徐乙巽 86 3 63 3 77.5 4
1951475 赵伯威 49.5 3 86 6 93.5 3
2153879 项卢羽成 81.5 2 64.5 3 87 4
2253636 张天阳 73 3 62 2 85 5

*/