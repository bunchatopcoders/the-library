#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRUCTSIZE 32
#define NAME 32
#define BOOKTILTE 32


typedef struct book {
    char title[BOOKTILTE];
    char author[NAME];
    char ISBN[18]; // isbn should be char char ISBN[18] 13 digits + 4'-'s + '\0' 
    char publisher[NAME];
    char category[NAME];
    int av; // аvailability
    //bool isSafe; // to check whether content is safe for underage
    //date date_pub;
    int popularity;
    //borrow -> copies

}book;


void search_in_book(book books[] , char* str , int mode);

// declare books array  :
book books[STRUCTSIZE];


int main()
{
strcpy(books[0].ISBN , "1234567");
strcpy(books[0].author , "John");
strcpy(books[0].title, "oly 0007");
strcpy(books[0].publisher, "longman");
strcpy(books[0].category, "Si-fi");

strcpy(books[1].ISBN , "1234567");
strcpy(books[1].author , "John");
strcpy(books[1].title, "oly 0007");
strcpy(books[1].publisher, "longman");
strcpy(books[1].category, "Si-fi");

int g;
char str[11] = "12345";;
//search_in_book(books , str , 1);
//printf("g = %d",g);

char buffer[10];
fgets(buffer ,18,stdin);
g = strcmp(books[0].ISBN, "1234567");
search_in_book( books , buffer , 1);
printf("%d",g);
return 0;

}



void search_in_book(book books[] , char* str , int mode){
  
  
  for(int i=0; i < STRUCTSIZE; i++){
  if(mode ==1)
  
    {
    if(strcmp(books[i].ISBN , str)==0){
        printf("%s\n",books[i].ISBN);
    }
}
    
  }
  //return -1;
}
