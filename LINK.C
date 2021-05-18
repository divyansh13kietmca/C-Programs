#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

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
    node *loc;
    loc = (node *)malloc(sizeof(node));
    loc->data = data;
    loc->next = NULL;
    if(*H == NULL){
	*H = loc;
    }
    else{
	loc->next = *H;
	loc = *H;
    }

}
void print_node(node *H){
    while(H != NULL)
    {
    printf("Node data = %d",H->data);
    // printf("Node next add = %ls",H->next);
    H = H->next;
    }
}
    /*
void insert_at_end(node **H, int data){
    node *loc;
    loc = (node *)malloc(sizeof(node));
    loc->data = data;
    loc->next = NULL;
    if (*H == NULL){
	*H = loc;
    }
    else{
    while(H->next != NULL){
	H = H->next;
    }

 }
}   */
void main(){

    node *head;
    int data;int i = 0;
    clrscr();
    head = (node *)malloc(sizeof(node));
    create_node(&head);
    printf("Enter data: ");
    scanf("%d",&data);
    for(i=0;i<3;i++){
    insert_node(&head,data);}
    print_node(head);
    getch();

}