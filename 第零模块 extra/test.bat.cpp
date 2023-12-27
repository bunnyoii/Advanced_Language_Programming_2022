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
	cout << "/* 测试数据文件与批处理测试文件生成程序 */\n\n请输入测试数据组数：";
	cin >> n;
	cout << "请选择测试数据文件生成方式：\n[1] 生成测试数据文件\n[2] 生成空测试数据文件\n[3] 不生成测试数据文件\n";
	option_1 = _getch();
	if (option_1 == '1') {
		cout << "开始生成测试数据文件\n";
		ofs_data.open("test_data.txt", ios::out);
		/* data_generate start */

		/* data_generate end */
		ofs_data.close();
		cout << "测试数据文件生成完毕\n";
	}
	else if (option_1 == '2') {
		cout << "开始生成空测试数据文件\n";
		ofs_data.open("test_data.txt", ios::out);
		for (int i = 1; i <= n; i++)
			ofs_data << "[" << i << "]\n\n\n";
		ofs_data.close();
		cout << "空测试数据文件生成完毕\n";
	}
	cout << "请选择txt_compare方式每行空格/tab的忽略方式：\n[1] 每行均严格匹配空格(none)\n[2] 每行均忽略头部空格(left)\n[3] 每行均忽略尾部空格(right)\n[4] 每行均忽略头尾空格(all)\n";
	option_2 = _getch();
	cout << "文本比较完毕后是否删除输出重定向文件(1-是 0-否)\n";
	option_3 = _getch();
	cout << "开始生成批处理测试文件\n";
	ofs_test.open("test.bat", ios::out);
	ofs_test << "echo off\n\necho.\n";
	for (int i = 0; i < 3; i++) {
		ofs_test << "echo /* " << file_name[i] << ".exe 测试开始 共" << setw(4) << n << " 组数据待测试 */\necho.\n\nget_input_data test_data.txt 1 | " << file_name[i] << " > result_" << file_name[i] << ".txt\necho " << file_name[i] << ".exe 第   1 组数据 测试完毕\n";
		for (int j = 2; j <= n; j++)
			ofs_test << "get_input_data test_data.txt " << j << " | " << file_name[i] << " >> result_" << file_name[i] << ".txt\necho " << file_name[i] << ".exe 第" << setw(4) << j << " 组数据 测试完毕\n";
		ofs_test << "\necho.\necho /* " << file_name[i] << ".exe 测试结束 共" << setw(4) << n << " 组数据完成测试 */\necho.\n";
	}
	ofs_test << endl;
	for (int i = 1; i <= 2; i++)
		ofs_test << "echo [comp方式] result_" << file_name[0] << ".txt 和 result_" << file_name[i] << ".txt 的文本比较结果如下：\ncomp result_" << file_name[0] << ".txt result_" << file_name[i] << ".txt /M\n\n";
	for (int i = 1; i <= 2; i++)
		ofs_test << "echo [fc方式] result_" << file_name[0] << ".txt 和 result_" << file_name[i] << ".txt 的文本比较结果如下：\nfc result_" << file_name[0] << ".txt result_" << file_name[i] << ".txt\n\n";
	for (int i = 1; i <= 2; i++)
		ofs_test << "echo [txt_compare方式] result_" << file_name[0] << ".txt 和 result_" << file_name[i] << ".txt 的文本比较结果如下：\ntxt_compare --file1 result_" << file_name[0] << ".txt --file2 result_" << file_name[i] << ".txt --trim " << ignore_method[option_2 - '1'] << " --display normal\necho.\n\n";
	if (option_3 == '1') {
		for (int i = 0; i < 3; i++)
			ofs_test << "del result_" << file_name[i] << ".txt\n";
		ofs_test << endl;
	}
	ofs_test << "pause";
	ofs_test.close();
	cout << "批处理测试文件生成完毕\n程序运行结束" << endl;

	return 0;
}