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

typedef long long int ll;

ll DP[60+1];

ll fib_memo(ll n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(DP[n] != -1) return DP[n];

    DP[n] = fib_memo(n-1) + fib_memo(n-2);

    return DP[n];
}

int main()
{
    ll T; cin >> T;
    for0(i,T)
    {
        ll N;
        cin >> N;
        memset(DP,-1,sizeof DP);
        printf("Fib(%lld) = %lld\n",N,fib_memo(N));
    }
}