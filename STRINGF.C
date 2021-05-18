//6 functions of string header file.`
#include<string.h>
#include<conio.h>

void main() {

char arr[80], dest[80];
char *ar2, *ar3;
int len,check;

clrscr();

printf("Enter the string: ");
gets(arr);

strupr(arr);
printf("\nAfter appling strupr = %s",arr);

strrev(arr);
printf("\nAfter appling strrev = %s",arr);

len = strlen(arr);
printf("\nAfter appling strlen = %d",len);

strcpy(dest,arr);
printf("\nAfter appling strcpy dest = %s  and src = %s",dest,arr);

strcat(dest,arr);
printf("\nAfter appling strcat dest = %s  and src = %s",dest,arr);

check=strcmp(dest,arr);
if(check != 0){
 printf("\n strings %s and %s are not equal",dest,arr);
}
getch();
}