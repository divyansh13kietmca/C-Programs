#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
FILE *fp1, *fp2;
char ch;
while(argc == 3)
{
fp1 = fopen(argv[1],"r");
fp2 = fopen(argv[2],"w+");
while((ch=fgetc(fp1))!=EOF)
{
fputc(ch,fp2);
}
printf(" 1 file copied successfully");
fclose(fp1);
fclose(fp2);
printf("\nDone");
exit(0);
}
printf("\nWrong input entered");
delay(5000);
}
