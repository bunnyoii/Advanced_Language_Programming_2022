/*��07 2251730 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
	int y, m, w, d, ret;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &y, &m);
		if (ret == 2 && (y <= 2023 && y >= 2000 && m >= 1 && m <= 12))
			break;
		else if (ret == 2 && !(y <= 2023 && y >= 2000 && m >= 1 && m <= 12))
		{
		}
		else {
			while (getchar() != '\n')
				;
		}

		printf("����Ƿ�[ret=%d y=%d m=%d],����������\n", ret, y, m);
	}
	bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;

	if (y <= 2023 && y >= 2000 && m >= 1 && m <= 12) {
		while (1) {
			printf("������");
			printf("%d", y);
			printf("��");
			printf("%d", m);
			printf("��1�յ�����(0-6��ʾ������-������) �� ");
			ret = scanf("%d", &w);
			if (ret == 1 && (w >= 0 && w <= 6))
				break;
			else if (ret == 0) {
				while (getchar() != '\n');
			}

			printf("����Ƿ�[ret=%d x=%d],����������\n", ret, y, m);
		}

		printf("%d", y);
		printf("��");
		printf("%d", m);
		printf("�µ�����Ϊ:\n");
		printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
		if (m == 4 || m == 6 || m == 9 || m == 11) {
			switch (w) {
			case 0:
				for (d = 1; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if (d % 7 == 0)
						printf("\n");
				}
				break;
			case 1:
				printf("           1       2       3       4       5       6\n");
				for (d = 7; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 1) % 7 == 0)
						printf("\n");
				}
				break;
			case 2:
				printf("                   1       2       3       4       5\n");
				for (d = 6; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 2) % 7 == 0)
						printf("\n");
				}
				break;
			case 3:
				printf("                           1       2       3       4\n");
				for (d = 5; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 3) % 7 == 0)
						printf("\n");
				}
				break;
			case 4:
				printf("                                   1       2       3\n");
				for (d = 4; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 4) % 7 == 0)
						printf("\n");
				}
				break;
			case 5:
				printf("                                           1       2\n");
				for (d = 3; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 5) % 7 == 0)
						printf("\n");
				}
				break;
			case 6:
				printf("                                                   1\n");
				for (d = 2; d <= 30; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 6) % 7 == 0)
						printf("\n");
				}
				break;
			}
		}
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			switch (w) {
			case 0:
				for (d = 1; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if (d % 7 == 0)
						printf("\n");
				}
				break;
			case 1:
				printf("           1       2       3       4       5       6\n");
				for (d = 7; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 1) % 7 == 0)
						printf("\n");
				}
				break;
			case 2:
				printf("                   1       2       3       4       5\n");
				for (d = 6; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 2) % 7 == 0)
						printf("\n");
				}
				break;
			case 3:
				printf("                           1       2       3       4\n");
				for (d = 5; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 3) % 7 == 0)
						printf("\n");
				}
				break;
			case 4:
				printf("                                   1       2       3\n");
				for (d = 4; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 4) % 7 == 0)
						printf("\n");
				}
				break;
			case 5:
				printf("                                           1       2\n");
				for (d = 3; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 5) % 7 == 0)
						printf("\n");
				}
				break;
			case 6:
				printf("                                                   1\n");
				for (d = 2; d <= 31; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 6) % 7 == 0)
						printf("\n");
				}
				break;
			}
		}
		if (leap == 1 && m == 2) {
			switch (w) {
			case 0:
				for (d = 1; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if (d % 7 == 0)
						printf("\n");
				}
				break;
			case 1:
				printf("           1       2       3       4       5       6\n");
				for (d = 7; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 1) % 7 == 0)
						printf("\n");
				}
				break;
			case 2:
				printf("                   1       2       3       4       5\n");
				for (d = 6; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 2) % 7 == 0)
						printf("\n");
				}
				break;
			case 3:
				printf("                           1       2       3       4\n");
				for (d = 5; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 3) % 7 == 0)
						printf("\n");
				}
				break;
			case 4:
				printf("                                   1       2       3\n");
				for (d = 4; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 4) % 7 == 0)
						printf("\n");
				}
				break;
			case 5:
				printf("                                           1       2\n");
				for (d = 3; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 5) % 7 == 0)
						printf("\n");
				}
				break;
			case 6:
				printf("                                                   1\n");
				for (d = 2; d <= 29; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 6) % 7 == 0)
						printf("\n");
				}
				break;
			}
		}
		if (leap == 0 && m == 2) {
			switch (w) {
			case 0:
				for (d = 1; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if (d % 7 == 0)
						printf("\n");
				}
				break;
			case 1:
				printf("           1       2       3       4       5       6\n");
				for (d = 7; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 1) % 7 == 0)
						printf("\n");
				}
				break;
			case 2:
				printf("                   1       2       3       4       5\n");
				for (d = 6; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 2) % 7 == 0)
						printf("\n");
				}
				break;
			case 3:
				printf("                           1       2       3       4\n");
				for (d = 5; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 3) % 7 == 0)
						printf("\n");
				}
				break;
			case 4:
				printf("                                   1       2       3\n");
				for (d = 4; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 4) % 7 == 0)
						printf("\n");
				}
				break;
			case 5:
				printf("                                           1       2\n");
				for (d = 3; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 5) % 7 == 0)
						printf("\n");
				}
				break;
			case 6:
				printf("                                                   1\n");
				for (d = 2; d <= 28; d++) {
					printf("  ");
					printf("%2d", d);
					printf("    ");
					if ((d + 6) % 7 == 0)
						printf("\n");
				}
				break;
			}
		}
	}
	return 0;
}