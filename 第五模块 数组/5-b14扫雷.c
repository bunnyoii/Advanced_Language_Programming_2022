/* 2251730 ��07 ������ */
/* 2250758 �ּ��� 2251310 ������ 2251649 �ž��� 2252429 ������ 2252436 ��С�� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char bomb[12][28] = { 0 };
	char show[12][28] = { 0 };
	int num = 0;
	//��ʼ��
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			bomb[i][j] = 0;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 28; j++)
			show[i][j] = 0;

	//����
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 27; j++)
			while (1) {
				char ch = getchar();
				if ((ch >= '0' && ch <= '8') || ch == '*') {
					bomb[i][j] = ch;
					break;
				}
			}

	//�ж�'*'�Ƿ�Ϊ50��
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 27; j++) {
			if (bomb[i][j] == '*')
				num++;
			else
				continue;
		}
	if (num != 50) {
		printf("����1\n");
		return 0;
	}
	else
		;

	//�ж����ܱ������Ƿ���ȷ
	//show��ֵ
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
					printf("����2\n");
					return 0;
				}
			}
			else
				continue;
		}
	}
	printf("��ȷ\n");
	return 0;
}