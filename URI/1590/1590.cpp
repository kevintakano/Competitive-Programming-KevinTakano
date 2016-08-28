#include <cstdio>
#include <algorithm>
#include <cmath>

#define ENDLINE printf("\n");

#define D1 printf("D1\n");
#define D2 printf("D2\n");


using namespace std;

bool cmp(int i, int j)
{
	return j < i; 
}

void print_vector(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("[%d]",v[i]);
	}

	ENDLINE;

}

int main()
{
	int T,N,K;

	scanf("%d",&T); 

	for(int i = 0; i < T;i++)
	{
		scanf("%d %d",&N,&K); 

		int n_vet[N]; 

		for(int j = 0; j < N; j++)
		{
			scanf("%d",&n_vet[j]); 
		}

		sort(n_vet,n_vet + N,cmp); 


		int current = n_vet[0]; 
		int logvalue = (int)log2(current);	

		int count = 0; // considera que para contar deve se ter pelo menos 2, dígitos 1's igguais
		int res = 0;

		int entrou = 0;
		int mask = 0;
		int ifanterior = 0;

		int k = logvalue ;

		 // printf("** Encontrar o primeiro bit com count >= K\n");

		while(k != 0)
		{
			count = 0;

			 // printf("	k atual = %d\n",k);

			for(int j = 0 ;j < N ;j++)
			{
				if( (1 << k & n_vet[j]) != 0 )
				{
					/*printf("	Counted when j = %d (n_vet[j] %d) and k = %d\n",j,n_vet[j],k);*/
					count ++; 
				}
			}
			
			if(count >= K)
			{
				// printf("	Encontrou um dígito k = %d, com count (%d) >= K (%d)\n",k,count,K);
				entrou = 1;
				res |= 1 << k; 
				// printf("	aqui, res = %d\n",res);

				break;
			} 
			k--;
		}
		 // printf("** Entra na segunda parte de encontrar os dígitos restantes\n");
		 // printf("Atual k = %d\n",k);
		while(k >= 0)
		{
			// printf("	atual, k = %d\n",k);			

			count = 0; 
			for(int j = 0; j < N;j++)
			{
				if ( (res & n_vet[j]) == res && (1 << k & n_vet[j]) != 0)
				{
					// printf("	Encontrou um n_vet[j] = %d, que contém a máscara %d (que é próprio 'res')\n",n_vet[j],res);
					// printf("	Aqui n_vet[j] = %d contém o dígito 1 << k = %d\n",n_vet[j],1 << k);					
					count++;
				}
			}
			if(count >= K)
			{
				// printf("Encontrou um k = %d com count (%d) >= K (%d) e com a máscara res %d\n",k,count,K,res);
				res |= 1 << k; 
				// printf("atualiza res = %d",res);
			}
			k--;
		}

		// printf("** Resposta final: %d\n",res);
		printf("%d\n",res);

	}
}