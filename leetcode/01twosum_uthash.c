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
        HASH_ADD_INT(hash_table, id, item2); // 添加节点，第二个参数是key，只是个象征
    }
    return result;
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
