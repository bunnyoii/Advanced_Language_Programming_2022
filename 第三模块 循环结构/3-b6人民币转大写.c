/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	double a;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &a);
	a = a + 0.001;
	printf("��д�����:\n");
	int b = (int)a;
	int c = (int)(a / 1000000000) % 10;//ʮ��
	int d = (int)(a / 100000000) % 10;//��
	int e = (int)(a / 10000000) % 10;//ǧ��
	int f = (int)(a / 1000000) % 10;//����
	int g = (int)(a / 100000) % 10;//ʮ��
	int h = (int)(a / 10000) % 10;//��
	int i = (int)(a / 1000) % 10;//Ǫ
	int j = (int)(a / 100) % 10;//��
	int k = (int)(a / 10) % 10;//ʰ
	if (c > 0) {//����ʮ�ڲ���
		switch (c) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
		if (d == 0)
			printf("��");
	}
	if (d > 0) {//�����ڲ���
		switch (d) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}

	if ((e == 0 && (f != 0 || g != 0 || h != 0)) || (f == 0 && (g != 0 || h != 0)) || (g == 0 && h != 0))
		printf("��");
	if (e > 0) {//����Ǫ�򲿷�
		switch (e) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
	}
	if (f > 0) {//������򲿷�
		switch (f) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	if (g > 0) {//����ʰ�򲿷�
		switch (g) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}
	if (h > 0) {//�����򲿷�
		if (g == 0 && (c != 0 || d != 0 || e != 0 || f != 0) && h > 0)
			printf("��");
		switch (h) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else if (h == 0 && (/*c != 0 || d != 0 ||*/ e != 0 || f != 0 || g != 0))
		printf("��");

	if (((j > 0 && i == 0) || (k > 0 && (i == 0 || j == 0))) && (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0))
		printf("��");
	if (i > 0) {//����Ǫ����
		switch (i) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
	}
	if (j > 0) {//����۲���
		switch (j) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else if (j == 0 && i > 0 && k > 0)
		printf("��");
	if (k > 0) {//����ʰ����
		/*if (j == 0 && k > 0)
			cout << "��";*/
		switch (k) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}


	a = a / 10 - (int)(a / 10);//��λ
	int x = (int)(a * 1000);//����
	int y = x / 100 % 10;//Բ
	int z = x / 10 % 10;//��
	int p = x % 10;//��


	if (y > 0) {//����Բ����
		if (((j == 0 || k == 0) && (i != 0 || h != 0 || g != 0 || c != 0 || d != 0)) || (i != 0 && j == 0 && k == 0) || (j != 0 && k == 0))
			printf("��");
		switch (y) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Բ");
	}
	else if (y == 0 && ((z != 0 || p != 0) && (b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0)))
		printf("Բ");
	else if (y == 0 && ((z == 0 && p == 0) && (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0)))
		printf("��Բ");
	else if (y == 0 && ((z != 0 || p != 0) && (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0)))
		printf("��Բ");
	if (z > 0) {//����ǲ���
		switch (z) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else if (z == 0 && p == 0)
		printf("��");


	if (p > 0) {//����ֲ���
		if (z == 0 && p > 0)
			printf("��");
		switch (p) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	return 0;
}