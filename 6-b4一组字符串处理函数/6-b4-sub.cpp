/* 2251730 信07 刘淑仪 */

#include <cstdio>   //NULL
#include"6-b4.h"
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串长度
  输入参数：const char *str
  返 回 值：字符串长度
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    int sum = 0;
    if (str == NULL)
        return 0;
    while (*str != '\0') {
        sum += 1;
        str++;
    }
    return sum;
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将字符串s2追加到s1后面，含\0
  输入参数：char *s1,const char *s2
  返 回 值：p
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    char* p = s1;
    if (s1 == NULL)
        return NULL;
    if (s2 != NULL) {
        while (*s1 != '\0')
            s1++;
        for (; *s2 != '\0'; s1++, s2++)
            *s1 = *s2;
        *s1 = '\0';
    }
    return p;
}

/***************************************************************************
  函数名称：tj_strncat
  功    能：将字符串s2的前len个字符追加到s1后面，并添加\0
  输入参数：char *s1,const char *s2,const int len
  返 回 值：p
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    char* p = s1;
    int s1L = tj_strlen(s1);
    if (s1 == NULL)
        return NULL;
    if (s2 != NULL) {
        while (*s1 != '\0')
            s1++;
        for (; *s2 != '\0' && (s1 - p) < s1L + len; s1++, s2++)
            *s1 = *s2;
        *s1 = '\0';
    }
    return p;
}

/***************************************************************************
  函数名称：tj_strcpy
  功    能：将字符串s2复制到s1中，覆盖s1中原内容，复制时不含\0.
  输入参数：char *s1, const char *s2
  返 回 值：0
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    char* p = s1;
    if (s1 == NULL)
        return NULL;
    if (s2 != NULL) {
        for (; *s2 != '\0'; s1++, s2++)
            *s1 = *s2;
        *s1 = '\0';
    }
    else
        *s1 = NULL;
    return p;
}

/***************************************************************************
  函数名称：tj_strncpy
  功    能：将字符串s2的前n个内容复制到s1中，复制时不含\0.
  输入参数：char *s1, const char *s2,const int len
  返 回 值：0
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    char* p = s1;
    if (s1 == NULL)
        return NULL;
    if (s2 != NULL) {
        for (; *s2 != '\0' && (s1 - p) < len; s1++, s2++)
            *s1 = *s2;
    }
    return p;
}

/***************************************************************************
  函数名称：tj_strcmp
  功    能：比较字符串s1和s2的大小，英文字母要区分大小写
  输入参数：const char s1[],const char s2[]
  返 回 值：k
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    int j = 0;
    if (s1 == NULL) {
        if (s2 != NULL)
            return -1;
        else
            return 0;
    }
    if (s2 != NULL) {
        for (; tj_strlen(s1) > tj_strlen(s2) ? *s1 != '\0' : *s2 != '\0'; s1++, s2++) {
            if (*s1 != *s2) {
                j = *s1 - *s2;
                break;
            }
        }
    }
    else
        return 1;
    return j;
}

/***************************************************************************
  函数名称：tj_strcasecmp
  功    能：比较字符串s1和s2的大小，英文字母不分大小写
  输入参数：const char *s1,const char *s2
  返 回 值：j
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    int j = 0, m = 0, n = 0;
    if (s1 == NULL) {
        if (s2 != NULL)
            return -1;
        else
            return 0;
    }
    if (s2 != NULL) {
        for (; tj_strlen(s1) > tj_strlen(s2) ? *s1 != '\0' : *s2 != '\0'; s1++, s2++) {
            if (*s1 >= 'A' && *s1 <= 'Z')
                m = *s1 + 32;
            else
                m = *s1;
            if (*s2 >= 'A' && *s2 <= 'Z')
                n = *s2 + 32;
            else
                n = *s2;
            if (m != n) {
                j = m - n;
                break;
            }
        }
    }
    else
        return 1;
    return j;
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：比较字符串s1和s2前len个字符的大小，英文字母要区分大小写
            *若len大于s1/s2中长度短的串，则比较到短串的\0即结束
  输入参数：const char *s1,const char *s2,const int len
  返 回 值：j
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    int j = 0;
    const char* p1 = s1;
    const char* p2 = s2;
    int min = tj_strlen(s1) > tj_strlen(s2) ? (tj_strlen(s2) + 1) : (tj_strlen(s1) + 1);
    if (s1 == NULL) {
        if (s2 != NULL)
            return -1;
        else
            return 0;
    }
    if (s2 != NULL) {
        for (; min > len ? ((s1 - p1) < len && (s2 - p2) < len) : (*s1 != '\0' || *s2 != '\0'); s1++, s2++) {
            if (*s1 != *s2) {
                j = *s1 - *s2;
                break;
            }
        }
    }
    else
        return 1;
    return j;
}

/***************************************************************************
  函数名称：tj_strcasencmp
  功    能：比较字符串s1和s2前len个字符的大小，英文字母不分大小写
            *若len大于s1/s2中长度短的串，则比较到短串的\0即结束
  输入参数：const char *s1,const char *s2,const int len
  返 回 值：j
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    int j = 0, m = 0, n = 0;
    const char* p1 = s1;
    const char* p2 = s2;
    int min = tj_strlen(s1) > tj_strlen(s2) ? (tj_strlen(s2) + 1) : (tj_strlen(s1) + 1);
    if (s1 == NULL) {
        if (s2 != NULL)
            return -1;
        else
            return 0;
    }
    if (s2 != NULL) {
        for (; min > len ? ((s1 - p1) < len && (s2 - p2) < len) : (*s1 != '\0' || *s2 != '\0'); s1++, s2++) {
            if (*s1 >= 'A' && *s1 <= 'Z')
                m = *s1 + 32;
            else
                m = *s1;
            if (*s2 >= 'A' && *s2 <= 'Z')
                n = *s2 + 32;
            else
                n = *s2;
            if (m != n) {
                j = m - n;
                break;
            }
        }
    }
    else
        return 1;
    return j;
}

/***************************************************************************
  函数名称：tj_strupr
  功    能：将字符串str中所有小写字母均转为大写，其他字符不变，转换后放在原
            串中
  输入参数：char *str
  返 回 值：0
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    char* p = str;
    if (str != NULL) {
        while (*str != '\0') {
            if (*str >= 'a' && *str <= 'z')
                *str -= 32;
            str++;
        }
    }
    str = p;
    return str;
}

/***************************************************************************
  函数名称：tj_strlwr
  功    能：将字符串str中所有大写字母均转为小写，其他字符不变，转换后放在原
            串中
  输入参数：char *str
  返 回 值：0
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    char* p = str;
    if (str != NULL) {
        while (*str != '\0') {
            if (*str >= 'A' && *str <= 'Z')
                *str += 32;
            str++;
        }
    }
    str = p;
    return str;
}

/***************************************************************************
  函数名称：tj_strchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从左到右
  输入参数：const char *str,char ch
  返 回 值：j
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    int j = 1;
    if (str == NULL)
        return 0;
    while (*str != '\0') {
        if (*str != ch) {
            j++;
            str++;
        }
        else
            break;
    }
    if (j > tj_strlen(str))
        return 0;
    return j;
}

/***************************************************************************
  函数名称：tj_strstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从左到右
  输入参数：const char *str, const char *substr
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    if (str == NULL)
        return 0;
    if (substr == NULL)
        return 0;
    int sL = tj_strlen(str);
    int subL = tj_strlen(substr);
    const char* p1 = str;
    const char* p2 = substr;
    while (*str && *substr) {
        if (*str != *substr) {
            if (substr != p2) {
                substr--;
                continue;
            }
            else
                str++;
        }
        else {
            substr++;
            str++;
        }
    }
    if (str - p1 + 1 > sL && substr - p2 == 0)
        return 0;
    else
        return str - p1 - subL + 1;
}

/***************************************************************************
  函数名称：tj_strrchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从右到左
  输入参数：const char *str,const char ch
  返 回 值：j
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    int j = tj_strlen(str) + 1;
    const char* p = str;
    if (str == NULL)
        return 0;
    for (; *str != '\0'; str++);
    while (str >= p) {
        if (*str != ch) {
            str--;
            j--;
        }
        else
            break;
    }
    return j;
}

/***************************************************************************
  函数名称：tj_strrstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从右到左
  输入参数：const char *str, const char *substr
  返 回 值：j
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    if (str == NULL)
        return 0;
    if (substr == NULL)
        return 0;
    int sL = tj_strlen(str);
    int subL = tj_strlen(substr);
    const char* p1 = str;
    for (; *str != '\0'; str++);
    str--;
    for (; *substr != '\0'; substr++);
    substr--;
    const char* p2 = substr;
    while (*str && *substr) {
        if (*str != *substr) {
            if (substr != p2) {
                substr++;
                continue;
            }
            else
                str--;
        }
        else {
            substr--;
            str--;
        }
    }
    if (substr - p2 == 0)
        return 0;
    else
        return str - p1 + 2;
}

/***************************************************************************
  函数名称：tj_strrev
  功    能：字符串反转，放入原串中
  输入参数：char *str
  返 回 值：0
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    int SL = tj_strlen(str);
    char t;
    char* start = str;
    char* end = str + SL - 1;
    if (str == NULL)
        return 0;
    for (; start < end; start++, end--) {
        t = *start;
        *start = *end;
        *end = t;
    }
    return str;
}
