/* 2251730 ��07 ������ */
#include <iostream>
#include <iomanip>
using namespace std;

const char* sp = "=====================================";

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����ÿ�����ֿ��Ϊ8���Ҷ���
***************************************************************************/
template<typename T, int row, int col>
void matrix_print(const char* s1, T(&ary)[row][col])	//��...�滻Ϊ��Ӧ����
{
	cout << s1 << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(8) << ary[i][j];
		}
		cout << endl;
	}
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
template<typename T1, typename T2, typename T3, int row, int col>
void matrix_addition(T1(&dst)[row][col], T2(&src1)[row][col], T3(&src2)[row][col])	//��...�滻Ϊ��Ӧ����
{
	/* ������������ */
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dst[i][j] = src1[i][j] + src2[i][j];
	cout << "Դ����1 : ��=" << row << " ��=" << col << " ռ�ÿռ�=" << sizeof(src1) << "�ֽ�\n";
	cout << "Դ����2 : ��=" << row << " ��=" << col << " ռ�ÿռ�=" << sizeof(src2) << "�ֽ�\n";
	cout << "�;���  : ��=" << row << " ��=" << col << " ռ�ÿռ�=" << sizeof(dst) << "�ֽ�\n";
	return;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
template<typename T1, typename T2, typename T3, int row1, int col1, int row2, int col2, int row_dst, int col_dst>
void matrix_multiplication(T1(&dst)[row_dst][col_dst], T2(&src1)[row1][col1], T3(&src2)[row2][col2])	//��...�滻Ϊ��Ӧ����
{
	for (int i = 0; i < row1; i++)
		for (int j = 0; j < col2; j++) {
			dst[i][j] = 0;
			for (int k = 0; k < col1; k++)
				dst[i][j] += src1[i][k] * src2[k][j];
		}
	cout << "Դ����1 : ��=" << row1 << " ��=" << col1 << " ռ�ÿռ�=" << sizeof(src1) << "�ֽ�\n";
	cout << "Դ����2 : ��=" << row2 << " ��=" << col2 << " ռ�ÿռ�=" << sizeof(src2) << "�ֽ�\n";
	cout << "������  : ��=" << row_dst << " ��=" << col_dst << " ռ�ÿռ�=" << sizeof(dst) << "�ֽ�\n";
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼����
***************************************************************************/
int main()
{
	int t1[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int t2[3][4] = {
		{12,11,10,9},
		{8,7,6,5},
		{4,3,2,1}
	};
	int t3[4][2] = {
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8}
	};
	int t_add[3][4], t_mul[3][2];

	cout << sp << endl;
	matrix_print("�ӷ����㣬Դ����1��", t1);
	matrix_print("�ӷ����㣬Դ����2��", t2);
	matrix_addition(t_add, t1, t2);	//��t1��t2�ĺͷ���t_add�У��˹���֤������������һ��
	matrix_print("�ӷ����㣬�;��� ��", t_add);
	cout << sp << endl;
	matrix_print("�˷����㣬Դ����1��", t1);
	matrix_print("�˷����㣬Դ����2��", t3);
	matrix_multiplication(t_mul, t1, t3);	//��t1��t2�ĺͷ���t_add�У��˹���֤������������һ��
	matrix_print("�˷����㣬������ ��", t_mul);
	cout << sp << endl;

	double d1[2][4] = {
		{1.1, 2.2, 3.3, 4.4},
		{5.5 ,6.6, 7.7, 8.8}
	};
	double d2[2][4] = {
		{8.8, 7.7, 6.6, 5.5},
		{4.4, 3.3, 2.2, 1.1}
	};
	double d_add[2][4];
	/* ��Ҫ��Ϊʲô����˷��������Ͳ�ͬ������� */
	float f3[4][3] = {
		{12.12f, 11.11f, 10.10f},
		{9.9f, 8.8f, 7.7f},
		{6.6f, 5.5f, 4.4f},
		{3.3f, 2.2f, 1.1f}
	};
	int i_mul[2][3];

	matrix_print("�ӷ����㣬Դ����1��", d1);
	matrix_print("�ӷ����㣬Դ����2��", d2);
	matrix_addition(d_add, d1, d2);	//��d1��d2�ĺͷ���d_add�У��˹���֤������������һ��
	matrix_print("�ӷ����㣬�;��� ��", d_add);
	cout << sp << endl;
	matrix_print("�˷����㣬Դ����1��", d1);
	matrix_print("�˷����㣬Դ����2��", f3);
	matrix_multiplication(i_mul, d1, f3);	//��t1��t2�ĺͷ���t_add�У��˹���֤������������һ��
	matrix_print("�˷����㣬������ ��", i_mul);
	cout << sp << endl;

	return 0;
}