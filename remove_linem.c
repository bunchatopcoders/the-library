#include <stdio.h>
#include <stdlib.h>

void remove_line(int line,char*ch)//ch is the file name
	
int main()
{ int line;
 printf("enter the line number: ");
    scanf("%d",&line);
	remove_line(line,"student_file.txt");
    return 0;
}

void remove_line(int line,char*ch)
{   int i=1;
   char c;
    FILE*f1,*f2;
  f1=fopen(ch,"r");
  f2=fopen("student_file_remove.txt","w");
  if(f1!=NULL)
   {
	   //!feof(f1)

       while( (c = fgetc(f1)) != EOF)
    {

        if(i!=line)
        fprintf(f2,"%c",c);

       if (c=='\n')
       i++;
    }
      fclose(f1);
      fclose(f2);
      remove(ch);
      rename("student_file_remove.txt",ch);
   }
   else perror("ERROR");

}
