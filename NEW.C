//basic shapes using graphics.h header file
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main(){
int gdriver = DETECT, gmode;


initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

line(300,100,500,100); outtextxy(300,110,"line");
arc(200,200,0,120,30); outtextxy(200,200,"arc");
bar(350,250,550,290);  outtextxy(350,230,"bar");
circle(100,100,30);    outtextxy(80,100,"circle");
ellipse(400,400,0,270,30,30); outtextxy(400,410,"ellipse");


getch();
closegraph();

}
