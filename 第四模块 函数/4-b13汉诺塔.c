/* 2251730 信07 刘淑仪 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */
int count = 1;

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    printf("%5d: ", count);
    printf("%2d# %c-->%c\n", n, src, dst);
    ++count;
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
        int ret1 = scanf("%d", &n);
        if (ret1 == 1) {
            if (n >= 1 && n <= 16)
                break;
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }
    while (getchar() != '\n')
        ;
    while (1) {
        printf("请输入起始柱(A-C)\n");
        int ret2 = scanf("%c", &src);
        if (ret2 == 1) {
            if (src > 68)
                src -= 32;
            if (src == 65 || src == 66 || src == 67)
                break;
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }
    while (getchar() != '\n')
        ;

    while (1) {
        printf("请输入目标柱(A-C)\n");
        int ret3 = scanf("%c", &dst);
        if (ret3 == 1) {
            if (dst > 68)
                dst -= 32;
            if (src > 68)
                src -= 32;
            if (dst == src) {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
                while (getchar() != '\n')
                    ;
            }
            else {
                if (dst == 65 || dst == 66 || dst == 67)
                    break;
                else {
                    while (getchar() != '\n')
                        ;
                }
            }
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }

    if (src == 'A' || src == 'a') {
        src = 'A';
        if (dst == 'B' || dst == 'b') {
            tmp = 'C';
            dst = 'B';
        }
        else {
            tmp = 'B';
            dst = 'C';
        }
    }
    else if (src == 'B' || src == 'b') {
        src = 'B';
        if (dst == 'A' || dst == 'a') {
            tmp = 'C';
            dst = 'A';
        }
        else {
            tmp = 'A';
            dst = 'C';
        }
    }
    else {
        src = 'C';
        if (dst == 'A' || dst == 'a') {
            tmp = 'B';
            dst = 'A';
        }
        else {
            tmp = 'A';
            dst = 'B';
        }
    }

    printf("移动步骤为:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}