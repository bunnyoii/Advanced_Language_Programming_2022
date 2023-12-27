#include <iostream>
using namespace std;

const int matrix_row = 3, matrix_column = 4;

/***************************************************************************
  �������ƣ�fibonacci_array
  ��    �ܣ����鷽ʽ��Fibonacci���е�ǰ20��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void fibonacci_array()
{
    int fibonacci[20] = { 1,1 };
    for (int i = 2; i < 20; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    for (int i = 0; i < 20; i++)
        cout << fibonacci[i] << " ";
}

/***************************************************************************
  �������ƣ�bubble_sort_ascending
  ��    �ܣ�ð�ݷ������������У�
  ���������array[] ������
            length  �����鳤��
  �� �� ֵ����
  ˵    ��������ѭ���Ĺ�ϵ����ѭ�� i = 0����ѭ�� j = 0~8���Ƚ� 9 ��
         ����length=10Ϊ������ѭ�� i = 1����ѭ�� j = 0~7���Ƚ� 8 ��
                            ��ѭ�� i = 2����ѭ�� j = 0~6���Ƚ� 7 ��
                            ��ѭ�� i = 3����ѭ�� j = 0~5���Ƚ� 6 ��
                            ��ѭ�� i = 4����ѭ�� j = 0~4���Ƚ� 5 ��
                            ��ѭ�� i = 5����ѭ�� j = 0~3���Ƚ� 4 ��
                            ��ѭ�� i = 6����ѭ�� j = 0~2���Ƚ� 3 ��
                            ��ѭ�� i = 7����ѭ�� j = 0~1���Ƚ� 2 ��
                            ��ѭ�� i = 8����ѭ�� j = 0~0���Ƚ� 1 ��
                            �����鳤��Ϊ N ʱ����ѭ�� N - 1 �Σ�
***************************************************************************/
void bubble_sort_ascending(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - (i + 1); j++)
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

/***************************************************************************
  �������ƣ�bubble_sort_descending
  ��    �ܣ�ð�ݷ����򣨽������У�
  ���������array[] ������
            length  �����鳤��
  �� �� ֵ����
  ˵    ��������ѭ���Ĺ�ϵ����ѭ�� i = 0����ѭ�� j = 0~8���Ƚ� 9 ��
         ����length=10Ϊ������ѭ�� i = 1����ѭ�� j = 0~7���Ƚ� 8 ��
                            ��ѭ�� i = 2����ѭ�� j = 0~6���Ƚ� 7 ��
                            ��ѭ�� i = 3����ѭ�� j = 0~5���Ƚ� 6 ��
                            ��ѭ�� i = 4����ѭ�� j = 0~4���Ƚ� 5 ��
                            ��ѭ�� i = 5����ѭ�� j = 0~3���Ƚ� 4 ��
                            ��ѭ�� i = 6����ѭ�� j = 0~2���Ƚ� 3 ��
                            ��ѭ�� i = 7����ѭ�� j = 0~1���Ƚ� 2 ��
                            ��ѭ�� i = 8����ѭ�� j = 0~0���Ƚ� 1 ��
                            �����鳤��Ϊ N ʱ����ѭ�� N - 1 �Σ�
***************************************************************************/
void bubble_sort_descending(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - (i + 1); j++)
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

/***************************************************************************
  �������ƣ�select_sort_ascending
  ��    �ܣ�ѡ�������������У�
  ���������array[] ������
            length  �����鳤��
  �� �� ֵ����
  ˵    ��������ѭ���Ĺ�ϵ����ѭ�� i = 0��k = 0����ѭ�� j = 1~9���Ƚ� 9 ��
         ����length=10Ϊ������ѭ�� i = 1��k = 1����ѭ�� j = 2~9���Ƚ� 8 ��
                            ��ѭ�� i = 2��k = 2����ѭ�� j = 3~9���Ƚ� 7 ��
                            ��ѭ�� i = 3��k = 3����ѭ�� j = 4~9���Ƚ� 6 ��
                            ��ѭ�� i = 4��k = 4����ѭ�� j = 5~9���Ƚ� 5 ��
                            ��ѭ�� i = 5��k = 5����ѭ�� j = 6~9���Ƚ� 4 ��
                            ��ѭ�� i = 6��k = 6����ѭ�� j = 7~9���Ƚ� 3 ��
                            ��ѭ�� i = 7��k = 7����ѭ�� j = 8~9���Ƚ� 2 ��
                            ��ѭ�� i = 8��k = 8����ѭ�� j = 9~9���Ƚ� 1 ��
                            �����鳤��Ϊ N ʱ����ѭ�� N - 1 �Σ�
***************************************************************************/
void select_sort_ascending(int array[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        int k = i;
        for (int j = i + 1; j < length; j++)
            if (array[j] < array[k])
                k = j;
        int temp = array[k];
        array[k] = array[i];
        array[i] = temp;
    }
}

/***************************************************************************
  �������ƣ�select_sort_descending
  ��    �ܣ�ѡ�����򣨽������У�
  ���������array[] ������
            length  �����鳤��
  �� �� ֵ����
  ˵    ��������ѭ���Ĺ�ϵ����ѭ�� i = 0��k = 0����ѭ�� j = 1~9���Ƚ� 9 ��
         ����length=10Ϊ������ѭ�� i = 1��k = 1����ѭ�� j = 2~9���Ƚ� 8 ��
                            ��ѭ�� i = 2��k = 2����ѭ�� j = 3~9���Ƚ� 7 ��
                            ��ѭ�� i = 3��k = 3����ѭ�� j = 4~9���Ƚ� 6 ��
                            ��ѭ�� i = 4��k = 4����ѭ�� j = 5~9���Ƚ� 5 ��
                            ��ѭ�� i = 5��k = 5����ѭ�� j = 6~9���Ƚ� 4 ��
                            ��ѭ�� i = 6��k = 6����ѭ�� j = 7~9���Ƚ� 3 ��
                            ��ѭ�� i = 7��k = 7����ѭ�� j = 8~9���Ƚ� 2 ��
                            ��ѭ�� i = 8��k = 8����ѭ�� j = 9~9���Ƚ� 1 ��
                            �����鳤��Ϊ N ʱ����ѭ�� N - 1 �Σ�
***************************************************************************/
void select_sort_descending(int array[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        int k = i;
        for (int j = i + 1; j < length; j++)
            if (array[j] > array[k])
                k = j;
        int temp = array[k];
        array[k] = array[i];
        array[i] = temp;
    }
}

/***************************************************************************
  �������ƣ�transpose_matrix
  ��    �ܣ����ת�þ���
  ���������matrix_input[][matrix_column] ������
  �� �� ֵ����
  ˵    ��������������(matrix_row)����(matrix_column)ͨ������������
***************************************************************************/
void transpose_matrix(int matrix_input[][matrix_column])
{
    int matrix_output[matrix_column][matrix_row];
    cout << "Matrix_Input:" << endl;
    for (int i = 0; i < matrix_row; i++) {
        for (int j = 0; j < matrix_column; j++)
            cout << matrix_input[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            matrix_output[j][i] = matrix_input[i][j];
    cout << "Matrix_Output:" << endl;
    for (int i = 0; i < matrix_column; i++) {
        for (int j = 0; j < matrix_row; j++)
            cout << matrix_output[i][j] << " ";
        cout << endl;
    }
}

/***************************************************************************
  �������ƣ�matrix_maximum_row_column_first
  ��    �ܣ���������е����ֵ�Լ������ڵ��к���
  ���������matrix[][matrix_column] ������
  �� �� ֵ����
  ˵    �������ֵ������ͬ�������к���ȡ��һ��
            ����������(matrix_row)����(matrix_column)ͨ������������
***************************************************************************/
void matrix_maximum_row_column_first(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //��ʼ��Ϊ���ֵΪmatrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] > max) { //matrix[i][j] > max �����ֵ������ͬ�������к���ȡ��һ��
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "maximum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  �������ƣ�matrix_maximum_row_column_last
  ��    �ܣ���������е����ֵ�Լ������ڵ��к���
  ���������matrix[][matrix_column] ������
  �� �� ֵ����
  ˵    �������ֵ������ͬ�������к���ȡ���һ��
            ����������(matrix_row)����(matrix_column)ͨ������������
***************************************************************************/
void matrix_maximum_row_column_last(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //��ʼ��Ϊ���ֵΪmatrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] >= max) { //matrix[i][j] >= max �����ֵ������ͬ�������к���ȡ���һ��
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "maximum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  �������ƣ�matrix_minimum_row_column_first
  ��    �ܣ���������е���Сֵ�Լ������ڵ��к���
  ���������matrix[][matrix_column] ������
  �� �� ֵ����
  ˵    ������Сֵ������ͬ�������к���ȡ��һ��
            ����������(matrix_row)����(matrix_column)ͨ������������
***************************************************************************/
void matrix_minimum_row_column_first(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //��ʼ��Ϊ���ֵΪmatrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] < max) { //matrix[i][j] > max �����ֵ������ͬ�������к���ȡ��һ��
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "minimum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  �������ƣ�matrix_minimum_row_column_last
  ��    �ܣ���������е���Сֵ�Լ������ڵ��к���
  ���������matrix[][matrix_column] ������
  �� �� ֵ����
  ˵    ������Сֵ������ͬ�������к���ȡ���һ��
            ����������(matrix_row)����(matrix_column)ͨ������������
***************************************************************************/
void matrix_minimum_row_column_last(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //��ʼ��Ϊ���ֵΪmatrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] <= max) { //matrix[i][j] >= max �����ֵ������ͬ�������к���ȡ���һ��
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "minimum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�������
  �����������
  �� �� ֵ��0
  ˵    ������
***************************************************************************/
int main()
{
    int array[] = { 3,7,9,0,4,6,1,2,8,5 };
    int matrix[matrix_row][matrix_column] = { {1,2,3,4},
                                              {5,6,7,8},
                                              {9,9,2,1} };

    return 0;
}