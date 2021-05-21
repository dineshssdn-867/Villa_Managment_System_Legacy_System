#include<stdio.h>
#include"MarkettingManagement.h"
#include"SalesManagement.h"
#include"StaffManagement.h"
int main()
{
	int option;
	printf("1.Staff Management\n2.Sales Management\n3.Marketing management\n\n\nEnter your choice: ");
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
