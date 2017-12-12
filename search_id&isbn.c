#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strstr strtok
#include <curses.h>




int strtoint(char *str); //convert string to integer
int search_isbn(char *filename, int id , char **isbn);
int search_id(char *filename, char *ISBN, int *id);


int main() 

{
	
	
	int i;
	// declaration for isnb[][18]
	char **isbn = (char**) calloc(5, sizeof(char*));
	for(i = 0; i < 5; i++)
	isbn[i] = malloc(18 * sizeof(char));
	
	// test for search_isbn 
	int flag_isbn = search_isbn("isbn.txt", 4452 , isbn);
	if (flag_isbn)
	{for (i=0 ; i<flag_isbn ; i++)
	printf("\nisnb[%d] = %s\n",i,isbn[i]);
	} else 
	puts("NOT FOUND !!");
	
	
	int *id;
	id = (int*)calloc(5, sizeof(int));
	
	int flag_id;
	
	char strIS[]="12-57-55";
	
	flag_id = search_id("isbn.txt", strIS , id);
	
	printf("flag_find = %d\n", flag_id);
	if(!flag_id) {
		perror("Error");
		exit(1);
	}else 
	
	for(int i =0 ; i<flag_id ; i++)
	printf("\nid[%d] = %d\n",i,id[i]);
	
	
		
	
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


int search_id(char *filename, char *ISBN, int *id) {
	
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
		if((strstr(temp, ISBN)) ) {
			
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
