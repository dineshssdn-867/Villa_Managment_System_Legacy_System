#include <stdio.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct staff{
	char id[15];
    char name[20];
    char add[20];
    char department[10];
    long unsigned int aadhar_no,phone_no;
    long long int salary;
};

struct staff dj;
COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void setxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void rectangle(){
	int i=0;
	printf("%c",201);
    for(i = 1; i < 180; i++){
        setxy(i, 0);
        printf("%c",205);
    }
    setxy(179,0);
    printf("%c",187);
    i=0;
    for(i = 1; i < 42 ; i++){
        setxy(0, i);
        printf("%c",186);
    }
    setxy(0,41);
    printf("%c",200);
    for(i = 1; i < 180; i++){
        setxy(i, 41);
        printf("%c",205);
    }
    setxy(179,41);
    printf("%c",188);
    for(i = 40; i>0 ; i--){
        setxy(179, i);
        printf("%c",186);
    }
    for(i = 1; i < 178; i++){
        setxy(i,6);
		printf("%c",205);
    }
    for(i = 7; i < 41; i++){
        setxy(80,i);
        printf("%c",186);
    }
}
    void clearWindow(){
    int i,j;
    for(i = 84; i < 135; i++){
        for(j = 7; j < 40; j++){
            setxy(i,j);printf(" ");
        	}
    	}
    	for(i = 10 ; i < 40; i++){
            setxy(i,26);printf(" ");
        	}
    }
	
	void window(){
	rectangle();
    setxy(89,2);
    //SetColor(35);
    printf("HOTEL FCP");
    //SetColor(17);
	}
	void print_heading(const char st[]){
    //SetColorAndBackground(31,28);
    setxy(87,8);
	printf("SRS : %s",st);
    //SetColorAndBackground(17,15);
	}
	
	void add_employee(){
    clearWindow();
    print_heading("Add Record");
    int print = 87;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        setxy(print,10);printf("ID: ");gets(dj.id);
        //here you can confirms the ID
        setxy(print,14);printf("Name: ");gets(dj.name);
        setxy(print,16);printf("Address: ");gets(dj.add);
        setxy(print,18);printf("Deparment : ");gets(dj.department);
        setxy(print,20);printf("Adhar_no: ");scanf("%d",&dj.aadhar_no);
        setxy(print,22);printf("Phone Number: ");scanf("%ld",&dj.phone_no);
        setxy(print,24);printf("Salary: ");scanf("%ld",&dj.salary);
        fwrite(&dj, sizeof(dj), 1, fp);
        setxy(10,26); printf("The record is sucessfully added");
    }
    fclose(fp);
	}
	
	void search_employee()
	{
    clearWindow();
    print_heading("Search Record");
    char e_id[15];
    int isFound = 0;
    setxy(87,10);printf("Enter ID to Search: ");fflush(stdin);
    gets(e_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&dj,sizeof(dj),1,fp) == 1){
        if(strcmp(e_id,dj.id) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
		{
        setxy(87,12);printf("The record is Found");
        setxy(87,14);printf("ID: %s",dj.id);
        setxy(87,15);printf("Name: %s",dj.name);
        setxy(87,16);printf("Address: %s",dj.add);
        setxy(87,17);printf("Department: %s",dj.department);
        setxy(87,18);printf("Adhar_Number: %d",dj.aadhar_no);
        setxy(87,19);printf("Phone No: %ld",dj.phone_no);
        setxy(87,20);printf("Salary: %ld",dj.salary);
    	}
	else{
        setxy(87,12);printf("Sorry, No record found in the database");
    	}
    fclose(fp);
	}

void mod_employee(){
    clearWindow();
    print_heading("Modify Record");
    //SetColor(45);
    char e_id[15];
    int isFound = 0, print = 87;
    setxy(87,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(e_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&dj, sizeof(dj),1,fp) == 1){
        if(strcmp(e_id, dj.id) == 0){
            fflush(stdin);
            setxy(print,12);printf("ID: ");gets(dj.id);
            setxy(print,13);printf("Name: ");gets(dj.name);
            setxy(print,14);printf("Address: ");gets(dj.add);
            setxy(print,15);printf("Deparment: ");gets(dj.department);
            setxy(print,16);printf("Adhar_Number: ");scanf("%d",&dj.aadhar_no);
            setxy(print,17);printf("Phone Number: ");scanf("%ld",&dj.phone_no);
            setxy(print,18);printf("Salary: ");scanf("%ld",&dj.salary);
			fseek(fp,-sizeof(dj), SEEK_CUR);
            fwrite(&dj,sizeof(dj), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        setxy(print, 12);printf("No Record Found");
    }
    fclose(fp);
}

void delete_employee(){
    clearWindow();
    print_heading("Delete Record");
    //SetColor(45);
    int isFound = 0, print = 37;
    char e_id[15];
    setxy(87,10);printf("Enter ID to Delete: ");fflush(stdin);
    gets(e_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&dj, sizeof(dj),1,fp) == 1){
        if(strcmp(e_id, dj.id) == 0){
            fwrite(&dj,sizeof(dj),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    setxy(87,12);printf("The record is sucessfully deleted");
}

void main_window(){
    int choice;
    //SetColor(28);
    int x = 2;
    while(1){
        setxy(x,8);printf("1. Add Employee");
        setxy(x,10);printf("2. Search Employee");
        setxy(x,12);printf("3. Modify Employee Record");
        setxy(x,14);printf("4. Delete Employee Record");
        setxy(x,16);printf("5. Exit");
        setxy(x,18);printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_employee();
                break;
            case 2:
                search_employee();
                break;
            case 3:
                mod_employee();
                break;
            case 4:
                delete_employee();
				break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }

    }

}
	
	
	
	
	
	int main()
	{
	SMALL_RECT rect;
    COORD coord;
    coord.X = 200; // Defining our X and
    coord.Y = 50;  // Y size for buffer.

    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = coord.Y-1; // height for window
    rect.Right = coord.X-1;  // width for window

    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
    SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size
    SetConsoleWindowInfo(hwnd, TRUE, &rect);// set window size
	window();
	main_window();
	getch();
	return 0;
	}
