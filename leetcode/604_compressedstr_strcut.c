/**
 *  Filename   : 604_compressedstr_struct.c
 *  Version    : V1.0
 *  Author     : Zhoutaoccu
 *  Date       : 2020.4.7
 *  Review
 *  Usage      : data struct for compressed str by struct
 *  Func Name  : CompressedStrIteratorCreat()
 *  Web Link   : https://leetcode-cn.com/problemset/all/?search=604
 *  How to use : void qsort (void* base, size_t num, size_t size,
 *               int (*compar)(const void*,const void*));
 *  Paramenters 1 :   base    --Pointer to the first object of the array to be sorted
 *  Paramenters 2 :   num     --Number of elements in the array pointed to by base
 *  Paramenters 3 :   size    --Size in bytes of each element in the array, like sizeof()
 *  Paramenters 4 :   compar  --比较函数指针，入参要强转为对应数据类型，同时返回值为int,用于比较大小
 *  History:
 *  1.Date     : 2020.4.7
 *    Author   : Zhoutaoccu
 *    Content  : Creat New File
*/ 

#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc,qsort */
#include <string.h>  /* strcpy,strcmp */
#include <stdbool.h>  /* bool */
#include <ctype.h> /* isdigit() isalpha() */
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
#define MAX_QUEUE_SIZE 1000


typedef struct
{ 
    char c; 
    int cnt; 
} Node;

typedef struct {
    Node my_queue[MAX_QUEUE_SIZE];
    int size; // 队列实际大小
    int index; // 队列序号
} stCompressedStrIterator_t, pstCompressedStrIterator_t;


Node PackNode(char str_alpha, int count)
{
    Node node;
    node.c = str_alpha;
    node.cnt = count;
    return node;
}

stCompressedStrIterator_t* CompressedStrIteratorCreate(char* compressedStr)
{
    stCompressedStrIterator_t* obj = (stCompressedStrIterator_t*)malloc(sizeof(stCompressedStrIterator_t));
    if (obj == NULL) {
        return NULL;
    }

    memset(obj, 0, sizeof(stCompressedStrIterator_t));

    int i;
    int len = strlen(compressedStr);
    obj->index = 0;
    int count = 0;
    char str_alpha;

    for (i = 0; i < len; i++) {
        if (isalpha(compressedStr[i])) {
            if (count) {
                obj->my_queue[obj->index] = PackNode(str_alpha, count);
                printf("%c %d\n", str_alpha, count);
                obj->index++;
                count = 0;
            }
            else if (i == len - 1) { // 没有计数，并且还是最后一个字母结尾
                printf("illega count!\n");
                return NULL;
            }

            str_alpha = compressedStr[i];
            
        } else if (isdigit(compressedStr[i])) {
            count = count * 10 + compressedStr[i] - '0';
        }
    }   

    obj->size = obj->index;
    obj->index = 0;
    return obj;
}

char CompressedStrIteratorNext(stCompressedStrIterator_t* obj)
{
    if ((obj == NULL) || (obj->index >= obj->size)) {
        return ' ';
    }

    char ret = obj->my_queue[obj->index].c;
    obj->my_queue[obj->index].cnt--;

    if (!obj->my_queue[obj->index].cnt) {
        obj->index++;
    }

    return ret;
}

bool CompressedStrIteratorHasNext(stCompressedStrIterator_t* obj)
{
    if (obj == NULL) {
        return false;
    }

    return (obj->index < obj->size);
}

void CompressedStrIteratorFree(stCompressedStrIterator_t* obj)
{
    if (obj != NULL) {
        free(obj);
        obj == NULL;
    }
}

int main()
{
    char input[] = "L1e2t1C1o1d1e1";
    stCompressedStrIterator_t* iterator = CompressedStrIteratorCreate(input);

    printf("%c ", CompressedStrIteratorNext(iterator));
    printf("%c ", CompressedStrIteratorNext(iterator));
    printf("%c ", CompressedStrIteratorNext(iterator));
    printf("%c ", CompressedStrIteratorNext(iterator));
    printf("%c ", CompressedStrIteratorNext(iterator));
    printf("%c ", CompressedStrIteratorNext(iterator));

    printf("%d ", CompressedStrIteratorHasNext(iterator));
    printf("%c ", CompressedStrIteratorNext(iterator));
    printf("%d ", CompressedStrIteratorHasNext(iterator));
}