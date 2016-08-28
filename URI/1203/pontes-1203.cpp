#include <stdio.h>

//int matrix[100][100];

int backtrack(int vet[101], int *sum, int init, int K)
{
	if(init	 == (K+1) && *sum != K)
	{
		printf("porra\n");
		return 0;
	}
	if(*sum == K)
	{
		printf("entrei aqui\n");
		return 1;
	}
	for(int i = init; i <= K; i++)
	{
		*sum = *sum + vet[i];
		printf("Verifcando o valor %d na posição vet[%d]\n",vet[i],i);
		printf("Soma %d\n",*sum);
		printf("Valor de i %d\n",i);
		if(*sum == K)
		{
			printf("entrei aqui\n");
			return 1;
		}	
		if(backtrack(vet,sum,init+1,K) == 1)
		{
			return 1;
		}

		*sum = *sum - vet[i];

	}	
	return 0;
}

/* 
i == 0, i == 1, i == 2;
00001
00010 
00011

00011 = 3
00101 = 5
00110 = 6
01001 = 9
01010 = 10
01100 = 12

*/
void print_matrix(int matrix[101][101],int R)
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0 ; j < R; j++)
		{
			printf("[%d]",matrix[i][j]);
		}
		printf("\n");
	}
}
int  main()
{
	int R,K;	
	int r1, r2; 
	int i,j =0;
	int regions[101][101];
	int saiu = 0;
	int sum = 0;

	while(scanf("%d %d",&R,&K) != EOF)
	{

		//printf("r k %d %d\n",R,K);	
		for(i = 0; i < R;i++) for(j = 0; j < R;j++)	regions[i][j] = 0;

		for (i = 0	; i < K; ++i)
		{
			scanf("%d %d",&r1,&r2);
			regions[r1-1][r1-1]++;
			regions[r2-1][r2-1]++;

			if(regions[r1][r1] == K || regions[r2][r2] == K) saiu = 1;
		}
		R = 4; K = 5;
		regions[0][0] = 2; regions[1][1] = 3; regions[2][2] = 2; regions[3][3] = 3;
		saiu = 0;
		print_matrix(regions,R);
		printf("********************\n");		
		for(i = 0; i < R && saiu == 0; i++)
		{
			for(j = i+1; j < R && saiu == 0; j++)
			{
				printf("oi\n");
				regions[i][j] = regions[i][i] + regions[j][j];
				/*if(regions[i][j] == K)
				{
					saiu = 1;
				}*/
			}
		}			
		print_matrix(regions,R);
		printf("********************\n");
		int k = 2; 
		while(k < R)
		{
			for(i = 0; i < (R-k) && saiu == 0; i++)
			{
				for(j = k; j < R && saiu == 0; j++)
				{
					//printf("i e j %d %d\n",i,j);
					regions[i][j] = regions[i][j-(k-1)] + regions[j][j];
					/*if(regions[i][j] == K)
					{
						saiu = 1;
					}*/
				}
			}
			k++;
		}
		print_matrix(regions,R);
		printf("********************\n");
		if(saiu == 1)
		{
			printf("S\n");
		} else 
			printf("N\n");
		saiu = 0;

		return 0;
	}	
	return 0;
}