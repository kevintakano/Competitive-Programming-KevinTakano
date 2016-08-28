#include <cstdio>
#include <cstring>
#include <cstdlib> 
#include <map>
#include <algorithm>

using namespace std;

bool myfn(char a , char b)
{
	return a < b;
}

char max_string(char string[])
{

	int large = string[0];

	for(int i = 0 ; i < strlen(string); i ++)
	{	
		if(string[i] == '-')
			continue;
		if(large < string[i])
		{
			large = string[i];
		}
	}

	return large; 
}

int main()
{
	int base = 1;

	char input[1024];

	map<char,int> bases_map; 

	int k = 0;
	
	for(char i = '0'; i <= '9';i++)
	{
		bases_map.insert(pair<char,int>(i,k));
		k++;
	}
	for(char i = 'A'; i <= 'Z'; i++)
	{
		bases_map.insert(pair<char,int>(i,k));
		k++;	
	}
	// printf("k atal %d\n",k);

	for(char i = 'a'; i <= 'z'; i++)
	{
		bases_map.insert(pair<char,int>(i,k));
		k++;	
	}

	/*for(auto &obj : bases_map)
	{
		printf("[%c->%d] ",obj.first,obj.second);
	}*/
	int sum = 0;
					
	while(scanf("%s",input)==1)
	{
		// printf("%s\n",input);
		{
			
			char  large = max_string(input);

			int real_value = bases_map[large];

			// printf("valor correspondente ao caracter inicial (menor base possível representativa) %d %c\n",real_value,large);

			int passed_away = 0;

			for(base = real_value + 1; base <= 62 ; base++)
			{
				sum = 0;
				for(int i = 0; i < strlen(input); i++)
				{
					if(input[i] == '-')
					{
						continue;
					}
					// printf("%c,%d ",input[i],bases_map[input[i]]);
					//printf("char atual %c  ",input[i]);
					sum += bases_map[input[i]]; 
				}	
				if(base > 1)
				{
					if(sum % (base -1) == 0)
					{
						printf("%d\n",base);
						base = 14321;
						passed_away = 1;
					}
				}
					
			}
			if(!passed_away)
			{
				printf("such number is impossible!\n");
			}
		}


		// printf("soma %d\n",sum);


	}


	return 0;
}