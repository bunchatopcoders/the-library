#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct date {



int day, month, year;





} date;

int comparedates(date d)
{


time_t t=time(NULL);
struct tm now=*localtime(&t);
date n;
n.day=now.tm_mday;
n.month=now.tm_mon+1;
n.year=now.tm_year+1900;
return ((n.year-d.year)*365)+((n.month-d.month)*30)+(n.day-d.day);




}












int main()
{
date d;
scanf("%d%d%d",&d.day,&d.month,&d.year);
printf("%d",comparedates(d));

    return 0;
}
