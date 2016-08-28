
#include <bits/stdc++.h>


using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define FOR(i,N) for(int i =0;i < N;i++)

vector<int> ocorrencias[1000002];
					   //465461

int main()
{
	int N,M;
	int last = N; 

	while(cin >> N >> M)
	{
		// HEY
		for(int i = 1 ;i <= 1000002;i++)
		{
			ocorrencias[i].erase(ocorrencias[i].begin(),ocorrencias[i].end());
		}

		for(int i = 1; i <= N;i++)
		{
			int value ; cin >> value; 


			ocorrencias[value].push_back(i);

		}

		for(int i =0 ; i < M;i++)
		{
			int a,b;

			cin >> a >> b;

			int j = 1;

			int found = 0;

			// printf("valor a lido %d\n",a);

			for(auto &obj : ocorrencias[b])
			{
				if((a) == j)
				{
					found = 1;

					printf("%d\n",obj);
					break;
				}
				j++;
			}
			if(!found)
			{
				printf("0\n");
			}

		}
		last = N;


	}


	return 0;
}