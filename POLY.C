#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct Polynomial{
    int cof;
    int pw;
    struct Polynomial *next;
};

typedef struct Polynomial poly;

void make_node(poly **head)
{
    *head = (poly *)malloc(sizeof(poly));
}

void insert_val(poly **head,int coff, int poww)
{
    poly *temp,*add;

     temp = *head;
     make_node(&add);
     add->cof = coff;
     add->pw = poww;

     if(*head == NULL){
	*head = add;
	add->next = NULL;
     }
     else{
	 while(temp->next!= NULL){
	    temp = temp->next;
	 }
	 temp->next = add;
	 add->next = NULL;
     }
    //  printf("\tAdded Successfully\n");

}


void insert_at_end(poly **head)// instead of order can also ask for number of terms
{

    int poww,coff,n = 1;
    int order;

    printf("\n\nEnter the number of terms in the equation: ");
    scanf("%d",&order);
    while( n <= order)
    {

	printf("\n\nEnter the power of X = ");
	scanf("%d",&poww);
	printf("Enter the Coffient of X^%d = ",poww);
	scanf("%d",&coff);

	insert_val(head,coff,poww);
	printf("\n Element Entered Successfully");
	n += 1;
    }

}
int check_list(poly *head,int poww){
 poly *temp;
 int flag=0;
 temp = head;
 while(temp->next != NULL)
 {
	 if(temp->pw == poww)
	{
		flag = 1;
		break;
	}
	temp = temp->next;
 }
 if (flag == 0){
	 return 0;
 }
 else{
	return 1;
 }
}
void traverse(poly *head)
{

    poly *temp;
    temp = head;
    printf("\n-----------------------------\n");
    while(temp != NULL)
    {
	printf("(%dX^%d) + ",temp->cof,temp->pw);
	temp = temp->next;
    }
    printf("\n-----------------------------\n");

}


void add_poly(poly **head1,poly **head2, poly **sum)
// extra check for highest pw and dont change
//if i know in which head it is seen then other loop will be started after it.
{

    poly *i,*j;
    int sums = 0;
    int check;
    insert_val(sum,sums,j->pw);
    for(i = *head1; i != NULL; i = i->next) //for same power addition
    {
	for(j = *head2; j != NULL; j = j->next)
	{
	    if( (i->pw) == (j->pw) )
	    {
		sums = (i->cof) + (j->cof);
		insert_val(sum,sums,j->pw);
	    }
	}

    }
    for(i = *head1; i->next != NULL; i = i->next) //for different power of first list
    {
    check = check_list(*sum,i->pw);
    if( check == 0)
	{
	 insert_val(sum,i->cof,i->pw);
	 }
    }
    for(i = *head2; i->next != NULL; i = i->next) //for different power of second list
    {
    check = check_list(*sum,i->pw);
    if( check == 0)
	{
	 insert_val(sum,i->cof,i->pw);
	 }
    }

    printf("\n\tDone Successfully\n\t");
}


void main()
{
    poly *head1,*head2,*head3, *temp;
    int ch;
    clrscr();
    make_node(&head1);
    head1 = NULL;
    make_node(&head2);
    head2 = NULL;
    make_node(&head3);
    head3 = NULL;

    while(1)
    {
	printf("\n Enter 1 to insert polynomial from highest to lowest acc to power of x");
	printf("\n Enter 2 to traverse polynomial");
	printf("\n Enter 3 to add polynomial");
	printf("\n Enter 4 to to traverse head 3");
	printf("\n Enter 9 to exit\t: ");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:
		insert_at_end(&head1);
		printf("\n\nEnter the second polynomial");
		insert_at_end(&head2);
		break;

	    case 2:
		traverse(head1);
		printf("\nThe second polynomial\n");
		traverse(head2);
		break;

	    case 3:
		add_poly(&head1,&head2,&head3);
		traverse(head3);
		break;

	    case 4:
		traverse(head3);
		break;

	    case 9:
		printf("\n\t\t Exiting");
		exit(0);

        }
    }
}