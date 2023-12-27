#include <iostream>
using namespace std;

int main()
{
	//确定数据类型的上下限

	cout << "INT_MAX = " << INT_MAX << endl;
	cout << "INT_MIN = " << INT_MIN << endl;
	cout << "UINT_MAX = " << UINT_MAX << endl;
	cout << "LLONG_MAX = " << LLONG_MAX << endl;
	cout << "LLONG_MIN = " << LLONG_MIN << endl;
	cout << "SHRT_MAX = " << SHRT_MAX << endl;
	cout << "SHRT_MIN = " << SHRT_MIN << endl;

	cout << "64bit有符号数的最大值：" << 0x7FFFFFFFFFFFFFFF << endl; //0x7FFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF / 2
	unsigned long long x = -1;
	cout << "64bit有符号数的最大值：" << x / 2 << endl;

	//整型常量在C/C++源程序中的四种表示方法

		//输出缺省为十进制
	cout << "整型常量119输出为：" << 119 << endl;				//十进制：正常方式
	cout << "整型常量0b1110111输出为：" << 0b1110111 << endl;	//二进制：0b+0~1
	cout << "整型常量0176输出为：" << 0167 << endl;				//八进制：0+0~7
	cout << "整型常量0x77输出为：" << 0x77 << endl;				//十六进制：0x/0X+0~9,A(a)~F(f)

		//可加前导进制转换(十进制dec/八进制oct/十六进制hex)改为其他进制
	cout << "前导进制转换dec改为十进制：" << dec << 119 << endl;
	cout << "前导进制转换oct改为八进制：" << oct << 119 << " → 避免二义性：" << "0" << oct << 119 << endl;
	cout << "前导进制转换hex改为十六进制：" << hex << 119 << " → 避免二义性：" << "0x" << hex << 119 << endl;

	//确定整型常量和浮点型常量的类型

	cout << "整型常量123的类型为：" << typeid(123).name() << endl;
	cout << "整型常量123L的类型为：" << typeid(123L).name() << endl;
	cout << "整型常量123U的类型为：" << typeid(123U).name() << endl;
	cout << "整型常量123LU的类型为：" << typeid(123LU).name() << endl;
	cout << "整型常量123UL的类型为：" << typeid(123UL).name() << endl;
	cout << "浮点型常量1.23的类型为：" << typeid(1.23).name() << endl;
	cout << "浮点型常量1.23f的类型为：" << typeid(1.23f).name() << endl;

	//ASCII码

	/*	ASCII码占用一个字节，共可表示256个字符	*/
	/*											*/
	/*	基本ASCII码(0xxxxxxx)：128个(0~127)		*/
	/*		控制字符：34个(0~32,127)			*/
	/*		图形字符：94个(33~126)				*/
	/*											*/
	/*	扩展ASCII码(1xxxxxxx)：128个(128~255)	*/

	cout << ' ' << "的ASCII码为：32/0x20" << endl;
	cout << '0' << "的ASCII码为：48/0x30" << endl;
	cout << 'A' << "的ASCII码为：65/0x41" << endl;
	cout << 'a' << "的ASCII码为：97/0x61" << endl;

	//普通字符常量与转义字符常量

	/*	直接表示：'空格或大部分可见的图形字符'																*/
	/*																										*/
	/*	转义符表示：'\字符、八进制数、十六进制数'															*/
	/*		'\字符'																							*/
	/*		'\八进制数'：000~377(0~255)：8进制值对应的ASCII码												*/
	/*		'\十六进制数'：x+00~ff/FF(0~255)：16进制值对应的ASCII码											*/
	/*																										*/
	/*	一个字符常量可有多种表现形式：																		*/
	/*		A(ASCII=65)	'A'		  ESC(ASCII=27)	'\33'	   双引号(ASCII=34)	'\"'	 换行(ASCII=10)	'\n'	*/
	/*					'\101'					'\033'						'\42'					'\12'	*/
	/*					'\x41'					'\x1b'						'\042'					'\012'	*/
	/*											'\x1B'						'\x22'					'\xA'	*/
	/*	'0'与'\0'的区别：																			'\xa'	*/
	/*		'0'(ASCII=48)：'\60'、'\060'、'\x30'													'\x0A'	*/
	/*		'\0'(ASCII=0)：'\00'、'\000'、'\x0'、'\x00'												'\x0a'	*/
	/*																										*/
	/*	一个字符常量只能表示一个字符，一个字符在内存中占用一个字节，字节的值为该字符的ASCII码				*/

	//字符串常量

	/*	在内存中的存放：每个字符的ASCII码+字符串结束标志'\0'（ASCII 0、尾0）*/
	/*																		*/
	/*	 ""与" "的区别： "" - 空字符串，长度为0								*/
	/*					" " - 含一个空格的字符串，长度为1					*/
	/*																		*/
	/*	'A'与"A"的区别：'A' - 字符常量，内存中占一个字节					*/
	/*					"A" - 字符串常量，内存中占两个字节					*/

	cout << "strlen(\"\") = " << strlen("") << endl;
	cout << "strlen(\" \") = " << strlen(" ") << endl;

	cout << "sizeof(\"汉\") = " << sizeof("汉") << endl;
	cout << "sizeof(\"\") = " << sizeof("") << endl;
	cout << "sizeof(\" \") = " << sizeof(" ") << endl;
	cout << "sizeof(\'A\') = " << sizeof('A') << endl;
	cout << "sizeof(\"A\") = " << sizeof("A") << endl;

	//强制类型转换

	/*	C形式：		(类型名)(表达式)			*/
	/*	C++形式：	类型名(表达式)				*/
	/*	C++形式：	static_cast<类型名>(表达式)	*/
	/*											*/
	/*	强制转换后，原变量的值、类型不变		*/
	/*	（强制转换的结果放在一个中间变量中）	*/

	int a = -3;
	unsigned int b = 2;
	cout << "a+b = " << dec << a + b << endl;
	cout << "int(a+b) = " << dec << int(a + b) << endl;

	//字符与字符串的输出

	/*	有效的输出：										*/
	/*		纯ASCII图形字符的输出（基本ASCII码 33-126之间）	*/
	/*		汉字的输出（成对的扩展ASCII码）					*/
	/*		汉字 + 纯ASCII图形字符的混合输出				*/

	cout << "有效的输出：" << endl;
	cout << "纯ASCII图形字符的输出（基本ASCII码 33-126之间）" << endl;
	cout << "\x21\x31\x7e" << " " << "\41\061\176" << " " << "!1~" << endl;
	cout << "汉字的输出（成对的扩展ASCII码）" << endl;
	cout << "\xB8\xDF\xB3\xCC" << " " << "\270\337\263\314" << " " << "高程" << endl;
	cout << "汉字 + 纯ASCII图形字符的混合输出" << endl;
	cout << "\x21\xB8\xDF\xB3\xCC\x31\x7e" << " " << "\41\270\337\263\314\061\176" << " " << "!高程1~" << endl;

	/*	无效的输出：										*/
	/*		单独的扩展ASCII码的输出（中文系统下非法）		*/
	/*		非法的情况（不成对的扩展ASCII码、含控制字符）	*/
	/*		同一程序设置不同显示字体的情况下				*/

	/*	cout << "无效的输出：" << endl;
		cout << "\xB8" << '*' << endl; // "高"的前半个
		cout << "\xB8\xDF\xB3" << '*' << endl; // "高"+"程"的前半个
		cout << "\xB8*\xDF\xB3" << endl; // "高"的前半个+*+"高"的后半个+"程"的前半个
		cout << "Hello\x8" << endl; // \x8是Backspace键
		cout << "Hello\x8x" << endl; // \x8是Backspace键
		cout << "\3\4\5\6" << endl; // 新版控制台(新宋体)与新版控制台(点阵字体)显示不一致	*/

	/*	尾0的输出：											*/

	/*	cout << "尾0的输出：" << endl;
		cout << "a \0" << "a *" << endl;
		cout << "a " << '\0' << "a *" << endl;	*/

	/*	现象分析：											*/
	/*		新版控制台(新宋体28)：\0无对应输出				*/
	/*		旧版控制台(新宋体28)：\0对应一个另一种字体的a	*/
	/*		旧版控制台(新宋体16)：\0对应一个空格			*/
	/*														*/
	/*	最终结论：											*/
	/*		\0不是合法的图形字符，看到的内容不可信			*/

	/*	总结：															*/
	/*		含汉字/图形字符/空格的字符串可以正常显示，否则输出不可信	*/
	/*		研究长度：strlen()											*/
	/*		研究占内存空间：sizeof()									*/
	/*		研究某个字节确定值：转int打印								*/

	cout << "\"高\"+\"程\"的前半个的确定值为：" << strlen("\xB8\xDF\xB3") << endl;
	cout << "\"Hello\\x8x\"的确定值为：" << sizeof("Hello\x8x") << endl; // \x8是Backspace键
	cout << "\"程\"的前半个的确定值为：" << int('\xB3') << endl; // '\xB3'不能打成"\xB3"

	//float型数据的内部存储格式

	float f = 123.456;
	unsigned char* p_f = (unsigned char*)&f;
	cout << "float型数据的内部存储格式：" << endl;
	cout << hex << (int)(*p_f) << endl;
	cout << hex << (int)(*(p_f + 1)) << endl;
	cout << hex << (int)(*(p_f + 2)) << endl;
	cout << hex << (int)(*(p_f + 3)) << endl;

	/*	单精度浮点数123.456，在内存中占四个字节，四个字节的值依次为0x42 0xf6 0xe9 0x79（按打印顺序逆向取）	*/
	/*	转换为32bit则为：01000010 11110110 11101001 01111001（符号位 + 8位指数 + 23位尾数）					*/

	//double型数据的内部存储格式

	double d = 1.23e4;
	unsigned char* p_d = (unsigned char*)&d;
	cout << "double型数据的内部存储格式：" << endl;
	cout << hex << (int)(*p_d) << endl;
	cout << hex << (int)(*(p_d + 1)) << endl;
	cout << hex << (int)(*(p_d + 2)) << endl;
	cout << hex << (int)(*(p_d + 3)) << endl;
	cout << hex << (int)(*(p_d + 4)) << endl;
	cout << hex << (int)(*(p_d + 5)) << endl;
	cout << hex << (int)(*(p_d + 6)) << endl;
	cout << hex << (int)(*(p_d + 7)) << endl;

	/*	双精度浮点数1.23e4，在内存中占八个字节，八个字节的值依次为0x40 0xc8 0x06 0x00 0x00 0x00 0x00 0x00（按打印顺序逆向取）	*/
	/*	转换为64bit则为：01000000 11001000 00000110 00000000 00000000 00000000 00000000 00000000（符号位 + 11位指数 + 52位尾数）*/

	return 0;
}