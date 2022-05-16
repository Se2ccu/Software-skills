/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 滑动窗口模板
 * Author:  zhoutao
 * Data: 2022-04-07 01:05:50
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int longestOnes(int* nums, int numsSize, int k)
{
    int maxSum = 0;
    int left = 0;
    int cnt = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            cnt++;
        }

        while ((cnt > k) && (left <= right)) {
            if (nums[left] == 0) {
                cnt--;
            }
            left++;
        }

        maxSum = MAX(maxSum, right - left + 1);
    }

    return maxSum;
}


int main(int argc, char *argv[])
{
    int input[4] = {0, 0, 0, 0};
    int result = longestOnes(input, 4, 0);
    printf("%d\n", result);
    return 0;
}
