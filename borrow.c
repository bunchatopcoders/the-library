
void borrow(char isbn,int id)
{
    FILE* f;
    time_t t=time(NULL);
    struct tm now=*localtime(&t);
    fopen("membertemp.csv","r");
    int i,l;
    search_line_borrow("membertemp.csv",id,&l);
    for(i=0; i<l; i++)
        fscanf(f,"",,);   // *mickey* el tartib
    if(!member.borrowsav)
    {
        puts(reached the maximum number of books borrowed);
        fclose(f)
    }
    else
    {

        fclose(f);
        member.borrowsav--;
        deleteline("membertemp.csv",l);
        fopen("membertemp.csv","a");
        fprintf(f,"",,);    // *mickey* el tartib
        fclose(f);
        date n;
        n.day=now.tm_mday;
        n.month=now.tm_mon+1;
        n.year=now.tm_year+1900;
        f=fopen("bborrowtemp.csv","a");
        fprintf(f,"%d,%s ,%d,%d,%d\n",id,isbn,n.day,n.month,n.year);
        fclose(f);
        f=fopen("booktemp.csv","r");
        search_line("booktemp.csv", &isbn,&l );
        for(i=0; i<l; i++)
            fscanf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
                   books.publisher,books.category,&books.av,&books.date_pub.day,&books.date_pub.month,&books.date_pub.year);
        fclose(f);
        deleteline("booktemp.csv",l);
        books.av--;
        fopen("booktemp.csv","a");
        fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
                books.publisher,books.category,books.av,books.date_pub.day,books.date_pub.month,books.date_pub.year);
        fclose(f);

    }
}

int returnbook(char isbn,int id,int d)      //d is the time period limit
{
    FILE* f;
    int i,l1,l2;
    int flag=0;
    f=fopen("bborrowtemp.csv","r");
    date n;
    do {
    fscanf(f,"%d,%s ,%d,%d,%d\n",idp,isbnb,n.day,n.month,n.year);
    }while(isbnb!=isbn&&idp!=id)
        fclose(f);
    if(comparedates(n)>d)
        {printf("Your book is over due please report to the proper authority");
        flag=1;
        }

    // *hagar*

    remove_line(l1,"bborrowtemp.csv");
    for(i=0; i<l1; i++)
        fscanf(f,"",,);    // *mickey* el tartib
    fclose(f);
    search_line_borrow("membertemp.csv",id,&l1);
    member.borrowsav++;
    deleteline("membertemp.csv",l);
    fopen("membertemp.csv","a");
    fprintf(f,"",,);      // *mickey* el tartib
    fclose(f);
    f=fopen("booktemp.csv","r");
    search_line("booktemp.csv", &isbn,&l1 );
    for(i=0; i<l1; i++)
        fscanf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
                   books.publisher,books.category,&books.av,&books.date_pub.day,&books.date_pub.month,&books.date_pub.year);
    fclose(f);
    deleteline("booktemp.csv",l1);
    books.av++;
    fopen("booktemp.csv","a");
    fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%d,%d\n",books.title,books.author,books.ISBN,
            books.publisher,books.category,books.av,books.date_pub.day,books.date_pub.month,books.date_pub.year);
    fclose(f);
    return flag;
}

