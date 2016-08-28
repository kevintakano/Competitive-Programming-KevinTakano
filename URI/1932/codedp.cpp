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
int DP[MAXN];

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
    DP[0] = 0;
    // HEY
    for(int i = 1; i < N;i++)
    {
        DP[i] = DP[i-1];
        for( int j = 0; j < i;j++)
        {
                int value; 
                if( DP[i] > V[i] - V[j] - C + DP[j])
                {
                    value = DP[i];                     
                } else 
                {
                    value = V[i] - V[j] - C + DP[j];
                    i = j;
                }
            
            if(value >= DP[i])
            {
                DP[i] = value; 
            } else 
                break;
        }
    }

    printf("%d\n",DP[N-1]);
}