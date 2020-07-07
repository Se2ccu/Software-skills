
#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc,qsort */
#include <string.h>  /* strcpy,strcmp */

typedef struct Node{
    int val;
    struct Node *next;
}MyLinkedList ;


/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {//创建一个头节点
    MyLinkedList *head=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->next=NULL;
    head->val=-1;   
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p=obj->next;
    while(p&&index)
    {
        index--;
        p=p->next;
    }
    if(!p)
    return -1;
    return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *new_first=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    new_first->val=val;
    new_first->next=obj->next;
    obj->next=new_first;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *new_tail=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    new_tail->val=val;
    while(obj->next)
    {
        obj=obj->next;
    }
    new_tail->next=NULL;
    obj->next=new_tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    //index--;
    while(index&&obj)
    {
        index--;
        obj=obj->next;
    }
    if(!obj)
    return ;
    MyLinkedList *new_node=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    new_node->val=val;
    new_node->next=obj->next;
    obj->next=new_node;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  //index--;
  while(index&&obj->next)
  {
      index--;
      obj=obj->next;
  }
  if(!obj->next)
  return;
  MyLinkedList *q=obj->next;
  obj->next=q->next;
  free(q);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *p=obj;
    while(p)
    {
        obj=obj->next;
        free(p);
        p=obj;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
