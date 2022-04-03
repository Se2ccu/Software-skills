#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc */
#include <string.h>  /* strcpy */
#include "uthash.h"



typedef struct hash_node {
    int id;         // key
    int index;      // value
    UT_hash_handle hh;
} hash_node;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 2);
    hash_node* item1 = NULL;
    hash_node* item2 = NULL;
    hash_node* hash_table = NULL;


    for (int i = 0; i < numsSize; i++) {
        int other_id = target - nums[i];
        HASH_FIND_INT(hash_table, &other_id, item1); // 查找节点，第二个参数是传入key的引用
        if (item1) {
            result[0] = item1->index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }

        item2 = (hash_node*)malloc(sizeof(hash_node));
        if (!item2) return NULL;
        item2->id = nums[i];
        item2->index = i;
        HASH_ADD_INT(hash_table, other_id, item2); // 添加节点，第二个参数是key，只是个象征
    }
    return result;
}


struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int input[8] = {1, 2, 4, 6, 8, 9, 0, 3};
	int target = 9;
    int* result;
    int* returnSize = (int*)malloc(sizeof(int));
    result = twoSum(input, sizeof(input)/sizeof(int), target, returnSize);
    printf("result[%d] = %d and %d\n", target, result[0], result[1]);
}
