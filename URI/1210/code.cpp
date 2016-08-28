/*
4 2 6 100
30 50 65 80 100 120
60 50 40 30 20 10

R: 260, 1 3

1o ano: venda(100) + custo(30) + venda(50)
2o ano: custo(50) 
3o ano: venda(100) + custo(30) + venda(50)
4o ano: custo(50)

i - periodo atual de produção
j - idade da máquina atual

CUSTOMINIMO_ij = 
{ 
	0, SE i == 0 ou j == 0,

	-V[j-1] + C[0] + P + CUSTOMINIMO_(i-1,j-1)	SE j == M e i <= N
									
	min(-V[j-1] + C[0] + P + CUSTOMINIMO_(i-1,j-1), C[j-1]  + CUSTOMINIMO_(i-1,j-1)  ), SE i <= N e j < M
}
*/
#include <bits/stdc++.h>
#include <algorithm> 

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
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mat[i][j] << "]";    \
        }ENDLINE    \
    }   \
 
#define pa(array,n) \
    {               \
    for0(i,n)       \
    {               \
        cout << "[" << array[i] << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);

const int MAXN = 1001, INF = 0x3f3f3f3f;;

int C[2002],V[2002];
int MIN[2001][2001];


int main()
{
	int N,I,M,P;

	while(cin >> N >> I >> M >> P)
	{
		memset(C,0,sizeof C);
		memset(V,0,sizeof V);
		memset(MIN, 0 ,sizeof MIN);

		for1(i,M) cin >> C[i];
		for1(i,M) cin >> V[i];

		for(int i = 1;i <= N;i++)
		{
			for(int j = 1; j < M;j++)	
			{
				/*printf("Production year i = %d and Distiller year j = %d\n",i,j); 
				getchar();
				printf("C[j] + MIN[i-1][j-1] = %d + %d = %d\n",C[j],MIN[i-1][j-1],C[j] + MIN[i-1][j-1]);
				getchar();
				printf("C[1] + P - V[j] + MIN[i-1][1] = %d + %d - %d + %d = %d\n",C[1],P,V[j],MIN[i-1][1],C[1] + P - V[j] + MIN[i-1][1]);
				getchar();	
				printf("Let's take the minor between first(%d) and second(%d)\n",C[j] + MIN[i-1][j-1],C[1] + P - V[j] + MIN[i-1][1]);
				getchar();
				printf("M[i=%d][j=%d] = %d\n",i,j,min(C[j] + MIN[i-1][j-1],C[1] + P - V[j] + MIN[i-1][1]));
				getchar();*/
			
				MIN[i][j] = min(C[j+1] + MIN[i-1][j+1],C[1] + P - V[j] + MIN[i-1][1]);
			}
			MIN[i][M] = C[1] + P - V[M] + MIN[i-1][1];
		}
		printf("%d\n",MIN[N][I]);
		/*pm(MIN,N+1,M+1	);
		ENDLINE;*/

		int age = I;
		vector<int> sol;
		int k = 1;
		for(int i=N;i>=1 ;i--) {
			// if(age == m || c[0] + p - v[age] + dp[i+1][1] <= c[age] + dp[i+1][age+1]) {
			if(age == M || C[1] + P - V[age] + MIN[i-1][1] <= C[age+1] + MIN[i-1][age+1] ) {
				sol.push_back(k);
				age = 1;
			} else 
				age++;
			k++;
		}

		if(sol.empty()) printf("0\n");
		else {
			printf("%d", sol[0]);
			for(int i=1;i<sol.size();i++) printf(" %d", sol[i]);
			printf("\n");
		}


	}



	return 0;
}
