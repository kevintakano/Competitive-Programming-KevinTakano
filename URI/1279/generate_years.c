#include <stdio.h>

int main(int argc, char **argv)
{
	int total = atoi(argv[1]);
	int i;
	int value; 
	for (i = 0; i < total; ++i)
	{
		value = rand() ;
		printf("%d\n",value);
	}

	return 0;
}