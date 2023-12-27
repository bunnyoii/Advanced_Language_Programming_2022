/* 2251730 ��07 ������*/
#include <iostream>
using namespace std;

const int ROW = 2;
const int COL = 3;

#define OPERATOR_IS_MENBER_FUNCTION		0	//������������ó�Ա������ʽʵ�֣����ֵΪ0����ʾ����Ԫ��ʽʵ�֣�

class matrix {
private:
	int value[ROW][COL];
	//����֮�ⲻ������������ݳ�Ա
public:
	matrix(const int(*p)[COL]);	//���캯�����������ʼ������

#if OPERATOR_IS_MENBER_FUNCTION
	//����+�ĳ�Ա����ʵ�ַ�ʽ������
	matrix operator+(matrix& a);
#else
	//����+����Ԫ����ʵ�ַ�ʽ������
#endif
	/* ----������Ҫ���������Ա�����Ķ������Ԫ��������������������---- */
	matrix();
	friend istream& operator>>(istream& in, matrix& A);
	friend ostream& operator<<(ostream& out, matrix& A);
	friend matrix operator+(matrix& a, matrix& b);
};

/* ---- ������Ա����������ʵ��/��Ԫ������ʵ�֣�����+��ʵ���г�Ա����Ԫ������ʽ��Ҫ����������Ԥ������ ---- */

#if OPERATOR_IS_MENBER_FUNCTION
//����+�ĳ�Ա������ʽ������ʵ��
matrix matrix::operator+(matrix& a)
{
	matrix b;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			b.value[i][j] = a.value[i][j] + value[i][j];
		}
	return b;
}
#else
//����+����Ԫ������ʽ������ʵ��
matrix operator+(matrix& a, matrix& b) {
	matrix ret;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			ret.value[i][j] = a.value[i][j] + b.value[i][j];
		}
	return ret;
}

#endif
istream& operator >>(istream& in, matrix& A)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			in >> A.value[i][j];
	return in;
}

ostream& operator <<(ostream& out, matrix& A)
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
			out << A.value[i][j] << " ";
		cout << endl;
	}
	return out;
}


matrix::matrix(const int(*p)[COL]) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			value[i][j] = p[i][j];
}

matrix::matrix() {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			value[i][j] = 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int a[ROW][COL] = { { 1,2,3 },{ 4,5,6 } };
	int b[ROW][COL] = { { 2,4,6 },{ 3,6,9 } };
	matrix m1(a), m2(b), m3; //m3�ĳ�ֵΪȫ0

	/* ����Ϊ��ֵ���� */
	cout << "��ʼ����m1��ֵ" << endl;
	cout << m1 << endl;
	cout << "��ʼ����m2��ֵ" << endl;
	cout << m2 << endl;

	m3 = m1 + m2;
	cout << "��Ӻ����m3��ֵ" << endl;
	cout << m3 << endl;

	cout << "------------------" << endl;

	/* ����Ϊ����������� */
	cout << "�������ʼ����m1" << endl;
	cin >> m1;
	cout << "�������ʼ����m2" << endl;
	cin >> m2;

	cout << "��ʼ����m1��ֵ" << endl;
	cout << m1 << endl;
	cout << "��ʼ����m2��ֵ" << endl;
	cout << m2 << endl;
	cout << "��Ӻ����m3��ֵ" << endl;
	cout << (m3 = m1 + m2) << endl;

	return 0;
}
