#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial{
    int data[2];
    struct Polynomial *next;
}Polynomial;

void        node_delete      (Polynomial *last);
void        Polynomial_Sort  (Polynomial *node);
void        Polynomial_Print (Polynomial *node);
void        Polynomial_Free  (Polynomial *node);
Polynomial *Polynomial_Create();
Polynomial *Polynomial_Add   (Polynomial polynomial_1, Polynomial polynomial_2);
Polynomial *Polynomial_Minus (Polynomial polynomial_1, Polynomial polynomial_2);
Polynomial *Polynomial_Handle(Polynomial polynomial_1, Polynomial polynomial_2, int mode);

int main(){
    printf("请输入第一个多项式:\n");
    Polynomial *polynomial_1 = Polynomial_Create();
    printf("第一个多项式链表创建完成,排序和操作重复项后:\n");
    Polynomial_Print(polynomial_1);

    printf("请输入第二个多项式:\n");
    Polynomial *polynomial_2 = Polynomial_Create();
    printf("第二个多项式链表创建完成,排序和操作重复项后:\n");
    Polynomial_Print(polynomial_2);

    Polynomial *polynomial_3 = Polynomial_Add(*polynomial_1, *polynomial_2);
    printf("多项式相加并且删除系数为 0 的项和排序后:\n");
    Polynomial_Print(polynomial_3);

    Polynomial *polynomial_4 = Polynomial_Minus(*polynomial_1, *polynomial_2);
    printf("多项式相减并且删除系数为 0 的项和排序后:\n");
    Polynomial_Print(polynomial_4);

    Polynomial_Free(polynomial_1);
    Polynomial_Free(polynomial_2);
    Polynomial_Free(polynomial_3);
    Polynomial_Free(polynomial_4);

    return 0;
}

void Polynomial_Print(Polynomial *node){
    for (Polynomial *temp = node; temp != NULL; temp = temp->next){
        if      (temp == node)  printf("%dx^%d",     temp->data[0] , temp->data[1]);
        else if (temp != node)  printf("%dx^%d", abs(temp->data[0]), temp->data[1]);
        if      (temp->next == NULL) continue;
        else if (temp->next->data[0] > 0) printf(" + ");
        else if (temp->next->data[0] < 0) printf(" - ");
    }
    printf("\n\n");
}

void Polynomial_Free(Polynomial *node) {
    Polynomial *temp = node;
    while (temp != NULL) {
        Polynomial *next = temp->next;
        free(temp);
        temp = next;
    }
}

void node_delete(Polynomial *last){
    Polynomial *temp = last->next;
    last->next = temp->next;
    free(temp);
}

Polynomial *Polynomial_Create(){
    int n, input_data[2];
    Polynomial *head = NULL, *temp = NULL, *tail = NULL;
    printf("请输入 n 的值: ");
    scanf("%d", &n);
    printf("输入 %d 组元素: ", n);
    for (int i = 0; i < n; i++){
        temp = (Polynomial*)malloc(sizeof(Polynomial));
        temp->next = NULL;
        scanf("%d %d", &(temp->data[0]), &(temp->data[1]));
        if (head == NULL) head = temp;
        else if (temp->data[0] == 0) continue;
        else tail->next = temp;
        tail = temp;
    }
    Polynomial_Sort(head);
    for (Polynomial *last = head, *temp = head->next; temp != NULL; temp = temp->next){
        if (last->data[1] == temp->data[1]){
            int choice;
            printf("两项指数相同\n");
            printf("%dx^%d %dx^%d\n", last->data[0], last->data[1], temp->data[0], temp->data[1]);
            printf("请选择: 1-舍弃 2-覆盖 3-系数相加\n");
            scanf("%d", &choice);
            if      (choice == 2) for(int i = 0; i < 2; i++) last->data[i] = temp->data[i];
            else if (choice == 3) last->data[0] += temp->data[0];
            node_delete(last);
            temp = last;
        }
        last = temp;
    }
    return head;
}

void Polynomial_Sort(Polynomial *node){
    for (Polynomial *temp_1 = node; temp_1 != NULL; temp_1 = temp_1->next){
        for (Polynomial *temp_2 = temp_1; temp_2 != NULL; temp_2 = temp_2->next){
            if (temp_1->data[1] > temp_2->data[1]){
                int temp_data[2];
                for (int i = 0; i < 2; i++){
                    temp_data[i] = temp_1->data[i];
                    temp_1->data[i] = temp_2->data[i];
                    temp_2->data[i] = temp_data[i];
                }
            }
        }
    }
}

Polynomial *Polynomial_Add(Polynomial polynomial_1, Polynomial polynomial_2){
    return Polynomial_Handle(polynomial_1, polynomial_2, 1);
}

Polynomial *Polynomial_Minus(Polynomial polynomial_1, Polynomial polynomial_2){
    return Polynomial_Handle(polynomial_1, polynomial_2, 2);
}

Polynomial *Polynomial_Handle(Polynomial polynomial_1, Polynomial polynomial_2, int mode){
    Polynomial *temp_1, *temp_2, *head = NULL, *last = NULL;
    for (temp_2 = &polynomial_2; temp_2 != NULL; temp_2 = temp_2->next){
        Polynomial *temp = (Polynomial*)malloc(sizeof(Polynomial));
        temp->next = NULL;
        if      (mode == 1) temp->data[0] =     temp_2->data[0];
        else if (mode == 2) temp->data[0] = 0 - temp_2->data[0];
        temp->data[1] = temp_2->data[1];
        if (head == NULL) head = temp;
        else last->next = temp;
        last = temp;
    }
    for (temp_1 = &polynomial_1; temp_1 != NULL; temp_1 = temp_1->next){
        int found = 0;
        for (temp_2 = head, last = NULL; temp_2 != NULL; temp_2 = temp_2->next){
            if (temp_1->data[1] == temp_2->data[1]){
                temp_2->data[0] += temp_1->data[0];
                if (!temp_2->data) node_delete(last);
                found = 1;
            }
            last = temp_2;
        }
        if (!found){
            Polynomial *temp = (Polynomial*)malloc(sizeof(Polynomial));
            temp->data[0] = temp_1->data[0];
            temp->data[1] = temp_1->data[1];
            temp->next = head;
            head = temp;
        }
    }
    Polynomial_Sort(head);
    return head;
}