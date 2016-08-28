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

int DURATION[101];
int SCORE[101];

int MAX[101][601];

int main()
{
    int N,T;
    
    int k = 1;
    while(cin >> N >> T && N && T)
    {
        memset(DURATION,0,sizeof DURATION);
        memset(SCORE,0,sizeof SCORE);
        memset(MAX,0,sizeof MAX);

        for1(i,N)
        {
            cin >> DURATION[i] >> SCORE[i]; 
        }

        for1(i,N)
        {
            for1(j,T)
            {
                if(DURATION[i] <= j)
                {
                    MAX[i][j] = max(SCORE[i] + MAX[i-1][j - DURATION[i]] , MAX[i-1][j] );
                    MAX[i][j] = max(SCORE[i] + MAX[i][j - DURATION[i]] , MAX[i][j] );
                }else 
                {
                    MAX[i][j] = MAX[i-1][j];
                }
                 
            }
        }

       
        // pm(MAX,N+1,T+1);

        printf("Instancia %d\n",k++);
        printf("%d\n",MAX[N][T]);
        ENDLINE;
    }

    return 0;
}