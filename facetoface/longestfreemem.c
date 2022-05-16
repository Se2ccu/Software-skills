/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 最长空闲内存(滑动窗口）
 * ..表示空闲 xx表示占用，如果允许释放cnt个内存，求连续最大的空闲内存大小
 * Author:  zhoutao
 * Data: 2022-04-08 00:13:04
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int GetMaxFreeMemoryLen(char *memory, int cnt)
{
    int len = strlen(memmory);
    int num = 0;
    int left = 0;
    int maxSum = 0;

    for (int right = 0; right < len; right++) {
        if (memory[right] == 'x') {
            num++;
        }

        while ((num > cnt) && (left <= right)) {
            if (memory[left] == 'x') {
                num--;
            }
            left++;
        }

        maxSum = MAX(maxSum, right - left + 1);
    }

    return maxSum;
}


int main(int argc, char *argv[])
{
    
    return 0;
}
