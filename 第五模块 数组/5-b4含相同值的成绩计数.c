//2251730 信07 刘淑仪
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 1001
int main()
{
	int num[N] = { 0 }, count[N] = { 0 };
	int i, j, t;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	//将num数组全部置负
	for (i = 0; i < N; i++)
		num[i] = -1;
	//输入数组
	for (i = 0; i < N - 1; i++) {
		scanf("%d", &num[i]);
		count[i]++;
		if (num[0] < 0) {
			printf("无有效输入\n");
			return 0;
		}
		else {
			if (num[i] < 0)
				break;
		}
	}
	while (getchar() != '\n')
		;
	//打印输入的数组（十个一行）
	printf("输入的数组为:\n");
	for (i = 0; i < N; i++) {
		if (num[i] >= 0) {
			printf("%d ", num[i]);
			if ((i + 1) % 10 == 0 && num[i + 1] >= 0)
				printf("\n");
		}
	}
	printf("\n");

	printf("分数与人数的对应关系为:\n");
	//冒泡排序，大的在上小的在下
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - (i + 1); j++)
			if (num[j] < num[j + 1]) {
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
	//将相同的数字合并
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N - 1; j++)
			if (num[i] == num[j]) {
				num[j] = -1;
				count[i]++;
			}
	//输出结果
	for (i = 0; i < N; i++)
		if (num[i] >= 0 && count[i] > 0)
			printf("%d %d\n", num[i], count[i]);

	return 0;
}