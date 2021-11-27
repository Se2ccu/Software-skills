/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 流量令牌更新和数据传输使用令牌系统
 * Author:  周涛
 * Data: 2021-11-27 23:14:48
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_RULE_NUM 1000
typedef struct {
    int tokenLimit;
    int tokenSum;
    int ruleMatrix[MAX_RULE_NUM][4];
} TokenDataStru;


void CalcuTokenFunc(TokenDataStru *obj, int time)
{
    for (int i = 0; i < MAX_RULE_NUM; i++) {
        if (obj->ruleMatrix[i][0] == 0) {
            continue;
        }
        int beginTime = obj->ruleMatrix[i][1];
        int interval = obj->ruleMatrix[i][2];
        int number = obj->ruleMatrix[i][3];
        obj->tokenSum += ((time - beginTime) / interval) * number;
        obj->ruleMatrix[i][1] = time;
        obj->tokenSum = fmin(obj->tokenSum, obj->tokenLimit);
    }
}

/*
 * 初始化令牌系统, 令牌限制是当前时刻及之前所有令牌积累之和，要小于该限制
 */
TokenDataStru* RateLimitSystem(int tokenLimit)
{
    TokenDataStru *obj = (TokenDataStru*)malloc(sizeof(TokenDataStru));
    if (obj == NULL) {
        return NULL;
    }
    memset(obj, 0, sizeof(TokenDataStru));
    obj->tokenLimit = tokenLimit;
    obj->tokenSum = 0;
    return obj;
}

bool AddRule(TokenDataStru* obj, int ruleId, int beginTime, int interval, int number)
{
    if (obj->ruleMatrix[ruleId][0] == 1) {
        return false;
    }

    obj->ruleMatrix[j][0] = 1;
    obj->ruleMatrix[j][1] = beginTime;
    obj->ruleMatrix[j][2] = interval;
    obj->ruleMatrix[j][3] = number;
    obj->tokenSum = fmin(obj->tokenSum + number, obj->tokenLimit);
    return true;
}

/*
 * 先看是否能更新此时的令牌，然后删除规则
 */
int RemoveRule(TokenDataStru* obj, int ruleId, int time)
{
    if (obj->ruleMatrix[ruleId][0] == 0) {
        return false;
    }
    CalcuTokenFunc(obj, time);
    obj->ruleMatrix[ruleId][0] = 0;
    return true;
}

/*
 * 某时刻传输数据，按照规则生成的令牌，只有该时刻及以前生成的能够使用，所以要计算当前时刻剩余的令牌数
 */
bool TransferData(TokenDataStru* obj, int time, int size)
{
    CalcuTokenFunc(obj, time);
    if (size > obj->tokenSum) {
        return false;
    }
    obj->tokenSum -= size;
    return true;
}

/*
 * 现在某时刻生成令牌，然后查询
 */
int QueryToken(TokenDataStru* obj, int time)
{
    CalcuTokenFunc(obj, time);
    return obj->tokenSum;
}

void FreeToken(TokenDataStru* obj)
{
    free(obj);
}

