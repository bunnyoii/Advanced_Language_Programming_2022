/*2251730 ��07 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c, d, e, f;
    printf("������һ��[1..30000]�������:\n");
    scanf("%d", &a);
    b = a / 10000 % 10;
    c = a / 1000 % 10;
    d = a / 100 % 10;
    e = a / 10 % 10;
    f = a % 10;
    printf("��λ : ");
    printf("%d\n", b);
    printf("ǧλ : ");
    printf("%d\n", c);
    printf("��λ : ");
    printf("%d\n", d);
    printf("ʮλ : ");
    printf("%d\n", e);
    printf("��λ : ");
    printf("%d\n", f);

    return 0;
}