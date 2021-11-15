​/******************************************************************************
  文 件 名   : 11.Olympic_Game.c
  版 本 号   : 初稿
  作    者   : Zhoutaoccu
  生成日期   : 2020年2月11日
  最近修改   :
  功能描述   : 用qsort实现结构体排序
    
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char acCountryName[20];
    unsigned int ucGoldMedal;
    unsigned int ucSilverMedal;
    unsigned int ucBronzeMedal;
} stRankMedal_t, *pstRankMedal_t;

int bigger(const void *r1, const void *r2)
{
    pstRankMedal_t st_a = (pstRankMedal_t)r1;

    pstRankMedal_t st_b = (pstRankMedal_t)r2;

    if (st_a->ucGoldMedal != st_b->ucGoldMedal)
    {
        return st_a->ucGoldMedal > st_b->ucGoldMedal ? -1 : 1;
    }
    else if (st_a->ucSilverMedal != st_b->ucSilverMedal)
    {
        return st_a->ucSilverMedal > st_b->ucSilverMedal ? -1 : 1;
    }
    else if (st_a->ucBronzeMedal != st_b->ucBronzeMedal)
    {
        return st_a->ucBronzeMedal > st_b->ucBronzeMedal ? -1 : 1;
    }
    else
    {
        return strcmp(st_a->acCountryName, st_b->acCountryName);
    }
}

void swap(stRankMedal_t *p1, stRankMedal_t *p2)
{
    stRankMedal_t temp_struct;
    temp_struct = *p1;
    *p1 = *p2;
    *p2 = temp_struct;
}

void PrintSturct(stRankMedal_t *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", (p + i)->acCountryName);
    }
}

int main()
{
    int n;
    char temp_acCountryName[20];
    unsigned int temp_ucGoldMedal;
    unsigned int temp_ucSilverMedal;
    unsigned int temp_ucBronzeMedal;

    while (scanf("%d", &n) != EOF)
    {
        stRankMedal_t *pstRankMedal_t = (stRankMedal_t *)malloc(sizeof(stRankMedal_t) * n);

        for (int i = 0; i < n; i++)
        {
            scanf("%s %d %d %d", temp_acCountryName, &temp_ucGoldMedal, &temp_ucSilverMedal, &temp_ucBronzeMedal);
            strcpy(pstRankMedal_t[i].acCountryName, temp_acCountryName);
            pstRankMedal_t[i].ucGoldMedal = temp_ucGoldMedal;
            pstRankMedal_t[i].ucSilverMedal = temp_ucSilverMedal;
            pstRankMedal_t[i].ucBronzeMedal = temp_ucBronzeMedal;
        }

        // PrintSturct(pstRankMedal_t, n);

        qsort(pstRankMedal_t, n, sizeof(stRankMedal_t), bigger);

#if 0
        unsigned char flag = 1;
        while(flag)
        {
            flag = 0;
            for (int i = 1; i < n; i++)
            {
                if (((pstRankMedal_t[i - 1].ucGoldMedal * 10001) + (pstRankMedal_t[i - 1].ucSilverMedal * 101) + (pstRankMedal_t[i - 1].ucBronzeMedal)) < 
                    ((pstRankMedal_t[i].ucGoldMedal * 10001) + (pstRankMedal_t[i].ucSilverMedal * 101) + (pstRankMedal_t[i].ucBronzeMedal)))
                {
                    swap(pstRankMedal_t + i, pstRankMedal_t + i - 1);
                    flag = 1;
                }
                else if (((pstRankMedal_t[i - 1].ucGoldMedal * 10001) + (pstRankMedal_t[i - 1].ucSilverMedal * 101) + (pstRankMedal_t[i - 1].ucBronzeMedal)) == 
                    ((pstRankMedal_t[i].ucGoldMedal * 10001) + (pstRankMedal_t[i].ucSilverMedal * 101) + (pstRankMedal_t[i].ucBronzeMedal)))
                {
                    if (strcmp(pstRankMedal_t[i - 1].acCountryName, pstRankMedal_t[i].acCountryName) > 0)
                    {
                        swap(pstRankMedal_t + i, pstRankMedal_t + i - 1);
                        flag = 1;
                    }
                }
                
            }
        }
#endif

        PrintSturct(pstRankMedal_t, n);
        free(pstRankMedal_t);
    }
    return 0;
}