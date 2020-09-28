 /******************************************************************************
  文 件 名   : my_string.c
  作    者   : Zhoutaoccu
  生成日期   : 2020年9月29日
  功能描述   : 字符串处理,ilearning 《C语言实战》
******************************************************************************/ 

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{   
	// 字符串初始化
    const char *ptr1 = "Something is pointing at me.";  // 指针指向字符串，字符串在静态存储区
    const char ar1[] = {"Something is pointing at me."};    // ar1在栈中，分配ar1并初始化
	printf("point pstr1 = %s sizeof(pstr1) = %u, len is %u\n", ptr1, sizeof(ptr1), strlen(ptr1));
	printf("array string = %s sizeof(ar1) = %u, len is %u\n", ar1, sizeof(ar1), strlen(ar1));
    
    const char *str = "hello";
    char str1[] = {"hello"};
    char str2[] = "hello";
    char str3[] = {'h', 'e', 'l', 'l', 'o'}; // 异常打印
    char str4[] = {'h', 'e', 'l', 'l', 'o', 0};
    // char str5[5] = {"hello"};
    char str6[6] = {"hello"};
    char* str7[2] = {"hello", "world"}; // 指针数组，两个指针分别指向不同的字符串
    const char *str8 = {"hello"};
    
    printf("\nstr is %s, point = [%p], sizeof(str) is %u, len is %u", str, str, sizeof(str), strlen(str));
    printf("\nstr1 is %s, point = [%p], sizeof(str) is %u, len is %u", str1, str1, sizeof(str1), strlen(str1));
    printf("\nstr2 is %s, point = [%p], sizeof(str) is %u, len is %u", str2, str2, sizeof(str2), strlen(str2));
    printf("\nstr3 is %s, point = [%p], sizeof(str) is %u, len is %u", str3, str3, sizeof(str3), strlen(str3));
    printf("\nstr4 is %s, point = [%p], sizeof(str) is %u, len is %u", str4, str4, sizeof(str4), strlen(str4));
    printf("\nstr6 is %s, point = [%p], sizeof(str) is %u, len is %u", str6, str6, sizeof(str6), strlen(str6));
    printf("\nstr7[0] is %s, point = [%p], sizeof(str) is %u, len is %u", str7[0], str7[0], sizeof(str7[0]), strlen(str7[0]));
    printf("\nstr7[1] is %s, point = [%p], sizeof(str) is %u, len is %u", str7[1], str7[1], sizeof(str7[1]), strlen(str7[1]));
    printf("\nstr8 is %s, point = [%p], sizeof(str) is %u, len is %u", str8, str8, sizeof(str8), strlen(str8));
    // char str4[] = {'h', 'e', 'l', 'l', 'o', 0};
	return 0;     
} 
 