/* 2251730 ��07 ������ */
#include <stdio.h>
#include<stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ���ʾ�˵�
  ���������HANDLE hout������豸���
  �� �� ֵ���������ֵ�ASCII��
  ˵    ������
***************************************************************************/

int menu(const HANDLE hout) {
	while (1) {
		//�˵�����
		printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)");
		printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
		printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
		printf("4.�ü�ͷ�������������ң��߽����\n");
		printf("5.��I��J��K��L�������ϱ�����(��Сд���ɣ��߽�ֹͣ)\n");
		printf("6.��I��J��K��L�������ϱ�����(��Сд���ɣ��߽����)");
		printf("0.�˳�\n");
		printf("[��ѡ��0-6] \n");
		//ѡ������
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
�������ƣ�moveϵ��
��    �ܣ�ͨ��ijkl���ͷ���ƹ���ƶ�
���������HANDLE hout������豸�����boundary���Ƿ���б߽绷��
�� �� ֵ����
˵    ����
****************************************************************************/

void move_by_ijkl(const HANDLE hout, bool boundary) {
	char ch1;
	int x = (MAX_X + 1) / 2;
	int y = (MAX_Y + 1) / 2;
	while (1) {
		ch1 = _getch();
		if (ch1 == 73 || ch1 == 105)//��
			--y;
		else if (ch1 == 75 || ch1 == 107)//��
			++y;
		else if (ch1 == 74 || ch1 == 106)//��
			--x;
		else if (ch1 == 76 || ch1 == 108)//��
			++x;
		else if (ch1 == 32)
			putchar(' ');
		else if (ch1 == 'Q' || ch1 == 'q') {
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�\n");
			do(
				ch1 = _getch(), gotoxy(hout, 0, 24)
				); while (ch1 != 13);
			break;
		}
		else
			;
		if (boundary == 1) {
			if (x > 68) {//��
				if (ch1 == 76 || ch1 == 108)
					x = 2;
			}
			else if (x < 2) {//��
				if (ch1 == 74 || ch1 == 106)
					x = 68;
			}
			else if (y > 16) {//��
				if (ch1 == 75 || ch1 == 107)
					y = 2;
			}
			else if (y < 2) {//��
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
			if (ch2 == 72)//��
				--y;
			else if (ch2 == 80)//��
				++y;
			else if (ch2 == 75)//��
				--x;
			else if (ch2 == 77)//��
				++x;
		}
		else if (ch1 == 'Q' || ch1 == 'q') {
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�\n");
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
			if (x > 69) {//��
				if (ch1 == -32 && ch2 == 77)
					x = 1;
			}
			else if (x < 1) {//��
				if (ch1 == -32 && ch2 == 75)
					x = 69;
			}
			else if (y > 17) {//��
				if (ch1 == -32 && ch2 == 80)
					y = 1;
			}
			else if (y < 1) {//��
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
			printf("��Ϸ���������س������ز˵�\n");
			do(
				ch1 = _getch(), gotoxy(hout, 0, 24)
				); while (ch1 != 13);
			break;
		}
		else {
			if (ch1 == 73 || ch1 == 105)//��
				--y;
			else if (ch1 == 75 || ch1 == 107)//��
				++y;
			else if (ch1 == 74 || ch1 == 106)//��
				--x;
			else if (ch1 == 76 || ch1 == 108)//��
				++x;
		}
		if (boundary == 1) {
			if (x > 68) {//��
				if (ch1 == 76 || ch1 == 108)
					x = 2;
			}
			else if (x < 2) {//��
				if (ch1 == 74 || ch1 == 106)
					x = 68;
			}
			else if (y > 16) {//��
				if (ch1 == 75 || ch1 == 107)
					y = 2;
			}
			else if (y < 2) {//��
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
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	/*��ʾ�˵�*/
	int m1 = menu(hout);

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
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
	printf("��Ϸ���������س����˳�.\n");

	char ch3;
	while (1) {
		ch3 = _getch();
		if (ch3 == 13)
			break;
		else
			;
	}
	/*˼����
	1���ܡ���Ϊ���ǿ����ַ������������ASCII�룺224��75.��224������char�͵ķ�Χ�����Ա�������
	������ڶ���ASCII�뼴75����K��ASCII��Ҳ��75�������൱�ڰ���һ��"K"����������ƶ���
	2����һ�����п��ܡ���������ͬʱ����һ������Ḳ��ǰһ�������*/
	return 0;
}