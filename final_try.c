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
    date date_pub; //time_m
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
    //date dateofbirth;
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
//void search_in_book(char* str , int mode);
void save_in_file(void);
void read_from_file(void);
int search_in_book_R(char* str , int mode);
void search_in_book(char* str , int mode);
void addcopy(char *isbn);
bool isstrdigit (char * str);
bool isstralpha (char * str);
bool isletter(int ch);
bool checkemail(char* str);
//void search_in_book(book books[] , char* str , int mode);
// GLOBAAAAL 
int struct_index1 = -1; // book
int struct_index2 = -1; // member
int struct_index3 = -1; // borrow
int id=0;
int indx[STRUCTSIZE] = {0}; //matches in search_in_book_R
int yeear;

int main()
{


time_t t = time(NULL);
tm tim = *localtime(&t);
yeear = tim.tm_year + 1900; // now global has current year
printf("current year = %d",yeear);
  read_from_file();
  
  
  char bufs[20];
  //fgets(bufs , sizeof(bufs),stdin);
  addmember();
  //addcopy(bufs);
  //search_in_book(bufs,1);
  
  
  
  //int len = search_in_book_R(bufs,1);
  //printf("len = %d\n");
  //int kk;
  //for (kk=0 ; kk < 5 ; kk++)
  //printf("index = %d\n",indx[kk]);
  
  //len = strlen(bufs)-1;
  //bufs[len] = '\0';
  //int found=0;
  //search_in_book(bufs , 1);
  
  addbook();
  
  //menu_search();
  //puts("Enter word to search");
  
  //found =  search_in_book_R(bufs , 2);

  
  //printf("found = %d" ,found);
  
  //char bufs[20];
  
  
  
  //char word[3] = "vi";
  //printf("%s\n",bufs);
  //search_in_book_R(bufs , 1,  found);
  //search_in_book(bufs , 1);
  //printf("found = %d",found);
  
  //printf("struct = %d",struct_index1);
   delay(20);
   
//addbook();

//menu_search();

//addmember();

//printf("\n%s\n",books[struct_index1].title);
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
printf(RED "\t\u2790 Suspend a Member\n\t\u2791 Remove a Member\t\n" RESET);


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
			menu_search();
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

	
	
/*	do{
	puts("Enter your choice number :");
	fgets(choicey , 18 , stdin);
	flag = isstrdigit(choicey);
	if(flag)
	choice = atoi(choicey);
	else 
	choice = 100;
	} while((choice < 0 || choice >5));
	//printf("choice = %d",choice);
	
	switch (choice)
	{
			case 1 : 
			puts("Enter ISBN :");
			break;
			case 2 : 
			puts("Enter Title or partial title :");
			break;
			case 3 :
			puts("Enter Author name or partial name :");
			break;
			case 4:
			puts("Enter Category :");
			break;
			case 5:
			puts("Enter Publisher name or partial :");
			break;
	}
*/
	
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
	
//FILE *f;
//f= fopen("booktemp.csv" ,"a");
char buffer[64];

puts("Enter Book Title :");
fgets(books[struct_index1].ISBN,18,stdin);
int len = strlen(buffer)-1;
buffer[len] = '\0';
//gets(books.title);

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
	delay(50);
} else
{
buffer[len] = '\0';
strcpy(books[struct_index1].ISBN,buffer);
//gets(books.ISBN);
puts("Enter Publisher name:");
fgets(buffer,sizeof(buffer)/2,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
lowercase(buffer);

strcpy(books[struct_index1].publisher,buffer);

//gets(books.publisher);

puts("Enter category");
fgets(buffer,sizeof(buffer)/2,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
lowercase(buffer);

strcpy(books[struct_index1].category,buffer);

//gets(books.category);
puts("Enter number of books available");
fgets(buffer,4,stdin);

int av;
av = atoi(buffer);
books[struct_index1].av = av;

//scanf("%d",&books.av);

puts("Enter date of publication .. enter day/month/year  e.g: 20/6/1998\n if any part is unkown just write 0");
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

bool flagfn = TRUE;
//isstralpha not working
do{ 
puts("Enter First Name:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flagfn = isstralpha(buffer);

}while(flagfn); 

strcpy(members[struct_index2].name[0],buffer);

bool flagln = TRUE;
do{
puts("Enter Last Name:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flagln = isstralpha(buffer);
}while(flagln);

strcpy(members[struct_index2].name[1],buffer);

id++;
members[struct_index2].id = id;

bool flag_bl = TRUE;

do {
	
puts("Enter building no:");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
flag_bl = isstrdigit(buffer);

} while(!flag_bl);


int buildno;
buildno = atoi(buffer);
members[struct_index2].addressmem.building = buildno;

puts("Enter street name :");
fgets(buffer,32,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
strcpy(members[struct_index2].addressmem.street , buffer); 


puts("Enter city:");
fgets(buffer,NAME/2,stdin);
len = strlen(buffer)-1;
buffer[len] = '\0';
strcpy(members[struct_index2].addressmem.city , buffer); 

int flag_age = FALSE;
int age=0;
puts("Enter you age :");
do {
	fgets(buffer,sizeof(buffer),stdin);
	len = strlen(buffer)-1;
	buffer[len] = '\0';
	flag_age = isstrdigit(buffer);
	
}while(flag_age);

age = atoi(buffer);
members[struct_index2].age = age;
/*scanf("%d/%d/%d",&members[struct_index2].dateofbirth.day,&members[struct_index2].dateofbirth.month,
&members[struct_index2].dateofbirth.year);
*/
//getchar();

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

strcpy(members[struct_index2].addressmem.street , buffer); 


//char *part1;
/*do
{
puts("Enter email address : aaa@bbb.com");
fgets(buffer,NAME,stdin);
part1 = strstr(buffer , "@");
}while(!part1 || (buffer[0] == '@'));
*/

bool flage;
do {
	puts("Enter email address : aaa@bbb.com");
	fgets(buffer,NAME,stdin);
	flage = checkemail(buffer);
} while(!flage);

len = strlen(buffer)-1;
buffer[len] = '\0';
strcpy(members[struct_index2].email , buffer); 


//gets(members.email);
char pass[64];
do{
system("clear");
printf("Finally ,enter the password (maximum 13) :\n");
fgets(buffer , 64, stdin);

int length = strlen(buffer);
puts(buffer);
//printf("length = %d",length);
puts("Confirm your pass");

fgets(pass , 64 , stdin);

//length = strlen(pass);

printf("length = %d",length);
//puts(pass);
}while(!((strcmp(buffer , pass) ==0) && (strlen(pass) <=14)));

printf("\nEqual and accepted"); 
//strcpy(pass , buffer);
strcpy(members[struct_index2].pass, pass); 



    
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
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
        
        found++;
    }
		break;
		
	case 2: //title
	
	partial = strstr(books[i].title,str); 
	if(partial)
	{	
	 printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		found++;
	}
	  break;
	  
	  
	  case 3: //author
	
	 partial = strstr(books[i].author,str); 
	
	if(partial)
	{	
	  printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		found++; }
	  break;
	  
	  
	  case 4: //category
	
	 partial = strstr(books[i].category,str); 
	
	if(partial)
	{
	  printf("%s\t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		found++; 
	}
	  break;
	  
	  
	  case 5: //publisher
	
	 partial = strstr(books[i].publisher,str); 
	
	if(partial)
		
	 { printf("%s\3t%s\t%s\t%s\t\t%d/%d/%d\n",books[i].title,
        books[i].author, books[i].category, books[i].publisher,
        books[i].date_pub.day , books[i].date_pub.month, books[i].date_pub.year);
		found++; }
	  break;
	} // end of switch
  
  
    
  } //end of for
  
  printf("Number of matches = %d",found);
 
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
  
	//printf("Number of matches = %d",*found);
	//found = 10;
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


/*void removebook();
{
    int ind,n,c;
    int indx;
    char buffer[32];
    fgets(buffer, sizeof(buffer),stdin);
    indx = search_in_book_R(buffer,1);
    //scanf("%d",&ind);//element to be removed
    if(indx > n)
        printf("ISBN is");
    else
    for(c=ind-1;c<n-1;c++)
        c[ind]=c[ind+1];
        //global iterator--
}

*/
 void save_in_file(void)
{
	
FILE * fp;

   fp = fopen ("book.csv", "w");
   int i ;
   for( i = 0 ; i <= struct_index1 ; i++)
   fprintf(fp, "%s,%s,%s,%s,%s,%d,%d,%d,%d,%d\n",
    books[i].title,books[i].author, books[i].ISBN,books[i].publisher,
    books[i].category, books[i].av,books[i].date_pub.day,books[i].date_pub.month,
    books[i].date_pub.year,books[i].popularity);
   
   fclose(fp);
 	
	
}

void addcopy(char *isbn)
{
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

FILE *fp = fopen("book.csv", "r") ; 
//int i =0;
//int len;
int counter =0;
//char sep[2] = ",";
//char *token;
//int av, pop , d , m,y;


while(!feof(fp))
	{
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d\n",
		books[counter].title, books[counter].author, books[counter].ISBN,
		books[counter].publisher,books[counter].category,&books[counter].av,
		&books[counter].date_pub.day,&books[counter].date_pub.month,&books[counter].date_pub.year
		,&books[counter].popularity
		);
		
		
		//final_try.c:1112:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 9 has type ‘int *’ [-Wformat=]
		/*printf("%s,%s,%s,%s,%s,%d,%d,%d,%d,%d\n",
		books[counter].title, books[counter].author, books[counter].ISBN,
		books[counter].publisher,books[counter].category,books[counter].av,
		books[counter].date_pub.day,&books[counter].date_pub.month,books[counter].date_pub.year
		,books[counter].popularity	);
		*/
		
		counter++;
		
	}
	
	printf("counter = %d\n" ,counter);
	struct_index1 = counter-1;
	printf("\nstruct_index = %d\n" ,struct_index1);
	delay(10);
	
/***
 if ( fp != NULL ) 
 { 
	 //while( feof(fp))
	 char line[128];
	 
	 while(fgets(line, sizeof(line), fp) != NULL)
	 { 
		len = strlen(line)-1;
		line[len] = '\0';
		
   token = strtok(line, sep);
   while( token != NULL ) {
	  count++;
	  switch (count)
	  {
	  case 1:
	  strcpy(books[i].title, token);
	  break;
	  case 2:
	  strcpy(books[i].author, token);
	  break;
	  case 3:
	  strcpy(books[i].ISBN, token);
	  break;
	  case 4:
	  strcpy(books[i].publisher, token);
	  break;
	  case 5:
	  strcpy(books[i].category, token);
	  break;
	  case 6:
	  av = atoi(token);
	  books[i].av = av;
	  break;
	  case 7:
	  d = atoi(token);
	  books[i].date_pub.day = d;
	  break;
	  case 8:
	  m = atoi(token);
	  books[i].date_pub.month = m;
	  break;
	  case 9:
	  y = atoi(token);
	  books[i].date_pub.year = y;
	  break; 
	  case 10:
	  pop = atoi(token);
	  books[i].popularity = pop;
	  break;
	} //end switch
  
      //printf( "%s\t", token );
      token = strtok(NULL, sep);
   }
   
   printf("\n");
   
  
   
   printf("%s ,%s, %d",books[i].title ,books[i].category, books[i].date_pub.year);
	  //puts(line);
	 
	 i++;
	 }
    {
	fscanf(fp, "%[^,],%[^.],%s,%[^,],%[^,],%d,%s,%d,%d,%d,%d,%d\n", 
    books[i].title,books[i].author,books[i].ISBN,books[i].publisher,
    books[i].category,&books[i].av,&books[i].date_pub.day,&books[i].date_pub.month,
    &books[i].date_pub.year,&books[i].popularity);
    i++;
	}
   
      
    
    
    
   printf( "%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
    books[i].title,books[i].author, books[i].ISBN,books[i].publisher,
    books[i].category, books[i].av,books[i].date_pub.day,books[i].date_pub.month,
    books[i].date_pub.year,books[i].popularity);
    

  //fclose(fp);   
  //  printf("i = %d",i);
//} 
***/
struct_index1 = counter-1;
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
