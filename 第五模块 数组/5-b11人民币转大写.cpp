/* 2251730 ��07 ������*/
#include <iostream>
#include <cstring>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */


void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)
			result = result + chnstr[0] + chnstr[1];
		break;
	case 1:
		result = result + chnstr[2] + chnstr[3];
		break;
	case 2:
		result = result + chnstr[4] + chnstr[5];
		break;
	case 3:
		result = result + chnstr[6] + chnstr[7];
		break;
	case 4:
		result = result + chnstr[8] + chnstr[9];
		break;
	case 5:
		result = result + chnstr[10] + chnstr[11];
		break;
	case 6:
		result = result + chnstr[12] + chnstr[13];
		break;
	case 7:
		result = result + chnstr[14] + chnstr[15];
		break;
	case 8:
		result = result + chnstr[16] + chnstr[17];
		break;
	case 9:
		result = result + chnstr[18] + chnstr[19];
		break;
	default:
		cout << "error";
		break;
	}
}

int main()
{
	double a;
	while (1) {
		cout << "������[0-100��)֮�������:" << endl;
		cin >> a;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (a >= 0 && a < 10000000000)
			break;
	}
	a = a + 0.001;
	cout << "��д�����:" << endl;
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
	a = a / 10 - (int)(a / 10);//��λ
	int x = (int)(a * 1000);//����
	int y = x / 100 % 10;//Բ
	int z = x / 10 % 10;//��
	int p = x % 10;//��

	daxie(c, 0);
	if (c > 0)
		result = result + "ʰ";
	daxie(d, 0);
	if (c > 0 || d > 0)
		result = result + "��";

	if (c > 0 || d > 0)
		daxie(e, f);
	else
		daxie(e, 0);
	if (e > 0)
		result = result + "Ǫ";
	if (c > 0 || d > 0 || e > 0)
		daxie(f, g);
	else
		daxie(f, 0);
	if (f > 0)
		result = result + "��";
	if (c > 0 || d > 0 || e > 0 || f > 0)
		daxie(g, h);
	else
		daxie(g, 0);
	if (g > 0)
		result = result + "ʰ";
	daxie(h, 0);
	if (e > 0 || f > 0 || g > 0 || h > 0)
		result = result + "��";

	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0)
		daxie(i, j);
	else
		daxie(i, 0);
	if (i > 0)
		result = result + "Ǫ";
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0)
		daxie(j, k);
	else
		daxie(j, 0);
	if (j > 0)
		result = result + "��";
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0)
		daxie(k, y);
	else
		daxie(k, 0);
	if (k > 0)
		result = result + "ʰ";

	if (c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && z == 0 && p == 0) {
		daxie(y, 1);
		result = result + "Բ";
	}
	else if (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || y != 0)
	{
		daxie(y, 0);
		result = result + "Բ";
	}
	if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0)
		daxie(z, p);
	else
		daxie(z, 0);
	if (z > 0)
		result = result + "��";
	if (p == 0)
		result = result + "��";
	if (p > 0) {
		if (c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0 || y > 0 || z > 0)
			daxie(p, 1);
		else
			daxie(p, 0);
		result = result + "��";
	}
	cout << result << endl;

	return 0;
}
