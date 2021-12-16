/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Leetcode 875： 爱吃香蕉的珂珂
 * 珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。
 * 珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 * 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
 * 链接：https://leetcode-cn.com/problems/koko-eating-bananas
 * Author:  周涛
 * Data: 2021-12-05 23:31:17
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

bool CheckOK(int* piles, int pilesSize, int mid, int h)
{
    int sum = 0;
    for (int i = 0; i < pilesSize; i++) {
        int temp = piles[i] % mid;
        if (temp > 0) {
            sum += piles[i] / mid + 1;
        } else {
            sum += piles[i] / mid;
        }

    }
    return sum <= h ? true : false;
}

int minEatingSpeed(int* piles, int pilesSize, int h)
{
    qsort(piles, pilesSize, sizeof(int), cmp);
    int k = 1;
    int low = 1;
    int high = piles[pilesSize - 1];
    int mid = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (CheckOK(piles, pilesSize, mid, h)) {
            k = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return k;
}

int main(int argc, char *argv[])
{
    int a[5] = {3, 6, 7, 11};
    int lengthTime = 8;
    int result = minEatingSpeed(a, 4, lengthTime);
    printf("%d\n", result);
    return 0;
}
