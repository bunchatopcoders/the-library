#include <stdio.h>
#include <stdlib.h>
#define NAME 25
typedef struct date {
int day, month, year;
} date;

typedef struct address
{
 int building;
 char street[16];
 char city[16];
}address;

typedef struct  member {

    char name[2][NAME];
    int id=1;
    address addressmem;
    date dateofbirth;
    int borrowav=3;
    char phone[12];
    char email[30];
    char pass[32];

}member;

member members;

void addmember();

int main()
{
  addmember();
    return 0;
}
void addmember(void)
{
FILE *f1,*f2;
f1= fopen("membertemp.txt" ,"a");
puts("Enter First Name:");
gets(members.name[0]);
puts("Enter Last Name:");
gets(members.name[1]);

// generate id
// let id global variable = 1 id++

puts("Enter building no:");
scanf("%d",&members.addressmem.building);
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
int i=0;
printf("Enter the password :\n");
    break;
   else if (members.member.pass[i]==8)
   {     putch(8);
         putch('\0');
         putch(8);
while (i<=13)
    {
   members.pass[i]=getch();
   if(members.member.pass[i]==13)
         i--;
         continue;
   }
    else printf("*");
    i++;
}
str[i]='\0';

fprintf(f1,"%s,%s,%d,%d,%s,%s,%d,%d,%d,%d,%s,%s,%s",members.member.name[0],members.member.name[1],members.member.id,members.member.addressmem.building,members.member.addressmem.street,
        members.member.addressmem.city,
        members.member.dateofbirth.members.member.dateofbirth.month,members.member.dateofbirth.year,members.member.phone,members.member.email,members.member.pass);
}
