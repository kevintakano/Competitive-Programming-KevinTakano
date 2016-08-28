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

	

	for(int i = 0; i < 10; i++) printf("%d ",digits[i]);


	return 0; 
}