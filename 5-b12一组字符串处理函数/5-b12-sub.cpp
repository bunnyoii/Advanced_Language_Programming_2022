/* 2251730 信07 刘淑仪 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串长度
  输入参数：const char str[]
  返 回 值：字符串长度
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    int sum = 0;
    for (int i = 0; i < 114514 && str[i] != '\0'; i++)
        sum += 1;

    return sum;
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将字符串s2追加到s1后面，含\0
  输入参数：char s1[],const char s2[]
  返 回 值：0
  说    明：
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
  函数名称：tj_strncat
  功    能：将字符串s2的前len个字符追加到s1后面，并添加\0
  输入参数：char s1[],const char s2[]
  返 回 值：0
  说    明：
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
  函数名称：tj_strcpy
  功    能：将字符串s2复制到s1中，覆盖s1中原内容，复制时不含\0.
  输入参数：char s1[], const char s2[]
  返 回 值：0
  说    明：
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
  函数名称：tj_strncpy
  功    能：将字符串s2的前n个内容复制到s1中，复制时不含\0.
  输入参数：char s1[], const char s2[]
  返 回 值：0
  说    明：
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
  函数名称：tj_strcmp
  功    能：比较字符串s1和s2的大小，英文字母要区分大小写
  输入参数：const char s1[],const char s2[]
  返 回 值：k
  说    明：
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
  函数名称：tj_strcasecmp
  功    能：比较字符串s1和s2的大小，英文字母不分大小写
  输入参数：const char s1[],const char s2[]
  返 回 值：j
  说    明：
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
  函数名称：tj_strncmp
  功    能：比较字符串s1和s2前len个字符的大小，英文字母要区分大小写
  输入参数：const char s1[],const char s2[],const int len
  返 回 值：j
  说    明：
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
  函数名称：tj_strcasencmp
  功    能：比较字符串s1和s2前len个字符的大小，英文字母不分大小写
  输入参数：const char s1[],const char s2[],const int len
  返 回 值：j
  说    明：
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
  函数名称：tj_strupr
  功    能：将字符串str中所有小写字母均转为大写，其他字符不变，转换后放在原
            串中
  输入参数：char str[]
  返 回 值：0
  说    明：
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
  函数名称：tj_strlwr
  功    能：将字符串str中所有大写字母均转为小写，其他字符不变，转换后放在原
            串中
  输入参数：char str[]
  返 回 值：0
  说    明：
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
  函数名称：tj_strchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从左到右
  输入参数：const char str[],char ch
  返 回 值：j
  说    明：
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
  函数名称：tj_strstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从左到右
  输入参数：const char str[], const char substr[]
  返 回 值：j
  说    明：
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
  函数名称：tj_strrchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从右到左
  输入参数：const char str[],const char ch
  返 回 值：j
  说    明：
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
  函数名称：tj_strrstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从右到左
  输入参数：const char str[], const char substr[]
  返 回 值：j
  说    明：
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
  函数名称：tj_strrev
  功    能：字符串反转，放入原串中
  输入参数：char str[]
  返 回 值：0
  说    明：
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