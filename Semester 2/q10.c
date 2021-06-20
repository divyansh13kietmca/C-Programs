//implement queue linked list fifo
//create node and head insert and delete and traverse

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct list {
    int data;
    struct list* prev;
    struct list* next;
};
typedef struct list node;


void insert_data_end(node** head,node** tail) //working 
{
 node *new, *tmp; int val;
 new = (node *)malloc(sizeof(node));
 new->next = NULL;
 
 printf("Enter the data to be inserted: ");
 scanf("%d",&val);
 new->data = val;

 if(*head == NULL)
 {
    *head = *tail = new;
 }
 else
 {
     (*tail)->next=new;
     new->prev = *tail;
     *tail = new;
 }
}
void delete_data(node** head,node** tail) //working
{
 node *tmp;
 
 if(*head == NULL)
 {
     printf("\n Empty");
 }
 else if(*head == *tail)
 {
     *head = *tail = NULL;
 }
 else
    {
    tmp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(tmp);
    }

}

void traverse_list(node *head, node *tail) //working
{
    node* tmp;
    if(head == NULL)
    {
        printf("\nList Empty");
    }
    else
    {
        tmp = head;  
        while(tmp != NULL)
        {
            printf("|%d|\t",tmp->data);
            tmp = tmp->next;
        }
    }
}

void main()
{
    node* head; node* tail; int ch;
    head = (node *)malloc(sizeof(node));
    head = NULL;
    tail = head;
    while(1)
    {
        printf("\n Enter 1 to insert the elements in the queue: ");
        printf("\n Enter 2 to traverse the elements of the queue: ");
        printf("\n Enter 3 to delete the elements in the queue: ");
        printf("\n Enter 4 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            
            case 1:
                    printf("\n Inserting the elements: \n");
                    insert_data_end(&head,&tail);
                        break;

            
            case 2:
                    printf("\n Displaying the elements: \n");
                    traverse_list(head,tail);
                    break;
                       
            
            case 3:
                    printf("\n Deleting the elements: \n");
                    delete_data(&head,&tail);
                        break;
            
            
            case 4: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}