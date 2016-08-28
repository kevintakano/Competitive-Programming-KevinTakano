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
    
    char input[15];
    int decimal;

    while(cin >> input >> decimal)
    {
        printf("$");
        int tam = strlen(input);
        int k = tam - 1;
        for(int i = 0; input[i]; i++)
        {
            printf("%c",input[i]);
            if(k % 3 == 0 && i != tam - 1)
            {
                printf(",");
            }
            k--;
        }   
        printf(".");
        printf("%02d\n",decimal);
    }




    return 0;
}