#include"Manager.h"
#include"RestaurentFinal.h"
#include"CustomerSatisfaction.h"
#include"Tariff.h"
#include<stdio.h>
#include<windows.h>
void rectangle();
void heading(); //
void login();
void manager();
void tariff();
void rectMain();
void setxy(int x,int y);
int main()
{
	system("cls");
	system("color B");
    SMALL_RECT rect;
    COORD coord;
    coord.X = 200; // Defining our X and
    coord.Y = 50;  // Y size for buffer.

    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = coord.Y-1; // height for window1
    rect.Right = coord.X-1;  // width for window
	
	
	
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
    SetConsoleScreenBufferSize(h, coord);       // set buffer size
    SetConsoleWindowInfo(h, TRUE, &rect);// set window size
	heading();
	//main_window();
	rectMain();

	return 0;
}
void rectMain(){
	int i=0;
    for(i = 0; i < 180; i++){
        setxy(i, 0);
        printf("%c",177);
    }
    setxy(179,0);
    printf("%c",177);
    i=0;
    for(i = 1; i < 42 ; i++){
        setxy(0, i);
        printf("%c",177);
    }
    setxy(0,41);
    printf("%c",177);
    for(i = 1; i < 180; i++){
        setxy(i, 41);
        printf("%c",177);
    }
    setxy(179,41);
    printf("%c",177);
    for(i = 40; i>0 ; i--){
        setxy(179, i);
        printf("%c",177);
    }
    for(i = 1; i < 179; i++){
        setxy(i,6);
		printf("%c",177);
    }
    for(i = 7; i < 41; i++){
        setxy(80,i);
        printf("%c",177);
    }
    
}
/*COORD coord = {0,0}; 
void setxy(int x, int y)
{
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/
	void heading(){
	setxy(76,3);
	fflush(stdin);
    printf(" VILLA FCP ");
	rectMain();
	login();
   
	}

void login()
{
	int choice;
	setxy(2,8);
	printf("1. Manager");
	setxy(2,10);
	printf("2.  Restaurent");
	setxy(2,12);
	printf("3. Customer");
	setxy(2,14);
	printf("4. Tariff");
	setxy(2,18);
	printf("Enter loign type:");
	scanf("%d",&choice);
	system("color E");
	if(choice==1)
	{
		manager();
	
	}	
	else if(choice==2)
	{
		
		system("cls");
		mainRestaurent();
		
	}
	else if(choice==3)
	{
		mainCustomer();
	}
	else if(choice==4)
	{
		tariff();
	}
}

void manager()
{
	char p[10];
	int i,a;

	
	setxy(87,8);
	fflush(stdin);
	printf("password temperorily is 'manager123' ");
    setxy(87,9);
	printf("Password:");
	setxy(97,9);	
	for(i=0;i<10;i++)
	{
		p[i]=getch();
		printf("*");
	}
	a=strcmp(p,"manager123");

	if(a==1)
	{
		system("color A");
		
		setxy(87,13);
		printf("LOGIN SUCCESSFULL!");
		setxy(87,14);	
		sleep(1);
		mainManager();
	}
		else
	{
		system("color C");
		setxy(87,13);
		printf("INCORRECT PASSWORD!");
	}
	sleep(2000);
}
void tariff()
{
	char p[10];
	int i,a;
	setxy(87,8);
	fflush(stdin);
	printf("password temperorily is 'tariff1234' ");
	setxy(87,9);
	printf("Password:");
	setxy(97,9);	
	for(i=0;i<10;i++)
	{
		p[i]=getch();
		printf("*");
	}
	a=strcmp(p,"tariff1234");
	if(a==1)
	{
		system("color A");
		setxy(87,13);
		printf("LOGIN SUCCESSFULL");
		sleep(2);
		mainTariff();
		//call tariff part
	}
	else
	{
		system("color A");
		setxy(87,13);
		printf("INCORRECT PASSWORD!");
	}
		sleep(2000);
}
