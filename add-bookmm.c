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
typedef struct bbooks // borrow book
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
	
	addbook();
	
	
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



void addbook(void)
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
puts("enter day-month-year  ex: 20-6-1998");
scanf("%d-%d-%d",&books.date_pub.day,&books.date_pub.month,&books.date_pub.year);
lowercase(books.title);
lowercase(books.author);
lowercase(books.publisher);
lowercase(books.category);
fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
books.publisher,books.category,books.av,books.date_pub.day,books.date_pub.month,books.date_pub.year);
}
