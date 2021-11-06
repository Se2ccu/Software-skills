 /******************************************************************************
  文 件 名   : strcut_changed_array.c
  作    者   : Zhoutaoccu
  生成日期   : 2018年8月28日
  功能描述   : 结构体变长数组
  1.日    期   : 2020年9月11日
    修改内容   : 创建文件
******************************************************************************/ 

#include <stdio.h>


typedef struct //边长结构体数组
{                                                                                                                                
	int len;  
	char c[]; // 等同于c[0]
} Stu1; //直接用stu1定义结构体，而不是struct stu1 one


int main()      
{       
  printf("sizeof(s_stu1)=%d\n", sizeof(Stu1)); // 4
  return 0;

}
