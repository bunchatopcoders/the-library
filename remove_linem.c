#include <stdio.h>
#include <stdlib.h>

void remove_line();


int main()
{ remove_line();
    return 0;
}


void remove_line()
{   int line,i=1;
   char c;
    printf("enter the line number: ");
    scanf("%d",&line);
    FILE*f1,*f2;
  f1=fopen("student_file.txt","r");
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
      remove("student_file.txt");
      rename("student_file_remove.txt","student_file.txt");
   }
   else perror("ERROR");

}

