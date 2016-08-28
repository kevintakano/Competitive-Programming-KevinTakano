#include <cstdio>
#include <cstring>

int value_in_alphabet(char c) 
{ 
	return c - 'A'; 
}

int get_hash(char string[50], int index_word)
{
	int length = strlen(string); 

	int hash_value = 0;

	for(int i = 0; i < length; i++)
	{
		char c = string[i]; 

		hash_value+= i + index_word + value_in_alphabet(c);
	}

	return hash_value; 
}

int main()
{
	int n_cases;

	int amount_lines; 

	char string[50]; 

	scanf("%d",&n_cases); 

	for(int i = 0; i < n_cases; i++)
	{
		scanf("%d",&amount_lines); 

		int result = 0; 
		int index_word = 0; 

		for(int j = 0; j < amount_lines ; j++)
		{
			scanf("%s",string); 
			result += get_hash(string,index_word); 
			index_word++;
		}

		printf("%d\n",result);
	}

	return 0; 
}