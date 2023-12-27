/* 2251730 ��07 ������ */

#include <cstdio>   //NULL
#include"6-b4.h"
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ����ַ�������
  ���������const char *str
  �� �� ֵ���ַ�������
  ˵    ����
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
  �������ƣ�tj_strcat
  ��    �ܣ����ַ���s2׷�ӵ�s1���棬��\0
  ���������char *s1,const char *s2
  �� �� ֵ��p
  ˵    ����
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
  �������ƣ�tj_strncat
  ��    �ܣ����ַ���s2��ǰlen���ַ�׷�ӵ�s1���棬�����\0
  ���������char *s1,const char *s2,const int len
  �� �� ֵ��p
  ˵    ����
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
  �������ƣ�tj_strcpy
  ��    �ܣ����ַ���s2���Ƶ�s1�У�����s1��ԭ���ݣ�����ʱ����\0.
  ���������char *s1, const char *s2
  �� �� ֵ��0
  ˵    ����
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
  �������ƣ�tj_strncpy
  ��    �ܣ����ַ���s2��ǰn�����ݸ��Ƶ�s1�У�����ʱ����\0.
  ���������char *s1, const char *s2,const int len
  �� �� ֵ��0
  ˵    ����
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
  �������ƣ�tj_strcmp
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸҪ���ִ�Сд
  ���������const char s1[],const char s2[]
  �� �� ֵ��k
  ˵    ����
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
  �������ƣ�tj_strcasecmp
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸ���ִ�Сд
  ���������const char *s1,const char *s2
  �� �� ֵ��j
  ˵    ����
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
  �������ƣ�tj_strncmp
  ��    �ܣ��Ƚ��ַ���s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸҪ���ִ�Сд
            *��len����s1/s2�г��ȶ̵Ĵ�����Ƚϵ��̴���\0������
  ���������const char *s1,const char *s2,const int len
  �� �� ֵ��j
  ˵    ����
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
  �������ƣ�tj_strcasencmp
  ��    �ܣ��Ƚ��ַ���s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸ���ִ�Сд
            *��len����s1/s2�г��ȶ̵Ĵ�����Ƚϵ��̴���\0������
  ���������const char *s1,const char *s2,const int len
  �� �� ֵ��j
  ˵    ����
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
  �������ƣ�tj_strupr
  ��    �ܣ����ַ���str������Сд��ĸ��תΪ��д�������ַ����䣬ת�������ԭ
            ����
  ���������char *str
  �� �� ֵ��0
  ˵    ����
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
  �������ƣ�tj_strlwr
  ��    �ܣ����ַ���str�����д�д��ĸ��תΪСд�������ַ����䣬ת�������ԭ
            ����
  ���������char *str
  �� �� ֵ��0
  ˵    ����
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
  �������ƣ�tj_strchr
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��1�γ��ֵ�λ�ã�˳���Ǵ�����
  ���������const char *str,char ch
  �� �� ֵ��j
  ˵    ����
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
  �������ƣ�tj_strstr
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��1�γ��ֵ�λ�ã�˳���Ǵ�����
  ���������const char *str, const char *substr
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�tj_strrchr
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��1�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  ���������const char *str,const char ch
  �� �� ֵ��j
  ˵    ����
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
  �������ƣ�tj_strrstr
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��1�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  ���������const char *str, const char *substr
  �� �� ֵ��j
  ˵    ����
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
  �������ƣ�tj_strrev
  ��    �ܣ��ַ�����ת������ԭ����
  ���������char *str
  �� �� ֵ��0
  ˵    ����
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
