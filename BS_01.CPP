#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
class	form//formations that can be used by pc
{
	public: char	name[50];
		char	a[8][8];//x=no ship,s= ship of size 2, d=ship of size 3, b=ship of size 4, c=sjip of size 5
	private:long	count;//counter
	public: form()
		{
			count=0;
		}
		void input();
		void print();
		void win(){ count++;}
		void lose(){ count-=2;}
		int return_count(){ return count;}
}ob;
void form::input()
{
     cout<<"\nEnter name of formation:";
     gets(name);
     cout<<"\nEnter formation:\n";
     for(int i=0;i<8;i++)
     {
	for(int j=0;j<8;j++)
	{
		cin>>a[i][j];
	}
     }
     count=0;
     cout<<endl;
}
void form::print()
{
	cout<<endl<<name<<endl;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<count<<endl;
}
void store()
{
	char 	opt;
	ofstream f;
		f.open("pc_form.dat",ios::app||ios::binary);
		do
		{
			ob.input();
			f.write((char*)&ob,sizeof(ob));
			cin>>opt;
		}while(opt=='y'||opt=='Y');
	f.close();
}
void display()
{
	ifstream f;
		f.open("pc_form.dat",ios::binary);
		while(f.read((char*)&ob,sizeof(ob)))
		{
			ob.print();
			getch();
		}
		f.close();
}
/*void main()
{
	clrscr();
	//store();
	display();
	getch();
}*/

