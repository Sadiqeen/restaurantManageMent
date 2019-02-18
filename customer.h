
void customer_view (char x[20]) {
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
				printf("\tEnter %d for bill\n",d+1);
				printf("\tEnter number for choose menu\n");
				printf("\t------------------------------------------\n\n");
				do {
					printf("\t\t");
					scanf ("%s",&ch);
					i = atoi(ch);
					while (!(i <= (d+1) && i >= 0)){
						printf("\t\t---------------------------------\n");
						printf("\t\tSorry! Plz enter again\n");
						printf("\t\t---------------------------------\n");
						printf("\t\t");
						scanf ("%s",&ch);
						i = atoi(ch);
					}
					if (i==0){
						Customer();
					} else if ((i==(d+1))&&c!=0) {
						oder(tempN,tempP,x,c);
						bill(x);
					}else if ((i==(d+1))&&c==0){
						printf("\t\t---------------------------------\n");
						printf("\t\tSorry! You didn't choose menu yet\n");
						printf("\t\t---------------------------------\n");
					} else {
						i *= 2;
						printf("\t\t| %s",line[i-2],line[i-1]);
						f=strlen(line[i-2]);
						if (f<6) {
							for (e = 0; e <= f; ++e) {
								printf(" ");
							}
						}
						printf("\t\t%s |\n",line[i-1]);
						strcpy(tempN[c],line[i-2]);
						strcpy(tempP[c],line[i-1]);
						c++;
					}
				} while (i != 0);
			} else {
				printf("\n");
			}
		}
	printf("\t------------------------------------------\n");
}

//===============================Bill==========================

void bill (char x[2]) {

 	//=================================================================0
	time_t mytime;
    mytime = time(NULL);
	//=================================================================0

	system("cls");
	char line[100][200];
	int i = 0,a,b=0,c=0,d;
    int total = 0,e,f;
    float result=0,n;

    FILE *fp,*wr;

    fp = fopen("order.dat", "r");
    /*
    if (x == "A") {
    	fp = fopen("oderA.dat", "r");
    } else if (x == "M") {
    	fp = fopen("oderM.dat", "r");
    } else {
    	fp = fopen("oderB.dat", "r");
    }*/
    wr = fopen("oldorder.txt", "a");

    while(fgets(line[i], 200, fp)) {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    fclose(fp);

    total = i;

    printf("\n\n\n\n\t##########################################\n");
    //fputs("\n\t##########################################\n",wr);
    fputs("------------------------------",wr);
	if ( x == "A") {
		printf("\n\t\tBill of Appetisers\n");
		fputs("\nBill of Appetisers\n",wr);
	} else if ( x == "M") {
		printf("\n\t\tBill of Main courses\n");
		fputs("\nBill of Main courses\n",wr);
	} else {
		printf("\n\t\tBill of Beverage\n");
		fputs("\nBill of Beverage\n",wr);
	}
	fprintf(wr,ctime(&mytime));
	fputs("------------------------------\n",wr);
	//fprintf(wr,"\n\t\t%s\n",system("date"));
	printf("\n\t##########################################\n\n\n");
	//fputs("\n\t##########################################\n\n\n",wr);


    for(i = 0; i < (total/2); ++i){
		printf("\t\t%d. %s",i+1,line[b]);
		fprintf(wr,"%d. %s",i+1,line[b]);
		f=strlen(line[b]);
		if (f<6) {
			for (e = 0; e <= f; ++e) {
				printf(" ");
				fputs(" ",wr);
			}
		}
		printf("\t\t%s\n",line[b+1]);
		fprintf(wr,"\t\t%s\n",line[b+1]);
		n=atoi(line[b+1]);
		//printf("%.2f\n",n);
		result+=n;
		b+=2 ;
	}
	printf("\n\t------------------------------------------\n");
	fputs("------------------------------\n",wr);
	printf("                                 Total is %.2f\n",result);
	fprintf(wr,"               Total is %.2f\n\n\n\n",result);

	fclose(wr);

}



/*
	ch = toupper(getche());
	switch(ch) {
		case '1' : oder(line[0],line[1],x);
		break;
		case '2' : oder(line[2],line[3],x);
		break;
		case '3' : oder(line[4],line[5],x);
		break;
		case '4' : oder(line[6],line[7],x);
		break;
		case '5' : oder(line[8],line[9],x);
		break;
		case '6' : oder(line[10],line[11],x);
		break;
		case '7' : oder(line[12],line[13],x);
		break;
		case '8' : oder(line[14],line[15],x);
		break;
		case '9' : oder(line[16],line[17],x);
		break;
		case '10' : oder(line[18],line[19],x);
		break;
		case '0' :
			Customer();
		break;
		default :
			printf("\n\tPlese Enter right character ONLY (Y,N,0) ::");
			ch=getch();
		break;
		}
    //for(i = 0; i < total; ++i)
    //    printf("%s\n", line[i]);

}
*/