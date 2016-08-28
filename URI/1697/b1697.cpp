
/*
	Se você tem uma lista de números, e o problema diz que podemos um número K formado por dois pares e inserir na lista então podemos formar um novo número também a partir de K e mais outro número.

	Um inteiro composto pode ser fatorado com dois ou mais inteiros primos. Logo, seja K um inteiro composto, pi inteiros primos, e ai inteiros positivos, X = (p1^a1) * (p2^a2) * … * (pi ^ ai).

	Assim, um inteiro primo pode gerar novos primos.

	Por exemplo, se na lista eu tenho os primos 1, 2 e 3, é possível obter os compostos 4 (2*2), 6 (2*3) e 8 (2*2*2), mas não os primos 5 e 7. Logo, a resposta seria 4.

	Se os primos 5 e 7 já estivessem na lista, eu poderia continuar e obter os compostos 9 (3*3), 10 (2*5), mas não o primo 11. Logo, a resposta seria 10.
		1 2 3 4 5 6 7 8 9 10


	Reduzimos então o exercício em: encontre o menor primo P não contido na lista, e imprima P-1	
*/


#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>

using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");


void print_list(list <int> &primes_ls)
{
	for(auto &obj: primes_ls)
	{
		printf("[%d]",obj);
	}

	ENDLINE;
}

void crivo(list<int> &primes_ls)
{	

	int lim = sqrt(MAX);

	int primos[lim + 1];
	int i; 
	for(i = 2; i <= lim;i++) // considera de que i até lim são primos
	{
		primos[i] = i; 
		primes_ls.push_back(i);
	}

	for(int j = i; j < MAX; j++)
	{
		primes_ls.push_back(j);
	}


	for(int k = 2; k <= lim; k++)
	{
		if(primos[k] == k)
		{
			for(auto it = primes_ls.begin(); it != primes_ls.end(); it++)
			{
				int number = *it; 

				if(number < k*k)
				{
					continue;
				}

				if((number) % k == 0)
				{
					primes_ls.erase(it++);
				}
			}
		}

	}

}


int main()
{
	list<int> primes_ls; // primes list 

	crivo(primes_ls);


	//print_list(primes_ls);

	int T;

	scanf("%d",&T);

	for(int i = 0; i < T;i++)
	{
		int N; 

		scanf("%d",&N);

		int X = 0;

		set<int> ls_to_solve; 

		int found_1 = 0;

		for(int j = 0; j < N;j++)
		{
			int a;
			scanf("%d",&a);
			
			ls_to_solve.insert(a);

			if(a == 1)
			{
				found_1 = 1;
			}
		}

		if(!found_1)
		{
			printf("0\n");
			continue;
		}


		for(auto &el : primes_ls) 
		{
			auto it = ls_to_solve.find(el);
			
			if(it == ls_to_solve.end())
			{
				printf("%d\n",el - 1);
				break;
			}	
		}


	}

	return 0;
}