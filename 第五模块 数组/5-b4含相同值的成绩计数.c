//2251730 ��07 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 1001
int main()
{
	int num[N] = { 0 }, count[N] = { 0 };
	int i, j, t;
	printf("������ɼ������1000������������������\n");
	//��num����ȫ���ø�
	for (i = 0; i < N; i++)
		num[i] = -1;
	//��������
	for (i = 0; i < N - 1; i++) {
		scanf("%d", &num[i]);
		count[i]++;
		if (num[0] < 0) {
			printf("����Ч����\n");
			return 0;
		}
		else {
			if (num[i] < 0)
				break;
		}
	}
	while (getchar() != '\n')
		;
	//��ӡ��������飨ʮ��һ�У�
	printf("���������Ϊ:\n");
	for (i = 0; i < N; i++) {
		if (num[i] >= 0) {
			printf("%d ", num[i]);
			if ((i + 1) % 10 == 0 && num[i + 1] >= 0)
				printf("\n");
		}
	}
	printf("\n");

	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	//ð�����򣬴������С������
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - (i + 1); j++)
			if (num[j] < num[j + 1]) {
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
	//����ͬ�����ֺϲ�
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N - 1; j++)
			if (num[i] == num[j]) {
				num[j] = -1;
				count[i]++;
			}
	//������
	for (i = 0; i < N; i++)
		if (num[i] >= 0 && count[i] > 0)
			printf("%d %d\n", num[i], count[i]);

	return 0;
}