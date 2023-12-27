/* 信07 2251730 刘淑仪*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	int count = 0;
	for (int b1 = 1; b1 <= 9; b1++) {
		for (int s1 = 1; s1 <= 9; s1++) {
			for (int g1 = 1; g1 <= 9; g1++) {
				if (b1 != s1 && b1 != g1 && s1 != g1) {
					int num1 = b1 * 100 + s1 * 10 + g1;
					for (int b2 = 1; b2 <= 9; b2++) {
						for (int s2 = 1; s2 <= 9; s2++) {
							for (int g2 = 1; g2 <= 9; g2++) {
								if ((b2 != b1 && b2 != s1 && b2 != g1 && b2 != s2 && b2 != g2) && (s2 != b1 && s2 != s1 && s2 != g1 && s2 != g2) && (g2 != b1 && g2 != s1 && g2 != g1)) {
									int num2 = b2 * 100 + s2 * 10 + g2;
									for (int b3 = 1; b3 <= 9; b3++) {
										for (int s3 = 1; s3 <= 9; s3++) {
											for (int g3 = 1; g3 <= 9; g3++) {
												int num3 = b3 * 100 + s3 * 10 + g3;
												if ((b3 != b1 && b3 != b2 && b3 != s1 && b3 != s2 && b3 != s3 && b3 != g1 && b3 != g2 && b3 != g3) && (s3 != b1 && s3 != b2 && s3 != s1 && s3 != s2 && s3 != g1 && s3 != g2 && s3 != g3) && (g3 != b1 && g3 != b2 && g3 != s1 && g3 != s2 && g3 != g1) && num1 < num2 && num2 < num3) {
													if (num1 + num2 + num3 == 1953) {
														count++;
														cout << "No." << setw(3) << std::right << count << " : " << num1 << "+" << num2 << "+" << num3 << "=1953" << endl;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "total : " << count << endl;
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}