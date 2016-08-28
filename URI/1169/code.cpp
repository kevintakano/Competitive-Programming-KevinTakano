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

typedef unsigned long long int llu;


int main()
{
    llu vet[65];
    llu vet2[65];
    memset(vet, 0 , sizeof vet);

    vet[1] = 1;
    vet2[1] =1;
    forab(i,2,64)
    {
        vet[i] = vet[i-1]*2; 
        vet2[i] = vet[i] + vet2[i-1];
    }
    


    int N;

    cin >> N;

    for0(i,N)
    {
        int X ; cin >> X; 
        // printf("X = %d\n",X);
        printf("%llu kg\n",vet2[X]/12000);
    }
}