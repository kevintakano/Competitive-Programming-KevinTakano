#include <cstdio>

#define D1 printf("D1\n");


typedef struct no
{
	int t1,t2,t3; 
} t3;

typedef struct no2
{
	int t1,t2; 
} t2;

int T_1(int c1, int c2, int c3, t3 a, t3 b) // verifica se dois t3, tem funções T iguais
{
	if( (c1*a.t1 + c2*a.t2 + c3*a.t3) == (c1*b.t1 + c2*b.t2 + c3*b.t3) )
	{
		return 1;
	} else 
		return 0;
}

int T_2(int c1, int c2, t2 a, t2 b) // verifica se dois t3, tem funções T iguais
{
	if( (c1*a.t1 + c2*a.t2) == (c1*b.t1 + c2*b.t2) )
	{
		return 1;
	} else 
		return 0;
}

int main()
{
	int N,M;

	while(scanf("%d %d",&N,&M) == 2)
	{
		int c1,c2,c3;

		for(int i = 0; i < N; i++)
		{
			if(i == 0)
			{
				scanf("%d",&c1);
			}
			if(i == 1)
			{
				scanf("%d",&c2);
			}
			if(i == 2)
			{
				scanf("%d",&c3);
			}
		}

		// printf("c1 c2 c3 %d %d %d\n",c1,c2,c3);	


		if(N == 3)
		{
			int length = 0; 


			t3 combinations_arry[M*M*M];

			for(int i = 1; i <= M;i++)
			{
				for(int j = 1; j <= M;j++)
				{
					for(int k = 1; k <= M;k++)
					{
						combinations_arry[length].t1 = i; 
						combinations_arry[length].t2 = j; 
						combinations_arry[length].t3 = k; 

						length++;
					}
				}
			}	


			int nao_da = 0; 

			for(int i = 0; i < length;i++)
			{
				for(int j = i + 1; j < length; j++)
				{
					if(T_1(c1,c2,c3,combinations_arry[i],combinations_arry[j]) == 1)
					{
						// printf("Não deu when T(%d,%d,%d) == T(%d,%d,%d)\n",combinations_arry[i].t1,combinations_arry[i].t2,combinations_arry[i].t3,combinations_arry[j].t1,combinations_arry[j].t2,combinations_arry[j].t3);
						nao_da = 1;
						goto resposta;
					}
				}
			}
			resposta:		

			if(nao_da)
			{
				printf("Try again later, Denis...\n");		
			} else 
			{
				printf("Lucky Denis!\n");
			} 

		} else if(N == 2)
		{
			int length = 0; 

			t2 combinations_arry[M*M*M];

			for(int i = 1; i <= M;i++)
			{
				for(int j = 1; j <= M;j++)
				{
						combinations_arry[length].t1 = i; 
						combinations_arry[length].t2 = j; 

						length++;
				}
			}	


			int nao_da = 0; 

			for(int i = 0; i < length;i++)
			{
				for(int j = i + 1; j < length; j++)
				{
					if(T_2(c1,c2,combinations_arry[i],combinations_arry[j]) == 1)
					{
						nao_da = 1;
						goto resposta2;
					}
				}
			}
			resposta2:		

			if(nao_da)
			{
				printf("Try again later, Denis...\n");		
			} else 
			{
				printf("Lucky Denis!\n");
			} 
		} else if(N == 1)
		{
			printf("Lucky Denis!\n");

		}
		
	}


	

	return 0;
}