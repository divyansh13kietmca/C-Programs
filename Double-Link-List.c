#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct LinkedList{
    int data;
    struct LinkedList *prev;
    struct LinkedList *next;
    
};
typedef struct LinkedList node;

insert_at_begin(node **head, node **tail)
{
    node *ptr,*temp;
    int data;
    printf("\nEnter the value: ");
    scanf("%d",&data);

    ptr = (node *)malloc(sizeof(node));

    if(*head == NULL){
        *head = ptr;
        *tail = ptr;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }
    printf("\n Inserted successfully");
    
}

insert_at_begin(node **head, node **tail)
{
    node *ptr,*temp;
    int data;
    printf("\nEnter the value: ");
    scanf("%d",&data);

    ptr = (node *)malloc(sizeof(node));

    if(*head == NULL){
        *head = ptr;
        *tail = ptr;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }
    printf("\n Inserted at beg successfully");    
}

insert_at_end(node **head,node **tail)
{
    node *ptr,*temp;
    int data;
    printf("\nEnter the value: ");
    scanf("%d",&data);

    ptr = (node *)malloc(sizeof(node));

    if(*head == NULL){
        *head = ptr;
        *tail = ptr;
    }
    else
    {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;

    }
    printf("\n Inserted at end successfully");    
    
}

void traverse(node *head, node *tail)
{
    node *temp;
    int yes;
    printf("\n Enter 1 to traverse from beginning\n Enter 0 to traverse from end");
    scanf("%d", &yes);
    if (yes)
    {
    temp = head;
    while(temp->next != NULL)
        {
        printf("%d ->",temp->data);
        temp = temp->next;
        }
    }
    else{

        temp = tail;
    while(temp->prev != NULL)
        {
        printf("%d <-",temp->data);
        temp = temp->prev;
        }
    }
}
void main(){
    node *head,*tail, *ptr;
    int value,ch;
    head = tail = NULL;
    
    switch(ch) 
    {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Traversing from end");
        printf("\n4. Exit");

        case 1:
            insert_at_begin(&head,&tail);
            break;
        
        case 2:
            insert_at_end(&head,&tail);
            break;

        case 3:
            traverse(head,tail);
            break;

        case 4:
            printf("\n Exiting");
            exit(0);
    }
}
