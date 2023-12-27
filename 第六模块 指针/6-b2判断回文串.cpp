/* 2251730 –≈07 ¡ı Á“« */
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define  N  10

int palindromic(char* p, char* p_)
{
	while (*p != '\0' && *p_ != '\0') {
		if (*p != *p_)
			return 0;
		else {
			p_ += 1;
			p -= 1;
		}
	}
	return 1;
}

int main()
{
	char str1[81], str2[81], * p = str1, * p_ = str2;
	fgets(str1, 81, stdin);
	p = strchr(str1, '\n');
	*p = '\0';
	p = str1;
	while (*p_++ = *p++);
	p_ = str2;
	p -= 2;
	bool yes_or_no = palindromic(p, p_);
	yes_or_no == 1 ? cout << "yes" << endl : cout << "no" << endl;
	return 0;
}