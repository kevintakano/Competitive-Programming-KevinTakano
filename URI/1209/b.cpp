#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 
#include <algorithm>

using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n");	
#define FOR(i,N) for(int i = 0; i < N;i++)

int GRAPH[1000][1000];

int VISITED[1000];

int DEGREE[1000];

int LIST[1000]; // i-ésimo vértice está no grafo se i-ésima posição for ZERO, não está caso contrário.

void DFS(int vertex, int N, int K)
{
	VISITED[vertex] = 1;

	for(int i = 0; i < N;i++)
	{
		if(GRAPH[vertex][i] == 1)
		{
			if(!VISITED[i])
			{
				DFS(i,N,K);
			}
		}
	}	

	int count = 0;
	for(int i = 0; i < N;i++)
	{
		if(GRAPH[vertex][i]==1)
		{
			count++;
		}
		if(GRAPH[i][vertex] == 1)
		{
			count++;
		}
	}

	if(count < K)
	{
		// printf("Entrei aqui quando vértice = %d e N = %d, K = %d, count = %d\n",vertex+1,N,K,count);
		LIST[vertex] = 1;

		for(int i = 0;i < N;i++) // remove ligaçoes
		{
			GRAPH[vertex][i] = 0;
			GRAPH[i][vertex] = 0;
		}
	} else 
	{
		// printf("	Entrei aqui quando vértice = %d e N = %d, K = %d, count = %d\n",vertex+1,N,K,count);
		LIST[vertex] = 0;
	}
}

bool DFS_PRINT(int vertex, int N,int &tam)
{
	VISITED[vertex] = 1;
	LIST[tam++] = vertex; 

	// 	cout << "current vertex = " << vertex << END;

	for(int i = 0; i < N;i++)
	{
		if(GRAPH[vertex][i] == 1)
		{
			if(!VISITED[i])
			{
				DFS_PRINT(i,N,tam);
			}
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	int K,N,M;

	while(cin >> N >> M >> K)
	{
		memset(GRAPH,0,sizeof GRAPH);
		memset(VISITED,0,sizeof VISITED);
		memset(LIST,0,sizeof LIST);

		for(int i = 0;i < M; i++)
		{
			int a,b;

			cin >> a >> b;
			GRAPH[a-1][b-1] = 1;
			// GRAPH[b-1][a-1] = 1;
		}
		HEY 

		for(int i = 0; i < N;i++)
		{

			DFS(i,N,K); 
		}	

		// memset(VISITED,0,sizeof VISITED);
		
		/*for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++) 
			{
				printf("[%d]",GRAPH[i][j]);
			}

			ENDLINE
		}	*/	

			HEYA 

		int tam = 0;

		int entrou = 0;

		for(int i = 0; i < N;i++)
		{
			if(LIST[i] == 0)
			{
				tam++;
			}
		}
		HEYB 

		if(tam > 0)
		{
			int k = 0;
			for(int i = 0; i < N;i++)
			{
				if(LIST[i] == 0)
				{
					printf("%d",i+1); 
					
					if(k != tam - 1) 
					{
						printf(" ");
					}
					k++;
				}
			}
			ENDLINE; 
		} else 
		{
			printf("0\n");
		}



	}



	return 0;
}