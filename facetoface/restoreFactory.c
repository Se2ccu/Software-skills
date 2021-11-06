/***********************************************************************
 * @file restoreFactory.c
     RESTOREFACTORY
 * @brief 二分法学习。2021.03.05 华为专业级认证考试真题
 * @ 将相邻的货箱分为3堆，并满足3堆升序排列的数量
 * @input boxes = [1,1,2,1,4] length属于[1, 10^6]
 * @output 满足要求的组合数
 * @history
 * Date       Version Author    description
 * ========== ======= ========= =======================================
 * 2021-09-02 V1.0    zhoutao   Create
 *
 * @Copyright (C)  2021  .cdWFVCEL. all right reserved
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 暴力解法 left和right做下标区分 两重循环
int ArrangeBoxes(int* nums, int length)
{
    int *preSum = (int*)malloc(sizeof(int) * length);
    memset(preSum, 0, length);

    preSum[0] = nums[0];

    for (int i = 1; i < length; i++) {
        preSum[i] = preSum[i - 1] + nums[i];
    }
    int cnt = 0;

    for (int j = 1; j < length; j++) {
        for (int i = 0; i < j; i++) {
            int first = preSum[i];
            int second = preSum[j] - preSum[i];
            int third = preSum[length - 1] - preSum[j];
            if (first <= second && second <= third) {
                cnt++;
            }
        }
    }
    return cnt;
}

// 二分法 对preSum有序数组，进行处理
int ArrangeBoxes(int* nums, int length)
{
    int *preSum = (int*)malloc(sizeof(int) * length);
    memset(preSum, 0, length);

    preSum[0] = nums[0];

    for (int i = 1; i < length; i++) {
        preSum[i] = preSum[i - 1] + nums[i];
    }
    int cnt = 0;

    for (int j = 1; j < length; j++) {
        for (int i = 0; i < j; i++) {
            int first = preSum[i];
            int second = preSum[j] - preSum[i];
            int third = preSum[length - 1] - preSum[j];
            if (first <= second && second <= third) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    printf("Hello Test\n");
    int a[5] = {1, 1, 2, 1, 4};
    printf("%d\n", ArrangeBoxes(a, 5));
    return 0;
}

