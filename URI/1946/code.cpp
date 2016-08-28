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

double pascal[4999][4999];

int main()
{
    memset(pascal, 0, sizeof pascal);
    pascal[0][0] = 100;
    pascal[1][0] = 50;
    pascal[1][1] = 50;
    int tam = 2;

    int N ; cin >> N;

    for(int i = 2; i < N;i++)
    {
        // printf("i = %d\n",i);
        // printf("tam = %d\n",tam);
        pascal[i][0] = pascal[i-1][0]/2.0;
        for(int j = 1; j < tam;j++)
        {
            pascal[i][j] = pascal[i-1][j-1]/2.0 + pascal[i-1][j]/2.0;
        }
        pascal[i][tam] = pascal[i-1][0]/2.0;
        tam++;
    }

    // pm(pascal,20,20);
    printf("%.2lf\n",pascal[N-1][N/2]);
    // pa(pascal[N-1],20);






}