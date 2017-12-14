#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strstr strtok
#include <curses.h>




int strtoint(char *str); //convert string to integer

// search isbn by id returns no. of matches (0,1) , matches stored in 2d array (calloc)
int search_isbn(char *filename, int id , char **isbn); // --> Youssef
// search id by isbn returns no of matches (0,1)
int search_id(char *filename, char *isbn, int *id); // --> Youssef
int search_line(char *filename, char *ISBN , int *line ); // --> Michael
int getnumline(char *filename); // --> Michael: you may need it


int main() 

{
	
	
	int i;
	// declaration for isnb[][18]
	char **isbn = (char**) calloc(5, sizeof(char*)); // rows = 5 
	for(i = 0; i < 5; i++)
	isbn[i] = malloc(18 * sizeof(char)); // columns = 18
	
	puts("=============");
	
	// test for search_isbn 
	int flag_isbn = search_isbn("isbn.txt", 4452 , isbn);
	if (flag_isbn)
	{for (i=0 ; i<flag_isbn ; i++)
	printf("isbn[%d] = %s\n",i,isbn[i]);
	} else 
	puts("NOT FOUND !!");
	
	puts("=============");
	
	// declaration for id[]
	int *id;
	id = (int*)calloc(5, sizeof(int));
	
	int flag_id;
	
	char strIS[]="12-57-55";
	flag_id = search_id("isbn.txt", strIS , id);
	
	if(!flag_id) {
		perror("Error");
		exit(1);
	}else 
	
	for(int i =0 ; i<flag_id ; i++)
	printf("id[%d] = %d\n",i,id[i]);
	
	
	// declaration for line[]
	puts("=============");
	int *line;
	line= (int*)calloc(20, sizeof(int));
	
	int flag_line;
	//int size=0;
	flag_line = search_line("isbn.txt", "12-57-55" , line); 
	
	if(!flag_line) {
		perror("Error");
		exit(1);
	}else
	
		for( i = 0 ; i< flag_line ; i++)
		printf("line_found = line[%d] = %d\n",i,line[i]);
	
		printf("no of lines = %d",line[i]);
	
		
	
	return(0);
}


int search_isbn(char *filename, int id , char **isbn) {
	
	int i=0 , j=0;
	char idstr[5]; //for id (max 9999)
	
	sprintf(idstr, "%d", id);
	//now id is string 
	
	
	//declare L file
	FILE *fp;
	int l_index = 1; 	// line number
	int counter = 0; 	// # of matched strings
	char temp[256]; // or 1024 7asab b2a L entries beta3tna
	
	const char sep[2] = ",";
    char *token;
	
	// open l file read mode tab3n 34an law m4 mawgood a2olo faks
	if((fp = fopen(filename, "r")) == NULL) {
		return(0);
	}

	// fgets syntax btw  :  char *fgets(char *str, int n, FILE *stream)
	while(fgets(temp, sizeof(temp)+1, fp) != NULL) {
		if((strstr(temp, idstr)) ) {
			
			//printf("a matched found in line %d\n",l_index);
			
			token = strtok(temp, sep);
   
			
			int count_field=0;
			
			// 2 represents # of fields required (to hide password in member file)
			while( token != NULL && count_field!=2) {
			
			if(i==0)
			{
			
			//printf("my token = %s\n",token);
			strcpy(isbn[j++],token);
			
			}
			count_field++;
			token = strtok(NULL, sep);
			i++;
			}
			i=0; // return it to zero again
			
		
			counter++;
			
		}
		
		l_index++;
	}
		
	
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	//return(TRUE);
   	
   	return counter;
}


int search_id(char *filename, char *isbn, int *id) {
	
	int i=0 , j=0;
	
	//declare L file
	FILE *fp;
	int l_index = 1; 	// line number
	int counter = 0; 	// # of matched strings
	char temp[256]; // or 1024 7asab b2a L entries beta3tna
	
	const char sep[2] = ",";
    char *token;
	
	// open l file read mode tab3n 34an law m4 mawgood a2olo faks
	if((fp = fopen(filename, "r")) == NULL) {
		return(FALSE);
	}

	// fgets syntax btw  :  char *fgets(char *str, int n, FILE *stream)
	while(fgets(temp, sizeof(temp)+1, fp) != NULL) {
		if((strstr(temp, isbn)) ) {
			
			//printf("a matched found in line %d\n",l_index);
			
			token = strtok(temp, sep);
   
			
			int count_field=0;
			
			// 2 represents # of fields required (to hide password in member file)
			while( token != NULL && count_field!=2) {
			
			if(i==1)
			{
			// i is token number (here is 2nd section : id)
			//printf( "%s\t", token );
			//printf("my token = %s\n",token);
			id[j++]= strtoint(token);
			
			}
			count_field++;
			token = strtok(NULL, sep);
			i++;
			}
			i=0; // return it to zero again
			
		
			counter++;
			
		}
		
		l_index++;
	}
		
	if(counter == 0) {
		//printf("\nNOT FOUND !!\n");
		
	}
	
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   
  
   	return counter;
}


int search_line(char *filename, char *ISBN , int *line ) {
	
	//declare L file
	FILE *fp;
	int l_index = 1; 	// line number
	int counter = 0; 	// # of matched strings
	char temp[512]; // or 1024 7asab b2a L entries beta3tna
	
	
    
	int i =0;
	// open l file read mode tab3n 34an law m4 mawgood a2olo faks
	if((fp = fopen(filename, "r")) == NULL) {
		return(0);
	}

	// fgets syntax btw  :  char *fgets(char *str, int n, FILE *stream)
	while(fgets(temp, sizeof(temp)+1, fp) != NULL) {
		if((strstr(temp, ISBN)) ) {
			//fscanf(fp, "%[^,],%d,%d\n", str1, &isbn , &copies);
			//printf("A match found on line: %d\n", l_index);
			line[i++] = l_index; // store it
			//printf("\n%s\n", temp);
			
			counter++;
		}
		
		l_index++;
	}

	
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
	
	 //printf("\n counter = %d",l_index);
	 line[i] = l_index-1;
   	return (counter);
}


int getnumline(char *filename)
	{
		FILE *fp;
	int l_index =0; 	// line number
	
	if((fp = fopen(filename, "r")) == NULL) {
		return(0);
	}
	char temp[128];
	while(fgets(temp, sizeof(temp)+1, fp) != NULL)
		l_index++;	
			
		
		
		return l_index;
		}

int strtoint(char *str)

{

int sum= 0, k=0;
	while( str[k])
	{
		sum = sum*10 + ( str[k] - '0' );
		k++;
	}
	
	return sum;
}
