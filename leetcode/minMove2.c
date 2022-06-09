/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 数组 对每个数据可以加减1，求最少次数让每个数保持相同
 * Author:  zhoutao
 * Data: 2022-05-19 00:16:21
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int CmpInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int minMoves2(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), CmpInt);

    int res = 0;
    int optNum = nums[numsSize / 2];
    for (int i = 0; i < numsSize; i++) {
        res += abs(nums[i] - optNum);
    }

    return res;
}

int main(int argc, char *argv[])
{
    int input[3] = {1, 2, 3};
    int res = minMoves2(input, 3);
    printf("%d\n", res);
    return 0;
}
