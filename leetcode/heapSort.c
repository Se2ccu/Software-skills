/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 堆排序
 * Author:  zhoutao
 * Data: 2022-05-19 01:12:28
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void swap(int *nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

/* 大顶堆 升序 */
void sink(int *nums, int k, int end)
{
    /* 满足存在叶子节点的条件 */
    while (k * 2 <= end) {
        /* 找到需交换的叶节点 */
        int j = 2 * k;
        if ((j + 1 <= end) && (nums[j + 1] > nums[j])) {
            j++;
        }

        if (nums[j] > nums[k]) {
            swap(nums, j, k);
            k = j; // 交换后续继续，直到无叶子节点
        } else {
            break;
        }
    }
}

int *HeapSort(int *nums, int numsSize, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * (numsSize + 1));
    if (!arr) {
        return NULL;
    }
    memset(arr, 0, sizeof(int) * (numsSize + 1));

    for (int i = 0; i < numsSize; i++) {
        arr[i + 1] = nums[i];   
    }

    /* 下沉建堆:最后一个非叶子节点 */
    for (int j = numsSize / 2; j > 0 ; j--) {
        sink(arr, j, numsSize);
    }

    /* 最后一个节点开始往前，每次将大顶对的数据和最后节点进行交换，然后重新sink */
    int k = numsSize;
    while (k >= 1) {
        swap(arr, 1, k);
        k--; // 不能放最后
        sink(arr, 1, k);
    }

    for (int i = 0; i < numsSize; i++) {
        nums[i] = arr[i + 1];
    }

    free(arr);
    *returnSize = numsSize;

    return nums;
}

int main(int argc, char *argv[])
{
    int input[5] = {4, 5, 1, 3, 2};

    int returnSize = 0;
    int *res = HeapSort(input, 5, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
