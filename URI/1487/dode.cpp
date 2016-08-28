#include <cstdio>
#include <algorithm>
using namespace std;

int mochila[105][605];

int main() {
	int n, t, inst = 1, d[105], p[105];

	while( scanf( "%d%d", &n, &t ) && n ) {
		for( int i=1; i<=n; i++ )
			scanf( "%d%d", &d[i], &p[i] );

		for( int i=1; i<=t; i++ ) {
			mochila[0][i] = 0;
			for( int j=1; j<=n; j++ )
				if( i-d[j] < 0 )
					mochila[j][i] = mochila[j-1][i];
				else {
					mochila[j][i] = max( mochila[j-1][i], mochila[j-1][ i-d[j] ] + p[j] );
					mochila[j][i] = max( mochila[j][i], mochila[j][ i-d[j] ] + p[j] );
				}
		}

		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= t;j++)
			{
				printf("[%d]",mochila[i][j]);
			}
			printf("\n");
		}
		printf( "Instancia %d\n%d\n\n", inst++, mochila[n][t] );
	}

	return 0;
}