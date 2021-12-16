/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 多组预定航班数组，得出预定记录的求和
 * Author:  周涛
 * Data: 2021-12-08 23:56:24
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
 * 预定座位总数
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    int *result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, n * sizeof(int));
    for (int i = 0; i < bookingsSize; i++) {
        int begin = bookings[i][0];
        int end = bookings[i][1];
        int seatNum = bookings[i][2];
        for (int j = begin; j <= end; j++) {
            result[j - 1] += seatNum;
        }
    }

    *returnSize = n;

    return result;
}


int main(int argc, char *argv[])
{

    return 0;
}
