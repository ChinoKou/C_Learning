#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int data;
    struct List *next;
}List;

void ListPrint(List*);
List *ListInit();
int ListCount(List*);
void ListInsert(List*, int);
void ListDelete(List*, int);
int ListPop(List*, int);
void ListMerge(List*, List*, List*);

int main() {
    List *L1 = ListInit();
    for (int i = 1; i <= 20; i += 2) ListInsert(L1, i);
    ListPrint(L1);

    List *L2 = ListInit();
    for (int i = 1; i <= 20; i += 3) ListInsert(L2, i);
    ListPrint(L2);

    int count1 = ListCount(L1), count2 = ListCount(L2);

    List *L3 = ListInit();
    ListMerge(L1, L2, L3);
    ListPrint(L3);
}

void ListPrint(List *node) {
    for (List *temp = node->next; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n\n");
}

List *ListInit() {
    List *temp = (List*)malloc(sizeof(List));
    temp->next = NULL;
    return temp;
}

int ListCount(List *node) {
    int count = 0;
    for (List *temp = node->next; temp != NULL; temp = temp->next) {
        count += 1;
    }
    return count;
}

void ListInsert(List *node, int x) {
    if (node->next == NULL) {
        List *insert = (List*)malloc(sizeof(List));
        insert->data = x;
        insert->next = NULL;
        node->next = insert;
    }
    else {
        for (List *temp = node->next; temp != NULL; temp = temp->next) {
            if (x > temp->data) {
                List *insert = (List*)malloc(sizeof(List));
                insert->data = x;
                insert->next = temp->next;
                temp->next = insert;
                break;
            }
        }
    }
}

void ListDelete(List *node, int x) {
    for (List *temp = node->next; temp != NULL; temp = temp->next) {
        if (temp->next->data == x) {
            List *next = temp->next->next;
            free(temp->next);
            temp->next = next;
        }
    }
}

int ListPop(List *node, int i) {
    int j = 0;
    for (List *temp = node->next; temp != NULL; temp = temp->next, j++){
        if (j == i) return temp->data;
    }
    return 0;
}

void ListMerge(List *L1, List *L2, List *L3) {
    L1 = L1->next; L2 = L2->next;
    while (L1 != NULL || L2 != NULL) {
        List *temp = (List*)malloc(sizeof(List));
        if (L1->data < L2->data && L1 != NULL) {
            temp->data = L1->data;
            L1 = L1->next;
        }
        else {
            temp->data = L2->data;
            L2 = L2->next;
        }
        temp->next = NULL;
        L3->next = temp;
        L3 = L3->next;
    }
}