/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: 专业级题目：判断连通器是否连通，分主备区，主备联通，不同站点连接。
 * 默认节点都是打开，现在进行节点的开关操作,每次操作均为取反操作，输出每次操作后连通器是否通
 * 不建议每次操作遍历所有设备金秀贤检测判断，可考虑状态的保存（如阻断点的计数）
 * o --- x --- o
 * -------------
 * o --- x --- o
 * input: 操作数：num = 5  // 站点总数
 *        操作指令：[[0, 2],[0, 1], [1, 2], [0, 2], [0, 1]]  // 前一个表示主备[0, 1] 后一个表示站点编号
 * Author:  zhoutaoccu
 * Data: 2022-03-26 00:54:42
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DEVICE_NUM 100000

#define CHANGE_SWITCH_ST(value) ((value) == 0) ? (value) = 1 : (value) = 0


int *CheckConnectivity(int num, int **operations, int operationSize, int *returnSize)
{
    int *result = (int*)malloc(sizeof(int) * operationSize);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = operationSize;

    char state[MAX_DEVICE_NUM][2] = {0}; // 节点开关状态，默认0表示上电状态
    int unConectNum = 0;
    for (int i = 0; i < operationSize; i++)
    {
        int devType = operations[i][0]; // 主备区标记
        int devNum = operations[i][1]; // 站点编号标记

        /* 当前开闭，决定阻塞点是否新增：当前是上电，即后续操作后状态变为下电，下电阻塞点增加 */
        int add = (state[devNum][devType] == 0) ? 1 : -1;
        int ops = (devType == 0) ? 1 : 0; // 对偶 主次站点

        /* 根据节点对偶处的状态判断是否新增阻塞点还是减少 */
        /* 1.正对 对偶节点下电 */
        if (state[devNum][ops] == 1) {
            unConectNum += add;
        }

        /* 2.135度位置 对偶节点下电 */
        if ((devNum < num - 1) && (state[devNum + 1][ops] == 1)) {
            unConectNum += add;
        }

        /* 3.45度位置 对偶节点下电 */
        if ((devNum > 1) && (state[devNum - 1][ops] == 1)) {
            unConectNum += add;
        }

        /* 更新状态 */
        CHANGE_SWITCH_ST(state[devNum][devType]);
        /* 对偶阻断判断 */
        result[i] = (break > 0) ? 0 : 1;
    }

}




int main(int argc, char *argv[])
{

    return 0;
}
