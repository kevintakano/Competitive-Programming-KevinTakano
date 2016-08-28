

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
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");


void print_vector(int vector[] ,int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("[%d]",vector[i]);
	}

	ENDLINE;
}

void crivo(int primos[MAX])
{
	int lim = MAX;

	for(int i = 2; i <= lim ; i++) primos[i]= i; // considera que todos são primos


	for(int i = 2; i <= lim;i++)
	{
		if(primos[i] == i)
		{
			//HEY2
			for(int j = i +  i ; j < MAX ; j += i)
			{
				primos[j] = 0;

			}

		}

	}

}

int main()
{
	int T;

	int primos[MAX]; 

	memset(primos,0,sizeof primos);

	// print_vector(primos,MAX);

	crivo(primos);

	scanf("%d",&T);

 	cout.tie (NULL); 
	for(int i = 0; i < T;i++)
	{
		int N; 

		scanf("%d",&N);

		set<int> set_to_solve; 

		for(int j = 0; j < N;j++)
		{
			int a;
			scanf("%d",&a);
			set_to_solve.insert(a);

		}

		if(set_to_solve.find(1) == set_to_solve.end())
		{
			printf("0\n");
		} else 
		{
			for(int i = 2; i < MAX; i++)
			{
				if(primos[i] == i)
				{
					set<int>::const_iterator it = set_to_solve.find(i);

					if(it == set_to_solve.end())
					{
						printf("%d\n",i-1);
						break;
					} 
				}
			}

		}


	}


	return 0;
}