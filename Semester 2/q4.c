//implement doubly linked list
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

void insert_data(node** head,node** tail) //working
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
     new->next = *head;
     (*head)->prev = new;
     *head = new;
     }
 }

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
     new->prev = (*tail);
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
 else if((*head) == (*tail))
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
void delete_data_end(node** head,node** tail)  //working
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
	tmp = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
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
	    printf("-> %d -> ",tmp->data);
	    tmp = tmp->next;
	}
    }
}
void traverse_list_end(node *head, node *tail)  //not working
{
    node * tmp;
    if(head == NULL)
    {
	printf("\nList Empty");
    }
    else
    {

	tmp = tail;
	while(tmp != NULL)
	{
	    printf("-> %d -> ",tmp->data);
	    tmp = tmp->prev;
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
	printf("\n Enter 1 to insert the elements from the beg in the list: ");
	printf("\n Enter 2 to insert the elements from the end in the list: ");
	printf("\n Enter 3 to traverse the elements of the list: ");
	printf("\n Enter 4 to traverse the elements of the list in reverse: ");
	printf("\n Enter 5 to delete the elements from the beg in the list: ");
	printf("\n Enter 6 to delete the elements from the end in the list: ");
	printf("\n Enter 7 to exit: ");
	scanf("%d",&ch);

	switch(ch)
	{
	    case 1:
		    printf("\n Inserting the elements from the beg: \n");
		    insert_data(&head,&tail);
			break;


	    case 2:
		    printf("\n Inserting the elements from the end: \n");
		    insert_data_end(&head,&tail);
			break;


	    case 3:
		    printf("\n Displaying the elements: \n");
		    traverse_list(head,tail);
		    break;

	    case 4:
		    printf("\n Displaying the elements in reverse:  \n");
		    traverse_list_end(head,tail);
		    break;


	    case 5:
		    printf("\n Deleting the elements from the beg: \n");
		    delete_data(&head,&tail);
			break;

	    case 6:
		    printf("\n Deleting the elements from the end: \n");
		    delete_data_end(&head,&tail);
			break;

            case 7: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}