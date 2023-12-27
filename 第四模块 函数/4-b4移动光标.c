/* 2251730 信07 刘淑仪 */
#include <stdio.h>
#include<stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  函数名称：menu
  功    能：显示菜单
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：键入数字的ASCII码
  说    明：无
***************************************************************************/

int menu(const HANDLE hout) {
	while (1) {
		//菜单界面
		printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)");
		printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
		printf("3.用箭头箭控制上下左右，边界停止\n");
		printf("4.用箭头箭控制上下左右，边界回绕\n");
		printf("5.用I、J、K、L键控制上卞左右(大小写均可，边界停止)\n");
		printf("6.用I、J、K、L键控制上卞左右(大小写均可，边界回绕)");
		printf("0.退出\n");
		printf("[请选择0-6] \n");
		//选择输入
		char x;
		x = _getche();
		if (x == 49 || x == 50 || x == 51 || x == 52 || x == 53 || x == 54) {
			return x;
		}
		else if (x == 48) {
			putchar(0);
			return 48;
		}
		else
			cls(hout);
	}
}

/****************************************************************************
函数名称：move系列
功    能：通过ijkl或箭头控制光标移动
输入参数：HANDLE hout：输出设备句柄；boundary：是否进行边界环绕
返 回 值：无
说    明：
****************************************************************************/

void move_by_ijkl(const HANDLE hout, bool boundary) {
	char ch1;
	int x = (MAX_X + 1) / 2;
	int y = (MAX_Y + 1) / 2;
	while (1) {
		ch1 = _getch();
		if (ch1 == 73 || ch1 == 105)//上
			--y;
		else if (ch1 == 75 || ch1 == 107)//下
			++y;
		else if (ch1 == 74 || ch1 == 106)//左
			--x;
		else if (ch1 == 76 || ch1 == 108)//右
			++x;
		else if (ch1 == 32)
			putchar(' ');
		else if (ch1 == 'Q' || ch1 == 'q') {
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单\n");
			do(
				ch1 = _getch(), gotoxy(hout, 0, 24)
				); while (ch1 != 13);
			break;
		}
		else
			;
		if (boundary == 1) {
			if (x > 68) {//右
				if (ch1 == 76 || ch1 == 108)
					x = 2;
			}
			else if (x < 2) {//左
				if (ch1 == 74 || ch1 == 106)
					x = 68;
			}
			else if (y > 16) {//下
				if (ch1 == 75 || ch1 == 107)
					y = 2;
			}
			else if (y < 2) {//上
				if (ch1 == 73 || ch1 == 105)
					y = 16;
			}
		}
		else {
			if (x > 69) {
				if (ch1 == 76 || ch1 == 108)
					x = 69;
			}
			else if (x < 1) {
				if (ch1 == 74 || ch1 == 106)
					x = 1;
			}
			else if (y > 17) {
				if (ch1 == 75 || ch1 == 107)
					y = 17;
			}
			else if (y < 1) {
				if (ch1 == 73 || ch1 == 105)
					y = 1;
			}
		}
		gotoxy(hout, x, y);
	}
}

void move_by_arrow(const HANDLE hout, bool boundary) {
	char ch1;
	char ch2;
	int x = (MAX_X + 1) / 2;
	int y = (MAX_Y + 1) / 2;
	while (1) {
		ch1 = _getch();
		if (ch1 == -32)
		{
			ch2 = _getch();
			if (ch2 == 72)//上
				--y;
			else if (ch2 == 80)//下
				++y;
			else if (ch2 == 75)//左
				--x;
			else if (ch2 == 77)//右
				++x;
		}
		else if (ch1 == 'Q' || ch1 == 'q') {
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单\n");
			do(
				ch1 = _getch(), gotoxy(hout, 0, 24)
				); while (ch1 != 13);
			break;
		}
		else if (ch1 == 32)
			putchar(' ');
		else
			;
		if (boundary == 1) {
			if (x > 69) {//右
				if (ch1 == -32 && ch2 == 77)
					x = 1;
			}
			else if (x < 1) {//左
				if (ch1 == -32 && ch2 == 75)
					x = 69;
			}
			else if (y > 17) {//下
				if (ch1 == -32 && ch2 == 80)
					y = 1;
			}
			else if (y < 1) {//上
				if (ch1 == -32 && ch2 == 72)
					y = 17;
			}
		}
		else {
			if (x > 69) {
				if (ch1 == -32 && ch2 == 77)
					x = 69;
			}
			else if (x < 1) {
				if (ch1 == -32 && ch2 == 75)
					x = 1;
			}
			else if (y > 17) {
				if (ch1 == -32 && ch2 == 80)
					y = 17;
			}
			else if (y < 1) {
				if (ch1 == -32 && ch2 == 72)
					y = 1;
			}
		}
		gotoxy(hout, x, y);
	}
}

void move_by_ijkl56(const HANDLE hout, bool boundary) {
	char ch1;
	char ch2;
	int x = (MAX_X + 1) / 2;
	int y = (MAX_Y + 1) / 2;
	while (1) {
		ch1 = _getch();
		if (ch1 == -32) {
			ch2 = _getch();
			if (ch2 == 75) {}
		}
		else if (ch1 == 32)
			putchar(' ');
		else if (ch1 == 'Q' || ch1 == 'q') {
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单\n");
			do(
				ch1 = _getch(), gotoxy(hout, 0, 24)
				); while (ch1 != 13);
			break;
		}
		else {
			if (ch1 == 73 || ch1 == 105)//上
				--y;
			else if (ch1 == 75 || ch1 == 107)//下
				++y;
			else if (ch1 == 74 || ch1 == 106)//左
				--x;
			else if (ch1 == 76 || ch1 == 108)//右
				++x;
		}
		if (boundary == 1) {
			if (x > 68) {//右
				if (ch1 == 76 || ch1 == 108)
					x = 2;
			}
			else if (x < 2) {//左
				if (ch1 == 74 || ch1 == 106)
					x = 68;
			}
			else if (y > 16) {//下
				if (ch1 == 75 || ch1 == 107)
					y = 2;
			}
			else if (y < 2) {//上
				if (ch1 == 73 || ch1 == 105)
					y = 16;
			}
		}
		else {
			if (x > 69) {
				if (ch1 == 76 || ch1 == 108)
					x = 69;
			}
			else if (x < 1) {
				if (ch1 == 74 || ch1 == 106)
					x = 1;
			}
			else if (y > 17) {
				if (ch1 == 75 || ch1 == 107)
					y = 17;
			}
			else if (y < 1) {
				if (ch1 == 73 || ch1 == 105)
					y = 1;
			}
		}
		gotoxy(hout, x, y);
	}
}
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	/*显示菜单*/
	int m1 = menu(hout);

	/* 显示初始的边框及其中的随机字符 */
	while (1) {
		if (m1 == 48) {
			break;
		}
		else if (m1 == 49 || m1 == 50 || m1 == 51 || m1 == 52 || m1 == 53 || m1 == 54) {
			init_border(hout);
			int x = (MAX_X + 1) / 2;
			int y = (MAX_Y + 1) / 2;
			gotoxy(hout, x, y);
			if (m1 == 49)
				move_by_ijkl(hout, 0);
			else if (m1 == 50)
				move_by_ijkl(hout, 1);
			else if (m1 == 51)
				move_by_arrow(hout, 0);
			else if (m1 == 52)
				move_by_arrow(hout, 1);
			else if (m1 == 53)
				move_by_ijkl56(hout, 0);
			else if (m1 == 54)
				move_by_ijkl56(hout, 1);
			cls(hout);
			m1 = menu(hout);
		}
	}
	gotoxy(hout, 0, 23);
	printf("游戏结束，按回车键退出.\n");

	char ch3;
	while (1) {
		ch3 = _getch();
		if (ch3 == 13)
			break;
		else
			;
	}
	/*思考：
	1：能。因为←是控制字符，会产生两个ASCII码：224和75.而224超过了char型的范围，所以编译器自
	动读入第二个ASCII码即75，但K的ASCII码也是75，所以相当于按了一次"K"，光标向下移动。
	2：不一定，有可能。当坐标相同时，后一次输出会覆盖前一次输出。*/
	return 0;
}