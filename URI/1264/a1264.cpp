#include <cstdio>
#include <cstring> 

char INPUT[60]; // De dois a 62

int transform_char(char ch)
{
	if('A' <= ch && ch <= 'Z')
	{
		return ch - 'A' + 10; 
	}
	if('a' <= ch && ch <= 'z') 
	{
		return ch - 'a' + 10 + 26; 
	}
	return -1;
}

int transform_char_number(char ch_number)
{
	return ch_number - '0';
}

int get_minor_divisor(int number_to_calculate)
{
	int divisor = 0, best_divisor = 0 ;

	int i = 0;
	for(divisor = 62; divisor >= 2; divisor--)
	{
		if(number_to_calculate % (divisor - 1) == 0)
		{
			if(i == 0)
			{
				best_divisor = divisor; 
			}
			if(divisor < best_divisor)
			{
				best_divisor = divisor; 
			}
			i++; 
		}
	}

	return best_divisor ; 
}

int main()
{
	/*for(int i = 'A'; i <= 'Z'; i++)
	{
		printf("%c: %d\n",i,transform_char(i));
	}

	for(int i = 'a'; i <= 'z'; i++)
	{
		printf("%c: %d\n",i,transform_char(i));
	}*/

	int number_to_calculate = 0;

	while(scanf("%s",INPUT) == 1)
	{
		int len_string = strlen(INPUT); 

		for(int i = 0; i < len_string;i++)
		{
			if(INPUT[i] == '-')
			{
				continue ; 
			}

			if('0' <= INPUT[i] && INPUT[i] <= '9' )
			{
				if(len_string > 1)
				{
					number_to_calculate = number_to_calculate*10 + transform_char_number(INPUT[i]);
				} else if(len_string == 1)
				{
					number_to_calculate = transform_char_number(INPUT[i]);
				}
			}
			else 
			{
				if(len_string > 1)
				{
					int rest = transform_char(INPUT[i]);
					
					number_to_calculate = number_to_calculate*100 + rest ;
				} else if(len_string == 1)
				{
					number_to_calculate += transform_char(INPUT[i]);
				}
			}
		}

		printf("Number to calculate %d\n",number_to_calculate);


		int minor_divisor = get_minor_divisor(number_to_calculate);

		printf("Best divisor %d\n",minor_divisor);

		number_to_calculate = 0;
	}


	return 0;
}