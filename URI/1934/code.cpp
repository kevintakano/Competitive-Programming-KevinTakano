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

const int MAX = 101, INF = 0x3f3f3f3f;;



string var[MAX][MAX];
int dcol[MAX],dlin[MAX];
map<string,int> res; 

int main()
{

    int L,C;

    cin >> L >> C;

    for(int i = 0;i < L;i++)
    {
        for(int j = 0;j < C;j++)
        {
            cin >> var[i][j];
            // res[var[i][j]] = 0;
        }
        cin >> dcol[i];
    }

    for(int i = 0; i < C;i++)
    {
        cin >> dlin[i]; 
    }

    int total_descobertos = C;

    int k = 1;

    while(total_descobertos > 0)
    {
        int percorrer_coluna = pega_coluna_com_k_variaveis(k,var);
        int percorrer_linha = pega_linha_com_k_variaveis(k,var);
        if(percorrer_coluna != -1)
        {   
                        
        } else 
        if(percorrer_linha != -1)
        {

        }

        
    }


}