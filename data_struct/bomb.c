/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 地震预警通知,当二维网格中出现地震，要根据栅格通知范围依次通知栅格内的用户。并且按照距离由近到远
 * 用户由多到少，栅格编号由小到大
 * Author:  zhoutao
 * Data: 2022-03-16 01:17:12
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef struct {
    int distance;  // 栅格中心和震源的距离
    int num;  // 栅格内的用户数
    int index; // 栅格编号
} GridStru;

int cmpStruct(const void* a, const void* b)
{
    if (((GridStru*)a)->distance != ((GridStru*)b)->distance) {
        return ((GridStru*)a)->distance > ((GridStru*)b)->distance ? 1 : -1;  // 距离升序
    } else if (((GridStru*)a)->num != ((GridStru*)b)->num) {
        return ((GridStru*)a)->num < ((GridStru*)b)->num ? 1 : -1;  // 栅格内用户降序
    } else {
        return ((GridStru*)a)->index > ((GridStru*)b)->index ? 1 : -1;  // 栅格编号升序
    }
}

/*
 * mapSideLen图的边长，gridSideLen栅格边长，栅格边长为奇数，保证有中心点计算栅格通知范围 [1,8192]
 * row clo表示震源发生单元格位置，原点为左上角
 * usrNum表示用户数 [1, 1000]
 * 接下来usrNum行表示每个用户所在的单元格位置，一个单元格可能有多个用户，即会出现重复的用户位置
 * outBuf表示待通知的栅格编号
 */
int GetNotificationOrder(int mapSideLen, int gridSideLen, int radius, int row, int col,
    int userNum, int **userArray, int *outBuf, int maxOutBufLen)
{
    /* 计算栅格数量 */
    int width = mapSideLen / gridSideLen;
    int totalGridnum = width * width;

    /* 申请内存存放栅格信息 */
    GridStru *gridInfo = (GridStru *)malloc(sizeof(GridStru) * totalGridnum);
    if (gridInfo == NULL) {
        return -1;
    }

    /* 将每个用户数量增加到栅格用户数中 */
    int *gridUserNum = (int *)malloc(sizeof(int) * totalGridnum);
    memset(gridUserNum, 0, sizeof(int) * totalGridnum);
    for (int i = 0; i < userNum; i++) {
        int index = userArray[i][0] / gridSideLen * width + userArray[i][1] / gridSideLen;
        gridUserNum[index]++;
    }

    /* 符合要求的栅格数量 */
    int count = 0;
    for (int i = 0; i < totalGridnum; i++) {
        /* 栅格编号转化为坐标 */
        int centerRow = gridSideLen / 2 + (i / width) * gridSideLen;
        int centerCol = gridSideLen / 2 + (i % width) * gridSideLen;
        int distance = abs(centerRow - row) + abs(centerCol - col);

        if ((distance <= radius) && (gridUserNum[i] > 0)) {
            GridStru grid = {distance, gridUserNum[i], i};
            gridInfo[count++] = grid; // 符合要求的结构体直接赋值
        }
    }
    

    qsort(gridInfo, count, sizeof(GridStru), cmpStruct);

    for (int i = 0; i < count; i++) {
        outBuf[i] = gridInfo[i].index + 1;
    }

    return count;
}


int main(int argc, char *argv[])
{
    int mapSideLen;
    int gridSideLen;
    int radius;
    /* 网格和栅格信息 */
    if (scanf("%d%d%d", &mapSideLen, &gridSideLen, &radius) != 3) {
        return -1;
    }

    /* 震源点信息 */
    int row;
    int col;
    int userNum;
    if (scanf("%d%d%d", &row, &col, &userNum) != 3) {
        return -1;
    }

    int buf[1000][2];
    int *userArray[1000];
    for (int i = 0; i < userNum; i++) {
        if (scanf("%d%d", &buf[i][0], &buf[i][1]) != 2) {
            return -1;
        }
        userArray[i] = buf[i];
    }

    int outBuf[1000];
    int size = GetNotificationOrder(mapSideLen, gridSideLen, radius, row, col,
        userNum, userArray, outBuf, 1000);
    printf("result size = %d ", size);
    for (int i = 0; i < size; i++) {
        printf(" %d ", outBuf[i]);
    }

    return 0;
}
