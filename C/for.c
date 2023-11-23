/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 打印多字节的码流 + 双重循环，相同循环变量导致死循环
 * Author:  XXX
 * Data: 2022-10-21 16:29:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <securec.h>
#define ZT 

#define GNSS_LOGBASIC_FILE_END_FLAG   0x415A5A5A

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    unsigned int endFlag = GNSS_LOGBASIC_FILE_END_FLAG;
    int *ptr = (int *)malloc(sizeof(int)*10);
    /* 代码1 */
    printf("%s", &endFlag); // 会逐字节打印出对应的字符，小端系统打印出来会反序

    /* 等效代码1 */
    unsigned char *a = (unsigned char *)&endFlag;
    for (int i = 0; i < 4; i++) {
        printf("single %c\n", a[i]);
    }

    int i;
    int cnt = 0;
    /* 双重循环用相同循环变量，会导致循环变量错乱，当(内层循环数 < 外层) 逻辑出错,导致死循环。主要是i的作用域
    i = 0在第一层循环中赋值，然后到第二层重新赋值0，在第二层作用域中叠加到4，并且最后还会i++到5，返回第一层时i = 5，
    而不再是期望的0。然后在第一层i++，变为i = 6.导致后续永远无法退出第一层循环 */
    for (i = 0; i < 10; i++) {
    #ifdef ZT
        printf("1st = %d\n", i);
    #endif
        for (i = 0; i < 5; i++) {
            printf("2st = %d\n", i);
            cnt++;
            
        }
        if (cnt == 50) {
            break;
        }
    }
    return 0;
}
