#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int count;
    int maxSize;
} CircularQueue;

CircularQueue* QueueCreate(int k) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->data = (int*)malloc(sizeof(int) * k);
    queue->front = 0;
    queue->count = 0;
    queue->maxSize = k;
    return queue;
}

int QueueAppend(CircularQueue* obj, int value) {
    if (obj->count == obj->maxSize) return 0;
    int last = (obj->front + obj->count) % obj->maxSize;
    obj->data[last] = value;
    obj->count++;
    return 1;
}

int QueueDelete(CircularQueue* obj) {
    if (obj->count == 0) return 0;
    obj->front = (obj->front + 1) % obj->maxSize;
    obj->count--;
    return 1;
}

int QueueGet(CircularQueue* obj) {
    if (obj->count == 0) return -1;
    return obj->data[obj->front];
}

int QueueIsEmpty(CircularQueue* obj) {
    return obj->count == 0;
}