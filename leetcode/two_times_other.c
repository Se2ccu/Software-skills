/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍
 * Author:  zhoutao
 * Data: 2022-01-13 00:49:05
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int cmp_int(const void* a , const void* b)
{
    return (*(int*)a - *(int*)b); // a - b > 0表示升序， a - b < 0表示降序
}

int dominantIndex(int* nums, int numsSize){
    // qsort(nums, numsSize, sizeof(int), cmp_int);
    int maxValue = nums[0];
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
            index = i;
        }
    }

    for (int j = 0; j < numsSize; j++) {
        if (j == index) {
            continue;
        }
        if (maxValue < 2 * nums[j]) {
            return -1;
        }
    }

    return index;
}

int main(int argc, char *argv[])
{

    return 0;
}

