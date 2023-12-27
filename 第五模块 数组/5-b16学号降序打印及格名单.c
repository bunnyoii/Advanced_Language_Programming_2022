/* 2251730 信07 刘淑仪 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

void bubble_sort(int grade[], int n, char number[][8], char name[][9])
{
	int i, j, t;
	char Tnum[1][128] = { 0 };
	char Tname[1][128] = { 0 };
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - (i + 1); j++)
			if (strcmp(number[j], number[j + 1]) < 0) {
				t = grade[j];
				strcpy(Tnum[0], number[j]);
				strcpy(Tname[0], name[j]);

				grade[j] = grade[j + 1];
				strcpy(number[j], number[j + 1]);
				strcpy(name[j], name[j + 1]);

				grade[j + 1] = t;
				strcpy(number[j + 1], Tnum[0]);
				strcpy(name[j + 1], Tname[0]);
			}
}

void input(char number[][8], char name[][9], int grade[])
{
	for (int i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", number[i], name[i], &grade[i]);
	}
}
void output(int grade[], char number[][8], char name[][9])
{
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++)
		if (grade[i] >= 60)
			printf("%s %s %d\n", name[i], number[i], grade[i]);
}
int main() {
	char number[10][8];
	char name[10][9];
	int grade[10];
	input(number, name, grade);
	printf("\n");
	bubble_sort(grade, 10, number, name);
	output(grade, number, name);
	return 0;
}