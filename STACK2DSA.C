#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *Top = NULL;  

void push(int pushdata) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    new->data = pushdata;
    new->next = Top;
    Top = new;  
}

void pop() {
    struct node *temp;
    if (Top == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = Top;
        Top = Top->next;
        free(temp);
       
    }
}

void display() {
    struct node *temp = Top;
    if (Top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int operate;
    char choice;
    int value;
    do {
        printf("Enter the operation:\n1 for Push \n2 for Pop \n3 for Display \n4 to Exit\n");
        scanf("%d", &operate);  

        switch (operate) {
        case 1:
            
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to continue? If yes then enter y:");
        scanf(" %c,&choice");
    } while (choice=='y');

    return 0;
}