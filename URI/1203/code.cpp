
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
#define ps(s) printf("%s\n",s);
#define modulo 1000000009
#define printm(MAT,N,M) for(int i = 0;i < N;i++){for(int j = 0;j < M;j++) printf("[%d]",MAT[i][j]); ENDLINE}
typedef long long int ll; 

int D[101]; //Degree
int SMAX[101][5000];

int main()
{
	int r,k;

	while(cin >> r >> k)
	{
		memset(D,0,sizeof D);
		memset(SMAX,0,sizeof SMAX);
		int a,b;

		FOR(i,k)
		{
			cin >> a >> b;
			D[a]++;
			D[b]++;
		}

		for(int i =  1; i <= r; i++)
		{
			for(int j = 1; j <=	 k;j++)
			{
				if(D[i] <= j)
				{
					SMAX[i][j] = max(SMAX[i-1][j],D[i] + SMAX[i-1][j-D[i]]);
				}else
				{
					SMAX[i][j] = SMAX[i-1][j];
				}
			}
		}
		int count = 0 ;
		for(int i = 1; i <= r && !count;i++)
		{
			if(SMAX[i][k] == k){ count++; break; }
		}

		// printm(SMAX,r+1,k+1);

		if(count) printf("S\n"); else printf("N\n");


	}
}


