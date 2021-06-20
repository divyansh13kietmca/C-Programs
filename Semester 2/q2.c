    //transpose of 2d arrays
#include<stdio.h>
#include<stdlib.h>
void print(int arr[][3])
{
    int i,j;
    for(i = 0; i< 3; i++)
    {
        for(j = 0; j< 3; j++)
        {
            printf("\t %d",arr[i][j]);
        }
        printf("\n");
    }
}
void swap(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void main()
{
    int a[3][3], i, j,ch;
    

    printf("\nEnter the elements of the array 1: ");

    for(i=0; i< 3; i++)
    {
        for(j = 0; j< 3; j++)
        {
        scanf("%d",&a[i][j]);
        }
    }

    while(1)
    {
        printf("\n Enter 1 to transpose the elements of the array: ");
        printf("\n Enter 2 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\n After transposing the matrixes\n");
                    print(a);
                    printf("\n After transposing the matrixes\n");
                     for(i=0; i< 3; i++)
                        {
                            for(j = 0; j< 3; j++)
                            {
                                if( i < j)
                                {
                                swap(&a[j][i],&a[i][j]);
                                }
                            }
                        }
                    print(a);
                        break;

            case 2: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}