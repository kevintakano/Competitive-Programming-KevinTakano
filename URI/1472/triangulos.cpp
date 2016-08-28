#include <cstdio>
#include <iostream>
/*#include <set>*/


#define oi printf("oi\n");
#define oi2 printf("oi2\n");
#define oi3 printf("oi3\n");
#define oi4 printf("oi4\n");
#define oi5 printf("oi5\n");
#define endline printf("\n");

int array[100000];
int reached[100000];

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int comprimento = 0;
		for(int i = 0; i < N;i++)
		{
			scanf("%d",&array[i]);
			comprimento += array[i];
			reached[i] = 0;
		}
		int arco = comprimento/3; 
		int total_arcos = 0;
		int acumulador = 0;
		int numero_triangulos = 0;
		int j ;
		int k = 0;

		/*std::set<int> reached;*/
		for(int i = 0 ; i < N; i++)
		{
			j = i;
			//printf("Iteração i %d\n",i);
			//printf("%d %d %d %d\n",k < N , total_arcos < 3 , acumulador < arco , reached[j] != 1);
			if(reached[i] == 1)
			{
				continue;
			}
			while(k < N && total_arcos < 3 && acumulador < arco)
			{
				acumulador += array[j]; 
				//printf("	Iteração j %d\n",j);
				//printf("	Acumulador %d\n",acumulador);
				if(acumulador == arco)
				{	
					/*std::set<int>::iterator it;*/

				/*	it = reached.find(j);
					if(it != reached.end()) // ja encontrou um numero
					{
						break;
					}*/
					if(reached[j] == 1)
					{
						break; 
					}

					total_arcos++;
					acumulador = 0;
					reached[j]  = 1;				
					//printf("	Encontrou um arco.\n");	
				} 
				j++;
				if(j == (N))
				{
					j = 0;
				}
				k++;			
			}
			//printf("total de arcos %d\n",total_arcos);
			if(total_arcos == 3)
			{
				numero_triangulos++;
			}
			total_arcos = 0;
			acumulador = 0;
			k = 0;
		}		
		printf("%d\n",numero_triangulos);
	}



	return 0;
}