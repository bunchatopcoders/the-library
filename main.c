#include <stdio.h>
#include <stdlib.h>

#include "coniox.h"
#include <curses.h>
#include <string.h>


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void delay(int t);
void main_menu(void);
void menu_sys1(void);
void instructions(void);
void menu_sys2(void);
void menu_reader(void);
void menu_reg (void);
void menu_mem(void);
void menu_search(void);



#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#define BOOKTILTE 50
#define NAME 25

typedef struct date {

int day, mounth, year;


} date;


typedef struct book {
    char title[BOOKTILTE];
    char author[NAME];
    char ISBN[18];
    char publisher[NAME];
    char category[NAME];
    int av; //availability
    //bool isSafe; // to check whether content is safe for underage
    date date_pub;
    //borrow -> copies

}book;

typedef struct borrow // borrow book
{
   
    int id; // id tany 5als
    int ISBN; // ISBN tany 5als
    date date_due;
    date date_issue;
    //int book.ISBN;

} bbooks;
typedef struct  member {

    char name[2][NAME];
    int id;
    char address[3][NAME];
    int age;
    char phone[12];
    char email[30];
}member;

int main()
{
    printf("Hello world!\n");
    return 0;
}
int main()
{




while(1)
{

main_menu();
delay(10);

puts("main_menu : passed");

delay(10);
 }
return 0;

}

void main_menu(void)
{

system("clear");
int i ;
for (i = 0 ; i<18 ; i++)
printf("\u287F\u287F\u287F");

//E22D

printf("\n \u262F Welcome to m4 Ibn El-Haitham Library System  \u262F \n");

//printf(" arrow \u25C4  \u21E6\n");

for (i = 0 ; i<18; i++)

printf("\u287F\u287F\u287F");

//printf(" Smile :\u263B   1 \u24F5  \u2592 tick \u2611 wrong \u2612 \u278A \u278B \u278C \u278D \u278E"
// " \u278F \u2790 \u2791 \u2792 \u2793  \n");



 puts("\n\t \u287F\u287F\u287F Select Portal\u287F\u287F\u287F \n\t \u278A System Portal\n\t \u278B Member / Vistor Portal");
	//puts("\t \u287F\u287F\u287F OR \u287F\u287F\u287F\n\t \u278c see how-to-use the program\n");
	printf(BLU "\t \u287F\u287F\u287F OR \u287F\u287F\u287F\n\t \u278c see how-to-use the program\n\n" RESET);

	bool flag;
	//bool stop = TRUE;
	//bool space = FALSE ;
	// in case no 10 --> case 1 handle ??



do{


	switch (getche())

{

	/*case '\n':
	flag = TRUE;
	//stop = TRUE;
	//space = TRUE;

	break;
	*/

	 case '1' :
	flag = FALSE;
	menu_sys1();
	delay(20);

	puts("yes");
	delay(20);
	//stop = TRUE;

	break;

	case '2' :
	//puts (" regular memeber");
	flag = FALSE;
	//stop = TRUE;
	puts("no");
	menu_reader();
	break;

	case '3' :
	//puts ("instrustions");
	flag = FALSE;
	//stop = TRUE;
	puts("oh");
	instructions();
	break;


	case 'e':
	exit(1);
	break;


	default :
	flag = TRUE;
		//if(stop)
	//{
		puts("\ninvalid input, please try again");
		//stop = FALSE;

	//}




	};

} while (flag);
}



void instructions(void)
{
		system("clear");
	for (int i = 0 ; i<18 ; i++)
printf(YEL"\u287F\u287F\u287F");

puts(YEL"\n\u287F\u287F\u287F How to use \u287F\u287F\u287F ");

puts(YEL "Exit : e\nBack to Main menu : any other key, DON'T PRESS 'ENTER' "RESET);

//getchar(); // for enter
switch(getche())
{

case 'e':
exit(1);
break;

//default :
//main_menu();

}


}


void menu_sys1(void) {
//getchar();
system("clear");

	char buf[50] ; // pass from user
	char syspass[] = "AlexUni99";

	puts("\u287F\u287F System\nEnter Password (case-sesitive):");
		fgets(buf, sizeof buf, stdin);
		int i;
		char userPass[10];

	for(i=0 ; i<9 ; i++)
	userPass[i] = buf[i];
	buf[10] = '\0';


		bool flag_b = TRUE;

		while(strcmp(userPass,syspass) !=0 && flag_b )
		{
			puts("Wrong Password : Try again (t) , Exit (e) , or any other key for main menu");

			switch(getche())
			{
			 case 't' :
			 	puts("\n\u287F\u287F System\nEnter Password (case-sesitive):");
			 	//getchar();

				fgets(buf, sizeof buf, stdin);
				for(i=0 ; i<9 ; i++)
				userPass[i] = buf[i];
				buf[10] = '\0';

				flag_b = TRUE;
				break;

			/*case 'm' :
				//break the loop

				flag_b = FALSE;

				break;
				*/
			case 'e' :
			exit(1);
			break;

			default :
			flag_b = FALSE;
			main_menu();

			}




			}

	if (strcmp(userPass,syspass) == 0)
	{ puts("true");
	delay(15);

		menu_sys2();

	}


};

void menu_sys2(void)
{
system("clear");

int i ;
for (i = 0 ; i<18 ; i++)
printf("\u287F\u287F\u287F");

puts("\n\t \u287F\u287F\u287F Select an Action :\u287F\u287F\u287F \n"
"\t \u287F\u287F\u287F Book Management \u287F\u287F\u287F\n\t"
"\u278A Add New Book\n\t\u278B Add New Copy\n\t\u278C Delete Book\n\t\u278D Search a Book");

for (i = 0 ; i<18 ; i++)
printf("\u287F\u287F\u287F");

puts("\n\t\u287F\u287F\u287F Memeber Management \u287F\u287F\u287F\t");

puts ("\t\u278E Search a Memeber");
puts ("\t\u278F Add Memeber");
//u287F
printf(RED "\t\u2790 Suspend a Member\n\t\u2791 Remove a Member\t\n" RESET);


for (i = 0 ; i<18 ; i++)
printf("\u287F\u287F\u287F");

puts("\n\t\u287F\u287F\u287F Get Reports \u287F\u287F\u287F\n\t\u2792 Overdue Books ");

//just to see it
delay(10);
};

void menu_reader(void)
{
	system("clear");
	for (int i = 0 ; i<18; i++)

printf("\u287F\u287F\u287F");
 puts("\n\t \u287F\u287F\u287F Readers Zone \u287F\u287F\u287F \n\t \u278A Sign in\n\t \u278B Sign up\n\t \u278C Search");

	for (int i = 0 ; i<18; i++)

printf("\u287F\u287F\u287F");

puts("");


	bool flagR = FALSE;

	//getchar(); //enter
	do {

	switch (getche())
	{
		case '1' :
		//menu_login();
		flagR = FALSE;
		break;

		case '2' :
		menu_reg();
		flagR = FALSE;
		break;

		case '3' :
		menu_search();
		flagR = FALSE;
		break;

		default :
		puts("Invalid input");
		flagR = TRUE;

	}




	}while(flagR);





}


void menu_reg (void)
{
	system("clear");
	for (int i = 0 ; i<18; i++)

   printf("\u287F\u287F\u287F");

   puts("");

	puts("\u287F\u287F\u287F Registration \u287F\u287F\u287F");
	puts("\u287F\u287F Enter First Name");
	puts("\u287F\u287F Enter Last Name");
	puts("\u287F\u287F Enter Address [building - street - city]");
	puts("\u287F\u287F Enter building");
	puts("\u287F\u287F Enter Street");
	puts("\u287F\u287F Enter City");

	puts("\u287F\u287F Enter phone number");
	puts("\u287F\u287F Enter Age");
	puts("\u287F\u287F Enter Email address");
	puts("\u287F\u287F Press any key to continue registration ...");


	delay(15);
	// if or loop to check validity

	// back to menu_reader

	menu_reader();



	// id_should be generated by another function



	}


void menu_login(void)
{
	system("clear");
	for (int i = 0 ; i<18; i++)

printf("\u287F\u287F\u287F");


puts("\n\u287F Enter ID :");

// check from file
// if exists :

puts ("\u287F\u287F Enter password :");

//if both true --> menu_mem(); false : indicate invalid inputs

// just for test :

 delay(10);
 menu_mem();


}

void menu_mem(void)
{
bool flagm = TRUE;
system("clear");
for (int i = 0 ; i<18; i++)

printf("\u287F\u287F\u287F");

	puts("\n\u287F\u287F\u287F Member Page : \u287F\u287F\u287F");
	puts("\t\u278A Title\n\t\u278B Search\n\t\u278C Borrow\n\t\u278D Return\n\t\u278E Leave (delete account)");

	do {

		switch (getche())
		{

			case '1':
			case '2' :
			flagm = FALSE;
			puts(" unavailable now :)");
			break;


			case '3' :
			flagm = FALSE;
			menu_search();
			break;


			case 'm' :
			flagm = FALSE;


			default :
			puts("invalid input in menu_mem");

		}



		} while(flagm);
	delay(10);

}


void menu_search(void)
{

	system("clear");
	for (int i = 0 ; i<18; i++)

	printf("\u287F\u287F\u287F");
	puts("");

	puts("\u287F\u287F\u287F Search By : \u287F\u287F\u287F");
	puts("\t\u278A Title\n\t\u278B Author\n\t\u278C ISBN\n\t\u278D Category");

	delay(12);
	menu_mem();


}


void delay(int t)
{

	int i , j;
for(i=0 ; i<t*1000 ; i++) //delay
for(j=0 ; j< t*1000; j++)
{}

}


mainTry.c

Open with




