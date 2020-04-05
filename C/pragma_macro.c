 /******************************************************************************
  文 件 名   : pragma_macro.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年7月16日
  最近修改   :
  功能描述   : #pragma学习（预处理），<<C语言深度解剖>> 3.6
  函数列表   : 
  修改历史   :
  1.日    期   : 2018年7月16日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
    
******************************************************************************/ 

#include <stdio.h>
//通过宏定义的不同来控制两个版本：一个开发调试，一个最终发布
// #define BUILD_VERSION 0
#define FINAL_VERSION 1 
//简单结构体
//https://www.cnblogs.com/0201zcr/p/4789332.html
//（1）[内存对齐]结构体变量中成员的偏移量必须是成员大小的整数倍[相当于前面的变量要刚刚好等于后面新进来的成员，然后一一对应，把零散的成员，拼凑成和后面大成员一样的内存]
//（2）结构体大小必须是所有成员大小的整数倍，也即所有成员大小的公倍数。

struct TestStruct1 //编译器自动让其内存对齐，结构体的大小是所有成员大小的公倍数。在寻址的时候可以采用固定的间隔2,4,8,16而不是1，2,1
{
	char c1;
	short s;
	char c2;
	int i;
};//内存布局（*表示空闲，1表示内存占用1Byte），(1*,11),1***,1111
struct TestStruct2 //本身就是内存对齐的，编译器无需操作
{
	char c1;
	char c2;
	short s;
	int i;
};//内存布局（*表示空闲，1表示内存占用1Byte），(1,1),11,1111

//嵌套结构体
//（1）展开后的结构体的第一个成员的偏移量应当是被展开的结构体中最大的成员的整数倍。
//（2）结构体大小必须是所有成员大小的整数倍，这里所有成员计算的是展开后的成员，而不是将嵌套的结构体当做一个整体。
#pragma pack(8) //指定对齐参数，但实际对齐参数取指定参数和成员大小的最小值
struct TestStruct4 
{
	char a;
	int b;
};//内存布局（*表示空闲，1表示内存占用1Byte），1***,1111
struct TestStruct5 
{
	char c;
	struct TestStruct4 d; //记得写struct数据类型
	long long e;
};//内存布局（*表示空闲，1表示内存占用1Byte），(1***,1***),(1111,****),11111111 为了和后面的配对，加上4个空字节
#pragma pack()

int main()
{
	//#error预处理指令,编译错误提示，停止编译
	// #if 1
		// #error "Boom Clap!!"
	// #endif
	
	//#pragma message 在编译过程中输入提示信息。结合条件编译，控制版本。比如版本1对应一个宏定义，比如"BUILD_VERSION"\
	版本2对应"FINAL_VERSION"，可以在编译中就告诉开发者，现在在开发哪个版本
	#ifdef BUILD_VERSION
	printf("No more BUG, OK?");
	#endif
	#ifdef FINAL_VERSION
	printf("Finally Success! We can go home to have a sleep!");
	#endif
	
	#ifdef BUILD_VERSION
	#pragma message("BUILD_VERSION MACRO ACTICIVATED")
	#endif
	#ifdef FINAL_VERSION
	#pragma message("FINAL_VERSION MACRO ACTICIVATED") //这个好像并不会在运行窗口显示
	#endif
	
	//#pragma pack内存对齐,一般用于结构体的定义
	//定义前面使用#pragma pack(n)，编译器将按照n各字节对齐
	//定义后面使用#pragma pack(),编译器将取消自定义字节对齐方式
	//最终对齐的规则：按照每个成员中类型的大小和指定对齐字节的最小值确定
	struct TestStruct1 st1;
	printf("\n c1 %p\n s %p\n c2 %p\n i %p\n",
	(unsigned int)(void*)&st1.c1-(unsigned int)(void*)&st1,
	(unsigned int)(void*)&st1.s-(unsigned int)(void*)&st1,
	(unsigned int)(void*)&st1.c2-(unsigned int)(void*)&st1,
	(unsigned int)(void*)&st1.i-(unsigned int)(void*)&st1);
	printf("sizeof(TestStruct1)=%d\n",sizeof(st1));
	
	struct TestStruct2 st2;
	printf("c1 %p\n s %p\n c2 %p\n i %p\n",
	(unsigned int)(void*)&st2.c1-(unsigned int)(void*)&st2,
	(unsigned int)(void*)&st2.c2-(unsigned int)(void*)&st2,
	(unsigned int)(void*)&st2.s-(unsigned int)(void*)&st2,
	(unsigned int)(void*)&st2.i-(unsigned int)(void*)&st2);
	printf("sizeof(TestStruct2)=%d\n",sizeof(st2));
	
	struct TestStruct4 st4;
	printf("a %p\n b %p\n",
	(unsigned int)(void*)&st4.a-(unsigned int)(void*)&st4,
	(unsigned int)(void*)&st4.b-(unsigned int)(void*)&st4);
	printf("sizeof(TestStruct4)=%d\n",sizeof(st4));
	return 0;
}
