
void borrow(char* isbn,int id)
{
    //check if isbn exists
    int i;
    time_t t=time(NULL);
    n.day=now.tm_mday;
    n.month=now.tm_mon+1;
    n.year=now.tm_year+1900;
    struct tm now=*localtime(&t);
    //search by id for itrator
    if (!member[i].borrowav)
    {
            puts("You have reached the limit for maximum number of borrows");
    }
    else
    {
        member[i].borrowav--;
        // global bborrows itrator++
        bborrows[/*global itrator*/].id=id;
        bborrows[/*global itrator*/].isbn=isbn;
        bborrows[/*global itrator*/].date_issue=n;

        //search by isbn for itrator
        books[i].av--;
        books[i].popularity++;


    }
}
int returnbook(char*isbn,int id,int d)
{
    int i,flag=0;
    //search by isbn and id for index
    if(comparedates(bborrows[i].date_issue)>d)
        {printf("Your book is over due please report to the proper authority");
        flag=1;
        }
    //remove element i
    //search by isbn for itrator
        books[i].av--;
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

















