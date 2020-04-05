 /******************************************************************************
  文 件 名   : define_macro.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年7月16日
  最近修改   :
  功能描述   : 宏定义学习（预处理），<<C语言深度解剖>> 3.1 宏定义等
  函数列表   : 
  修改历史   :
  1.日    期   : 2018年7月16日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
    
******************************************************************************/ 

#include <stdio.h>
//数值宏常量
#define PI 3.141592654 //演技高超的替身演员，从本行宏定义开始，后面就认识这个宏(这个替身演员)，实际上看的是他后面定义的东西
#define ERROR_POWEROFF -1 //防止函数返回魔鬼数，用文字表示-1

//字符串宏常量
#define PATH_1 D:\\China //到底是双反斜杠还是单，依系统而定
#define PATH_2 "D:\\China"
//最后一个反斜杠是接续符
#define PATH_3 "D:\\China\\hello\\\
world"

//define宏定义表达式,千万别吝啬括号，变量和结果都得加上
#define SEC_A_YEAR (60*60*24*365)
#define SQR(x) ((x)*(x))
#define SUM(x) ((x)+(x))
#define my_SUM(x) printf("The my square of "#x" is %d.\n", ((x)+(x))) //用#做预处理，这样能动态显示x

//宏撤销，相当于宏的作用域
#define X 3
#define Y 2*X
#undef X //撤销宏定义，
#define X 2 //此时X为2，X=3已被撤销

#define ID "replacementlist"

#define GPIO(n) IO##n

#define SMS_NULL_PTR                0L //long型
int main()
{
	// char *str=PATH_1;
	// printf(str);
	printf(PATH_2);
	printf("\n");
	printf(PATH_3);
	printf("\n");
	int z=Y;
	printf("Y=%d",z);
	printf("\n");

	printf("hello world\n");
	int a=222;
	printf("The sum of X is %d.\n",SUM(a));
	printf("The square of X is %d.\n",SQR(a));
	int my_add=my_SUM(1);
	
	char GPIO(3) =0x01;
	printf("IO3=%d\n",GPIO(3)); //使用还是有点问题
	printf(ID);
	printf("\n");
	
	printf("sizeof(SMS_NULL_PTR)=0L=%d\n",sizeof(SMS_NULL_PTR));
	
	//#error预处理指令,编译错误提示，停止编译
	// #if 1
		// #error "Boom Clap!!"
	// #endif
	#ifdef ID
	#pragma message("ID MACRO ACTICIVATED")
	#endif
	return 0;
}
