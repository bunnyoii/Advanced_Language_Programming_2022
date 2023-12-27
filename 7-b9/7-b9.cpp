/* 2251730 ��07 ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	friend class stu_list;
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	int cnt = 0;						//����
	int choose1[MAX_STU_NUM] = { 0 };
	int choose2[MAX_STU_NUM] = { 0 };

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();											//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������
	void merge();										//�ϲ�
	void deduplication();						//ȥ��
	void sort();										//����
	void choose_or_withdraw();							//�ж�ѡ��/�˿�/��ѡ
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
//�ϲ�
void stu_list::merge()
{
	/* �ѵ�һ����ȫ���� */
	for (int i = 0; i < list_num_1; i++) {
		list_merge[i].stu_no = list_round_1[i].no;
		strcpy(list_merge[i].stu_name, list_round_1[i].name);
	}
	/* ȥ�ص�һ�� */
	deduplication();
	/* �ѵڶ�����ȫ���� */
	int t = 0;
	for (int i = 0; i < list_num_2; i++) {
		for (int j = t; j < MAX_STU_NUM; j++) {
			if (list_merge[j].stu_no == 0) {
				list_merge[j].stu_no = list_round_2[i].no;
				strcpy(list_merge[j].stu_name, list_round_2[i].name);
				t = j + 1;
				break;
			}
		}
	}
	deduplication();
}
//ȥ��
void stu_list::deduplication()
{
	for (int i = 0; i < MAX_STU_NUM; i++) {
		for (int j = 0; j < MAX_STU_NUM; j++) {
			if (list_merge[i].stu_no == list_merge[j].stu_no && i != j) {
				list_merge[j].stu_no = 0;
			}
		}
	}
}
//����
void stu_list::sort()
{
	int t = 0;
	char tname[MAX_NAME_LEN] = { 0 };
	for (int i = 0; i < MAX_STU_NUM - 1; i++)
		for (int j = 0; j < MAX_STU_NUM - (i + 1); j++)
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				t = list_merge[j].stu_no;
				strcpy(tname, list_merge[j].stu_name);

				list_merge[j].stu_no = list_merge[j + 1].stu_no;
				strcpy(list_merge[j].stu_name, list_merge[j + 1].stu_name);

				list_merge[j + 1].stu_no = t;
				strcpy(list_merge[j + 1].stu_name, tname);
			}
}
//�ж�ѡ��/�˿�/��ѡ
void stu_list::choose_or_withdraw()
{
	/*
	�ԱȺϲ������͵�һ��������������غϣ�����ǡ�
	choose1[i]==1 : Y;
	choose1[i]==0 : /;
	*/
	for (int i = 0; i < MAX_STU_NUM; i++) {
		for (int j = 0; j < list_num_1; j++) {
			if (list_merge[i].stu_no) {
				if (list_merge[i].stu_no == list_round_1[j].no) {
					choose1[i] = 1;
					break;
				}
			}
		}
	}
	/*
	�ԱȺϲ������͵ڶ���������������غϣ�
	��choose1[i]==1, choose2[i]==1;// Y Y
	��choose1[i]==0��choose2[i]==2;// / ��ѡ
	���û�غϣ�
	�ԱȺϲ������͵ڶ���������������غϣ�
	��choose1[i]==1, choose2[i]==0;// Y �˿�
	��choose1[i]==0��choose2[i]==(��������);// / /
	*/
	for (int i = 0; i < MAX_STU_NUM; i++) {
		for (int j = 0; j < list_num_2; j++) {
			if (list_merge[i].stu_no) {
				if (list_merge[i].stu_no == list_round_2[j].no) {
					if (choose1[i])
						choose2[i] = 1;
					else
						choose2[i] = 2;
					break;
				}
			}
		}
	}
}
/***************************************************************************
  �������ƣ�stu_list
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	for (int i = 0; i < MAX_STU_NUM; i++) {
		list_merge[i].stu_no = 0;
		list_merge[i].stu_name[0] = '0';
		list_merge[i].stu_no = 0;
	}
}

/***************************************************************************
  �������ƣ�read
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
	case 1:
		this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
		if (this->list_num_1 > 0)
			print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
		else
			ret = -1;
		break;
	case 2:
		this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
		if (this->list_num_2 > 0)
			print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
		else
			ret = -1;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << "����ѡ������" << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (int i = 0, cnt = 0; i < MAX_STU_NUM; i++) {
		if (list_merge[i].stu_no != 0) {
			cout << setw(5) << setiosflags(ios::left) << cnt + 1
				<< setw(9) << list_merge[i].stu_no
				<< setw(32) << list_merge[i].stu_name;
			cnt++;
			if (choose1[i] == 1)
				cout << setw(7) << "Y";
			else
				cout << setw(7) << "/";
			if (choose2[i] == 1)
				cout << setw(1) << "Y";
			else if (choose2[i] == 2)
				cout << setw(4) << "��ѡ";
			else
				cout << setw(4) << "�˿�";
			cout << endl;
		}
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.merge();
	list.sort();
	list.choose_or_withdraw();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}
