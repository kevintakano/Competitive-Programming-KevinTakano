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


int main()
{

	char input[100000];

	int N,D;

	while(1)
	{
		cin >> N >> D;

		if(N == 0 && D == N)
		{
			break;
		}

		int pilha[N];

		int tam = 0;

		cin >> input ;

		int count = 0;

		int initial_D = D;

		for(int i = 0; i < N;i++)
		{
			int valor = input[i] - '0';

			if(tam == 0)
			{
				pilha[tam] = valor;
				tam++;
			} else 
			{
				// printf("i = %d, input[i] %d, pilha[tam = %d] = %d\n",i,valor,tam,pilha[tam-1]);

				while(valor > pilha[tam-1] && count < D && tam > 0)
				{ 
					tam--;
					// D--;	
					count++;
				}	
				pilha[tam] = valor;
				tam++;
			}
		}

		// cout << "N" << N;

		for(int i = 0; i < (N - initial_D);i++)
		{
			printf("%d",pilha[i]);
		}
		ENDLINE;

	

	}


	return 0;
}