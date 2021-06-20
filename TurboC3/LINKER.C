#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList node;
void create_node(node **H)
{

    *H = NULL;
    printf("Empty List Created\n");

}
void insert_at_beg_node(node **H, int data){
    node *loc;
    loc = (node *)malloc(sizeof(node));
    loc->data = data;
    loc->next = NULL;
    if(*H == NULL){
	*H = loc;
    }
    else{
	loc->next = *H;
	*H = loc;
    }

}
void print_node(node *H){
    while(H != NULL)
    {
	printf("%d -> ",H->data);
    // printf("Node next add = %ls",H->next);
	H = H->next;
    }
}

void insert_at_end(node **H, int data){
    node *loc;
    node *last = *H;
    loc = (node *)malloc(sizeof(node));
    loc->data = data;
    loc->next = NULL;
    if (*H == NULL){
	*H = loc;
	return;
    }
    else
    {
    while(last->next != NULL)
	{
	last = last->next;
	}
    last->next = loc;
    return;
   }
}
void linear_search_list(node *head,int data){
	node *temp;
	int flag =0;
	temp = head;
	while(temp->next!=NULL)
	{
	 if(temp->data== data)
		{
		flag = 1;
		break;
		}
	 temp = temp->next;
	}
	if(flag)
	{
	printf("%d found",data);
	}
	else
	{
	 printf("%d not found",data);
	}
}
void insert_at_pos(node **head,int data,int pos)
{
  int count = 1;
  node *temp,*loc;
  loc = (node *)malloc(sizeof(node));
  loc->data = data;
  loc->next = NULL;
  temp = *head;
 if (pos==1)
 {
    printf("\nInsert at Beginning:");
    insert_at_beg_node(head,data);
 }
 else
 {
  while(temp->next!=NULL)
  {
    if(count == pos)
    {
    printf("\nAdded Successfully");
    loc->next= temp->next;
    temp->next = loc;
    break;
    }
    temp = temp->next;
    count += 1;
  }

 }

}

void delete_from_beg(node **head)
{
 node *temp;
 printf("\nDeleting from beginning");
 temp = *head;
 if(*head == NULL)
 {
  printf("\n List Already Empty");
  exit(0);
 }
 else
 {
 *head = (*head)->next;
 free(temp);
 }
}

void delete_from_end(node **head)
{
 node *temp,*fr;
 printf("\nDeleting from end");
 temp = *head;
 if(*head == NULL)
 {
  printf("\n List Already Empty");
  exit(0);
 }
 else
 {
 while((temp->next)->next!=NULL)
 {
  temp = temp->next;
 }
  fr = temp->next;
  temp->next = NULL;
  free(fr);
  }
}
void main(){

    node *head,*temp;
    int data,ch,pos;
    clrscr();
    head = (node *)malloc(sizeof(node));
    create_node(&head);
    while(1)
    {
	printf("\n\nEnter 1 to insert at beginning: ");
	printf("\nEnter 2 to insert at the end: ");
	//printf("\nEnter 3 to insert after the element: ");
	//printf("\nEnter 4 to insert at any position: ");
	printf("\nEnter 5 to traverse the linked list: ");
	//printf("\nEnter 6 to search the linked list: ");
       //printf("\nEnter 7 to traverse in reverse the linked list: ");
	printf("\nEnter 8 to delete from beg of the linked list: ");
	printf("\nEnter 9 to delete from end the linked list: ");
	//printf("\nEnter 10 to delete after the element: ");
	//printf("\nEnter 11 to delete element from specific postion: ");
	printf("\nEnter 10 to exit: ");
	scanf("%d",&ch);
	switch(ch)
	{
     case 1://insert at beginning
		printf("Enter data: ");
		scanf("%d",&data);
		insert_at_beg_node(&head,data);
		break;

     case 5://traverse the node

		printf("Traversing Nodes: \n");
		print_node(head);
		break;

     case 2://insert at end

		printf("\nEnter data: ");
		scanf("%d",&data);
		insert_at_end(&head,data);
		break;

     case 4://insert at any position
		printf("\nEnter the data: ");
		scanf("%d",&data);
		printf("\n Enter the position: ");
		scanf("%d",&pos);
		insert_at_pos(&head,data,pos);
		break;

     case 6://to search the linked list
		printf("Enter the element to search: ");
		scanf("%d",&data);
		linear_search_list(head,data);
		break;
     case 8://to delete from beginning
		delete_from_beg(&head);
		break;
     case 9://to delete from end of the list
		delete_from_end(&head);
		break;
     default:
		printf("Exiting");
		exit(0);

	}
    }
    //getch();
}
