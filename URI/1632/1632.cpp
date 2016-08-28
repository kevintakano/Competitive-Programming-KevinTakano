#include <cstdio>
#include <cstring>

int main()
{

	int T;

	scanf("%d",&T);

	char string[16]; 

	int res = 1; 

	for(int i = 0; i < T; i++)
	{
		scanf("%s",string);

		for(int j = 0; j < strlen(string); j++)
		{
			if(string[j] == 'A' || string[j] == 'a' || string[j] == '4' ||
				string[j] == 'e' || string[j] == 'E' || string[j] == '3' ||
				string[j] == 'i' || string[j] == 'I' || string[j] == '1' ||
				string[j] == 'O' || string[j] == 'o' || string[j] == '0' ||
				string[j] == 's' || string[j] == '5' || string[j] == 'S')	
			{
				res *= 3;
			}
			else 
			{
				res *= 2; 
			}
		}
		printf("%d\n",res);


		res = 1;
	}

	return 0; 
}