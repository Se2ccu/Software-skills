/***********************************************************************
 * @file auto_adapte.c
     AUTO_ADAPTE
 * @brief   header file
 * @history
 * Date       Version Author    description
 * ========== ======= ========= =======================================
 * 2021-07-14 V1.0    Wukong.SUN   Create
 *
 * @Copyright (C)  2021  .cdWFVCEL. all right reserved
***********************************************************************/

#include <stdio.h>


#define HEAD_OFFSET sizeof(int) + 10
int main(int arg, int* argv)
{
    char a[HEAD_OFFSET] = "WORLD";
    printf("%s \n", a);
    return 0;
}