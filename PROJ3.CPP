#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int i, j, x=272, y=430, key, score=0, m[63], n[63], c1[63], c2[63], step=10;
int speed=150, ch;
char scostr[10];

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void xmove(void);
void ourcar(void);
void fcar(int, int, int, int);
void result(void);
void game(void);
void start(void);
void cont(void);
void level(void);


void main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

start();

getch();
cleardevice();
closegraph();
}

void level()
{
 cleardevice();
 setbkcolor(15);
 setcolor(6);
 rectangle(1,31,638,478);
 rectangle(4,34,635,475);
 rectangle(5,35,634,474);
 rectangle(95,70,550,164);
 rectangle(94,69,551,165);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(100,100,6);
 setcolor(2);
 settextstyle(4,0,6);
 outtextxy(130,80,"CAR  RACING");

 setcolor(CYAN);
 settextstyle(7,0,4);
 outtextxy(70,190,"SELECT DIFFICULTY:-");

 setcolor(4);
 settextstyle(0,0,3);
 outtextxy(160,250,"1. VERY EASY");
 outtextxy(160,300,"2. EASY");
 outtextxy(160,350,"3. MEDIUM");
 outtextxy(160,400,"4. DIFFICULT");
 scanf("%d",&ch);
 switch(ch)
 {
    case 1:   speed=200;
	      break;
    case 2:   break;
    case 3:   speed=100;
	      break;
    case 4:   speed=50;
	      break;
    default:  setcolor(8);
	      settextstyle(1,0,3);
	      outtextxy(225,437,"WRONG CHOICE");
	      delay(1000);
	      level();
 }
 game();
}


void start()
{
 cleardevice();
 setbkcolor(15);
 setcolor(6);
 rectangle(1,31,638,478);
 rectangle(4,34,635,475);
 rectangle(5,35,634,474);
 rectangle(95,70,550,164);
 rectangle(94,69,551,165);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(100,100,6);
 setcolor(2);
 settextstyle(4,0,6);
 outtextxy(130,80,"CAR  RACING");

 setcolor(8);
 settextstyle(8,0,1);
 outtextxy(175,195,"1. START GAME");
 outtextxy(175,215,"2. CONTINUE (CURRENTLY NOT WORKING)");
 outtextxy(175,235,"3. EXIT");

 setcolor(CYAN);
 settextstyle(7,0,3);
 outtextxy(190,315,"CHOOSE AN OPTION");
 outtextxy(200,345,"& PRESS ENTER");

 setcolor(BROWN);
 settextstyle(0,0,3);
 outtextxy(80,410,"DESIGNED BY:- RAJ SEN");

 scanf("%d",&ch);
 switch(ch)
 {
      case 1:   level();
		break;
      case 2:   cont();
		break;
      case 3:   exit(0);
		break;
      default:  setcolor(RED);
		settextstyle(0,0,2);
		outtextxy(220,280,"WRONG CHOICE");
		delay(1000);
		start();
 }
}


void cont()
{
  cleardevice();
  setcolor(15);
  rectangle(1,31,638,478);
  rectangle(4,34,635,475);
  rectangle(5,35,634,474);
  setcolor(RED);
  settextstyle(0,0,5);
  outtextxy(85,110,"Sorry we are");
  outtextxy(65,210,"not available");
  outtextxy(135,310,"right now");
  getch();
  start();
}

void result()
{
 cleardevice();
 setbkcolor(15);
 setcolor(6);
 rectangle(1,31,638,478);
 rectangle(4,34,635,475);
 rectangle(5,35,634,474);
 setcolor(RED);
  if(score==2900)
  {settextstyle(0,0,7);
   outtextxy(150,110,"YOU WON");
  }
  else
  {settextstyle(0,0,7);
   outtextxy(100,110,"Game Over");
  }
  setcolor(BROWN);
  settextstyle(7,0,5);
  outtextxy(100,200,"Your Score: ");
  sprintf(scostr,"%d",score);
  outtextxy(400,200,scostr);

 setcolor(8);
 settextstyle(3,0,4);
 outtextxy(230,285,"1. Play Again");
 outtextxy(230,320,"2. Select Level");
 outtextxy(230,355,"3. Main Menu");
 scanf("%d",&ch);
 switch(ch)
 {
     case 1:    game();
		break;
     case 2:    level();
		break;
     case 3:	start();
		break;
     default:   setcolor(7);
		settextstyle(0,0,3);
		outtextxy(185,420,"WRONG CHOICE");
		delay(1000);
		result();
 }
}


void fcar(int r, int s, int c1, int c2)
{
setfillstyle(1,c1);
bar(r,s,r+30,s+35);
setfillstyle(1,c2);
bar(r+5,s+35,r+25,s+45);
setfillstyle(1,0);
bar(r+2,s+37,r+4,s+43);
bar(r+26,s+37,r+28,s+43);
setcolor(15);
}

void xmove()
{
switch(key)
{    case LEFT:    if(x>152)  x-=60;
		   break;
     case RIGHT:   if(x<452)  x+=60;
		   break;
}
}

void ourcar()
{
setfillstyle(2,BROWN);
bar(x,y,x+35,y+40);
setfillstyle(1,YELLOW);
bar(x+5,y-15,x+30,y);
setfillstyle(1,0);
bar(x+2,y-13,x+4,y-2);
bar(x+31,y-13,x+33,y-2);
setcolor(15);
}


void game()
{
score=0;
cleardevice();
setbkcolor(0);
srand(time(0));
setcolor(15);
setlinestyle(0,0,1);
rectangle(1,1,639,479);
rectangle(140,1,500,479);
setfillstyle(1,LIGHTGREEN);
floodfill(2,2,15);
setfillstyle(1,LIGHTGREEN);
floodfill(630,2,15);
setcolor(6);
settextstyle(0,0,1);
outtextxy(10,25,"Score: ");
setcolor(15);
for(i=0;i<21;i++)
{
m[3*i]= 152+60*(rand()%6);    n[3*i]=0;
m[3*i+1]= 152+60*(rand()%6);    n[3*i+1]=0;
m[3*i+2]= 152+60*(rand()%6);    n[3*i+2]=0;
col:
c1[3*i]=1+rand()%15;       c2[3*i]=1+rand()%15;
c1[3*i+1]=1+rand()%15;     c2[3*i+1]=1+rand()%15;
c1[3*i+2]=1+rand()%15;     c2[3*i+2]=1+rand()%15;
if(c1[3*i]==7||c1[3*i+1]==7||c1[3*i+2]==7||c2[3*i]==7||c2[3*i+1]==7||c2[3*i+2]==7)
goto col;
}

while(1)
{
while(!kbhit())
{
setfillstyle(1,LIGHTGRAY);
bar(140,1,500,479);
setlinestyle(0,0,3);
setcolor(BROWN);
line(140,1,140,479);
line(500,1,500,479);
setcolor(6);
gotoxy(10,2);
printf("%d",score);
setcolor(15);
setlinestyle(3,3,3);
for(i=200;i<=440;i+=60)
line(i,1,i,479);

for(i=0;i<21;i++)
{
if(score>=i*120)
{ fcar(m[3*i],n[3*i],c1[3*i],c2[3*i]);
  fcar(m[3*i+1],n[3*i+1],c1[3*i+1],c2[3*i+1]);
  fcar(m[3*i+2],n[3*i+2],c1[3*i+2],c2[3*i+2]);
  n[3*i]+=step;      n[3*i+1]+=step;      n[3*i+2]+=step;
}
else         break;
}

ourcar();
score+=10;
delay(speed);
for(i=0;i<63;i++)
if((n[i]>=370)&&(n[i]<=470)&&(m[i]==x))   result();
if(score==2900)   result();
}
key=getch();


if(key==27)
{
cleardevice(); closegraph();
exit(0);
}
switch(key)
{  case LEFT:
   case RIGHT:  xmove();
}
}
}