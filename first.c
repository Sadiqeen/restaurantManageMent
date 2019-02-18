#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include <math.h>
//#include <dos.h>
#include <time.h>
//#include <ctype.h>
//#include <windows.h>
//#include <stdlib.h>
#include "customer.h"
//#include "full.h"

//===============================Function======================

//#define NULL 0

void main_menu_welcome();
//===============================Customer======================
void Customer();
void customer_view (char x[20]);
void oder(char a[100][200],char b[100][200],char x[2],int c);
void bill (char x[2]);
//===============================Admin======================
void admin();
void admin_menu();
void add_menu(char x[2]);
//void full_product ();
void show_bill();
void clear_bill();
void change_password ();
void add_menu_product(char x[10]);
void add_product(char x[20],float y,char type[20]);
void delete_menu(char x[2]);
void delete_confirm (char line[100][200],int total,int recieve,char b[2]);
void delete_menu_file(char line[100][200],int total,int recieve,char x[2]);
/*
//===============================Structure======================

typedef struct {
		char name[15] ;
		float price;
	} menu_info ;

*/

//===============================Main======================


int main(int argc, char const *argv[])
{
	system("cls");
	main_menu_welcome();

	return 0;
}

//===============================Main menu======================

void main_menu_welcome() {

	int i;
	char ch;

	system("cls");
	printf("\n\n\n\n\t##########################################\n");
	printf("\n\t\tWelcome to Fatoni restaurant\n");
	printf("\n\t##########################################\n");
	for (i=0;i<=20;i++){
		if (i == 2) {
		printf("\n\t\tCustomer\n");
		i++;
		printf("\n\t\tAdmin\n");
		i++;
		i++;
		} else {
		printf("\n");
		}
	}
	printf("\t------------------------------------------\n");
	printf("\tFirst Character for further Menu  ");

	ch=toupper(getche());
	switch(ch){
		case 'C' : Customer();
		break;
		case 'A' : admin();
		break;
		default: main_menu_welcome();
		break;
	}


}

//===============================Customer======================

void Customer() {

	int i;
	char ch;

	do {
		system("cls");
		printf("\n\n\n\n\t##########################################\n");
		printf("\n\t\tChoose category of food\n");
		printf("\n\t##########################################\n");
		for (i = 0; i < 20; ++i){
			if (i==2){
			printf("\n\t\tAppetisers\n");
			i++;
			printf("\n\t\tMain courses\n");
			i++;
			printf("\n\t\tBeverage\n");
			i++;
			} else {
				printf("\n");
			}
		}
		printf("\t------------------------------------------\n");
		printf("\tEnter 0 for back to main menu\n");
		printf("\tFirst Character for further Menu ");

		ch = toupper(getche());

		switch(ch) {
			case 'A' : customer_view("A");
			break;
			case 'M' : customer_view("M");
			break;
			case 'B' : customer_view("B");
			break;
			case '0' :
				main_menu_welcome();
			break;
			default :
				printf("\n\tPlese Enter right character ONLY (A,M,B,0)\n");
				ch=getch();
			break;
		}
	} while (ch != '0');
}


//===============================Admin======================

void admin() {

	int i,a;
	char ch[20],pw[20];

	system("cls");

	FILE *fp;

	fp=fopen("pw.dat","r");
	fscanf(fp,"%s",pw);

	printf("\n\n\n\n\t##########################################\n");
	printf("\n\t\tPlz enter password\n");
	printf("\n\t##########################################\n\n");
	for (i = 0; i < 20; ++i){
		if (i==2){
			printf("\t\tEnter 0 for back to main menu\n");
			i++;
			printf("\n\t\tPassword ::: ");
			scanf ("%s",&ch);
			i++;
		} else {
			printf("\n");
		}
	}

	printf("\t------------------------------------------\n");

	if (strcmp(ch,pw) == 0) {
		admin_menu();
	} else {
		main_menu_welcome();
	}

	//ch = toupper(getche());
}

//===============================Admin_Menu======================

void admin_menu() {

	int i;
	char ch;

	do{
		system("cls");
		printf("\n\n\n\n\t##########################################\n");
		printf("\n\t\tWelcome administrator\n");
		printf("\n\t##########################################\n\n");

		for (i = 0; i < 20; ++i){
			if (i == 2)	{
				printf("\t\tAdd new menu\n");
				i++;
				printf("\n\t\tDelete Menu\n");
				i++;
				printf("\n\t\tShow bill\n");
				i++;
				printf("\n\t\tRemove bill\n");
				i++;
				printf("\n\t\tChange password\n");
				i++;
			} else {
				printf("\n");
			}
		}
		printf("\t------------------------------------------\n");
		printf("\tEnter 0 for back to main menu\n");
		printf("\tFirst Character for further Menu ");

		ch = toupper(getche());

		switch(ch) {
			case 'A' : add_menu("A");
			break;
			case 'D' : add_menu("D");
			break;
			case 'S' : show_bill();
			break;
			case 'C' : change_password ();
			break;
			case 'R' : clear_bill();
			break;
			case '0' :
				main_menu_welcome();
			break;
			default :
				printf("\n\tPlese Enter right character ONLY (A,D,0)\n");
				ch=getch();
			break;
		}
	} while (ch != '0');

}

//===============================Add_menu======================

void add_menu(char x[2]){

	int i;
	char ch;

	do {
		system("cls");
		printf("\n\n\n\n\t##########################################\n");
		printf("\n\t\tChoose type of menu\n");
		printf("\n\t##########################################\n");
		for (i = 0; i < 20; ++i){
			if (i==2){
			printf("\n\t\tAppetisers\n");
			i++;
			printf("\n\t\tMain courses\n");
			i++;
			printf("\n\t\tBeverage\n");
			i++;
			} else {
				printf("\n");
			}
		}
		printf("\t------------------------------------------\n");
		printf("\tEnter 0 for back to main menu\n");
		printf("\tFirst Character for further Menu ");

		ch = toupper(getche());

		switch(ch) {
			case 'A' :
				if (strcmp(x,"A")==0){
					add_menu_product("A");
				} else {
					delete_menu("A");
				}

			break;
			case 'M' :
				if (strcmp(x,"A")==0){
					add_menu_product("M");
				} else {
					delete_menu("M");
				}
			break;
			case 'B' :
				if (strcmp(x,"A")==0){
					add_menu_product("B");
				} else {
					delete_menu("B");
				}
			break;
			case '0' :
				main_menu_welcome();
			break;
			default :
				printf("\n\tPlese Enter right character ONLY (A,M,B,0)\n");
				ch=getch();
			break;
		}
	} while (ch != '0');
}

//===============================Add_menu_Appetisers======================

void add_menu_product(char x[10]) {

	int i;
	float menu_price;
	char menu_name[20],ch;

	system("cls");
	printf("\n\n\n\n\t##########################################\n");
	if ( x == "A") {
		printf("\n\t\tAdd menu appetisers\n");
	} else if ( x == "M") {
		printf("\n\t\tAdd menu main courses\n");
	} else {
		printf("\n\t\tAdd menu Beverage\n");
	}
	printf("\n\t##########################################\n");


	//printf("%s\n",x);

	for (i = 0; i < 20; ++i){
		if (i==2){
			printf("\t\tEnter menu name ::: ");
			scanf ("%s",&menu_name);
			i++;
			printf("\n\t\tEnter price of menu ::: ");
			scanf ("%f",&menu_price);
			i++;
			printf("\n\n\n\t\tProduct :: %s :: %.2f\n\n",menu_name,menu_price);
			printf("\n\t\tDo you want to save it ? \n\n\t\t|Y| Yes\t\t|N| No\n");
			i+=10;

		} else {
			printf("\n");
		}
	}
	printf("\t------------------------------------------\n");
	printf("\tEnter 0 for back to main menu\n");
	printf("\tFirst Character for further Menu ");

	ch = toupper(getche());
	switch(ch) {
		case 'Y' : add_product(menu_name,menu_price,x);
		break;
		case 'N' : add_menu("A");
		break;
		case '0' :
			main_menu_welcome();
		break;
		default :
			printf("\n\tPlese Enter right character ONLY (Y,N,0) ::");
			ch=getch();
		break;
		}
}

//===============================Add_menu======================


void add_product(char x[20],float y,char type[20]) {

	char line[100][200];
	int i;

	FILE *fp;

	if ( type == "A") {
	fp = fopen("menuA.dat", "a");
	} else if ( type == "M") {
	fp = fopen("menuM.dat", "a");
	} else {
	fp = fopen("menuB.dat", "a");
	}

	fprintf(fp,"%s\n%.2f\n",x,y);

	fclose(fp);
}

//===============================Add_order======================

void oder(char a[100][200],char b[100][200],char x[2],int c) {


	FILE *fp;

	int count,arr=0,i;

	fp = fopen("order.dat", "w");
	/*if (x == "A") {
    	fp = fopen("oderA.dat", "w");
    } else if (x == "M") {
    	fp = fopen("oderM.dat", "w");
    } else {
    	fp = fopen("oderB.dat", "w");
    }*/


    for (i = 0; i < c; ++i){
    	fprintf(fp, "%s\n%s\n",a[arr],b[arr]);
    	arr++;
    }
	//fprintf(fp,"%s\n%.2f\n",n,p);

	fclose(fp);
}

//===============================delete_menu======================

void delete_menu(char x[2]) {
	char line[100][200],ch[2];
	char tempN[100][200];
	char tempP[100][200];
    FILE *fp;
    int i = 0,a,b=0,c=0,d,e,f;
    int total = 0;

    if (x == "A") {
    	fp = fopen("menuA.dat", "r");
    } else if (x == "M") {
    	fp = fopen("menuM.dat", "r");
    } else {
    	fp = fopen("menuB.dat", "r");
    }

    while(fgets(line[i], 200, fp)) {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    fclose(fp);

    total = i;

    system("cls");
    printf("\n\n\n\n\t##########################################\n");
	if ( x == "A") {
		printf("\n\t\tAppetisers\n");
	} else if ( x == "M") {
		printf("\n\t\tMain courses\n");
	} else {
		printf("\n\t\tBeverage\n");
	}
	printf("\n\t##########################################\n");
		for (a = 0; a < 20; ++a){
			if (a==2){
				for(i = 0; i < (total/2); ++i){
						printf("\t\t%d. %s",i+1,line[b]);
						f=strlen(line[b]);
						if (f<6) {
							for (e = 0; e <= f; ++e) {
								printf(" ");
							}
						}
						printf("\t\t%s\n",line[b+1]);
						b+=2 ;
						a++;
				}
				d=i;
				printf("\n\n\t------------------------------------------\n");
				printf("\tEnter 0 for cancel\n");
				//printf("\tEnter %d for backward\n",d+1);
				//printf("\tEnter %d for bill\n",d+2);
				printf("\tEnter number for choose menu\n");
				printf("\t------------------------------------------\n\n");
				do {
					printf("\t\t");
					scanf ("%s",&ch);
					i = atoi(ch);
					while (!(i <= (d+2) && i >= 0)){
						printf("\t\tSorry! Plz enter again\n");
						printf("\t\t");
						scanf ("%s",&ch);
						i = atoi(ch);
					}
					if (i==0){
						admin_menu();
					} else {
						i *= 2;

						printf("\n\n\t\tDo you want to delete it ? \n\n");
						printf("\n\t\t| %s",line[i-2],line[i-1]);
						f=strlen(line[i-2]);
						if (f<6) {
							for (e = 0; e <= f; ++e) {
								printf(" ");
							}
						}
						printf("\t\t%s |\n\n",line[i-1]);
						printf("\t\t|Y|\t\t|N|\n\n\t\t");
						i /=2;
						delete_confirm (line,total,i,x);

						//---------------------------------------------------------0
						//c++;
					}
				} while (i != 0);
			} else {
				printf("\n");
			}
		}
	printf("\t------------------------------------------\n");
}

//==============================delete_confirm==========================

void delete_confirm (char line[100][200],int total,int recieve,char b[2]){

	//int a;
	char x[2],a;

	do{
	//x = getch();
	scanf ("%s",&(x));
	//x=toupper(getchar());
	//printf("\n%d\n",recieve);
	} while (!(strcmp(x,"Y")==0||strcmp(x,"N")==0||strcmp(x,"y")==0||strcmp(x,"n")==0));

	if (strcmp(x,"Y")==0||strcmp(x,"y")==0) {
		a='1';
	} else {
		a='2';
	}

	switch(a) {
		case '1' :
		delete_menu_file (line,total,recieve,b);
			/*
			for (recieve=0; recieve < b; ++recieve)
			{
				c=recieve/2;
				d=(c+1)*2;
				//strcpy(line[c-2],line[d-2]);
				//strcpy(line[c-1],line[d-1]);
				printf("%s\n",recieve);
			}
			for (e = 0; e < b; ++e)
			{
				printf("%s\n",line[e]);
			}
			*/

		break;
		case '2' :
			add_menu("D");
		break;
	}
	/*
	if (strcmp(toupper(x),"Y")) {
		strcpy(tempN[c],line[i-2]);
		strcpy(tempP[c],line[i-1]);
	} else if (strcmp(x,"N")) {
		add_menu("D");
	} else {
		printf("Sorry! Plz enter again  ");
		x = toupper(getche());
	}
	*/
}

//==============================delete_confirm==========================

void delete_menu_file(char line[100][200],int total,int recieve,char x[2]) {

	int b = (total/2)-1,c,d,e;

	printf("%d22\n",recieve );
	printf("%d\n",total);
	printf("%d\n",b);

	while (recieve <= b) {
		c = (recieve+1)*2;
		strcpy(line[c-4],line[c-2]);
		strcpy(line[c-3],line[c-1]);
		//printf("%s\t%s\n",line[c-2],line[c-1]);
		recieve++;
	}

	FILE *fp;

	if (x == "A") {
    	fp = fopen("menuA.dat", "w");
    } else if (x == "M") {
    	fp = fopen("menuM.dat", "w");
    } else {
    	fp = fopen("menuB.dat", "w");
    }

	c=0;
	for (d = 0; d < b; ++d)
	{

		fprintf(fp,"%s\n%s\n",line[c],line[c+1]);
		c+=2;
	}

	fclose(fp);

	delete_menu(x);

}

//==============================show_bill==========================

void show_bill() {

	system ("oldorder.txt");
}

//==============================change_password==========================
void change_password () {

	char a[15],b[15],ch[2];

	do {

		if (strcmp(a,b)!=0)
		{
			printf("Sorry! password does not same\n");
		}

		system("cls");
		printf("\n\n\n\n\t##########################################\n");
		printf("\n\t\tChange admin password\n");
		printf("\n\t##########################################\n");

		printf("\n\n\n\n\t\tEnter new password ::: ");
		scanf ("%s",&a);

		printf("\n\n\n\t\tEnter new password again ::: ");
		scanf ("%s",&b);

	} while (strcmp(a,b)!=0);

	do {
		printf("\n\n\t\tDo you want to save it?\n\n\t\t|Y|\t\t|N|\n\n\t\t");
		scanf ("%s",&ch);
	} while (!(strcmp(ch,"Y")==0||strcmp(ch,"N")==0||strcmp(ch,"y")==0||strcmp(ch,"n")==0));

	if (strcmp(ch,"y")==0 || strcmp(ch,"Y")==0)
	{
		FILE *fp;

		fp = fopen("pw.dat","w");
		fprintf(fp, "%s",a);
		fclose(fp);
		main_menu_welcome();
	} else {
		admin_menu();
	}
}

//================================clear_bill=========================

void clear_bill() {

	char ch[2];
	int a=0;

	system("cls");
	printf("\n\n\n\n\t##########################################\n");
	printf("\n\t\tDo you want to clear all bill?\n");
	printf("\n\t##########################################\n");
	printf("\n\n\n\t\t|Y|\t|N|\n");
	do {
		if (a >= 1)
		{
		  printf("\t\tSorry! plz enter again\n");
		}
		printf("\t\t");
		scanf ("%s",&ch);
		a++;
	} while (!(strcmp(ch,"Y")==0||strcmp(ch,"N")==0||strcmp(ch,"y")==0||strcmp(ch,"n")==0));

	if (strcmp(ch,"y")==0 || strcmp(ch,"Y")==0)
	{
		FILE *fp;
		fp = fopen("oldorder.txt","w");
		fclose(fp);
		admin_menu();
	} else {
		admin_menu();
	}
}
