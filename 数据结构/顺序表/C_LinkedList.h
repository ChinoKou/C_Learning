#ifndef DataType
#define DataType int
#endif

typedef struct LinkedList{
    DataType data;
    struct LinkedList* next;
}LinkedList;