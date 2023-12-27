/* 2251730 信07 刘淑仪 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
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

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(两边为A) */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(0, 1, 'A', end_ch);  //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl;/* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(0, 0, 'A', end_ch);//逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（外侧为A） */
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw((end_ch - 64) * 2 - 1) << "=" << endl;/* 按字母塔最大宽度输出= */
	print_tower(1, 1, 'A', end_ch);   //打印 A~结束字符的正三角 
	print_tower(1, 0, 'A', end_ch);  //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
