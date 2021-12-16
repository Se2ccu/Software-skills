/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 实现随机输出数值的类，插入删除需要O(1)复杂度
 * Hash表实现，插入删除常数时间，通过随机数，随机输出
 * Author: 周涛
 * Data: 2021-12-07 00:02:25
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int val;
    UT_hash_handle hh;
} RandomizedSet;

RandomizedSet* set = NULL;
/** Initialize your data structure here. */

RandomizedSet* randomizedSetCreate() {
    return (RandomizedSet*)calloc(1, sizeof(RandomizedSet));
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    RandomizedSet* tmp;
    HASH_FIND_INT(set, &val, tmp);
    if (tmp == NULL) {
        tmp = (RandomizedSet*)calloc(1, sizeof(RandomizedSet));
        tmp->val = val;
        HASH_ADD_INT(set, val, tmp);
        return true;
    }
    return false;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    RandomizedSet* tmp;
    HASH_FIND_INT(set, &val, tmp);
    if (tmp != NULL) {
        HASH_DEL(set, tmp);
        free(tmp);
        return true;
    }
    return false;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    int cnt = 0;
    cnt = HASH_COUNT(set);
    int loop = rand() % cnt;
    RandomizedSet* current_user, *tmp;
    cnt = 0;
    HASH_ITER(hh, set, current_user, tmp) {
        if (cnt++ >= loop) {
            break;
        }
    }
    return current_user->val;
}

void randomizedSetFree(RandomizedSet* obj) {

    RandomizedSet* current_user, *tmp;
    HASH_ITER(hh, set, current_user, tmp) {
        HASH_DEL(set,current_user);
        free(current_user);
    }
    return;
}


int main(int argc, char *argv[])
{

    return 0;
}
