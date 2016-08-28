#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 
#include <algorithm>
#include <vector>

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

void DFS(int vertex, int N, int K)
{
	VISITED[vertex] = 1;

	for(int i = 0; i < N; i++)
	{
		if(GRAPH[vertex][i] == 1) DEGREE[i]--; // Se for adjacente, diminui um grau, pois sabe que o vertice vertex não contém as condições iniciais.

		if(GRAPH[vertex][i] == 1 && DEGREE[i] < K && !VISITED[i]) // caso algum vizinho mantenha a propriedade, vá em cima dele :D
		{

			DFS(i, N , K);	
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
		memset(DEGREE,0,sizeof DEGREE);

		for(int i = 0;i < M; i++)
		{
			int a,b;

			cin >> a >> b;
			GRAPH[a-1][b-1] = 1;
			GRAPH[b-1][a-1] = 1;
			DEGREE[a-1]++;
			DEGREE[b-1]++;

		
		}



		for(int i = 0; i < N;i++)
		{
			if(!VISITED[i] && DEGREE[i] < K){ // procura por um vértice que mantenha a propriedade e mete o dfs no vizinho
				//printf("Visitando quando i = %d, grau = %d\n",i+1,DEGREE[i]);
				DFS(i,N,K );
			}
		}

		vector<int> vet; 

		for(int i = 0; i < N;i++)
		{
			if(DEGREE[i] >= K) vet.push_back(i);
		};
		sort(vet.begin(), vet.end());

		if(vet.size())
		{
			for(int i = 0; i < vet.size();i++)
			{
				printf("%d",vet[i]+1);
				
				if(i != vet.size() - 1)
				{
					printf(" ");
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