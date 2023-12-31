#include <iostream>
#include <conio.h>
using namespace std;

/***************************************************************************
  函数名称：is_power
  功    能：判断是否为幂
  输入参数：num  ：整数
			base ：基数
  返 回 值：0 - 整数不是基数的幂
			1 - 整数是基数的幂
  说    明：无
***************************************************************************/
int is_power(int num, int base)
{
	if (num == 1)
		return 1;
	else if (num > 1 && num % base == 0)
		return is_power(num / base, base);
	else
		return 0;
}

/***************************************************************************
  函数名称：my_sqrt
  功    能：迭代法求解算术平方根
  输入参数：a ：浮点数
  返 回 值：浮点数的算术平方根
  说    明：无
***************************************************************************/
double my_sqrt(double a)
{
	double s, b = a;
	s = (b + a / b) / 2;
	while (fabs(b - s) >= 1e-5)
	{
		b = s;
		s = (s + a / s) / 2;
	}
	return s;
}

/***************************************************************************
  函数名称：fibonacci
  功    能：返回Fibonacci数列第n项的值
  输入参数：n ：正整数
  返 回 值：Fibonacci数列第n项的值
  说    明：无
***************************************************************************/
int fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

/***************************************************************************
  函数名称：legendre
  功    能：返回Legendre多项式的值
  输入参数：x ：浮点数
			n ：正整数
  返 回 值：Legendre多项式的值
  说    明：无
***************************************************************************/
double legendre(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else
		return ((2 * n - 1) * x * legendre(x, n - 1) - (n - 1) * legendre(x, n - 2)) / n;
}

/***************************************************************************
  函数名称：sum_of_square
  功    能：返回Sigma(n^2)的值
  输入参数：n ：正整数
  返 回 值：Sigma(n^2)的值
  说    明：无
***************************************************************************/
int sum_of_square(int n)
{
	if (n == 1)
		return 1;
	else
		return sum_of_square(n - 1) + n * n;
}

/***************************************************************************
  函数名称：prime
  功    能：判断某正整数是否是素数
  输入参数：n ：正整数
  返 回 值：0 - 该正整数不是素数
			1 - 该正整数是素数
  说    明：无
***************************************************************************/
int prime(int n)
{
	int i, k = int(sqrt(n));
	for (i = 2; i <= k; i++)
		if (n % i == 0)
			break;
	return i <= k ? 0 : 1;
}

/***************************************************************************
  函数名称：gotbaha
  功    能：验证哥德巴赫猜想
  输入参数：even ：正整数
  返 回 值：无
  说    明：本函数需要用到判断某正整数是否是素数的函数prime
***************************************************************************/
void gotbaha(int even)
{
	int n;
	for (n = 3; n <= even / 2; n += 2)
		if (prime(n) + prime(even - n) == 2) {
			cout << n << "+" << even - n << "=" << even << endl;
			/* 此处添加break语句可以只列举一种情况 */
		}
}

/***************************************************************************
  函数名称：fac_forLoop
  功    能：非递归法求解n!(n的阶乘)
  输入参数：n ：非负整数
  返 回 值：n!(n的阶乘)
  说    明：无
***************************************************************************/
int fac_forLoop(int n)
{
	int s = 1, i;
	for (i = 0; i < n; i++)
		s *= i;
	return s;
}

/***************************************************************************
  函数名称：fac_recursion
  功    能：递归法求解n!(n的阶乘)
  输入参数：n ：非负整数
  返 回 值：n!(n的阶乘)
  说    明：无
***************************************************************************/
int fac_recursion(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fac_recursion(n - 1) * n;
}

/***************************************************************************
  函数名称：positionalNotation_conversion
  功    能：实现从十进制到二进制和从十进制到八进制的转换
  输入参数：n                  ：十进制整数
			positionalNotation ：2 - 十进制转换为二进制
								 8 - 十进制转换为八进制
  返 回 值：无
  说    明：无
***************************************************************************/
void positionalNotation_conversion(int n, int positionalNotation)
{
	if (n >= positionalNotation)
		positionalNotation_conversion(n / positionalNotation, positionalNotation);
	cout << n % positionalNotation;
}

/***************************************************************************
  函数名称：convert_positive
  功    能：整数正序分解并以字符方式输出(输出负号)
  输入参数：n ：整数
  返 回 值：无
  说    明：无
***************************************************************************/
void convert_positive(int n)
{
	if (n < 0)
		cout << "- ";
	if (n >= 10)
		convert_positive(n / 10);
	else if (n <= -10)
		convert_positive(n / -10);
	else
		;
	if (n >= 0)
		cout << char(48 + n % 10) << " ";
	else
		cout << char(48 - (n % 10)) << " ";
}

/***************************************************************************
  函数名称：convert_reverse
  功    能：整数逆序分解并以字符方式输出(输出负号)
  输入参数：n ：整数
  返 回 值：无
  说    明：无
***************************************************************************/
void convert_reverse(int n)
{
	if (n >= 0)
		cout << char(48 + n % 10) << " ";
	else
		cout << char(48 - (n % 10)) << " ";
	if (n >= 10)
		convert_reverse(n / 10);
	else if (n <= -10)
		convert_reverse(n / -10);
	else
		;
	if (n < 0)
		cout << "- ";
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
	//伪随机数的生成

	/*	srand函数的功能：生成伪随机数的种子										*/
	/*	    只需在程序开始时执行一次即可										*/
	/*																			*/
	/*	rand函数的功能：生成一个伪随机数										*/
	/*	    VS下会得到一个0-32767间的int型数据(其他编译器可能不是这个数据范围)	*/

	srand((unsigned int)(time(0))); //反复运行伪随机数改变
	srand(1);						//srand()函数中的参数改变伪随机数改变，反复运行伪随机数不变

	//局部变量
	
	/*	含义：在函数内部定义，只在本函数范围内有效(可访问)的变量	*/
	/*	使用：(1)不同函数内的局部变量可以同名						*/
	/*		  (2)形参等同于局部变量									*/
	/*		  (3)复合语句内的变量，只在复合语句中有效(包括循环)		*/
	/*		  (4)在该函数的被调用函数内也无效(不可访问)				*/

	//全局变量

	/*	含义：在函数体外定义，被多个函数所共用的变量							*/
	/*	使用：(1)从定义点到源文件结束之间的所有函数均可使用						*/
	/*			 (递归函数中的局部变量/形参只能在本层被访问)					*/
	/*		  (2)全局变量在某个函数中被改变后，其他函数再访问则得到改变后的结果	*/
	/*			 (全局变量不在某函数被调用时被保存的"现场栈"中)					*/
	/*			 (递归函数的各层均可以访问同一全局变量)							*/
	/*		  (3)在使用全局变量时应加以限制，提高程序的通用性和可靠性			*/
	/*		  (4)若全局变量与局部变量同名，按"低层屏蔽高层"的原则处理			*/

	//无回显读入单个字符

	while (1) {
		char ch = _getch();
		if (ch == 0 || ch == -32)
			ch = _getch();
		else if (ch >= 33 && ch <= 126)
			cout << ch << endl;
		else
			continue;
	}

	return 0;
}