/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 用最少的天数，在预算范围能购买指定数量的办公物品。每天存在价格限量优惠
 * Author:  zhoutao
 * Data: 2022-05-24 00:17:41
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int Cmp(const void *a, const void *b)
{
    return - ((int *)a)[2] + ((int *)b)[2]; 
}

int b_arr[4][3] = { {2, 5, 3},
                    {3, 6, 2},
                    {4, 2, 1},
                    {6, 1, 4} };
int c_arr[1][3] = { {2, 3, 3} };

int CheckRight(int num, int price, int **discount, int budget, int day)
{
    int cnt = 0;
    int sum = 0;
    int itemSize = 3 * sizeof(int);
    int itemNum = sizeof(discount) / itemSize;
    itemNum = 1;
    for (int i = 0; i < itemNum; i++) {
        if (sum > budget) {
            break;
        }

        /* 找到对应促销表中在限定时间内的优惠 */
        if (discount[i][0] > day) {
            continue;
        }

        int avalibelCnt = MIN(num - cnt, discount[i][2]);
        int canBuy = (budget - sum) / discount[i][1];
        int realCnt = MIN(avalibelCnt, canBuy);

        cnt += realCnt;
        sum += realCnt * discount[i][1];
    }

    /* 优惠使用完，但还未满足num要求 何时使用原价用品 */
    if (cnt < num) {
        cnt += (budget - sum) / price;
        sum += cnt * price;
    }

    return (cnt >= num) && (sum <= budget);
}

int PurchaseItems(int num, int price, int **discount, int budget)
{
    if (price * num <= budget) {
        return 1;
    }

    int itemSize = 3 * sizeof(int);
    int itemNum = sizeof(discount) / itemSize;
    itemNum = 1;

    int left = 1;
    int right = discount[itemNum - 1][0];

    /* 需传入指针数组，而不是二级指针 */
    qsort(*discount, itemNum, itemSize, Cmp);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (CheckRight(num, price, discount, budget, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int** CreateIdentityMatrix(int r,int c){
    int** pm = (int**)malloc(sizeof(int*)*r);
    for(int i=0;i<r;++i){
        pm[i] = (int*)malloc(sizeof(int)*c);
    }
    return pm;
}


int main(int argc, char *argv[])
{
    int num = 2;
    int price = 4;
    int budget = 10;

    /* 
    int **p = CreateIdentityMatrix(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            p[i][j] = b_arr[i][j];
        }
    } */

    
    /* 将二维数据转化为二级指针，二维数组本质是个指针数组 */
    int *p[1];            
    for (int i = 0; i < 1; i++) {
        p[i] = c_arr[i];
    }
    int ret = PurchaseItems(num, price, p, budget);
    printf("%d\n", ret);
    return 0;
}
