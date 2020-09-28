 /******************************************************************************
  文 件 名   : strcut_aline.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年8月28日
  最近修改   :
  功能描述   : 结构体内存对齐
  函数列表   : 
  修改历史   :
  1.日    期   : 2018年8月28日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
******************************************************************************/ 

#include <stdio.h>
typedef struct //stu1,不用typedef就这样写
{
	int i;
	char c;
	int j;
}stu1; //直接用stu1定义结构体，而不是struct stu1 one


int main()
{   
	//struct stu1 my_stuct;
	stu1 my_stu1;
	printf("sizeof(stu1)=%d\n", sizeof(stu1));//结构体名
	printf("sizeof(my_stu1)=%d\n", sizeof(my_stu1));//结构体具体的例子
	return 0;     
} 
