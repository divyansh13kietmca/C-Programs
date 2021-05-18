#include<stdio.h>
#include<stdlib.h>

typedef struct{
int age;
char *name;
}details;

/*
void swap(details *a, details *b, val)
{
details temp;

temp.val = *a.val;
*a.val = *b.val;
*b.val = temp;
}
*/
void main(int args, char *agrv[])
{
FILE *fp;
char ch; int i;
details d[5], tmp;
while(args == 2)
 {
printf("Enter the details of 5 students: ");
for(i=0; i<5;i++)
	{
printf("\nEnter the name: ");
scanf("%s",d[i].name);
printf("\nEnter the age: ");
scanf("%d",&d[i].age);
	}

for(i = 0; i< 5;  i++)
	{
if(d[i].age>d[i+1].age){
tmp = d[i];
d[i] = d[i+1];
d[i+1] = tmp;
		}
	}

fp = fopen(argv[1],"a+");
for(i =0; i<5; i++)
	{
fprintf(fp,"%d %s",d[i].age,d[i].name); 
	}
 }

fclose(fp);
}