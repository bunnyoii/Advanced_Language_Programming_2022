//2251730 ��07 ������
#include<iostream>
using namespace std;
const int N = 1000;
int main()
{
	int num[N] = { 0 }, count[N] = { 0 };
	int i, j, t;
	cout << "������ɼ������1000������������������" << endl;
	//��num����ȫ���ø�
	for (i = 0; i < N; i++)
		num[i] = -1;
	//��������
	for (i = 0; i < N; i++) {
		cin >> num[i];
		if (num[0] < 0) {
			cout << "����Ч����" << endl;
			return 0;
		}
		else {
			if (num[i] < 0)
				break;
		}
	}

	//��ӡ��������飨ʮ��һ�У�
	cout << "���������Ϊ:" << endl;
	for (i = 0; i < N; i++) {
		if (num[i] >= 0) {
			cout << num[i] << ' ';
			if ((i + 1) % 10 == 0 && num[i + 1] >= 0 && i + 1 < N)
				cout << endl;
		}
	}
	cout << endl;

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	//ð�����򣬴������С������
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - (i + 1); j++)
			if (num[j] < num[j + 1]) {
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
	//�ϲ���ͬ����
	for (i = 0; i < N - 1; i++) {
		count[i] = i + 1;
		for (j = 1; j < N; j++)
			if (num[j] == num[j - 1])
				count[j] = count[j - 1];
	}
	//������
	for (i = 0; i < N; i++)
		if (num[i] >= 0)
			cout << num[i] << ' ' << count[i] << endl;

	return 0;
}