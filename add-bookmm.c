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

//new addbook 

void addbook(void)
{
	
struct_index1++; // global variable intialized with -1

char buffer[64];
puts("Enter Book Title :");
fgets(buffer,sizeof(buffer),stdin);
//gets(books.title);
strcpy(books[struct_index1].title,buffer);

puts("Enter Author name :");
fgets(buffer,sizeof(buffer),stdin);
strcpy(books[struct_index1].author,buffer);

//gets(books.author);

puts("Enter ISBN (using standard)");
fgets(buffer,18,stdin);
strcpy(books[struct_index1].author,buffer);

//gets(books.ISBN);
puts("Enter Publisher name:");
fgets(buffer,sizeof(buffer)/2,stdin);
strcpy(books[struct_index1].publisher,buffer);

//gets(books.publisher);

puts("Enter category");
fgets(buffer,sizeof(buffer)/2,stdin);
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

scanf("%d/%d/%d",&books[struct_index1].date_pub.day,	
&books[struct_index1].date_pub.month,&books[struct_index1].date_pub.year);
/*lowercase(books.title);
lowercase(books.author);
lowercase(books.publisher);
lowercase(books.category);
fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
books.publisher,books.category,books.av,books.date_pub.day,books.date_pub.month,books.date_pub.year);
*/

}



/////////////////////////////////////////////////////////

/* void addbook(void)
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
*/
