#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc, qsort */
#include <string.h>  /* strcpy,strcmp */

// 单链表用于节点数据存放
typedef struct node {
    int key;
    int value;
    struct node* next;
} NODE;

/* 查找是否存在该key */
NODE* FindNode(NODE* obj, int key)
{
    if (obj == NULL)
        return obj;
    NODE* head = obj;
    while(head) {
        if (head->key == key)
            return head;
        head = head->next;
    }
    return NULL;
}
/* 前插法，插入链表的前端 */
NODE* AddNode(NODE* obj, int key, int val)
{
    if(FindNode(obj, key)) {
        return obj;
    }
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->key = key;
    node->value = val;
    node->next = obj;
    return node;
}

NODE* DelNode(NODE* obj, int key)
{
    if (obj == NULL)
        return obj;
    NODE* head = NULL;
    if (obj->key == key) {
        head = obj->next;
        free(obj);
        return head;
    }

    NODE* prev = obj;
    NODE* node = obj->next;
    while (node) {
        if(node->key == key) {
            prev->next = node->next;
            free(node);
            return obj;
        }
        prev = node;
        node = node->next;
        
    }
    return obj;
}

/* 哈希函数指针 */
typedef int(*HASH_FUN)(int); 


#define HASH_SIZE 1000 // Hash Table Size

int hash_fun(int x) 
{
    return x % HASH_SIZE;
}

/* HashMap struct */
typedef struct {
    HASH_FUN fun;
    int len; // HASH_SIZE
    NODE* bkt[0]; // 动态指针数组
    
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap) + HASH_SIZE * sizeof(NODE*));
    if (obj == NULL)
        return NULL;
    memset(obj, 0, sizeof(MyHashMap) + HASH_SIZE * sizeof(NODE*));
    obj->fun = hash_fun;
    obj->len = HASH_SIZE;
    return obj;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    unsigned int index = obj->fun(key); // 链表中的序号
    NODE* head = obj->bkt[index];
    NODE* fobj = FindNode(head, key);
    if (fobj) {
        fobj->value = value;
    } else {
        obj->bkt[index] = AddNode(head, key, value);
    }
    return;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    unsigned int index = obj->fun(key);
    NODE* head = obj->bkt[index];
    NODE* fobj = FindNode(head, key);
    if (!fobj) return -1;
    return fobj->value;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    unsigned int index = obj->fun(key);
    NODE* head = obj->bkt[index];
    NODE* fobj = DelNode(head, key);
    obj->bkt[index] = fobj;
    return;
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < obj->len; i++) {
        NODE* head = obj->bkt[i];
        if (head == NULL) {
            continue;
        }
        NODE* node = head;
        NODE* next = head->next;
        while (node) {
            next = node->next;
            free(node);
            node = next;
        }
        obj->bkt[i] = NULL;
    }
    free(obj);
    return;

}

int main()
{
    MyHashMap hashMap = new MyHashMap();
    hashMap.put(1, 1);
    hashMap.put(2, 2); 
    hashMap.get(1); // returns 1
    hashMap.get(3); // returns -1 (not found)
    hashMap.put(2, 1);// update the existing value
    hashMap.get(2); // returns 1 
    hashMap.remove(2);// remove the mapping for 2
    hashMap.get(2); // returns -1 (not found)


}