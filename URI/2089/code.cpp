
#include <bits/stdc++.h>


using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)
#define pm(mat,n,m) \
	for0(i,n)		\
	{				\
		for0(j,m)	\
		{			\
			cout << "[" << mat[i][j] << "]";	\
		}ENDLINE	\
	}	\

#define pa(array,n) \
	{				\
	for0(i,n)		\
	{				\
		cout << "[" << array[i] << "]";	\
	}				\
	ENDLINE; 		\
	}				\

#define ps(s) printf("%s\n",s);

#define MAXV 100000
#define MAXN 1000

typedef long long int ll; 

ll SMAX[2][MAXV];
ll VALUES[MAXV];

int main()
{
	int V,N;

	

	while(cin >> V >> N && N != 0 && V != 0)
	{

		memset(SMAX,0,sizeof SMAX);
		memset(VALUES,0,sizeof VALUES);
		// printf("V = %d e N = %d\n",V,N);
		for0(i,N)
		{
			cin >> VALUES[i]; 
		}

		for1(i,N)
		{
			ll *cur = SMAX[i&1];
			ll *prev = SMAX[!(i&1)];
			for1(j,V)
			{
				cur[j] = (VALUES[i-1] <= j) ? max(prev[j],prev[j-VALUES[i-1]] + VALUES[i-1]) : prev[j];
			}
		} 
		if(SMAX[N&1][V]==V) printf("sim\n"); else printf("nao\n");
	}




	return 0;
}