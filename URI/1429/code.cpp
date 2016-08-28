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

ll DP[10];

ll fat_memo(ll n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;

    if(DP[n] != -1) return DP[n];

    DP[n] = n*fat_memo(n-1);

    return DP[n];
}

int main()
{
    char string[5];

    while(cin >> string && string[0] != '0')
    {
        ll value = 0; 
        ll k = strlen(string);
        memset(DP,-1,sizeof DP);
        DP[0] = 1;
        DP[1] = 1;
        fat_memo(k);

        for(int i = 0;string[i]; i++)
        {
            // printf("    %d\n",string[i]-'0');
            // printf("DP[k=%d] == %ld\n",k,DP[k]);
            value += (string[i] - '0')*DP[k--];
        }

        printf("%lld\n",value);
    }
}