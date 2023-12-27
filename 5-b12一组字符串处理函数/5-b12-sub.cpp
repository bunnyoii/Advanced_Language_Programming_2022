/* 2251730 ��07 ������ */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��return 0ֻ��һ��ʾ�����ɸı� */

/* ���������κ���ʽ���ⲿȫ�֡���̬ȫ�֡��궨�塢ֻ������ */

/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ����ַ�������
  ���������const char str[]
  �� �� ֵ���ַ�������
  ˵    ����
***************************************************************************/
int tj_strlen(const char str[])
{
    int sum = 0;
    for (int i = 0; i < 114514 && str[i] != '\0'; i++)
        sum += 1;

    return sum;
}

/***************************************************************************
  �������ƣ�tj_strcat
  ��    �ܣ����ַ���s2׷�ӵ�s1���棬��\0
  ���������char s1[],const char s2[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    int s1L = tj_strlen(s1);
    int s2L = tj_strlen(s2);
    for (int i = 0; i < s2L && s2[i] != '\0'; i++) {
        s1[i + s1L] = s2[i];
        s1[i + s1L + 1] = '\0';
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strncat
  ��    �ܣ����ַ���s2��ǰlen���ַ�׷�ӵ�s1���棬�����\0
  ���������char s1[],const char s2[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    int s1L = tj_strlen(s1);
    int s2L = tj_strlen(s2);
    for (int i = 0; i < len && s2[i] != '\0'; i++) {
        s1[i + s1L] = s2[i];
        s1[i + s1L + 1] = '\0';
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strcpy
  ��    �ܣ����ַ���s2���Ƶ�s1�У�����s1��ԭ���ݣ�����ʱ����\0.
  ���������char s1[], const char s2[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    int s2L = tj_strlen(s2);
    for (int i = 0; i < s2L && s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    s1[s2L] = '\0';
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strncpy
  ��    �ܣ����ַ���s2��ǰn�����ݸ��Ƶ�s1�У�����ʱ����\0.
  ���������char s1[], const char s2[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    int s1L = tj_strlen(s1);
    int s2L = tj_strlen(s2);
    for (int i = 0; i < len && s2[i] != '\0'; i++)
        s1[i] = s2[i];

    return 0;
}

/***************************************************************************
  �������ƣ�tj_strcmp
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸҪ���ִ�Сд
  ���������const char s1[],const char s2[]
  �� �� ֵ��k
  ˵    ����
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    int j = 0;
    for (int i = 0; tj_strlen(s1) > tj_strlen(s2) ? i < tj_strlen(s1) : i < tj_strlen(s2); i++) {
        if (s1[i] != s2[i]) {
            j = int(s1[i]) - int(s2[i]);
            break;
        }
    }
    return j;
}

/***************************************************************************
  �������ƣ�tj_strcasecmp
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸ���ִ�Сд
  ���������const char s1[],const char s2[]
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    int j = 0, m = 0, n = 0;

    for (int i = 0; tj_strlen(s1) > tj_strlen(s2) ? i < tj_strlen(s1) : i < tj_strlen(s2); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            m = int(s1[i]) + 32;
        else
            m = int(s1[i]);
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            n = int(s2[i]) + 32;
        else
            n = int(s2[i]);
        if (m != n) {
            j = m - n;
            break;
        }
    }
    return j;
}

/***************************************************************************
  �������ƣ�tj_strncmp
  ��    �ܣ��Ƚ��ַ���s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸҪ���ִ�Сд
  ���������const char s1[],const char s2[],const int len
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    int j = 0, min = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s2) : tj_strlen(s1);

    for (int i = 0; (i < ((min + 1) >= len ? len : (min + 1))); i++) {
        if (s1[i] != s2[i]) {
            j = int(s1[i]) - int(s2[i]);
            break;
        }
    }

    return j;
}
/***************************************************************************
  �������ƣ�tj_strcasencmp
  ��    �ܣ��Ƚ��ַ���s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸ���ִ�Сд
  ���������const char s1[],const char s2[],const int len
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    int j = 0, m = 0, n = 0;
    int min = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s2) : tj_strlen(s1);

    for (int i = 0; (i < ((min + 1) >= len ? len : (min + 1))); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            m = int(s1[i]) + 32;
        else
            m = int(s1[i]);
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            n = int(s2[i]) + 32;
        else
            n = int(s2[i]);
        if (m != n) {
            j = m - n;
            break;
        }
    }
    return j;
}

/***************************************************************************
  �������ƣ�tj_strupr
  ��    �ܣ����ַ���str������Сд��ĸ��תΪ��д�������ַ����䣬ת�������ԭ
            ����
  ���������char str[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strupr(char str[])
{
    int sL = tj_strlen(str);
    for (int i = 0; i < sL; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strlwr
  ��    �ܣ����ַ���str�����д�д��ĸ��תΪСд�������ַ����䣬ת�������ԭ
            ����
  ���������char str[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strlwr(char str[])
{
    int sL = tj_strlen(str);
    for (int i = 0; i < sL; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strchr
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��1�γ��ֵ�λ�ã�˳���Ǵ�����
  ���������const char str[],char ch
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    int sL = tj_strlen(str);
    int j = 1;
    for (int i = 0; i < sL; i++) {
        if (str[i] != ch)
            j++;
        else
            break;
    }
    if (j > sL)
        return 0;
    else
        return j;
}

/***************************************************************************
  �������ƣ�tj_strstr
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��1�γ��ֵ�λ�ã�˳���Ǵ�����
  ���������const char str[], const char substr[]
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    int sL = tj_strlen(str);
    int subL = tj_strlen(substr);
    int i = 0, j = 0, k = 0;
    for (i = 0; i <= sL - subL; i++) {
        for (j = i, k = 0; k < subL && str[j] == substr[k]; j++, k++);
        if (k == subL)
            return i + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strrchr
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��1�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  ���������const char str[],const char ch
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    int sL = tj_strlen(str);
    int j = sL + 1;
    for (int i = 0; i < sL; i++) {
        if (str[sL - i] != ch)
            j--;
        else
            break;
    }
    if (j > sL)
        return 0;
    else
        return j;
}

/***************************************************************************
  �������ƣ�tj_strrstr
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��1�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  ���������const char str[], const char substr[]
  �� �� ֵ��j
  ˵    ����
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    int sL = tj_strlen(str);
    int subL = tj_strlen(substr);
    int i = 0, j = 0, k = 0;

    for (i = sL - subL; i >= 0; i--) {
        for (j = i, k = 0; k < subL && str[j] == substr[k]; j++, k++);
        if (k == subL)
            return i + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strrev
  ��    �ܣ��ַ�����ת������ԭ����
  ���������char str[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strrev(char str[])
{
    int sL = tj_strlen(str);
    int t = 0;
    for (int i = 0; i < (sL + 1) / 2; i++) {
        t = str[i];
        str[i] = str[sL - 1 - i];
        str[sL - 1 - i] = t;
    }
    return 0;
}