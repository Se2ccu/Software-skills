/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 根据物理机的容量，虚拟机数量，虚拟机编号，填充优先级队列。选择出最优的物理机编号
 * Author:  【优先队列的结构体排序】很典型的题目
 * Data: 2024-10-23 15:21:02
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "securec.h"
#include "vos_priorityqueue.h"

typedef struct userData {
    int cap;
    int num;
    int index;
} UserData;

// 按照容量降序排列，按照已有虚拟机数量升序排列，按照编号升序排列。优先选择容量大的，数量少的，编号小的。
static inline int32_t cmpFunc2(uintptr_t data1, uintptr_t data2)
{
    UserData *tmpData1 = (UserData *)data1;
    UserData *tmpData2 = (UserData *)data2;
    if (tmpData1->cap != tmpData2->cap) {
        return tmpData1->cap > tmpData2->cap ? 1 : -1;
    } else if (tmpData1->num != tmpData2->num) {
        return tmpData1->num > tmpData2->num ? -1 : 1;
    } else {
        return tmpData1->index > tmpData2->index ? -1 : 1;
    }
}

uint32_t AddOneData(VosPriQue *priQueue, int cap, int num, int index)
{
    UserData data = {0, 0, 0};
    data.cap = cap;
    data.num = num;
    data.index = index;
    return VOS_PriQuePush(priQueue,(uintptr_t)&data);
}

void FillPriQueue(VosPriQue *priQueue, const int *capacities, size_t capacitiesSize)
{
    for (size_t i = 0; i < capacitiesSize; ++i) {
        AddOneData(priQueue, capacities[i], 0, i);
    }
}

static inline void *dupFunc(void *src)
{
    UserData *tmpSrc = (UserData *)src;
    UserData *data = (UserData *)malloc(sizeof(UserData));
    (void)memset_s(data, sizeof(UserData), 0, sizeof(UserData));

    data->cap = tmpSrc->cap;
    data->num = tmpSrc->num;
    data->index = tmpSrc->index;
    return data;
}

static int *DispatchRequests(const int *capacities, size_t capacitiesSize,
                             const int *requests, size_t requestsSize, size_t *returnSize)
{
    *returnSize = requestsSize;
    int *result = (int *)malloc(requestsSize * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    VosPriQue *priQueue;
    VosDupFreeFuncPair dataFunc = {dupFunc, free};
    priQueue = VOS_PriQueCreate(cmpFunc2, &dataFunc);
    FillPriQueue(priQueue, capacities, capacitiesSize);

    for (size_t i = 0; i < requestsSize; i++) {
        UserData *user = (UserData *)(VOS_PriQueTop(priQueue));  // 取出大顶堆的堆顶元素
        // printf("show cap: %d  num: %d  index: %d\n", user->cap, user->num, user->index);
        if (requests[i] > user->cap) {
            result[i] = -1;
            continue;
        }

        UserData new_user;
        new_user.cap = user->cap - requests[i];
        new_user.index = user->index;
        new_user.num = user->num + 1;

        VOS_PriQuePop(priQueue);  // 去除并更新堆顶元素
        AddOneData(priQueue, new_user.cap, new_user.num, new_user.index);
        // printf("new one cap: %d  num: %d  index: %d\n", new_user.cap, new_user.num, new_user.index);
        result[i] = new_user.index;
    }

    return result;
}

int main()
{
    const int capacities[] = {10, 32, 32, 64};
    const int requests[] = {32, 16, 33};
    size_t requestsSize = sizeof(requests) / sizeof(requests[0]);
    size_t returnSize = 0;

    int *result = DispatchRequests(capacities, sizeof(capacities) / sizeof(capacities[0]),
                                   requests, requestsSize, &returnSize);

    for (size_t i = 0; i < returnSize; i++) {
        printf("Request %zu: %d\n", i, result[i]);
    }

    free(result);

    return 0;
}

int main1()
{
    const int capacities[] = {100000, 60000};
    const int requests[] = {40000, 40000};
    size_t requestsSize = sizeof(requests) / sizeof(requests[0]);
    size_t returnSize = 0;

    int *result = DispatchRequests(capacities, sizeof(capacities) / sizeof(capacities[0]),
                                   requests, requestsSize, &returnSize);

    for (size_t i = 0; i < returnSize; i++) {
        printf("Request %zu: %d\n", i, result[i]);
    }

    free(result);

    return 0;
}
