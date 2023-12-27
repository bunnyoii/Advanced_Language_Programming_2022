/* 2251730 信07 刘淑仪 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;

#define N 10
int count = 1;
int top1 = 0, top2 = 0, top3 = 0;
int A[N] = { 0 }, B[N] = { 0 }, C[N] = { 0 };

void choose(int n, char src, char tmp, char dst)
{
    if (src == 'A') {
        top1 = n;
        printf("A:");
        for (int i = 0; i < n; i++) {
            A[i] = n - i;
            printf("%2d", A[i]);
        }
        for (int j = 0; j < 2 * (N - n) + 1; j++)
            printf(" ");
        printf("B:                     C:                    \n");
    }
    else if (src == 'B') {
        top2 = n;
        printf("A:                     B:");
        for (int i = 0; i < n; i++) {
            B[i] = n - i;
            printf("%2d", B[i]);
        }
        for (int j = 0; j < 2 * (N - n) + 1; j++)
            printf(" ");
        printf("C:                   \n");
    }
    else if (src == 'C') {
        top3 = n;
        printf("A:                     B:                     C:");
        for (int i = 0; i < n; i++) {
            C[i] = n - i;
            printf("%2d", C[i]);
        }
        for (int j = 0; j < 2 * (N - n) + 1; j++)
            printf(" ");
        printf("\n");
    }
}

void print(int n, int top1, int top2, int top3)
{
    int i, j;
    printf("A:");
    for (i = 0; i < top1; i++) {
        if (A[i] > 0)
            printf("%2d", A[i]);
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        printf(" ");

    printf("B:");
    for (i = 0; i < top2; i++) {
        if (B[i] > 0)
            printf("%2d", B[i]);
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        printf(" ");

    printf("C:");
    for (i = 0; i < top3; i++) {
        if (C[i] > 0)
            printf("%2d", C[i]);
    }
    for (j = 0; j < 2 * (N - i) + 1; j++)
        printf(" ");
    printf("\n");
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    printf("第%4d 步(%2d): %c-->%c ", count, n, src, dst);
    if (src == 'A')
        A[--top1] = 0;
    else if (src == 'B')
        B[--top2] = 0;
    else
        C[--top3] = 0;

    if (dst == 'A')
        A[top1++] = n;
    else if (dst == 'B')
        B[top2++] = n;
    else
        C[top3++] = n;

    print(n, top1, top2, top3);
    ++count;
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        int ret1 = scanf("%d", &n);
        if (ret1 == 1) {
            if (n >= 1 && n <= 10)
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

    printf("初始:                ");
    choose(n, src, tmp, dst);
    hanoi(n, src, tmp, dst);

    return 0;
}