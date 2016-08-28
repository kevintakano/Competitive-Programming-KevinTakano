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

int visited[1000];

int LIST[1000]; // 

int main()
{
	ios_base::sync_with_stdio(false);
	int K,N,M;

	int count = 0;

	while(cin >> N >> M >> K)
	{
		memset(GRAPH,0,sizeof GRAPH);
		memset(visited,0,sizeof visited);
		memset(LIST,0,sizeof LIST);

		printf("Instancia %d\n",count +1);

		printf("N, M, K %d %d %d\n",N,M,K);

		for(int i = 0;i < M; i++)
		{
			int a,b;

			cin >> a >> b;

			printf("	%d %d\n",a,b);
			// GRAPH[b-1][a-1] = 1;
		}


		

		count ++;


	}



	return 0;
}