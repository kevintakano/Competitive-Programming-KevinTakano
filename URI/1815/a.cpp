#include <bits/stdc++.h>

#define FOR(i,N) for(int i =0;i < N;i++)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")

using namespace std;

const int MAXN = 101;

double transition_matrix[MAXN][MAXN];
double ret_matrix[MAXN][MAXN];
double aux[MAXN];
double p[MAXN];

void matmult(double  a[][MAXN],double  b[][MAXN],double c[][MAXN],int N)//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            c[i][j]=0;
            for(k=0;k<N;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
}


void print_array(double array[MAXN], int N)
{
	FOR(i,N)
	{
		printf("[%lf]",array[i]);ENDLINE;
	}
}

void vector_mul_matrix(double V[MAXN], double T[MAXN][MAXN], double AUX[MAXN], int N)
{
    double sum;
    for(int j=0;j<N;j++)
    {
        sum = 0;
        for(int i=0;i<N;i++)
            sum+=T[i][j]*V[i
            	];
        AUX[j] = sum;
    }
    for(int i = 0;i < N;i++) V[i] = AUX[i];
}

void copy(double A[MAXN][MAXN],double B[MAXN][MAXN],int N)
{
	FOR(i,N)
	{
		FOR(j,N) 
		{
			A[i][j] = B[i][j];
		}
	}
}

void print_matrix(double A[MAXN][MAXN], int N){
	FOR(i,N)
	{
		FOR(j,N)
		{
			printf("[%lf]",A[i][j]);
		}ENDLINE
	}
}

int main()
{
	int N,T,K,M;
	int k = 1;

	// double aux[MAXN];

	while(1)
	{
		cin >> N; 
		if(N == 0) break;

		cin >> T >> K >> M;
		
		memset(transition_matrix,0,sizeof transition_matrix);
		memset(ret_matrix,0,sizeof ret_matrix);
		memset(p,0,sizeof p);
		
		FOR(i,N)
		{
			FOR(j,N)
			{
				cin >> transition_matrix[i][j];
			}
		}

		double sum = 0; // a resposta é a probabilidade de todos os estados
		
		p[K-1] = 1;

		// for(int i = 0; i < N;i++) ret_matrix[i][i] = 1; 
		for(int i = 0; i < N;i++) transition_matrix[T-1][K-1] = 0;
		transition_matrix[K-1][K-1] = 1;; 

		for(int i = 0; i < M;i++)
		{
			// matmult(ret_matrix,transition_matrix,aux,N);
			// copy(ret_matrix,aux,N);
			
			// print_matrix(ret_matrix,N); ENDLINE
			// memset(aux,0,sizeof aux);
			vector_mul_matrix(p,transition_matrix,aux,N);
			// sum += p[K-1];
			print_array(p,N); ENDLINE;
		}

		printf("Instancia %d\n",k);
		printf("%.6lf\n",1.0 - p[T-1]);
		ENDLINE;
		k++;
	}	






}