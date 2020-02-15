#include"BATTLESH.CPP"
#include"mouse.cpp"
#include<stdlib.h>
#include <graphics.h>
int jambu,rememberx=-1,remembery=-1,x,y;
struct lives
{
	int s;
	int d;
	int b;
	int c;
}u,p;
int check_pos1(int x,int y)
{
	int i,j;
	if(x<340) i=0;
	else if(x<360) i=1;
	else if(x<380) i=2;
	else if(x<400) i=3;
	else if(x<420) i=4;
	else if(x<440) i=5;
	else if(x<460) i=6;
	else if(x<480) i=7;
	if(y<170) j=0;
	else if(y<190) j=1;
	else if(y<210) j=2;
	else if(y<230) j=3;
	else if(y<250) j=4;
	else if(y<270) j=5;
	else if(y<290) j=6;
	else if(y<310) j=7;
	if(pc[1][j][i]!='\0') return 0;
	else return 1;
}
void pc_disp()
{
	for(int j=0,x=320;j<8;j++)
	{
		for(int i=0,y=150;i<8;i++)
		{
			if(pc[1][i][j]=='x')  setcolor(GREEN);
			else setcolor(RED);
			outtextxy(x+5,y+5,ctos(pc[1][i][j]));
			y+=20;
		}
		x+=20;
	}
}
void user_move()
{
	char a[50];
	setcolor(CYAN);
	setfillstyle(1,BLACK);
	do
	{	bar(10,340,470,380);//fill coordinates in later
		outtextxy(20,350,"ENTER POSITION TO ATTACK:");
		strcpy(a,accept1(400,350));
	}while(!(strlen(a)==2&&tolower(a[0])<='h'&&tolower(a[0])>='a'&&a[1]<='8'&&a[1]>='1'&&pc[1][tolower(a[0])-'a'][a[1]-'1']=='\0'));
	int j=tolower(a[0]-97);
	int i=a[1]-49;
	pc[1][j][i]=pc[0][j][i];
	bar(10,340,470,380);
	if(pc[0][j][i]!='x') outtextxy(100,350,"YOU HAVE HIT A SHIP");
	else outtextxy(100,350,"YOU HAVEN'T HIT ANY SHIPS");
	switch(pc[0][j][i])
	{
		case 's': p.s--; break;
		case 'd': p.d--; break;
		case 'b': p.b--; break;
		case 'c': p.c--;break;
		default: break;
	}
	getch();
	pc_disp();
	bar(10,340,470,380);
	if(pc[0][j][i]=='s'&&p.s==0) outtextxy(100,350,"SCAVENGER SUNK");
	else if(pc[0][j][i]=='d'&&p.d==0) outtextxy(100,350,"DESTROYER SUNK");
	else if(pc[0][j][i]=='c'&&p.c==0) outtextxy(100,350,"CARRIER SUNK");
	else if(pc[0][j][i]=='b'&&p.b==0) outtextxy(100,350,"BATTLESHIP SUNK");
	getch();
}
int gimmenames(char a)
{
	switch(a)
	{
		case 's': if(u.s==0) jambu=0; else jambu= 1;break;
		case 'b': if(u.b==0) jambu=0; else jambu= 1;break;
		case 'd': if(u.d==0) jambu=0; else jambu= 1;break;
		case 'c': if(u.c==0) jambu=0; else jambu= 1;break;
	}
	return jambu;
}
void scan(int &x,int& y)
{       int flag=0;
	for(int i=0;i<8&&flag==0;i++)
	{
		for(int j=0;j<8&&flag==0;j++)
		{
			if(user[1][i][j]!='\0'&&tolower(user[1][i][j])!='x')
			if(gimmenames(user[1][i][j])) { x=i;y=j; flag=1;}
		}
	}

}
void pc_move()
{
	randomize();
	int sathu;
	if(((u.s==0)||(u.s==2))&&((u.c==0)||(u.c==5))&&((u.d==0)||(u.d==3))&&((u.b==0)||(u.b==4)))
	{
		do
		{
			sathu=random(64);
		}while(user[1][0][sathu]!='\0');
		x=sathu/8;
		y=sathu%8;
	}
		else
	{
		scan(x,y);
		if(x==0&&y==0)
		{
			if(user[1][1][0]=='\0'&&user[1][0][1]=='\0')
			{
				if(random(2)){ x=1;y=0;}
				else {x=0;y=1;}
			}
			else if(user[1][1][0]=='\0'&&user[1][0][1]!=user[1][0][0])
			{
				x+=1;
			}
			else if(user[1][0][1]=='\0'&&user[1][1][0]!=user[1][0][0])
			{
				y+=1;
			}
			else if(user[1][1][0]==user[1][0][0])
			{
				do
				{
					x+=1;
				}while(user[1][x][y]==user[1][0][0]);
			}
			else if(user[1][0][1]==user[1][0][0])
			{
				do
				{
					y+=1;
				}while(user[1][x][y]==user[1][0][0]);
			}
		}
		else if(x==7 && y==0)
		{
			if(user[1][6][0]=='\0'&&user[1][7][1]=='\0')
			{
				if(random(2)){ x=6;y=0;}
				else {x=7;y=1;}
			}
			else if(user[1][6][0]=='\0'&&user[1][7][1]!=user[1][7][0])
			{
				x-=1;
			}
			else if(user[1][7][1]=='\0'&&user[1][6][0]!=user[1][7][0])
			{
				y+=1;
			}
			else if(user[1][6][0]==user[1][7][0])
			{
				do
				{
					x-=1;
				}while(user[1][x][y]==user[1][7][0]);
			}
			else if(user[1][7][1]==user[1][7][0])
			{
				do
				{
					y+=1;
				}while(user[1][x][y]==user[1][7][0]);
			}
		}
		else if(x==0&&y==7)
		{
			if(user[1][1][7]=='\0'&&user[1][0][6]=='\0')
			{
				if(random(2)){ x=1;y=7;}
				else {x=0;y=6;}
			}
			else if(user[1][1][7]=='\0'&&user[1][0][6]!=user[1][0][7])
			{
				x+=1;
			}
			else if(user[1][0][6]=='\0'&&user[1][1][7]!=user[1][0][7])
			{
				y-=1;
			}
			else if(user[1][1][7]==user[1][0][7])
			{
				do
				{
					x+=1;
				}while(user[1][x][y]==user[1][0][7]);
			}
			else if(user[1][0][6]==user[1][0][7])
			{
				do
				{
					y-=1;
				}while(user[1][x][y]==user[1][0][7]);
			}
		}
		else if(x==7&&y==7)
		{
			if(user[1][6][7]=='\0'&&user[1][7][6]=='\0')
			{
				if(random(2)){ x=6;y=7;}
				else {x=7;y=6;}
			}
			else if(user[1][6][7]=='\0'&&user[1][7][6]!=user[1][7][7])
			{
				x-=1;
			}
			else if(user[1][7][6]=='\0'&&user[1][6][7]!=user[1][7][7])
			{
				y-=1;
			}
			else if(user[1][6][7]==user[1][7][7])
			{
				do
				{
					x-=1;
				}while(user[1][x][y]==user[1][7][7]);
			}
			else if(user[1][7][6]==user[1][7][7])
			{
				do
				{
					y-=1;
				}while(user[1][x][y]==user[1][7][7]);
			}
		}
		else if(x==0)
		{
			if(user[1][x+1][y]=='\0'&& user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0')
			{
				sathu=random(3);
				if(sathu==2) { x+=1;}
				else if(sathu==1){ y+=1;}
				else y-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) {x+=1;}
				else y+=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x][y+1]!=user[1][x][y])
			{
				if(random(2)) x+=1;
				else y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x+1][y]!=user[1][x][y])
			{
				if(random(2)) y+=1;
				else y-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				x+=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x+1][y]!=user[1][x][y])
			{
				y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				y+=1;
			}
			else if(user[1][x+1][y]==user[1][x][y])
			{
				do
				{
					x+=1;
				}while(user[1][x][y]==user[1][x-1][y]);
			}
			else if(user[1][x][y-1]!=user[1][x][y]&&user[1][x][y+1]==user[1][x][y])
			{
				if(user[1][x][y-1]=='\0') {rememberx=x;remembery=y-1;}
				do
				{
					y+=1;
				}while(user[1][x][y]==user[1][x][y-1]&&y<7);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}
			}
			else if(user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]==user[1][x][y])
			{
				if(user[1][x][y+1]=='\0') {rememberx=x;remembery=y+1;}
				do
				{
					y-=1;
				}while(user[1][x][y]==user[1][x][y+1]&&y>0);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}

			}
		}
		else if(x==7)
		{
			if(user[1][x-1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0')
			{
				sathu=random(3);
				if(sathu==2) { x-=1;}
				else if(sathu==1){ y+=1;}
				else y-=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) {x-=1;}
				else y+=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x][y+1]!=user[1][x][y])
			{
				if(random(2)) x-=1;
				else y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x-1][y]!=user[1][x][y])
			{
				if(random(2)) y+=1;
				else y-=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				x-=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x-1][y]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				y+=1;
			}
			else if(user[1][x-1][y]==user[1][x][y])
			{
				do
				{
					x-=1;
				}while(user[1][x][y]==user[1][x+1][y]);
			}
			else if(user[1][x][y-1]!=user[1][x][y]&&user[1][x][y+1]==user[1][x][y])
			{
				if(user[1][x][y-1]=='\0') {rememberx=x;remembery=y-1;}
				do
				{
					y+=1;
				}while(user[1][x][y]==user[1][x][y-1]&&y<7);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}
			}
			else if(user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]==user[1][x][y])
			{
				if(user[1][x][y+1]=='\0') {rememberx=x;remembery=y+1;}
				do
				{
					y-=1;
				}while(user[1][x][y]==user[1][x][y+1]&&y>0);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}

			}
		}
		else if(y==0)
		{
			if(user[1][x][y+1]=='\0'&&user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0')
			{
				sathu=random(3);
				if(sathu==2) { y+=1;}
				else if(sathu==1){ x+=1;}
				else x-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x+1][y]=='\0'&&user[1][x-1][y]!=user[1][x][y])
			{
				if(random(2)) {y+=1;}
				else x+=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x+1][y]!=user[1][x][y])
			{
				if(random(2)) y+=1;
				else x-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y+1]!=user[1][x][y])
			{
				if(random(2)) x+=1;
				else x-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				y+=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x][y+1]!=user[1][x][y])
			{
				x-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				x+=1;
			}
			else if(user[1][x][y+1]==user[1][x][y])
			{
				do
				{
					y+=1;
				}while(user[1][x][y]==user[1][x][y-1]);
			}
			else if(user[1][x-1][y]!=user[1][x][y]&&user[1][x+1][y]==user[1][x][y])
			{
				if(user[1][x-1][y]=='\0') {rememberx=x-1;remembery=y;}
				do
				{
					x+=1;
				}while(user[1][x][y]==user[1][x-1][y]&&x<7);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}
			}
			else if(user[1][x+1][y]!=user[1][x][y]&&user[1][x-1][y]==user[1][x][y])
			{
				if(user[1][x+1][y]=='\0') {rememberx=x+1;remembery=y;}
				do
				{
					x-=1;
				}while(user[1][x][y]==user[1][x+1][y]&&x>0);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}

			}
		}
		else if(y==7)
		{
			if(user[1][x][y-1]=='\0'&&user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0')
			{
				sathu=random(3);
				if(sathu==2) { y-=1;}
				else if(sathu==1){ x+=1;}
				else x-=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x+1][y]=='\0'&&user[1][x-1][y]!=user[1][x][y])
			{
				if(random(2)) {y-=1;}
				else x+=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x+1][y]!=user[1][x][y])
			{
				if(random(2)) y-=1;
				else x-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) x+=1;
				else x-=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				y-=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				x-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y-1]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				x+=1;
			}
			else if(user[1][x][y-1]==user[1][x][y])
			{
				do
				{
					y-=1;
				}while(user[1][x][y]==user[1][x+1][y]);
			}
			else if(user[1][x-1][y]!=user[1][x][y]&&user[1][x+1][y]==user[1][x][y])
			{
				if(user[1][x-1][y]=='\0') {rememberx=x-1;remembery=y;}
				do
				{
					x+=1;
				}while(user[1][x][y]==user[1][x-1][y]&&x<7);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}
			}
			else if(user[1][x+1][y]!=user[1][x][y]&&user[1][x-1][y]==user[1][x][y])
			{
				if(user[1][x+1][y]=='\0') {rememberx=x+1;remembery=y;}
				do
				{
					x-=1;
				}while(user[1][x][y]==user[1][x+1][y]&&x>0);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}

			}
		}
		else
		{
			if(user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0')
			{
				sathu=random(4);
				if(sathu==3) x+=1;
				else if(sathu==2) x-=1;
				else if(sathu==1) y+=1;
				else y-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]!=user[1][x][y])
			{
				sathu=random(3);
				if(sathu==2) x+=1;
				else if(sathu==1) x-=1;
				else y+=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x][y+1]!=user[1][x][y])
			{
				sathu=random(3);
				if(sathu==2) x+=1;
				else if(sathu==1) x-=1;
				else y-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x-1][y]!=user[1][x][y])
			{
				sathu=random(3);
				if(sathu==2) x+=1;
				else if(sathu==1) y+=1;
				else y-=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x+1][y]!=user[1][x][y])
			{
				sathu=random(3);
				if(sathu==2) x-=1;
				else if(sathu==1) y+=1;
				else y-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) x+=1;
				else x-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y+1]=='\0'&&user[1][x-1][y]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) x+=1;
				else y+=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				if(random(2)) x+=1;
				else y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) y+=1;
				else x-=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x-1][y]=='\0'&&user[1][x][y+1]!=user[1][x][y]&&user[1][x+1][y]!=user[1][x][y])
			{
				if(random(2)) x-=1;
				else y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x][y-1]=='\0'&&user[1][x+1][y]!=user[1][x-1][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				if(random(2)) y+=1;
				else y-=1;
			}
			else if(user[1][x+1][y]=='\0'&&user[1][x-1][y]!=user[1][x][y]&&user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				x+=1;
			}
			else if(user[1][x-1][y]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				x-=1;
			}
			else if(user[1][x][y-1]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x][y+1]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y])
			{
				y-=1;
			}
			else if(user[1][x][y+1]=='\0'&&user[1][x+1][y]!=user[1][x][y]&&user[1][x-1][y]!=user[1][x][y]&&user[1][x][y-1]!=user[1][x][y])
			{
				y+=1;
			}
			else if(user[1][x][y-1]!=user[1][x][y]&&user[1][x][y+1]==user[1][x][y])
			{
				if(user[1][x][y-1]=='\0') {rememberx=x;remembery=y-1;}
				do
				{
					y+=1;
				}while(user[1][x][y]==user[1][x][y-1]&&y<7);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}
			}
			else if(user[1][x][y+1]!=user[1][x][y]&&user[1][x][y-1]==user[1][x][y])
			{
				if(user[1][x][y+1]=='\0') {rememberx=x;remembery=y+1;}
				do
				{
					y-=1;
				}while(user[1][x][y]==user[1][x][y+1]&&y>0);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}

			}

			else if(user[1][x-1][y]!=user[1][x][y]&&user[1][x+1][y]==user[1][x][y])
			{
				if(user[1][x-1][y]=='\0') {rememberx=x-1;remembery=y;}
				do
				{
					x+=1;
				}while(user[1][x][y]==user[1][x-1][y]&&x<7);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}
			}
			else if(user[1][x+1][y]!=user[1][x][y]&&user[1][x-1][y]==user[1][x][y])
			{
				if(user[1][x+1][y]=='\0') {rememberx=x+1;remembery=y;}
				do
				{
					x-=1;
				}while(user[1][x][y]==user[1][x+1][y]&&x>0);
				if(user[1][x][y]!='\0') { x=rememberx;y=remembery;}

			}
		}
	}
	bar(10,340,470,380);//fill coordinates in later
	user[1][x][y]=user[0][x][y];
	if(user[0][x][y]=='s') outtextxy(100,350,"SCAVENGER HIT");
	else if(user[0][x][y]=='d')outtextxy(100,350,"DESTROYER HIT");
	else if(user[0][x][y]=='b')outtextxy(100,350,"BATTLESHIP HIT");
	else if(user[0][x][y]=='c')outtextxy(100,350,"CARRIER HIT");
	else outtextxy(100,350,"SHOT MISSED");
	switch(user[0][x][y])
	{
		case 's': u.s--; break;
		case 'd': u.d--; break;
		case 'b': u.b--; break;
		case 'c': u.c--;break;
		default: break;
	}
	getch();
	user_disp();
	bar(10,340,470,380);
	if(user[0][x][y]=='s'&&u.s==0) outtextxy(100,350,"SCAVENGER SUNK");
	else if(user[0][x][y]=='d'&&u.d==0) outtextxy(100,350,"DESTROYER SUNK");
	else if(user[0][x][y]=='c'&&u.c==0) outtextxy(100,350,"CARRIER SUNK");
	else if(user[0][x][y]=='b'&&u.b==0) outtextxy(100,350,"BATTLESHIP SUNK");
	getch();

}
void gameplay()
{
	do
	{
		user_move();
		if(p.s+p.c+p.d+p.b>0) pc_move();
	}while((u.s+u.c+u.b+u.d)>0&&(p.s+p.c+p.d+p.b)>0);
	getch();
	int result;
	bar(10,340,470,380);
	setcolor(CYAN);
	if((u.s+u.c+u.b+u.d)>0){ outtextxy(100,350,"YOU WIN!"); result=0;}
	else{ outtextxy(100,350,"YOU LOSE!"); result=1;}
	fstream f;
	f.open("pc_form.DAT",ios::out|ios::in|ios::binary);
	f.seekg(maxpos*sizeof(ob),ios::beg);
	f.read((char*)&ob,sizeof(ob));
	if(result)
	{
		ob.win();
		f.seekp(maxpos*sizeof(ob),ios::beg);
		f.write((char*)&ob,sizeof(ob));
	}
	else
	{
		ob.lose();
		f.seekp(maxpos*sizeof(ob),ios::beg);
		f.write((char*)&ob,sizeof(ob));
		f.close();
		f.open("pc_form.DAT",ios::app|ios::binary);
		form ani;
		strcpy(ani.name,username);
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				ani.a[i][j]=user[0][i][j];
			}
		}
		f.write((char*)&ani,sizeof(ani));
	}
	f.close();
	getch();
	bar(10,340,470,380);
}
void main()
{
	u.s=p.s=2;
	u.d=p.d=3;
	u.b=p.b=4;
	u.c=p.c=5;
	part1();
	gameplay();
	pc_disp();
	getch();
	cleardevice();
	closegraph();
}
