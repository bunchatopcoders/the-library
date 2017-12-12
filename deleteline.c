
void copyfile(char* s,char* d)
{
    char c;
    FILE*fr;
    fr=fopen(s,"r");
    FILE*fw;
    fw=fopen(d,"w");
    while((c=getc(fr))!=EOF)
    {
        putc(c,fw);
    }
    fclose(fr);
    fclose(fw);
}
int linesize(FILE*fr)
{
    char ch;
    int i=0;
    while((ch=getc(fr))!=10)i++;
    return i+2;
    fclose(fr);
}
void deleteline(char*c,int n)
{
    FILE*fr,*fw;
    fw=fopen("temp.txt","w");
    fr=fopen(c,"r");
    int i;
    char ch;
    for(i=0;i<n&&((ch=getc(fr))!=EOF);i++)
    {
        putc(ch,fw);
    }
    fseek(fr,linesize(fr),1);
    while ((ch=getc(fr))!=EOF)
    {
         putc(ch,fw);
    }
    fclose(fr);
    fclose(fw);
    copyfile("temp.txt",c);

}
