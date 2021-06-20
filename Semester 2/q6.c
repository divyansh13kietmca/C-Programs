//stack using array

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 4
struct list {
    int data[MAX];
    int top;
};
typedef struct list stack;

void push(stack** element)
{
    int value,i;
    if(((*element) -> top) == MAX - 1)
    {
        printf("\n stack is full");
    }
    else
    {
        for(i = (*element)->top+1; i< MAX; i++)
        {
            printf("\n Enter the value to enter the stack: ");
            scanf("%d",&value);
            (*element)->data[i] = value;
            (*element)->top += 1;
        }
    }
}
int pop(stack** element)
{
    int item = 0;
    
    if((*element)-> top == -1)
    {
        printf("\n Stack is empty");

    }
    else
    {
        item = (*element)->data[(*element)->top];
        if((*element)->top == 0)
        {
            (*element)->top = -1;
            
        }
        else
        {
            (*element)->top -= 1;
        }
    }
    return item;
}
void peep(stack* element)
{
    int i;
    if(element-> top == -1)
    {
        printf("\n Stack Empty");
    }
    else
    {
        for(i = (element->top); i > -1 ; i--)
        {
            printf("\n\t %d ",element->data[i]);
        }
    }
}
// void arithmeticOperation()
void main()
{
    stack* element; int ch;
    element = (stack *)malloc(sizeof(stack));
    element->top = -1;

    while(1)
    {
        printf("\n Enter 1 to push the elements in the stack: ");
        printf("\n Enter 2 to pop the elements of the stack: ");
        printf("\n Enter 3 to peep the elements of the stack: ");
        printf("\n Enter 4 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\n Pushing the element : \n");
                    push(&element);
                    break;

            
            case 2:
                    printf("\n Poped the element : %d\n",pop(&element));
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