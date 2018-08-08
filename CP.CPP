/* A program which Learns about Intensity of Crime From files with Object of type Factor
   and alters itself to be Free from Errorness
   Intensity of Crime R > Y >G 
*/
#include<iostream.h>
#include<conio.h>
#include<fstream.h>

float F1=1,F2=1,F3=1,F4=1,F5=25,F6=1,Trans=0.1,FT=0.3;
double Check=480500;

class Factor
{
public:
unsigned int PD;
unsigned int YD;
unsigned int EC;
float PP;
unsigned int SD;
double CT;
char zone;
};




void FTrans(int n,Factor o)
{
if(o.PP>0.4)
{
	F1=F1+(n*Trans);
	F2=F3=F4=F6=F1;
	F5=F5+(n*FT);
}
else
{
	F1=F1+(n*Trans);
	F5=F5+(n*FT);
	F2=F3=F6=F1;
}
}





void TransCheck(char C,Factor o)
{
if(C==o.zone)
 return;

if(C=='Y')
{
	if(o.zone=='R')
		FTrans(1,o);
	else
	if(o.zone=='G')
		FTrans(-1,o);
}
else
if(C=='R')
{
	if(o.zone=='Y')
		FTrans(-1,o);
	else
	if(o.zone=='G')
		FTrans(-2,o);
}
else
{
	if(o.zone=='Y')
		FTrans(1,o);
	else
	if(o.zone=='R')
		FTrans(2,o);
}

}





char Predict(Factor o)
{
double i;
char ch;
if(o.PD > 5000)
{
	if(o.PP>0.4)
		i=(F1*o.PD)+(F2*o.YD)+(F3*o.EC)+(F4*o.PD*o.PP)-(F5*o.SD)+(F6*o.CT);
	else
		i=(F1*o.PD)+(F2*o.YD)+(F4*o.PD*o.PP)-(F5*o.SD)+(F6*o.CT);
}
else
{
	if(o.PP>0.4)
		i=(F2*o.YD)-(F1*o.PD)+(F3*o.EC)+(F4*o.PD*o.PP)-(F5*o.SD)+(F6*o.CT);
	else
		i=(F2*o.YD)-(F1*o.PD)+(F4*o.PD*o.PP)-(F5*o.SD)+(F6*o.CT);
}

if(i>(0.7*Check))
	ch='R';
else
if(i>(0.4*Check))
	ch='Y';
else
	ch='G';

TransCheck(ch,o);
return(ch);

}


void Learn(char FN[])
{
ifstream fin(FN,ios::out);
Factor o;
while(!fin.eof())
{
 fin.read((char *)&o,sizeof(o));
 Predict(o);
}
cout<<"\n\nFinished Learning Using Provided Data ";
fin.close();
}





void Implement(Factor o)
{
char P=Predict(o);
cout<<"\n\n\nThe Prediction Is : "<<P;
cout<<"\n\nActual Senario Is : "<<o.zone;
if(P==o.zone)
 cout<<"\n\nHurrah! I Predicted it :)";
else
 cout<<"\n\nI Am Still Learning :)";
}


void main()
{
clrscr();
char FN[100],Y;
Factor o;


cout<<"Crime Predictor";

X:
cout<<"\n\n\nFeed Me : ";
cin>>FN;//The File Path Given Should be a Binary File of Objects of Class Factor

Learn(FN);//Here the Program Learns and alters the Equation

cout<<"\n\nWanna Feed Me More (Y/y or N/n) : ";
cin>>Y;
if(Y=='y' || Y=='Y')
 goto X;

cout<<"\n\nNow Check Me Out ";
Z:
cout<<"\n\nFill The Info And I will Predict it : ";

cout<<"\nPopulation Density : ";
cin>>o.PD;
cout<<"\nYouth Density (!>Population Density : ";
cin>>o.YD;
cout<<"\nValue of Things Present : ";
cin>>o.EC;
cout<<"\nPoverty Percentage (0 to 1) : ";
cin>>o.PP;
cout<<"\nSecurity Density : ";
cin>>o.SD;
cout<<"\nCash Transfer : ";
cin>>o.CT;
cout<<"\n\nFor Cross Check, What is the Actual Senario (R,Y,G): ";
cin>>o.zone;

Predict(o);

cout<<"\n\nDo you want to try again (Y or y) : ";
cin>>Y;

if(Y=='y'||Y=='Y')
 goto Z;

cout<<"\n\n\nThank You ";
getch();
}