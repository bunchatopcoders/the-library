
void borrow(char* isbn,int id)
{
    //check if isbn exists
    int i;
    time_t t=time(NULL);
    struct tm now=*localtime(&t);
    now.tm_mon+1;
    now.tm_year+1900;
    //search by id for itrator
    if (!member[i].borrowav)
    {
            puts("You have reached the limit for maximum number of borrows");
    }
    else
    {
        member[i].borrowav--;
        // global bborrows itrator++
        borrows[/*global itrator*/].id=id;
        borrows[/*global itrator*/].isbn=isbn;
        borrows[/*global itrator*/].date_issue=now;
        borrows[/*global itrator*/].date_due=/*calc n+*/
        borrows[/*global itrator*/].date_returned=NULL;

        //search by isbn for itrator
        books[i].av--;
        books[i].popularity++;


    }
}
int returnbook(char*isbn,int id)
{
    int i,flag=0;
    time_t t=time(NULL);
    struct tm now=*localtime(&t);
    now.tm_mon+1;
    now.tm_year+1900;
    //search by isbn and id for index
    if( now<borrows[/*isbn and id index*/].date_due )
        {printf("Your book is over due please report to the proper authority");
        flag=1;
        }
    borrows[/*isbn index*/].date_returned=now;
    //search by isbn for itrator
        books[i].av++;
     //search by id for itrator
        member[i].borrowav++;
    return flag;
}

void addcopy(char* isbn)
{
    int i,n;
    do {
        puts("please enter the number of copies you want to add");
        scanf("%d",&n);
        }
    while(n<1)
    //search for itrator by isbn
    books[i].av++;

}



