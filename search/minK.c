/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 生产线消耗电容的最小速度K，在lengthTime内消耗完一批N份电容
 * 仓库电容分为N份，每份有part[i]个，消耗完一份才消耗下一份，每分钟消耗K个，如果小于K则剩余时间空闲，直到下一分钟才消耗下一份
 * 距离下份电容上限前有lengthTime分钟，请计算最小速度K
 * input : 电容数组 part[] 剩提供最大时长 lengthTime
 * output: K 范围[1,MAX(parts)], K = MAX(parts)时，耗时 N <= lengthTime
 * Author:  周涛
 * Data: 2021-11-30 23:22:51
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool CheckOk(int *parts, int num, int mid, int lengthTime)
{
    int costTime = 0;
    int temp = 0;
    for (int i = 0; i < num; i++) {
        temp = parts[i] % mid;
        costTime += parts[i] / mid;
        if (temp > 0) {
            costTime += 1;
        }
    }
    return costTime <= lengthTime ? true : false;
}

/*
 * K越大，用时越少，在满足lengthTime的情况下，最小的K
 */
int minConsumingSpeed(int *parts, int nums, int lengthTime)
{
    qsort(parts, nums, sizeof(int), cmp);
    int K = 1;
    int low = 1;
    int high = parts[nums - 1];
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // printf("low, high mid = [%d, %d] %d\n", low, high, mid);
        /* 等效于求K得左边界,即K的最小值 */
        if (CheckOk(parts, nums, mid, lengthTime)) {
            K = mid;
            printf("K = %d\n", K);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return K;
}

int main(int argc, char *argv[])
{
    int a[5] = {3, 6, 7, 11};
    int lengthTime = 8;
    int result = minConsumingSpeed(a, 4, lengthTime);
    printf("%d\n", result);
    return 0;
}
