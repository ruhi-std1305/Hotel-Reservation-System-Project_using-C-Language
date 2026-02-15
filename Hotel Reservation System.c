/*

 Project: Hotel Reservation System
 Course: Computer Programming 1
 Contributers:
            Nusrath Jahan Shawon
            Sumaia Tarannoom Mahi
            Suraia Tabassoom Ruhi
            Sabiha Jannat
 Description: This project allows users to book, cancel, and manage hotel reservations.

*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>

int sR=25, kR=40, tR=50, totRes=0;
char myName[100], guest;
struct Reservation {
    char custName[30], custLastName[30], roomType;
    int rD, rM, rY, perDay, noOfPer, resId, noOfRoom;
    float billAmt;
}strR[115];

void gotoxy(int x, int y);
void resetColor();
void red();
void cyan();
void headerFooter();
void footeronly();
bool isLeapYear(int year);
void firstImpression();
void login();
char menu();
void hotelInfo();
void report();
void roomAvl();
void res();
void bill();
void saveReservationData(struct Reservation strR[]);
void loadFromFile();


void main()
{
	firstImpression();
    if (guest=='e'||guest=='E') return;
	char option;
	loadFromFile();
    do
	{
		option=menu();
		switch(option)
			{
				case 'd':case 'D':
				report();
				break;

				case'h':case 'H':
				hotelInfo();
				break;

				case'a':case'A':
				roomAvl();
				break;

				case'r':case'R':
				res();
				break;

				case'l':case'L':
                firstImpression();
				break;
			}

		getch();

	}while(option!='e'&&option!='E');

    return;
}


/* FUNCTION DEFINITIONS */


/// Decor

void gotoxy(int x, int y) {
	printf("\033[%d;%dH", y, x); //cursor position according to ANSII unicode
}

void resetColor() {
    printf("\033[0m"); // Reset colour to default using ANSII unicode
}

void red () {
	printf("\033[1;31m");
}

void cyan () {
	printf("\033[0;36m");
}

void headerFooter() {
    gotoxy(5,2);
    	  red();    printf("*================================================================*");
    gotoxy(5,3);	printf("|                         Raindrops Resorts                      |");
    gotoxy(5,4);    printf("*================================================================*");
    gotoxy(1,27);printf("___________________________________________________________________________");
    gotoxy(4,28);
		 cyan();    printf("                      Created By Team: RainDrops                   ");
    gotoxy(4,29);	printf("                 Members: Shawon, Mahi, Ruhi ,Jannat               ");

    resetColor();
}

void footeronly() {
    red();
    gotoxy(1,27);printf("___________________________________________________________________________");
        gotoxy(4,28);   printf("                      Created By Team: RainDrops                   ");
        gotoxy(4,29);	printf("                 Members: Shawon, Mahi, Ruhi ,Jannat               ");
    resetColor();
}


/// Front-End + Back-End

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

void firstImpression()
{
    system("cls");
    footeronly();

    char entrytype[20];
    gotoxy(1,25); printf("Press 'E' to exit.");
    gotoxy(1,19); printf("Dear Customer! We are out of service right now.");
    gotoxy(1,20); printf("Only Admin or Staff members are allowed to enter.");

    gotoxy(1,1); red(); printf("                                   Welcome!");
            resetColor();
    gotoxy(21,8);       printf("Are you a Customer or Staff member?");
    gotoxy(21,9);       printf("            Type C or S:  "); scanf("%c", &guest);
                                                              getchar();

    if (guest!='E'&&guest!='e'&&guest!='S'&&guest!='s'&&guest!='C'&&guest!='c')
    {
        main();
    }

    else if (guest=='e'||guest=='E')
    {
        gotoxy(22,26);
        cyan(); printf("Thank You...Do Visit Us Again...%c\n\n\n\n\n\n",2);
        resetColor(); getch(); fflush(stdin);
    }
    else if (guest=='s'||guest=='S') login();
    else if (guest=='c'||guest=='C')
        {
        system("cls");

        gotoxy(1,19); printf("Apologies! Invalid choice.                              ");
        gotoxy(1,20); printf("                                                        ");
        getch(); fflush(stdin);
        }
}

void login()
{
	char c, uniquePass[10], adminPass[10]="admin";
    int a=0, i=0;

    do
    {
        system("cls");
        footeronly();

                        ///take the pass from user
        gotoxy(1,8);printf("   ~~~~~~~~~~  Enter the password to proove your authenticity!  ~~~~~~~~~~");
        gotoxy(36,11);

        while(i<10)		// it will accept till 9th characterm
        {
            uniquePass[i]=getch();	// using getch instead of getche, character entered is not visible
            c=uniquePass[i];

            if(c==13) break;	    // ASCII decimal value for carriage return is 13 ('enter' key)
            else 	  printf("*");
            i++;
        }
        uniquePass[i]='\0';

        i=0;    // reset i value for cases: wrong password entered


                //two conditions for pass entered
        if(strcmp(uniquePass,adminPass)==0)
            {   break;  }   //to jump out of the do...while loop
        else
            {
                printf("\n\n\n        try agin, won't ya?");
                a++;
                getch();
            }

    } while(a<=2);	//accepts pass for 3 times

    if (a>2)
    {
        printf("\n\nSorry, you have entered the wrong password for three times.\n\tNow, get outta here, outsider!");
        getch();    fflush(stdin);
        firstImpression();
    }
    else
    {
        system ("cls");
        printf("\n\n\n");
        printf("             Welcome sir/madam, Login in successful");
        printf("\n");
        printf("             Press any key to move forward...");
        getch();	fflush(stdin);
    }
    system("cls");
}

char menu()
{
    system("cls");
    headerFooter();

    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime); // Display current date and time

    gotoxy(1,7); printf("   %02d/%02d/%04d \n   %02d:%02d:%02d\n",
           localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

	cyan();
    gotoxy(23,8);    printf("*------------------------------*");
    gotoxy(23,9);    printf("|   D for Data                 |");
    gotoxy(23,10);   printf("|                              |");
    gotoxy(23,11);   printf("|   H for Hotel Information    |");
    gotoxy(23,12);   printf("|                              |");
    gotoxy(23,13);   printf("|   A for Availability         |");
    gotoxy(23,14);   printf("|                              |");
    gotoxy(23,15);   printf("|   R for Reservation          |");
    gotoxy(23,16);   printf("|                              |");
    gotoxy(23,17);   printf("|   L for Logout               |");
    gotoxy(23,18);   printf("|______________________________|");	resetColor();
    gotoxy(26,21);   printf("Enter your choice ");
    gotoxy(46,21);   return(getche());
}

void hotelInfo()
{
system("cls");
headerFooter();

    gotoxy(3,6);   printf(" It is 30-story Hotel, which is completely Air-condition, Spacious.");
    gotoxy(3,7);   printf(" There are total 10 Restaurants, 5 Swimming Pool, one large Kid's Corner,\n   Icecream & Juice bars, and a total of 115 rooms");
    gotoxy(3,10);  printf(" Amenities: ");
    gotoxy(15,10); printf(" WIFI, Telephone, 24 Hour BAR & Restaurant and Room Service,\n   full day Icecream & Juice bars, 24/7 gaming zone, ");
    gotoxy(3,12);  printf(" Near By:");
    gotoxy(15,12); printf(" Kolatoli road, @ 20Mtr.");

    gotoxy(40,12); printf(" Loacated at COX'S BAZAR");

    gotoxy(3,15);  printf(" ROOM INFORMATION");
    gotoxy(4,16);  printf("*-------------------------------------------------------------------*");
    gotoxy(4,17);  printf("| Room Type | Information                                | Price    |");
    gotoxy(4,18);  printf("|-----------*--------------------------------------------*----------|");
    gotoxy(4,19);  printf("|   SUIT    | 2Rooms, 120Sq-Mtr, Sofa and King Bed       | 10000/-  |");
    gotoxy(4,20);  printf("|-----------*--------------------------------------------*----------|");
    gotoxy(4,21);  printf("|   KING    | 60Sq-Meter, Sofa, Table and King Bed       | 5000/-   |");
    gotoxy(4,22);  printf("|-----------*--------------------------------------------*----------|");
    gotoxy(4,23);  printf("|   TRAVEL  | 40Sq-Meter, Table, Queen Bed               | 2500/-   |");
    gotoxy(4,24);  printf("|___________________________________________________________________|");
}



void report()
{
    int i;
    system("cls");
    headerFooter();
    gotoxy(10,5);
        if(totRes==0)
        {
            printf("\n No Information To Display ");
        }
    else{
        for(i=0;i<totRes;i++){
            printf("\n ID: %4d          Name: %s %s", strR[i].resId, strR[i].custName, strR[i].custLastName);
            printf("\n Date: %d-%d-%d   Days: %d        Room: %c", strR[i].rD, strR[i].rM, strR[i].rY, strR[i].perDay, strR[i].roomType);
            printf("\n Person: %d       No of Room: %d  Amt: %6.0f ",strR[i].noOfPer, strR[i].noOfRoom, strR[i].billAmt);
            printf("\n*----------------------------------------------------------*\n");
			}
        }
}

void roomAvl()
{
    system("cls");
    headerFooter();

    gotoxy(5,7);      printf(" ~~~~ROOM  AVAILABILITY~~~~");
    if (sR > 0 && sR <= 25) {
        gotoxy(3, 9); printf("      Suit     : %d", sR);
    } else {
        gotoxy(3, 9); printf("      Suit     : N/A");
    }

    if (kR > 0 && kR <= 40) {
        gotoxy(3, 10); printf("      King     : %d", kR);
    } else {
        gotoxy(3, 10); printf("      King     : N/A");
    }

    if (tR > 0 && tR <= 50) {
        gotoxy(3, 11); printf("      Travel   : %d", tR);
    } else {
        gotoxy(3, 11); printf("      Travel   : N/A");
    }
}

void res()
{
    system("cls");
    headerFooter();

    // Getting the current date
        time_t t;
        struct tm* now;
        time(&t);
        now = localtime(&t);
        int currentDay = now->tm_mday,
            currentMonth = now->tm_mon+1,   //0-based
            currentYear = now->tm_year+1900;    //since 1900

    gotoxy(3,6);   printf(" Enter Your First Name: ");
                gets(strR[totRes].custName);
    gotoxy(3,7);   printf(" Enter Your Last Name : ");
                gets(strR[totRes].custLastName);

    while(1)
    {
        int flag=0;
        gotoxy(3,8);   printf(" Enter Date: dd/mm/yyyy");
        gotoxy(16,8);   scanf("%d/%d/%d", &strR[totRes].rD, &strR[totRes].rM, &strR[totRes].rY);
                        getchar();
        int LY=isLeapYear(strR[totRes].rY);

            if (strR[totRes].rY<currentYear||
                strR[totRes].rY==currentYear&&strR[totRes].rM<currentMonth||
                strR[totRes].rY==currentYear&&strR[totRes].rM==currentMonth&&strR[totRes].rD<currentDay||
                strR[totRes].rM>12 || strR[totRes].rD>31||
                (strR[totRes].rD>30&&(strR[totRes].rM==4||strR[totRes].rM==6||
                strR[totRes].rM==8||strR[totRes].rM==9||strR[totRes].rM==11))||
                strR[totRes].rD>29&&(LY)&&strR[totRes].rM==2||
                strR[totRes].rD>28&&(!LY)&&strR[totRes].rM==2) {

                printf("\n.\n.\n.\nYou have entered an invalid date! Go get a calender.\n");
                printf("Press 'R' to retry or press ENTER key to cancel reservation right now__");
                    char c=getch(); fflush(stdin);
                    if(c=='r'||c=='R') res(); else break;
            }

            int var=1;
            while(var)
            {
                gotoxy(3,8);printf("                                     ");
                gotoxy(3,8);   printf(" Enter Room Type (S/K/T): ");
                gotoxy(29,8);   scanf(" %c", &strR[totRes].roomType); //fflush(stdin);

                char cr=tolower(strR[totRes].roomType);

                if (cr == 's' || cr == 'k' || cr == 't') {
                    break; // Exit the inner while loop when the condition is met
                }
                else {
                    printf("\n.\n.\n.\nThere is no such room.\n");
                    printf("Press 'R' to retry or press ENTER key to cancel reservation right now__");
                    char c = getch(); fflush(stdin);
                        if (c == 'r' || c == 'R')
                            {res(); var=0;} // Continue the outer loop
                        else {var=0; break;} // Exit both loops
                }
            }
        if (!var) break;

        gotoxy(3,8);printf("                                     ");
        gotoxy(3,8);   printf(" Enter No days: ");
        gotoxy(19,8);   scanf("%d", &strR[totRes].perDay); getchar();

        gotoxy(3,8);printf("                                     ");
        gotoxy(3,8);   printf(" Enter no of People: ");
        gotoxy(25,8);   scanf("%d", &strR[totRes].noOfPer); getchar();

        strR[totRes].noOfRoom=1;
        if(strR[totRes].noOfPer>3)
            {
                strR[totRes].noOfRoom = 0;
                strR[totRes].noOfRoom += (strR[totRes].noOfPer/3);

                if(strR[totRes].noOfPer%3 != 0) strR[totRes].noOfRoom ++;
            }
        bill();
        break;   // finally outta while loop
    }

}

void bill()
{
    float damt; //daily amount
    char ty[10];
    switch (strR[totRes].roomType)
    {
        case 's': case 'S':
            strcpy(ty, "SUIT"); damt=10000;
            sR=sR-(strR[totRes].perDay*strR[totRes].noOfRoom);
            break;
        case 'k': case 'K':
            strcpy(ty, "King"); damt=5000;
            kR=kR-(strR[totRes].perDay*strR[totRes].noOfRoom);
            break;
        case 't': case 'T':
            strcpy(ty, "Travel"); damt=2500;
            tR=tR-(strR[totRes].perDay*strR[totRes].noOfRoom);
            break;
    }

strR[totRes].billAmt=strR[totRes].perDay*damt*strR[totRes].noOfRoom;

    gotoxy(3,10);   printf("Bill: ");
    gotoxy(3,11);   printf("*----------------------------------------------------------------*");
    gotoxy(3,12);   printf("| Room Type   |                                      %s          ", ty);
    gotoxy(3,13);   printf("|-------------|--------------------------------------------------|");
    gotoxy(3,14);   printf("| Total Days  |                                       %d         ", strR[totRes].perDay);
    gotoxy(3,15);   printf("|-------------|--------------------------------------------------|");
    gotoxy(3,16);   printf("| Per day     |                                    Tk %03.2f      ", damt);
    gotoxy(3,17);   printf("|-------------|--------------------------------------------------|");
    gotoxy(3,18);   printf("| No of Rooms |                                       %d         ", strR[totRes].noOfRoom);
    gotoxy(3,19);   printf("|-------------|--------------------------------------------------|");
    gotoxy(3,20);   printf("| Price       |                                    Tk %03.2f       ", strR[totRes].billAmt);
    gotoxy(3,21);   printf("|-------------|--------------------------------------------------|");
    gotoxy(3,22);   printf("| Total Bill  ~~~                                  Tk %03.2f       ", strR[totRes].billAmt);
    gotoxy(3,23);   printf("|________________________________________________________________|");

    strR[totRes].resId = totRes+1;
    gotoxy(3,25); printf("Resevation ID=%d", strR[totRes].resId);
    totRes++;
    saveReservationData(strR);

}

void saveReservationData(struct Reservation strR[]) {
    FILE *file = fopen("reservationData.txt", "a");

    if (file == NULL) {
        printf("Could not open the file.\n");
        return;
    }

    for (int i = 0; i < totRes; i++) {
        fprintf(file, "%s %s %c %d %d %d %d %d %d %f %d\n",
                strR[i].custName, strR[i].custLastName, strR[i].roomType, strR[i].rD, strR[i].rM, strR[i].rY,
                strR[i].perDay, strR[i].noOfPer, strR[i].resId, strR[i].billAmt, strR[i].noOfRoom);
    }

    fclose(file);
    printf("\t---data has been saved successfully.\n");
}

void loadFromFile() {
    FILE *file = fopen("reservationData.txt", "r");

    if (file == NULL) {
        printf("Could not open the file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %s %c %d %d %d %d %d %d %f %d",
                  strR[totRes].custName, strR[totRes].custLastName, &strR[totRes].roomType, &strR[totRes].rD,
                  &strR[totRes].rM, &strR[totRes].rY, &strR[totRes].perDay,
                  &strR[totRes].noOfPer, &strR[totRes].resId, &strR[totRes].billAmt,
                  &strR[totRes].noOfRoom) != EOF)
            {
        char cTemp=tolower(strR[totRes].roomType);
             if (cTemp=='s') sR--;
        else if (cTemp=='k') kR--;
        else if (cTemp=='t') tR--;
        totRes++;
    }

    fclose(file);
    printf("Reservation data has been loaded successfully.\n");
}



// Ends Here
