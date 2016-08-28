#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int digits[10];
	memset(digits,0,10*sizeof(int)); 

	char str[MAX]; 

	scanf("%s",str);

	int value;
	
	value = atoi(str);


	for(int j = 0; j <= value; j++)
	{
		char string[MAX];
		sprintf(string, "%d", j);
		//printf("String atual %s\n",string);
		for(int i = 0; i < strlen(string); i++)
		{
			//printf("	Analisando a posição %c\n",string[i]);
			//getchar();
			if(string[i] == '0')
			{
				digits[0] += 1;
			}
			if(string[i] == '1')
			{
				digits[1] += 1;
			}		
			if(string[i] == '2')
			{
				digits[2] += 1;
			}
			if(string[i] == '3')
			{
				digits[3]++;
			}
			if(string[i] == '4')
			{
				digits[4] += 1;
			}
			if(string[i] == '5')
			{
				digits[5] += 1;
			}
			if(string[i] == '6')
			{
				digits[6] += 1;
			}
			if(string[i] == '7')
			{
				digits[7] += 1;
			}
			if(string[i] == '8')
			{
				digits[8] += 1;
			}
			if(string[i] == '9')
			{
				digits[9] += 1;
			}
		}
		//for(int i = 0; i < 10; i++) //printf("%d ",digits[i]);		
		//printf("\n");
		//getchar();
	}

	for(int i = 0; i < 10; i++) printf("%d ",digits[i]);


	return 0; 
}