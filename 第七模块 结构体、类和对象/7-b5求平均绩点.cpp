/* 2251730 ������ ��07 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3������������һ������������Ҫ����Ҫ��
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
	int   gpa;		//ĳ�γ̵ļ��㣨ͬ�ù���[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5��
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	float average_gpa;
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����˴�����������һ���������Һ������βΡ��Զ������ȶ������Ǽ򵥱�������������[]��ʽ��
***************************************************************************/
void value_to_gpa(struct student* stu, int num)
{
	int i, j;
	float all_grade = 0;
	float all_weight = 0;
	/* �󵥿Ƽ��� */
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
	/* ��ƽ������ */
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
  �������ƣ�input
  ��    �ܣ�����10��ѧ������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void input(struct student* stu, int num)
{
	int i, j;
	for (i = 0; i < num; i++, stu++) {
		cout << "�������" << setw(2) << i + 1 << "��ѧ������Ϣ : ";
		cin >> stu->no >> stu->name;
		for (j = 0; j < 3; j++) {
			cin >> (stu->score + j)->value >> (stu->score + j)->weight;
		}
	}
}

/***************************************************************************
  �������ƣ�output_base
  ��    �ܣ����������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	struct student* ps;
	struct course* pc;
	value_to_gpa(stu, num);
	cout << endl << "10��ѧ���ĳɼ�" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
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
  �������ƣ�output_max
  ��    �ܣ����������ߵ�ѧ���������в��У�
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* ��������������������͵ļ򵥱������������������� */
	struct student* ps;
	struct student* ps0 = stu;
	struct course* pc;
	int i;
	cout << endl << "������ߵ�ѧ��Ϊ" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	/* �ҵ���߼��� */
	for (i = 1; i < num; i++) {
		if (stu->average_gpa < (stu + i)->average_gpa) {
			stu += i;
			i = 0;
		}
	}
	ps = stu;
	/* ���������ߵ��� */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, N);		//����10��ѧ������Ϣ
	output_base(stu, N);	//���10��ѧ���Ļ�����Ϣ
	output_max(stu, N);	//�����ߣ������ж����

	return 0;
}
/*
�������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩

2150844 ���ں� 76.5 4 82 5 52 2
2154284 �� 63 4 49 1 87 6
2253105 �Ժ��� 56 3 76 4 69 5
2254319 ��ϣ�� 44.5 2 83.5 4 87 6
2251754 ��ҫ�� 91 4 43.5 1 66 3
2250269 ˾ͽ�ɂ� 79 6 85.5 3 62 2
2252558 ������ 86 3 63 3 77.5 4
1951475 �Բ��� 49.5 3 86 6 93.5 3
2153879 ��¬��� 81.5 2 64.5 3 87 4
2253636 ������ 73 3 62 2 85 5

*/