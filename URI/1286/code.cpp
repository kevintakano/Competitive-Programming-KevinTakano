
#include <bits/stdc++.h>


using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define FOR(i,N) for(int i =0;i < N;i++)

typedef struct no 
{
	int temp,npizzas;
} entrega;

entrega entregas[21];

int MAX[20+1][30+1];

void print_matrix(int matrix[][30+1],int N, int M){
	FOR(i,N+1)
	{
		FOR(j,M+1)
		{
			printf("[%d]",matrix[i][j]);
		}ENDLINE
	}
}


int main()
{
	int N,P;



	while(1)
	{
		// for(int i = 0; i < 21;i++)
		// {
		// 	entregas[i].temp = entregas[i].npizzas = 0;
		// }

		memset(MAX,0,sizeof MAX);
		cin >> N; if(N == 0) break;

		cin >> P;

		FOR(i,N)
		{
			int v1,v2;
			cin >> v1 >> v2;
			entregas[i+1].temp = v1;
			entregas[i+1].npizzas = v2;
		}

	
		// MAX[0] = 0; // caso base 
		// for(int i = 0; i <= P;i++) MAX[0][i] = 0;

		for(int j = 1;j <= P;j++)
		{
			for(int i = 1; i <= N;i++)
			{	
					if(entregas[i].npizzas <= j)
					{
						MAX[i][j] = max(MAX[i-1][j],entregas[i].temp + MAX[i-1][j- entregas[i].npizzas]);
					}
					else {
						MAX[i][j] = MAX[i-1][j];
					}
			}
		}

		// print_matrix(MAX,N,P);

		printf("%d min.\n",MAX[N][P]);



	}

}