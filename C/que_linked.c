 /******************************************************************************
  文 件 名   : que_linked.c
  作    者   : Zhoutaoccu
  生成日期   : 2020年9月11日
  功能描述   : 链表实现队列操作
  1.日    期   : 2020年9月11日
    修改内容   : 创建文件
******************************************************************************/ 

#include <stdio.h>

struct Node {
    int val;
    struct Node *next;
}

struct Queue {
    struct Node *front;
    struct Node *rear;
}

int InitQueue(struct Queue *queue)
{
    if (!queue) {
        return -1;
    }

    queue.front = (struct Queue *)malloc(sizeof(struct Queue));
    if (!queue.front) {
        return -1;
    }

    queue->rear = queue->front;
    queue->front->next = NULL;
    return 0;
}

int EnQueue(struct Queue *queue, int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    if (!queue || !new) {
        return -1;
    }

    new->val = val;
    new->next = NULL;

    queue->rear->next = new;
    queue->rear = new;
    return 0;
}

int IsEmptyQueue(struct Queue *queue)
{
    if (queue && queue->front == queue->rear){
        return TRUE;
    }
    return FLASE;
}

int DeQueue(struct Queue *queue, int *ret)
{
    struct Node *p;
    if (!queue || !ret || isEmptyQueue(queue)) {
        return -1;
    }

    // 出队为front后一个节点
    p = queue->front->next;

    queue->front->next = p->next;
    *ret = p->val;

    if (p == queue->rear) {
        queue->front = queue->rear;
    }

    return 0;
}

int main()
{

}
