/**
 *  Filename   : 707_2design_linklist.c
 *  Version    : V1.0
 *  Author     : Zhoutaoccu
 *  Date       : 2020.4.9
 *  Review
 *  Usage      : qsort for Huawei Work Contest
 *  Func Name  : qsort
 *  Web Link   : qsort website link (http://www.cplusplus.com/reference/cstdlib/qsort/)
 *  How to use : void qsort (void* base, size_t num, size_t size,
 *               int (*compar)(const void*,const void*));
 *  Paramenters 1 :   base    --Pointer to the first (*obj)ect of the array to be sorted
 *  Paramenters 2 :   num     --Number of elements in the array pointed to by base
 *  Paramenters 3 :   size    --Size in bytes of each element in the array, like sizeof()
 *  Paramenters 4 :   compar  --比较函数指针，入参要强转为对应数据类型，同时返回值为int,用于比较大小
 *  History:
 *  1.Date     : 2020.4.9
 *    Author   : Zhoutaoccu
 *    Content  : Creat New File
*/ 

#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc,qsort */
#include <string.h>  /* strcpy,strcmp */
//#include "uthash.h"

typedef unsigned char UINT8;
typedef signed char INT8;
typedef unsigned short UINT16;
typedef signed short INT16;
typedef unsigned int UINT32;
typedef signed int INT32;
typedef float FP32;
typedef double FP64;

#define MAX(x, y) ((x) > (y) ? (x) : (y))


#define MAX_QUEUE_NUM 2500



typedef struct node {
    unsigned int id;
    unsigned int timetrip;
    struct node * next;
} Node, *LogSystem;

LogSystem* LogSystemCreate()
{
    LogSystem obj = (LogSystem)malloc(sizeof(Node));
    if (obj == NULL) {
        return NULL;
    }
    obj->id = 0;
    obj->timetrip = 0;
    obj->next = NULL;
    return &obj;
}

void LogSystemAdd(LogSystem* obj, int id, int timeStamp)
{
    
    LogSystem head = (LogSystem)malloc(sizeof(Node));
    if ((*obj) == NULL) {
        return;
    }
    //printf("head->id = %x\n", head->id);
    head->id = id;
    head->timetrip = timeStamp;
    printf("head->id = %x\n", head->id);
    head->next = (*obj)->next;
    (*obj)->next = head;
    return;

    /*
    LogSystem* tail=malloc(sizeof(LogSystem));
    tail->id = id;
    tail->next = NULL;
    LogSystem* tmp=(*obj);
    while(tmp->next != 0) tmp=tmp->next;
    tmp->next=tail;*/

}

int LogSystemDelete(LogSystem* obj, int id)
{
    if (!(*obj) || id < 0) {
        return -1;
    }

    LogSystem temp = (*obj);
    LogSystem temp_free = (*obj);

    /* Delete head node */
    if (temp->id == id) {
        (*obj) = temp->next;
        temp->next = NULL;
        free(temp);
        return 0;
    }

    while((temp != NULL) && (temp->next != NULL)) {
        if (id = temp->next->id) {
            temp_free = temp->next;
            temp->next = temp->next->next;
            free(temp_free);
            return 0;
        }  
        temp = temp->next;
    }

    if (temp->next == NULL) {
        
    }
    return -1;

}

int LogSystemQuery(LogSystem* obj, int startTime, int endTime)
{
    if ((*obj) == NULL) {
        return 0;
    }
    if ((startTime < 0) || (endTime < 0)) {
        return 0;
    }
    int count = 0;
    LogSystem temp = (*obj);
    

    while (temp != NULL) {
        if ((temp->timetrip <= endTime) && (temp->timetrip >= startTime)) {
            printf("temp = %x\n", temp);
            printf("temp->id= %x\n", temp->id);
            printf("temp->timetrip = %x\n", temp->timetrip);
            count++;
        }
        temp = temp->next;
    }
    return count;

}

void LogSystemFree(LogSystem* obj)
{
    if ((*obj) == NULL) 
        return;
    LogSystem temp = (*obj);
    while(temp) {
        free(temp);
        temp = temp->next;
    }
    (*obj) = NULL;
}


int main()
{

	printf("TEST BEGIN.\n");
    
    LogSystem* obj = LogSystemCreate();
    LogSystemAdd(obj, 1, 5);
    LogSystemAdd(obj, 2, 5);
    LogSystemAdd(obj, 3, 6);
    int param_1 = LogSystemQuery(obj, 5, 6);
    printf("param_1 = %d\n", param_1);
    
    int param_2 = LogSystemDelete(obj, 2);
    printf("param_2 = %d\n", param_2);
    int param_3 = LogSystemDelete(obj, 4);
    printf("param_3 = %d\n", param_3);
    int param_4 = LogSystemQuery(obj, 5, 6);
    printf("param_4 = %d\n", param_4);
    LogSystemFree(obj);
 
    return 0;
}
