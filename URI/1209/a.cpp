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
#define END ("\n");	
#define FOR(i,N) for(int i = 0; i < N;i++)

int main()
{
	int K,N,M;

	while(cin >> N >> M >> K)
	{
		int GRAPH[N][N];

		memset(GRAPH,0,sizeof GRAPH);

		for(int i = 0;i < M; i++)
		{
			int a,b;

			cin >> a >> b;
			GRAPH[a-1][b-1] = 1;
			GRAPH[b-1][a-1] = 1;
		}

		/*for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++) 
			{
				printf("[%d]",GRAPH[i][j]);
			}

			ENDLINE
		}*/

		int k = 0;

		int LIST[N];

		int tam = 0; 

		FOR(i,N)
		{
			k = 0;
			int j = 0;
			while(j < N)
			{
				if(GRAPH[i][j] == 1)
				{
					k++;
				}
				j++;
			}
			if(k >= K)
			{
				LIST[tam] = (i+1);
				tam++;
			}
		}

		for(int i = 0; i < tam;i++)
		{
			printf("%d",LIST[i]);
			if(i != (tam - 1))	cout << " ";
		}
		if(tam != 0) ENDLINE
			
		if(tam == 0)
		{
			printf("0\n");
		}
		
	}



	return 0;
}