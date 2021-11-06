/**
 *  Filename   : 704_BinarySearch.c
 *  Version    : V1.0
 *  Author     : Zhoutaoccu
 *  Date       : 2020.4.9
 *  Review
 *  Usage      : BinarySearch
 *  Func Name  : search
 *  Web Link   : https://leetcode-cn.com/problems/binary-search/
 *  How to use : int search(int* nums, int numsSize, int target)
 *  Paramenters 1 :   nums      --Pointer to the array to be searched
 *  Paramenters 2 :   numsSize  --Number of elements in the array pointed to by base
 *  Paramenters 3 :   target    --target to be searched
 *  History:
 *  1.Date     : 2020.4.9
 *    Author   : Zhoutaoccu
 *    Content  : Creat New File
*/ 

#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi,malloc,qsort */
#include <string.h>  /* strcpy,strcmp */
#include "uthash.h"

typedef unsigned char UINT8;
typedef signed char INT8;
typedef unsigned short UINT16;
typedef signed short INT16;
typedef unsigned int UINT32;
typedef signed int INT32;
typedef float FP32;
typedef double FP64;

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int cmp_int(const void* a , const void* b)
{
    return (*(int*)a - *(int*)b); // a - b > 0表示升序， a - b < 0表示降序
}

/* 确认数组为升序 */
int sorted(int* nums, int numsSize)
{
    int i;
    for (i = 1; i < numsSize - 1; i++) {
        if (nums[i] < nums[i - 1]) {
            return 0;
        } 
    }
    return 1;
}

int search(int* nums, int numsSize, int target){
    if ((nums == NULL) || (numsSize <= 0)) {
        return -1;
    }

    if (!sorted(nums, numsSize)) {
        /* To make sure the array is sorted */
        qsort(nums, numsSize, sizeof(nums[0]), cmp_int);
    }

    int low = 0;
    int high = numsSize - 1;
    int mid = 0;

    /* 只有一个数据，要考虑等号 */
    while (low <= high) {
        mid = low + (high - low) / 2;  // 避免加溢出
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else if (target > nums[mid]) {
            low = mid + 1;
        }
    }
    
    return -1;
}

int main()
{
	printf("TEST BEGIN.\n");
	
    int a[10] = {-1,0,3,5,9,12};
    int target = 2;
    printf("Index in sorted array is [%d]\n", search(a, 6, target));
    
    return 0;
}




int searchInsert(int *nums, int numsSize, int target)
{
    int low, high, mid, val;
    low = 0;
    high = numsSize - 1;
    while(low <= high){
        mid = (low + high) / 2;
        val = nums[mid];
        if (target == val){
            return mid;
        }
        else if (target > val){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        
    }
    return high + 1;
}