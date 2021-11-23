 /******************************************************************************
  文 件 名   : strcut_changed_array.c
  作    者   : Zhoutaoccu
  生成日期   : 2021年6月11日
  功能描述   : 结构体变长数组 变长数组（variable-length array)，也简称VLA
  1.日    期   : 2020年6月11日
    修改内容   : 创建文件
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct //变长结构体数组
{
    int len;
	int array[]; // 等同于array[0]
} Stu1; //直接用stu1定义结构体，而不是struct stu1 one

int main()
{
    printf("sizeof(Stu1)=%d\n", sizeof(Stu1)); // 4

    int len = MAX_LENGTH;
    Stu1 *s1 = (Stu1 *)malloc(sizeof(Stu1) * sizeof(int) * len);
    s1->len = len;

    for (int i = 0; i < s1->len; i++) {
        s1->array[i] = i;
    }

    int msgLen = sizeof(Stu1) + sizeof(int) * s1->len;
    int targetIndex = MAX_LENGTH + 1;

    /* 变长数组越界判断：变长内容不能大于整体数据长度 */
    if ((msgLen < sizeof(Stu1) + sizeof(int) * targetIndex)
        || (msgLen < sizeof(Stu1) + sizeof(int))
        || (targetIndex > MAX_LENGTH)
        || (targetIndex < 0)) {
        printf("Segment Fault\n");
    } else {
        printf("s1.arrlay[%d] = %d\n", len, s1->array[len]);
    }

    return 0;
}
