#include <cstdio>
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cstring>

#define ENDLINE printf("\n");
#define END ('\n')

#define D1 printf("D1\n");
#define D2 printf("D2\n");
#define D3 printf("D3\n");

#include <cmath>

using namespace std;


typedef struct node
{
	char c; 
	int id; 
} strType;

bool cmp(strType a, strType b) {return a.c < b.c;}

int main()
{

	strType input[100000];

	char original[100000];

	int N,D;

	while(1)
	{


		memset(input,0,sizeof input);
		memset(original,0,sizeof original);

		cin >> N >> D;

		// cout << N << " " << D << END;

		if(N == 0 && D == 0)
		{
			break;
		}
		int tam = 0;

		for(int i = 0; i < N; i++)
		{
			scanf(" %c",&input[tam].c);
			input[tam].id = tam;
			original[tam] = input[tam].c;

			tam++;
		}
		if(N > 3)
		{
			if(original[N-1] == '0' && original[1] != '0')
			{
				original[N-1] = 'A';
				input[N-1].c = 'A';
				D--;
			}
		}


		sort(input , input + N,cmp);

		/*cout << "input ordenado" << END;

		for(int i = 0; i < tam; i++)
		{
			{
				printf("%c",input[i].c);		
			}	
		}
		ENDLINE*/

		for(int i = 0; i < D;i++)
		{
			original[input[i].id] = ('A');
		}


		for(int i = 0; i < tam; i++)
		{
			if(original[i] != ('A'))
			{
				printf("%c",original[i]);		
			}	
		}
		ENDLINE

	}


	return 0;
}