#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList node;
void create_node(node **H)
{

    *H = NULL;
    printf("Node Created\n");

}
void insert_node(node **H, int data){
    *H->data = data;
    *H->next = NULL;
}
void print_node(node **H){

    printf("Node data = %d",*H->data);
    printf("Node next add = %ls",*H->next);
}
void main(){

    node *head; 
    int data;
    head = (node *)malloc(sizeof(node));
    create_node(&head);
    printf("Enter data: ");
    scanf("%d",&data);
    insert_node(&head,data);
    print_node(&head);


}
