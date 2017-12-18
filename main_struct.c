
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#define BOOKTILTE 64
#define NAME 32

typedef struct date {

int day, month, year;


} date;


typedef struct book {
    char title[BOOKTILTE];
    char author[NAME];
    char ISBN[18]; // isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
    char publisher[NAME];
    char category[NAME];
    int av; // аvailability
    //bool isSafe; // to check whether content is safe for underage
    date date_pub;
    int popularity; // required
    //borrow -> copies

}book;

typedef struct borrow // borrow book
{
   
    int id; // id tany 5als
    char ISBN[18]; // ISBN tany 5als \\// isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
    date date_due;
    date date_issue;
    date date_return; // required
    //int book.ISBN;

} borrow;

typedef struct address
{
 int building;
 char city[16];
 char street[16];
}address;

typedef struct  member {

    char name[2][NAME]; // 0,1 
    int id;
    address addressmem;  // 0,1,2
    date dateofbirth;
    char phone[12];
    char email[30];
    char pass[32];
    int borrowav;
}member;


int main()
{
    printf("Hello world!\n");
    return 0;
}
