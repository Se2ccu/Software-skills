/**
 *  Filename   : linkedlist.c
 *  Version    : V1.0
 *  Author     : Zhoutaoccu
 *  Date       : 2020.10.20
 *  Review
 *  Usage      : 
 *  Func Name  : 
 *  Web Link   : 
 *  How to use : 
 *  Paramenters 1 :   
 *  Paramenters 2 :   
 *  Paramenters 3 :   
 *  History:
 *  1.Date     : 2020.10.20
 *    Author   : Zhoutaoccu
 *    Content  : Creat New File
*/ 

// Self Reference

// Single-LinkedList
struct Node {
    int data;
    struct Node *next;
}

// Double-LinkedList
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
}

int InsertNode(struct Node *head, struct Node *new, int prevValue)
{
    struct Node *cur;
    
    if (!head || !new) {
        return -1;
    }

    cur = head->next;

    while (cur != NULL) {
        if (cur->data == prevValue) {
            break;
        }
        cur = cur->next;
    }

    if (!cur) {
        return -1;
    }

    new->next = cur->next;
    cur->next = new;

    return 0;
}

int DelNode(struct Node *head, struct Node *new, int prevValue)
{
    pre->next = cur->next;
    cur->next = NULL;
}

// Double-LinkedList
int InsertList(strct Node *cur, struct Node *new)
{
    if (!cur) {
        return -1;
    }

    new->next = cur->next;
    cur->next->prev = new;
    cur->next = new;
    new->prev = cur;
    return 0;
}

int DelList(struct Node *cur)
{
    if (!cur) {
        return -1;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    cur->prev = NULL;
    cur->next = NULL;
    return 0;
}