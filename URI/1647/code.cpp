    #include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
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

typedef long long ll;

ll vec[53];
ll sum[53];

int main()
{
    ll N;

    while(cin >> N && N)
    {
        memset(vec,0,sizeof vec);

        for(int j = N-1;j>=0;j--)
        {
            cin >> vec[j];
        }   

        ll final_sum = 0;

        for(int i = 0;i < N;i++)
        {    
            for(int j = i+1;j <= N;j++)
            {
                vec[j] += vec[i];
            }
            final_sum += vec[i];
        }


        printf("%lld\n",final_sum);
        
    }

}