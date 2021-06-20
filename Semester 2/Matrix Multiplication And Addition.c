//addition and multiplication of 2d arrays

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[3][3], b[3][3], i, j,k,ch;
    int add[3][3], mul[3][3];


    printf("\nEnter the elements of the array 1: ");

    for(i=0; i< 3; i++)
    {
        for(j = 0; j< 3; j++)
        {
        scanf("%d",&a[i][j]);
        }
    }


    printf("\nEnter the elements of the array 2: ");

    for(i=0; i< 3; i++)
    {
        for(j = 0; j< 3; j++)
        {
        scanf("%d",&b[i][j]);
        }
    }

    while(1)
    {
        printf("\n Enter 1 to add the elements of the array: ");
        printf("\n Enter 2 to multiply the elements of the array: ");
        printf("\n Enter 3 to exit: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("\n Adding both the matrixes\n");
                     for(i=0; i<3; i++)
                        {
                            for(j = 0; j< 3; j++)
                            {
                                add[i][j] = a[i][j] + b[i][j];
                                printf("\t %d",add[i][j]);
                            }
                            printf("\n");
                        }
                        break;

            case 2: 
                    printf("\n Multiplying both the matrixes\n");
                   for(i=0; i<3; i++)
                        {
                            for(j = 0; j< 3; j++)
                            {
                                mul[i][j] = 0;
                                for(k = 0; k< 3; k++)
                                {
                                    mul[i][j] += a[i][k] * b[k][j];

                                }
                                printf("\t %d",mul[i][j]);

                            }
                            printf("\n");
                        }
                        break;

            case 3: printf("\n ---------------Exiting the program -----------------\n");
                    exit(0);
        }
    }
}
