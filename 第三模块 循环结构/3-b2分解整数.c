/*2251730 信07 刘淑仪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c, d, e, f;
    printf("请输入一个[1..30000]间的整数:\n");
    scanf("%d", &a);
    b = a / 10000 % 10;
    c = a / 1000 % 10;
    d = a / 100 % 10;
    e = a / 10 % 10;
    f = a % 10;
    printf("万位 : ");
    printf("%d\n", b);
    printf("千位 : ");
    printf("%d\n", c);
    printf("百位 : ");
    printf("%d\n", d);
    printf("十位 : ");
    printf("%d\n", e);
    printf("个位 : ");
    printf("%d\n", f);

    return 0;
}