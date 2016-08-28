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

const int MAXN = 2*(100000) + 1, INF = 0x3f3f3f3f;;

int V[MAXN];
int DP[MAXN][2];

#define DONT_HAVE_STOCK 0
#define HAVE_STOCK 1

int solve(int day, int &N, int &C, int state)
{
    /*for(int i = 0; i < N;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            printf("[%d(%d,%d)]",DP[i][j],i,j);
        }
        ENDLINE;
    }
    HEY
*/
    if(day == N) return 0;

    if(DP[day][state] != -1) return DP[day][state];

    
    if(state == HAVE_STOCK) // se tem ação, vende
    {
        DP[day][state] = max(V[day] + solve(day+1,N,C,DONT_HAVE_STOCK),solve(day+1,N,C,HAVE_STOCK));
    } else /*if(state == DONT_HAVE_STOCK)*/
    {
        DP[day][state] = max(-V[day] - C + solve(day+1,N,C,HAVE_STOCK),solve(day+1,N,C,DONT_HAVE_STOCK));
    }

    return DP[day][state];
}

int main()
{
      ios::sync_with_stdio(false);
    int N,C;

    cin >> N >> C;
    int minimum = 0,maximum = 0; 
    int cost = 0;
    
    for0(i,N)
    {
        cin >> V[i];
    }
    memset(DP,-1,sizeof DP);
    printf("%d\n",solve(0,N,C,0));
}