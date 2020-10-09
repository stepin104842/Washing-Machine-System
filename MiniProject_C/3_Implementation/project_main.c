//#include "stdafx.h"
//#include<iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
void stateOnOff();
void mainmenu();
void Washcolthes();
void WashMenu();
void soak();
void getTimesoak();
void Temperature();
void viewlog();
void viewlogb();
void readviewlogb();
char result[4];
int main(void);
int times,count;
char ch;
FILE *fp;
int j=0,i=0;
int _tmain(int argc,char * argv[])
{
	stateOnOff();
	return 0;
} 
int main(void)
{
	time_t timer= time(NULL);
	printf("current time is %s",ctime(&timer));
	stateOnOff();

}
void stateOnOff()
{

	printf("\n**********");
	printf("\n*  ((welcome dear user))  *");
	printf("\n**********");
	printf("\nPress (o) to washing machine start?");
	ch=_getch();
	printf("\n%c",ch);
	if(ch=='o')
	{
		printf("\nWashing machine is On");
		mainmenu();
	}
	else
		printf("\n Washing machine is Off, run the machine again");
	stateOnOff();
}
void mainmenu()
{
	system("cls");

	printf("\n*************");
	printf("\n*    ((Main Menu))              *");
	printf("\n*************");
	printf("\nIf you want to wash clothes, please type w:");
	printf("\nIf you want to see view log, please type v:");
	ch=_getch();
	printf("\n%c",ch);
	do
	{
		if(ch=='w')
			Washcolthes();
		else if(ch=='v')
			readviewlogb();
		printf("\nInvalid answer, type correctly:");
		ch=_getch();
		printf("\n%c",ch);
	}while(ch!='w' && ch!='v');
}
void readviewlogb()
{
	FILE *fp;
	int c;
	fp=fopen("New Text Document.doc","r");
	c=getc(fp);
	while(c!=EOF)
	{
		putchar(c);
		c=getc(fp);
	}
	fclose(fp);
	printf("\n Press any key to continue...");
	getch();
	system("cls");
	mainmenu();
}
void Washcolthes()
{
	system("cls");

	printf("\n***********");
	printf("\n*    (Size Menu))        *");
	printf("\n***********");
	printf("\nPlease select size of clothes:");
	printf("\nEnter s(small) if your cloths b/w 1-2kgs:");
	printf("\nEnter m(medium) if your cloths b/w 2-3kgs:");
	printf("\nEnter l(large) if your cloths b/w 3-4kgs:");
	printf("\nEnter x(Extra large) if your cloths more than 4kgs:");
	printf("\nEnter f(free load) if machine determines the load capacity:");
	ch=_getch();
	printf("\n%c",ch);
	while(ch!='s' && ch!='m' && ch!='l' && ch!='x' &&ch!='f'){
	printf("\nInvalid answer,type correctly:");
	ch=_getch();
	printf("\n%c",ch);
	}
	result[count]=ch;
	count++;
	WashMenu();
}
void WashMenu()
{
	system("cls");

	printf("\n***********");
	printf("\n*      ((Wash menu))         *");
	printf("\n***********");
	printf("\nPlease select one of the wash menu options for your clothes");
	printf("\nEnter f(full wash) consists of washing,rinsing and spining");
	printf("\nEnter w(wash) consist of only washing");
	printf("\nEnter r(rinse) consist of only rinsing");
	printf("\nEnter s(spin) consist of only spinning");
	ch=_getch();
	printf("\n%c",ch);
	while(ch!='f' && ch!='w' && ch!='r' && ch!='s'){
	printf("\nInvalid answer, type correctly");
	ch=_getch();
	printf("\n%c",ch);
	}
	result[count]=ch;
	count++;
	if(ch=='f' || ch=='w')
	{
		soak();
	}
	else{
		Temperature();
	}
}
void soak()
{
	system("cls");

	printf("\n************");
	printf("\n*    ((soak menu))          *");
	printf("\n************");
	printf("\nIf you want soak please press (y):");
	ch=_getch();
	printf("\n%c",ch);
	while(ch!='y'&& ch!='n'){
	printf("\nInvalid answer,type correctly:");
	ch=_getch();
	printf("\n%c",ch);
	}
	if(ch=='y'){
	result[count]=ch;
	count++;
	getTimesoak();
	}
	Temperature();
}
void getTimesoak()
{
	system("cls");

	printf("\n**********");
	printf("\n*     ((Soak time)         *");
	printf("\n***********");
	printf("\nPlease enter time b/w 1-60minutes");
	scanf("%d",&ch);
	if(ch>60){
	printf("\n************");
	printf("\n*     (warning)                *");
	printf("\n************");
	printf("\nThis time is more than 60 min, enter time less than 60 min");
	scanf("%d",&ch);
	}
	times=ch;
}
void Temperature()
{
	system("cls");

	printf("\n**********");
	printf("\n    (Temperture menu)       *");
	printf("\n************");
	printf("\n Enter h(hot) if you want hot water for operation");
	printf("\n Enter c(cold) if you want cold water for operation");
	ch=_getch();
	printf("\n%c",ch);
	while(ch!='h' && ch!='c'){
	printf("\nInvalid answer, type correctly");
	ch=_getch();
	printf("\n%c",ch);
	}
	result[count]=ch;
	viewlog();
}
void viewlog()
{
	system("cls");
	printf("\n******((The machine start to work))***:");
	printf("\n");

	if(result[j]=='s'){
	printf("\nSmall");
	}else
		if(result[j]=='m'){
	printf("\nMedium");
	}else
		if(result[j]=='l'){
	printf("\nLarge");
	}else
	if(result[j]=='x'){
	printf("\nExtra large");
	}else
		if(result[j]=='f'){
	printf("\nFreeload");
	}

	j++;
	if(result[j]=='f'){
	printf("\nfullwash");
	}else
		if(result[j]=='w'){
	printf("\nwash");
	}else
		if(result[j]=='r'){
	printf("\nrinse");
	}else
	if(result[j]=='s'){
	printf("\nspin");
	}

	j++;
	if(result[j]=='y')
	{
		printf(",soak is active");
		printf("\nTime for washing your clothes :60 min and for soaking:");
		printf("%d",times);
		printf("\nTotal:");
		times+=60;
		printf("%d",times);
		printf("min");
	}
	else{
		printf("\nSoak is not active");
		printf("\nTime for washing clothes is :60 min");
	}

	j++;
	if(result[j]=='h'){
	printf("\nTemperature water is hot");
	}else if(result[j]=='c')
	{ printf("\nTemperature water is cold");}
	system("pause");
	viewlogb();
}
void viewlogb()
{
	system("cls");
	time_t timer=time(NULL);
	fp=fopen("New Text Document.doc","a");

	fprintf(fp,"current time is %s",ctime(&timer));

	if(result[i]=='s'){
	fprintf(fp,"%s","Small\n");
	}else
		if(result[i]=='m'){
	fprintf(fp,"%s","Medium\n");
	}else
		if(result[i]=='l'){
	fprintf(fp,"%s","Large\n");
	}else
	if(result[i]=='x'){
	fprintf(fp,"%s","Extra large\n");
	}else
		if(result[i]=='f'){
		fprintf(fp,"%s","Freeload\n");
		}
	i++;
	if(result[i]=='f'){
		fprintf(fp,"%s","fullwash\n");
	}else
		if(result[i]=='w'){
		fprintf(fp,"%s","wash\n");
	}else
		if(result[i]=='r'){
		fprintf(fp,"%s","rinse\n");
	}else
		if(result[i]=='s'){
		fprintf(fp,"%s","spin\n");
	}

	i++;
	if(result[i]=='y'){
	fprintf(fp,"%s","soak is active\n");
	fprintf(fp,"%s","Time for washing your clothes :60 min and for soaking\n");
	fprintf(fp,"%d",times);
	fprintf(fp,"%s","Total\n");
	times+=60;
	fprintf(fp,"%d",times);
	fprintf(fp,"%s","min");
	}
	else{
		fprintf(fp,"%s","soak is not active\n");
		fprintf(fp,"%s","Time for washing your clothes is :60min:\n");
	}

	i++;
	if(result[i]=='h'){
		fprintf(fp,"%s","Temperature water is hot\n");
	} else if(result[i]=='c')
		fprintf(fp,"%s","Temperature water is cold\n");
	fclose(fp);
	stateOnOff();
}
