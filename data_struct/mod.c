/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: MOD取余操作
 * Author:  XXX
 * Data: 2022-03-16 01:29:57
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 260
#define MOD_NUM 7

/* 正常情况 */
int funcname()
{
    int a = 0;
    int modRes;
    /* 保证能够连续在[0, MOD_NUM] */
    for (int i = 0; i < MAX_NUM; i++) {
        a = (a + 1) % MOD_NUM; // 限定a不会翻转，达到MOD_NUM就给她翻转了
        modRes = a;
        printf("i = %d mod = %d\n", i, modRes);
    }
    return 0;
}

/* 异常情况，如果计数翻转会出现不连续的情况 */
int funcname1()
{
    unsigned char a = 0;
    int modRes;
    /* 不能保证结果在[0, MOD_NUM]连续 */
    for (int i = 0; i < MAX_NUM; i++) {
        modRes = a % MOD_NUM;
        a++;
        printf("i = %d mod = %d\n", i, modRes);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    funcname1();
    funcname();
    return 0;
}



