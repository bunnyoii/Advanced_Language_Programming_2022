/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int zeller(int y, int m, int d) {
	int c, w; {}
	if (m >= 3) {
		c = y / 100;
		y = y - c * 100;
		w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)((13 * (m + 1) / 5)) + d - 1;
	}
	else if (m == 1 || m == 2) {
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
		w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)((13 * (m + 13) / 5)) + d - 1;
	}
	for (int i = 1; w < 0; i++) {
		w = w + 7 * 1;
	}
	w = w % 7;
	return w;
}

int main() {
	int w, c, y, m, d, ret;
	while (1) {
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d %d %d", &y, &m, &d);
		bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
		if (ret != 3){
			printf("�����������������\n");
			while (getchar() != '\n');
		}
		else if (ret == 3 && (y > 2100 || y < 1900))
			printf("��ݲ���ȷ������������\n");
		else if (ret == 3 && (m > 12 || m < 1))
			printf("�·ݲ���ȷ������������\n");
		else if (ret == 3 && (m == 4 || m == 6 || m == 9 || m == 11) && d > 30 || d < 1)
			printf("�ղ���ȷ������������\n");
		else if (ret == 3 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31 || d < 1)
			printf("�ղ���ȷ������������\n");
		else if (ret == 3 && leap == 1 && m == 2 && d > 29 || d < 1)
			printf("�ղ���ȷ������������\n");
		else if (ret == 3 && leap == 0 && m == 2 && d > 28 || d < 1)
			printf("�ղ���ȷ������������\n");
		else
			break;
	}
	w = zeller(y, m, d);
	printf("����");
	switch (w) {
	case 0:
		printf("��\n");
		break;
	case 1:
		printf("һ\n");
		break;
	case 2:
		printf("��\n");
		break;
	case 3:
		printf("��\n");
		break;
	case 4:
		printf("��\n");
		break;
	case 5:
		printf("��\n");
		break;
	case 6:
		printf("��\n");
		break;
	}
	return 0;
}