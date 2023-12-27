/* 2251730 ��07 ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_blank(char end_ch_, char end_ch)
{
	cout << setfill(' ') << setw(end_ch_ - end_ch + 1);

}

void print_line(bool left_right, char start_ch, char end_ch)
{
	if (left_right == 1)//1 left 0 right
	{
		if (start_ch < end_ch) {
			cout << start_ch;
			print_line(1, start_ch + 1, end_ch);
		}
		else
			return;
	}
	else {
		if (start_ch >= end_ch) {
			cout << start_ch;
			print_line(0, start_ch - 1, end_ch);
		}
		else
			return;
	}
}

void print_tower(bool both, bool order, char start_ch, char end_ch)
{
	static char end_ch_ = end_ch;
	if (both == 0) {
		if (order == 1) {
			if (start_ch != end_ch)
				print_tower(0, 1, start_ch, end_ch - 1);
			print_blank(end_ch_, end_ch);
			print_line(1, 'A', end_ch);
			print_line(0, end_ch, 'A');
			cout << endl;
		}
		else {
			print_blank(end_ch_, end_ch);
			print_line(1, 'A', end_ch);
			print_line(0, end_ch, 'A');
			cout << endl;
			if (start_ch != end_ch)
				print_tower(0, 0, start_ch, end_ch - 1);
			else
				return;
		}
	}
	else {
		if (order == 1) {
			if (start_ch != end_ch)
				print_tower(1, 1, start_ch, end_ch - 1);
			print_blank(end_ch_, end_ch);
			print_line(1, 'A', end_ch);
			print_line(0, end_ch, 'A');
			cout << endl;
		}
		else {
			if (end_ch != 65) {
				print_blank(end_ch_ + 1, end_ch);
				print_line(1, 'A', end_ch - 1);
				print_line(0, end_ch - 1, 'A');
				cout << endl;
				if (start_ch != end_ch - 1)
					print_tower(1, 0, start_ch, end_ch - 1);
				else
					return;
			}
			else
				;
		}

	}
}

int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(0, 1, 'A', end_ch);  //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl;/* ����ĸ����������=(��������ѭ��) */
	print_tower(0, 0, 'A', end_ch);//�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl;/* ����ĸ����������= */
	print_tower(1, 1, 'A', end_ch);   //��ӡ A~�����ַ��������� 
	print_tower(1, 0, 'A', end_ch);  //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
