/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 有n种不同颜色的珠子，每种珠子有一定的数量，把这些珠子做成M完美项链(一条M完美项链，就是由M颗不同颜色的珠子组成的)
 * 最多可以组成多少条M完美项链。
 * Author:  周涛
 * Data: 2021-11-29 00:49:34
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

/* 升序排序 */
int compare(int* a, int* b)
{
    return *a - *b;
}

int ok(int* nums, int len, int m, int target)
{
    int idx = 0;
    int used = 0;
    for (int i = 0; i < m; i++) {
        if (idx == len) {
            return 0;
        }
        if (nums[idx] - used >= target) {
            used = 0;
            idx++;
        } else {
            int rest = target;
            while (idx < len && rest >= nums[idx] - used) {
                rest -= nums[idx++] - used;
                used = 0;
            }
            used = rest;
            if (idx == len && used) {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n;
    int m;
    int sum = 0;
    /* 不同颜色种类数量 */
    if (!scanf("%d", &n)) {
        return -1;
    }
    int *nums = (int*)malloc(n * sizeof(int));
    if (!nums) {
        return -1;
    }
    /* 颜色各种分别的数量 */
    for (int i = 0; i < n; i++) {
        if (!scanf("%d", &nums[i])) {
            free(nums);
            return -1;
        }
    }
    /* 完美M项链 M种不同的珠子 */
    if (!scanf("%d", &m)) {
        free(nums);
        return -1;
    }
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    qsort(nums, n, sizeof(int), compare);
    int beg = 0;
    int end = sum / m + 1;
    while (beg < end) {
        int mid = beg + (end - beg) / 2;
        if (ok(nums, n, m, mid)) {
            beg = mid + 1;
        } else {
            end = mid;
        }
    }
    free(nums);
    printf("%d\n", beg - 1);
}