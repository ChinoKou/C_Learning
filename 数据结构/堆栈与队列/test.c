#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

typedef struct LinkQueue {
    Node *last; // 尾指针，指向最后一个节点
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue *Q) {
    // 创建头结点
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head; // 头结点的next指向自身
    Q->last = head;    // 尾指针初始指向头结点
}

// 入队操作
void QueueAppend(LinkQueue *Q, DataType x) {
    Node *head = Q->last->next; // 获取头结点
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = head;       // 新节点指向头结点
    Q->last->next = new_node;    // 原尾节点指向新节点
    Q->last = new_node;          // 更新尾指针
}

// 出队操作
DataType DeQueue(LinkQueue *Q) {
    Node *head = Q->last->next; // 获取头结点
    if (head->next == head) {   // 队列为空（头结点指向自身）
        printf("Queue is empty, cannot dequeue.\n");
        exit(1);
    }
    Node *temp = head->next;     // 要删除的队头节点
    DataType data = temp->data;  // 保存数据
    head->next = temp->next;     // 头结点跳过待删除节点
    if (temp == Q->last) {       // 若删除的是尾节点（队列仅剩一个元素）
        Q->last = head;          // 重置尾指针指向头结点
    }
    free(temp);                  // 释放节点
    return data;
}