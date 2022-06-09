/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 结构体指定初始化 并用函数实现
 * Author:  zhoutao
 * Data: 2022-05-17 02:01:57
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int a;
    int b;
} Stu1;

void FillStruct(Stu1 *s1, Stu1 *s2)
{
    Stu1 s = {
        .a = s2->a,
        .b = s2->b,
    };

    *s1 = s;
}

int main(int argc, char *argv[])
{
    Stu1 s2 = {5, 6};
    Stu1 s1 = {
        .a = 1,
        .b = 1,
    };

    FillStruct(&s1, &s2);

    printf("s1.a = %d, s1.b = %d\n", s1.a, s1.b);
    return 0;
}
