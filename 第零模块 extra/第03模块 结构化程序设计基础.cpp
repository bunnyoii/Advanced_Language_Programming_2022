#include <stdio.h>
#include <iostream>
#include <limits>
#include <conio.h> //_getch()/_getche()用到的头文件
using namespace std;

int main()
{
	int x;

	//C++方式cin输入错误处理

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;
		if (cin.fail()) { //或 !cin / !cin.good()
			cin.clear();  //清除内部错误状态标记位
			/* 方式1：清除缓冲区中字符，到'\n'为止，最大65536(可改) */
			cin.ignore(65536, '\n');
			/* 方式2：#include <limits>: INT_MAX */
			cin.ignore(INT_MAX, '\n');
			/* 方式3：numeric_limits<streamsize>::max(): 返回流缓冲区的最大容量 */
			/*        VS ：64位整数时直接可用，当 #include <Windows.h> 时不可用 */
			/*        Dev：32位整数且 #include <limits> 时可用                  */
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误" << endl;
			cout << "请重新输入" << endl;
			continue;
		}
		else if (x >= 0 && x <= 100) {
			cout << "输入正确且满足条件" << endl;
			break;
		}
		else {
			cout << "输入正确但不满足条件" << endl;
			cout << "请重新输入" << endl;
			continue;
		}
	}
	cout << "您输入的值为" << x << endl;

	//C方式scanf输入错误处理

	while (1) {
		printf("请输入x的值[0-100] : ");
		if (scanf("%d", &x) != 1) {
			while (getchar() != '\n')
				continue;
			printf("输入错误\n");
			printf("请重新输入\n");
			continue;
		}
		else if (x >= 0 && x <= 100) {
			printf("输入正确且满足条件\n");
			break;
		}
		else {
			printf("输入正确但不满足条件\n");
			printf("请重新输入\n");
			continue;
		}
	}
	printf("您输入的值为%d\n", x);

	//字符输出函数putchar

	/*	功能：输出一个字符									*/
	/*	putchar返回值可赋值给字符型/整型变量				*/
	/*	putchar返回值的数据类型为int型，是输出字符的ASCII码	*/

	char ch = 'A';
	putchar(ch);
	putchar('A');
	putchar('\x41');
	putchar('\101');
	cout << endl;

	char ret1;
	int ret2;								//优先级问题：
	cout << (ret1 = putchar('A')) << endl;	//执行putchar函数输出一个字符→执行赋值→执行cout语句
	cout << (ret2 = putchar('B')) << endl;	//执行putchar函数输出一个字符→执行赋值→执行cout语句
	cout << putchar('A') << endl;			//执行putchar函数输出一个字符→执行cout语句

	cout << "putchar()返回值的数据类型为：" << typeid(putchar('A')).name() << endl; //putchar返回值是int型（输出字符的ASCII码）

	//字符输入函数getchar

	/*	功能：给指定的变量输入一个字符																						*/
	/*	getchar返回值可赋值给字符型/整型变量																				*/
	/*	getchar返回值的数据类型为int型，是输入字符的ASCII码																	*/
	/*		因为除了正常的256个ASCII字符（含基本和扩展ASCII码、中文、其它语言文字等），										*/
	/*		还需要额外考虑一个输入出错情况下的返回，因此无法用1字节返回值													*/
	/*																														*/
	/*	输入时有回显，输入后需按回车结束输入（若直接按回车则得到回车的ASCII码）												*/
	/*	可以输入空格、回车等cin无法处理的非图形字符，但仍不能处理转义符														*/
	/*	调试程序时，可以用getchar()来延迟结束																				*/
	/*																														*/
	/*	cin和getchar的区别：																								*/
	/*		cin是按格式读入，到空格、回车、非法为止；getchar是只读一个字符													*/
	/*																														*/
	/*	cin和getchar的共同点：																								*/
	/*		都有输入缓冲区，输入必须以回车结束，每次仅从输入缓冲区中取需要的字节，多余的字节仍保留在输入缓冲区中供下次读取	*/
	/*		（如果程序结束，则操作系统会清空输入缓冲区）																	*/

	char ch1, ch2;
	ch1 = getchar();
	cout << ch1 << endl;
	while (getchar() != '\n'); //避免读取输入缓冲区中的空格
	cout << (ch2 = getchar()) << endl;

	cout << "getchar()返回值的数据类型为：" << typeid(getchar()).name() << endl; //getchar返回值是int型（输入字符的ASCII码）

	//字符输入函数_getch与_getche

	/*	_getche()/_getch()是没有输入缓冲区的，输入后不需要按回车键	*/
	/*																*/
	/*	几个字符输入函数的差别：									*/
	/*		getchar：有回显，不立即生效，需要回车键					*/
	/*		_getch ：无回显，立即生效，不需要回车键					*/
	/*		_getche：有回显，立即生效，不需要回车键					*/
	/*																*/
	/*	在Dev C++中：												*/
	/*		getch() ：_getch()										*/
	/*		getche()：_getche()										*/

	char ch3, ch4;
	ch3 = _getch();
	cout << int(ch3) << endl;
	ch4 = _getche();
	cout << int(ch4) << endl;

	//实数参与关系运算时要考虑误差

	/*	在不了解IEEE754的情况下，避免误差的通用方法：							*/
	/*		fabs是求绝对值的系统函数，当两数相减的绝对值小于某个值则认为相等	*/
	/*																			*/
	/*	用==判断实型数是否相等，某些情况下可能与预期结果不符合，因此禁用		*/
	/*																			*/
	/*	fabs函数是通用的保证实型数误差方法，但是使用时不要超过有效位数限定		*/

	float f1 = 100.25, f2 = 1234567.7654321;
	cout << (f1 - 100.25) << endl;
	cout << (f1 == 100.25) << endl;
	cout << (f2 - 1234567.7654321) << endl;
	cout << (f2 == 1234567.7654321) << endl;
	cout << (fabs(f1 - 100.25) < 1e-6) << endl;
	cout << (fabs(f2 - 1234567.7654321) < 1e-1) << endl;
	cout << (fabs(f2 - 1234567.7654321) < 1e-2) << endl;

	double f3 = 123.456789012345678;
	double f4 = 123.456789123456789;
	cout << (f3 == f4) << endl;
	cout << (fabs(f3 - f4) < 1e-6) << endl;
	cout << (fabs(f3 - f4) < 1e-7) << endl;

	//逻辑常量和逻辑变量（C++特有）

	/*	逻辑常量：true / false									*/
	/*	逻辑变量：bool 变量名									*/
	/*															*/
	/*		1.逻辑变量表示为整型值，取值只有0/1					*/
	/*		2.cin时只能输入0/1，输出时按整型量进行处理			*/
	/*		3.赋值及运算时，按“非零为真零为假”的原则进行		*/
	/*		4.可按整型值0/1参与表达式的运算						*/
	/*		5.C方式加stdbool.h头文件后，可以使用bool/true/false	*/

	cout << typeid(bool).name() << endl;
	cout << "bool型逻辑变量所占的字节为：" << sizeof(bool) << endl;
	cout << sizeof(true) << endl;
	cout << sizeof(false) << endl;

	/*	bool赋值时不是多字节赋少字节的规则，而是“非零为真零为假”	*/

	bool b;
	b = 123;
	cout << b << " " << int(b) << endl;
	b = 0;
	cout << b << " " << int(b) << endl;
	b = 256;
	cout << b << " " << int(b) << endl;

	//条件运算符和条件表达式

	/*	形式：表达式1 ? 表达式2 : 表达式3										*/
	/*																			*/
	/*	表达式1按逻辑值求解，若为真，求解表达式2并使整个表达式的值为表达式2的值	*/
	/*						 若为否，求解表达式3并使整个表达式的值为表达式3的值	*/
	/*																			*/
	/*	表达式1、2、3的类型可以不同，但表达式2、3的类型必须相容					*/

	//switch语句

	/*	形式：															*/
	/*		switch(整型表达式){											*/
	/*			case 整型常量表达式1:									*/
	/*				语句序列1;											*/
	/*			case 整型常量表达式2:									*/
	/*				语句序列2;											*/
	/*			...														*/
	/*			case 整型常量表达式n:									*/
	/*				语句序列n;											*/
	/*			default:												*/
	/*				语句序列n+1;										*/
	/*		}															*/
	/*																	*/
	/*	使用：															*/
	/*		1.表达式可以是任何类型，最终取值为整型即可					*/
	/*		2.各整型常量表达式的值应各不相同，但顺序无要求				*/
	/*		3.各语句序列的最后一句应是break，否则连续执行下一case语句	*/
	/*		4.语句序列不必加{}											*/
	/*		5.多个case可以共用一组语句									*/

	//编写选择结构的程序

		//键盘输入一个整数当年份，判断该年是否为闰年
	int year, leap;
	cout << "Enter a year: ";
	cin >> year;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	cout << year << (leap ? " is" : " is not") << " a leap year." << endl;

		//对n个人分班，每班k(k>0)人，最后不足k人也编为一个班，输出分班数
	int n, k;
	cout << "Enter the total number of people and the number of people in each class: ";
	cin >> n >> k;

	if (n % k == 0)										//使用if-else语句的实现
		cout << n / k << endl;
	else
		cout << n / k + 1 << endl;

	cout << (n % k == 0 ? n / k : n / k + 1) << endl;	//不使用if-else语句的实现
	cout << (n / k + (n % k == 0 ? 0 : 1)) << endl;

	cout << n / k + (n % k > 0) << endl;				//不使用if-else和条件表达式的实现
	cout << n / k + bool(n % k) << endl;
	cout << n / k + !!(n % k) << endl;

	cout << (n + k - 1) / k << endl;					//不使用if-else、条件表达式、逻辑变量、关系运算符和逻辑运算符的实现

	//for循环语句

	/*	形式：																						*/
	/*		for(表达式1; 表达式2; 表达式3){															*/
	/*			语句序列;																			*/
	/*		}																						*/
	/*																								*/
	/*	执行过程：																					*/
	/*		1.求解表达式1（初值）																	*/
	/*		2.以逻辑值求解表达式2，为真则执行循环体，为假则结束循环体的执行（当型）					*/
	/*		3.执行完循环体后，求解表达式3，重复2（语句序列或表达式3中应该有改变表达式2的求解条件）	*/
	/*																								*/
	/*	与while语句的互换性：																		*/
	/*		表达式1;																				*/
	/*		while(表达式2){																			*/
	/*			语句序列;																			*/
	/*			表达式3;																			*/
	/*		}																						*/
	/*																								*/
	/*	for语句的基本使用形式：																		*/
	/*		for(循环变量赋初值; 循环条件; 循环变量增值){											*/
	/*			语句序列;																			*/
	/*		}																						*/
	/*																								*/
	/*	for语句的扩展使用：																			*/
	/*		1.表达式1可省，在for语句前给变量赋值													*/
	/*		2.表达式2可省，永真（死循环）															*/
	/*		3.表达式3可省，另外设法改变表达式2的取值												*/
	/*		4.表达式1、3可省，完全等同于while语句的形式												*/
	/*		5.表达式1、2、3全省，永真（死循环）														*/
	/*		6.表达式1、3可以是简单表达式，也可以是多个简单表达式组合形式的逗号表达式，如果因此而导	*/
	/*	致循环不需要包含任何语句，则要加一个;表示不需要语句序列（;也可以理解为空语句）				*/
	/*		7.表达式2可以是任何类型，但按逻辑性求解													*/

	//break语句

	/*	作用：提前结束循环体的循环											*/
	/*		1.无条件结束循环体，因此必须和if/else语句一起使用				*/
	/*		2.当多重循环嵌套时，break仅跳出本循环							*/
	/*		3.若出现循环和switch语句的嵌套，则break的位置决定了跳转的位置	*/

	//continue语句

	/*	作用：结束本次循环，进行下一次是否执行循环的判断								*/
	/*		1.无条件结束循环体，因此必须和if/else语句一起使用							*/
	/*		2.若出现循环和switch语句的嵌套，则continue只对循环体有效					*/
	/*		3.for语句中若出现continue，则先执行表达式3，再去判断表达式2是否应该继续执行	*/

	return 0;
}