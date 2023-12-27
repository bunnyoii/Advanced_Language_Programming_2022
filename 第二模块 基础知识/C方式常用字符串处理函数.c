//C方式常用的字符串处理函数

/*	strlen(const char s[]);												*/
/*	strcat(char dst[], const char src[]);								*/
/*	strncat(char dst[], const char src[], const unsigned int len);		*/
/*	strcpy(char dst[], const char src[]);								*/
/*	strncpy(char dst[], const char src[], const unsigned int len);		*/
/*	strcmp(const char s1[], const char s2[]);							*/
/*	strncmp(const char s1[], const char s2[], const unsigned int len);	*/

/***************************************************************************
  函数名称：strlen
  功    能：求字符串的长度
  输入参数：s[] ：存放字符串的字符数组
  返 回 值：整型值表示的长度
  说    明：返回第一个'\0'前(不含'\0')的字符数量
***************************************************************************/
strlen(const char s[]);

/***************************************************************************
  函数名称：strcat
  功    能：将字符串src(含尾零)连接到字符串dst的尾部
  输入参数：dst[] ：存放字符串dst的字符数组dst
            src[] ：存放字符串src的字符数组src(只读)
  返 回 值：改变后的字符数组dst
  说    明：字符数组dst要有足够的空间(两字符串总长度+1)
***************************************************************************/
strcat(char dst[], const char src[]);

/***************************************************************************
  函数名称：strncat
  功    能：将字符串src的前n个字符连接到字符串dst的尾部
  输入参数：dst[] ：存放字符串dst的字符数组dst
            src[] ：存放字符串src的字符数组src(只读)
            len   ：要复制的长度(只读)
                    (如果len超过字符数组src的长度，则只连接src字符串长度个字符)
  返 回 值：改变后的字符数组dst
  说    明：字符数组dst要有足够的空间(原dst字符串长度+min(dst字符串长度,len)+1)
***************************************************************************/
strncat(char dst[], const char src[], const unsigned int len);

/***************************************************************************
  函数名称：strcpy
  功    能：将字符串src(含尾零)复制到字符串dst中，覆盖原dst串
  输入参数：dst[] ：存放字符串dst的字符数组dst
            src[] ：存放字符串src的字符数组src(只读)
  返 回 值：改变后的字符数组dst
  说    明：字符数组dst要有足够的空间(max(dst字符串长度,src字符串长度)+1)
***************************************************************************/
strcpy(char dst[], const char src[]);

/***************************************************************************
  函数名称：strncpy
  功    能：将字符串src(不含尾零)的前n个字符复制到字符串dst中，覆盖原dst串
  输入参数：dst[] ：存放字符串dst的字符数组dst
            src[] ：存放字符串src的字符数组src(只读)
            len   ：要复制的长度(只读)
                    (如果len超过字符数组src的长度，则只复制src字符串长度个字符)
  返 回 值：改变后的字符数组dst
  说    明：字符数组dst要有足够的空间(min(dst字符串长度,len)+1)
***************************************************************************/
strncpy(char dst[], const char src[], const unsigned int len);

/***************************************************************************
  函数名称：strcmp
  功    能：比较字符串s1和字符串s2的大小
  输入参数：s1[] ：存放字符串s1的字符数组s1(只读)
            s2[] ：存放字符串s2的字符数组s2(只读)
  返 回 值：整型值  0 - 相等
                   >0 - 字符串1大
                   <0 - 字符串1小
  说    明：无
***************************************************************************/
strcmp(const char s1[], const char s2[]);

/***************************************************************************
  函数名称：strncmp
  功    能：比较字符串s1和字符串s2的前n个字符的大小
  输入参数：s1[] ：存放字符串s1的字符数组s1(只读)
            s2[] ：存放字符串s2的字符数组s2(只读)
            len  ：要比较的长度(只读)
  返 回 值：整型值  0 - 相等
                   >0 - 字符串1大
                   <0 - 字符串1小
  说    明：无
***************************************************************************/
strncmp(const char s1[], const char s2[], const unsigned int len);