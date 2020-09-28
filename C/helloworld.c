 /******************************************************************************
  文 件 名   : helloworld.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2018年7月16日
  最近修改   :
  功能描述   : Hello world，用条件编译和宏定义实现稍微高端的helloworld，和最原始的对比
  函数列表   : 
  修改历史   :
  1.日    期   : 2018年7月16日
    作    者   : Zhoutaoccu
    修改内容   : 创建文件
  2.日    期   : 2018年7月26日
	作    者   : Zhoutaoccu
	修改内容   : 增加<<C语言深度解剖>>第二章符号章节
******************************************************************************/ 

#include <stdio.h>
#define ADVANCE_HELLO 1
#define ID "Hello World!\n"
int main()
{
	#ifdef ADVANCE_HELLO //条件编译主要用于调试，定义了就执行，等到最后发布的时候就不定义，就不执行了
	printf(ID);
	#else
	printf("hello world\n");
	#endif  
    
	//char str1[10]={"HelloWorld!\n"}; // error缓冲区长度不够
	char str1[20]="HelloWorld!\n";

	// char str2[20]={"H", "e", "l", "l", "o", "W","o","r","l","d","!","\n"}; //error 初始化太多
	char str2[20]={'H', 'e', 'l', 'l', 'o', 'W','o','r','l','d','!','\n'}; //error 初始化太多
    
    char *str3 = "HelloWorld!\n";
	printf("whole str is %s\n", str1);
	printf("single character together is %s\n", str2);
	printf("point character together is %s\n", str3);
    
    int a, b;
    if (scanf("%d%d", &a, &b) != EOF) {
        //return -1;
    }
    
    printf("1# dd is %d + %d\n", a, b);
    
    if (scanf("%d %d", &a, &b) != EOF) {
        //return -1;
    }
    printf("2# d d is %d + %d\n", a, b);
    
    if (scanf("%d,%d", &a, &b) != EOF) {
        //return -1;
    }
    printf("3# d,d is %d + %d\n", a, b);
	
    if (scanf("%d, %d", &a, &b) != EOF) {
        //return -1;
    }
    printf("4# d, d is %d + %d\n", a, b);

#if 0
	int/* ... */i; //注释相当于空格
	//Is it\
	a valid comment?
	//in/* ... */t i; //error
	char char_a=0x61;//01100001 ASCII码对应字符a
	printf("char_a=printf(int)=%d\n",char_a);
	printf("char_a=printf(char)=%c\n",char_a);
	int a=1;
	char b='1';
	char *c="1";
	printf("The sizeof(1) is %d\n",sizeof(a));
	printf("The sizeof('1') is %d\n",sizeof(b));
	printf("The sizeof(\"1\") is %d\n",sizeof(c));
	printf("The sizeof('1'+1) is %d\n",sizeof(b+1));
	printf("'1'+1 is %d\n",b+1);
	printf("%d\n",0x01<<2+3);//位操作符，超过数据位数或者为负数，则结果为0
	printf("0x0F=%d\n",0x0F);//int 整形有32位，最高为符号位
	printf("0xFF=%d\n",0xFF);
	printf("int max =%d\n",0x7FFFFFFF);//int 最大正数。0-0x7FFFFFFF是正数范围，然后再加一就是最大负数，然后慢慢增大，直到0xFFFFFFFF为-1.
	printf("int min =%d\n",0x10000000);//int 最小负数，储存是按照补码存档，所以实际上是负的最大值，比最大的正数二进制加一。对于0x00000000和0x10000000都是+0和-0，浪费了一个空间，所以用补码表示负数，把-0变成负的最小值。
	

	i=3;
	printf("(++i)+(++i)+(++i)=%d\n",(++i)+(++i)+(++i));
	
	//用逗号分开的表达式的值分别结算，但整个表达式的值是最后一个表达式的值。
	i=0;
	int j=(i++,i++,i++);
	printf("j=(i++,i++,i++)=%d\n",j);
	
	// for ((i=0,printf("First is %d\n",i));(i<1,printf("Second is %d\n",i));(i++,printf("Fourth is %d\n",i))) //这里的逗号运算，循环判断没什么用，逗号运算只看最后一个表达式，所以在second和Fourth间不断叠加
	// {
		// printf("Third is %d",i);
	// }
	
	i=0;
	j=(i++) + (i++) + (i++);
	printf("j=(i++) + (i++) + (i++)=%d\n",j);
	
	printf("2/(-2)=%d\n",2/(-2));
	printf("2\%(-2)=%d\n",2%(-2));
#endif
	return 0;
}
