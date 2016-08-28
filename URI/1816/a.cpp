#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 

using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")


void swap(char *a, char *b)
{
	int aux; 

	aux = *a; 
	*a = *b; 
	*b = aux;
}

void insert_init(char list[26], int position)
{
	char pivot = list[0];

	// printf("inserindo %c\n",list[position]);

	list[0] = list[position];

	int i ;

	for(i = 1; i <= position;i++)
	{
		int aux = list[i];

		list[i] = pivot;

		pivot = aux;
	}

	// printf("ultimo pivot %c\n",pivot);

	pivot =  list[i];

	// printf("ultimo i %d\n",i);

	for(; i < 25;i++)
	{
		list[i] = pivot;

		pivot = list[i+1];
	}

/*	
	for(; list[i] != '-' && i < 26;i++)
	{
		int aux = list[i];

		list[i] = pivot;

		pivot = aux;
	}*/


}

int main()
{


	int m;
	int h = 1;
	while(1)
	{
		cin >> m;
		if(m == 0) break;

		printf("Instancia %d\n",h);
		char lista[26]; 

		int count = 0 ;
		for(char a = 'A'; a <= 'Z'; a++)
		{
			lista[count] = a; 
			count++;
		}

		for(int i = 0; i < m; i++)
		{
			int N; 
			cin >> N;

			printf("%c",lista[N-1]);

			insert_init(lista,N-1);
		}	

		ENDLINE;
		ENDLINE

		h++;
	}


	return 0;
}