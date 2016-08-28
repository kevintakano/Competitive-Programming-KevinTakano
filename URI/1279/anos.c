#include <stdio.h>
#include <string.h>

#define MAX 10000

int VERBOSE ;

typedef enum{FALSE,TRUE} bool;

bool divisible(char *string_year, int value)
{
	int length_string = strlen(string_year);

	if(value == 400)
	{
		if(VERBOSE)
			printf("Verifying divisibilty by 400\n");
		char buffer[5]; 
		buffer[0] = string_year[length_string-4]; 
		buffer[1] = string_year[length_string-3]; 
		buffer[2] = string_year[length_string-2]; 
		buffer[3] = string_year[length_string-1]; 
		buffer[4] = '\0'; 
		//printf("%s\n",buffer);
		int buffer_value = atoi(buffer);
		
		if(buffer_value % 400 == 0)
			return TRUE;
		else return FALSE;
	}
	if(value == 4)
	{	
		if(VERBOSE)
			printf("Verifying divisibilty by 4\n");
		char buffer[3]; 
		buffer[0] = string_year[length_string-2]; 
		buffer[1] = string_year[length_string-1]; 
		buffer[2] = '\0';
		//printf("%s %s \n",buffer,string_year);
		int buffer_value = atoi(buffer);
		//printf("%d\n",buffer_value);
		if(buffer_value % 4 == 0)
			return TRUE;
		else return FALSE;

	}
	if(value == 100)
	{	
		if(VERBOSE)
			printf("Verifying divisibilty by 100\n");
		char buffer[3]; 
		buffer[0] = string_year[length_string-3]; 
		buffer[1] = string_year[length_string-2]; 
		buffer[2] = string_year[length_string-1]; 
		buffer[3] = '\0'; 
		//printf("%s\n",buffer);
		int buffer_value = atoi(buffer);
		//printf("%d\n",buffer_value);
		if(buffer_value % 100 == 0)
			return TRUE;
		else return FALSE;		
	}	

	if(value == 15)
	{		
		if(VERBOSE)
			printf("Verifying divisibilty by 15\n");
		char buffer[4]; 
		buffer[0] = string_year[length_string-4]; 
		buffer[1] = string_year[length_string-3]; 
		buffer[2] = string_year[length_string-2]; 
		buffer[3] = string_year[length_string-1]; 
		buffer[4] = '\0'; 

		//printf("%s\n",buffer);
		int buffer_value = atoi(buffer);
		
		if(divisible(string_year,3) == TRUE && divisible(string_year,5) == TRUE)
			return TRUE;
		else return FALSE;		
	}	 
	if(value == 3)
	{
		int i = 0;
		int sum = 0;		
		for(; i < MAX && string_year[i] != '\0' ;i++)
		{			
			int buffer_value = string_year[i] - '0';
			sum += buffer_value;		
		}		
		if(sum % 3 == 0)
			return TRUE;
		else return FALSE;		
	}
	if(value == 5)
	{
		if(VERBOSE)
			printf("Verifying divisibilty by 5\n");
		char buffer[2]; 		
		buffer[0] = string_year[length_string-2]; 
		buffer[1] = string_year[length_string-1]; 
		buffer[2] = '\0'; 

		int buffer_value = atoi(buffer);

		if(buffer_value % 5 == 0)
		{
			return TRUE;
		} else return FALSE;
	}

	if(value == 11)
	{
		if(VERBOSE)
			printf("Verifying divisibilty by 11\n");
		int i = 0;
		int sum = 0;
		int j; 
		for(; i < length_string ;i++)
		{
			//printf("a\n");
			if(i % 2 == 0)
			{
				j = 1;
			} else 
			 	j = -1;
			int buffer_value = string_year[i] - '0';
			sum += buffer_value * j; 
			
		}		
		//printf("%d\n",sum);
		if(sum % 11 == 0)
		{
			return TRUE;
		} else return FALSE;
	}
	if(value == 55) // value é divisível por 55, se somente se for divísvel por 5 e 11
	{ 
		// também pode se pegar sempre a soma dos dígitos até a antepenultima posição e subtrair com o resto
		if(VERBOSE)
			printf("Verifying divisibilty by 55\n");
		if(divisible(string_year,5) == TRUE && divisible(string_year,11) == TRUE)
			return TRUE;
		else return FALSE;	
	}
}
		
bool leap_year(char string_year[MAX]) /*Ano bissexto, divisíveis por 400*/
{
	//printf("a\n");

	if (divisible(string_year,400) == TRUE)
	{
		if(VERBOSE)
			printf("i'm in leapyear, and it has divisibilty for 400\n");
		//printf("b\n");
		return TRUE;
	} else if(divisible(string_year,4) == TRUE && divisible(string_year,100) == FALSE)
	{	
		if(VERBOSE)
			printf("i'm in leapyear, it has divisibilty for 4 and 100\n");
		//printf("c\n");
		return TRUE;
	}
	//printf("no leap_year %d %d %d\n",divisible(string_year,400),divisible(string_year,4),divisible(string_year,100));
	//printf("d\n");
	return FALSE;
}

bool huluculu(char string_year[MAX])
{
	if(divisible(string_year,15) == TRUE)
	{

		if(VERBOSE)
			printf("i'm in leapyear, it has divisibilty for 15\n");
		return TRUE; 
	}
	else return FALSE; 
}

bool bulukulu(char string_year[MAX])
{
	if(divisible(string_year,55) == TRUE && leap_year(string_year) == TRUE) 
	{
		if(VERBOSE)
			printf("i'm in leapyear, it has divisibilty for 55\n");
		return TRUE; 
	}
	else return FALSE; 
}



int main(int argc, char **argv)
{	
	char string_year[MAX]; 
	int i =0;
	VERBOSE = 0;
	int res =scanf("%s",string_year);
	do
	{	
		if(VERBOSE)
		{
			printf("Ano: %s\n",string_year);	
		}
		if(leap_year(string_year)==TRUE)
		{
			
			printf("This is leap year.\n"); 
		} 
		if(huluculu(string_year)==TRUE)
		{
			printf("This is huluculu festival year.\n");
		} 
		if(bulukulu(string_year)==TRUE )
		{
			printf("This is bulukulu festival year.\n");
		}   
		if(huluculu(string_year) == FALSE && bulukulu(string_year) == FALSE && leap_year(string_year) == FALSE)
		{
			printf("This is an ordinary year.\n");			
		}/*else if (leap_year(string_year)==FALSE && huluculu(string_year) == FALSE && bulukulu(string_year) == TRUE)
		{
			printf("This is an ordinary year.\n");
		}*/
		//memset(string_year,0,sizeof(string_year));		
		i++;
		if(VERBOSE)
			printf("Fim do loop.\n");
		res =scanf("%s",string_year);		
		
		if(res == 1)
			printf("\n");
		else 
			return 0;
		
	}while(1);


	return 0;
}
