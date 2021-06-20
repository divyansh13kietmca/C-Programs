//poly addition and multiply

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct list {
    int data;
    int pow;
    struct list* next;
};
typedef struct list poly;
void insert_data(poly** head, int data, int pow) //working
{   
    poly *new,*tmp;
    new = (poly *)malloc(sizeof(poly));
    new->next = NULL;
    new->data = data;
    new->pow = pow;
    if(*head == NULL)
    {
        *head = new;

    }
    else
    {
        tmp = *head;
        while(tmp-> next!=  NULL)
        {
            tmp = tmp -> next;
        }
        tmp ->next = new;
    }
}
void insert_value(poly** first, poly** second) //for x~3 //working
{   int count,data,pow;
    int i = 0;

        printf("\n Enter the number of terms in first polynomial: ");
        scanf("%d",&count); 
        while(i < count)
        { 
           
            printf("\n Enter the data and pow for the %d term: ",i+1);
            scanf("%d %d",&data,&pow);
           
            insert_data(first,data,pow);
            i++;
        }
        printf("\n Enter the number of terms in second polynomial: ");
        scanf("%d",&count);
        i = 0; 
        while(i < count)
        { 
            printf("\n Enter the data and pow for the %d term: ",i+1);
            scanf("%d %d",&data,&pow);
            insert_data(second,data,pow);
            i++;
        }

    printf("\n Successfull Inserted");
}
void delete_data(poly** head, int pow)  //working
{  
    poly *tmp,*del; int flag = 0;
    if(*head == NULL) //Empty
    {
        printf("\n Empty polynomial");
    }
    else if((*head)->pow == pow)  //single element working 
    {
        del = *head;
        if ((*head)->next == NULL)
        {
            *head = NULL;
            
        }
        else
        {
            *head = (*head)->next;
        }
        free(del);
        printf("\n Successfull deleted");
    }
    else //others
    {
        tmp = *head;
        while(tmp !=  NULL)
        {   if((tmp->next)->pow == pow)
            {  
                flag = 1;
                break;
            }
            tmp = tmp->next;
        }
        
        if(flag == 0)
        {
            printf("\nElement not found");
        }
        else
        {
            del = tmp->next;
            tmp->next = (tmp->next)->next;
            free(del);
            printf("\n Successfully deleted");        
        
        }
        
    }
}
void delete_value(poly** first, poly** second)
{
    int ch,pow;
    printf("\nEnter from which polynomial the elements is to be deleted: ");
    scanf("%d",&ch);
    printf("\nEnter the power of x of the element which is to be deleted: ");
    scanf("%d",&pow);
    if(ch == 1)
    {
        delete_data(first,pow);
    }
    else
    {
        delete_data(second,pow);
    }

}
void traverse(poly* first, poly* second) //working
{
    poly* trav;
    if(first == NULL)
    {
        printf("\n first is Empty");
    }
    else
    {
        printf("\n Displaying all the elements of the first polynomial");
        trav = first;
        while(trav !=  NULL)
        {   
            printf("\t %d x^%d ",trav->data,trav->pow);
            trav = trav-> next;
        }
    }

    if(second == NULL)
    {
        printf("\n Second is Empty");
    }
    else
    {
        printf("\n Displaying all the elements of the Second polynomial");
        trav = second;
        while(trav !=  NULL)
        {   
            printf("\t %d x^%d ",trav->data,trav->pow);
            trav = trav-> next;
        }
    }
}
void addition(poly* first, poly* second, poly** sum) //working output wierd
{
    poly *i, *j, *trav; int flag = 1;
    for(i = first; i !=  NULL; i = i->next) //for same add
    {
      for(j = second; j !=  NULL; j = j->next)
      {
          if(i->pow == j->pow)
          { 
              insert_data(sum,((i->data)+(j->data)),i->pow);
          }
      }
    }
    for(i = first; i !=  NULL; i = i-> next) //for first poly
    {
        flag = 0;
      for(j = *sum; j !=  NULL; j = j-> next)
      {
          if(i-> pow == j->pow)
          { 
            flag = 1;
            break;
          }
      }

        if(flag == 0)
        {
            insert_data(sum,i->data,i->pow);
        }
    }

    for(i = second; i !=  NULL; i = i-> next) //for sec poly
    {
        flag = 0;
      for(j = *sum; j !=  NULL; j = j-> next)
      {
          if(i-> pow == j->pow)
          { 
            flag = 1;
            break;
          }
      }

        if(flag == 0)
        {
            insert_data(sum,i->data,i->pow);
        }
    }
    printf("\n Displaying all the elements of the sum polynomial\n");
    trav = *sum;
    while(trav !=  NULL)
    {   
        printf("\t %d x^%d ",trav->data,trav->pow);
        trav = trav-> next;
    }
}
void multiply(poly* first, poly* second, poly** mul) //powers add data mul 
{
    poly *i, *j, *trav; int count = 0;
    int total = 1;
    for(i = first; i !=  NULL; i = i->next) //for same add
    {
      for(j = second; j !=  NULL; j = j->next)
      {
        insert_data(mul,((i->data)*(j->data)),((i->pow)+(j->pow)));
      }
    }
    for(i = *mul; i !=  NULL; i = i->next) //for total count of same power of x 
    {
        for(j = i->next ; j !=  NULL; j = j->next)
        {
            if(i->pow == j->pow)
            {
                total++;
            }
        }

    }
    while(count != total)
    {
        for(i = *mul; i !=  NULL; i = i->next) //for remove unecessary vals
        {
            for(j = i->next ; j !=  NULL; j = j->next)
            {
                if(i-> pow == j->pow)
                {
                    j->data += i->data;
                    delete_data(mul,j->pow);
                    break;
                }
            }
        }
        count++;
    }

    printf("\n Displaying all the elements of the Multiplied polynomial\n");
    trav = *mul;
    while(trav !=  NULL)
    {   
        printf("\t %d x^%d ",trav->data,trav->pow);
        trav = trav-> next;
    }
    
}
void main()
{
    poly *first, *second, *add, *mul; int ch;
    
    first = (poly *)malloc(sizeof(poly));
    first = NULL;

    second = (poly *)malloc(sizeof(poly));
    second = NULL;
    
    add = (poly *)malloc(sizeof(poly));
    add = NULL;
    
    mul = (poly *)malloc(sizeof(poly));
    mul = NULL;
        while(1)
    {
        
        printf("\n\n Enter 1 to insert the elements of the polynomial: ");
        printf("\n Enter 2 to traverse the elements of the list: ");
        printf("\n Enter 3 to delete the elements from the polynomial: ");
        printf("\n Enter 4 to add the two polynomials: ");
        printf("\n Enter 5 to multiply the two polynomials: ");
        printf("\n Enter 6 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\n Inserting the elements : \n");
                    insert_value(&first,&second);
                        break;
            
            case 2:
                    printf("\n Displaying the elements: \n");
                    traverse(first,second);
                    break;
            
            case 3:
                    printf("\n Deleting the elements : \n");
                    delete_value(&first,&second);
                        break;
            
            case 4:
                    printf("\n Adding the elements of the polynomial: \n");
                    addition(first,second,&add);
                        break;
            
            
            case 5:
                    printf("\n Multiplying the elements of the polynomial: \n");
                    multiply(first,second,&mul);
                        break;
            
            default: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}
