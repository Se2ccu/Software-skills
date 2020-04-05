 /******************************************************************************
  文 件 名   : my_strlen.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年8月27日
  最近修改   :
  功能描述   : strlen复现，采用迭代的方法实现，每次迭代strlen+1，并且指针后移。
  函数列表   : 
  修改历史   :
  1.日    期   : 2018年8月27日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
******************************************************************************/ 

#include <stdio.h>
#include <assert.h>

int my_strlen(char* strDest)
{
	assert(strDest != NULL); //需要头文件
	if (*strDest == '\0')
	{
		return 0;
	}
	else
	{
		return (1+my_strlen(++strDest)); //或者(1+my_strlen(strDest+1)),但++不能再strDest之后
	}
}


int main()
{
	char* a= "helloworld";
	printf("my_strlen(\"helloworld\")=%d\n",my_strlen(a));
	return 0;
}
