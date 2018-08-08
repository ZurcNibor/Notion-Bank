#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

int x1,x2,x3,y2,y3,i=0,score=0;
float t=150;
char value[20],ch;

void title()
{
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(int i=0;i<10;i++)
	{
	cleardevice();
	setfillstyle(SOLID_FILL,RED);
	bar(50,150,600,230);
	rectangle(50,150,600,230);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(80,160,"    Dashing Trucks");
	delay(100);
	cleardevice();
	setfillstyle(SOLID_FILL,BLUE);
	bar(50,150,600,230);
	rectangle(50,150,600,230);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(80,160,"    Dashing Trucks");
	delay(100);
	cleardevice();
	setfillstyle(SOLID_FILL,CYAN);
	bar(50,150,600,230);
	rectangle(50,150,600,230);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(80,160,"    Dashing Trucks");
	delay(100);
	cleardevice();
	setfillstyle(SOLID_FILL,MAGENTA);
	bar(50,150,600,230);
	rectangle(50,150,600,230);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(80,160,"    Dashing Trucks");
	delay(100);
	}
}




void ScoreSave()
{
	ofstream fin("Score_Truck.dat",ios::app);
	cout<<"\n===============================================================================\n\n";
	cout<<"\t\t\tScoreboard\n\t\t\t------------\n\tEnter name (Max 20 characters): ";
	char name[20],ch1;
	fin<<"\n"<<gets(name)<<"       "<<score;
	fin.close();
	clrscr();
	cout<<"\n\t\t\t  Summary\n\t\t\t-----------\n\nName: "<<name<<"\nScore: "<<score;
	cout<<"\n\n\nPress any key to exit.........";
	getch();
}


void ene()
{
	X:randomize();
	int a=210+(rand()%190);
	x2=a;
	y2=0;
}

void ene1()
{
	randomize();
	int a=210+random(190);
	x3=a;
	y3=-70;
	randomize();

}

void ene12()
{
	ene1();
	ene();
}

void move()
{
	y3+=10;
	y2+=10;
}
int Control()
{
	if(!kbhit())
	{       delay(50);
		return 0;
	}
	else
	{
		switch(getch())
		{
			case'd':case'D':x1+=10;break;
			case'a':case'A':x1-=10;break;
			case 27:getch();closegraph();exit(0);break;
		}
	}
		return 0;
}



void BGround()
{
	/*		GRASS		*/
	setfillstyle(9,GREEN);
	bar3d(0,0,getmaxx()/3,getmaxy(),0,0);
	setfillstyle(9,GREEN);
	bar3d(2*getmaxx()/3,0,getmaxx(),getmaxy(),0,0);

	/*		ROAD		       */
	setfillstyle(SOLID_FILL,8);
	bar3d(getmaxx()/3,0,2*getmaxx()/3,getmaxy(),0,0);

}




void car()
{
	/*		Tyres		*/
	setfillstyle(1,BLACK);
	bar3d(x1+1,getmaxy()-38,x1+5,getmaxy()-32,0,0);
	setfillstyle(1,BLACK);
	bar3d(x1+25,getmaxy()-38,x1+29,getmaxy()-32,0,0);

	/*		Body		*/
	setfillstyle(1,YELLOW);
	bar3d(x1+5,getmaxy()-10,x1+25,getmaxy()-40,0,0);

	/*		Container	*/
	setfillstyle(4,BLUE);
	bar3d(x1,getmaxy()-30,x1+30,getmaxy(),0,0);


}




void car1()
{
	/*		Tyres		*/
	setfillstyle(1,BLACK);
	bar3d(x2+1,y2+2,x2+5,y2+7,0,0);
	setfillstyle(1,BLACK);
	bar3d(x2+25,y2+2,x2+29,y2+7,0,0);


	/*		Body		*/
	setfillstyle(1,RED);
	bar3d(x2+5,y2-10,x2+25,y2+10,0,0);

	/*		Container	*/
	int a=random(13)+1;
	setfillstyle(11,a);
	bar3d(x2,y2-40,x2+30,y2,0,0);

	if(y2>getmaxy())
		ene();
}

void car2()
{
	/*		Tyres		*/
	setfillstyle(1,BLACK);
	bar3d(x3+1,y3+2,x3+5,y3+7,0,0);
	setfillstyle(1,BLACK);
	bar3d(x3+25,y3+2,x3+29,y3+7,0,0);


	/*		Body		*/
	setfillstyle(1,GREEN);
	bar3d(x3+5,y3-10,x3+25,y3+10,0,0);

	/*		Container	*/
	randomize();
	int a=random(13)+1;
	setfillstyle(11,a);
	bar3d(x3,y3-40,x3+30,y3,0,0);

	if(y3>getmaxy())
		ene1();
}

void draw()
{
	BGround();

	outtextxy(465,100,"Press Esc to exit...");
	outtextxy(440,10,"Score: ");
	sprintf(value,"%d",score);
	outtextxy(500,10,value);

	car();
	car1();
	car2();

	setfillstyle(1,RED);
	bar3d(480,150,500,400,0,0);
	setfillstyle(1,WHITE);

	if(t>400)
	{
		cleardevice();
		closegraph();
		cout<<"\n\t\tTime Finished !\n\n\n Press Any key to Proceed.....";
		ScoreSave();
		getch();
		exit(0);
	}
	bar3d(480,t,500,400,0,0);


}

void out()
{

	int a1=x1-30,a2=x1+30;
	if((x1+7)<=(getmaxx()/3)||(x1)>=(2*(getmaxx()/3))-20)
	{
			getch();
			cleardevice();
			closegraph();
			cout<<"\nOh ! Ride only on roads !\nGame Over ! ;(\n\n\nPress any key to proceed....";
			getch();
			ScoreSave();
			exit(0);
		}
	if(y2>=(getmaxy()-35))
	{
		if(x2>a1 && x2<a2)
		{
			getch();
			cleardevice();
			closegraph();
			cout<<"\nOh ! You crashed on Truck 1 !\nGame Over ! ;(\n\n\nPress any key to proceed....";
			getch();
			ScoreSave();
			exit(0);
		}
	}
	if(y3>=(getmaxy()-35))
	{
		if(x3>a1 && x3<a2)
		{
			getch();
			cleardevice();
			closegraph();
			cout<<"\nOh ! You crashed on Truck 2!\nGame Over ! ;(\n\n\nPress any key to proceed....";
			getch();
			ScoreSave();
			exit(0);
		}
	}




}


void main()
{
	int gd= DETECT, gm, err,i;
	clrscr();
	cout<<"\n\n Initiating Graphics....";
	//delay(2000);

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	err = graphresult();
	if (err!= grOk)
	{
		cout<<"\n\t\t\t  Error\n\t\t\t==========";
		cout<<"\n Graphics error: "<<grapherrormsg(err);
		cout<<"\n\n Press any key to halt......";
		getch();
		exit(1);
	}
	cleardevice();
	title();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy((getmaxx()/2)-100,(getmaxy()/2)+50,"Press Any key");
	getch();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

	cleardevice();

	cout<<"\n Graphics Initiated...\n Graphic Result is "<<err;
	cout<<"\n Use A and D to control ! Have Fun :D\n\n Press any key to continue...";
	getch();

	cleardevice();
	x1=(getmaxx()/2)-10;
	ene12();
	for(i=0;ch!='x';i++)
	{
		draw();
		Control();
		move();
		out();
		score+=50;
		t+=(0.5);
	}
	closegraph();
}

