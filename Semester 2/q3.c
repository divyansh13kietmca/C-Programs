//implement single linked list
//create node and head insert and delete and traverse

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct list {  //making the structure
    int data;
    struct list* next;
};
typedef struct list node;

void insert_data_end(node** head) //working
{
 node *new, *tmp; int val;
 new = (node *)malloc(sizeof(node));   //new node
 new->next = NULL;   
 
 printf("Enter the data to be inserted: ");
 scanf("%d",&val);
 new->data = val;     //new value

 if(*head == NULL)  //check empty
 {
    *head = new;  //single element inserted
 }
 else
 {
     tmp = *head;  //traverse
     while(tmp->next != NULL)   //last element
     {
         
        tmp = tmp->next;  //moving pointer
        
     }
     tmp->next = new;  //adding value
 }

}
void insert_data(node** head)  //working
{
 node *new, *tmp; int val;
 new = (node *)malloc(sizeof(node));   //new node
 new->next = NULL;   
 
 printf("Enter the data to be inserted: ");
 scanf("%d",&val);
 new->data = val;     //new value

 if(*head == NULL)  //check empty
 {
    *head = new;  //single element inserted
 }
 else
 {
    new->next =  (*head);
    *head = new;  

 }

}
void delete_data_end(node** head) //
{
    node *del, *tmp;

    if(*head == NULL)  //check empty
        {
            printf("Empty list ");
        }
    else if((*head)->next == NULL) //single element
        {
            del = *head;
            *head = NULL;
            free(del);
        }
    else  
    {
        tmp = *head;  //traverse
        while((tmp->next)->next != NULL)   //last element
        {
            
            tmp = tmp->next;  //moving pointer
            
        }
        del = tmp->next;
        tmp->next = NULL;
        free(del);
    }

}
void delete_data(node** head)
{
    node *del;

    if(*head == NULL)  //check empty
        {
            printf("Empty list ");
        }
    else if((*head)->next == NULL) //single element
        {
            del = *head;
            *head = NULL;
            free(del);
        }
    else  
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        
    }

}
void traverse_list(node *head)  //single pointer means location no change //working
{
    node* tmp;
    if(head == NULL)   //empty 
    {
        printf("\nList Empty");
    }
    else
    {
        tmp = head;  
        while(tmp != NULL)
        {
            printf("-> %d -> ",tmp->data);
            tmp= tmp->next;
        }
    }
}
void traverse_list_end(node *head)  //single pointer means location no change //working
{
    node* tmp; int ar[10],i;
    int count=0;
    if(head == NULL)   //empty 
    {
        printf("\nList Empty");
    }
    else
    {
        tmp = head;  
        while(tmp != NULL)
        {
            ar[count] = tmp->data; 
            // printf("-> %d -> ",tmp->data);
            tmp= tmp->next;
            count++;
        }
    }
    for(i = count-1;i>=0;i--)
    {
       printf("-> %d -> ",ar[i]);

    }
}
void main()
{
    node* head; int ch;
    head = (node *)malloc(sizeof(node));
    head = NULL;
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
                    insert_data(&head);
                        break;

            
            case 2:
                    printf("\n Inserting the elements from the end: \n");
                    insert_data_end(&head);
                        break;

            
            case 3:
                    printf("\n Displaying the elements: \n");
                    traverse_list(head);
                    break;
            
            case 4:
                    printf("\n Displaying the elements in reverse:  \n");
                    traverse_list_end(head);
                    break;
            
            
            case 5:
                    printf("\n Deleting the elements from the beg: \n");
                    delete_data(&head);
                        break;
            
            case 6:
                    printf("\n Deleting the elements from the end: \n");
                    delete_data_end(&head);
                        break;
            
            case 7: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}