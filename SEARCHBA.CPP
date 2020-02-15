#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include"ACCEPTN.CPP"
char* lay()
{
	int	gd=9;
	int	gm=2;
		char	stp[20];
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		outtextxy(50,20,"ENTER RESTAURANT NAME:");
		cleardevice();
		rectangle(170,80,400,100);
		strcpy(stp,accept_1(175,85));
		 closegraph();
		return stp;
}
/*void main()
{
	char	st[20];
		strcpy(st,lay());
		clrscr();
		cout<<st;
		getch();
}*/

