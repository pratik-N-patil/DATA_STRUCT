#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;

};
void linklisttravsal(struct node*ptr){
    while(ptr!=NULL){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node*first;
    struct node*second;
    struct node*third;
    struct node*forth;
    //dynamic memory allocating
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));
    //data and adrees allocation
    first->data=4;
    first->next=second;
    second->data=5;
    second->next=third;
    third->data=7;
    third->next=forth;
    forth->data=8;
    forth->next=NULL;
    linklisttravsal(first);
}