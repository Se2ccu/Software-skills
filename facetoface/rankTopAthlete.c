/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 系统设计题
 * Author:  Zhoutao
 * Data: 2022-05-15 23:57:49
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_USR_NUM 1001
#define MAX_TOP_NUM 3

typedef struct {
    int id;
    int dur;
    int index;
} User;

typedef struct {
    User arr[MAX_USR_NUM];
    int record[MAX_USR_NUM];
    int num;
} SkiRankingSystem;

SkiRankingSystem *SkiRankingSystemCreat(void)
{
    SkiRankingSystem *sys = (SkiRankingSystem *)malloc(sizeof(SkiRankingSystem));
    if (sys == NULL) {
        return NULL;
    }

    memset(sys, 0, sizeof(SkiRankingSystem));

    return sys;
}

void SkiRankingSystemAddRecord(SkiRankingSystem *sys, int userId, int duration)
{
    sys->arr[sys->num].id = userId;
    sys->arr[sys->num].dur = duration;
    sys->arr[sys->num].index = sys->num;
    sys->record[userId]++; /* 每个用户的记录频次统计 */
    sys->num++;
}

int Cmp(const void *a, const void *b)
{
    const User *u1 = (const User*)a;
    const User *u2 = (const User*)b;
    if (u1->dur == u2->dur) {
        return u1->index - u2->index;
    }

    return u1->dur - u2->dur;
}

/* 输出topN的用户id */
int *SkiRankingSystemGetTopAthletes(SkiRankingSystem *sys, int num, int *returnSize)
{
    int retNum = fmin(num, sys->num);
    *returnSize = 0;

    qsort(sys->arr, sys->num, sizeof(sys->arr[0]), Cmp);

    int *res = (int *)malloc(sizeof(int) * retNum);
    if (!res) {
        return NULL;
    }

    int table[MAX_USR_NUM] = {0};
    retNum = 0;
    for (int i = 0; i < sys->num; i++) {
        if (table[sys->arr[i].id] == 0) {
            res[retNum] = sys->arr[i].id;
            retNum++;
        }

        /* 只选择一个用户id */
        table[sys->arr[i].id] = 1;

        /* topN限制，提前退出 */
        if (retNum == num) {
            break;
        }
    }
    *returnSize = retNum;

    return res;
}

int CmpInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int *SkiRankingSystemQuerryTop3Record(SkiRankingSystem *sys, int userId, int *retSize)
{
    int retNum = fmin(sys->record[userId], MAX_TOP_NUM);
    *retSize = 0;

    int *res = (int *)malloc(sizeof(int) * retNum);
    if (!res) {
        return NULL;
    }

    int cnt = 0;
    for (int i = 0; i < sys->num; i++) {
        if (sys->arr[i].id == userId) {
            res[cnt] = sys->arr[i].dur;
            cnt++;
        }

        if (cnt == retNum) {
            break;
        }
    }

    qsort(res, retNum, sizeof(res[0]), CmpInt);

    *retSize = retNum;

    return res;
}

void SkiRankingSystemFree(SkiRankingSystem *sys)
{
    free(sys);
}


int main(int argc, char *argv[])
{
    SkiRankingSystem *sys = SkiRankingSystemCreat();
    SkiRankingSystemAddRecord(sys, 3, 1);
    SkiRankingSystemAddRecord(sys, 2, 5);
    SkiRankingSystemAddRecord(sys, 2, 8);
    SkiRankingSystemAddRecord(sys, 1, 9);
    SkiRankingSystemAddRecord(sys, 1, 100);
    int returnSize;
    int *res1 = SkiRankingSystemGetTopAthletes(sys, 3, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res1[i]);
    }

    printf("\n");
    int retSize;
    int *res2 = SkiRankingSystemQuerryTop3Record(sys, 1, &retSize);
    for (int i = 0; i < retSize; i++) {
        printf("%d ", res2[i]);
    }
    SkiRankingSystemFree(sys);
    return 0;
}
