#include <stdio.h>
#include <malloc.h>

typedef struct Polynomial{
    int data[2];
    struct Polynomial *next;
}Polynomial;

Polynomial *Polynomial_Input();
void        Polynomial_Print(Polynomial *node);
void        Polynomial_Sort (Polynomial *node);
Polynomial *Polynomial_Add  (Polynomial Polynomial_1, Polynomial Polynomial_2);

int main(){
    printf("请输入第一个多项式:\n");
    Polynomial *Polynomial_1 = Polynomial_Input();

    printf("排序前:\n");
    Polynomial_Print(Polynomial_1);

    Polynomial_Sort(Polynomial_1);

    printf("\n排序后:\n");
    Polynomial_Print(Polynomial_1);

    printf("请输入第二个多项式:\n");
    Polynomial *Polynomial_2 = Polynomial_Input();
    Polynomial_Sort(Polynomial_2);

    printf("多项式相加前:\n");
    printf("多项式一:\n");
    Polynomial_Print(Polynomial_1);
    printf("多项式二:\n");
    Polynomial_Print(Polynomial_2);

    Polynomial_Add(*Polynomial_1, *Polynomial_2);

    printf("相加后:\n");
}

void Polynomial_Print(Polynomial *node){
    for (Polynomial *temp = node; temp != NULL; temp = temp->next){
        printf("%dX^%d+", temp->data[0], temp->data[1]);
    }
}

Polynomial *Polynomial_Input(){
    int input_1, input_2;
    Polynomial *head = NULL, *temp = NULL, *tail = NULL;
    printf("输入多项式(最后请输入Ctrl+Z以结束):\n");
    while (scanf("%d %d", &input_1, &input_2) == 2){
        temp = (Polynomial*)malloc(sizeof(Polynomial));
        temp->data[0] = input_1;
        temp->data[1] = input_2;
        temp->next = NULL;
        if (head == NULL || tail == NULL) head = tail = temp;
        else if (tail->data[1] == temp->data[1]){
            int choice;
            printf("两项指数相同\n");
            printf("%dx^%d %dx^%d\n", tail->data[0], tail->data[1], temp->data[0], temp->data[1]);
            printf("请选择: 1-舍弃 2-覆盖 3-系数相加\n");
            scanf("%d", &choice);
            if      (choice == 1) continue;
            else if (choice == 2) for (int i = 0; i < 2; i++) tail->data[i] = temp->data[i];
            else if (choice == 3) for (int i = 0; i < 2; i++) tail->data[i] += temp->data[i];
        }
        else{
            tail->next = temp;
            tail = temp;
        }
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
    
}