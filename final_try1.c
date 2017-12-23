#define BOOKTILTE 64
#define NAME 32
#define STRUCTSIZE 99

#include <stdio.h>
#include <stdlib.h>
#include "coniox.h"
#include <curses.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"



typedef struct date {

int day, month, year;


} date;

typedef struct tm tm;



typedef struct book {
    char title[BOOKTILTE];
    char author[NAME];
    char ISBN[18]; // isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
    char publisher[NAME];
    char category[NAME];
    int av; // аvailability
    tm date_pub1;
    //date date_pub; //time_m
    int popularity;
    //borrow -> copies

}book;

// declare books array  :
book books[STRUCTSIZE];

typedef struct borrow // borrow book
{
   
    int id; // id tany 5als
    char ISBN[18]; // ISBN tany 5als \\// isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
    tm date_issued;
    tm date_due;
    tm date_returned;
    //date date_due;
    //date date_issue;
    
    
    //time_t 
    //int book.ISBN;

} borrow;

// declare borrows array  :
 borrow borrows[STRUCTSIZE];
 

typedef struct address
{
 int building;
 char city[16];
 char street[16];
}address;



typedef struct  member {

    char name[2][NAME]; 
    int id;
    address addressmem; 
    tm dateofbirth; 
    date dateofbirth1;
    char phone[12];
    char email[30];
    char pass[13];
    int borrowav;
    int age;
}member;



// declare members array  :
member members[STRUCTSIZE];

void delay(int t);
void lowercase(char *str);
//bool isstrdigit (char * str);
void main_menu(void);
void menu_sys1(void);
void instructions(void);
void menu_sys2(void);
void menu_reader(void);
void menu_reg (void);
void menu_mem(void);
void menu_search(void);
void addbook(void);
void addmember(void);

void save_in_file(void);
void read_from_file(void);
int search_in_book_R(char* str , int mode);
void search_in_book(char* str , int mode);
void addcopy(void);
bool isstrdigit (char * str);
bool isstralpha (char * str);
bool isletter(int ch);
bool checkemail(char* str);
bool checkdatem(int day , int month , int year);
bool checkdateb(int day , int month , int year);
void read_from_file3(void);
void save_in_file3(void);
void save_in_file2(void);
bool checkdate(int day , int month , int year);
bool check_string(char*str);
int search_id(int id);
void removebook(void);
void search_member(void);
void removemember(void);

void read_from_file2(void);
//void search_in_book(book books[] , char* str , int mode);
// GLOBAAAAL 
int struct_index1 = -1; // book
int struct_index2 = -1; // member
int struct_index3 = -1; // borrow
int id=0;
int indx[STRUCTSIZE] = {0}; //matches in search_in_book_R
int yeear = 2017;
int id_hold;

int main()
{


time_t t = time(NULL);
tm tim = *localtime(&t);

yeear = tim.tm_year + 1900; // now global has current year

read_from_file();
read_from_file2();

removemember();
//search_member();
delay(50);
//removebook();
//menu_login();
//read_from_file3();

//addbook();

 //menu_login();
  //addmember();
  //delay(50);
	
  //addbook();
  //char bufs[20];
  
  
  
  
   

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
	//puts ("instructions");
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
printf(RED "\t\u2790 Remove a Member\t\n" RESET);


for (i = 0 ; i<18 ; i++)
printf("\u287F\u287F\u287F");

puts("\n\t\u287F\u287F\u287F Get Reports \u287F\u287F\u287F\n\t\u2792 Overdue Books ");

for (i = 0 ; i<18 ; i++)
printf("\u287F\u287F\u287F");
printf("\n");

// int choice;
	bool flag;
	
	//char buffer[18];
	//char choicey[16];
	
	
	do{ 
	
	puts("\nSelect your choice");
	switch (getche())

{
	
	case '1' : 
			system("clear");
			
			addbook();
			//getchar();
			//choice = 1;
			flag = FALSE;
			break;
	case '2' : 
			system("clear");
			addcopy();
			//choice = 2;
			flag = FALSE;
			break;
	case '3' :
			system("clear");
			
			//choice = 3;
			flag = FALSE;
			break;
	case '4' :
			system("clear");
			puts("search :");
			menu_search();
			//choice = 4;
			flag = FALSE;
			break;
	case '5':
			system("clear");
			search_member();
			//choice = 5;
			flag = FALSE;
			break;
	case '6':
			system("clear");
			addmember();
			//choice = 5;
			flag = FALSE;
			break;
	 
	default :
			flag = TRUE;	
		// here go back somewhere
};
	
} while (flag);
	
	
	
delay(1000);
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

char buffer[64];
int fid;

puts("\n\u287F Enter ID :");
fgets(buffer,sizeof(buffer),stdin);

// search for id in member structure 
fid = search_id(atoi(buffer));

if( fid == -1)
puts("Id NOT FOUND!");
else
// get password --> you have index
{
	//strcpy(passgot , members[fid].pass);
 puts("Enter password");
 fgets(buffer, sizeof(buffer),stdin);
 int len = strlen(buffer)-1;
 buffer[len] = '\0';
 if( strcmp(buffer,members[fid].pass)==0)
 menu_mem();
 id_hold = members[fid].id;

}

	
}

void menu_mem(void)
{
bool flagm = TRUE;
system("clear");
for (int i = 0 ; i<18; i++)

printf("\u287F\u287F\u287F");

	puts("\n\u287F\u287F\u287F Member Page : \u287F\u287F\u287F");
	puts("\t\u278A Search\n\t\u278B Borrow\n\t\u278C Return\n\t\u278D Sign out");

	do {
		
		switch (getche())
		{
		
			case '1':
			menu_search();
			flagm = FALSE;
			break;
			case '2' :
			flagm = FALSE;
			
			break;
		
			
			case '3' :
			flagm = FALSE;
			menu_search();
			break;
			
			case '4' :
			flagm = FALSE;
			id_hold = 0;
			//end of loop main_menu again
			break;
			
			case 'm' :
			flagm = FALSE;
			
			
			default :
			puts("invalid input in menu_mem");
			
		}
		
		
		
		} while(flagm);
	delay(20);
	
}


void menu_search(void)
{
	
	system("clear");
	for (int i = 0 ; i<18; i++)

	printf("\u287F\u287F\u287F");
	puts("");

	puts("\u287F\u287F\u287F Search By : \u287F\u287F\u287F");
	puts("\t\u278A ISBN\n\t\u278B Title\n\t\u278C Author\n\t\u278D Category\n\t\u278E Publisher");
	
	int choice;
	bool flag;
	
	char buffer[18];
	//char choicey[16];
	
	do{ 
	
	puts("\nSelect your choice");
	switch (getche())

{
	
	case '1' : 
			system("clear");
			puts("Enter ISBN :");
			choice = 1;
			flag = FALSE;
			break;
	case '2' : 
			system("clear");
			puts("Enter Title or partial title :");
			choice = 2;
			flag = FALSE;
			break;
	case '3' :
			system("clear");
			puts("Enter Author name or partial name :");
			choice = 3;
			flag = FALSE;
			break;
	case '4' :
			system("clear");
			puts("Enter Category :");
			choice = 4;
			flag = FALSE;
			break;
	case '5':
			system("clear");
			puts("Enter Publisher name or partial :");
			choice = 5;
			flag = FALSE;
			break;
	 
	default :
			flag = TRUE;	
		// here go back somewhere
};
	
} while (flag);

	
	fgets(buffer , 18,stdin);
	search_in_book(buffer ,choice); 
	
	delay(10);
	//menu_mem();
	
	
}


void delay(int t)
{
	
	int i , j;
for(i=0 ; i<t*1000 ; i++) //delay
for(j=0 ; j< t*1000; j++)
{}
	
}

void lowercase(char *str)
{
	
	
	int i=0;
	while(str[i])
	{
		str[i]=tolower(str[i]);
		i++;
		}
	
	
	}


void addbook(void)
{
	struct_index1++;
	
char buffer[64];
int len;
/*puts("Enter Book Title :");
fgets(books[struct_index1].ISBN,64,stdin);

buffer[len] = '\0';
//gets(books.title);

lowercase(buffer);

strcpy(books[struct_index1].title,buffer);

*/

puts("Enter Title  :");
fgets(buffer,sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
lowercase(buffer);

strcpy(books[struct_index1].title,buffer);

puts("Enter Author name :");
fgets(buffer,sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
lowercase(buffer);

strcpy(books[struct_index1].author,buffer);
//printf("\n%s\n",books[struct_index1].author);

puts("Enter ISBN (using standard)");
fgets(buffer,18,stdin);
len = strlen(buffer)-1;
lowercase(buffer);


int fisbn;

 fisbn = search_in_book_R(buffer , 1);
 //printf("isbnf = %d",fisbn);
 if (fisbn)
 {
	puts(" ISBN exists ... Back to main menu");
	struct_index1--;
	delay(50);
} else
{
buffer[len] = '\0';
strcpy(books[struct_index1].ISBN,buffer);
//gets(books.ISBN);
puts("Enter Publisher name:");
fgets(buffer,sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
lowercase(buffer);

strcpy(books[struct_index1].publisher,buffer);

//gets(books.publisher);

puts("Enter category");
fgets(buffer,sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
lowercase(buffer);

strcpy(books[struct_index1].category,buffer);



bool flag_av = TRUE;
do {puts("Enter number of books available");
fgets(buffer,sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flag_av = isstrdigit(buffer);

}while(!flag_av);
int av;
av = atoi(buffer);
books[struct_index1].av = av;

//scanf("%d",&books.av);
int d,m,y;
char buf1[32] , buf2[32];
bool flagd , flagm , flagy , flagg = TRUE;
do {
puts("Enter date of publication .. if any part is unkown just write 0");
puts("day :");
fgets(buffer, sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flagd = isstrdigit(buffer);
printf("flagd = %d\n",flagd);

puts("Month :");
fgets(buf1, sizeof(buf1),stdin);
len = strlen(buf1)-1;
buf1[len] = '\0';
flagm = isstrdigit(buf1);
//printf("flagd = %d\n",flagm);


puts("Year :");
fgets(buf2, sizeof(buf2),stdin);
len = strlen(buf2)-1;
buf2[len] = '\0';
flagy = isstrdigit(buf2);
//printf("flagd = %d\n",flagy);

if (flagd && flagm && flagy)
{
	d = atoi(buffer);
	m = atoi(buf1);
	y = atoi(buf2);
	//printf("d = %d , m = %d , y = %d\n",d,m,y);
	flagg = checkdateb(d+1,m+1,y+1);
	//printf("flagg = %d\n",flagg);

}

} while (!flagg);

books[struct_index1].date_pub1.tm_mday = d;
books[struct_index1].date_pub1.tm_mon = m;
books[struct_index1].date_pub1.tm_year = y;

//fgets(buffer,2,stdin);
//strcpy(books[struct_index].category,buffer);

/*scanf("%d/%d/%d",&books[struct_index1].date_pub.day,	
&books[struct_index1].date_pub.month,&books[struct_index1].date_pub.year);
getchar(); // bad scanf
*/

puts("Would you like to save?");
bool flag;
do 
{
	switch (getche())
	case 'y' : case 'Y' :
	save_in_file();
	
	puts("\nsaved :)");
	delay(10);
	flag = FALSE;
	break;
	
} while (flag);


}


menu_sys2();
}


void addmember(void)
{

struct_index2++;
char buffer[64];
int len;


do{
puts("Enter First Name:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
//flagfn = isstralpha(buffer);
} while(!check_string(buffer));

strcpy(members[struct_index2].name[0],buffer);
//printf("\n %s\n",members[struct_index2].name[0]);

do
{
puts("Enter Last Name:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
//flagln = isstralpha(buffer);
} while(!check_string(buffer));

strcpy(members[struct_index2].name[1],buffer);
//printf("\n %s\n",members[struct_index2].name[1]);

//bool flag_bl = TRUE;

do {
	
puts("Enter building no:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';

} while(!isstrdigit(buffer));


int buildno;
buildno = atoi(buffer);
members[struct_index2].addressmem.building = buildno;



puts("Enter Street:");
fgets(buffer,NAME/2,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
strcpy(members[struct_index2].addressmem.street , buffer); 


puts("Enter city:");
fgets(buffer,NAME/2,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
strcpy(members[struct_index2].addressmem.city , buffer); 


/*int d,m,y;
char buf1[32] , buf2[32];
bool flagd , flagm , flagy , flagg = TRUE;
*/
/*
do {
puts("Enter date of birth : ");
puts("day :");
fgets(buffer, sizeof(buffer),stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flagd = isstrdigit(buffer);
//printf("flagd = %d\n",flagd);

puts("Month :");
fgets(buf1, sizeof(buf1),stdin);
len = strlen(buf1)-1;
buf1[len] = '\0';
flagm = isstrdigit(buf1);
//printf("flagd = %d\n",flagm);


puts("Year :");
fgets(buf2, sizeof(buf2),stdin);
len = strlen(buf2)-1;
buf2[len] = '\0';
flagy = isstrdigit(buf2);
//printf("flagd = %d\n",flagy);

if (flagd && flagm && flagy)
{
	d = atoi(buffer);
	m = atoi(buf1);
	y = atoi(buf2);
	//printf("d = %d , m = %d , y = %d\n",d,m,y);
	flagg = checkdate(d,m,y);
	//printf("flagg = %d\n",flagg);

}

} while (!flagg);

members[struct_index2].dateofbirth.tm_mday = d;
members[struct_index2].dateofbirth.tm_mon = m;
members[struct_index2].dateofbirth.tm_year = y; // just if you wish to calc age

*/
/* printf("%d/%d/%d",members[struct_index1].dateofbirth.tm_mday = d,
members[struct_index1].dateofbirth.tm_mon = m,
members[struct_index1].dateofbirth.tm_year = y);
*/

/* 
members[struct_index2].dateofbirth.tm_sec = 0;
members[struct_index2].dateofbirth.tm_min = 0;
members[struct_index2].dateofbirth.tm_hour = 0;
*/
bool flag_age =TRUE;
int age = 0;

do {
puts("Enter your age:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flag_age = isstrdigit(buffer);
if (flag_age)
age = atoi(buffer);

} while(age < 5);

members[struct_index2].age = age;

bool flag_ph = TRUE;
//not working! {solved by getchar() }
do {
puts("Enter phone number:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flag_ph = isstrdigit(buffer);
//printf("flag = %d",flag);
} while(!flag_ph || (strlen(buffer)<= 6));

strcpy(members[struct_index2].phone , buffer); 

//printf("%s",members[struct_index2].addressmem.street);

bool flage;
do {
	puts("Enter email address : aaa@bbb.com");
	fgets(buffer,NAME,stdin);
	flage = checkemail(buffer);
} while(!flage);

len = strlen(buffer)-1;
buffer[len] = '\0';
strcpy(members[struct_index2].email , buffer); 

//rintf("%s",members[struct_index2].email);
//gets(members.email);
char pass[64];
do{
system("clear");
printf("Finally ,enter the password (maximum 13) :\n");
fgets(buffer , 64, stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';

puts(buffer);
//printf("length = %d",length);
puts("Confirm your pass");

fgets(pass , 64 , stdin);
len = strlen(pass)-1;
pass[len] = '\0';

//length = strlen(pass);

//printf("length = %d",length);
//puts(pass);
}while(!((strcmp(buffer , pass) ==0) && (strlen(pass) <=14)));

printf("\nEqual and accepted\n"); 
//strcpy(pass , buffer);
strcpy(members[struct_index2].pass, pass); 

puts("Would you like to confirm registration? yes = y||Y , no = otherwise");

bool flag_reg;
do 
{
	switch (getche())
	{case 'y' : case 'Y' :
		id++;
		members[struct_index2].id = id;
		
	//save_in_file();
	save_in_file2();
	
	puts("\nsaved :)");
	system("clear");
	printf(YEL "\nYour id is :" RESET);
	printf(" %d\n",id);
	delay(10);
	flag_reg = FALSE;
	break;
	
	/*default:
	id--;
	struct_index2--;*/
}
	
} while (flag_reg);


    
}


/*void search_in_book(book books[] , char* str , int mode){
  
  
  for(int i=0; i < STRUCTSIZE; i++){
  if(mode ==1)
  
    {
    if(strcmp(books[i].ISBN , str)==0){
        printf("%s\n",books[i].ISBN);
    }
}
    
  }
 
}

*/
void search_in_book(char* str , int mode){
   
  // printf("\n%c",str[1]);
   int len = strlen(str)-1;
   str[len] = '\0';
	int found =0;
   char *partial;
   
   //
 
  for(int i=0; i <= struct_index1; i++){
  
 
  //printf("%s\n", books[0].title);
  switch (mode)
  {
	 case 1 : // isbn
		//puts("case 1 entered");
		if(strcmp(books[i].ISBN , str) == 0){
			//puts("if entered");
        printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub1.tm_mday , books[i].date_pub1.tm_mon, books[i].date_pub1.tm_year);
        
        found++;
    }
		break;
		
	case 2: //title
	
	partial = strstr(books[i].title,str); 
	if(partial)
	{	
	 printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub1.tm_mday , books[i].date_pub1.tm_mon, books[i].date_pub1.tm_year);
		found++;
	}
	  break;
	  
	  
	  case 3: //author
	
	 partial = strstr(books[i].author,str); 
	
	if(partial)
	{	
	  printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub1.tm_mday , books[i].date_pub1.tm_mon, books[i].date_pub1.tm_year);
		found++; }
	  break;
	  
	  
	  case 4: //category
	
	 partial = strstr(books[i].category,str); 
	
	if(partial)
	{
	  printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
       books[i].date_pub1.tm_mday , books[i].date_pub1.tm_mon, books[i].date_pub1.tm_year);
		found++; 
	}
	  break;
	  
	  
	  case 5: //publisher
	
	 partial = strstr(books[i].publisher,str); 
	
	if(partial)
		
	 { printf("%s\3t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub1.tm_mday , books[i].date_pub1.tm_mon, books[i].date_pub1.tm_year);
		found++; }
	  break;
	} // end of switch
  
  
    
  } //end of for
  
  //printf("Number of matches = %d",found);
 
} // end of function
 
// void play(int n, int m, Cell array[n][m])


int search_in_book_R(char* str , int mode){
   
   int len = strlen(str)-1;
   str[len] = '\0';
	int found =0;
   char *partial;
 
  for(int i=0; i <= STRUCTSIZE; i++){
  
 
  switch (mode)
  {
	 case 1 : // isbn
		
		if(strcmp(books[i].ISBN , str) == 0){
        indx[found++] = i;
        //printf("\ni = %d" ,i);
        //printf("\n indx[found] = %d", indx[found]);
        //found++;
    }
		break;
		
	case 2: //title
	
	partial = strstr(books[i].title,str); 
	if(partial)
	{	
	 /*printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
        */
        indx[found++] = i;
		//found++;
	}
	  break;
	  
	  
	  case 3: //author
	
	 partial = strstr(books[i].author,str); 
	
	if(partial)
	{	
	  /*printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		*/
		
		indx[found++] = i;
		//found++;
		 }
	  break;
	  
	  
	  case 4: //category
	
	 partial = strstr(books[i].category,str); 
	
	if(partial)
	{
	  /*printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		*/
		indx[found++] = i;
		//found++; 
	}
	  break;
	  
	  
	  case 5: //publisher
	
	 partial = strstr(books[i].publisher,str); 
	
	if(partial)
		
	 { /*printf("%s\3t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		*/
		
		indx[found++] = i;
		//found++; 
		}
	  break;
	} // end of switch
  
  
    
  } //end of for
  
	
	
	return found;
} // end of function


/*void 
 * search_in_book(char* str , int mode)
{
 // search in books structure
 switch (mode)
 {
	 int i =0;
	 case 1: // isbn
	 for( i=0 ; i< 128 ; i++)
	 if(strcmp(books[i].ISBN, str)==0) // full search
	 puts("done");
	 printf("\nfound\n%s\t%s\t%s\t%s",
	 books[i].title,books[i].author,
	 books[i].category,books[i].publisher);
	 break;
	 
	 
	 
	 
	}	

	
	
	
}
*/



 void save_in_file(void)
{
	
FILE *fp1;

	//book
   fp1 = fopen ("book.csv", "w");
   int i ;
   for( i = 0 ; i <= struct_index1 ; i++)
   fprintf(fp1, "%s,%s,%s,%s,%s,%d,%d-%d-%d,%d\n",
    books[i].title,books[i].author, books[i].ISBN,books[i].publisher,
    books[i].category, books[i].av,books[i].date_pub1.tm_mday,books[i].date_pub1.tm_mon,
    books[i].date_pub1.tm_year,books[i].popularity);
   


   fclose(fp1);
   
 
  
  
}

void save_in_file3(void)
{
	
FILE *fp1;

	//book
   fp1 = fopen ("members.csv", "w");
   int i ;
   for( i = 0 ; i <= struct_index1 ; i++)
   fprintf(fp1, "%s,%s,%s,%s,%s,%d,%d-%d-%d,%d\n",
    books[i].title,books[i].author, books[i].ISBN,books[i].publisher,
    books[i].category, books[i].av,books[i].date_pub1.tm_mday,books[i].date_pub1.tm_mon,
    books[i].date_pub1.tm_year,books[i].popularity);
   


   fclose(fp1);
   
 
  
  
}



void save_in_file2(void)
{
	
FILE *fp1;

	//borrow
   fp1 = fopen ("member.csv", "w");
   int i ;
   
   for( i = 0 ; i <= struct_index2 ; i++)
   fprintf(fp1, "%s,%s,%d,%s,%s,%d,%s,%s,%s,%d\n",
   members[i].name[0],members[i].name[1],
   members[i].addressmem.building,
   members[i].addressmem.street,
   members[i].addressmem.city,
   members[i].age,
   members[i].phone,
   members[i].email,
   members[i].pass,
   members[i].id
   );
    

   fclose(fp1);
   
 

  
 
}

void addcopy()
{
	char isbn[32];
	puts("Enter ISBN");
	fgets(isbn , sizeof(isbn), stdin);
	//int len = strlen(isbn)-1;
	//isbn[len] = '\0';
	
	int found = search_in_book_R(isbn , 1);
	if (!found)
	puts("Book Not Found!");
	else
	{
		bool flag = FALSE;
		char buffer[15];
		do {
			puts("Enter # of copies");
			fgets(buffer , sizeof(buffer),stdin);
			flag = isstrdigit (buffer);
		}while (!flag);
			
			int copies;
			copies = atoi(buffer);
			books[indx[0]].av += copies;
			puts("Copies added :) , back to main menu");
			delay(10);
			save_in_file();
		
	}
}


void read_from_file(void)
{

// book
FILE *fp1 ;

fp1 = fopen("book.csv", "r") ; 

int counter =0;


while(!feof(fp1))
	{
		fscanf(fp1, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d-%d-%d,%d\n",
		books[counter].title, books[counter].author, books[counter].ISBN,
		books[counter].publisher,books[counter].category,&books[counter].av,
		&books[counter].date_pub1.tm_mday,&books[counter].date_pub1.tm_mon,&books[counter].date_pub1.tm_year
		,&books[counter].popularity
		);
		
	
		counter++;
		//puts("reads");
		
	}
	
	//printf("counter = %d\n" ,counter);
	struct_index1 = counter-1;
	printf("\nstruct_index = %d\n" ,struct_index1);
	
	
	
	//delay(10);
	
fclose(fp1);


}


void read_from_file3(void)
{

// book
FILE *fp1 ;

fp1 = fopen("member.csv", "r") ; 

int counter =0;


while(!feof(fp1))
	{
		fscanf(fp1, "%[^,],%[^,],%d,%[^,],%[^,],%d-%d-%d,%s,%s,%[^,],%d\n",
		members[counter].name[0],
		members[counter].name[1],
		&members[counter].addressmem.building,
		members[counter].addressmem.street,
		members[counter].addressmem.city,
		&members[counter].dateofbirth.tm_mday,
		&members[counter].dateofbirth.tm_mon,
		&members[counter].dateofbirth.tm_year,
		members[counter].phone,
		members[counter].email,
		members[counter].pass,
		&members[counter].id
		);
		
		
	
		counter++;
		//puts("reads");
		
	}
	
	//printf("counter = %d\n" ,counter);
	struct_index2 = counter-1;
	printf("\nstruct_index = %d\n" ,struct_index2);
	
	
	
	//delay(10);
	
fclose(fp1);


}


void read_from_file2(void)
{

// book
FILE *fp2  ,*fpt;

int counter =0;

fp2 = fopen("member.csv", "r") ; 
fpt = fopen("member.csv", "r") ; 
char *token;
char line[100];
while(fgets(line, sizeof(line), fpt) != NULL)
	{
		
		
		token = strtok(line,",");
		strcpy(members[counter].name[0], token);
		//puts(token);
		//printf("%s,",members[counter].name[0]);
		
		token =  strtok(NULL,",");
		strcpy(members[counter].name[1], token);
		//printf("%s,",members[counter].name[1]);
		//puts(token);
		
		token =  strtok(NULL,",");
		members[counter].addressmem.building = atoi(token);
		//strcpy(members[counter].name[1], token);
		//printf("%d\n",atoi(token));
		
		token =  strtok(NULL,",");
		strcpy(members[counter].addressmem.street, token);
		//puts(token);
		
		token =  strtok(NULL,",");
		strcpy(members[counter].addressmem.city, token);
		//puts(token);
		
		token =  strtok(NULL,",");
		members[counter].age = atoi(token);
		//printf("%d\n",atoi(token));
		
		token =  strtok(NULL,",");
		strcpy(members[counter].phone, token);
		//puts(token);
		
		
		token =  strtok(NULL,",");
		strcpy(members[counter].email, token);
		//puts(token);
		
		
		token =  strtok(NULL,",");
		strcpy(members[counter].pass, token);
		//printf("%s,",members[counter].pass);
		//puts(token);
		
		token =  strtok(NULL,"\n");
		members[counter].id = atoi(token);
		//printf("%d,",members[counter].id);
		//printf("%d\n",atoi(token));
		
		/*sscanf( temp, "%[^,],%[^,],%d,%[^,],%[^,],%d,%s,%s,%[^,],%d",
		members[counter].name[0],
		members[counter].name[1],
		&members[counter].addressmem.building,
		members[counter].addressmem.street,
		members[counter].addressmem.city,
		&members[counter].age,
		//&members[counter].dateofbirth.tm_mday,
		//&members[counter].dateofbirth.tm_mon,
		//&members[counter].dateofbirth.tm_year,
		members[counter].phone,
		members[counter].email,
		members[counter].pass,&members[counter].id);
		*/
		
		//printf("%s",temp);
		
		/*fscanf(fp2, "%[^,],%[^,],%d,%[^,],%[^,],%d,%s",
		members[counter].name[0],
		members[counter].name[1],
		&members[counter].addressmem.building,
		members[counter].addressmem.street,
		members[counter].addressmem.city,
		&members[counter].age,
		//&members[counter].dateofbirth.tm_mday,
		//&members[counter].dateofbirth.tm_mon,
		//&members[counter].dateofbirth.tm_year,
		members[counter].phone
		//members[counter].email,
		//members[counter].pass,&members[counter].id
		);
		
		fscanf(fp2, "%s,%d", members[counter].pass,&members[counter].id);
		*/
	
		
		//printf("pass = %s , id = %d\n",members[counter].pass,members[counter].id);
		
   
   
   
		
	
		
		counter++;
		id++;
		puts("reads");
		
	}
	
	//printf("%s",temp);
	struct_index2 = counter-1;
	printf("\nstruct_index2 = %d\n" ,struct_index2);
	
fclose(fpt);
fclose(fp2);
delay(10);
}
bool checkdateb(int day , int month , int year)
 {
 
 bool flag;	


if(year >=1900 && year<= yeear)
    {
        //check month
        if( month >=1 &&  month <=12)
        {
            //check days
            if((day >=1 && day <=31) 
            && (month ==1 || month ==3 || month ==5
             || month ==7 || month ==8 || month ==10 || month ==12))
                flag = TRUE;
            else if((day >=1 && day <=30) && (month ==4 ||
             month ==6 || month ==9 || month ==11))
                flag = TRUE;
            else if((day >=1 && day <=28) && (month ==2))
               flag = TRUE;
            else if(day ==29 && month ==2 && (year%400==0 ||
            (year%4==0 && year%100!=0)))
                flag = TRUE;
            else
                flag = FALSE;
        }
        else
        {
           flag = FALSE;
        }
    }
    else
    {
        flag = FALSE;
    }	
	
	
	
	return flag;
}

	

bool checkdatem(int day , int month , int year)
 {
 
 bool flagv = FALSE;
 //int year , month , day ;
 if( year >=1940 && year <= yeear)
    {
        //check month
        if( month >=1 &&  month <=12)
        {
            //check days
            if((day >=1 && day <=31) 
            && (month ==1 || month ==3 || month ==5
             || month ==7 || month ==8 || month ==10 || month ==12))
             flagv = TRUE;
               
             else if((day >=1 && day <=30) && (month ==4 ||
             month ==6 || month ==9 || month ==11))
             
				 flagv = TRUE;
				
			
                
            else if((day >=1 && day <=28) && (month ==2))
				 flagv = TRUE;
				
			
            else if(day ==29 && month ==2 && (year%400==0 ||
            (year%4==0 && year%100!=0)))
               
				 flagv = TRUE;
			
            else
                flagv = FALSE;
                
        }
        else
        {
            flagv = FALSE;
            
        }
    }
    else
    {
       flagv = FALSE;
                
    }
    
    return flagv;
}


bool checkdate(int day , int month , int year)
{
	
bool flag;	


if(year >=1900 && year<= yeear)
    {
        //check month
        if( month >=1 &&  month <=12)
        {
            //check days
            if((day >=1 && day <=31) 
            && (month ==1 || month ==3 || month ==5
             || month ==7 || month ==8 || month ==10 || month ==12))
                flag = TRUE;
            else if((day >=1 && day <=30) && (month ==4 ||
             month ==6 || month ==9 || month ==11))
                flag = TRUE;
            else if((day >=1 && day <=28) && (month ==2))
               flag = TRUE;
            else if(day ==29 && month ==2 && (year%400==0 ||
            (year%4==0 && year%100!=0)))
                flag = TRUE;
            else
                flag = FALSE;
        }
        else
        {
           flag = FALSE;
        }
    }
    else
    {
        flag = FALSE;
    }	
	
	
	
	return flag;
}

bool checkemail(char* str)
{
	
int flag1 = FALSE , flag2 = FALSE;
int atp=-1;
int len , i;

len = strlen(str)-1;

 if (str[0] != '@')
 {
	for(i=0 ; i<len ; i++)
	if (str[i] == '@')
		{atp = i;  // index of @ got
		flag1 = TRUE;
		break;
		}
	if (flag1 == 1)
	{for(i=atp; i<len-1 ; i++)
	if (str[i] == '.')
		{
		flag2 = TRUE;
		break;
	
		}
	}
 }
 
 //printf("flag 1 = %d , flag2 =%d",flag1, flag2);

	return flag1*flag2;
	
	
}


	
bool isstralpha (char * str)
{
		int len = strlen(str)-1;
		int i = 0;
		bool flag = TRUE;
		
		for (i=0 ; i<len ; i++)
		
			
			while (!(str[i] <= 'a' && str[i] >='z' ) || (str[i] <= 'A' && str[i] >= 'Z'))
			{	
				return FALSE;
				break;
			}
				
		
		
		
		
	
		return flag;
	
}

bool isletter(int ch)
{
	if ( (65 <= ch &&  ch <= 90) || (97 <= ch &&  ch <= 122))
	return TRUE;	
	else
	return FALSE;
}

bool isstrdigit (char * str)
{
		int len = strlen(str)-1;
		int i = 0;
		int flag = 1;
		
		for (i=0 ; i<len ; i++)
		{
			flag = isdigit(str[i]);
			if(!flag)
			{return 0;
			break;
			}
		}
		
		return flag;
	
}

 int search_id(int id)
 {
	 int i;
	 int r;
	 for (i = 0 ; i<= struct_index2 ; i++)
	 if (members[i].id == id)
	 {
		 r = i;
		 return i;
	 break;
	}else
	r=-1;
	
	return  r;
 }


void removebook(void)
{
	int i;
	char isbn[32];
	puts("Enter ISBN");
	fgets(isbn , sizeof(isbn), stdin);
	
	int found = search_in_book_R(isbn , 1); // found is index
	if (!found)
	puts("Book Not Found!");
	else
	{
		puts("book removed");
		for (i=found ; i < struct_index1 ; i++)
		books[i] = books[i+1];
		struct_index1--;
		save_in_file();
	}
}


void removemember(void)
{
	int i;
	char id[32];
	puts("Enter Id");
	fgets(id , sizeof(id), stdin);
	
	int found=-1;
	
	for( i=0; i<=struct_index2 ; i++)
	if( members[i].id == atoi(id)) 
	{found = i;
	break;
	}
	if (found == -1)
	puts("Member Not Found!");
	else
	{
		
		// check if all book returned
		for (i=found ; i < struct_index2 ; i++)
		members[i] = members[i+1];
		struct_index2--;
		save_in_file2();
		puts("Member removed");
	}
}


void search_member(void)
{
		puts("Enter Id:");
		char id[32];
		fgets(id,sizeof(id),stdin);
		//printf("id entered : %d",atoi(id));
		int i;
		for (i=0; i <=struct_index2 ; i++)
		{
			if(members[i].id == atoi(id))
			
			{
				printf("%s %s\t %d,%s,%s\t%s\t%s\n",
				members[i].name[0],members[i].name[1],
				members[i].addressmem.building,members[i].addressmem.street,members[i].addressmem.city,
				members[i].phone,members[i].email);
				
				break;
			}else 
		puts("Id NOT FOUND");
		} 
	
	
}

int timediff(tm date1 , tm date2)
{
	int day_due , day_r;
	time_t issue , due ,returned;
	
	date1.tm_hour = 0;  date1.tm_min = 0;  date1.tm_sec = 0;	
	date2.tm_hour = 0;  date2.tm_min = 0;  date2.tm_sec = 0;
	
	day_due = difftime(due, issue)/(3600*24);
	day_r = difftime(returned , issue)/(3600*24);
	
	
}

void borrowbook(void)
{
	
	
	
}

bool check_string(char*str)
{
    int i,x; //return value
    for(i=0; str[i]!='\0' ;i++)
       { if(isalpha(str[i]))
          x=1; 
       else
       {x=0;
          break;
       }
       }
       return x;
}
