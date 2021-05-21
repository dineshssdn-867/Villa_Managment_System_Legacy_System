#include<stdio.h>
#include<conio.h>
#include <unistd.h>
#include<windows.h>
int main(){
	
	int choice;
	int food,cleanliness,ambience,service,problem;
	int avg;

  int i;
  FILE *fp;
  //	textcolor(1);
  COORD c = {0, 0};
void setxy (int x, int y)
{
 c.X = x; c.Y = y; // Set X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


  //over
  
  printf("\t\t\t\t\t");
  for(i=0;i<10;i++)
  {
     system("color B");
     printf("**");
  }
	a:
	
	printf("\n\t\t\t\t\t     MAIN MENU \n");
	printf("\t\t\t\t\t");
  for(i=0;i<10;i++)
  {
      system("color B");
      printf("**");
  }
  
	

	printf("\nEnter\n1. To give ratings\n2. Have any problem?\n");
	scanf("%d",&choice);
	if(choice==1)
	{	
		fp=fopen("CustomerSatisfaction.txt","a+");
		printf("You can give ratings from 1 to 5\nwhere 1 is: Very Bad and 5:Very Good\n");
		printf("Ambience:");
		fscanf(stdin," %d",&ambience);
		printf("Service:");
		fscanf(stdin," %d",&service);
		printf("Food:");
		fscanf(stdin," %d",&food);
		printf("Cleanliness:");
		fscanf(stdin," %d",&cleanliness);
		avg=(ambience+service+food+cleanliness)/4;
		
		fprintf(fp,"\n%d          %d          %d          %d",ambience,service,food,cleanliness);
		
		//printing moving output
		for(i=0; i<35; i++)
  		{
    		system("color B");
		    setxy(i, 15);
			printf(" THANKYOU FOR YOUR FEEDBACK  : )");
            setxy(i-3, 15); //For clearing previous position of arrow
    		

    Sleep(100); 
		}
				
				fclose(fp);
				fp=fopen("review_avg.txt","a");
				fprintf(fp,"%d\n",avg);
				fclose(fp);
	}
	else if(choice==2)
	{
		printf("Choose your problem:\nEnter:\n1.Room cleaning\n2.Electricty\n3.Water\n4.Wifi connection issue\n");
		scanf("%d",&problem);
		printf("\nThankyou for letting us know.\nWe will be solving your issue as soon as possible.\n");
	    sleep(3);
	    

		    
	    	for(i=0; i<35; i++)
  		{
  			system("color B1");
  			setxy(i, 18);
    	
			printf(" Your problem is being solved : )");
            setxy(i-1, 18); 
            Sleep(100);
	   }
	}
	else
	{
		printf("Please enter valid input");
		goto a;
	}
		getch();
		return 0;
}
