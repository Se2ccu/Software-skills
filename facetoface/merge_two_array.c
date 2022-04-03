/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 合并两数组为升序数组
 * Author:  zhoutao
 * Data: 2022-04-01 23:59:42
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int cmpInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for (int i = 0; i < n; i++) {
        nums1[i + m] = nums2[i];
    }

    qsort(nums1, nums1Size, sizeof(int), cmpInt);
}
