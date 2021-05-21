#include<stdio.h>
#include"MarkettingManagement.h"
#include"SalesManagement.h"
#include"StaffManagement.h"
//#include"StaffManagementFinal.h"
void rectangleManager(){
	int i=0;
	printf("%c",201);
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
    for(i = 1; i < 180; i++){
        setxy(i,6);
		printf("%c",177);
    }
    for(i = 7; i < 41; i++){
        setxy(80,i);
        printf("%c",177);
    }
}
int mainManager()
{
	system("cls");
	system("color B");
	rectangleManager();
	int option;
	setxy(79,3);
	printf("MANAGING LIST");
	setxy(5,9);
	printf("1.Staff Management");
	setxy(5,10);
	printf("2.Sales Management");
	setxy(5,11);
	printf("3.Marketing management");
	setxy(5,14);
	printf("Enter your choice: ");
	scanf("%d",&option);
	if(option==1)
	{
		mainStaff();
	}
	else if(option==2)
	{
		mainSales();
	}
	else if(option==3)
	{
		mainMarketting();
	}
	
	return 0;
}
