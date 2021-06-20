#include<stdio.h>
#include<stdlib.h>

void linear_search(int a[], int item, int size)
{
    int i;
    int flag = 0;
    for(i=0; i<size; i++)
    {
        if(a[i] == item)
        {
           printf("\nElement found at %d",i+1);
           flag = 1;
           break; 
        }
    }
    if(flag == 0)
    {
        printf("\nElement not found");
    }
}

void binary_search(int a[],int left,int mid,int right,int size,int item)
{
    if(left <= right)
    {
        if(a[mid] == item)
        {
            printf("\nElement found at %d",mid+1);
        }
        else if(item < a[mid])
        {

            right = mid - 1;
            binary_search(a,left,(left+right)/2,right,size,item);
        }
        else
        {
            left = mid + 1;
            binary_search(a,left,(left+right)/2,right,size,item);
        }
    }
    else
    {
        printf("\n Element Not Found");
    }

}
void main()
{
    int item,i,ch;
    int a[6];
    int left,mid,right;
    // printf("Enter the size of the array: ");
    // scanf("%d",&size);
    // a = (int *)malloc(size*sizeof(int));
    printf("Enter the 6 elements for the array: ");
    for(i=0; i< 6;i++)
    {
        scanf("%d",&a[i]);

    }
    
    while(1)
    {
        printf("\nEnter 1 to enter element to find: ");
        printf("\nEnter 2 to use linear_search: ");
        printf("\nEnter 3 to use binary_search: ");
        printf("\nEnter 4 to Exit: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:
                printf("\nEnter the item of the array: ");
                scanf("%d",&item);
                break;
        
            case 2:
                linear_search(a,item,6);
                break;

            case 3:
                left = 0;
                right = 6;
                mid = (left + right)/2;
                binary_search(a,left,mid,right,6,item);
                break;
            
            default:
                printf("\n Exiting");
                exit(0);
        }
    }

}