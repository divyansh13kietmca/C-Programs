//queue using array
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 5
struct list
{
    int a[MAX];
    int front;
    int rear;
};
typedef struct list queue; 
void enqueue(queue **q) //working
{
    int data;
    if( ((*q)->rear == MAX-1 && (*q)->front == 0) || ((*q)->rear == (*q)->front-1) ) //just behind
    {
        printf("\n Queue is full");
    }
    else if(((*q)->rear == MAX - 1) && ((*q)->front != 0))
    {
        printf("\nEnter the element: ");
        scanf("%d",&data);
        (*q)->rear = 0;
        (*q)->a[(*q)->rear] = data;
 
    }
    else 
    {   
        printf("\nEnter the element: ");
        scanf("%d",&data);

        if((*q)->front == -1)
        {
            (*q)->front = (*q)->rear = 0;

        }
        else
        {
            (*q)->rear += 1;
        }
        (*q)->a[(*q)->rear] = data;
    }
        
}
int dequeue(queue **q)  // working
{
    int data = -1;
    if((*q)->front == -1)
    {
        printf("\n Queue is Empty");
    }
    else if((*q)->front == MAX-1)
    {
        data = (*q)->a[(*q)->front];
        (*q)->front = 0;
    }
    else if((*q)->front == (*q)->rear)
    {
        data = (*q)->a[(*q)->front];
        (*q)->front = (*q)->rear = -1;
    }
    else
    {
        data = (*q)->a[(*q)->front];
        (*q)->front += 1;
    }
    return data;
}
void peep(queue *q) //not working
{
    int i;
    if(q->front == -1)
    {
        printf("\n Queue is Empty");
    }
    else 
    {
        if(q->front <= q->rear) 
        {
            i= q->front;
        
            for(;i <= q->rear; i++)
            {
                printf("\t %d",q->a[i]);
            }
        }
        else // r ----- f
        {
            i = 0;    //start to rear
            for(;i <= q->rear; i++)
            {
                printf("\t %d",q->a[i]);
            }
            i=q->front; //front to last
            for(;i <= MAX - 1; i++)
            {
                printf("\t %d",q->a[i]);
            }
        }
    }
}
void main()
{
    queue* element; int ch;
    element = (queue *)malloc(sizeof(queue));
    element->front = element->rear = -1;

    while(1)
    {
        printf("\n\n Enter 1 to insert the elements in the circular queue: ");
        printf("\n Enter 2 to delete the elements of the circular queue: ");
        printf("\n Enter 3 to traverse the elements of the circular queue: ");
        printf("\n Enter 4 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\n Inserting the element : \n");
                    enqueue(&element);
                    break;

            
            case 2:
                    printf("\n Deleting the element : %d\n",dequeue(&element));
                    break;

            
            case 3:
                    printf("\n Displaying the elements: \n");
                    peep(element);
                    break;
            
            
            case 4: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}