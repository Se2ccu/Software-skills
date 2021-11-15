​
 /******************************************************************************
  文 件 名   : DAG\stringNumCode.c
  作    者   : Zhoutaoccu
  生成日期   : 2021年11月16日
  功能描述   : 判断编码字符是否符合格式，且无歧义。数字 + N个字符串
  1.日    期   : 2021年11月16日
    修改内容   : 创建文件
******************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>

int GetLength(char *encodedString)
{
    int i = 0;
    int encLen = 0;
    int retLen = -1;
    int subLen;
    int successTime = 0;
    char *es = encodedString;
    int strLen = strlen(es);
    /* 递归结束标记 */
    if (strLen == 0)
    {
        return 0;
    }

    if (strLen == 1 || es[0] == '0')
    {
        return -1;
    }

    while (isdigital(es[i]))
    {
        encLen = encLen * 10 + es[i] - '0';
        i++;
        if (encLen > (strLen - i))
        {
            break;
        }
        
        /* 迭代求解 */
        if ((subLen = GetLength(es + i + encLen)) != -1)
        {
            retLen = encLen + subLen;
            if (++successTime > 1)
            {
                return -1;
            }
        }
    }

    return retLen;
}

​