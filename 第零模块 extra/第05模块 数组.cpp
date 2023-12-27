#include <iostream>
using namespace std;

const int matrix_row = 3, matrix_column = 4;

/***************************************************************************
  函数名称：fibonacci_array
  功    能：数组方式求Fibonacci数列的前20项
  输入参数：无
  返 回 值：无
  说    明：无
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
  函数名称：bubble_sort_ascending
  功    能：冒泡法排序（升序排列）
  输入参数：array[] ：数组
            length  ：数组长度
  返 回 值：无
  说    明：内外循环的关系：外循环 i = 0，内循环 j = 0~8，比较 9 次
         （以length=10为例）外循环 i = 1，内循环 j = 0~7，比较 8 次
                            外循环 i = 2，内循环 j = 0~6，比较 7 次
                            外循环 i = 3，内循环 j = 0~5，比较 6 次
                            外循环 i = 4，内循环 j = 0~4，比较 5 次
                            外循环 i = 5，内循环 j = 0~3，比较 4 次
                            外循环 i = 6，内循环 j = 0~2，比较 3 次
                            外循环 i = 7，内循环 j = 0~1，比较 2 次
                            外循环 i = 8，内循环 j = 0~0，比较 1 次
                            （数组长度为 N 时，外循环 N - 1 次）
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
  函数名称：bubble_sort_descending
  功    能：冒泡法排序（降序排列）
  输入参数：array[] ：数组
            length  ：数组长度
  返 回 值：无
  说    明：内外循环的关系：外循环 i = 0，内循环 j = 0~8，比较 9 次
         （以length=10为例）外循环 i = 1，内循环 j = 0~7，比较 8 次
                            外循环 i = 2，内循环 j = 0~6，比较 7 次
                            外循环 i = 3，内循环 j = 0~5，比较 6 次
                            外循环 i = 4，内循环 j = 0~4，比较 5 次
                            外循环 i = 5，内循环 j = 0~3，比较 4 次
                            外循环 i = 6，内循环 j = 0~2，比较 3 次
                            外循环 i = 7，内循环 j = 0~1，比较 2 次
                            外循环 i = 8，内循环 j = 0~0，比较 1 次
                            （数组长度为 N 时，外循环 N - 1 次）
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
  函数名称：select_sort_ascending
  功    能：选择法排序（升序排列）
  输入参数：array[] ：数组
            length  ：数组长度
  返 回 值：无
  说    明：内外循环的关系：外循环 i = 0，k = 0，内循环 j = 1~9，比较 9 次
         （以length=10为例）外循环 i = 1，k = 1，内循环 j = 2~9，比较 8 次
                            外循环 i = 2，k = 2，内循环 j = 3~9，比较 7 次
                            外循环 i = 3，k = 3，内循环 j = 4~9，比较 6 次
                            外循环 i = 4，k = 4，内循环 j = 5~9，比较 5 次
                            外循环 i = 5，k = 5，内循环 j = 6~9，比较 4 次
                            外循环 i = 6，k = 6，内循环 j = 7~9，比较 3 次
                            外循环 i = 7，k = 7，内循环 j = 8~9，比较 2 次
                            外循环 i = 8，k = 8，内循环 j = 9~9，比较 1 次
                            （数组长度为 N 时，外循环 N - 1 次）
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
  函数名称：select_sort_descending
  功    能：选择法排序（降序排列）
  输入参数：array[] ：数组
            length  ：数组长度
  返 回 值：无
  说    明：内外循环的关系：外循环 i = 0，k = 0，内循环 j = 1~9，比较 9 次
         （以length=10为例）外循环 i = 1，k = 1，内循环 j = 2~9，比较 8 次
                            外循环 i = 2，k = 2，内循环 j = 3~9，比较 7 次
                            外循环 i = 3，k = 3，内循环 j = 4~9，比较 6 次
                            外循环 i = 4，k = 4，内循环 j = 5~9，比较 5 次
                            外循环 i = 5，k = 5，内循环 j = 6~9，比较 4 次
                            外循环 i = 6，k = 6，内循环 j = 7~9，比较 3 次
                            外循环 i = 7，k = 7，内循环 j = 8~9，比较 2 次
                            外循环 i = 8，k = 8，内循环 j = 9~9，比较 1 次
                            （数组长度为 N 时，外循环 N - 1 次）
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
  函数名称：transpose_matrix
  功    能：输出转置矩阵
  输入参数：matrix_input[][matrix_column] ：矩阵
  返 回 值：无
  说    明：输入矩阵的行(matrix_row)和列(matrix_column)通过常变量定义
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
  函数名称：matrix_maximum_row_column_first
  功    能：输出矩阵中的最大值以及其所在的行和列
  输入参数：matrix[][matrix_column] ：矩阵
  返 回 值：无
  说    明：最大值如有相同，按先行后列取第一个
            输入矩阵的行(matrix_row)和列(matrix_column)通过常变量定义
***************************************************************************/
void matrix_maximum_row_column_first(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //初始认为最大值为matrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] > max) { //matrix[i][j] > max ：最大值如有相同，按先行后列取第一个
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "maximum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  函数名称：matrix_maximum_row_column_last
  功    能：输出矩阵中的最大值以及其所在的行和列
  输入参数：matrix[][matrix_column] ：矩阵
  返 回 值：无
  说    明：最大值如有相同，按先行后列取最后一个
            输入矩阵的行(matrix_row)和列(matrix_column)通过常变量定义
***************************************************************************/
void matrix_maximum_row_column_last(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //初始认为最大值为matrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] >= max) { //matrix[i][j] >= max ：最大值如有相同，按先行后列取最后一个
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "maximum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  函数名称：matrix_minimum_row_column_first
  功    能：输出矩阵中的最小值以及其所在的行和列
  输入参数：matrix[][matrix_column] ：矩阵
  返 回 值：无
  说    明：最小值如有相同，按先行后列取第一个
            输入矩阵的行(matrix_row)和列(matrix_column)通过常变量定义
***************************************************************************/
void matrix_minimum_row_column_first(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //初始认为最大值为matrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] < max) { //matrix[i][j] > max ：最大值如有相同，按先行后列取第一个
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "minimum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  函数名称：matrix_minimum_row_column_last
  功    能：输出矩阵中的最小值以及其所在的行和列
  输入参数：matrix[][matrix_column] ：矩阵
  返 回 值：无
  说    明：最小值如有相同，按先行后列取最后一个
            输入矩阵的行(matrix_row)和列(matrix_column)通过常变量定义
***************************************************************************/
void matrix_minimum_row_column_last(int matrix[][matrix_column])
{
    int row = 0, column = 0, max = matrix[0][0]; //初始认为最大值为matrix[0][0]
    for (int i = 0; i < matrix_row; i++)
        for (int j = 0; j < matrix_column; j++)
            if (matrix[i][j] <= max) { //matrix[i][j] >= max ：最大值如有相同，按先行后列取最后一个
                max = matrix[i][j];
                row = i;
                column = j;
            }
    cout << "minimum = " << max << " row = " << ++row << " column = " << ++column << endl;
}

/***************************************************************************
  函数名称：main
  功    能：主函数
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
    int array[] = { 3,7,9,0,4,6,1,2,8,5 };
    int matrix[matrix_row][matrix_column] = { {1,2,3,4},
                                              {5,6,7,8},
                                              {9,9,2,1} };

    return 0;
}