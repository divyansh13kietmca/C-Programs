//implement  stack using link list
//create node and top insert and delete and traverse

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct list {  //making the structure
    int data;
    struct list* next;
};
typedef struct list node;

void insert_data_end(node** top) //working
{
 node *new, *tmp; int val;
 new = (node *)malloc(sizeof(node));   //new node
 new->next = NULL;   
 
 printf("Enter the data to be inserted: ");
 scanf("%d",&val);
 new->data = val;     //new value

 if(*top == NULL)  //check empty
 {
    *top = new;  //single element inserted
 }
 else
 {
     tmp = *top;  //traverse
     while(tmp->next != NULL)   //last element
     {
         
        tmp = tmp->next;  //moving pointer
        
     }
     tmp->next = new;  //adding value
 }

}

void delete_data_end(node** top) //
{
    node *del, *tmp;

    if(*top == NULL)  //check empty
        {
            printf("Empty list ");
        }
    else if((*top)->next == NULL) //single element
        {
            del = *top;
            *top = NULL;
            free(del);
        }
    else  
    {
        tmp = *top;  //traverse
        while((tmp->next)->next != NULL)   //last element
        {
            
            tmp = tmp->next;  //moving pointer
            
        }
        del = tmp->next;
        tmp->next = NULL;
        free(del);
    }

}


void traverse_list_end(node *top)  //single pointer means location no change //working
{
    node* tmp; int ar[10],i;
    int count=0;
    if(top == NULL)   //empty 
    {
        printf("\nList Empty");
    }
    else
    {
        tmp = top;  
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
       printf(" |%d|\n ",ar[i]);

    }
}
void main()
{
    node* top; int ch;
    top = (node *)malloc(sizeof(node));
    top = NULL;
    while(1)
    {
        // printf("\n Enter 1 to insert the elements from the beg in the list: ");
        printf("\n Enter 1 to insert the elements from the end in the stack: ");
        // printf("\n Enter 3 to traverse the elements of the list: ");
        printf("\n Enter 2 to traverse the elements of the stack: ");
        // printf("\n Enter 5 to delete the elements from the beg in the list: ");
        printf("\n Enter 3 to delete the elements from the stack: ");
        printf("\n Enter 4 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\n Pushing the elements: \n");
                    insert_data_end(&top);
                        break;
   
            case 2:
                    printf("\n Peeping the elements:  \n");
                    traverse_list_end(top);
                    break;
            
    
            case 3:
                    printf("\n Poping the elements : \n");
                    delete_data_end(&top);
                        break;
            
            case 4: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}