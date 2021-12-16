/*
 * Copyright (c) HaHa Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: 文件功能描述
 * Author:  XXX
 * Data: 2021-12-14 01:49:24
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct ItemTag {
    struct ItemTag *next;
    struct ItemTag *prev;
    int sid;
    int val;
} Item;

typedef struct {
    int length;
    int maxSid; // 快照次数
    Item data[]; // 用来存储头指针
} SnapshotArray;

SnapshotArray* snapshotArrayCreate(int length)
{
    SnapshotArray* ret=(SnapshotArray*)malloc(sizeof(SnapshotArray) + sizeof(Item)*length);
    memset(ret,0x0,sizeof(SnapshotArray)+sizeof(Item)*length);

    ret->maxSid = 0;
    ret->length = length;

    return ret;
}
// 比较尾节点的快照ID 是否与快照次一致，一致直接修改相应值，不一致侧在尾部添加新节点，以保持链表有序。
void snapshotArraySet(SnapshotArray* obj, int index, int val)
{
    Item *head = &obj->data[index];

    if(head->prev == NULL){   // 初始化头节点
        Item *item=(Item*)malloc(sizeof(Item));
        item->val=0;
        item->sid=0;
        item->prev=head;
        item->next=head;
        head->prev=item;
        head->next=item;
    }

    if (head->prev->sid != obj->maxSid) { // 只用判断尾节点的 快照ID是否与快照次数相等即可
        Item *tail = head->prev;
        Item *item=(Item*)malloc(sizeof(Item));

        item->sid=obj->maxSid;
        item->val=val;
        item->next=head;
        item->prev = tail;

        tail->next=item;
        head->prev=item;
    } else {
        head->prev->val=val;
    }
}

int snapshotArraySnap(SnapshotArray* obj) {
    return obj->maxSid++;
}

// 每次都从头开始遍历，因为快照ID是有顺序的，找到相等的或者比指定ID大的即可结束。时间复杂度为O(n).
int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id)
{
    Item *head=&obj->data[index];

    while(head->next != &obj->data[index] && head->next!=NULL){
        Item *t=head->next;
        if(t->sid == snap_id){
            return t->val;
        }else if(t->sid > snap_id){  // 如果下个节点的快照ID比指定的ID大，则返回前节点的值。
            return head->val;
        }
        head=head->next;
    }
    return head->val;
}

void snapshotArrayFree(SnapshotArray* obj)
{
    for (int i=0; i<obj->length; i++) {
        Item *item=obj->data[i].next;
        while(item!= &obj->data[i] && item!=NULL){
            Item *next=item->next;
            free(item);
            item=next;
        }
    }

    free(obj);
}


int main(int argc, char *argv[])
{

    return 0;
}
