#include <bits/stdc++.h>
using namespace std;

#define FOR(i,N) for(int i =0;i < N;i++)
#define ENDLINE printf("\n");
int n, s, f, m;

const int MAXN = 101;

double** mult( double **A, double **B ) {
	double **M;
	M = new double*[n+1];

	for( int i = 1; i <= n; i++ ) {
		M[i] = new double[n+1];
		for( int j = 1; j <= n; j++ ) {
			M[i][j] = 0;
			for( int k = 1; k <= n; k++ )
				M[i][j] += A[i][k] * B[k][j];
		}
	}
	return M;
}

void print_matrix(double **A, int N){
	FOR(i,N)
	{
		FOR(j,N)
		{
			printf("[%lf]",A[i][j]);
		}ENDLINE
	}
}


int main() {
	int t = 1;
	double p, **A, **answer;

	while( scanf( "%d", &n ) && n ) {
		scanf( "%d%d%d", &s, &f, &m );
		A = new double*[n+1];
		answer = new double*[n+1];
		
		for( int i = 1; i <= n; i++ ) {
			A[i] = new double[n+1];
			answer[i] = new double[n+1];
			answer[i][i] = 1.0;
			for( int j = 1; j <= n; j++ ) {
				scanf( "%lf", &p );
				A[i][j] = p;
			}
		}
		for( int j = 1; j <= n; j++ ) A[f][j] = 0.0;
		A[f][f] = 1.0;
for( int i = 1; i <= n; i++ ) 
		{
			for( int j = 1; j <= n; j++ ) 
			{
				printf("[%lf]",answer[i][j]);
			}ENDLINE
		}
		ENDLINE

		while( m ) {
			answer = mult( answer, A );
	

		for( int i = 1; i <= n; i++ ) 
		{
			for( int j = 1; j <= n; j++ ) 
			{
				printf("[%lf]",answer[i][j]);
			}ENDLINE
		}
		ENDLINE

			m--;
		}
		printf("s %d e f %d\n",s,f);
		printf( "Instancia %d\n%.6lf\n\n", t++, 1.0 - answer[s][f] );
	}

	return 0;
}