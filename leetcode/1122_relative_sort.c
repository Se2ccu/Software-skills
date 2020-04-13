/**
 *  Filename   : 1122_relative_sort.c
 *  Version    : V1.0
 *  Author     : Zhoutaoccu
 *  Date       : 2020.4.1
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
 *  1.Date     : 2020.4.1
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

typedef struct
{ 
    int data1; 
    int data2; 
}Stu,*pStu;

#if 0
int compareMyType (const void * a, const void * b)
{
  if ( *(MyType*)a <  *(MyType*)b ) return -1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
}
#endif


int cmp_int(const void* a , const void* b)
{
    return (*(int*)a - *(int*)b); 
}

int cmp_int_reverse(const void* a , const void* b)
{
    return (- *(int*)a + *(int*)b); 
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
    int *ap = *(int**)a;
    int *bp = *(int**)b;
    return ap[0] - bp[0];
}


#if 0
int cmp_gold_medals(const void* lhs, const void* rhs) {
    const struct Nation* left = (const struct Nation*)lhs;
    const struct Nation* right = (const struct Nation*)rhs;
    if (left->gold_medals < right->gold_medals) {
        return -1;
    } else if (right->gold_medals < left->gold_medals) {
        return 1;
    }
    return 0;
}
#endif

void sortInt()
{
	int num[] = {10, 9, 8, 7, 10, 6, 5, 4, 3, 2, 1};
	printf("Test for int sorted.\n");
    qsort(num, sizeof(num)/sizeof(num[0]), sizeof(num[0]), cmp_int);
    for (int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
	
	qsort(num, sizeof(num)/sizeof(num[0]), sizeof(num[0]), cmp_int_reverse);
    for (int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void sortStr()
{
	/* error string init */
    //char c_str[4][10] = {"abc", "bcd", "abd", "abcd"};
	char* c_str[] = {"abc", "bcd", "abd", "abcd", "ABC", "BC"};
	
    printf("Test for char sorted.\n");
	qsort(c_str, 6, sizeof(c_str[0]), cmp_string);
    for (int i = 0; i < 6; i++) {
        printf("%s ", c_str[i]);
    }
    printf("\n");
	
	qsort(c_str, 6, sizeof(c_str[0]), cmp_string_reverse);
    for (int i = 0; i < 6; i++) {
        printf("%s ", c_str[i]);
    }
    printf("\n");
}

void sortDouble()
{
	double d_num[] = {10.1, 9.9, 8, 7, 6, 5, 4, 3, 2, 1, 1.01};
	
	printf("Test for double sorted.\n");
    qsort(d_num, 11, sizeof(d_num[0]), cmp_double);
    for (int i = 0; i < 11; i++) {
        printf("%f ", d_num[i]);
    }
    printf("\n");
	
	qsort(d_num, 11, sizeof(d_num[0]), cmp_double_reverse);
    for (int i = 0; i < 11; i++) {
        printf("%f ", d_num[i]);
    }
    printf("\n");
}

void sortStruct2()
{
	Stu s[3] = {
        {3, 3},
        {2, 2},
        {1, 1}
    };
	
	printf("Test for struct2 sorted.\n");
    qsort(s, 3, sizeof(s[0]), cmp_struct2);
    for (int i = 0; i < 3; i++) {
        printf("%d %d\n", s[i].data1, s[i].data2);
    }
    printf("\n");
	
	qsort(s, 3, sizeof(s[0]), cmp_struct2_reverse);
    for (int i = 0; i < 3; i++) {
        printf("%d %d\n", s[i].data1, s[i].data2);
    }
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int count = 0;
    int temp;
    for (int i = 0; i < arr2Size; i++) {
        for (int j = 0; j < arr1Size; j++) {
            if (arr2[i] == arr1[j]) {
                temp = arr1[count];
                arr1[count] = arr1[j];
                arr1[j] = temp;
                count++;
            }
        }
          
    }

    if (count < arr1Size) {
        qsort(&arr1[count], arr1Size - count, sizeof(arr1[0]), cmp_int);
    }
    
    *returnSize = arr1Size;
    
    return arr1;
}



int main()
{
    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[] = {2,1,4,3,9,6};
    int* result = (int*)malloc(sizeof(int) * sizeof(arr1)/sizeof(int));
    
	printf("TEST BEGIN.\n");
    int returnSize = 0;
	result = relativeSortArray(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int), &returnSize);

    for (int i = 0; i < sizeof(arr1)/sizeof(int); ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}






