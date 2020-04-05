 /******************************************************************************
  文 件 名   : checksystem.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年7月11日
  最近修改   :
  功能描述   : 判断系统储存模式是大端还是小端
  函数列表   : Is_big_endian()
  修改历史   :
  1.日    期   : 2018年7月11日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
    
******************************************************************************/ 
// <<C语言深度解剖>> 1.15 union关键字
// 储存模式是大端还是小端
// int a=1 数据字节从高到低是：0x00000001 地址一般是低地址在前
// 大端就是就是一般而言。高字节放到最前面的低地址
// 小端就是高字节放到了高字节
#include <stdio.h>
int Is_big_endian()
{
	union checkSystem // union的成员共用存储空间，数据成员有相同的数据地址，指向低地址 
	{
		//double a;
		int i;
		char ch;
	} c;
	c.i=1;
	printf("union has %d Bytes\n",sizeof(c));
	return(c.ch==0); //如果低地址是0，就是大端，反之是小端 

}
int main()
{
	if (Is_big_endian())
		printf("Big Endian\n");
	else
		printf("Little Endian\n");
	return 0;
}
