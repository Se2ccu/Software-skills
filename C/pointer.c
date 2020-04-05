 /******************************************************************************
  文 件 名   : pointer.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年7月26日
  最近修改   :
  功能描述   : 学习指针的使用
  函数列表   : 
  修改历史   :
  1.日    期   : 2018年7月26日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
******************************************************************************/ 

#include <stdio.h>

int main()
{
	int *p;
	printf("sizeof(*p)=%d\n",sizeof(void *)); //指针的大小都是32位，这是由于地址的位数决定的。前面的数据类型表示，该地址保存的数据的类型。
	int i=0;
	printf("int i pointer is %d\n",&i);
	p=&i; //p指针的地址指向i
	*p=NULL; //p的地址内容没变，但是其指向的内容变成0
	printf("*p=%d\n",*p);
	//将数值储存到指定内存地址
	p=0x0022FF18;//32位
	*p=0x100;
	* (int*) 0x0022FF18=0x100;
	printf("pointer to designated address，*p changed to 0x100 int i=%d\n",*p);
	return 0;
}
