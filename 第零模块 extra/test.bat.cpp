#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

ofstream ofs_data, ofs_test;

long long counter = 0;

void data_generate()
{
	ofs_data << "[" << ++counter << "]" << endl;
}

int main()
{
	srand((unsigned int)(time(0)));
	string file_name[3] = { "demo", "debug_VS", "debug_Dev" }, ignore_method[4] = { "none", "left" , "right" , "all" };
	int n, option_1, option_2, option_3;
	cout << "/* ���������ļ�������������ļ����ɳ��� */\n\n�������������������";
	cin >> n;
	cout << "��ѡ����������ļ����ɷ�ʽ��\n[1] ���ɲ��������ļ�\n[2] ���ɿղ��������ļ�\n[3] �����ɲ��������ļ�\n";
	option_1 = _getch();
	if (option_1 == '1') {
		cout << "��ʼ���ɲ��������ļ�\n";
		ofs_data.open("test_data.txt", ios::out);
		/* data_generate start */

		/* data_generate end */
		ofs_data.close();
		cout << "���������ļ��������\n";
	}
	else if (option_1 == '2') {
		cout << "��ʼ���ɿղ��������ļ�\n";
		ofs_data.open("test_data.txt", ios::out);
		for (int i = 1; i <= n; i++)
			ofs_data << "[" << i << "]\n\n\n";
		ofs_data.close();
		cout << "�ղ��������ļ��������\n";
	}
	cout << "��ѡ��txt_compare��ʽÿ�пո�/tab�ĺ��Է�ʽ��\n[1] ÿ�о��ϸ�ƥ��ո�(none)\n[2] ÿ�о�����ͷ���ո�(left)\n[3] ÿ�о�����β���ո�(right)\n[4] ÿ�о�����ͷβ�ո�(all)\n";
	option_2 = _getch();
	cout << "�ı��Ƚ���Ϻ��Ƿ�ɾ������ض����ļ�(1-�� 0-��)\n";
	option_3 = _getch();
	cout << "��ʼ��������������ļ�\n";
	ofs_test.open("test.bat", ios::out);
	ofs_test << "echo off\n\necho.\n";
	for (int i = 0; i < 3; i++) {
		ofs_test << "echo /* " << file_name[i] << ".exe ���Կ�ʼ ��" << setw(4) << n << " �����ݴ����� */\necho.\n\nget_input_data test_data.txt 1 | " << file_name[i] << " > result_" << file_name[i] << ".txt\necho " << file_name[i] << ".exe ��   1 ������ �������\n";
		for (int j = 2; j <= n; j++)
			ofs_test << "get_input_data test_data.txt " << j << " | " << file_name[i] << " >> result_" << file_name[i] << ".txt\necho " << file_name[i] << ".exe ��" << setw(4) << j << " ������ �������\n";
		ofs_test << "\necho.\necho /* " << file_name[i] << ".exe ���Խ��� ��" << setw(4) << n << " ��������ɲ��� */\necho.\n";
	}
	ofs_test << endl;
	for (int i = 1; i <= 2; i++)
		ofs_test << "echo [comp��ʽ] result_" << file_name[0] << ".txt �� result_" << file_name[i] << ".txt ���ı��ȽϽ�����£�\ncomp result_" << file_name[0] << ".txt result_" << file_name[i] << ".txt /M\n\n";
	for (int i = 1; i <= 2; i++)
		ofs_test << "echo [fc��ʽ] result_" << file_name[0] << ".txt �� result_" << file_name[i] << ".txt ���ı��ȽϽ�����£�\nfc result_" << file_name[0] << ".txt result_" << file_name[i] << ".txt\n\n";
	for (int i = 1; i <= 2; i++)
		ofs_test << "echo [txt_compare��ʽ] result_" << file_name[0] << ".txt �� result_" << file_name[i] << ".txt ���ı��ȽϽ�����£�\ntxt_compare --file1 result_" << file_name[0] << ".txt --file2 result_" << file_name[i] << ".txt --trim " << ignore_method[option_2 - '1'] << " --display normal\necho.\n\n";
	if (option_3 == '1') {
		for (int i = 0; i < 3; i++)
			ofs_test << "del result_" << file_name[i] << ".txt\n";
		ofs_test << endl;
	}
	ofs_test << "pause";
	ofs_test.close();
	cout << "����������ļ��������\n�������н���" << endl;

	return 0;
}