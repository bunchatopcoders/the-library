
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
    char ISBN[18]; // isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
    char publisher[NAME];
    char category[NAME];
    int availability;
    bool isSafe; // to check whether content is safe for underage
    date date_pub;
    //borrow -> copies

}book;

typedef struct borrow // borrow book
{
   
    int id; // id tany 5als
    char ISBN[18]; // ISBN tany 5als \\// isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
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
