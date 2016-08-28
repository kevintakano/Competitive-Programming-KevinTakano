#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 

using namespace std;

int main()
{
	int G,P;

	while(1)
	{
		cin >> G >> P;

		if(G == P && P == 0)
		{
			break; 
		}

		int chegadas[G][P]; 

		for(int i = 0; i < G; i++)
		{
			for(int j = 0 ; j < P; j++)
			{
				cin >> chegadas[i][j]; 	
			}
		}

		int S; 

		cin >> S;
	
		int TABELA[S][P];  

		memset(TABELA,0,sizeof TABELA);

		for(int i = 0; i < S; i++) //
		{
			int K;

			cin >> K ;

			for(int j = 0; j < K; j++)
			{
				cin >> TABELA[i][j];
			}
		}

		/*for(int i = 0; i < S; i++)
		{
			for(int j = 0; j < P; j++)
			{
				printf("[%d]",TABELA[i][j]);
			}
			printf("\n");
		}	
*/


		int RES_FINAL[S][P];
		memset(RES_FINAL,0,sizeof RES_FINAL);

		for(int i = 0; i < S; i++)
		{
			for(int j = 0; j < P; j++)
			{
				for(int g = 0; g < G; g++)
				{

					int aux = chegadas[g][j];

					int value = TABELA[i][chegadas[g][j]- 1];

					// cout << "value = " << value << endl;
					// printf("	quando i = %d e chegadas = %d\n",i,chegadas[g][j] - 1);

					RES_FINAL[i][j] += value ;

				}
			}
		}

		// for(int i = 0; i < S; i++)
		// {
		// 	for(int j = 0; j < P; j++)
		// 	{
		// 		printf("[%d]",RES_FINAL[i][j]);
		// 	}
		// 	printf("\n");
		// }		
		// 	printf("\n");

		int vencendor[P];

		int tam = 0;

		for(int i = 0; i < S; i++)
		{
			tam = 0;
			int larger = RES_FINAL[i][0];

			for(int k = 0; k < P; k++)
			{
				if(larger < RES_FINAL[i][k]) larger = RES_FINAL[i][k];
			}

			for(int k = 0; k < P; k++)
			{
				if(RES_FINAL[i][k] == larger)
				{
					vencendor[tam] = k + 1	; 
					tam++;
				}
			}

			for(int k = 0; k < tam; k++)
			{
				cout << vencendor[k]; 
				if(k != (tam - 1)) cout << " "; 
			}
			cout << endl;
			// printf("\n");


		}

	}

	return 0;
}