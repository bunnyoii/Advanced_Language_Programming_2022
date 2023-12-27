/* 2251730 信07 刘淑仪 */
/* 2250758 林继申 2251310 杜天乐 2251649 张静涵 2252429 蔡宇轩 2252436 周小新 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char bomb[12][28] = { 0 };
	char show[12][28] = { 0 };
	int num = 0;
	//初始化
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			bomb[i][j] = 0;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			show[i][j] = 0;

	//输入
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 27; j++)
			while (1) {
				char ch = getchar();
				if ((ch >= '0' && ch <= '8') || ch == '*') {
					bomb[i][j] = ch;
					break;
				}
			}

	//判断'*'是否为50个
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 27; j++) {
			if (bomb[i][j] == '*')
				num++;
			else
				continue;
		}
	if (num != 50) {
		printf("错误1\n");
		return 0;
	}
	else
		;

	//判断雷周边数字是否正确
	//show赋值
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			if(bomb[i][j]!='*')
			{
				num = 0;
				if (bomb[i][j - 1] == '*')
					num++;
				if (bomb[i][j + 1] == '*')
					num++;
				if (bomb[i - 1][j] == '*')
					num++;
				if (bomb[i - 1][j - 1] == '*')
					num++;
				if (bomb[i - 1][j + 1] == '*')
					num++;
				if (bomb[i + 1][j] == '*')
					num++;
				if (bomb[i + 1][j - 1] == '*')
					num++;
				if (bomb[i + 1][j + 1] == '*')
					num++;
				show[i][j] = num + '0';
			}
		}
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			if (bomb[i][j] != '*') {
				if (show[i][j]!= bomb[i][j]) {
					printf("错误2\n");
					return 0;
				}
			}
			else
				continue;
		}
	}
	printf("正确\n");
	return 0;
}