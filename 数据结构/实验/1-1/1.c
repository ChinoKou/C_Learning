#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial{
    int data[2];
    struct Polynomial *next;
}Polynomial;

void        print           (Polynomial *node);
void        node_delete     (Polynomial *last);
void        Polynomial_Sort (Polynomial *node);
Polynomial *Polynomial_Create();
Polynomial *Polynomial_Add  (Polynomial Polynomial_1, Polynomial Polynomial_2);

int main(){

    printf("请输入第一个多项式:\n");
    Polynomial *Polynomial_1 = Polynomial_Create();
    printf("第一个多项式创建完成,排序和操作重复项后\n");
    print(Polynomial_1);

    printf("请输入第二个多项式:\n");
    Polynomial *Polynomial_2 = Polynomial_Create();
    printf("第二个多项式创建完成,排序和操作重复项后\n");
    print(Polynomial_1);

    printf("多项式相加前:\n");
    printf("多项式一:\n");
    print(Polynomial_1);
    printf("多项式二:\n");
    print(Polynomial_2);
    Polynomial *Polynomial_3 = Polynomial_Add(*Polynomial_1, *Polynomial_2);
    printf("相加后:\n");
}

void print(Polynomial *node){
    for (Polynomial *temp = node; temp != NULL; temp = temp->next){
        printf("%dX^%d+", temp->data[0], temp->data[1]);
    }
}

void node_delete(Polynomial *last){
    Polynomial *temp = last->next;
    last->next = temp->next;
    free(temp);
}

Polynomial *Polynomial_Create(){
    int n, input_data[2];
    printf("请输入 n 的值");
    scanf("%d", &n);
    Polynomial *head = NULL, *temp = NULL, *tail = NULL;
    for (int i = 0; i < n; i++){
        temp = (Polynomial*)malloc(sizeof(Polynomial));
        temp->next = NULL;
        scanf("%d %d", &(temp->data[0]), &(temp->data[1]));
        if (head == NULL || tail == NULL) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    Polynomial_Sort(head);
    for (Polynomial *last = head, *temp = head; temp != NULL; temp = temp->next){
        if (temp->data[0] == 0 && temp != head){
            node_delete(last);
            temp = last;
        }
        else if (temp->data[0] == 0 && temp == head){
            head = head->next;
            free(temp);
            temp = head;
        }
        if (last->data[1] == temp->data[1]){
            int choice;
            printf("两项指数相同\n");
            printf("%dx^%d %dx^%d\n", tail->data[0], tail->data[1], temp->data[0], temp->data[1]);
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
                for (int i = 0; i < 2; i++) temp_data[i] = temp_1->data[i];
                for (int i = 0; i < 2; i++) temp_1->data[i] = temp_2->data[i];
                for (int i = 0; i < 2; i++) temp_2->data[i] = temp_data[i];
            }
        }
    }
}

Polynomial *Polynomial_Add(Polynomial Polynomial_1, Polynomial Polynomial_2){
    Polynomial *temp = (Polynomial*)malloc(sizeof(Polynomial));
    return temp;
}