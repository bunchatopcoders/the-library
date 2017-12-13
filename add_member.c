#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//tolower

#define BOOKTILTE 50
#define NAME 25

void lowercase(char *str);
void addbook(void);
typedef struct date {

int day, month, year;


} date;


typedef struct book {
    char title[BOOKTILTE];
    char author[NAME];
    char ISBN[18];
    char publisher[NAME];
    char category[NAME];
    int av ; //availability
    //bool isSafe; // to check whether content is safe for underage
    date date_pub;
    //borrow -> copies

}book;
book books;

typedef struct address
{
 int building;
 char city[16];
 char street[16];
}address;

typedef struct  member {

    char name[2][NAME]; // 0,1 
    int id;
    address addressmem;  
    date dateofbirth;
    char phone[12];
    char email[30];
    char pass[32];
    
}member;

member members;


int main()
{
	
	addbook();
	system("xdg-open booktemp.csv");
	
return 0;	
	
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



void addmember(void)
{
FILE *f;
f= fopen("membertemp.csv" ,"a");

puts("Enter First Name:");
gets(members.name[0]);
puts("Enter Last Name:");
gets(members.name[1]);

// generate id
// let id global variable = 1 id++

puts("Enter building no:");
gets(members.addressmem.building);
puts("Enter street name :");
gets(members.addressmem.street);
puts("Enter city:");
gets(members.addressmem.city);
puts("Enter date of birth ie:25/1/2018");
scanf("%d/%d/%d",&members.dateofbirth.&members.dateofbirth.month,&members.dateofbirth.year);

puts("Enter phone number:");
gets(members.phone);

puts("Enter email address : aaa@bbb.com");
gets(members.email);

puts("Enter number of books available");
scanf("%d",&books.av);
puts("enter day/month/year  ie: 20/6/1998");
scanf("%d/%d/%d",&books.date_pub.day,&books.date_pub.month,&books.date_pub.year);
lowercase(books.title);
lowercase(books.author);
lowercase(books.publisher);
lowercase(books.category);
fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
books.publisher,books.category,books.av,books.date_pub.day,books.date_pub.month,books.date_pub.year);
}


void add(void)
{
FILE *f;
f= fopen("booktemp.csv" ,"a");

puts("Enter Book Title :");
gets(books.title);
puts("Enter Author name :");
gets(books.author);
puts("Enter ISBN (using standard)");
gets(books.ISBN);
puts("Enter Publisher:");
gets(books.publisher);
puts("Enter category");
gets(books.category);
puts("Enter number of books available");
scanf("%d",&books.av);
puts("enter day/month/year  ie: 20/6/1998");
scanf("%d/%d/%d",&books.date_pub.day,&books.date_pub.month,&books.date_pub.year);
lowercase(books.title);
lowercase(books.author);
lowercase(books.publisher);
lowercase(books.category);
fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
books.publisher,books.category,books.av,books.date_pub.day,books.date_pub.month,books.date_pub.year);
}
