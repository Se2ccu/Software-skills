/**
 *  Filename   : qsort_leetcode.c
 *  Version    : V1.0
 *  Author     : Zhoutaoccu
 *  Date       : 2020.3.27
 *  Review
 *  Usage      : qsort for Huawei Work Contest
 *  Func Name  : qsort
 *  Web Link   : qsort website link (http://www.cplusplus.com/reference/cstdlib/qsort/)
 *  How to use : void qsort (void* base, size_t num, size_t size,
 *               int (*compar)(const void*,const void*));
 *  Paramenters 1 :   base    --Pointer to the first object of the array to be sorted
 *  Paramenters 2 :   num     --Number of elements in the array pointed to by base
 *  Paramenters 3 :   size    --Size in bytes of each element in the array, like sizeof()
 *  Paramenters 4 :   compar  --比较函数指针，入参要强转为对应数据类型，同时返回值为int,用于比较大小
 *  History:
 *  1.Date     : 2020.3.27
 *    Author   : Zhoutaoccu
 *    Content  : Creat New File
*/ 

#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc,qsort */
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

typedef struct
{ 
    int data1; 
    int data2; 
}Stu,*pStu;

#if 0
// 如果a > b表示需要调换顺序，return 1，这样理解，就会使得数组为升序
int compareMyType (const void * a, const void * b)
{
  if ( *(MyType*)a <  *(MyType*)b ) return -1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
}
#endif


int cmp_int(const void* a , const void* b)
{
    return (*(int*)a - *(int*)b); // a - b > 0表示升序， a - b < 0表示降序
}

int cmp_int_reverse(const void* a , const void* b)
{
    return (- *(int*)a + *(int*)b); // a - b > 0表示升序， a - b < 0表示降序
}


int cmp_char(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

int cmp_char_reverse(const void* a, const void* b)
{
    return - *(char*)a + *(char*)b;
}


/* For return datatype is int */
int cmp_double(const void* a, const void* b)
{
    return *(double*)a > *(double*)b ? 1 : -1;
}

int cmp_double_reverse(const void* a, const void* b)
{
    return *(double*)a < *(double*)b ? 1 : -1;
}


/* need to transform to char** */
int cmp_string(const void* a, const void* b)
{
    return strcmp(*(char**)a, *(char**)b);
}

int cmp_string_reverse(const void* a, const void* b)
{
    return -strcmp(*(char**)a, *(char**)b);
}


int cmp_struct1(const void* a, const void* b)
{
    if (((Stu*)a)->data1 != ((Stu*)b)->data1) {
        return ((Stu*)a)->data1 > ((Stu*)b)->data1 ? 1 : -1;
    }
}

int cmp_struct1_reverse(const void* a, const void* b)
{
    if (((Stu*)a)->data1 != ((Stu*)b)->data1) {
        return ((Stu*)a)->data1 < ((Stu*)b)->data1 ? 1 : -1;
    }
}


/* Started by Zhoutaoccu 2020.03.27 降序将大于号改为小于号即可 */
int cmp_struct2(const void* a, const void* b)
{
    if (((Stu*)a)->data1 != ((Stu*)b)->data1) {
        return ((Stu*)a)->data1 > ((Stu*)b)->data1 ? 1 : -1;
    } else if (((Stu*)a)->data2 != ((Stu*)b)->data2) {
        return ((Stu*)a)->data2 > ((Stu*)b)->data2 ? 1 : -1;
    }
}

int cmp_struct2_reverse(const void* a, const void* b)
{
    if (((Stu*)a)->data1 != ((Stu*)b)->data1) {
        return ((Stu*)a)->data1 < ((Stu*)b)->data1 ? 1 : -1;
    } else if (((Stu*)a)->data2 != ((Stu*)b)->data2) {
        return ((Stu*)a)->data2 < ((Stu*)b)->data2 ? 1 : -1;
    }
}

int cmp_matrix(const void* a, const void* b)
{
    //int *ap = *(int**)a;
    //int *bp = *(int**)b;
    //return ap[0] - bp[0];

    return (*(int**)a)[0] - (*(int**)b)[0];
}

#define MAX_QUENE_NUM 10001
int* Slove(int k, int** update, int updateSize, int* updateColSize, int** out, int outSize, int* outColSize, int* returnSize)
{
    int update_queue[MAX_QUENE_NUM] = { 0 };
    int out_for_paper[MAX_QUENE_NUM] = { 0 };

    printf("qsort BEGIN.\n");
    qsort(update, updateSize, sizeof(update[0]), cmp_matrix);
    printf("qsort END.\n");

    for (int i = 0; i < updateSize; i++) {
        update_queue[update[i][0]] = update[i][1];
        printf("update_queue: index = [%d], value = [%d].\n", update[i][0], update[i][1]);
    }

    for (int i = 0; i < outSize; i++) {
        for (int j = out[i][0]; j <= out[i][1]; j++) {
            out_for_paper[j] = 1;
            printf("out_for_paper: index = [%d], value = [%d].\n", j, out_for_paper[j]);

        }
    }

    int days = update[updateSize - 1][0];
    int chapter_to_learn = 0;
    int index = 0;
    int* ret = (int*)malloc(sizeof(int) * (days + 1));
    if (ret == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i <= days; i++)
    {
        chapter_to_learn += update_queue[i];
        printf("chapter_to_learn is %d.\n", chapter_to_learn);

        if (out_for_paper[i] == 1) {
            continue;
        }

        if (chapter_to_learn == 0) {
            ret[index++] = i;
        }

        chapter_to_learn = (chapter_to_learn > k) ? (chapter_to_learn - k) : 0;
    }

    *returnSize = index;
    return ret;
}





int main()
{

	printf("TEST BEGIN.\n");
	
    int k = 3; // 每天学习课程最大章节数
    int update[3][2] = {{3, 6}, {0, 5}, {9, 1}}; // 按照日期的课程更新情况
    int out[1][2] = {{3, 5}}; // 写论文区间，多个

    int returnSize;
    int* ret = NULL;

    printf("Slove BEGIN.\n");
    ret = Slove(k, update, 3, NULL, out, 1, NULL, &returnSize);
    printf("returnSize = %d\n", returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ret[i]);
    }
    
    return 0;
}





